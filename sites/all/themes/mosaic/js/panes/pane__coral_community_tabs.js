
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
        $('#superfish-1 a[href="/content/community-documentation"]').addClass('active');
        
        // Need a place to drop this:
        // It unbinds some stuipid gigya click handler from MY links!
        $('#superfish-2 a').unbind('click');
      }
      catch (err) {
        console.log('mosaicCommunityInit() reported errors. Error: '+err);
      }
    }
  };
  
})(jQuery);
