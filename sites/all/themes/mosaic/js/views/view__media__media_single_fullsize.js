
// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

/**
 * mosaicSectionIntroInit takes care of a few items on the main projects page
 *   This is where this block tends to show up.
 */
// Document loaded!
(function($) {

  Drupal.behaviors.mosaicMediaSingleInit = {
    attach : function(context, settings) {
      try {
        // Ensure context
        if (context.nodeName === '#document') {
          new Drupal.mosaic.mediaSingleIntro();
        }
      }
      catch (err) {
        console.log('mosaicSectionIntroInit errored: '+err);
      }
    }
  };

  Drupal.mosaic.mediaSingleIntro = function() {
    try {
      this.init();
      this.size();
      var SI = this;
      $(window).resize(function() { SI.size(); });
    }
    catch(err) {
      console.log('mediaSingleIntro errored: '+err);
    }
  };


  // ZzZap!
  Drupal.mosaic.mediaSingleIntro.prototype.init = function() {
    try {
      this.$pane = $('.view-display-id-media_single_fullsize');
      this.$frame = this.$pane.find('iframe');
      this.$frame.originalHeight = this.$frame.outerHeight();
      this.$frame.originalWidth = this.$frame.outerWidth();
    }
    catch(err) {
      console.log('init errored: '+err);
    }
  };


  // Size the iframe keeping aspect ratio
  Drupal.mosaic.mediaSingleIntro.prototype.size = function() {
    try {
      if (this.$pane.length && this.$frame.length) {
        var cw = this.$pane.outerWidth();
        var nh = 0; // new height
        if (cw < this.$frame.originalWidth) {
          nh = (this.$frame.originalHeight * cw) / this.$frame.originalWidth;
          this.$frame.attr('height', nh).attr('width', cw);
        }
      }
    }
    catch(err) {
      console.log('init errored: '+err);
    }
  };

})(jQuery);
