
// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};


// ----------------------------------------------------------------------
// About menu scripts
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicAboutMenuInit = {    
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
        var $about = $('.pane-block.pane-menu-about');
        if ($about.length > 0) {
          $about.find('.leaf a').each(function() {
            $(this).append('<span class="ar-out"><span class="ar-in"></span></span>');
          });
        }    
      }
      catch(err) {
        console.log('mosaicAboutMenuInit reported errors! Error: '+err);
      }
    }
  };
})(jQuery);
