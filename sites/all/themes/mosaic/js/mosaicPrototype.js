// Registers the Mosaic namespace

// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// @TODO: Turn this into a good prototype!
// ----------------------------------------------------------------------
// Magnificent popup instantiation
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicHelpPanelInit = {    
    attach : function(context, settings) {
      
      try { // Use try to prevent systemic failure
        $panel = $('#pane-getting-help');
        if ($panel.length > 0) {
          new Drupal.mosaic.helpPanelManager($panel);
        }
      }
      catch(err) {
        console.log('mosaicHelpPanelInit reported errors! Error: '+err);
      }
    }
  };
  
  Drupal.mosaic.helpPanelManager = function($panel) {
    
    // jQuery objects of note
    this.$panel = $panel;
    
    // Identification and settings
    var helpPanelManager = this;
    var PanelView = Backbone.View.extend({
      // Home
      el: this.$panel,
      
      // Settings and conf
      helpPanelManager: helpPanelManager,
      
      // events
      events: {
        'click .sf-menu a': 'menuClick'
      },
      
      // Init
      initialize: function() {
        helpPanelManager.initializeForms(this.el);
         _.bindAll(this, 'menuClick');
      },
      
      menuClick: function(ev) {
        console.log('Item clicked');
      }
     
    });
    // Instantiate the panel view object
    new PanelView();
  }
  
  Drupal.mosaic.helpPanelManager.prototype.initializeForms = function($panel) {
    console.log('Initializing'); 
  }
  
})(jQuery);



/*

Backbone = Backbone || {};
Drupal.mosaicPrototype = Drupal.mosaicPrototype || {};


// Document loaded!
(function($, Backbone) {
  
  Drupal.behaviors.mosaicPrototypeInit = {    
    attach : function(context, settings) {
      // use try to ensure that if this code breaks/fails, it won't break other stuff.
      try {
      	
      	var foo = 'foo';
      	var bar = 'bar'; 
      	
        // Process your codes baby!
        new Drupal.mosaicPrototype.starter(foo, bar);
      }
      catch (err) {
      	// Log a message to the console on breakdowns
        console.log('mosaicPrototypeInit() reported errors! Error: '+err);
      }
    }
  };

  // Mosaic process
  
  Drupal.mosaicPrototype.starter = function(foo, bar) {
    
    starter = this; // we need to use this later
    
    // Prep vars - do whatever you feel like!
    this.foo = foo;
    this.bar = bar;
    
    // Component backbone core
    var ProtoView = Backbone.View.extend({
      
      // Homebase for operations
      el: $('a.proto-click'),
      
      // Events
      events: {
        'click btn.proto-click' : 'clickProto'
      },
      
      // Initialize the ProtoView
      initialize: function() {
      	$('body').append('<input type="submit" class="proto-click" value="clicked">Click me baby</input>'); 
        starter.process(starter.foo, starter.bar);
        _.bindAll(this, 'clickProto'); 
      },
      
      // Updates
      clickProto: function() { starter.process(starter.foo, starter.bar); },
    });
    
    // Kick start! ---
    new ProtoView();
  };
  
  //---
  
  Drupal.mosaicPrototype.prototype.process = function(foo, bar) {
    console.log(foo + ' : ' + bar);
  }
  
})(jQuery); */
