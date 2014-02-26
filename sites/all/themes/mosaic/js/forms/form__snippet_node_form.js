
// js file for snippet form

// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// ----------------------------------------------------------------------
// Snippet form processing
// ----------------------------------------------------------------------
(function($) { // doc loaded
  Drupal.behaviors.mosaicSnippetFormInit = {    
    attach : function(context, settings) { // play it again Sam...
      try { // Use try to prevent systemic failure
      	// Disregard node-form instances that are right under
      	// the body tag... this is a panels issue: it wraps
      	// the page in a form. -_- 
      	$nodeForm = $('.node-snippet-form').filter(function(index) {
      		return !$(this).parent('body').length;
      	});
      	
      	$nodeForm.each(function() {
      		new Drupal.mosaic.snippetManager($(this));
      	});    	
			}
			catch (err) {
				console.log('mosaicSnippetFormInit errored: '+err);
			}
		}
	};


	Drupal.mosaic.snippetManager = function($form) {
		try {
			if (!$form.hasClass('sfproc')) {
				this.id    = Drupal.mosaic.core.createID($form);
				this.$form = $form.addClass('sfproc');
				this.$filterLink  = this.$form.find('.filter-help a[href="/filter/tips"]').addClass(this.id+'-filter-tips');
				this.$filterGuide = this.$form.find('.filter-guidelines').addClass('hidden').append('<a href="/filter/tips" class="more btn">Even more information</a>').hide();
				
				this.events = {};
				this.events['click .'+this.id+'-filter-tips'] = 'filterClick';

				var snippetManager = this;
      	var ManagerView = Backbone.View.extend({
	        // Home
	        el: this.$form,
	        
	        // Settings and conf
	        snippetManager: snippetManager,
	        
	        // events
	        events: snippetManager.events, // keyed events
	                
	        // Init
	        initialize: function() {
	          snippetManager.init();
	          _.bindAll(this, 'filterClick');
	        },
	        
	        filterClick: function(ev) {
	          ev.preventDefault();
	          snippetManager.handleFilterClick(ev);
	        }
      	});
      	new ManagerView();
			} // end if
			
			// Add class to first tr of snippet components
			// We do this even if the form has already been processed.
			var $rows = $form.find('.field-name-field-snippet-components tr.draggable').removeClass('first').removeClass('last');
			$rows.first().addClass('first');
			$rows.last().addClass('last');
		}
		catch (err) {
			console.log('snippetManager errored: '+err);
		}
	};


	// Initilize the snippet node form
	Drupal.mosaic.snippetManager.prototype.init = function() {
		try {
			// Move the field-body description above the filter formats fieldset
			var $body  = this.$form.find('.field-name-body');
			var $descr = $body.find('.description').detach();
			$body.find('fieldset.filter-wrapper').before($descr);	
		}
		catch (err) {
			console.log('Init errored: '+err);
		}
	};


	// Handle clicke event on filter tips link
	Drupal.mosaic.snippetManager.prototype.handleFilterClick = function(ev) {
		try {
			ev.preventDefault();
			if (this.$filterGuide.hasClass('hidden')) {
				this.Overlay  = Drupal.mosaic.core.objects.mboverlay;
	      this.$overlay = Drupal.mosaic.core.objects.mboverlay.$overlay;
	      
	      var SMan = this;

				this.$overlay.removeClass('hidden').fadeTo(250, .65, function() {
					SMan.Overlay.updateOverlay(false);
					SMan.initClose();
				});

				this.$filterGuide.removeClass('hidden').show();
			}
		}
		catch (err) {
			console.log('handleFilterClick errored: '+err);
		}
	};
	
	
	  // Set up close facilities
  Drupal.mosaic.snippetManager.prototype.initClose = function() {
    try {
      var SMan = this;
      
      this.$filterGuide.prepend('<div class="mbclose">x</div>');
      this.$close = this.$filterGuide.children('.mbclose');
      this.$close.css({
        'cursor': 'pointer',
        'position': 'absolute',
        'z-index': 9,
        'font-size': '2em',
        'right': '-14px',
        'top': '-14px',
      });
      this.$close.click(function() {
        SMan.closePane();
      });
      
      // Listen for changes in browser scroll position (100ms)
      // Ripped from mosaicBox initClose()
      this.closeInterval = setInterval(function() {
        var docTop = $(window).scrollTop();
        var qTop = SMan.$filterGuide.offset().top;
        var extra = 0;
        var $navBar = $('#navbar-administration');
        if ($navBar.length) extra = 40;
        if ((docTop + extra) > qTop) {
          SMan.$close.css('top', docTop - qTop + extra);
        }
        else {
          SMan.$close.css('top', -14);
        }
      }, 100);
    }
    catch (err) {
      console.log('initClose errored: '+err);
    }
  };
  
  
    // Handle closing of the pane
  Drupal.mosaic.snippetManager.prototype.closePane = function() {
    try {
      var SMan = this;
      
      // hide the box
      this.$filterGuide.addClass('hidden').slideUp(150);
      
      // update the overlay
      this.$overlay.fadeTo(250, 0, function() {
        SMan.$overlay.addClass('hidden');
        SMan.Overlay.updateOverlay(true);
      });
      
      clearInterval(this.closeInterval); // clear close btn positioning timer
      
      this.$close.remove();
      delete this.$close;
    }
    catch (err) {
      console.log('closePane errored: '+err);
    }
  };
  
})(jQuery);

