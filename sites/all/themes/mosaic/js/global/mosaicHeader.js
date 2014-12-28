// This file controls the site header

// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// ----------------------------------------------------------------------
// This scripts controls the site header and
//  determines if the header should be collapsed and fixed pos.
// ----------------------------------------------------------------------
// Document loaded!
(function($) {

  Drupal.behaviors.mosaicHeaderInit = {
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
        if (context.nodeName === '#document') { // only on doc loaded
          new Drupal.mosaic.mosaicHeader();
        }
      }
      catch (err) {
        console.log('mosaicHeaderSearchInit errored: '+err);
      }
    }
  };

  Drupal.mosaic.mosaicHeader = function() {
    try {
      // Set the core object for the header if its not defined
      Drupal.mosaic.core.objects.mosaicHeader = Drupal.mosaic.core.objects.mosaicHeader || {};

      // Make state known to other systems
      Drupal.mosaic.core.objects.mosaicHeader['state'] = 'open';

      // Init and first run stuff
      this.init();
      this.checkDims();
      var MH = this;

      // On resize
      $(window).resize(function() {
        MH.checkDims();
      });

      // On scrolling
      $(window).scroll(function() {
        MH.checkScroll();
      });
    }
    catch (err) {
      console.log('mosaicHeaderSearch errored: '+err);
    }
  };


  Drupal.mosaic.mosaicHeader.prototype.init = function() {
    try {
      this.$header = $('header');
      this.$body   = $('.page-inner-wrapper > .mosaic-cont');
      this.$limiter = $('header > .limiter');
      this.collapseWidth = 768;
    }
    catch (err) {
      console.log('init errored: '+err);
    }
  };


  Drupal.mosaic.mosaicHeader.prototype.checkScroll = function() {
    try {

      // Header is out of sight - show miniheader
      if (!Drupal.mosaic.core.visible($('header'), 'true')) {
        // Dynamic setting of header height here...
        this.$header.addClass('collapsed');
        this.$body.addClass('resp');

        // Make state known to other systems
        Drupal.mosaic.core.objects.mosaicHeader.state = 'collapsed';
      }
      else {
        if (this.winW > this.collapseWidth) {
          this.$header.removeClass('collapsed');
        }
        this.$body.removeClass('resp');

        // Make state know to other systems
        Drupal.mosaic.core.objects.mosaicHeader.state = 'open';
      }
    }
    catch (err) {
      console.log('checkScroll errored: '+err);
    }
  };


  // Check dimensions after a resize
  Drupal.mosaic.mosaicHeader.prototype.checkDims = function() {
    try {
      this.winW = $(window).width();
      if (this.winW < this.collapseWidth || !Drupal.mosaic.core.visible($('header'))) {
        this.$header.addClass('collapsed');
      }
      else {
        this.$header.removeClass('collapsed');
      }
    }
    catch (err) {
      console.log('checkDims errored: '+err);
    }
  };

})(jQuery);