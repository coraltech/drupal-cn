
// This is a generic js file for manipulating ALL node forms
//  It should be used for all mods affecting node_edit/add forms.
//  Presently, this only handles polishing the textformats info

// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// ----------------------------------------------------------------------
// Snippet form processing
// ----------------------------------------------------------------------
(function($) { // doc loaded
  Drupal.behaviors.mosaicNodeFormInit = {    
    attach : function(context, settings) { // play it again Sam...
      try { // Use try to prevent systemic failure
      	// Disregard node-form instances that are right under
      	// the body tag... this is a panels issue: it wraps
      	// the page in a form. -_- 
      	$nodeForm = $('.node-form').filter(function(index) {
      		return !$(this).parent('body').length;
      	});
      	
      	$nodeForm.each(function() {
      		new Drupal.mosaic.nodeFormManager($(this));
      	});    	
			}
			catch (err) {
				console.log('mosaicNodeFormInit errored: '+err);
			}
		}
	};

	// @TODO see what happens when we have multiple filter tips in the same form.
	// I expect it will not work at this time. It should iterate through them.
	// As we only use one filter tips on any give node form, the issue is not a P1
	Drupal.mosaic.nodeFormManager = function($form) {
		try {
			if (!$form.hasClass('nfproc')) {
				this.id    = Drupal.mosaic.core.createID($form);
				this.$form = $form.addClass('nfproc');
				this.$filterLink  = this.$form.find('.filter-help a[href="/filter/tips"]').addClass(this.id+'-filter-tips');
				this.$filterGuide = this.$form.find('.filter-guidelines').addClass('hidden').append('<a href="/filter/tips" class="more btn">Even more information</a>').hide();
				
				this.events = {};
				this.events['click .'+this.id+'-filter-tips'] = 'filterClick';

				var nodeFormManager = this;
      	var ManagerView = Backbone.View.extend({
	        // Home
	        el: this.$form,
	        
	        // Settings and conf
	        nodeFormManager: nodeFormManager,
	        
	        // events
	        events: nodeFormManager.events, // keyed events
	                
	        // Init
	        initialize: function() {
	          nodeFormManager.init();
	          _.bindAll(this, 'filterClick');
	        },
	        
	        filterClick: function(ev) {
	          ev.preventDefault();
	          nodeFormManager.handleFilterClick(ev);
	        }
      	});
      	new ManagerView();
			} // end if
		}
		catch (err) {
			console.log('nodeFormManager errored: '+err);
		}
	};


	// Initilize the snippet node form
	Drupal.mosaic.nodeFormManager.prototype.init = function() {
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
	Drupal.mosaic.nodeFormManager.prototype.handleFilterClick = function(ev) {
		try {
			ev.preventDefault();
			if (this.$filterGuide.hasClass('hidden')) {
				this.Overlay  = Drupal.mosaic.core.objects.mboverlay;
	      this.$overlay = Drupal.mosaic.core.objects.mboverlay.$overlay;
	      
	      var NFMan = this;

				this.$overlay.removeClass('hidden').fadeTo(250, .65, function() {
					NFMan.Overlay.updateOverlay(false);
					NFMan.initClose();
				});

				this.$filterGuide.removeClass('hidden').show();
			}
		}
		catch (err) {
			console.log('handleFilterClick errored: '+err);
		}
	};
	
	
	  // Set up close facilities
  Drupal.mosaic.nodeFormManager.prototype.initClose = function() {
    try {
      var NFMan = this;
      
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
        NFMan.closePane();
      });
      
      // Listen for changes in browser scroll position (100ms)
      // Ripped from mosaicBox initClose()
      this.closeInterval = setInterval(function() {
        var docTop = $(window).scrollTop();
        var qTop = NFMan.$filterGuide.offset().top;
        var extra = 0;
        var $navBar = $('#navbar-administration');
        if ($navBar.length) extra = 40;
        if ((docTop + extra) > qTop) {
          NFMan.$close.css('top', docTop - qTop + extra);
        }
        else {
          NFMan.$close.css('top', -14);
        }
      }, 100);
    }
    catch (err) {
      console.log('initClose errored: '+err);
    }
  };
  
  
    // Handle closing of the pane
  Drupal.mosaic.nodeFormManager.prototype.closePane = function() {
    try {
      var NFMan = this;
      
      // hide the box
      this.$filterGuide.addClass('hidden').slideUp(150);
      
      // update the overlay
      this.$overlay.fadeTo(250, 0, function() {
        NFMan.$overlay.addClass('hidden');
        NFMan.Overlay.updateOverlay(true);
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

