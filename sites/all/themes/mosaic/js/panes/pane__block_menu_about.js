
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
        
        // Add some arrow containers
        var $about = $('.pane-block.pane-menu-about');
        if ($about.length > 0) {
          $about.find('.leaf a').each(function() {
            $(this).append('<span class="ar-out"><span class="ar-in"></span></span>');
          });
        }
        
        // Highligh about main menu link
        var $main_items = $('.sf-menu.main li a');
        $main_items.each(function() {
          if ($(this).attr('href') == '/content/about-coral') {
            $(this).addClass('active');
          }
        });
      }
      catch(err) {
        console.log('mosaicAboutMenuInit reported errors! Error: '+err);
      }
    }
  };
})(jQuery);
