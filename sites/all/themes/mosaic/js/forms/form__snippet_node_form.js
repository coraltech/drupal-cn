
// js file for snippet form

// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// ----------------------------------------------------------------------
// Snippet form processing
// ----------------------------------------------------------------------
(function($) { // doc loaded
  Drupal.behaviors.mosaicSnippetFormInit = {    
    attach : function(context, settings) { // play it again Sam...
      try { // Use try to prevent systemic failure
      	// Disregard node-form instances that are right under
      	// the body tag... this is a panels issue: it wraps
      	// the page in a form. -_- 
      	$nodeForm = $('.node-snippet-form').filter(function(index) {
      		return !$(this).parent('body').length;
      	});
      	
      	$nodeForm.each(function() {
      		new Drupal.mosaic.snippetManager($(this));
      	});    	
			}
			catch (err) {
				console.log('mosaicSnippetFormInit errored: '+err);
			}
		}
	};


	Drupal.mosaic.snippetManager = function($form) {
		try {
			// Add class to first tr of snippet components
			// We do this even if the form has already been processed.
			var $rows = $form.find('.field-name-field-snippet-components tr.draggable').removeClass('first').removeClass('last');
			$rows.first().addClass('first');
			$rows.last().addClass('last');
		}
		catch (err) {
			console.log('snippetManager errored: '+err);
		}
	};
})(jQuery);

