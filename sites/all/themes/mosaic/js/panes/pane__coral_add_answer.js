
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
        //  If there is no question there is nothing
        //  for the user to answer.
        $questions = $('.node-question:not(".processed")');
        
        $questions.each(function(i) {
          // The questions... Oh, the questions
          new Drupal.coralQA.coralAnswer($(this));
          
          // Must ensure we don't re-attach the handlers
          $(this).addClass('processed');
        });        
      }
      catch(err) {
        console.log('coralAnswerInit reported errors! Error: '+err);
      }
    }
  };


  // Primary initiator of all answering related activities
  Drupal.coralQA.coralAnswer = function($question) {
    
    // jQuery objects of note
    this.$question = $question; // everything centers around the Q
    
    // Tertiary jQuery objects
    this.$btn = $question.find('.btn.answer');
    this.$answerForm = $(this.$question).find('.pane-coral-answer-form');
    this.$answersTgt = $(this.$question).find('.pane-coral-answers-target');
    this.$loadMore = this.$answersTgt.find('.load-more');
    
    // Setup and more
    // --------------
    // $loadMore may or may not exist. It usually does not
    //  on the first page run (document.loaded). In this case
    //  we should init a few items.
    if (!this.$loadMore.length) {
      
      // Identification and settings
      this.answerClass;
      this.answerID;
      this.settingsID;
      this.settings;
      this.currentPage; 
      
      // hide the answers container
      this.$answersTgt.hide();
      
      // we only want 5 cols - then we hide the form
      this.$answerForm.find('textarea').attr('rows', '5'); 
      this.$answerForm.hide();
    }
        
    var coralAnswer = this;
    var AnswerView = Backbone.View.extend({
      // Home
      el: this.$question,
      
      // Settings and conf
      coralAnswer: coralAnswer,
      
      // events
      events: {
        'click .btn.answer': 'answerClick', // show answers and form
        'click .load-more' : 'moreClick',   // get another set from the view
        'click .form-actions .form-submit': 'formSubmit' // submit an answer
      },
           
      // Init
      initialize: function() {
        coralAnswer.initAnswerBtn();
        _.bindAll(this, 'answerClick', 'moreClick', 'formSubmit');
      },
     
      answerClick: function(ev) {
        ev.preventDefault();
        coralAnswer.handleAnswerClick(ev);
      },
      
      moreClick: function(ev) {
        ev.preventDefault();
        coralAnswer.handleMoreClick(ev);
      },
      
      formSubmit: function(ev) {
        ev.preventDefault();
        coralAnswer.submitForm(ev);        
      }
    });
    
    new AnswerView();
  };


  // Sets up the Answer button and pulls data from it.
  Drupal.coralQA.coralAnswer.prototype.initAnswerBtn = function() {
    // find this button's nid and ensure the AnswerView's  
    var classes = $(this.$btn).attr('class');
    classes = classes.split(" ");
    for (cls in classes) {
      var c = classes[cls];
      if (c.match(/answer-\d+/)) {
        this.answerClass = c; // capture the class
        this.answerID = c.replace('answer-', ''); // and the nid
      }
    }
  };


  // Handles the clicke event of the answer button
  Drupal.coralQA.coralAnswer.prototype.handleAnswerClick = function(ev) {
    // store the coralAnswer object for use in the callbacks
    // @TODO: Add waiting gif or something to let the user know something is happening!

    //if (this.$btn.hasClass('answers-hidden') && !this.$btn.hasClass('processed')) {
    if (this.$btn.hasClass('answers-hidden')) {

      //this.loadViewResults('answers', 'new_answers');
      this.$answerForm.show(); // show the form
      this.$answersTgt.show(); // show answers 
      this.$btn.find('.arrow').addClass('arrow-down');
      //this.$btn.removeClass('answers-hidden').addClass('answers-visible').addClass('processed');
      
      this.$btn.removeClass('answers-hidden');
      
      // The answers are hidden.  We are starting with the first set
      //  already loaded.  We need to discover if there are more.
      var $answers = $(this.$answersTgt).find('.node-answer');
      var numAnswers = $answers.length;
      var moreHide = 'hide'; // a hide class
      
      if (Drupal.settings.mosaicViews.hasOwnProperty('answers_new_answers_'+this.answerID)) {
        this.settingsID = 'answers_new_answers_'+this.answerID;
        this.settings   = Drupal.settings.mosaicViews[this.settingsID];
        
        if (Number(numAnswers) < Number(this.settings.total_items)) {
          moreHide = ''; // hide this only if it's not needed... apparently it's needed here.
        }
      }
      // This button appears when there are more items to load. Otherwise it's hidden
      if (!this.$loadMore.length) { // add it only if it's not there
        this.$answersTgt.append(this.loadMoreBtn('1', moreHide));
        this.$loadMore = this.$answersTgt.find('.load-more');
      }
    }
    else {
      // hide the answers and form
      this.$answerForm.hide(); // hide the form
      this.$answersTgt.hide(); // hide the answers
      this.$btn.addClass('answers-hidden');
      this.$btn.find('.arrow').removeClass('arrow-down');
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
    this.loadViewResults('answers', 'new_answers');
  };


  // Handles loading the answers view
  Drupal.coralQA.coralAnswer.prototype.loadViewResults = function(view_name, view_display) {
    var ca = this; // for use later
    var offset = String(Number(this.currentPage) * Number(this.settings.limit)); // current offset

    // enable a throbber
    this.$loadMore.find('.no-js').removeClass('no-js').addClass('ajax-progress');
    this.$loadMore.find('span span').addClass('throbber');

    // Render the view upon the world! Go view, go!
    Drupal.coral_ajax.view_render(view_name, {
      display_id: view_display,
      args : [ca.answerID],
      offset : offset,
      limit : this.settings.limit
    },
    function(data) { ca.processViewResults(data); }, // success
    function(data) { console.log('err'); });         // failure
    // and so ends the adventure of the ajax view request... the end?
  };


  // Runs after the view succeeds in returning the next set.
  Drupal.coralQA.coralAnswer.prototype.processViewResults = function(data) {
    this.$answersTgt.find('.answers-tgt').append(data); // append the new answers
    this.updateMoreBtn();     // Updates the more button or removes it if we have no more items 
    Drupal.attachBehaviors(); // get timeago to re-run on the nodes
      
    if ($(this.$btn).hasClass('answers-hidden')) {
      $(this.$btn).addClass('answers-visible').removeClass('answers-hidden');
      $(this.$btn).find('.arrow').addClass('arrowDown');
    }
      
    this.$loadMore.find('span span').removeClass('throbber'); // disable throbber
  };
  
  // Handles submission of the node answer form
  Drupal.coralQA.coralAnswer.prototype.submitForm = function(ev) {
    
    ca = this;
    
    var $form    = $(ev.currentTarget).parents('form');
    var title    = $form.find('input[name="title"]').val();
    var body     = $form.find('.field-name-body textarea.text-full').val();
    var question = $form.find('.field-name-field-question .form-text').val();
    var langNone = Drupal.settings.coral_qa_manager.language_none || "und";
        
    // Setup our node
    var node = {
      "type":"answer",
      "title":title,
      "language":langNone,
      "body":{langNone:{"0":{"value":body}}},
      "field_question":{langNone:{"0":{"target_id":question}}}
    };
        
    Drupal.coral_ajax.node_create(node, 
      function(data, msg, xhr) { 
        //console.log(data); console.log(msg); 
        if (msg == 'success') {
          ca.clearForm($form); // clear the form
        }
      }, 
      function(err){}
    );
  };
  
  
  // Handles clearing of the node answer form
  Drupal.coralQA.coralAnswer.prototype.clearForm = function($form) {
    $form.find('input[name="title"]').val('');
    $form.find('.field-name-body textarea.text-full').val('');      
  }

  // Returns a Load More link
  Drupal.coralQA.coralAnswer.prototype.loadMoreBtn = function(page, hide) {
    return '<a href="#" class="btn load-more page-'+page+' '+hide+'">Load more<span class="no-js"><span></span></a>';
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
})(jQuery);
