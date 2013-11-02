// This file will provide support for mosaic box
// mosiacBox will highlight the question and it's contents
//  when the Answers link is clicked

// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// Document loaded!
(function($) {

  Drupal.behaviors.mosaicBoxInit = {
    attach : function(context, settings) {
      try {// Use try to prevent systemic failure
        
        // We have to wait for the other JS in the site to finish before
        //  we compute the overlay and get it ready for action.
        setTimeout(function() {
          var mboxOverlay = new Drupal.mosaic.mosaicBoxOverlay();
          
          // Overlays only apply to questions
          $('.node-question.node-teaser:not(".mbox-processed")').each(function(i) {
            
            // Only apply if not a full node or a child of the parent node container
            if (!$(this).parents('.node-full-node.node-question').length &&
                !$(this).parents('.pane-coral-parent-content').length) {
                          
              // The questions... Oh, the questions
              new Drupal.mosaic.mosaicBox($(this), mboxOverlay);

              // Must ensure we don't re-attach the handlers
              $(this).addClass('mbox-processed');
            }
          });
        }, 500); // wait a sec / 2
      } catch (err) {
        console.log('mosaicBoxInit() reported errors. Error: ' + err);
      }
    }
  };


  // Initialize the overlay
  Drupal.mosaic.mosaicBoxOverlay = function() {
    try {
      this.initOverlay();
      this.updateOverlay();
    }
    catch (err) {
      console.log('mosaicBoxOverlay errored: '+err);
    }
  };


  // MosaicBox will surround the question and it's contents
  //  this is so it is easier to tell where it ends.
  Drupal.mosaic.mosaicBox = function($question, mbOverlay) {
    try {
      if ($question.length) {
        this.id;
        
        this.$question = $question;
        this.$btn      = $question.find('.btn.answer');
        this.mbOverlay = mbOverlay;
        
        // will store a reference to an ongoing close button position monitor (if one is visible)
        this.closeInterval = false;
        
        this.getID(this.$btn);

        this.events = {};
        this.events['click .btn.answer-'+this.id] = 'answerClick';
        
        var mosaicBox = this;
        var MosaicBoxView = Backbone.View.extend({
          // Home
          el : this.$question,

          // Settings and conf
          mosaicBox : mosaicBox,

          // events
          events : mosaicBox.events, // keyed events
          
          // Init
          initialize : function() {
            _.bindAll(this, 'answerClick'); //, 'closeClick');
          },

          // Events
          // Answer link       console.log(this);initiates overlay
          answerClick: function(ev) {
            mosaicBox.handleAnswerClick(ev);
          }
        });
        
        new MosaicBoxView();
      }
    } catch (err) {
      console.log('mosaicBox errored: ' + err);
    }
  };
  
  
  // Handles the opeing of the answers
  //  Will cause the overlay to engage, etc...
  Drupal.mosaic.mosaicBox.prototype.handleAnswerClick = function(ev) {
    try {
      this.initClose(); // start up the close button
      
      this.updateQBox(true); // Initialize the Question box styles
      
      this.mbOverlay.$overlay.fadeTo(50, .65);
      this.mbOverlay.$overlay.removeClass('hidden');
      
      var mbo = this.mbOverlay;
      setTimeout(function() {
        mbo.updateOverlay();
      }, 250); // leave time for transistions and so on
    }
    catch (err) {
      console.log('handleAnswerClick errored: '+err);
    }
  };


  // Box state around the question. Truthy to create a box, 
  //  falsey to reset the box.
  Drupal.mosaic.mosaicBox.prototype.updateQBox = function(state) {
    try {
      var boxState = state || false;
      
      var color    = (boxState) ? '#FFFFFF': 'transparent';
      var position = (boxState) ? 'relative': 'inherit';
      var padding  = (boxState) ? 15 : 0;
      var zIndex   = (boxState) ? '6' : 'auto';
      
      this.$question.css({
        'background-color': color,
        'position': position,
        'padding-left': padding+'px',
        'padding-right': padding+'px',
        'margin-left': (-1*padding)+'px',
        'margin-right': (-1*padding)+'px',
        'z-index': zIndex
      });      
    }
    catch (err) {
      console.log('updateQBox errored: '+err);
    }
  };
  
  
  // Set up close facilities
  Drupal.mosaic.mosaicBox.prototype.initClose = function() {
    try {
      // For coupling the close clicks
      this.$clsAnswers = this.$question.find('.pane-coral-answers-target .cls-answer').eq(0);
    
      this.$question.prepend('<div class="mbclose">x</div>');
      this.$close = this.$question.children('.mbclose');
      
      this.$close.css({
        'cursor': 'pointer',
        'position': 'absolute',
        'z-index': 7,
        'font-size': '2em',
        'right': '10px',
        'top': '10px',
      });
      
      // Close triggers two clicks
      var mbo = this;
      this.$close.click(function() { 
        mbo.handleCloseClick(); 
        mbo.$clsAnswers.trigger('click');  
      });
      
      this.$clsAnswers.click(function() {
        if (mbo.$close != undefined) { // No more!
          mbo.$close.trigger('click');
        }
      });
      
      this.closeInterval = setInterval(function() {
        var docTop = $(window).scrollTop();
        var qTop = mbo.$question.offset().top;
        var extra = 0;
        var $navBar = $('#navbar-administration');
        if ($navBar.length) extra = 40;
        if ((docTop + extra) > qTop) {
          mbo.$close.css('top', docTop - qTop + extra);
        }
        else {
          mbo.$close.css('top', 0);
        }
      }, 100);
    }
    catch (err) {
      console.log('initClose errored: '+err);
    }
  };
  
  
  // Close up the animations
  Drupal.mosaic.mosaicBox.prototype.handleCloseClick = function() {
    try {
      if (this.$close != undefined) {
        this.$close.remove();
        delete this.$close;
      }
      this.mbOverlay.updateOverlay('hide');
      this.mbOverlay.$overlay.addClass('hidden');
      this.updateQBox(); // reset question box
      clearInterval(this.closeInterval);
    }
    catch (err) {
      console.log('handleCloseClick errored: '+err);
    }
  };
  

  // Extract the question id
  Drupal.mosaic.mosaicBox.prototype.getID = function($btn) {
    try {
      var classes = $btn.attr('class');
      classes = classes.split(" ");
      for (cls in classes) {
        var c = classes[cls];
        if (c.match(/answer-\d+/)) {
          this.id = c.replace('answer-', ''); // and the nid
          break;
        }
      }
    }
    catch (err) {
      console.log('getID errored: '+err);
    }
  };


  // Overlay methods
  // ---------------

  // Create and append the overlay
  Drupal.mosaic.mosaicBoxOverlay.prototype.initOverlay = function() {
    try {
      var $overlay = $('.mbox-over');
      if (!$overlay.length) {
        $('body').append('<div class="mbox-over hidden"></div>');
        $overlay = $('body').children('.mbox-over');
      }
      
      this.$overlay = $overlay; // set the overlay in the object
    }
    catch (err) { 
      console.log('initOverlay errored: '+ err);
    }
  };
  
  
  // Update the overlay settings
  Drupal.mosaic.mosaicBoxOverlay.prototype.updateOverlay = function(hide) {
    try {
      var boxHide = hide || false;
    
      var width = $(document).width();
      var height = $(document).height();
      
      var display = (this.$overlay.hasClass('hidden') || boxHide) ? 'none' : 'block';
      
      this.$overlay.css({
        'height': height+'px',
        'width': width+'px',
        'background': '#000000',
        'position': 'absolute',
        'top': 0,
        'left': 0,
        'z-index': 5,
        'display': display
      });
    }
    catch (err) {
      console.log('updateOverlay errored: '+err);
    }
  };
  
})(jQuery);
