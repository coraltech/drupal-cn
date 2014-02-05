// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// @TODO: Turn this into a good prototype!
// ----------------------------------------------------------------------
// Magnificent popup instantiation
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicBookFormInit = {    
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
        var $formElem = $('.form-item-book-bid select');
        if ($formElem.length > 0) {
        	// Set the community documentation link to be selected (nid:32).
        	//  Then trigger a change event (to load book lineage),
        	//   and disable main select.
          $formElem.val(32).trigger('change').attr('disabled', 'disabled');
        }
      }
      catch(err) {
        console.log('mosaicBookFormInit reported errors! Error: '+err);
      }
    }
  };
}) (jQuery);