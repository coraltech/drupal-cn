
// This file ensures that if the community tabs are
//  shown, the Community primary link will be active

// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// Document loaded!
(function($) {
  
  Drupal.behaviors.mosaicCommunityInit = {
    attach : function(context, settings) {
      try {
        // This just makes sure the right primary link is highlighted
        $('#mini-panel-top_menus a[href="/content/community-documentation"]').addClass('active');
      }
      catch (err) {
        console.log('mosaicCommunityInit() reported errors. Error: '+err);
      }
    }
  };
  
})(jQuery);
