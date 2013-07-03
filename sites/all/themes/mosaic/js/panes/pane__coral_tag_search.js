
// This file ensures enter press support for the
//  coral_tag_search custom pane.

// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// Document loaded!
(function($) {
  
  Drupal.behaviors.mosaicTagSearchInit = {
    attach : function(context, settings) {
      try {
        // Any part of this that gets a mouse down we want
        //  to focus the user on the textfield 
        $('.pane-coral-tag-search').mousedown(function(e) {
          // Give the system a little time to return control 
          //  from the destroyed autocomplete box
          setTimeout(function() {
            $('.pane-coral-tag-search .form-text').focus();
          }, 50);
        });
        
        // Check for the press of enter (13) and
        //  submit form once detected
        $('.pane-coral-tag-search .form-text').keypress(function(event) {
          if (event.which == 13) {
            event.preventDefault();
            $(".pane-coral-tag-search form").submit();
          }
        });
      }
      catch (err) {
        console.log('mosaicTagSearchInit() reported errors. Error: '+err);
      }
    }
  };
  
})(jQuery);
