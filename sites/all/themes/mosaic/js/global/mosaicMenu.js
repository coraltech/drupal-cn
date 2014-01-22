
// JS file to manage some menu fixes or upgrades.-

// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// Document loaded!
(function($) {
  
  // Initialize tinyMCE comps.
  Drupal.behaviors.mosaicMenuInit = {
    attach : function(context, settings) {
      try { // use try to ensure that if this breaks/fails, it won't break other stuff.
        // At the moment there is not much to do here...
        var $a = $('a[href="/user"]').off('click');
        
      }
      catch (err) {
        console.log('mosaicMenuInit() reported errors. Error: '+err);
      }
    }
  };
  
}) (jQuery);
