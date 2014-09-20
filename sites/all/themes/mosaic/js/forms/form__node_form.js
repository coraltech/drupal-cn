
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
        // Update only on book form and loaded events
        if (context.nodeName === '#document' || $(context).prop('id') == 'book-node-form') {
        	// Disregard node-form instances that are right under
          // the body tag... this is a panels issue: it wraps
          // the page in a form. -_-
          $nodeForm = $('.node-form').filter(function(index) {
            return !$(this).parent('body').length;
          });

          $nodeForm.each(function() {
            new Drupal.mosaic.nodeFormFilterManager($(this));
          });
        }
      }
      catch (err) {
        console.log('mosaicNodeFormInit errored: '+err);
      }
    }
  };


  // Manager of filter link clicks... how exciting, eh?
	Drupal.mosaic.nodeFormFilterManager = function($form) {
	  try {
      this.events = {}; // storage for click events
	    this.formID = Drupal.mosaic.core.createID($form);
	    this.$form  = $form;
	    this.$filterLinks = this.$form.find('.filter-help a[href="/filter/tips"]');

	    // Filter links to those not processed yet
	    this.$filterLinks = this.$filterLinks.filter(function(i) {
	      return !$(this).hasClass('ffmproc');
	    });

	    // filter out links that have already been processed
	    var nodeFormFilterManager = this; // also used in BB view
	    this.$filterLinks.each(function(i) {
	      $(this).addClass('ffmproc');
	      var id = Drupal.mosaic.core.createID($(this));
	      nodeFormFilterManager.events['click #'+id] = 'filterClick';
	    });

      // New items can be added to the form at any time so we have
	    //  to be able to process the items repeatedly, safely.
	    var FilterManagerView = Backbone.View.extend({
        // Home
        el: this.$form,

        // Settings and conf
        nodeFormFilterManager: nodeFormFilterManager,

        // events
        events: nodeFormFilterManager.events, // keyed events

        // Init
        initialize: function() {
          nodeFormFilterManager.init();
          _.bindAll(this, 'filterClick');
        },

        filterClick: function(ev) {
          ev.preventDefault();
          nodeFormFilterManager.handleFilterClick(ev);
        }
      });
      new FilterManagerView();
	  }
	  catch (err) {
	    console.log('nodeFormFilterManager errored: '+err);
	  }

	};


	// Handle clicke event on filter tips link
  Drupal.mosaic.nodeFormFilterManager.prototype.handleFilterClick = function(ev) {
    try {
      ev.preventDefault();

      this.Overlay  = Drupal.mosaic.core.objects.mboverlay;
      this.$overlay = Drupal.mosaic.core.objects.mboverlay.$overlay;

      var FFM = this;
      this.$overlay.removeClass('hidden').fadeTo(250, .65, function() {
        FFM.Overlay.updateOverlay(false);
      });

      var $filter = $(ev.currentTarget);
      var $guide  = $filter.parents('.filter-help').siblings('.filter-guidelines').show();
      this.initClose($guide); // prepare to close it
    }
    catch (err) {
      console.log('handleFilterClick errored: '+err);
    }
  };


  // Initilize the snippet node form
  Drupal.mosaic.nodeFormFilterManager.prototype.init = function() {
    try {
      // Move the field-body description above the filter formats fieldset
      var $body  = this.$form.find('.field-name-body');
      var $descr = $body.find('.description').detach();
      $body.find('fieldset.filter-wrapper').before($descr);

      var FFM = this;
      this.$filterLinks.each(function(i) {
        $(this).parents('.filter-help').siblings('.filter-guidelines').hide();
      });
    }
    catch (err) {
      console.log('Init errored: '+err);
    }
  };


  // Add closing capability
  Drupal.mosaic.nodeFormFilterManager.prototype.initClose = function($guide) {
    try {
      var FFM = this;

      var $cls = $guide.prepend('<div class="mbclose">x</div>').children('.mbclose');
      $cls.css({
        'cursor': 'pointer',
        'position': 'absolute',
        'z-index': 9,
        'font-size': '2em',
        'right': '-14px',
        'top': '-14px',
      });

      // Close click closes!
      $cls.click(function() {
        FFM.closeFilters($guide);
        $(this).remove();
      });

      // Allow closing on overlay click
      this.$overlay.off('click').click(function() {
        FFM.closeFilters($guide);
        $cls.remove();
      });
    }
    catch (err) {
      console.log('initClose errored: '+err);
    }
  };


  // Handle closing of the pane
  Drupal.mosaic.nodeFormFilterManager.prototype.closeFilters = function($guide) {
    try {
      var FFM = this;

      // hide the box
      $guide.addClass('hidden').slideUp(150);

      // update the overlay
      this.$overlay.fadeTo(250, 0, function() {
        FFM.$overlay.addClass('hidden');
        FFM.Overlay.updateOverlay(true);
      });
    }
    catch (err) {
      console.log('closeFilters errored: '+err);
    }
  };
})(jQuery);

