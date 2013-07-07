
// This file ensures enter press support for the
//  coral_tag_search custom pane.

// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// Document loaded!
(function($) {
  
  Drupal.behaviors.mosaicQAInit = {
    attach : function(context, settings) {
      try {
        // Any part of this that gets a mouse down we want
        //  to focus the user on the textfield 
        $('.pane-coral-qa-ask-question .field-name-body .text-full').attr('rows', '5'); // reset rows
        $('.pane-coral-qa-ask-question .node-question-form .form-submit').attr('value', Drupal.t('Submit question')); // reset submit text
        
        var currentHeight = $('.pane-coral-qa-ask-question form').height() - 20;
        if (currentHeight < 185) currentHeight = 185;
        $('.pane-coral-qa-ask-question').height(currentHeight + 30);  
        $('.pane-coral-qa-ask-question .qa-msg .cont').height(currentHeight); // resize height of msg box
        
        // add little icon holder - if it doesnt exist yet
        if (!$('.pane-coral-qa-ask-question .field-name-field-tags .icon').length) {
          $('.pane-coral-qa-ask-question .field-name-field-tags').prepend('<span class="icon"></span>');  
        }
        
      }
      catch (err) {
        console.log('mosaicQAInit() reported errors. Error: '+err);
      }
    }
  };
  
})(jQuery);
