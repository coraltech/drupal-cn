
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
        $('.node-question:not(".question-processed")').each(function(i) {
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
      
      //console.log(this.$question);
      this.initID(this.$question, {pat: /node-\d+/, cls: 'node-'});
      
      // Tertiary jQuery objects
      this.$btn = $question.find('.btn.answer-'+this.refID);
      this.$answerForm = $(this.$question).find('.answer-form-'+this.refID);
      this.$answersTgt = $(this.$question).find('.answers-tgt-'+this.refID);
      this.$loadMore = $(this.$question).find('.more-answers-'+this.refID);
      this.$trimmed = $(this.$question).find('.body-trimmed.body-'+this.refID); // trimmed text body pane
      this.$full = $(this.$question).find('.body-full.body-'+this.refID);       // full text body pane
      
      this.$answerForm.parents('.panel-pane').eq(0).hide(); // show the form
      this.$answersTgt.parents('.panel-pane').eq(0).hide(); // show answers
      
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
        this.$answerForm.find('textarea').attr('rows', '5'); 
        
        // Add something clickable to the trimmed text (if necc.)
        var $tt = this.$trimmed.find('.trimmed'); // trimmed 
        var $tf = this.$full.find('.trimmed');    // full
        if (!$tt.length) this.$trimmed.append('<p class="trimmed trimmed-'+this.refID+' trimmed-more"><a href="#">View full text</a></p>');
        if (!$tf.length) this.$full.append('<p class="trimmed trimmed-'+this.refID+' trimmed-less"><a href="#">Hide full text</a></p>');
      }
      
      // Adding events here so we can control the key    
      this.events = {};
      this.events['click .btn.answer-'+this.refID] = 'answerClick';
      this.events['click .more-answers-'+this.refID] = 'moreClick';
      this.events['click .answer-form-'+this.refID+' .form-submit'] = 'formSubmit';
      this.events['click .trimmed-'+this.refID+' a'] = 'trimmedClick';
      this.events['click .ans-form-title-'+this.refID] = 'formClick';
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
          coralAnswer.initQuestionText(); // check for summary and hide full text if avail.
          _.bindAll(this, 'answerClick', 'moreClick', 'formSubmit', 'trimmedClick', 'formClick', 'titleHover');
        },
       
        answerClick: function(ev) {
          ev.preventDefault();
          coralAnswer.handleAnswerClick(ev);
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

  
  // Manage the titleHoverHelp text (eg. Show form, etc...)
  Drupal.coralQA.coralAnswer.prototype.titleHoverHelp = function(ev) {
    try {
      var $wrap = this.$answerForm.parent('.pane-content').siblings('.help-wrap-'+this.refID); // get the wrapper
      var $help = $wrap.find('.help-text');
      
      if (ev.type == 'mouseenter') $help.animate({left: '9em'}, 500); // mouseenter; expose the text
      else $help.animate({left: '0em'}, 500); // mouseleave; hide text
    }
    catch (err) {
      console.log('titleHoverHelp errored: '+err);
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
      this.$answerForm.slideToggle(); // action!
    }
    catch (err) {
      console.log('manageForm errored: '+err);
    }
  };
  
  
  // Add an identifying class to the form title
  Drupal.coralQA.coralAnswer.prototype.initForm = function() {
    try {
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
  Drupal.coralQA.coralAnswer.prototype.initQuestionText = function() {
    try {
      var trimmedText = $.trim(this.$trimmed.text()); // get trimmed text
      var fullText = $.trim(this.$full.text());
      
      if (fullText.length > trimmedText.length) {
        this.$full.hide(); // hide it
        this.hasTrimmed = true;
      }
      else {
        this.$trimmed.hide();
        $link = this.$full.find('.trimmed-'+this.refID);
        $link.remove(); // junkit
      }
    }
    catch (err) {
      console.log('initQuestionText errored: '+err);
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


  // Handles the clicke event of the answer button
  Drupal.coralQA.coralAnswer.prototype.handleAnswerClick = function(ev) {
    try {
      if (!this.$btn.hasClass('ajax-processing')) {
        this.$btn.addClass('ajax-processing'); // no dupes
        this.settingsID = 'answers_new_answers_'+this.refID;
        ca = this;
        
        if (!Drupal.settings.hasOwnProperty('mosaicViews')) {
          Drupal.settings.mosaicViews = {};
        }
    
        // If we don't have settings for this, it's the first time we've looked at it
        if (!Drupal.settings.mosaicViews.hasOwnProperty('answers_new_answers_'+this.refID)) {
          var callback = function() {
            ca.settings = Drupal.settings.mosaicViews[ca.settingsID];
            ca.manageAnswers();
          };
          ca.setLoadStatus('loading'); // Set the loading status
          ca.getSettings(callback);    // Get the new settings and then process callback
        }
        
        // No settings loading! We have already loaded these answers
        else {
          ca.manageAnswers(); // manage them like never before
        }
      }
    }
    catch (err) {
      console.log('handleAnswerClick errored: '+err);
    }
  };


  // Show a set of Answers
  Drupal.coralQA.coralAnswer.prototype.manageAnswers = function() {
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
      
      if (this.$btn.hasClass('answers-hidden')) {
  
        this.$answerForm.parents('.panel-pane').eq(0).slideDown(350); // show the form
        this.$answersTgt.parents('.panel-pane').eq(0).slideDown(350, callback); // show answers 
        this.$btn.find('.arrow').addClass('arrow-down'); // change the arrow to down
        this.$btn.removeClass('answers-hidden'); // update the btn status
        
        
        var $view = $(this.$answersTgt).children('.view-answers');  // must only return children!
        var $cont = $view.children('.view-content');  // so we can't use find
        var $answers = $cont.children('.views-row'); // so be it. 
        var numAnswers = $answers.length;
        var moreHide = 'hide';
        
        // @TODO: I bet addedNew should be in here too
        if (Drupal.settings.mosaicViews.hasOwnProperty('answers_new_answers_'+this.refID)) {
          if (Number(numAnswers) < Number(this.settings.total_items)) {
            this.$answersTgt.parents('.panel-pane').eq(0).addClass('answers-more');
            //this.loadViewResults('answers', 'new_answers', this.refID);
            moreHide = ''; // hide this only if it's not needed... apparently it's needed here.
          }
          // This button appears when there are more items to load. Otherwise it's hidden
          //  starts off hidden here
          if (!this.$loadMore.length) { // add it only if it's not there
            this.$answersTgt.parent('.pane-content').append(this.loadMoreBtn('1', moreHide));
            this.$loadMore = this.$answersTgt.parent('.pane-content').find('.more-answers-'+this.refID);
          }
          
          // Clicking on the answer btn opens the full content
          if (this.hasTrimmed) {
            this.$trimmed.hide();
            this.$full.show();
          }
        }
        else {
          // @TODO: is it possible that we could be missing the settings?
        }
      }
      else {
        // hide the answers and form
        this.$answerForm.parents('.panel-pane').eq(0).slideUp(350); // hide the form
        this.$answersTgt.parents('.panel-pane').eq(0).slideUp(350); // hide the answers
        this.$btn.addClass('answers-hidden');
        this.$btn.find('.arrow').removeClass('arrow-down');
            
        if (this.hasTrimmed) { // show the trimmed version
          this.$trimmed.show();
          this.$full.hide();
        }
      }
    }
    catch (err) {
      console.log('manageAnswers errored: '+err);
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
              try {
                this.currentPage = classes[i].replace('page-', '');
              }
              catch (err) {
                console.log('handleMoreClick errored: '+err);
              }
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
      if (mode == 'full') {   // add new results to the end
        this.updateMoreBtn(); // Update the more button (page-#)
        this.$answersTgt.append(data); // append the new answers
      }
      else { // single mode - add to the start
        $rows = this.$answersTgt.find('.views-row');
        if (tot < 1 && !$rows.length) { // any rows already there?
          this.$answersTgt.html(''); // remove the default "empty" text
        }
        this.$answersTgt.prepend(data); // append the new answers
      }
      
      // get timeago et.al. to re-run on the nodes
      Drupal.attachBehaviors();
        
      if ($(this.$btn).hasClass('answers-hidden')) {
        $(this.$btn).addClass('answers-visible').removeClass('answers-hidden');
        $(this.$btn).find('.arrow').addClass('arrowDown');
      }
      
      this.$btn.removeClass('ajax-processing'); // enable the user to click again
      this.$loadMore.find('span span').removeClass('throbber'); // disable throbber
    }
    catch (err) {
      console.log('processViewResults errored: '+err);
    }
  };
  
  
  // Attaches and configures a "to parent" link on the content 
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
  

  // Get the settings for this item and add to the associated theme settings
  Drupal.coralQA.coralAnswer.prototype.getSettings = function(callback) {
    try {
      ca = this;
      ca.settingsID = 'answers_new_answers_'+ca.refID;
        
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
      function(data) { console.log('err'); }); // failure @TODO: get a real error handler;
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
      
        Drupal.coral_ajax.view_info('answers', {
          display_id: 'new_answers',
          args : refID,
        },
        function(data) {
          settingsID = 'answers_new_answers_'+refID;
          Drupal.settings.mosaicViews[settingsID] = data;
        },
        function(data) { console.log('err'); }); // failure @TODO: get a real error handler;
      });
    }
    catch (err) {
      console.log('updateSettings errored: '+err);
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
          function(err) {}
        );
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
  
        $viewRow.css('padding-bottom', '1px');
        $newAnswer.animate({ backgroundColor: '#F1F1F1' }, 3000, 'swing', function() {
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
      return '<a href="#" class="btn load-more more-answers-'+this.refID+' page-'+page+' '+hide+'">Load more<span class="no-js"><span></span></a>';
    }
    catch (err) {
      console.log('loadMoreBtn errored: '+err);
    }
  };

  
  // Updates the more button or removes it if we have no more items
  Drupal.coralQA.coralAnswer.prototype.updateMoreBtn = function() {
    try {
      if ((Number(this.currentPage) + 1) * Number(this.settings.limit) >= Number(this.settings.total_items)) {
        this.$loadMore.hide(); // No more to show, hide the button
        this.$answersTgt.parents('.panel-pane').eq(0).removeClass('answers-more'); // get rid of empty space
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
  
  
  // Handle the click even on the trimmed link
  Drupal.coralQA.coralAnswer.prototype.trimmedClick = function(ev) {
    try {
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
    }
    catch (err) {
      console.log('trimmedClick errored: '+err);
    }
  };
 
})(jQuery);



