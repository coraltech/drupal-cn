// This file will provide a central access point for mosaic components

// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// Document loaded!
(function($) {

  Drupal.behaviors.mosaicTextField = {
    attach : function(context, settings) {
      try {// Use try to prevent systemic failure
        //$empties = $('.field-type-text-with-summary').find('p'); //.remove(); // clear useless P tags created by wysiwyg and or text filters
        $p = $('.field-type-text-with-summary').find('p');
        $p.each(function() {
     			if($(this).html().replace(/\s|&nbsp;/g, '').length == 0)
        		$(this).remove();
					}
				);
      } catch (err) {
        console.log('mosaicTextField() reported errors. Error: ' + err);
      }
    }
  };

})(jQuery);
