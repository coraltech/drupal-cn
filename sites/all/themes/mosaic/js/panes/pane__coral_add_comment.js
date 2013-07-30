
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
        var selectors = '.node-question:not(".comment-processed"), .node-answer:not(".comment-processed"), .node-comment:not(".comment-processed")';
        $content = $(selectors);
        $content.each(function(i) {
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
    
    // Top level variable
    this.refID; // all other things revolve around this - content nid 
    
    // jQuery objects of note
    this.$content = $content; // everything centers around the content
    
    //console.log(this.$question);
    this.initID(this.$content, /node-\d+/, 'node-');
    
    // Tertiary jQuery objects
    this.$btn = $content.find('.btn.comment-'+this.refID);
    this.$commentForm = $(this.$content).find('.comment-form-'+this.refID);
    this.$commentsTgt = $(this.$content).find('.comments-tgt-'+this.refID);
    this.$loadMore = $(this.$content).find('.more-comments-'+this.refID);
    this.$trimmed = $(this.$content).find('.body-trimmed.body-'+this.refID); // trimmed text body pane
    this.$full = $(this.$content).find('.body-full.body-'+this.refID);       // full text body pane
    
    this.$commentForm.parents('.panel-pane').eq(0).hide(); // hide the form
    this.$commentsTgt.parents('.panel-pane').eq(0).hide(); // hide comments
    
    // Setup and more
    // ----
    // $loadMore may or may not exist. It usually does not
    //  on the first page run (document.loaded). In this case
    //  we should init a few items.
    if (!this.$loadMore.length) {
      
      // Identification and settings
      this.settingsID;
      this.settings;
      this.currentPage = 1; 
      this.addedNew = 0;
      this.hasTrimmed = false;
      
      // we only want 5 cols - then we hide the form
      this.$commentForm.find('textarea').attr('rows', '5'); 
      
      // Add something clickable to the trimmed text (if necc.)
      var $tt = this.$trimmed.find('.trimmed'); // trimmed 
      var $tf = this.$full.find('.trimmed');    // full
      if (!$tt.length) this.$trimmed.append('<p class="trimmed trimmed-'+this.refID+' trimmed-more"><a href="#">View full text</a></p>');
      if (!$tf.length) this.$full.append('<p class="trimmed trimmed-'+this.refID+' trimmed-less"><a href="#">Hide full text</a></p>');
    }
    
    // Adding events here so we can control the key (nid)   
    this.events = {};
    this.events['click .btn.comment-'+this.refID] = 'commentClick';
    this.events['click .more-comments-'+this.refID] = 'moreClick';
    this.events['click .comment-form-'+this.refID+' .form-submit'] = 'formSubmit';
    this.events['click .trimmed-'+this.refID+' a'] = 'trimmedClick';
        
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
        coralComment.initContentText(); // check for summary and hide full text if avail.
        _.bindAll(this, 'commentClick', 'moreClick', 'formSubmit', 'trimmedClick');
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
      }
    });
    
    new CommentView();
  };


  // Ensure the full node is hidden if the trimmed is shorter
  Drupal.coralQA.coralComment.prototype.initContentText = function() {
    var trimmedText = this.$trimmed.text()
    var fullText = this.$full.text();

    // Set what is visible and hidden
    if (fullText.length > trimmedText.length) {
      this.$full.hide(); // hide it
      this.hasTrimmed = true;
    }
    else {
      this.$trimmed.hide(); // hide the trimmed and clickable link
      $link = this.$full.find('.trimmed-'+this.refID);
      $link.remove();
    }
  };


  // Sets up the Comment button and pulls data from it.
  Drupal.coralQA.coralComment.prototype.initID = function($obj, pat, cls) {
    
    var objPattern = pat || /comment-\d+/;
    var objClass = cls || 'comment-';
    
    // find this button's nid and ensure the AnswerView's  
    var classes = $obj.attr('class');
    classes = classes.split(" ");
    for (cls in classes) {
      var c = classes[cls];
      if (c.match(objPattern)) {
        this.refID = c.replace(objClass, ''); // and the nid
      }
    }
  };


  // Handles the clicke event of the comment button
  Drupal.coralQA.coralComment.prototype.handleCommentClick = function(ev) {

    // If hidden, unhide!
    if (this.$btn.hasClass('comments-hidden')) {

      this.$commentForm.parents('.panel-pane').eq(0).show(); // show the form
      this.$commentsTgt.parents('.panel-pane').eq(0).show(); // show answers 
      this.$btn.find('.arrow').addClass('arrow-down'); // change the arrow to down
      this.$btn.removeClass('comments-hidden'); // update the btn status
      
      // The comments are hidden.  We are starting with the first set
      //  already loaded.  We need to discover if there are more.
      var $comments = $(this.$commentsTgt).find('.node-comment');
      var numComments = $comments.length;
      var moreHide = 'hide'; // a hide class
      
      if (Drupal.settings.mosaicViews.hasOwnProperty('comments_new_comments_'+this.refID)) {
        //console.log('test');
        this.settingsID = 'comments_new_comments_'+this.refID;
        this.settings   = Drupal.settings.mosaicViews[this.settingsID];
        
        if (Number(numComments) < Number(this.settings.total_items)) {
          this.$commentsTgt.parents('.panel-pane').eq(0).addClass('comments-more');
          moreHide = ''; // hide this only if it's not needed... apparently it's needed here.
        }
      }

      // This button appears when there are more items to load. Otherwise it's hidden
      //  starts off hidden here
      if (!this.$loadMore.length) { // add it only if it's not there
        this.$commentsTgt.parent('.pane-content').append(this.loadMoreBtn('1', moreHide));
        this.$loadMore = this.$commentsTgt.parent('.pane-content').find('.more-comments-'+this.refID);
      }
      
      // Clicking on the answer btn opens the full content
      if (this.hasTrimmed) {
        this.$trimmed.hide();
        this.$full.show();
      }
    }
    
    else {
      // hide the answers and form
      this.$commentForm.parents('.panel-pane').eq(0).hide(); // hide the form
      this.$commentsTgt.parents('.panel-pane').eq(0).hide(); // hide the comments
      this.$btn.addClass('comments-hidden');
      this.$btn.find('.arrow').removeClass('arrow-down');
      
      if (this.hasTrimmed) { // show the trimmed version
        this.$trimmed.show();
        this.$full.hide();
      }
    }
  };


  // Process a $loadMore click! Fetches from the view
  Drupal.coralQA.coralComment.prototype.handleMoreClick = function(ev) {
    var $more = $(ev.currentTarget);

    // Find out the limits and page we are on
    var classes = $more.attr('class');
    classes = classes.split(' ');
    for (var i = 0; i < classes.length; i++) {
      if (classes[i] != '') {
        // find what page we are on.
        if (classes[i].match(/page-\d+/)) {
          this.currentPage = classes[i].replace('page-', '');
        }
      }
    }
    this.loadViewResults('comments', 'new_comments', this.refID);
  };


  // Handles loading the comments view
  //  NOTE: It's a good idea to ALWAYS pass the arguments.
  Drupal.coralQA.coralComment.prototype.loadViewResults = function(view_name, view_display, args, callback, mode, offset, limit) {
    var cc = this; // for use later

    var args     = [args]   || [cc.refID]; // the view args
    var callback = callback || {}; 
    var offset   = offset   || String((Number(this.currentPage) * Number(this.settings.limit)) + Number(this.addedNew)); // current offset
    var limit    = limit    || this.settings.limit; // limit for the view results
    var mode     = mode     || 'full'; // if we are in "single" mode, we don't update the page number etc...

    // enable a throbber
    this.$loadMore.find('.no-js').removeClass('no-js').addClass('ajax-progress');
    this.$loadMore.find('span span').addClass('throbber');

    // Render the view upon the world! Go view, go!
    Drupal.coral_ajax.view_render(view_name, {
      display_id: view_display,
      args : args,
      offset : offset,
      limit : limit
    },
    function(data) { // success 
      cc.processViewResults(data, mode); 
      if (typeof(callback) == 'function') callback(data, mode); // fastest method: no ducktyping 
    },
    function(data) { console.log('err'); }); // failure @TODO: get a real error handler
    // and so ends the adventure of the ajax view request... the end?

  };


  // Runs after the view succeeds in returning the next set.
  Drupal.coralQA.coralComment.prototype.processViewResults = function(data, mode) {
    
    // Check get the default total items figure
    var tot = 0;
    if (this.hasOwnProperty('settings')) {
      if (this.settings.hasOwnProperty('total_items')) {
        tot = this.settings.total_items;
      }
    }
  
    // Add the results to the screen
    if (mode == 'full') {   // add new results to the end
      this.updateMoreBtn(); // Update the more button (page-#)
      this.$commentsTgt.append(data); // append the new answers
    }
    else { // single mode - add to the start
      if (tot < 1) {
        this.$commentsTgt.html(''); // remove the default "empty" text
      }
      this.$commentsTgt.prepend(data); // append the new comments
    }
    
    // get timeago et.al. to re-run on the nodes
    Drupal.attachBehaviors();
      
    if ($(this.$btn).hasClass('comments-hidden')) {
      $(this.$btn).addClass('comments-visible').removeClass('comments-hidden');
      $(this.$btn).find('.arrow').addClass('arrowDown');
    }
      
    this.$loadMore.find('span span').removeClass('throbber'); // disable throbber
  };


  // Handles submission of the node comment form
  Drupal.coralQA.coralComment.prototype.submitForm = function(ev) {
    
    cc = this; // capture the coralComment for use later
    
    var $form   = $(ev.currentTarget).parents('form');
    var $submit = $(ev.currentTarget);
    
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
    Drupal.coral_ajax.node_create(node, 
      function(data, msg, xhr) { 
        if (msg == 'success') {
          cc.clearForm($form);   // clear the form
          cc.addNewComment(data); // add this new answer to the top of the list
          
          // User added one! Lets remember that to supplement the views offset
          // ----
          // @NOTE: this may still show the users post if they are browsing 
          //  an active thread.
          cc.addedNew = Number(cc.addedNew) + 1;
        }
      },
      // @TODO: process errors (missing fields etc)
      function(err) {}
    );
  };
  
  
  // Loads up this users "just submitted" comment and puts it in the list.
  //  eg: loadViewResults(view_name, view_display, args, callback, mode, offset, limit)
  Drupal.coralQA.coralComment.prototype.addNewComment = function(data) {
    var cc = this; // keep this!
    var callback = function() { // stuff we do on the there-after...
      cc.$commentForm.find('.form-actions').find('.ajax-progress').remove();
      var $newComment = cc.$content.find('.node-'+data.nid).css("background", "#FFF6B6");
      $newComment.animate({ backgroundColor: '#F1F1F1' }, 3000);
    };
    this.loadViewResults("comments", "this_comment", data.nid, callback, "single", "0", "1");
  };
  
  
  // Handles clearing of the node comment form
  Drupal.coralQA.coralComment.prototype.clearForm = function($form) {
    $form.find('input[name="title"]').val('');
    $form.find('.field-name-body textarea').val('');
  };


  // Returns a Load More link
  Drupal.coralQA.coralComment.prototype.loadMoreBtn = function(page, hide) {
    return '<a href="#" class="btn load-more more-comments-'+this.refID+' page-'+page+' '+hide+'">Load more<span class="no-js"><span></span></a>';
  };

  
  // Updates the more button or removes it if we have no more items
  Drupal.coralQA.coralComment.prototype.updateMoreBtn = function() {
    if ((Number(this.currentPage) + 1) * Number(this.settings.limit) >= Number(this.settings.total_items)) {
      this.$loadMore.hide(); // No more to show, hide the button
    }
    else { // increment the page number
      this.$loadMore.removeClass('page-'+this.currentPage).addClass('page-'+String((Number(this.currentPage) + 1)));
    }
  };
  
  
  // Handle the click even on the trimmed link
  Drupal.coralQA.coralComment.prototype.trimmedClick = function(ev) {
    var $wrap = $(ev.currentTarget).parent('.trimmed');
    // view all
    if ($wrap.hasClass('trimmed-more')) {
      this.$full.show();
      this.$trimmed.hide();
    }
    // view trimmed
    else {
      this.$full.hide();
      this.$trimmed.show();
    }
  };
 
})(jQuery);



