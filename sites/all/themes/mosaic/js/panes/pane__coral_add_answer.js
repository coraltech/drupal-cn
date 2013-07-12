
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
        $questions = $('.node-question');
        
        $questions.each(function(i) {
          // The questions... Oh, the questions
          new Drupal.coralQA.coralAnswer($(this));
        });        
      }
      catch(err) {
        console.log('coralAnswerInit reported errors! Error: '+err);
      }
    }
  };
  
  
  Drupal.coralQA.coralAnswer = function($question) {
    
    // jQuery objects of note
    this.$question = $question; // everything centers around the Q
    
    // Tertiary jQuery objects
    this.$btn = $question.find('.btn.answer');
    this.$answerForm = $(this.$question).find('.pane-coral-answer-form');
    this.$answersTgt = $(this.$question).find('.pane-coral-answers-target');
    this.$loadMore = ''; // holds the more link once it's generated!
    
    // Identification and settings
    this.answerClass = '';
    this.answerID = '';
    
    
    // Setup and more:
    this.$answersTgt.hide(); // hide the answers container

    // we only want 5 cols - then we hide the form
    this.$answerForm.find('textarea').attr('rows', '5'); 
    this.$answerForm.hide();

    var coralAnswer = this;
    var AnswerView = Backbone.View.extend({
      // Home
      el: this.$question,
      
      // Settings and conf
      coralAnswer: coralAnswer,
      
      // events
      events: {
        'click .btn.answer': 'answerClick',
        'click .load-more' : 'moreClick'
      },
           
      // Init
      initialize: function() {
        coralAnswer.initAnswerBtn();
        _.bindAll(this, 'answerClick', 'moreClick');
      },
     
      answerClick: function(ev) {
        ev.preventDefault();
        coralAnswer.handleClick(ev);
      },
      
      moreClick: function(ev) {
        ev.preventDefault();
        console.log(ev);
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
        this.answerClass = c;
        this.answerID = c.replace('answer-', ''); 
      }
    }
  };
  
  // Handles the clicke event of the answer button
  Drupal.coralQA.coralAnswer.prototype.handleClick = function(ev) {
    // store the coralAnswer object for use in the callbacks
    // @TODO: Add waiting gif or something to let the user know something is happening!
    if (this.$btn.hasClass('answers-hidden')) {
      //this.loadViewResults('answers', 'new_answers');
      this.$answerForm.show(); // show the form
      this.$answersTgt.show(); // show answers 
      this.$btn.find('.arrow').addClass('arrow-down');
      this.$btn.removeClass('answers-hidden').addClass('answers-visible');
      
      // The answers are hidden.  We are starting with the first set
      //  already loaded.  We need to discover if there are more.
      var $answers = $(this.$answersTgt).find('.node-answer');
      var numAnswers = $answers.length;
      var moreHide = 'hide'; // a hide class
      
      if (Drupal.settings.mosaicViews.hasOwnProperty('answers_new_answers_'+this.answerID)) {
        var viewSettings = Drupal.settings.mosaicViews['answers_new_answers_'+this.answerID];
        if (viewSettings.hasOwnProperty('total_items') && (Number(numAnswers) < Number(viewSettings.total_items))) {
          // If there is no more button in this answer set, add one.
          moreHide = ''; // hide this if it's not needed
        }
      }
      this.$answersTgt.append('<a href="#" class="load-more '+moreHide+'">Load more</a>');
      
    }
    else {
      // hide the answers and form
      this.$answerForm.hide(); // hide the form
      this.$answersTgt.hide(); // hide the answers
      this.$btn.addClass('answers-hidden').removeClass('answers-visible');
      this.$btn.find('.arrow').removeClass('arrow-down');
    }
  };
  
  // Handles loading the answers view
  Drupal.coralQA.coralAnswer.prototype.loadViewResults = function(view_name, view_display) {
    var ca = this;
    Drupal.coral_ajax.view_render(view_name, {
      display_id: view_display,
      args : [ca.answerID],
      offset : '0'//, page * settings.lmt,
      //limit : settings.lmt
    },
    function(data) {
      ca.$answerForm.show(); // show the form
      ca.$answersTgt.show().append(data); // show the answers
      $(ca.$btn).addClass('answers-visible').removeClass('answers-hidden');
      $(ca.$btn).find('.arrow').addClass('arrowDown');
    }, 
    function(data) {
      console.log('err');
    });
  };
  
})(jQuery);