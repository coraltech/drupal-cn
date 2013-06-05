// Registers the Mosaic namespace
Backbone = Backbone || {};
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
    // Now, every time you click on a link with the class
    //  proto-click, you should get an alert message saying
    //  foo : bar
    new ProtoView();
  };
  
  //---
  
  Drupal.mosaicPrototype.prototype.process = function(foo, bar) {
    console.log(foo + ' : ' + bar);
  }
  
})(jQuery); 
