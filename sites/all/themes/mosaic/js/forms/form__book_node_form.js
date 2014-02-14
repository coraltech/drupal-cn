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
        var $formElem = $('.form-item-book-bid select:not(".bfproc")');
        if ($formElem.length > 0) {
        	// Set the community documentation link to be selected (nid:32).
        	//  Then trigger a change event (to load book lineage)
          $formElem.addClass('bfproc').val(32).trigger('change');

					// This gets around a bug in panels/drupal where book pages 
					//  vertical tab displays the title of our parent book
					//  twice... It is not a huge deal but in the future should
					//  be resolved in a cleaner fashion. 
          $('.vertical-tabs-list span.summary').each(function() {
          	if ($(this).text() == 'Community documentationCommunity documentation') {
          		$(this).before('<span class="summary mbsummary">Community documentation</span>').hide();
          	}
          });
        }
      }
      catch(err) {
        console.log('mosaicBookFormInit reported errors! Error: '+err);
      }
    }
  };
}) (jQuery);