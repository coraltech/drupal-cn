
// This file will manage the display of the signature pane
//  seen on user page

Drupal.mosaic = Drupal.mosaic || {};

// Document loaded!
(function($) {

  Drupal.behaviors.coralSignaturePaneInit = {
    attach : function(context, settings) {
      try {
        var $sig = $('.pane-user-signature:not(".sigp-proc")');
        if ($sig.length) {
          $sig.each(function() {
            new Drupal.mosaic.signaturePane($sig);
          });
        }
      }
      catch (err) {
        console.log('coralSignaturePaneInit() reported errors. Error: '+err);
      }
    }
  };


  // Signature pane startup
  Drupal.mosaic.signaturePane = function($sig) {
    try {
      if (!$sig.siblings('.pane-menu-create').length) {
        $sig.removeClass('grid-11-last');
      }
      if (!$sig.siblings('.pane-user-field-biography').length) {
        var text = '<div class="panel-pane pane-entity-field pane-user-field-biography prepend-1 mb-25"><h2 class="pane-title">Biography</h2><div class="pane-content"><div class="field field-name-field-biography field-type-text-with-summary field-label-hidden"><div class="field-items"><div class="field-item even">';
        text += 'No biography found.';
        text += '</div></div></div></div></div></div>';
        $sig.after(text);
      }
    }
    catch (err) {
      console.log('signaturePane errored: '+err);
    }
  };

})(jQuery);
