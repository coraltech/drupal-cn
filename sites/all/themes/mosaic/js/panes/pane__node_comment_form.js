// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// ----------------------------------------------------------------------
// Comment form / and comments (talk) init here:
// ----------------------------------------------------------------------
//
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicCommentFormInit = {    
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
        $('.pane-node-comment-form').each(function(i) {
          new Drupal.mosaic.manageCommentForm($(this));
        })
      }
      catch(err) {
        console.log('mosaicCommentFormInit reported errors! Error: '+err);
      }
      
      try {
        new Drupal.mosaic.manageCommentTitles();
      }
      catch(err) {
        console.log('mosaicCommentFormInit reported errors! Error: '+err);
      }
    }
  };
  
  // Removed unneeded comment titles
  Drupal.mosaic.manageCommentTitles = function() {
    $comments = $('.comment');
    if ($comments.length) {
      $comments.each(function(i) {
        $commentTitle = $(this).find('.comment-title');
        commentTitle = $(this).find('.comment-title').text();
        
        $commentText  = $(this).find('.field-name-comment-body');
        commentText  = $(this).find('.field-name-comment-body').text();
        
        var pattern = new RegExp('^'+commentTitle);
        if (commentText.match(pattern)) {
          $commentTitle.remove();
        }
      });
    }
  }
  
  // Manages comment form layout
  Drupal.mosaic.manageCommentForm = function($form) {
    if ($form.parents('.page-node-talk').length) {
      $title = $('.limiter>.pane-node-title'); //$title.height()
      $node  = $('.limiter>.pane-entity-view');
      
      try {
        formPos  = $form.position(); formPos.top = formPos.top + 20;
        titlePos = $title.position();
        nodePos  = $node.position();
        
        if (formPos.top && (formPos.top >= (titlePos.top + $title.height() + $node.height()))) {
          $form.css('width', '99.8%');
        }
        else {
          $form.css({'margin':'0 0 2.5em', 'float': 'left'});
        }
      }
      catch (err) {
        console.log('Apparently something is missing: '+err);
      }
    }
  };
})(jQuery);
