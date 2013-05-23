
// Registers the Coral namespace.
Drupal.coral = Drupal.coral || {};

// Protect the global namespace and set up $ = JQuery.
(function($) {

  // Define Drupal bahaviors.
  Drupal.behaviors.coralInit = {
      attach: function(context, settings) {
        var coreSettings = Drupal.settings.coralCore;
        new Drupal.coral.core(coreSettings);
      }
  };
  
  // Define Coral core object.
  Drupal.coral.core = function(settings) {
    // General properties.
    
    // Display settings.
    
    // Event handlers.
    
  };
  
  //Drupal.coral.core.prototype.something = function() {
  //  
  //};

})(jQuery);
