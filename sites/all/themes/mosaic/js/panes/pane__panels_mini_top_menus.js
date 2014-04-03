
// This file controls advanced behaviors of the primary menus (Main | Service)

// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// ----------------------------------------------------------------------
// Primary menus scripts
// ----------------------------------------------------------------------
// Document loaded!
(function($) {

  Drupal.behaviors.mosaicTopMenusInit = {    
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
      	if (context.nodeName === '#document') { // only on doc loaded
      		new Drupal.mosaic.mosaicTopMenus();
      	}	        
      }
      catch(err) {
        console.log('mosaicTopMenusInit reported errors! Error: '+err);
      }
    }
  };
  

	// Main object - could be backbone if needed
  Drupal.mosaic.mosaicTopMenus = function() {
  	try {
  		// Start up
      this.initMenus();
      
      // Add overlay
      this.addOverlay();
      	
      // add events (tap / click)
			this.addEvents();
  	}
  	catch (err) {
  		console.log('mosaicTopMenus errored: '+err);
  	}
  };


  // Get data
  Drupal.mosaic.mosaicTopMenus.prototype.initMenus = function() {
  	try {
			var TM = this;

      this.$menus = $('#mini-panel-top_menus .panel-pane'); // Get menus
  		this.$menus.each(function() {
	  		var $ul = $(this).find('.pane-content > ul'); // only get the top lvl...
	     	if (!$(this).find('.respond').length) {       // already added?
	       	if ($(this).hasClass('pane-menu-main')) {   // main menu
	       		var msg = Drupal.t('Menu');
	       		$ul.before('<span class="respond"><span class="icon"></span>'+msg+'</span>');
	       		
	       		TM.$mainMenu = $ul;
	       		TM.$mainIcon = $(this).find('.respond');
	       	}
	       	else {                                      // service menu
	       		var msg = Drupal.t('Account');
	       		$ul.after('<span class="respond">'+msg+'<span class="icon"></span></span>');

	       		TM.$serviceMenu = $ul;
	       		TM.$serviceIcon = $(this).find('.respond');
	      	}
	     	}
    	});
   	}
  	catch (err) {
  		console.log('init errored: '+err);
  	}
  };


  // Add events
  Drupal.mosaic.mosaicTopMenus.prototype.addEvents = function() {
  	try {
  		var TM = this;

			if (this.$mainIcon.length && this.$serviceIcon.length) {


  			// Set main menu click handler
  			this.$mainIcon.off('click').click(function() {
  				if (!TM.$mainMenu.hasClass('open')) {
  					TM.showOverlay();
  					TM.hideMenu(TM.$serviceMenu, 'right');
  					TM.showMenu(TM.$mainMenu);
  				}
  				else {
  					TM.hideOverlay();
  					TM.hideMenu(TM.$mainMenu);
  				}
  			});


				// Set service menu click handler
  			this.$serviceIcon.off('click').click(function() {
  				if (!TM.$serviceMenu.hasClass('open')) {
  					TM.showOverlay();
  					TM.hideMenu(TM.$mainMenu);
  					TM.showMenu(TM.$serviceMenu, 'right');
  				}
  				else {
  					TM.hideOverlay();
  					TM.hideMenu(TM.$serviceMenu, 'right');
  				}
  			});
			}


			// On re-size past tablet width, undo changes
  		$(window).resize(function() {
  			var winW = $(window).width();
  			if (winW > 768) {
  				TM.hideOverlay();
  				TM.$mainMenu.attr('style', '').removeClass('open');
  				TM.$serviceMenu.attr('style', '').removeClass('open');
  			}
  		});


  		// Overlay is not ready for 1/2 second after page is loaded
  		this.$overlay.off('click').click(function() {
  			TM.hideOverlay();
  			TM.hideMenu(TM.$mainMenu);
  			TM.hideMenu(TM.$serviceMenu, 'right');
  		});	
  		
  	}
  	catch (err) {
  		console.log('addEvents errored: '+err);
  	}
  };


	// Show a menu
  Drupal.mosaic.mosaicTopMenus.prototype.showMenu = function($menu, dir) {
  	try {
  		this.showOverlay();
  		
  		var dir = dir || 'left';
  		if (dir === 'left') {
  			$menu.slideDown(0).css({'position':'absolute', 'top':'0px', 'left': '0px', 'z-index':'9'}).addClass('open');
  		}
  		else { 
  			$menu.slideDown(0).css({'position':'absolute', 'top':'0px', 'right': '0px', 'z-index':'9'}).addClass('open'); 
  		}
  	}
  	catch (err) {
  		console.log('showMenu errored: '+err);
  	}
  };


	// Hide a menu  
  Drupal.mosaic.mosaicTopMenus.prototype.hideMenu = function($menu, dir) {
  	try {
  		this.hideOverlay();
  		
  		var dir = dir || 'left';
  		if (dir === 'left') {
  			$menu.slideUp(0).css({'position':'absolute', 'top':'0px', 'left': '0px'}).removeClass('open');
  		}
  		else { 
  			$menu.slideUp(0).css({'position':'absolute', 'top':'0px', 'right': '0px'}).removeClass('open'); 
  		}
  	}
  	catch (err) {
  		console.log('hideMenu errored: '+err);
  	}
  };


	// Add an(other) overlay to page (cant use mboverlay as we get some event mixing)
	Drupal.mosaic.mosaicTopMenus.prototype.addOverlay = function() {
		try {
			var $overlay = $('.tm-over'); 
			if (!$overlay.length) {
				$('body').append('<div class="tm-over hidden"></div>');
        $overlay = $('body').children('.tm-over');
        
        var height = $(document).height();
        $overlay.css({
		      'height': height+'px',
		      'width': '100%',
		      'background': '#000000',
		      'position': 'absolute',
		      'top': 0,
		      'left': 0,
		      'z-index': 7,
		      'display': 'none'
		    });
      }
      
      this.$overlay = $overlay; // set the overlay in the object
		}
		catch (err) {
			console.log('addOverlay errored: '+err);
		}
	};


	// Update overlay
	Drupal.mosaic.mosaicTopMenus.prototype.updateOverlay = function(display) {
		try {
			if (this.$overlay.length) {
				if (display == 'show') {
					this.$overlay.fadeTo(0, .35);
				}
				else {
					this.$overlay.fadeTo(0, 0).hide();
				}
			}
			this.$overlay.css({'height': $(document).height()+'px'});
		}
		catch (err) {
			console.log('updateOverlay errored: '+err);
		}
	};


	// Show overlay
  Drupal.mosaic.mosaicTopMenus.prototype.showOverlay = function() {
  	try {
  		$('header').css({'position': 'relative', 'z-index': '9'});
  		$('.pane-top-menus').css({'z-index': '9'});
  		this.updateOverlay('show');
  	}
  	catch (err) {
  		console.log('showOverlay errored: '+err);
  	}	
 	};


	// Hide overlay
 	Drupal.mosaic.mosaicTopMenus.prototype.hideOverlay = function() {
  	try {
  		$('header').attr('style', '');
  		$('.pane-top-menus').attr('style', '');
  		this.updateOverlay('hide');
  	}
  	catch (err) {
  		console.log('hideOverlay errored: '+err);
  	}	
 	};
})(jQuery);
