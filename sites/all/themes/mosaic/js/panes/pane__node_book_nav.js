
// This file will manage the display of the book node nav

Drupal.mosaic = Drupal.mosaic || {};

// Document loaded!
(function($) {

  Drupal.behaviors.coralBookNavInit = {
    attach : function(context, settings) {
      try {
        var $nav = $('.pane-node-book-nav:not(".book-nav-proc")');
        if ($nav.length) {
        	$nav.each(function() {
        		new Drupal.mosaic.bookNav($nav);	
        	});
        }
      }
      catch (err) {
        console.log('coralBookNavInit() reported errors. Error: '+err);
      }
    }
  };


	// Book nav startup
	Drupal.mosaic.bookNav = function($nav) {
		try {
			this.init($nav);
			this.orientItems();

			var BN = this;
			$(window).resize(function() { BN.orientItems(); });
		}
		catch (err) {
			console.log('bookNavInit errored: '+err);
		}
	};


	// Get objects together
	Drupal.mosaic.bookNav.prototype.init = function($nav) {
		this.$nav  = $nav.addClass('book-nav-proc'); // the actual pane
		this.$tree = this.$nav.find('.tree');        // ul list of items
		this.$prev = this.$nav.find('.btn-prev');    // prev btn
		this.$next = this.$nav.find('.btn-next');    // next btn
		this.$up   = this.$nav.find('.book-parent'); // up to parent btn
		this.$cont = this.$nav.find('.book-navigation'); // the book-nav container
		this.$ttl  = this.$nav.find('.pane-title');  // pane title
	};


	// Ensure proper orientation of nav items
	Drupal.mosaic.bookNav.prototype.orientItems = function() {
		try {
			var navW = this.$nav.outerWidth();
			
			// configure css to let items have various heights
			// Do we have a tree?
			if (this.$tree.length && navW > 512) {
				var h = this.$tree.outerHeight();
				if (h > 100) h = 100;
				this.$prev.css({
					'height': h, 
					'line-height': (h-3)+'px',
					'position':'static',
					'width':'16.667%'
				});
				this.$next.css({
					'height': h, 
					'line-height': (h-3)+'px',
					'position':'static',
					'width':'16.667%'
				});
				this.$ttl.css({
					'position':'static',
					'top':'inherit'					
				});
				this.$tree.css({'width':'66.667%'});
				this.$nav.css({'margin-top':'1.25em'});
				this.$up.css({'top': '-11px'});
			}

			if (this.$tree.length && navW <= 512) {
				this.$prev.css({
					'position': 'absolute',
					'top': '-2em',
					'left': '0',
					'width': '50%',
					'line-height':'inherit',
					'height':'auto'
				});
				this.$next.css({
					'position': 'absolute',
					'top': '-2em',
					'right': '0',
					'width': '50%',
					'line-height':'inherit',
					'height':'auto'
				});
				this.$ttl.css({
					'position':'relative',
					'top':'-1.65em'
				});
				this.$tree.css({'width': '100%'});
				this.$nav.css({'margin-top': '3em'});
				this.$up.css({'top': '-2.65em'});
			}

			// This should come last...			
			this.$up.css('right', (this.$next.outerWidth() - (this.$up.outerWidth() / 2)) + 'px');

		}
		catch (err) {
			console.log('orientItems errored: '+err);
		}
	};
	
	
})(jQuery);
