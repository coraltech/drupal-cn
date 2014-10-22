
// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

/**
 * mosaicSectionIntroInit takes care of a few items on the main projects page
 *   This is where this block tends to show up.
 */
// Document loaded!
(function($) {

  Drupal.behaviors.mosaicSectionIntroInit = {
    attach : function(context, settings) {
      try {
        //var keys = Object.keys(context); for (key in keys) { console.log(keys[key]+': '+context[keys[key]]); }

       // Ensure context
        if (context.nodeName === '#document') {
          new Drupal.mosaic.sectionIntro();
        }
      }
      catch (err) {
        console.log('mosaicSectionIntroInit errored: '+err);
      }
    }
  };


  Drupal.mosaic.sectionIntro = function() {
    try {
      this.init();
      this.resize();
    }
    catch (err) {
      console.log('SectionIntro errored: '+err);
    }
  };


  Drupal.mosaic.sectionIntro.prototype.init = function() {
    try {
      this.$h3 = $('div.ui-tabs.project-library > h3');
    }
    catch(err) {
      console.log('Init errored: '+err);
    }
  };


  Drupal.mosaic.sectionIntro.prototype.resize = function() {
    try {
      this.ems = 0;
      this.$row = this.$h3.parents('.row');
      this.compute(); // first run

      var SI = this;
      $(window).resize(function() { SI.compute(); });
    }
    catch (err) {
      console.log('resize errored: '+err);
    }
  };


  Drupal.mosaic.sectionIntro.prototype.compute = function() {
    try {
      var width = this.$row.outerWidth();
      this.ems = (15.5 * width) / 1024;
      this.$h3.css({'padding-left': this.ems+'em', 'margin-left': '-'+this.ems+'em'});
    }
    catch (err) {
      console.log('compute errored: '+ err);
    }
  };

})(jQuery);
