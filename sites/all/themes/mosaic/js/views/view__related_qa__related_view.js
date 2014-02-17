
// Registers the coralQA namespace
Drupal.coralQA = Drupal.coralQA || {};

// ----------------------------------------------------------------------
// Get more questions for this view
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.coralRelatedQAInit = {    
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
       	var params = Drupal.mosaic.core.getQueryParams(window.location.href);
        $relatedPane = $('.pane-related-qa-related-view');
        if ($relatedPane.length) {
          if (Drupal.mosaic.core.objCount(params) == 0) { // theres nothing "related" about it... no tags
            $relatedPane.children('.pane-title').text('Recent Q&A');
          }
        }
      }
      catch(err) {
        console.log('coralRelatedQAInit reported errors! Error: '+err);
      }
    }
  };  
})(jQuery);

