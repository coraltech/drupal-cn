
// Registers the coralQA namespace
Drupal.coralQA = Drupal.coralQA || {};

// ----------------------------------------------------------------------
// Add answer button manager
//
//  Controls answer button events and answers display.
//  @TODO: decide if we want to try to impliment 
//         a ajax enabled backbone model to submit
//         and display answers
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.coralAnswerInit = {    
    attach : function(context, settings) {
      
      try { // Use try to prevent systemic failure
        
        // Answers revolve around the parent question.
        //  If there is no question there is nothing.
        $questions = $('.node-question:not(".question-processed")');
        $questions.each(function(i) {
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
    
    // Top level variable
    this.refID; // all other things revolve around this - question nid 
    
    // jQuery objects of note
    this.$question = $question; // everything centers around the Q
    
    //console.log(this.$question);
    this.initID(this.$question, /node-\d+/, 'node-');
    
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
        coralAnswer.initQuestionText(); // check for summary and hide full text if avail.
        _.bindAll(this, 'answerClick', 'moreClick', 'formSubmit', 'trimmedClick');
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
      }
    });
    
    new AnswerView();
  };


  // Ensure the full node is hidden if the trimmed is shorter
  Drupal.coralQA.coralAnswer.prototype.initQuestionText = function() {
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


  // Sets up the Answer button and pulls data from it.
  Drupal.coralQA.coralAnswer.prototype.initID = function($obj, pat, cls) {
    
    var objPattern = pat || /answer-\d+/;
    var objClass = cls || 'answer-';
    
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


  // Handles the clicke event of the answer button
  Drupal.coralQA.coralAnswer.prototype.handleAnswerClick = function(ev) {

    // If hidden, unhide!
    if (this.$btn.hasClass('answers-hidden')) {

      this.$answerForm.parents('.panel-pane').eq(0).show(); // show the form
      this.$answersTgt.parents('.panel-pane').eq(0).show(); // show answers 
      this.$btn.find('.arrow').addClass('arrow-down'); // change the arrow to down
      this.$btn.removeClass('answers-hidden'); // update the btn status
      
      // The answers are hidden.  We are starting with the first set
      //  already loaded.  We need to discover if there are more.
      var $answers = $(this.$answersTgt).find('.node-answer');
      var numAnswers = $answers.length;
      var moreHide = 'hide'; // a hide class
      
      if (Drupal.settings.mosaicViews.hasOwnProperty('answers_new_answers_'+this.refID)) {
        this.settingsID = 'answers_new_answers_'+this.refID;
        this.settings   = Drupal.settings.mosaicViews[this.settingsID];
        
        if (Number(numAnswers) < Number(this.settings.total_items)) {
          this.$answersTgt.parents('.panel-pane').eq(0).addClass('answers-more');
          moreHide = ''; // hide this only if it's not needed... apparently it's needed here.
        }
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
      // hide the answers and form
      this.$answerForm.parents('.panel-pane').eq(0).hide(); // hide the form
      this.$answersTgt.parents('.panel-pane').eq(0).hide(); // hide the answers
      this.$btn.addClass('answers-hidden');
      this.$btn.find('.arrow').removeClass('arrow-down');
      
      if (this.hasTrimmed) { // show the trimmed version
        this.$trimmed.show();
        this.$full.hide();
      }
    }
  };


  // Process a $loadMore click! Fetches from the view
  Drupal.coralQA.coralAnswer.prototype.handleMoreClick = function(ev) {
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
    this.loadViewResults('answers', 'new_answers', this.refID);
  };


  // Handles loading the answers view
  //  NOTE: It's a good idea to ALWAYS pass the arguments.  It is possible that ca.answerID may not be the one you want?
  Drupal.coralQA.coralAnswer.prototype.loadViewResults = function(view_name, view_display, args, callback, mode, offset, limit) {
    var ca = this; // for use later

    var args     = [args]   || [ca.refID]; // the view args
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
      ca.processViewResults(data, mode); 
      if (typeof(callback) == 'function') callback(data, mode); // fastest method: no ducktyping 
    },
    function(data) { console.log('err'); }); // failure @TODO: get a real error handler
    // and so ends the adventure of the ajax view request... the end?
  };


  // Runs after the view succeeds in returning the next set.
  Drupal.coralQA.coralAnswer.prototype.processViewResults = function(data, mode) {
    
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
      if (tot < 1) {
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
      
    this.$loadMore.find('span span').removeClass('throbber'); // disable throbber
  };


  // Handles submission of the node answer form
  Drupal.coralQA.coralAnswer.prototype.submitForm = function(ev) {
    
    ca = this; // capture the coralAnswer for use later
    
    var $form   = $(ev.currentTarget).parents('form');
    var $submit = $(ev.currentTarget);
    
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
          // @NOTE: this may still show the users post if they are browsing 
          //  an active thread.
          ca.addedNew = Number(ca.addedNew) + 1;
        }
      },
      // @TODO: process errors (missing fields etc)
      function(err) {}
    );
  };
  
  
  // Loads up this users "just submitted" answer and puts it in the list.
  //  eg: loadViewResults(view_name, view_display, args, callback, mode, offset, limit)
  Drupal.coralQA.coralAnswer.prototype.addNewAnswer = function(data) {
    var ca = this; // keep this!
    var callback = function() { // stuff we do on the there-after...
      ca.$answerForm.find('.form-actions').find('.ajax-progress').remove();
      var $newAnswer = ca.$question.find('.node-'+data.nid).css("background", "#FFF6B6");
      $newAnswer.animate({ backgroundColor: '#F1F1F1' }, 3000);
    };
    this.loadViewResults("answers", "this_answer", data.nid, callback, "single", "0", "1");
  };
  
  
  // Handles clearing of the node answer form
  Drupal.coralQA.coralAnswer.prototype.clearForm = function($form) {
    $form.find('input[name="title"]').val('');
    $form.find('.field-name-body textarea').val('');
  };


  // Returns a Load More link
  Drupal.coralQA.coralAnswer.prototype.loadMoreBtn = function(page, hide) {
    return '<a href="#" class="btn load-more more-answers-'+this.refID+' page-'+page+' '+hide+'">Load more<span class="no-js"><span></span></a>';
  };

  
  // Updates the more button or removes it if we have no more items
  Drupal.coralQA.coralAnswer.prototype.updateMoreBtn = function() {
    if ((Number(this.currentPage) + 1) * Number(this.settings.limit) >= Number(this.settings.total_items)) {
      this.$loadMore.hide(); // No more to show, hide the button
    }
    else { // increment the page number
      this.$loadMore.removeClass('page-'+this.currentPage).addClass('page-'+String((Number(this.currentPage) + 1)));
    }
  };
  
  
  // Handle the click even on the trimmed link
  Drupal.coralQA.coralAnswer.prototype.trimmedClick = function(ev) {
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



