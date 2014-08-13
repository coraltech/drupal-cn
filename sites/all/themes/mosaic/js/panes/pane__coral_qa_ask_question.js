
// This file ensures enter press support for the
//  coral_tag_search custom pane.

// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// Document loaded!
(function($) {
  
  Drupal.behaviors.mosaicQAInit = {
    attach : function(context, settings) {
      try {
        var winW = $(window).width();
      	
      	// Any part of this that gets a mouse down we want
        //  to focus the user on the textfield 
        $('.pane-coral-qa-ask-question .field-name-body .text-full').attr('rows', '5'); // reset rows
        var $submit = $('.pane-coral-qa-ask-question .node-question-form .form-actions .form-submit').attr('value', Drupal.t('Submit question')); // reset submit text
        
        var $pane = $('.pane-coral-qa-ask-question');
        var $form = $('.pane-coral-qa-ask-question form');
        var $msg  = $('.pane-coral-qa-ask-question .qa-msg');
        var $btn  = $('.pane-coral-qa-ask-question .ask.btn');

        if (winW > 768) {
        	$form.removeClass('hide');
        	$('.pane-coral-qa-ask-question .ask.btn').addClass('hide');
        	
        	if (winW < 850) {
        		$submit.attr('value', Drupal.t('Submit'));
        	}
        }
        else {
        	$form.addClass('hide');
        	$('.pane-coral-qa-ask-question .ask.btn').removeClass('hide');
        }
        
        
        $( window ).resize(function() {
  				var winW = $( window ).width();
  				if (winW > 768) {
  					if (winW < 875) {
        			$submit.attr('value', Drupal.t('Submit'));
        		}
        		else {
        			$submit.attr('value', Drupal.t('Submit question'));
        		}
        		$btn.addClass('hide');
  					$form.removeClass('hide');
   				}
  				else {
  					$submit.attr('value', Drupal.t('Submit question'));
  					if (!$form.hasClass('open')) {
  					  $btn.removeClass('hide');
  					  $form.addClass('hide');
  					}
  				}
				});
				
				// Show and hide the form
				$('.pane-coral-qa-ask-question .ask.btn').off('click').click(function(ev) {
					ev.preventDefault();
					if ($form.hasClass('hide')) { 
						$form.removeClass('hide').addClass('open');
					}
					else {
						$form.addClass('hide').removeClass('open');
					}
				});
				
				
				
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
