
// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

/**
 * mosaicMediaSingleInit takes care of scaling iframed videos in the titular view
 */
// Document loaded!
(function($) {

  Drupal.behaviors.mosaicMediaSingleInit = {
    attach : function(context, settings) {
      try {
        // Ensure context
        if (context.nodeName === '#document') {
          new Drupal.mosaic.mediaSingleView();
        }
      }
      catch (err) {
        console.log('mosaicSectionIntroInit errored: '+err);
      }
    }
  };

  // Single view media display (individual vids)
  Drupal.mosaic.mediaSingleView = function() {
    try {
      this.init();
      this.size();
      var SV = this;

      $(window).resize(function() { SV.size(); });
    }
    catch(err) {
      console.log('mediaSingleIntro errored: '+err);
    }
  };


  // ZzZap!
  Drupal.mosaic.mediaSingleView.prototype.init = function() {
    try {
      this.$pane = $('.view-display-id-media_single_fullsize');
      this.$frame = this.$pane.find('iframe');
      this.$frame.originalHeight = this.$frame.outerHeight(); // set orig
      this.$frame.originalWidth = this.$frame.outerWidth();   //  dims
    }
    catch(err) {
      console.log('init errored: '+err);
    }
  };


  // Size the iframe keeping aspect ratio
  Drupal.mosaic.mediaSingleView.prototype.size = function() {
    try {
      if (this.$pane.length && this.$frame.length) {
        var cw = this.$pane.outerWidth(); // container w
        var nh = 0; // new height

        // Update dimensions
        if (cw < this.$frame.originalWidth) {
          nh = (this.$frame.originalHeight * cw) / this.$frame.originalWidth;
          this.$frame.attr('height', nh).attr('width', cw);
        }
        else { // reset back to normal
          this.$frame.attr('height', this.$frame.originalHeight).attr('width', this.$frame.originalWidth);
        }
      }
    }
    catch(err) {
      console.log('init errored: '+err);
    }
  };

})(jQuery);

// move along - nothing to see here