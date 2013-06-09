// Registers the Mosaic namespace
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
  
})(jQuery); 
