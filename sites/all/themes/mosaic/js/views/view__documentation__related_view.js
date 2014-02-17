
// Registers the coralQA namespace
Drupal.coralQA = Drupal.coralQA || {};

// ----------------------------------------------------------------------
// Get more questions for this view
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.coralRelatedDocsInit = {    
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
       	var params = Drupal.mosaic.core.getQueryParams(window.location.href);
        $relatedPane = $('.pane-documentation-related-view');
        if ($relatedPane.length) {
          if (Drupal.mosaic.core.objCount(params) == 0) { // theres nothing "related" about it... no tags
            $relatedPane.children('.pane-title').text('Documentation');
          }
        }
      }
      catch(err) {
        console.log('coralRelatedDocsInit reported errors! Error: '+err);
      }
    }
  };  
})(jQuery);

