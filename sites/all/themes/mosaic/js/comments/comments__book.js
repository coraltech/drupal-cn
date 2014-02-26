// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// ----------------------------------------------------------------------
// Comment form / and comments (talk) init here:
// ----------------------------------------------------------------------
//
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicCommentsBookInit = {    
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
        $('.pane-node-comment-form, .pane-coral-comment-reply').each(function(i) {
          new Drupal.mosaic.manageCommentBookForm($(this));
        })
      }
      catch(err) {
        console.log('mosaicCommentsBookInit reported errors! Error: '+err);
      }
      
      try {
        new Drupal.mosaic.manageCommentBookTitles();
      }
      catch(err) {
        console.log('mosaicCommentsBookInit reported errors! Error: '+err);
      }
    }
  };
  
  // Removed unneeded comment titles
  Drupal.mosaic.manageCommentBookTitles = function() {
    $comments = $('.comment');
    if ($comments.length) {
      $comments.each(function(i) {
        $commentTitle = $(this).find('.comment-title');
        commentTitle = $(this).find('.comment-title').text();
        commentTitle = commentTitle.replace(/^\s+|\s+$/g, ''); // get rid of whitespace
        
        $commentText  = $(this).find('.field-name-comment-body');
        commentText  = $(this).find('.field-name-comment-body').text();
        
        // check to see if the title matches the start of the body
        var pattern = new RegExp('^'+commentTitle);
        if (commentText.match(pattern)) {
          $commentTitle.remove();
        }
      });
    }
  }
  
  // Manages comment form layout
  Drupal.mosaic.manageCommentBookForm = function($form) {
    if ( // Comments can happen on these two types (body classes) so far
      $form.parents('.page-node-talk').length || 
      $form.parents('.page-comment-reply').length
    ){

      $title = $('.limiter>.pane-node-title');
      $node  = $('.limiter>.pane-entity-view');
      
      try { // check positioning of comment form
        formPos  = $form.position(); formPos.top = formPos.top + 41; // the page-title h1 is now like 40 px tall!
        titlePos = $title.position();
        nodePos  = $node.position();
        
        // Form is below the displayed (floating) node
        if (formPos.top && (formPos.top >= (titlePos.top + $title.height() + $node.height()))) {
          $form.removeClass('form-left');
          $form.addClass('form-center');
        }
        // Form is beside the displayed (floating) node
        else {
          $form.addClass('form-left');
          $form.removeClass('form-center');
        }
        
        //console.log(formPos.top);
        //console.log(titlePos.top + $title.height() + $node.height());
      }
      catch (err) {
        console.log('Apparently something is missing: '+err);
      }
    }
  };
})(jQuery);
