
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
        var getQueryParam = function(name) {
          name = name.replace(/[\[]/,"\\\[").replace(/[\]]/,"\\\]");
          var regexS = "[\\?&]"+name+"=([^&#]*)";
          var regex = new RegExp( regexS );
          var results = regex.exec( window.location.href );
          if( results == null )
            return "";
          else
            return decodeURIComponent(results[1].replace(/\+/g, " "));
        };
        
        $relatedPane = $('.pane-documentation-related-view');
        if ($relatedPane.length) {
          var tag = getQueryParam('tag');
          if (tag == '') { // theres nothing "related" about it... no tags
            $relatedPane.children('.pane-title').text('Documentation');
          }
        }
      }
      catch(err) {
        console.log('coralNewQuestionsInit reported errors! Error: '+err);
      }
    }
  };  
})(jQuery);

