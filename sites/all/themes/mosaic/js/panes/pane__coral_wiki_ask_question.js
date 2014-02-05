// Registers the Mosaic namespace

// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// @TODO: Turn this into a good prototype!
// ----------------------------------------------------------------------
// Magnificent popup instantiation
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicWikiAsk = {    
    attach : function(context, settings) {
      
      try { // Use try to prevent systemic failure
        var $panel = $('.pane-coral-wiki-ask-question:not(".wa-processed")');
        
        // @TODO: Set a unique identifier for each instance 
        // if there are more than one
        
        if ($panel.length > 0) {
          $panel.each(function() {
            new Drupal.mosaic.mosaicWAManager($(this));  
          });
        }
      }
      catch(err) {
        console.log('mosaicWikiAsk reported errors! Error: '+err);
      }
    }
  };


  // The main control for the Wiki Ask forms
  Drupal.mosaic.mosaicWAManager = function($panel) {
    try {
      
      // jQuery objects of note
      this.$panel  = $panel.addClass('wa-processed');
      this.$askBtn = $panel.find('.ask-btn');
      this.id      = '';
      this.initID(this.$askBtn);
      
      this.$askBtn.prop('id', 'ask-btn-'+this.id); // initialize an id

      this.$form  = {}; // will hold the question form jQ obj.
      this.events = {};
      this.events['click #ask-btn-'+this.id] = 'askClick';
      this.overlay = {}; // Reference to the overlay
      
      // Identification and settings
      var WAManager = this; // The wiki ask manager
      var WAView = Backbone.View.extend({ // the view
        // Home
        el: this.$panel,
        
        // Save settings and conf
        WAManager: WAManager,
        
        // events
        events: WAManager.events,
        
        // Init
        initialize: function() {
          WAManager.initializePane(); // initialize pane
           _.bindAll(this, 'askClick');      // attach event handlers
        },
        
        askClick: function(ev) { 
          WAManager.handleClick(ev);
        }
       
      });

      // Instantiate the panel view object
      new WAView();
    }
    catch (err) {
      console.log('mosaicWAManager errored: '+err);
    }
  };


  // Get an id
  Drupal.mosaic.mosaicWAManager.prototype.initID = function($obj) {
    if ($obj.prop('id')) {
      this.id = $obj.prop('id');
    }
    else {
      this.id = Drupal.mosaic.core.createID($obj);
    }
  };

  // Gather data
  Drupal.mosaic.mosaicWAManager.prototype.initializePane = function() {
    this.$form = this.$panel.find('.wiki-ask-question');
  };


  // Respond to click events
  Drupal.mosaic.mosaicWAManager.prototype.handleClick = function(ev) {
    try {
      this.Overlay  = Drupal.mosaic.core.objects.mboverlay;
      this.$overlay = Drupal.mosaic.core.objects.mboverlay.$overlay;
      
      var WAM = this;
            
      this.$overlay.removeClass('hidden').fadeTo(250, .45, function() {
        WAM.Overlay.updateOverlay(false);
        WAM.initClose();
      });

      // Show the form over the overlay      
      this.$form.removeClass('hide').slideDown(250, function() {}).css(this.boxCss('show'));
    }
    catch (err) {
      console.log('handleClick errored: '+err);
    }
    
  };
  
  
  // Some css to pass into the box
  Drupal.mosaic.mosaicWAManager.prototype.boxCss = function(state) {
    try {
      if (state == 'show') {
        return {
          'padding':'1em 1.5em',
          'position':'relative',
          'z-index':'6',
          'background-color':'#fff'
        }
      }
      else {
        return {
          'padding':'1em 1.5em',
          'position':'inherit',
          'background-color':'transparent'
        }
      }
    }
    catch (err) {}
  };
  
  
  // Set up close facilities
  Drupal.mosaic.mosaicWAManager.prototype.initClose = function() {
    try {
      var WAM = this;
      
      this.$form.prepend('<div class="mbclose">x</div>');
      this.$close = this.$form.children('.mbclose');
      this.$close.css({
        'cursor': 'pointer',
        'position': 'absolute',
        'z-index': 7,
        'font-size': '2em',
        'right': '-14px',
        'top': '-14px',
      });
      this.$close.click(function() {
        WAM.closePane();
      });
      
      // Listen for changes in browser scroll position (100ms)
      // Ripped from mosaicBox initClose()
      this.closeInterval = setInterval(function() {
        var docTop = $(window).scrollTop();
        var qTop = WAM.$form.offset().top;
        var extra = 0;
        var $navBar = $('#navbar-administration');
        if ($navBar.length) extra = 40;
        if ((docTop + extra) > qTop) {
          WAM.$close.css('top', docTop - qTop + extra);
        }
        else {
          WAM.$close.css('top', -14);
        }
      }, 100);
    }
    catch (err) {
      console.log('initClose errored: '+err);
    }
  };
  

  // Handle closing of the pane
  Drupal.mosaic.mosaicWAManager.prototype.closePane = function() {
    try {
      var WAM = this;
      
      // hide the box
      this.$form.slideUp(150, function() {
        WAM.$form.css(WAM.boxCss('hide'));
      });
      
      // update the overlay
      this.$overlay.fadeTo(250, 0, function() {
        WAM.$overlay.addClass('hidden');
        WAM.Overlay.updateOverlay(true);
      });
      
      clearInterval(this.closeInterval); // clear close btn positioning timer
      
      this.$close.remove();
      delete this.$close;
    }
    catch (err) {
      console.log('closePane errored: '+err);
    }
  };
  
})(jQuery);
