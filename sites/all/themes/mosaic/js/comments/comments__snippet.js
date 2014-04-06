// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// ----------------------------------------------------------------------
// Comment form / and comments (talk) init here:
// ----------------------------------------------------------------------
//
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicCommentsSnippetInit = {    
    attach : function(context, settings) {
      try { // Update the form layout
        $('.pane-node-comment-form, .pane-coral-comment-reply').each(function(i) {
          new Drupal.mosaic.manageCommentSnippetForm($(this));
        })
      }
      catch(err) { console.log('manageCommentSnippetForm reported errors! Error: '+err); }
      
      // Remove comment titles where needed
      new Drupal.mosaic.manageCommentSnippetTitles();
      
      // Add slidability to parent node when the screen is narrow
      new Drupal.mosaic.manageSnippetSlider();
    }
  };
  
    // The user will swipe the window to view the parent content
  Drupal.mosaic.manageSnippetSlider = function() {
  	try {
  		this.$swipe  = $('.pane-coral-swipe');
  		this.$parent = $('.pane-entity-view.pane-node');

  		var MSS = this;
  		
  		this.changeView = function() {
	  		var winW = $(window).width();
	  		if (winW < 768) {
	  			// Show parent content
	  			$('body').off('swipeleft').on('swipeleft',function(e,data){
	      		MSS.$parent.show().animate({ 'margin-right': '0' }, 250);
	      		MSS.$swipe.find('.icon').removeClass('arrow-left').addClass('arrow-right');
	      		MSS.$swipe.find('.msg').text(MSS.$swipe.find('.msg').text().replace('view', 'hide'));
	      	});
	      	
	      	// Hide parent content
	      	$('body').off('swiperight').on('swiperight',function(e,data){
	      		MSS.$parent.animate({ 'margin-right': '-100%' }, 400, function() {
	      			MSS.$parent.hide();
	      		});
	      		MSS.$swipe.find('.icon').removeClass('arrow-right').addClass('arrow-left');
	      		MSS.$swipe.find('.msg').text(MSS.$swipe.find('.msg').text().replace('hide', 'view'));
	      	});
	     	}
	     	else {
	     		$('body').off('swipeleft').off('swiperight');
	     		MSS.$parent.attr('style', '');
	     	}
    	};
    	this.changeView();
    	
    	// On resize, the script must attach and detach the slider
  		// behavior, based on the width.
  		$(window).resize(function() {
  			MSS.changeView();	
  		});
  	}
  	catch (err) {
  		console.log('manageSnippetSlider errored' + err);
  	}
  };
  
  
  // Removed unneeded comment titles
  Drupal.mosaic.manageCommentSnippetTitles = function() {
    try {
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
    catch (err) {
    	console.log('manageCommentSnippetTitles errored: '+err);
    }
  };
  
  // Manages comment form layout
  Drupal.mosaic.manageCommentSnippetForm = function($form) {
    try { // check positioning of comment form
	    if ( // Comments can happen on these two types (body classes) so far
	      $form.parents('.page-node-talk').length || 
	      $form.parents('.page-comment-reply').length) {

	      this.$node   = $('.limiter>.pane-entity-view');
        this.formPos = $form.position(); this.formPos.top = this.formPos.top + 41; // the page-title h1 is now like 40 px tall!
        this.nodePos = this.$node.position();

        var MCS = this;

        this.updateForm = function() {
        	var winW = $(window).width();
        	
        	// Form is below the displayed (floating) node
		      if (winW <= 768 || (this.formPos.top && (this.formPos.top >= (this.nodePos.top + this.$node.height())))) {
		        if (!$form.hasClass('form-center')) {
		        	$form.removeClass('form-left');
		        	$form.addClass('form-center');
		        }
		      }
		      // Form is beside the displayed (floating) node
		      else {
		      	if (!$form.hasClass('form-left')) {
		        	$form.addClass('form-left');
		       		$form.removeClass('form-center');
		      	}
		      }
        };
        this.updateForm();

        // On resize, the form's position may change
	  		$(window).resize(function() {
	  			MCS.updateForm();	
	  		});
      }
    }
    catch (err) {
      console.log('Apparently something is missing: '+err);
    }
  };

})(jQuery);
