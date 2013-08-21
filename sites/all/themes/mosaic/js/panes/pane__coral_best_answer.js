
// Registers the coralQA namespace
Drupal.coralQA = Drupal.coralQA || {};

// ----------------------------------------------------------------------
// Get more questions for this view
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.coralBestAnswerInit = {    
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
        var $questions = $('.node-question'); // Get the questions (All of them!)
        $questions.each(function() {
          new Drupal.coralQA.coralBestAnswers($(this));
        });
      }
      catch(err) {
        console.log('coralBestAnswerInit reported errors! Error: '+err);
      }
    }
  };
  
  
  // Finds this questions visible answers and updates the 
  //  best answer button if it is appropriate.
  Drupal.coralQA.coralBestAnswers = function($question) {
    try {
      
      this.$question = $question; // remember the question
      this.answers = {}; // will contain a hash of answers {nid: $node}
      this.refID; // node id of the question
      this.author; // will contain the author info
      this.currentSelected; // Holds the nid of the selected node if there is one.
            
      var coralBestAnswers = this;
      
      // Get ready for some fun stuff!
      coralBestAnswers.initQuestion();

      // Events
      this.events = {};
      for (id in this.answers) this.events['click .best-answer-'+id] = 'bestAnswer';

      var BestAnswersView = Backbone.View.extend({
        // Home
        el: this.$question,
        
        // Settings and conf
        coralBestAnswers: coralBestAnswers,
        
        // events
        events: coralBestAnswers.events, // keyed events
             
        // Init
        initialize: function() {
          _.bindAll(this, 'bestAnswer');
        },
       
        // callbacks
        bestAnswer: function(ev) {
          ev.preventDefault();
          coralBestAnswers.bestAnswerClick(ev);
        }
      });
      
      new BestAnswersView();
    }
    catch (err) {
      console.log('coralBestAnswers errored: '+err);
    }
  };
  
  
  Drupal.coralQA.coralBestAnswers.prototype.bestAnswerClick = function(ev) {
    try {
      var cba = this; // save this!

      if (!$(ev.currentTarget).hasClass('ajax-processing')) {
        // Get question nid info      
        var questionID     = this.getMatch(/^node-\d+/, this.$question.attr('class'));
        questionID         = questionID.replace('node-', '');
        
        // Get answer nid info
        var $bestAnswerBtn = $(ev.currentTarget).addClass('ajax-processing');
        var answerID       = this.getMatch(/^best-answer-\d+/, $bestAnswerBtn.attr('class'));
        answerID           = answerID.replace('best-answer-', '');
        
        // Add the throbber class or make the component
        var $progress = $bestAnswerBtn.find('.ajax-progress span');
        if ($progress.length) $progress.addClass('throbber');
        else $bestAnswerBtn.append('<span class="ajax-progress"><span class="throbber"></span></span>');
        
        // Get ready to send the changes
        var object = {field_answer: {'und': {'0': answerID}}};
        Drupal.coral_ajax.node_save(questionID, object, 
          // Success! - most likely
          function(output, message, $request) { 
            if (message == 'success') { // truly success
              $bestAnswerBtn.find('.throbber').removeClass('throbber'); // remove the throbber
              $bestAnswerBtn.removeClass('ajax-processing'); // release control of button
              
              // Show a success message (like flagging)
              cba.reportStatus($bestAnswerBtn, 'Best answer selection updated!', 'success');
              
              // Replace/Move best asnwer node as needed
              cba.moveAnswer($bestAnswerBtn, answerID);
            }
          },
          // Fail! @TODO: do something useful here ;-)
          function($request, message, error) {
            console.log('Transmission of best answer failed!');
          }
        );
      }
    }
    catch (err) {
      console.log('bestAnswerClick errored: '+err);
    }
  };


  // 
  Drupal.coralQA.coralBestAnswers.prototype.moveAnswer = function($btn, answerID) {
    try {
      var cba = this;

      var callback = function() {

        var $answersTgt = cba.$question.find('.pane-coral-answers-target');
        var $answer = $answersTgt.find('.node-'+answerID);
        
        cba.refreshBest(answerID, $answer);
      }

      // Stuff that lets the user know something is happening
      var $bestTgt = this.$question.find('.pane-coral-best-answer-target'); // get the best ans tgt
      var $bestNode = $bestTgt.find('.node'); // current best answer
      
      if ($bestNode.length) { // if we already have one
        var tgtPosition = $bestNode.position(); // current position
        var tgtHeight = $bestNode.height();     // current height
        var tgtWidth = $bestNode.width();       // current width
        $bestTgt.prepend('<div class="best-switch"><span style="margin-top: '+((tgtHeight/2)-7)+'px"></span></div>'); // add a cover that will contain a gif
        $bestTgt.find('.best-switch').css({
          'position':'absolute', 
          'top':tgtPosition.top+'px', 
          'left': tgtPosition.left+'px', 
          'height':tgtHeight+'px',
          'width':tgtWidth+'px',
          'z-index': 3
        });
      }

      // re-add click functionality to the answer btn
      this.$question.find('.btn.answer').off('click').click(function() { 
        $bestTgt.find('.node-answer').slideToggle(200); 
        $bestTgt.find('.selected-title').slideToggle(200);
      });
      
      setTimeout(callback, 1950); // wait for the message to complete
    }
    catch (err) {
      console.log('moveAnswer errored: '+err);
    }
  };


  // Refresh the target panes and nodes
  //  $answer is the answer the user has selected
  //  $oldAns is the old selected answer
  Drupal.coralQA.coralBestAnswers.prototype.refreshBest = function(answerID, $answer) {
    try {
      var cba = this;
    
      // Append the data - actually called second -_-
      var callback = function(data) {
        var $newAnswer = $(data).find('.node-answer');
        
        var $bestAnswerTgt = cba.$question.find('.pane-coral-best-answer-target');
        var $bestAnswer = $bestAnswerTgt.find('.node-answer');

        if ($newAnswer.length) {
          var $cover = $bestAnswerTgt.find('.best-switch');
          
          // Remove the cover if it's present
          if ($cover.length) $cover.remove();
          
          // Target empty? - add the pane title
          if (!$bestAnswer.length) $bestAnswerTgt.append('<h2 class="selected-title">Selected answer</h2>');
          
          // The answer that will live in the best answer target
          $newAnswer.find('.pane-coral-best-answer').hide();

          // Answers that live in the additional answers target
          $answersTgt = cba.$question.find('.pane-coral-answers-target');
          $answers = $answersTgt.find('.node-answer');
          $answers.each(function() { // un-hide the best answer button
            if (!$(this).hasClass('node-'+answerID)) { // if this isnt the selected answer
              $(this).find('.pane-coral-best-answer').show().find('a').removeClass('hide');
            }
          });
          
          $answer.find('.pane-coral-best-answer').hide();
        
          // Add this newly selected answer
          $bestAnswerTgt.find('.node').remove(); // remove old one
          cba.$question.find('.pane-coral-best-answer-target').append($newAnswer); // add new one
          cba.currentSelected = answerID; // update the currentSelected
          
          Drupal.attachBehaviors(); // reset behaviors
        }
      };
      
      // Load the answer
      this.getAnswer(answerID, callback);  
    }
    catch(err) {
      console.log('refreshBest errored: '+err);
    }
  };
  

  // You got questions? we got answers!
  Drupal.coralQA.coralBestAnswers.prototype.getAnswer = function(answerID, callback) {
    try {
      // Render the view upon the world! Go view, go!
      Drupal.coral_ajax.view_render('answers', {
        display_id: 'this_answer',
        args : [answerID]
      },
      function(data) { 
        if (typeof(callback) == 'function') callback(data); // fastest method: no ducktyping 
      },
      function(data) { console.log('err'); }); // failure @TODO: get a real error handler
      // and so ends the (relatively short) adventure of the ajax view request... the end?
    }
    catch (err) {
      console.log('getAnswer errored: '+err);
    }
  };


  // Report the status of the submission
  Drupal.coralQA.coralBestAnswers.prototype.reportStatus = function($btn, message, state) {
    try {
      $btn.append('<span class="best-ans-msg msg-'+state+'">'+message+'</span>');
      $btn.find('.best-ans-msg').animate({opacity: 0}, 3000, function() {
        $btn.find('.best-ans-msg').remove(); // we don't need this anymore.
      });
    }
    catch (err) {
      console.log('reportStatus errored: '+err);
    }
  };


  // Set up this question's exposed answers
  Drupal.coralQA.coralBestAnswers.prototype.initQuestion = function() {
    try {
      var cba = this; // store this for later
    
      // Get this view's dom id - we'll use it as a referencing id so everything stays neat.
      this.questionID = this.getMatch(/^node-\d+/, this.$question.attr('class'));
      this.questionID = this.questionID.replace('node-', ''); // only the numbers

      var $authorInfo = this.$question.find('.editor_info-'+this.questionID);
      this.author = $authorInfo.find('.statdata').text(); // this question's author'
      this.userID = $authorInfo.find('.statid').text();   // this questions's user id
    
      // hide the best answer button on the question
      //  it's needed on the question only so that the 
      //  js can load when no answers were loaded.
      this.$question.find('.pane-coral-best-answer').eq(0).hide();
      
      var $selected = this.$question.find('.pane-coral-best-answer-target .node-answer');
      if ($selected.length) {
        this.currentSelected = this.getMatch(/^node-\d+/, $selected.attr('class'));
        this.currentSelected = this.currentSelected.replace('node-', ''); // only the numbers
      }
      
      var currentUser = Drupal.settings.coral_qa_manager.current_user; // get the user info
      if (currentUser.uid == this.userID) {
        // Get all un-processed answers from the view of answers
        var $answers = this.$question.find('.pane-coral-answers-target .node-answer:not(".best-answer-processed")');
        $answers.each(function() {
          // Once we know if this logged in user is the owner of the question,
          //  we can show the Best answer button and activate it.
          cba.initAnswer($(this));   
        });
      }
    }
    catch (err) {
      console.log('initQuestion errored: '+err);
    }
  };


  // Initialize the answer and save it's object
  Drupal.coralQA.coralBestAnswers.prototype.initAnswer = function($answer) {
    try {
      $answer.addClass('best-answer-processed'); // we won't be doing this one again
      answerID = this.getAnswerID($answer);      // current answer id
     
      // Save the answer object
      this.answers[answerID].$answer = $answer;   // save it. maybe it's useful?
      
      // Save the button for this answer
      this.answers[answerID].$answerBtn = this.answers[answerID].$answer.find('.best-answer-'+answerID);

      // Regular answer
      if (answerID != this.currentSelected) {
        // Remove the hidden class
        this.answers[answerID].$answerBtn.removeClass('hide');
      }
      
      // The currently selected answer
      else {
        // Hide best answer button
        this.answers[answerID].$answer.addClass('selected-best'); // give the node a class
        this.answers[answerID].$answer.children('.answer-node-pane-title').append('<span class="best-ans"></span>'); // add a new icon
        this.answers[answerID].$answer.find('.pane-coral-best-answer').hide(); // hide the best answer button (no re-click)
      }
    }
    catch (err) {
      console.log('initAnswer errored: '+err);
    }
  };
  
  
  // Get this answer's nid
  Drupal.coralQA.coralBestAnswers.prototype.getAnswerID = function($answer) {
    try {
      var $bestAnswerBtn = $answer.find('.best-answer');
      var answerID = this.getMatch(/^best-answer-\d+/, $bestAnswerBtn.attr('class'));
      answerID = answerID.replace('best-answer-', ''); // initialize this answer's id info
      
      if (!this.answers.hasOwnProperty(answerID)) this.answers[answerID] = {};
      this.answers[answerID].nid = answerID; 
      return answerID; // current answer id
    }
    catch (err) {
      console.log('getAnswerID errored: '+err);
    }  
  };


  // Find the class that matches the pattern
  Drupal.coralQA.coralBestAnswers.prototype.getMatch = function(pattern, classes) {
    try {
      classes = classes.split(' ');
      for (cls in classes) { 
        if (classes[cls].match(pattern)) { 
          return classes[cls]; // found it! 
        }
      } 
      return ''; // no results
    }
    catch (err) {
      console.log('getMatch errored: '+err);
    }
  };


})(jQuery);

