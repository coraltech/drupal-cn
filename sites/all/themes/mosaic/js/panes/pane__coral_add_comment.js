
// Registers the coralQA namespace
Drupal.coralQA = Drupal.coralQA || {};

// ----------------------------------------------------------------------
// Add comment button manager
//
//  Controls comment button events and comments display.
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.coralCommentInit = {    
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
        
        // Comments revolve around the parent content (question, answer, comment).
        //  If there is no content there is nothing.
        var selectors = '.node-question.node-teaser:not(".comment-processed"), .node-answer.node-teaser:not(".comment-processed"), .node-comment.node-teaser:not(".comment-processed")';
        $(selectors).each(function(i) {
          // A new case of the comments!
          new Drupal.coralQA.coralComment($(this));

          // Must ensure we don't re-attach the handlers
          $(this).addClass('comment-processed');
        });        
      }
      catch(err) {
        console.log('coralCommentInit reported errors! Error: '+err);
      }
    }
  };


  // Primary initiator of all commenting related activities
  Drupal.coralQA.coralComment = function($content) {
    try {
      // Top level variable
      this.refID; // all other things revolve around this - content nid 
      
      // jQuery objects of note
      this.$content = $content; // everything centers around the content
      
      //console.log(this.$question);
      this.initID(this.$content, { pat: /node-\d+/, cls: 'node-'});
 
      // Tertiary jQuery objects
      this.$btn = $content.find('.btn.comment-'+this.refID);
      this.$commentForm = $(this.$content).find('.comment-form-'+this.refID);
      this.$commentsTgt = $(this.$content).find('.comments-tgt-'+this.refID);
      this.$loadMore = $(this.$content).find('.more-comments-'+this.refID);
      this.$trimmed = $(this.$content).find('.body-trimmed.body-'+this.refID); // trimmed text body pane
      this.$full = $(this.$content).find('.body-full.body-'+this.refID);       // full text body pane
      
      this.$commentForm.parents('.panel-pane').eq(0).hide(); // hide the form
      this.$commentsTgt.parents('.panel-pane').eq(0).hide(); // hide comments

      // Initialize the content context (teaser|full)
      this.initContext();
      this.initActions();
      this.initClose();
      // Setup and more
      // ----
      // $loadMore may or may not exist. It usually does not
      //  on the first page run (document.loaded). In this case
      //  we should init a few items.
      if (!this.$loadMore.length) {
        
        // Identification and settings
        this.settingsID;
        this.settings;
        this.currentPage = 0; 
        this.addedNew = 0;
        this.hasTrimmed = false;
        this.initialLoad = false;
        
        // we only want 5 cols - then we hide the form
        this.$commentForm.find('textarea').attr('rows', '5'); 
        
        // Add something clickable to the trimmed text (if necc.)
        var $tt = this.$trimmed.find('.trimmed'); // trimmed 
        var $tf = this.$full.find('.trimmed');    // full
        if (!$tt.length) this.$trimmed.append('<p class="trimmed trimmed-'+this.refID+' trimmed-more"><a href="#">View full text</a></p>');
        if (!$tf.length) this.$full.append('<p class="trimmed trimmed-'+this.refID+' trimmed-less"><a href="#">Hide full text</a></p>');
        
        this.initActions();
        this.initClose();
      }
    
      // Adding events here so we can control the refID (nid)   
      this.events = {};
      this.events['click .btn.comment-'+this.refID] = 'commentClick';
      this.events['click .more-comments-'+this.refID] = 'moreClick';
      this.events['click .comment-form-'+this.refID+' .node-form .form-submit'] = 'formSubmit';
      this.events['click .trimmed-'+this.refID+' a'] = 'trimmedClick';
      this.events['click .com-form-title-'+this.refID] = 'formClick';
      this.events['hover .com-form-title-'+this.refID] = 'titleHover';
         
      var coralComment = this;
      var CommentView = Backbone.View.extend({
        // Home
        el: this.$content,
        
        // Settings and conf
        coralComment: coralComment,
        
        // events
        events: coralComment.events, // keyed events
             
        // Init
        initialize: function() {
          coralComment.initForm(); // initialize the form
          coralComment.initComment(); // initialize the comment (and parent)
          coralComment.initTargets(); // Initialize the target containers
          coralComment.initContentText(); // check for summary and hide full text if avail.
          _.bindAll(this, 'commentClick', 'moreClick', 'formSubmit', 'trimmedClick', 'formClick', 'titleHover');
        },
       
        commentClick: function(ev) {
          ev.preventDefault();
          coralComment.handleCommentClick(ev);
        },
        
        moreClick: function(ev) {
          ev.preventDefault();
          coralComment.handleMoreClick(ev);
        },
        
        trimmedClick: function(ev) {
          ev.preventDefault();
          coralComment.trimmedClick(ev);
        },
        
        formSubmit: function(ev) {
          ev.preventDefault();
          coralComment.submitForm(ev);        
        },
        
        formClick: function(ev) {
          ev.preventDefault();
          coralComment.manageForm(ev);
        },
        
        titleHover: function(ev) {
          coralComment.titleHoverHelp(ev);
        }
      });
      
      new CommentView();
    }
    catch (err) {
      console.log('coralComment errored: '+err);
    }
  };


  // Add an identifying class to the form title
  Drupal.coralQA.coralComment.prototype.initForm = function() {
    try {
      var $title = this.$commentForm.parents('.panel-pane').eq(0).children('.pane-title');  // get the pane title
      var contentText = $.trim(this.$content.children('h2').text()); // title of the content the user is responding to
  
      $title.addClass('com-form-title-'+this.refID).addClass('form-hidden'); // add some neat classes
      $title.wrap('<div class="help-wrap help-wrap-'+this.refID+'">');   // add a containing wrap
      $title.after('<span class="help-text help-text-'+this.refID+'">show form</span>').attr('title', 'Comment on '+contentText); // init some custom text and title
      
      this.$commentForm.prepend('<div class="mdgray-txt"><strong>Add comment to</strong>: <em class="ltyellow-bg">'+contentText+'</em></div>');
      this.$commentForm.hide(); // hide the form itself
    }
    catch (err) {
      console.log('initForm errored: '+err);
    }
  };


  // Ensure the full node is hidden if the trimmed is shorter
  Drupal.coralQA.coralComment.prototype.initContentText = function() {
    try {
      var trimmedText = $.trim(this.$trimmed.text()); // get trimmed text
      var fullText = $.trim(this.$full.text());
      var context = 'teaser';
      
      var $contentContext = this.$content.parents('.node-full-node');
      if ($contentContext.length) context = 'full'; 
      
      // The full text is longer than trimmed
      if (fullText.length > trimmedText.length) {
        if (context == 'teaser') {
          this.$full.hide(); // hide it
          this.hasTrimmed = true;
        }
        else {
          this.$full.find('.trimmed-'+this.refID).remove();
          this.$trimmed.find('.trimmed-'+this.refID).remove();
          this.$trimmed.hide();
        }
      }
      else {
        this.$trimmed.hide();
        this.$full.find('.trimmed-'+this.refID).remove();
      }
    }
    catch (err) {
      console.log('initContentText errored: '+err);
    }
  };
  
  
  // Initialize the settings
  Drupal.coralQA.coralComment.prototype.initSettings = function(cb) {
    try {
      // go ahead and set the settings id.
      this.settingsID = 'comments_new_comments_'+this.refID;
      
      var cc = this;
      
      // If we don't have settings for this, it's the first time we've looked at it
      if (!Drupal.settings.mosaicViews.hasOwnProperty(this.settingsID)) {
        var callback = function() {
          cc.settings = Drupal.settings.mosaicViews[cc.settingsID];
          if (typeof(cb) == 'function') cb();
        };

        this.getSettings(callback);    // Get the new settings and then process callback
      }
        
      // No settings loading! We have already loaded these answers
      else {
        this.settings = Drupal.settings.mosaicViews[cc.settingsID];
        if (typeof(cb) == 'function') cb();
      }
    }
    catch (err) {
      console.log('initSettings errored: '+err);
    }
  };


  // Attaches and configures a "to parent" link on the content 
  Drupal.coralQA.coralComment.prototype.initComment = function() {
    try {
      var cc = this;
      
      var $view = $(this.$commentsTgt).children('.view-comments');  // must only return children!
      var $cont = $view.children('.view-content');  // so we can't use find
      var $comments = $cont.children('.views-row'); // so be it.

      // Process all view result comments
      $comments.each(function() {
        cc.processComment($(this));
      });
      
      // Process the parent if it is a comment
      if (this.$content.hasClass('node-comment')) {
        var $parent = {};
        
        // Comments as a parent?
        var $cp = this.$content.parents('.node-comment');
        if (!$cp.length) { // not a comment
          var $ap = this.$content.parents('.node-answer');
          if (!$ap.length) { // answer?
            var $qp = this.$content.parents('.node-question');
            if (!$qp.length) { // not a question, could it be in parent content?
              var $parentContent = $('.pane-coral-parent-content > .pane-content > .node');
              if ($parentContent.length) {
                $parent = $parentContent.eq(0); // the node in the parent content container
              }
            }
            else {
              $parent = $qp.eq(0); // parent is a question
            }
          }
          else {
            $parent = $ap.eq(0); // parent is an answer
          }
        }
        else {
          $parent = $cp.eq(0); // parent is a comment
        }        
        cc.processComment(this.$content, $parent);
      }
      
    }
    catch (err) {
      console.log('initComment errored: '+err);
    }
  };


  // Analyze the object and pull refID data
  // Inputs:
  //  settings.pat (string) - a pattern to search for; defaults to /comment-\d+/
  //  settings.cls (string) - a class to replace with empty space; harvesting the integer
  //  settings.ret (bool) - a boolean val; true to return instead of set.
  Drupal.coralQA.coralComment.prototype.initID = function($obj, settings) {
    try {
      var objPattern = settings.pat || /comment-\d+/;
      var objClass = settings.cls || 'comment-';
      var ret = settings.ret || false;
  
      // find this button's nid and ensure the AnswerView's  
      var classes = $obj.attr('class');
      classes = classes.split(" ");
      for (cls in classes) {
        var c = classes[cls];
        if (c.match(objPattern)) {
          // Set this (standard) - save this item's id
          if (!ret) {
            this.refID = c.replace(objClass, ''); // and the nid
          }
          
          // return it (don't save) - see updateSettings()
          //  this can be used to identify refID's of new view rows.
          else { 
            return c.replace(objClass, ''); // and the nid
          }
        }
      }
    }
    catch (err) {
      console.log('initID errored: '+err);
    }
  };
  
  
  // Establish the rendering context of this content.
  Drupal.coralQA.coralComment.prototype.initContext = function() {
    this.context = 'teaser';
    
    var $contentContext = this.$content.parents('.node-full-node');
    
    if ($contentContext.length) this.context = 'full';
  };


  // Initialize the actions container
  Drupal.coralQA.coralComment.prototype.initActions = function() {
    try {
      var $parent = this.$commentsTgt.parent('.pane-content');
      var $actions = $parent.children('.actions');
      if (!$actions.length) {
        $parent.append('<div class="actions">');
        this.$actions = $parent.children('.actions');
      }
    }
    catch (err) {
      console.log('initActions errored: '+err);
    }
  };


  // Initialize more link
  Drupal.coralQA.coralComment.prototype.initMore = function() {
    try {
      var $view = $(this.$commentsTgt).children('.view-answers');  // must only return children!
      var $cont = $view.children('.view-content');  // so we can't use find
      var $comments = $cont.children('.views-row'); // so be it. 
      var numComments = $comments.length;
      var moreHide = 'hide';
      
      // @TODO: I bet addedNew should be in here too
      if (Drupal.settings.mosaicViews.hasOwnProperty(this.settingsID)) {
        if (Number(numComments) < Number(this.settings.total_items)) {
          this.$commentsTgt.parents('.panel-pane').eq(0).addClass('comments-more');
          moreHide = ''; // hide this only if it's not needed... apparently it's needed here.
        }
        // This button appears when there are more items to load. Otherwise it's hidden
        //  starts off hidden here
        if (!this.$loadMore.length) { // add it only if it's not there
          this.$actions.prepend(this.loadMoreBtn('1', moreHide));
          this.$loadMore = this.$actions.find('.more-comments-'+this.refID);
          
          if (moreHide) {
            this.$loadMore.hide();
          }
        }
      }
      else {
        // @TODO: is it possible that we could be missing the settings?
      }
    }
    catch (err) {
      console.log('initMore errored: '+err);
    }
  };


  // Initialize the color classes on the comment targets
  Drupal.coralQA.coralComment.prototype.initTargets = function() {
    try {
      var $tgts = this.$commentsTgt.parents('.pane-coral-comments-target');
      var $thisTgt = $tgts.eq(0);
      
      var colorData = this.getTargetColorData($thisTgt, $tgts);
      
      // Does it have a class? No, add one!
      if (!$thisTgt.hasClass('odd') && !$thisTgt.hasClass('even')) {
        $thisTgt.addClass(colorData.clrClass); 
      }
    }
    catch (err) {
      console.log('initTargets errored: '+err);
    }
  };
  
  
  // Init the close button - called directly after initMore.
  Drupal.coralQA.coralComment.prototype.initClose = function() {
    try {
      var cc = this;
      
      var $closeBtn = this.$actions.find('.btn.cls-comments-'+this.refID);
      if (!$closeBtn.length) {
        // Append the close button
        this.$actions.append('<a href="#" title="Collapse comments view" class="btn cls-comments cls-comments-'+this.refID+'">Close</a>');
        $closeBtn = this.$actions.find('.btn.cls-comments-'+this.refID);
        $closeBtn.off('click').click(function(ev) { // event must be bound here
          ev.preventDefault(); // animate scroll and close comments
          $('html, body').animate({ scrollTop: cc.$content.offset().top }, 800, function () { cc.hideComments(); });
        });
      }
    }
    catch (err) {
      console.log('initClose errored: '+err);
    }
  };


  // Handles the clicke event of the comment button
  Drupal.coralQA.coralComment.prototype.handleCommentClick = function(ev) {
    try {
      if (!this.$btn.hasClass('ajax-processing')) {
        this.$btn.addClass('ajax-processing'); // no dupes
        this.settingsID = 'comments_new_comments_'+this.refID;
        
        var cc = this;
        
        if (!Drupal.settings.hasOwnProperty('mosaicViews')) {
          Drupal.settings.mosaicViews = {};
        }
        
        // If we don't have settings for this, it's the first time we've looked at it
        if (!Drupal.settings.mosaicViews.hasOwnProperty('comments_new_comments_'+this.refID)) {
          var callback = function() {
            cc.settings = Drupal.settings.mosaicViews[cc.settingsID];
            cc.initMore();
            cc.manageComments();
          };
          cc.setLoadStatus('loading'); // Set the loading status
          cc.getSettings(callback);    // Get the new settings and then process callback
        }
        
        // No settings loading! We have already loaded these comments
        else {
          cc.settings = Drupal.settings.mosaicViews[cc.settingsID];
          cc.manageComments(); // manage them like never before
        }
      }
    }
    catch (err) {
      console.log('handleCommentClick errored: '+err);
    }
  };
  
  
  // Handles close click
  Drupal.coralQA.coralComment.prototype.handleClsClick = function(ev) {
    try {
      console.log('click');
      //var cc = this; // yeah, we have a callback!
      //$('html, body').animate({ scrollTop: this.$content.offset().top }, 800, function () { cc.hideComments(); });
    }
    catch (err) {
      console.log('handleCommentClick errored: '+err);
    }
  };


  // Process a $loadMore click! Fetches from the view
  Drupal.coralQA.coralComment.prototype.handleMoreClick = function(ev) {
    try {
      if (!this.$loadMore.hasClass('ajax-processing')) {
        // Find out the limits and page we are on
        var classes = this.$loadMore.attr('class');
        classes = classes.split(' ');
        for (var i = 0; i < classes.length; i++) {
          if (classes[i] != '') {
            // find what page we are on.
            if (classes[i].match(/page-\d+/)) {
              this.currentPage = classes[i].replace('page-', '');
            }
          }
        }
        this.$loadMore.addClass('ajax-processing');
        this.loadViewResults('comments', 'new_comments', this.refID);
      }
    }
    catch (err) {
      console.log('handlMoreClick errored: '+err);
    }
  };


  // Show a set of comments
  Drupal.coralQA.coralComment.prototype.manageComments = function() {
    try {
      if (this.$btn.hasClass('comments-hidden')) this.showComments();
      else this.hideComments();
    }
    catch (err) {
      console.log('manageComments errored: '+err);
    }
  };


  // Show's this content's comments
  Drupal.coralQA.coralComment.prototype.showComments = function() {
    try {
      var cc = this;

      var callback = function() {
        cc.setLoadStatus('finished');
        if (cc.settings.hasOwnProperty('total_items')) {
          if (Number(cc.settings.total_items) > 0) {
            cc.$commentsTgt.removeClass('empty');
          }
        }
      };
      
      this.$commentForm.parents('.panel-pane').eq(0).slideDown(200); // show the form
      this.$commentsTgt.parents('.panel-pane').eq(0).slideDown(200, callback); // show comments 
      this.$btn.find('.arrow').addClass('arrow-down'); // change the arrow to down
      this.$btn.removeClass('comments-hidden'); // update the btn status

      var $view = $(this.$commentsTgt).children('.view-comments');  // must only return children!
      var $cont = $view.children('.view-content');  // so we can't use find
      var $comments = $cont.children('.views-row'); // so be it. 
      var numComments = $comments.length;
        
      // @TODO: I bet addedNew should be in here too
      if (Drupal.settings.mosaicViews.hasOwnProperty('comments_new_comments_'+this.refID)) {
        if (Number(numComments) < Number(this.settings.total_items)) {
          this.$commentsTgt.parents('.panel-pane').eq(0).addClass('comments-more');
          if (!this.initialLoad) { // load the first set only on the first click - after that use "more"
            this.loadViewResults('comments', 'new_comments', this.refID);
            this.initialLoad = true;
          }
        }
                  
        // Clicking on the answer btn opens the full content
        if (this.hasTrimmed) {
          this.$trimmed.hide();
          this.$full.show();
        }
          
        this.$btn.removeClass('ajax-processing'); // no dupes
      }
      else {
        // @TODO: is it possible that we could be missing the settings?
      }
    }
    catch(err) {
      console.log('showComments errored: '+err);
    }
  };
  
  
  // Hide the comment pane.
  Drupal.coralQA.coralComment.prototype.hideComments = function() {
    try {
      // hide the comments and form
      this.$commentForm.parents('.panel-pane').eq(0).slideUp(200); // hide the form
      this.$commentsTgt.parents('.panel-pane').eq(0).slideUp(200); // hide the comments
      this.$btn.addClass('comments-hidden');
      this.$btn.find('.arrow').removeClass('arrow-down');
            
      if (this.hasTrimmed) { // show the trimmed version
        this.$trimmed.show();
        this.$full.hide();
      }

      this.$btn.removeClass('ajax-processing'); // no dupes
    }
    catch (err) {
      console.log('hideComments errored: '+err);
    }
  };


  // Handles loading the comments view
  //  NOTE: It's a good idea to ALWAYS pass the arguments.
  Drupal.coralQA.coralComment.prototype.loadViewResults = function(view_name, view_display, args, callback, mode, offset, limit) {
    try {
      var cc = this; // for use later
  
      var args     = [args]   || [cc.refID]; // the view args
      var callback = callback || {}; 
      var offset   = offset   || String((Number(this.currentPage) * Number(this.settings.limit)) + Number(this.addedNew)); // current offset
      var limit    = limit    || this.settings.limit; // limit for the view results
      var mode     = mode     || 'full'; // if we are in "single" mode, we don't update the page number etc...
  
      // enable load more throbber - if they clicked it
      if (mode == 'full') {
        this.$loadMore.find('.no-js').removeClass('no-js').addClass('ajax-progress');
        this.$loadMore.find('span span').addClass('throbber');
      }
      
      // Render the view upon the world! Go view, go!
      Drupal.coral_ajax.view_render(view_name, {
        display_id: view_display,
        args : args,
        offset : offset,
        limit : limit
      },
      function(data) { // success 
        cc.processViewResults(data, mode);
        cc.updateSettings(data, mode);
        if (typeof(callback) == 'function') callback(data, mode); // fastest method: no ducktyping 
      },
      function(requestObject, error, errorThrown) { // failure @TODO: get a real error handler - in the works
        console.log(error);
        console.log(errorThrown);
      });
      // and so ends the adventure of the ajax view request... the end?
    }
    catch (err) {
      console.log('loadViewResults errored: '+err);
    }
  };


  // Runs after the view succeeds in returning the next set.
  Drupal.coralQA.coralComment.prototype.processViewResults = function(data, mode) {
    try {
      // Check get the default total items figure
      var tot = 0;
      if (this.hasOwnProperty('settings')) {
        if (this.settings.hasOwnProperty('total_items')) {
          tot = this.settings.total_items;
        }
      }
          
      // Add the results to the screen
      if (mode == 'full') {    // add new results to the end
        this.$loadMore.show(); // show the loadMore button (hidden at first)
        this.updateMoreBtn();  // Update the more button (page-#)
        this.$commentsTgt.append(data); // append the new comments
      }
      
      // single mode - add to the start
      else { 
        $rows = this.$commentsTgt.find('.views-row');
        if (tot < 1 && !$rows.length) { // any rows already there?
          this.$commentsTgt.html('').removeClass('empty'); // remove the default "empty" text and class
        }
        this.$commentsTgt.prepend(data); // append the new comments
      }
      
      if (this.$btn.hasClass('comments-hidden')) {
        this.$btn.addClass('comments-visible').removeClass('comments-hidden');
        this.$btn.find('.arrow').addClass('arrowDown');
      }
      
      this.$btn.removeClass('ajax-processing'); // enable the user to click again
      this.$loadMore.find('span span').removeClass('throbber'); // disable throbber
      
      // get timeago et.al. to re-run on the nodes
      Drupal.attachBehaviors();
    }
    catch (err) {
      console.log('processViewResults errored: '+err);
    }
  };


  // Process each comment and get it ready for interactivity
  Drupal.coralQA.coralComment.prototype.processComment = function($comment, $parent) {
    try {
      
      $parent = $parent || {};

      // Default arrow points to this content's parent content
      var arrow = '<a class="top top-'+this.refID+'" href="#node-ttl-'+this.refID+'"><span class="arrow-up"></span></a>';
      var parentID = 0;
      if ($parent.length) {
        // Loose arrow trys to point to parent content pane node.
        parentID = this.initID($parent, { pat: /node-\d+/, cls: 'node-', ret: true });
        // If we have one use it
        if (parentID) arrow = '<a class="top top-'+parentID+'" href="#node-ttl-'+parentID+'"><span class="arrow-up"></span></a>';
        else arrow = ''; // or lets not show an arrow at all!
      }

      // add id if necc. to the parent node
      if (!this.$content.children('h2').attr('id')) {
        this.$content.children('h2').attr('id', 'node-ttl-'+this.refID);
      }
      // when the content is loose we don't have direct lineage to the parent
      if ($parent.length) { // use the actual parent from above
        $parent.children('h2').attr('id', 'node-ttl-'+parentID);
      }
      
      // add the arrow if necc.
      if (!$comment.children('h2').find('.arrow-up').length) {
        $comment.children('h2').append(arrow);
      }
          
      // Now we should move the title so it can float beside the posted data.
      var $commentHeader = $comment.children('h2');
      var $clone = $commentHeader.clone();
      var $leader = $comment.find('.leader').eq(0);
      if (!$leader.find('#node-ttl-'+this.refID).length) { // make sure you dont add more than once
        $leader.prepend($clone);
        $commentHeader.addClass('hide');
      }
    }
    catch (err) {
      console.log('processComment errored: '+ err);
    }
  };


  // Set the load status for this set of nodes
  //  It would be nice to add '.' to the loading
  //  message before the view is loaded.
  Drupal.coralQA.coralComment.prototype.setLoadStatus = function(status) {
    try {  
      var status = status || 'finished';
      // Add loading gif and manage target text
      if (status == 'loading') {
        // Let the user know something is happening
        this.$btn.append('<span class="ajax-progress"><span class="throbber"></span></span>');
      }
      else {
        this.$btn.find('.ajax-progress').remove();
        if (Number(this.settings.total_items) < 1) {
          this.$commentsTgt.children('.tgt-load').text('No comments were found!');  
        }
        else {
          this.$commentsTgt.children('.tgt-load').remove();
        }
      }
    }
    catch (err) {
      console.log('setLoadStatus errored: '+err);
    }
  };


  // Get the settings for this item and add to the associated theme settings
  Drupal.coralQA.coralComment.prototype.getSettings = function(callback) {
    try {
      cc = this;
      cc.settingsID = 'comments_new_comments_'+cc.refID;
        
      if (Drupal.settings.mosaicViews.hasOwnProperty('comments_new_comments_'+cc.refID)) {
        // return the current object
        return Drupal.settings.mosaicViews[cc.settingsID]
      }
      
      // Load it from the server
      Drupal.coral_ajax.view_info('comments', {
        display_id: "new_comments",
        args : cc.refID,
      },
      function(data) {
        Drupal.settings.mosaicViews[cc.settingsID] = data;
        if (typeof(callback) == 'function') callback();
        return data;
      },
      function(data) { console.log('err'); }); // failure @TODO: get a real error handler;
    }
    catch (err) {
      console.log('getSettings errored: '+err);
    }
  };


  // Get the needed color settings for this level;
  //  Colors alternate between levels for ease of reading.
  Drupal.coralQA.coralComment.prototype.getTargetColorData = function($target, $targets) {
    try {
      var data = {};
      
      data.color = data.defColor = '#EFEFEF';   // default (odd) color 
      data.clrClass = data.defClrClass = 'odd'; // default (odd) color class
      
      // Where is this target, within the scope of the targets?
      if ($targets.length % 2) {
        data.color = '#FFFFFF';
        data.clrClass = 'even';
      }
      
      return data;
    }
    catch (err) {
      console.log('initTargetColorData errored: '+err);
    }
  }


  // Update the settings array when new items are added to the page,
  //  as in when a list of items is added.
  Drupal.coralQA.coralComment.prototype.updateSettings = function(data, mode) {
    try {
      cc = this;
      
      // There are NEW items that were not in the page rendering
      //  so now we have to go back and ensure that the settings
      //  array is up to date... see Drupal.settings.mosaicViews
      var $newItems = $(data).find('.views-row');
      $newItems.each(function(i) {
        var refID = cc.initID($(this).find('.node'), {pat: /node-\d+/, cls: 'node-', ret: true});
        
        cc.initComment();
        cc.getSettings();
      });
    }
    catch (err) {
      console.log('updateSettings errored: '+err);
    }
  };


  // Show or hide the form
  Drupal.coralQA.coralComment.prototype.manageForm = function(ev) {
    try {
      var $wrap = this.$commentForm.parent('.pane-content').siblings('.help-wrap-'+this.refID); // get the wrapper
      var $help = $wrap.find('.help-text');
      var $title = $wrap.find('.pane-title');
      
      if ($title.hasClass('form-hidden')) {
        // update class and text
        $title.removeClass('form-hidden');
        $help.text('hide form');
      }
      else {
        // update class and text
        $title.addClass('form-hidden');
        $help.text('show form');
      }
      this.$commentForm.slideToggle(200); // action!
    }
    catch (err) {
      console.log('manageForm errored: '+err);
    }
  };


  // Handles submission of the node comment form
  Drupal.coralQA.coralComment.prototype.submitForm = function(ev) {
    try {
      cc = this; // capture the coralComment for use later
      
      var $form   = $(ev.currentTarget).parents('form');
      var $submit = $(ev.currentTarget);
      
      if (!$submit.hasClass('ajax-processing')) {
        
        $submit.addClass('ajax-processing'); // ensure no duplicate submissions
      
        var title    = $form.find('input[name="title"]').val();
        var body     = $form.find('.field-name-body textarea.text-full').val();
        var content  = $form.find('.field-name-field-content .form-text').val();
        var langNone = Drupal.settings.coral_qa_manager.language_none || "und";
        
        // Let the user know something is happening
        $submit.parent('.form-wrapper').append('<span class="ajax-progress"><span class="throbber"></span></span>');
            
        // Setup our node
        var node = {
          "type":"comment",
          "title":title,
          "language":langNone,
          "body":{},
          "field_content":{}
        };
        node["body"][langNone] = {"0":{"value": body }};
        node["field_content"][langNone] = {"0":{"target_id": content}};
    
        // Create the node
        //  But wait for a few computer moments... 
        //   Let tinyMce return if it needed to: see mosaicMce.js
        var callback = function() {
          Drupal.coral_ajax.node_create(node, 
            function(data, msg, xhr) { 
              if (msg == 'success') {
                cc.clearForm($form);    // clear the form
                cc.addNewComment(data); // add this new answer to the top of the list
                
                // User added one! Lets remember that to supplement the views offset
                // ----
                // @NOTE: this may still re show the users post if they are browsing 
                //  an active thread. We would need to save a list of the items they
                //  added and adjust the thread organization accordingly.
                cc.addedNew = Number(cc.addedNew) + 1;
              }
            },
            // @TODO: process errors (missing fields etc)
            function(err) {}
          );
        };
        
        // Set the timeout
        setTimeout(callback, 100); // actually save
      }
    }
    catch (err) {
      console.log('submitForm errored: '+err);
    }
  };
  
  
  // Loads up this users "just submitted" comment and puts it in the list.
  //  eg: loadViewResults(view_name, view_display, args, callback, mode, offset, limit)
  Drupal.coralQA.coralComment.prototype.addNewComment = function(data) {
    try {
      var cc = this; // keep this!
      var callback = function() { // stuff we do on the there-after...
        var $tgts = cc.$commentsTgt.parents('.pane-coral-comments-target');
        var colorData = cc.getTargetColorData($tgts.eq(0), $tgts);
        
        cc.$commentForm.find('.form-actions').find('.ajax-progress').remove(); // clear the Submit btn loading gif
        cc.$commentForm.find('.form-submit').removeClass('ajax-processing');    
        var $newComment = $tgts.eq(0).find('.node-'+data.nid).css("background", "#FFF6B6"); // make the new comment yellow
        
        cc.$commentForm.slideUp(800); // hide the comment form
        
        $newComment.animate({ backgroundColor: colorData.color }, 3000); // fade it back
      };
      this.loadViewResults("comments", "this_comment", data.nid, callback, "single", "0", "1");
    }
    catch (err) {
      console.log('addNewComment errored: '+err);
    }
  };
  
  
  // Handles clearing of the node comment form
  Drupal.coralQA.coralComment.prototype.clearForm = function($form) {
    try {
      $form.find('input[name="title"]').val('');
      $form.find('.field-name-body textarea').val('');
    }
    catch (err) {
      console.log('clearForm errored: '+err);
    }
  };


  // Returns a Load More link
  Drupal.coralQA.coralComment.prototype.loadMoreBtn = function(page, hide) {
    try {
      return '<a href="#" class="btn load-more more-comments-'+this.refID+' page-'+page+' '+hide+'">More comments<span class="no-js"><span></span></a>';
    }
    catch (err) {
      console.log('loadMoreBtn errored: '+err);
    }
  };

  
  // Updates the more button or removes it if we have no more items
  Drupal.coralQA.coralComment.prototype.updateMoreBtn = function() {
    try {
      if ((Number(this.currentPage) + 1) * Number(this.settings.limit) >= Number(this.settings.total_items)) {
        this.$loadMore.hide(); // No more to show, hide the button
        this.$commentsTgt.parents('.panel-pane').eq(0).removeClass('comments-more'); // get rid of empty space
      }
      else { // increment the page number
        this.$loadMore.removeClass('page-'+this.currentPage).addClass('page-'+String((Number(this.currentPage) + 1)));
        this.$loadMore.removeClass('ajax-processing'); // ok, now the user can click again!
      }
    }
    catch (err) {
      console.log('updateMoreBtn errored: '+err);
    }
  };
  
  
  // Manage the titleHoverHelp text (eg. Show form, etc...)
  Drupal.coralQA.coralComment.prototype.titleHoverHelp = function(ev) {
    try {
      var $wrap = this.$commentForm.parent('.pane-content').siblings('.help-wrap-'+this.refID); // get the wrapper
      var $help = $wrap.find('.help-text');
    
      if (ev.type == 'mouseenter') $help.animate({left: '7.85em'}, 500); // mouseenter; expose the text
      else $help.animate({left: '0em'}, 500); // mouseleave; hide text
    }
    catch (err) {
      console.log('titleHoverHelp errored: '+err);
    }
  };
  
  
  // Handle the click even on the trimmed link
  Drupal.coralQA.coralComment.prototype.trimmedClick = function(ev) {
    try {
      var cc = this;
      var $wrap = $(ev.currentTarget).parent('.trimmed');
      // view all
      if ($wrap.hasClass('trimmed-more')) {
        this.$full.show();
        this.$trimmed.hide();
      }
      // view trimmed
      else {
        $('html, body').animate({ scrollTop: this.$content.offset().top }, 500, 'swing', function() { 
          cc.$full.hide();
          cc.$trimmed.show();
        });
      }
    }
    catch (err) {
      console.log('trimmedClick errored: '+err);
    }
  };
 
})(jQuery);
