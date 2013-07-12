
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
    this.$question = $question;
    
    // Identification and settings
    this.$btn = $question.find('.btn.answer');
    this.answerClass = '';
    this.answerID = '';
    
    // Setup and more:
    $(this.$question).find('.pane-coral-answers-target').hide(); // hide the form.        
    $(this.$question).find('.pane-coral-answer-form textarea').attr('rows', '5'); // we only want 5 cols
    
    var coralAnswer = this;
    var AnswerView = Backbone.View.extend({
      // Home
      el: this.$question,
      
      // Settings and conf
      coralAnswer: coralAnswer,
      
      // events
      events: {
        'click .btn.answer': 'answerClick'
      },
           
      // Init
      initialize: function() {
        coralAnswer.initializeBtn();
        _.bindAll(this, 'answerClick');
      },
     
      answerClick: function(ev) {
        coralAnswer.handleClick(ev);
        event.preventDefault();
      },
    });
    
    new AnswerView();
  };
  
  Drupal.coralQA.coralAnswer.prototype.initializeBtn = function() {
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
    
    $(this.$question).find('.pane-coral-answers-target').hide(); 
  };
  
  // Handles the clicke event of the answer button
  Drupal.coralQA.coralAnswer.prototype.handleClick = function(ev) {
    // store the coralAnswer object for use in the callbacks
    // @TODO: Add waiting gif or something to let the user know something is happening!
    if ($(this.$btn).hasClass('answers-hidden')) {
      this.loadViewResults('answers', 'new_answers');  
    }
    else {
      // @TODO Hide answers and for on demand
      $(this.$btn).addClass('answers-hidden').removeClass('answers-visible');
      $(this.$btn).find('.arrow').removeClass('arrowDown');
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
      console.log(data);
      var $answersTarget = $(ca.$question).find('.answers-tgt');
      $answersTarget.append(data).after('<span>TESTING</span>');
      $(ca.$btn).addClass('answers-visible').removeClass('answers-hidden');
      $(ca.$btn).find('.arrow').addClass('arrowDown');
    }, 
    function(data) {
      console.log('err');
    });
  };
  
})(jQuery);