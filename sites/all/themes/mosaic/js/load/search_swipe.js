// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

/**
 * mosaicSearchSwipeInit gets the facets viewer ready
 */
// Document loaded!
(function($) {

  Drupal.behaviors.mosaicSearchSwipeInit = {    
    attach : function(context, settings) {
    	try {
    		if (context == '#search-swipe') {
    			new Drupal.mosaic.searchSwipe(); // Set up the swipe functionality
    		}
			}
			catch (err) { console.log('mosaicSearchSwipeInit errored: '+err); }
		}
	};


	// The primary object that handles search swipe features	
	Drupal.mosaic.searchSwipe = function() {
		try {
			this.init();            // gather data
			this.updatePositions(); // set elem positioning
			this.setEvents();       // cycle events
		}
		catch (err) { console.log('searchSwipe errored: '+err); }
	};


	// Set event handlers for swipe and click
	Drupal.mosaic.searchSwipe.prototype.setEvents = function() {
		try {
			sObj = this;

	    // Respond to scroll
			$(window).scroll(function(e) {
				sObj.updatePositions();
			});
			
			// Resize event
			$(window).resize(function(e) {
				sObj.updatePositions();
			});

			// Swipe events
			$('body').off('swiperight').on('swiperight',function(e, data) {
	      sObj.showFacets(e); // Show facets content
	    });
	    $('body').off('swipeleft').on('swipeleft',function(e, data) {
	    	sObj.hideFacets(e); // Hide facets content
	    });

			// Click event
			this.$swipe.off('click').click(function(e) {
				if (sObj.$swipe.hasClass('open')) {
    			sObj.hideFacets(e);	
    		}
    		else {
    			sObj.showFacets(e);	
    		}
			});
		}
		catch (err) { console.log('Search swipe setEvents errored: '+err); }
	};


	// Set positioning of the elements given the current window dimensions
	Drupal.mosaic.searchSwipe.prototype.updatePositions = function() {
		try {
			var scrl = $(window).scrollTop();
			var winW = $(window).width();
			
			if (winW < 768) {
				if (this.$swipe.hasClass('open')) { // facets should be open

					var ftop  = this.$facets.offset().top;
					var fhite = this.$facets.innerHeight();
					var stop  = this.$swipe.offset().top;
					
					// Keep swiper positioned on the facets
					if (ftop - scrl < 0) {
						if ((scrl - ftop) > 32) {
							this.$swipe.css({'top':(scrl - ftop)+'px'});
						}
						else {
							this.$swipe.css({'top':'0px'});
						}
					}
					
					// Hide once we scroll too far down
					if ((ftop + fhite) < scrl) {
						this.hideFacets();
					}
					
					// @TODO: hide if we scroll up out of range of facets
					// @TODO: Make sure that the facet bottom does not leave
					//  the content area if the user has scrolled to bottom
					//  and then opened the facets
				}
			
				else { // facets are closed
					if (scrl > this.headerHeight) { // header is off the page
						this.$facets.css('top', (scrl - this.headerHeight) + 'px');
					}

					else { // header in view
						this.$facets.css('top', 0 + 'px');
					}
					var val = (this.isAdmin) ? 65 : 16;
					this.$swipe.css('top', Math.max(this.headerHeight + val - scrl, val)+'px');
				}
			}
			
			// Make sure the facet block is cleared of it's responsive oriented styles
			else {
				$('body').off('swipeleft').off('swiperight'); // unbind body events
				
				this.$swipe.attr('style', '').removeClass('open');
	     	this.$facets.attr('style', '');
	     	this.$content.attr('style', '');
			}
		}
		catch (err) { console.log('Search swipe position errored: '+err); }
	};
	

	// Show the facets
	Drupal.mosaic.searchSwipe.prototype.showFacets = function(e) {
		try {
			this.$swipe.css({ // set up the swipeit to maintain bounds
      	'position':'absolute',	// between the top and bot. of the 
      	'top':'0px' // facets pane 
      });
			
			// Slide out the swipeit 
			this.$swipe.animate({'left': this.$facets.width()+'px'}, 150);
      this.$swipe.addClass('open'); // it's open

      
			this.$facets.animate({ 'left': '0%' }, 150);
      if (this.$facets.height() > this.$content.height()) {
      	this.contOrigH = this.$content.height();
      	this.$content.animate({'height': this.$facets.height() }, 150);
      }
			// ensure there is no hidden selection that 
			//  would prevent a next swipe.
      if ($(e.target).hasClass('swipeit')) this.clearSelection();
		}
		catch (err) { console.log('Search swipe showFacets errored: '+err); }
	};


	// Hide the facets
	Drupal.mosaic.searchSwipe.prototype.hideFacets = function(e) {
		try {
			sObj = this;
			
			this.$facets.animate({ 'left': '-51%' }, 150); // 51 to make sure its out of view
    	if (this.contOrigH > 0) {
    		this.$content.animate({'height': this.contOrigH }, 150);
    	}
    	this.$swipe.css('left', '100%');
    	this.$swipe.animate({'left': '0%'}, 150, function() {
    		sObj.$swipe.removeClass('open').attr('style', '');
    		sObj.updatePositions();
    	});

    	if (e && $(e.target).hasClass('swipeit')) this.clearSelection();
		}
		catch (err) { console.log('Search swipe hideFacets errored: '+err); }
	};


	// Clear text selection that may have occurred
	Drupal.mosaic.searchSwipe.prototype.clearSelection = function() {
		try {	document.selection.empty(); }
  	catch (err) {} // nothing 
  	try { window.getSelection().removeAllRanges() }
  	catch (err) {} // nothing here either
	}


	// Gather the data needed for processing
	Drupal.mosaic.searchSwipe.prototype.init = function() {
		try {
			this.$parent = $('.page-search .main-content').parent('.row');
			this.$swipe  = $('.pane-coral-swipe');
  		this.$facets = $('.page-search .secondary-content');
  		this.$content = $('.page-search .main-content');
  		this.contOrigH = -1;
  		this.isAdmin = ($('#navbar-administration').length) ? true : false;
  		this.headerHeight = $('header').height();
  	}
		catch (err) { console.log('Search swipe init errored: '+err); }
	};
	
})(jQuery);
