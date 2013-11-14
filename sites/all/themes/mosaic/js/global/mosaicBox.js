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
          Drupal.mosaic.core.objects['mboverlay'] = new Drupal.mosaic.mosaicBoxOverlay();
          Drupal.mosaic.core.objects['mosaicBox'] = {}; // will contain active boxable items

          // Overlays only apply to questions
          $('.node-question.node-teaser:not(".mbox-processed")').each(function(i) {
          
            var id = Drupal.mosaic.core.initID($(this));
            
            // Only apply if not a full node or a child of the parent node container
            if (!$(this).parents('.node-full-node.node-question').length &&
                !$(this).parents('.pane-coral-parent-content').length) {
                          
              // The questions... Oh, the questions
              Drupal.mosaic.core.objects.mosaicBox[id] = new Drupal.mosaic.mosaicBox($(this), id);

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
  Drupal.mosaic.mosaicBox = function($question, id) {
    try {
      if ($question.length) {
        this.id = id;
        
        this.$question = $question;
        this.mbOverlay = Drupal.mosaic.core.objects.mboverlay;
        
        // will store a reference to an ongoing close button position monitor (if one is visible)
        this.closeInterval = false;
        
        this.events = {};
        this.events['click .btn.answer-'+this.id]  = 'answerClick';
        this.events['click .btn.comment-'+this.id] = 'commentClick';

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
            _.bindAll(this, 'answerClick', 'commentClick');
          },

          // Events
          // Answer link       console.log(this);initiates overlay
          answerClick: function(ev) {
            mosaicBox.handleClick(ev, 'answer');
          },
          
          commentClick: function(ev) {
            mosaicBox.handleClick(ev, 'comment');
          }
        });
        
        new MosaicBoxView();
      }
    } catch (err) {
      console.log('mosaicBox errored: ' + err);
    }
  };
  
  
  // Handles the opening of the content
  //  Will cause the overlay to engage, etc...
  Drupal.mosaic.mosaicBox.prototype.handleClick = function(ev, type) {
    try {
      
      if (!$(ev.currentTarget).hasClass('mbopen')) {
        this.$question.find('.mbopen').removeClass('mbopen'); // clear old instances
        
        $(ev.currentTarget).addClass('mbopen'); // add class for toggling
        
        clearTimeout(this.closeInterval); // reset the interval - if one exists
        
        this.initClose(type); // start up the close button
        this.updateBox(true); // Initialize the Question box styles
        this.mbOverlay.$overlay.fadeTo(50, .65);
        this.mbOverlay.$overlay.removeClass('hidden');
        
        var mbo = this.mbOverlay;
        setTimeout(function() {
          mbo.updateOverlay();
        }, 250); // leave time for transistions and so on
      }
      else {
        this.closeBox();  
      }
    }
    catch (err) {
      console.log('handleClick errored: '+err);
    }
  };


  // Box state around the question. Truthy to create a box, 
  //  falsey to reset the box.
  Drupal.mosaic.mosaicBox.prototype.updateBox = function(state) {
    try {
      var boxState = state || false;
      
      var color    = (boxState) ? '#FFFFFF': 'transparent';
      var position = (boxState) ? 'relative': 'inherit';
      var padding  = (boxState) ? 15 : 0;
      var zIndex   = (boxState) ? '6' : 'auto';
      
      this.$question.css({
        'background-color': color,
        'position': position,
        'padding': (padding / 3) + 'px ' + padding + 'px',
        'margin': (-1 * (padding / 3)) + 'px ' + (-1 * padding) + 'px',
        'z-index': zIndex
      });      
    }
    catch (err) {
      console.log('updateBox errored: '+err);
    }
  };
  
  
  // Set up close facilities
  Drupal.mosaic.mosaicBox.prototype.initClose = function(type) {
    try {
      // For coupling the close clicks
      // this.$cls represents the answers or comments added close button (eg. .cls-comments
      this.$question.prepend('<div class="mbclose">x</div>');
      this.$close = this.$question.children('.mbclose');

      this.$close.css({
        'cursor': 'pointer',
        'position': 'absolute',
        'z-index': 7,
        'font-size': '2em',
        'right': '-14px',
        'top': '-14px',
      });
      
      // Close can trigger two clicks:
      // ---
      // the answers or comments section close btn
      var sel = '.pane-coral-'+type+'s-target .cls-'+type+'s';
      this.$cls = this.$question.find(sel);
      
      var mbo = this;      
      this.$cls.each(function() {
        var $p = $(this).parents('.node-teaser'); // only trigger the click event on the outermost close buttons
        if ($p.length < 2) {
          $(this).click(function() {
            if (mbo.$close != undefined && !mbo.$close.hasClass('closing')) {
              setTimeout(function() {
                mbo.closeBox();
              }, 25);
            }
            else {
              mbo.closeBox();
            }
          });
        }
      });
      
      // the mosaicBox gen. close btn (the big one)
      this.$close.off('click').click(function() { // dont re-add click event!
        mbo.$close.addClass('closing');
        setTimeout(function() {
          mbo.$cls.trigger('click');
        }, 25);
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
          mbo.$close.css('top', -14);
        }
      }, 100);
    }
    catch (err) {
      console.log('initClose errored: '+err);
    }
  };
  
  
  // Close up the box
  Drupal.mosaic.mosaicBox.prototype.closeBox = function() {
    try {
      var $open = this.$question.find('.mbopen');
      $open.removeClass('mbopen');
    
      if (this.$close != undefined) {
        this.$close.remove();
        delete this.$close;
      }
      clearInterval(this.closeInterval);

      this.mbOverlay.updateOverlay('hide');
      this.mbOverlay.$overlay.addClass('hidden');
      this.updateBox(); // reset question box
    }
    catch (err) {
      console.log('closeBox errored: '+err);
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
