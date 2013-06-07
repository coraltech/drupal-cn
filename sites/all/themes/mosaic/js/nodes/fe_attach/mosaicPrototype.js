// Registers the Mosaic namespace

Drupal.mosaicPrototype = Drupal.mosaicPrototype || {};

/**
 *
 * Mosaic forms will check to see if there are
 *  settings for any form's textfield defaults.
 *  Should only recieve requests for items that
 *  implement it. Only implement on pages where
 *  needed!
 *
 * These defaults are added via modules and 
 *  themes via whatever hooks they deem fit.
 *
 * Add new defaults to: 
 * 
 * Drupal.settings.mosaic.fieldDefaults:
 * 
 *  - fieldDefaults['.selector']['default'] = 'Default text';
 *  
*/
// Document loaded!
(function($) {
  
  Drupal.behaviors.mosaicPrototypeInit = {    
    attach : function(context, settings) {
      // use try to ensure that if this code breaks/fails, it won't break other stuff.
      try {
        
        // Add a couple of buttons :-)
        $('body').append('<input id="prot1" type="submit" class="proto-click" value="Click me baby!">');
        $('body').append('<input id="prot2" type="submit" class="proto-click" value="Click me too baby!">');
        
      	// Process the proto-click items
      	$('.proto-click').each(function(i) {
      	  //console.log(i);
      	  new Drupal.mosaicPrototype.starter($(this));
      	});
      }
      catch (err) {
      	// Log a message to the console on breakdowns
        console.log('mosaicPrototypeInit() reported errors! Error: '+err);
      }
    }
  };

  // Prototype starter
  Drupal.mosaicPrototype.starter = function($proto) {
    
    starter     = this;   // we may need to use this later
    this.$proto = $proto; // store this to pass in to other funcs
    console.log(this.$proto);
    //console.log(this.$proto);
    // # Clicks for this item
    this.clicks = 0;
        
    // Component backbone core
    var ProtoView = Backbone.View.extend({
      
      // Homebase for operations
      el: $('body'),
      
      // Events
      events: {
        'click .proto-click' : 'clickProto'
      },
      
      // Initialize the ProtoView
      initialize: function() {
        console.log($proto);
      	_.bindAll(this, 'clickProto'); 
      },
      
      // Updates
      clickProto: function() { console.log(starter); starter.process(); },
    });
    
    // Kick start! ---
    // Now, every time you click on a link with the class
    //  proto-click, you should get an alert message saying
    //  foo : bar
    new ProtoView();
  };
  
  //---
  
  Drupal.mosaicPrototype.starter.prototype.process = function() {
    console.log('Clicked');
  }
  
})(jQuery); 
