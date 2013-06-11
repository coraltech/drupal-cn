
// This file will contain and serve the settings for tiny MCE

// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// Document loaded!
(function($) {
  
  Drupal.behaviors.mosaicMceInit = {
    attach : function(context, settings) {
      try { // use try to ensure that if this breaks/fails, it won't break other stuff.
        // At the moment there is not much to do here...
        
        //console.log('mosaicMceInit');
      }
      catch (err) {
        console.log('mosaicMceInit() reported errors. Error: '+err);
      }
    }
  };

  // Return the settings for tinymce that we want
  Drupal.mosaic.tinymceSettings = function(selector) {
    $wrapper = $(selector).parent();
    $grippie = $wrapper.find('.grippie');
    $grippie.addClass('hide');
    return {
      selector: selector,
      content_css: "/sites/all/themes/mosaic/css/global/mce_content.css",
      plugins: [
        "advlist autolink lists link charmap print preview anchor",
        "searchreplace visualblocks code fullscreen",
        "insertdatetime table contextmenu paste"
      ],
      toolbar: "undo redo | styleselect | bold italic underline | alignleft aligncenter alignright alignjustify | bullist numlist outdent indent | charmap link"
    };
  };
  
}) (jQuery);

