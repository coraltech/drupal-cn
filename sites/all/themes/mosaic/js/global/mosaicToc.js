// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

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
  
  Drupal.behaviors.mosaicTocInit = {    
    attach : function(context, settings) {
      try { // use try to ensure that if this breaks/fails, it won't break other stuff.
        if (Drupal.settings.mosaic.tocDefaults) {
          
        }
      }
      catch (err) {
        console.log('mosaicTocInit() reported errors... Any forms on the page? Error: '+err);
      }
    }
  };

  // Mosaic textfieldDefault takes one textfield and ensures it is
  //  set as it should be according to the specs in textfield_defaults.inc
  Drupal.mosaic.tocInit = function(tocElement, tocDefaults) {
    
    
    
    // Kick start!
    new tocList();
  };
})(jQuery);

