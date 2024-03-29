
// Registers the coralQA namespace
Drupal.coralQA = Drupal.coralQA || {};

// ----------------------------------------------------------------------
// Add answer button manager
//
//  Controls answer button events and answers display.
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.coralAnswerInit = {    
    attach : function(context, settings) {
      
      try { // Use try to prevent systemic failure
        
        // Answers revolve around the parent question.
        //  If there is no question there is nothing.
        $('.node-question.node-teaser:not(".question-processed")').each(function(i) {
          // The questions... Oh, the questions
          new Drupal.coralQA.coralAnswer($(this));
          
          // Must ensure we don't re-attach the handlers
          $(this).addClass('question-processed');
        });        
      }
      catch(err) {
        console.log('coralAnswerInit reported errors! Error: '+err);
      }
    }
  };


  // Primary initiator of all answering related activities
  Drupal.coralQA.coralAnswer = function($question) {
    try {
      // Top level variable
      this.refID; // all other things revolve around this - question nid 
      
      // jQuery objects of note
      this.$question = $question; // everything centers around the Q
      
      // Get the id for this question: it is the refID of this item
      this.initID(this.$question, {pat: /node-\d+/, cls: 'node-'});

      // Tertiary jQuery objects
      this.$btn = $question.find('.btn.answer-'+this.refID);
      this.$answerForm = $(this.$question).find('.answer-form-'+this.refID);
      this.$answersTgt = $(this.$question).find('.answers-tgt-'+this.refID);
      this.$bestAnswer = $(this.$question).find('.best-ans-tgt-'+this.refID);
      this.$loadMore = $(this.$question).find('.more-answers-'+this.refID);
      this.$trimmed = $(this.$question).find('.body-trimmed.body-'+this.refID); // trimmed text body pane
      this.$full = $(this.$question).find('.body-full.body-'+this.refID).removeClass('hide'); // full text body pane - get rid of panels added hide class
      
      // Comment comps - needed to close the comments when answers is clicked
      // See: hideComments()
      this.$cmtBtn   = $question.find('.btn.comment-'+this.refID);
      this.$cmtsForm = $(this.$question).find('.comment-form-'+this.refID);
      this.$cmtsTgt  = $(this.$question).find('.comments-tgt-'+this.refID);
      // end comment tie-in
      
      this.speed = 250; // ms transistion speed

      // Initialize the content context (teaser|full)
      this.initContext();

      // dont hide the answers data on the full node view
      if (this.context == 'teaser') {
        this.$answerForm.parents('.panel-pane').eq(0).hide(); // hide the form
        this.$answersTgt.parents('.panel-pane').eq(0).hide(); // hide answers target
        this.$bestAnswer.hide(); // hide best answer
      }

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
        this.addedNew    = 0;
        this.hasTrimmed  = false;
        this.initialLoad = false;
        
        this.$actions; // will provide a parent container for the close and more buttons for each answers target
                
        // we only want 5 cols - then we hide the form
        this.$answerForm.find('textarea').attr('rows', '5'); 
        
        // Add something clickable to the trimmed text (if necc.)
        var $tt = this.$trimmed.find('.trimmed'); // trimmed 
        var $tf = this.$full.find('.trimmed');    // full
        if (!$tt.length) this.$trimmed.append('<p class="trimmed trimmed-'+this.refID+' trimmed-more"><a href="#">View full text</a></p>');
        if (!$tf.length) this.$full.append('<p class="trimmed trimmed-'+this.refID+' trimmed-less"><a href="#">Hide full text</a></p>');
      
        // Add more link and close actions
        this.initMore();
        this.initClose();
      }
            
      // Adding events here so we can control the key    
      this.events = {};
      this.events['click .btn.answer-'+this.refID] = 'answerClick';
      this.events['click .btn.comment-'+this.refID] = 'commentClick'; // closes the answers pane - all other comment related func. is in pane__coral_add_comment.js
      this.events['click .more-answers-'+this.refID] = 'moreClick';
      this.events['click .answer-form-'+this.refID+' .node-form .form-submit'] = 'formSubmit';
      this.events['click .trimmed-'+this.refID+' a'] = 'trimmedClick';
      this.events['click .ans-form-title-'+this.refID] = 'formClick';
      this.events['click .cls-answers-'+this.refID] = 'closeClick';
      this.events['hover .ans-form-title-'+this.refID] = 'titleHover';
          
      var coralAnswer = this;
      var AnswerView = Backbone.View.extend({
        // Home
        el: this.$question,
        
        // Settings and conf
        coralAnswer: coralAnswer,
        
        // events
        events: coralAnswer.events, // keyed events
             
        // Init
        initialize: function() {
          coralAnswer.initForm(); // initialize the form
          coralAnswer.initAnswer(); // initialize the answer
          coralAnswer.initQuestion(); // check for summary and hide full text if avail.
          _.bindAll(this, 'answerClick', 'commentClick', 'closeClick', 'moreClick', 'formSubmit', 'trimmedClick', 'formClick', 'titleHover');
        },
       
        answerClick: function(ev) {
          ev.preventDefault();
          coralAnswer.handleAnswerClick(ev);
        },
        
        commentClick: function(ev) {
          ev.preventDefault();
          coralAnswer.handleCommentClick(ev); // closes comments
        },
        
        closeClick: function(ev) {
          ev.preventDefault();
          coralAnswer.handleClsClick(ev); // closes answers
        },
        
        moreClick: function(ev) {
          ev.preventDefault();
          coralAnswer.handleMoreClick(ev);
        },
        
        trimmedClick: function(ev) {
          ev.preventDefault();
          coralAnswer.trimmedClick(ev);
        },
        
        formSubmit: function(ev) {
          ev.preventDefault();
          coralAnswer.submitForm(ev);        
        },
        
        formClick: function(ev) {
          ev.preventDefault();
          coralAnswer.manageForm(ev);
        },
        
        titleHover: function(ev) {
          coralAnswer.titleHoverHelp(ev);
        }
      });
      
      new AnswerView();
    }
    catch (err) {
      console.log('coralAnswer errored: '+err);
    }
  };
  
  
  // Add an identifying class to the form title
  Drupal.coralQA.coralAnswer.prototype.initForm = function() {
    try {
      // do we have a best answer?
      var $best = this.$bestAnswer.find('.node-answer');
      if (!$best.length) this.$answersTgt.parent('.pane-content').siblings('.pane-title').hide(); // if best exists, keep the second answers title (it makes a good divider)
      var $ansFrm = this.$answerForm.parent('.pane-content').parent('.pane-coral-answer-form').prepend('<div class="ans-header">Answers</div>');
      
      var $title = this.$answerForm.parents('.panel-pane').eq(0).children('.pane-title');  // get the pane title
      var contentText = $.trim(this.$question.children('.question-node-pane-title').text()); // title of the content the user is responding to
  
      $title.addClass('ans-form-title-'+this.refID).addClass('form-hidden'); // add some neat classes
      $title.wrap('<div class="help-wrap help-wrap-'+this.refID+'">');   // add a containing wrap
      $title.after('<span class="help-text help-text-'+this.refID+'">show form</span>').attr('title', 'Click to answer '+contentText); // init some custom text and title
      
      this.$answerForm.prepend('<div class="mdgray-txt"><strong>Add answer to</strong>: <em class="ltyellow-bg">'+contentText+'</em></div>');
      this.$answerForm.hide(); // hide the form itself
    }
    catch (err) {
      console.log('initForm errored: '+err);
    }
  };


  // Ensure the full node text is hidden if the trimmed is different
  // Also load first results if we are on full node
  Drupal.coralQA.coralAnswer.prototype.initQuestion = function() {
    try {
      var trimmedText = $.trim(this.$trimmed.text()); // get trimmed text
      var fullText = $.trim(this.$full.text());
      
      // The full text is longer than trimmed
      if (fullText.length > trimmedText.length) {
        if (this.context == 'teaser') {
          this.$full.hide(); // hide it - clear a class added via panels css settings
          this.$trimmed.show();
          this.hasTrimmed = true;
        }
        else {
          this.$full.find('.trimmed-'+this.refID).remove();
          this.$trimmed.find('.trimmed-'+this.refID).remove();
          this.$trimmed.hide();
        }
      }
      else {
        this.$trimmed.find('.trimmed-'+this.refID).remove();
        this.$full.hide();
      }

      if (this.context != 'teaser') {
        // Simulate first click if we are not looking at a teaser
        this.handleAnswerClick(); // load first page of results.
      }
    }
    catch (err) {
      console.log('initQuestionText errored: '+err);
    }
  };
  
  
  // Initialize the settings
  Drupal.coralQA.coralAnswer.prototype.initSettings = function(cb) {
    try {
      this.settingsID = 'answers_new_answers_'+this.refID; // main id
      
      var ca = this;
      
      // If we don't have settings for this, it's the first time we've looked at it
      if (!Drupal.settings.mosaicViews.hasOwnProperty(this.settingsID)) {
        var callback = function() {
          ca.settings = Drupal.settings.mosaicViews[ca.settingsID];
          if (typeof(cb) == 'function') cb();
        };

        this.getSettings(callback);    // Get the new settings and then process callback
      }
        
      // No settings loading! We have already loaded these answers
      else {
        this.settings = Drupal.settings.mosaicViews[ca.settingsID];
        if (typeof(cb) == 'function') cb();
      }
    }
    catch (err) {
      console.log('initSettings errored: '+err);
    }
  };
  
  
  // Attaches and configures a "to parent" link on the content
  //  Simpler here than in comments bc the answers can only be one
  //  level deep and a child of a question...
  Drupal.coralQA.coralAnswer.prototype.initAnswer = function() {
    try {
      var ca = this;

      var $view = $(this.$answersTgt).children('.view-answers');  // must only return children!
      var $cont = $view.children('.view-content');  // so we can't use find
      var $answers = $cont.children('.views-row'); // so be it.
      
      $answers.each(function() {
        var $answer = $(this).children('.node-answer');
        var arrow = '<a class="top top-'+ca.refID+'" href="#node-ttl-'+ca.refID+'"><span class="arrow-up"></span></a>';
        // add id if necc.
        if (!ca.$question.children('h2').attr('id')) {
          ca.$question.children('h2').attr('id', 'node-ttl-'+ca.refID);
        }
        // add the arrow if necc.
        if (!$answer.children('h2').find('.arrow-up').length) {
          $answer.children('h2').append(arrow);
        }
      });
    }
    catch (err) {
      console.log('initAnswer errored: '+err);
    }
  };


  // Analyze the object and pull refID data
  // Inputs:
  //  settings.pat (string) - a pattern to search for; defaults to /node-\d+/
  //  settings.cls (string) - a class to replace with empty space; harvesting the integer
  //  settings.ret (bool) - a boolean val; true to return instead of set.
  Drupal.coralQA.coralAnswer.prototype.initID = function($obj, settings) {
    try {
      var objPattern = settings.pat || /node-\d+/;
      var objClass = settings.cls || 'node-';
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
  Drupal.coralQA.coralAnswer.prototype.initContext = function() {
    try {
      this.context = 'teaser';
      
      var $questionContext = this.$question.parents('.node-full-node');
      
      if ($questionContext.length) {
        this.context = 'full';
      }
    }
    catch (err) {
      console.log('initContext errored: '+err);
    }
  };
  
  
  // Initialize more link
  Drupal.coralQA.coralAnswer.prototype.initMore = function() {
    try {
      
      var $view = $(this.$answersTgt).children('.view-answers');  // must only return children!
      var $cont = $view.children('.view-content');  // so we can't use find
      var $answers = $cont.children('.views-row'); // so be it. 
      var numAnswers = $answers.length;
      var moreHide = 'hide';
      
      var $parent = this.$answersTgt.parent('.pane-content');
      var $actions = this.$actions || undefined;
      if (!$actions) {
        $parent.append('<div class="actions">');
        this.$actions = $parent.children('.actions'); // GET THIS TO IDENT THE RIGHT ACTION SET!      
      }
      
      // @TODO: I bet addedNew should be in here too
      if (Drupal.settings.mosaicViews.hasOwnProperty(this.settingsID)) {
        if (Number(numAnswers) < Number(this.settings.total_items)) {
          this.$answersTgt.parents('.panel-pane').eq(0).addClass('answers-more');
          moreHide = ''; // hide this only if it's not needed... apparently it's needed here.
        }
        // This button appears when there are more items to load. Otherwise it's hidden
        //  starts off hidden here
        if (!this.$loadMore.length) { // add it only if it's not there
          this.$actions.append(this.loadMoreBtn('1', moreHide));
          this.$loadMore = $parent.find('.more-answers-'+this.refID);
          if (moreHide) this.$loadMore.hide();
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
  
  
  // Init the close button - called directly after initMore.
  Drupal.coralQA.coralAnswer.prototype.initClose = function() {
    try {
      this.$actions.append('<a href="#" title="Collapse answers view" class="cls-answers cls-answers-'+this.refID+'">x</a>');
    }
    catch (err) {
      console.log('initClose errored: '+err);
    }
  };


  // Handles the clicke event of the answer button
  Drupal.coralQA.coralAnswer.prototype.handleAnswerClick = function(ev) {
    try {
      if (!this.$btn.hasClass('ajax-processing')) {
        this.$btn.addClass('ajax-processing'); // no dupes
        this.settingsID = 'answers_new_answers_'+this.refID;
        
        var ca = this;
        
        if (!Drupal.settings.hasOwnProperty('mosaicViews')) {
          Drupal.settings.mosaicViews = {};
        }

        // If we don't have settings for this, it's the first time we've looked at it
        if (!Drupal.settings.mosaicViews.hasOwnProperty('answers_new_answers_'+this.refID)) {
          var callback = function() {
            ca.settings = Drupal.settings.mosaicViews[ca.settingsID];
            ca.initMore();
            ca.manageAnswers();
          };

          ca.setLoadStatus('loading'); // Set the loading status
          ca.getSettings(callback);    // Get the new settings and then process callback
        }
        
        // No settings loading! We have already loaded these answers
        else {
          ca.settings = Drupal.settings.mosaicViews[ca.settingsID];
          ca.manageAnswers(); // manage them like never before
        }
      }
    }
    catch (err) {
      console.log('handleAnswerClick errored: '+err);
    }
  };
  
  
  // This simply hides the answers when the comments are opened
  //  This is only necc. when answers and comments are both present
  //  ie. Questions...
  Drupal.coralQA.coralAnswer.prototype.handleCommentClick = function(ev) {
    try {
      this.hideAnswers('no toggle');
    }
    catch (err) {
      console.log('handleCommentClick errored: '+err);
    }
  };
  

  // Handles close click
  Drupal.coralQA.coralAnswer.prototype.handleClsClick = function(ev) {
    try {
      var ca = this; // yeah, we have a callback!
      
      if (this.inView()) {
        $('html, body').animate({ scrollTop: this.$question.offset().top }, this.speed, function () { ca.hideAnswers(); });  
      }
      else {
        this.hideAnswers();
      }
    }
    catch (err) {
      console.log('handleCommentClick errored: '+err);
    }
  };
  
  
  // Process a $loadMore click! Fetches from the view
  Drupal.coralQA.coralAnswer.prototype.handleMoreClick = function(ev) {
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
        this.loadViewResults('answers', 'new_answers', this.refID);
      }
    }
    catch (err) {
      console.log('handleMoreClick errored: '+err);
    }
  };


  // Show / Hide a set of Answers
  Drupal.coralQA.coralAnswer.prototype.manageAnswers = function() {
    try {
      if (this.$btn.hasClass('answers-hidden')) this.showAnswers();
      else this.hideAnswers();
    }
    catch (err) {
      console.log('manageAnswers errored: '+err);
    }
  };


  // Show's this question's answers
  Drupal.coralQA.coralAnswer.prototype.showAnswers = function() {
    try {
      var ca = this;

      var callback = function() {
        ca.setLoadStatus('finished');
        if (ca.settings.hasOwnProperty('total_items')) {
          if (Number(ca.settings.total_items) > 0) {
            ca.$answersTgt.removeClass('empty');
          }
        }
      };
      
      this.$answerForm.parents('.panel-pane').eq(0).slideDown(this.speed); // show the form
      this.$answersTgt.parents('.panel-pane').eq(0).slideDown(this.speed, callback); // show comments
      this.$bestAnswer.slideDown(this.speed); // show best answer
      this.$btn.find('.arrow').addClass('arrow-down'); // change the arrow to down
      this.$btn.removeClass('answers-hidden'); // update the btn status

      var $view = $(this.$answersTgt).children('.view-comments');  // must only return children!
      var $cont = $view.children('.view-content');  // so we can't use find
      var $answers = $cont.children('.views-row'); // so be it. 
      var numAnswers = $answers.length;
        
      // @TODO: I bet addedNew should be in here too
      if (Drupal.settings.mosaicViews.hasOwnProperty('answers_new_answers_'+this.refID)) {
        if (Number(numAnswers) < Number(this.settings.total_items)) {
          this.$answersTgt.parents('.panel-pane').eq(0).addClass('answers-more');
          if (!this.initialLoad) { // load the first set only on the first click - after that use "more"
            this.loadViewResults('answers', 'new_answers', this.refID);
            this.initialLoad = true;
          }
        }

        // Clicking on the answer btn opens the full content
        if (this.hasTrimmed) {
          this.$trimmed.hide();
          this.$full.show();
        }
          
        this.$btn.removeClass('ajax-processing'); // no dupes
        this.hideComments(); // hide comments
      }
      else {
        // @TODO: is it possible that we could be missing the settings?
      }
    }
    catch(err) {
      console.log('showAnswers errored: '+err);
    }
  };


  // Hide the question's answers
  //  Gets called on comment add click too!
  Drupal.coralQA.coralAnswer.prototype.hideAnswers = function(textToggle) {
    var text = textToggle || 'toggle';
    try {
      // hide the answers and form
      this.$answerForm.parents('.panel-pane').eq(0).slideUp(this.speed); // hide the form
      this.$answersTgt.parents('.panel-pane').eq(0).slideUp(this.speed); // hide the answers
      this.$bestAnswer.slideUp(this.speed);

      this.$btn.find('.arrow').removeClass('arrow-down');
      this.$btn.addClass('answers-hidden');
            
      if (this.hasTrimmed && text == 'toggle') { // show the trimmed version
        this.$trimmed.show();
        this.$full.hide();
      }
      
      this.$btn.removeClass('ajax-processing'); // no dupe events
    }
    catch (err) {
      console.log('hideAnswers errored: '+err);
    }
  };
  
  
  // Shuts comments when the answer button is clicked!
  //  Do not remove.  Comments js file can't do this!
  Drupal.coralQA.coralAnswer.prototype.hideComments = function() {
    try {
      // hide the comments and form
      // This is done here so we can shut one 
      // when the other opens. No need to add this to comments js.
      this.$cmtsForm.parents('.panel-pane').eq(0).slideUp(this.speed); // hide the form
      this.$cmtsTgt.parents('.panel-pane').eq(0).slideUp(this.speed); // hide the comments
      this.$cmtBtn.addClass('comments-hidden');
      this.$cmtBtn.find('.arrow').removeClass('arrow-down');
    }
    catch (err) {
      console.log('hideComments errored: '+err);
    }
  };


  // Handles loading the answers view
  //  NOTE: It's a good idea to ALWAYS pass the arguments.  It is possible that ca.answerID may not be the one you want?
  Drupal.coralQA.coralAnswer.prototype.loadViewResults = function(view_name, view_display, args, callback, mode, offset, limit) {
    try {
      var ca = this; // for use later
  
      var args     = [args]   || [ca.refID]; // the view args
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
        ca.processViewResults(data, mode);
        ca.updateSettings(data, mode);
        if (typeof(callback) == 'function') callback(data, mode); // fastest method: no ducktyping 
      },
      function(data) { console.log('err'); }); // failure @TODO: get a real error handler
      // and so ends the adventure of the ajax view request... the end?
    }
    catch (err) {
      console.log('loadViewResults errored: '+err);
    }
  };


  // Runs after the view succeeds in returning the next set.
  Drupal.coralQA.coralAnswer.prototype.processViewResults = function(data, mode) {
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
        this.updateMoreBtn();  // Update the more button (page-#)
        this.$answersTgt.append(data); // append the new answers
      }
      else { // single mode - add to the start
        $rows = this.$answersTgt.find('.views-row');
        if (tot < 1 && !$rows.length) { // any rows already there?
          this.$answersTgt.html('').removeClass('empty'); // remove the default "empty" text and class
        }
        this.$answersTgt.prepend(data); // append the new answers
      }
      
      if ($(this.$btn).hasClass('answers-hidden')) {
        $(this.$btn).addClass('answers-visible').removeClass('answers-hidden');
        $(this.$btn).find('.arrow').addClass('arrowDown');
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


  // Set the load status for this set of nodes
  //  It would be nice to add '.' to the loading
  //  message before the view is loaded.
  Drupal.coralQA.coralAnswer.prototype.setLoadStatus = function(status) {
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
          this.$answersTgt.children('.tgt-load').text('No answers were found!');  
        }
        else {
          this.$answersTgt.children('.tgt-load').remove();
        }
      }
    }
    catch (err) {
      console.log('setLoadStatus errored: '+err);
    }
  };


  // Get the settings for this item and add to the associated theme settings
  Drupal.coralQA.coralAnswer.prototype.getSettings = function(callback) {
    try {
      var ca = this;
              
      if (Drupal.settings.mosaicViews.hasOwnProperty('answers_new_answers_'+ca.refID)) {
        // return the current object
        return Drupal.settings.mosaicViews[ca.settingsID]
      }
      
      // Load it from the server
      Drupal.coral_ajax.view_info('answers', {
        display_id: "new_answers",
        args : ca.refID,
      },
      function(data) {
        Drupal.settings.mosaicViews[ca.settingsID] = data;
        if (typeof(callback) == 'function') callback();
        return data;
      },
      function(data) { // failure @TODO: get a real error handler;
        console.log('error recieved: '+data.responseText); 
      }); 
    }
    catch (err) {
      console.log('getSettings errored: '+err);
    }
  };
  

  // Update the settings array when new items are added to the page
  Drupal.coralQA.coralAnswer.prototype.updateSettings = function(data) {
    try {
      ca = this;
      
      // There are NEW items that were not in the page rendering
      //  so now we have to go back and ensure that the settings
      //  array is up to date... see Drupal.settings.mosaicViews
      var $newItems = $(data).find('.views-row');
      $newItems.each(function(i) {
        var $node = $(this).find('.node').eq(0); 
        var refID = ca.initID($node, {pat: /node-\d+/, cls: 'node-', ret: true});
        
        ca.initAnswer();
        ca.getSettings();
      });
    }
    catch (err) {
      console.log('updateSettings errored: '+err);
    }
  };


  // Show or hide the form
  Drupal.coralQA.coralAnswer.prototype.manageForm = function(ev) {
    try {
      var $wrap = this.$answerForm.parent('.pane-content').siblings('.help-wrap-'+this.refID); // get the wrapper
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
      this.$answerForm.slideToggle(this.speed); // action!
    }
    catch (err) {
      console.log('manageForm errored: '+err);
    }
  };


  // Handles submission of the node answer form
  Drupal.coralQA.coralAnswer.prototype.submitForm = function(ev) {
    try {
      ca = this; // capture the coralAnswer for use later
      
      var $form   = $(ev.currentTarget).parents('form');
      var $submit = $(ev.currentTarget);
      
      if (!$submit.hasClass('ajax-processing')) {
        
        $submit.addClass('ajax-processing'); // ensure no duplicate submissions
        
        var title    = $form.find('input[name="title"]').val();
        var body     = $form.find('.field-name-body textarea.text-full').val();
        var question = $form.find('.field-name-field-question .form-text').val();
        var langNone = Drupal.settings.coral_qa_manager.language_none || "und";
        
        // Let the user know something is happening
        $submit.parent('.form-wrapper').append('<span class="ajax-progress"><span class="throbber"></span></span>');
            
        // Setup our node
        var node = {
          "type":"answer",
          "title":title,
          "language":langNone,
          "body":{},
          "field_question":{}
        };
        node["body"][langNone] = {"0":{"value": body }};
        node["field_question"][langNone] = {"0":{"target_id": question}};
    
        // Create the node
        //  But wait for a few computer moments... 
        //   Let tinyMce return if it needed to: see mosaicMce.js
        var callback = function() {
          Drupal.coral_ajax.node_create(node, 
            function(data, msg, xhr) {
              if (msg == 'success') {
                ca.clearForm($form);   // clear the form
                ca.addNewAnswer(data); // add this new answer to the top of the list

                // User added one! Lets remember that to supplement the views offset
                // ----
                // @NOTE: this may still re show the users post if they are browsing 
                //  an active thread. We would need to save a list of the items they
                //  added and adjust the thread organization accordingly.
                ca.addedNew = Number(ca.addedNew) + 1;
              }
            },
            // @TODO: process errors (missing fields etc)
            function (jqXHR, status, err) {
							console.log('Answer creation errored: '+err);
						}
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
  
  
  // Loads up this users "just submitted" answer and puts it in the list.
  //  eg: loadViewResults(view_name, view_display, args, callback, mode, offset, limit)
  Drupal.coralQA.coralAnswer.prototype.addNewAnswer = function(data) {
    try {
      var ca = this; // keep this!
      var callback = function() { // stuff we do on the there-after...
        ca.$answerForm.find('.form-actions').find('.ajax-progress').remove();
        ca.$answerForm.find('.form-submit').removeClass('ajax-processing');
        var $newAnswer = ca.$question.find('.node-'+data.nid).css("background", "#FFF6B6");
        var $viewRow = $newAnswer.parent('.views-row');
        
        ca.$answerForm.slideUp(this.speed); // hide the answer form
        
        $viewRow.css('padding-bottom', '1px');
        $newAnswer.animate({ backgroundColor: '#FFFFFF' }, 3000, 'swing', function() {
          $newAnswer.css('background', 'transparent');
          $viewRow.css('padding-bottom', '0');
        });
      };
      this.loadViewResults("answers", "this_answer", data.nid, callback, "single", "0", "1");
    }
    catch (err) {
      console.log('addNewAnswer errored: '+err);
    }
  };


  // Handles clearing of the node answer form
  Drupal.coralQA.coralAnswer.prototype.clearForm = function($form) {
    try {  
      $form.find('input[name="title"]').val('');
      $form.find('.field-name-body textarea').val('');
    }
    catch (err) {
      console.log('clearForm errored: '+err);
    }
  };


  // Returns a Load More link
  Drupal.coralQA.coralAnswer.prototype.loadMoreBtn = function(page, hide) {
    try {
      var tot = this.settings.total_items;
      var cur = this.settings.limit;
      if (Number(this.settings.total_items) <= Number(this.settings.limit)) tot = cur;
                
      var btn = '<span class="btn">More answers</span>';
      var pgtot = '<span class="pgtot">(<span class="cur">'+cur+'</span>/<span class="tot">'+tot+'</span>)</span>';
      return '<a href="#" class="load-more more-answers-'+this.refID+' page-'+page+' '+hide+'"><span class="icon"></span>'+btn+pgtot+'<span class="no-js"><span></span></a>';
    }
    catch (err) {
      console.log('loadMoreBtn errored: '+err);
    }
  };


  // Updates the more button or removes it if we have no mo re items
  Drupal.coralQA.coralAnswer.prototype.updateMoreBtn = function() {
    try {
      if ((Number(this.currentPage) + 1) * Number(this.settings.limit) >= Number(this.settings.total_items)) {
        this.$loadMore.hide(); // No more to show, hide the button
        this.$answersTgt.parents('.panel-pane').eq(0).removeClass('answers-more'); // get rid of empty space
      }
      else { // increment the page number
        this.$loadMore.removeClass('page-'+this.currentPage).addClass('page-'+String((Number(this.currentPage) + 1)));
        this.$loadMore.removeClass('ajax-processing'); // ok, now the user can click again!
        
        this.$loadMore.find('.cur').text((Number(this.currentPage) + 1) * Number(this.settings.limit));
      }
    }
    catch (err) {
      console.log('updateMoreBtn errored: '+err);
    }
  };
  
  
  // Manage the titleHoverHelp text (eg. Show form, etc...)
  Drupal.coralQA.coralAnswer.prototype.titleHoverHelp = function(ev) {
    try {
      var $wrap = this.$answerForm.parent('.pane-content').siblings('.help-wrap-'+this.refID); // get the wrapper
      var $help = $wrap.find('.help-text');
      
      if (ev.type == 'mouseenter') $help.animate({left: '7.5em'}, this.speed); // mouseenter; expose the text
      else $help.animate({left: '0em'}, this.speed); // mouseleave; hide text
    }
    catch (err) {
      console.log('titleHoverHelp errored: '+err);
    }
  };
  
  
  // Handle the click even on the trimmed link
  Drupal.coralQA.coralAnswer.prototype.trimmedClick = function(ev) {
    try {
      var ca = this;
      var $wrap = $(ev.currentTarget).parent('.trimmed');
      // view all
      if ($wrap.hasClass('trimmed-more')) {
        this.$full.show();
        this.$trimmed.hide();
      }
      // view trimmed
      else {
        if (this.inView()) {
          $('html, body').animate({ scrollTop: this.$question.offset().top }, this.speed, 'swing', function() { 
            ca.$full.hide();
            ca.$trimmed.show();
          });
        }
        else {
          this.$full.hide();
          this.$trimmed.show();
        }
      }
    }
    catch (err) {
      console.log('trimmedClick errored: '+err);
    }
  };
  
  
  // Checks if the question is in-view
  Drupal.coralQA.coralAnswer.prototype.inView = function() {
    try {
      var docViewTop = $(window).scrollTop();
      var elemTop = this.$question.offset().top;
      if (elemTop <= docViewTop) return true;
      return false;
    }
    catch (err) {
      console.log('inView errored: '+err);
    }
  };
  
})(jQuery);
