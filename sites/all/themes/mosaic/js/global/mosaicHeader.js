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
      this.$header = $('header');
      this.$limiter = $('header > .limiter');
      this.collapseWidth = 668;

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


  Drupal.mosaic.mosaicHeader.prototype.checkScroll = function() {
    try {
      // Set the core object for the header if its not defined
      Drupal.mosaic.core.objects.mosaicHeader = Drupal.mosaic.core.objects.mosaicHeader || {};

      // Header is out of sight - show miniheader
      if (!Drupal.mosaic.core.visible($('header'))) {
        this.$header.css('height', '52px').addClass('collapsed');
        this.$limiter.css({
          'position': 'fixed',
          'width': '100%',
          'z-index': '9'
        });

        // Make state know to other systems
        Drupal.mosaic.core.objects.mosaicHeader['state'] = 'collapsed';
      }
      else {
        if (this.winW > this.collapseWidth) {
          this.$header.removeClass('collapsed');
        }
        this.$header.attr('style', '');
        this.$limiter.attr('style', '');

        // Make state know to other systems
        Drupal.mosaic.core.objects.mosaicHeader['state'] = 'open';
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