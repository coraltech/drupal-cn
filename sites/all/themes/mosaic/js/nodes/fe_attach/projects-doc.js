// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

/**
 * Responsive JS for projects-doc (see: Projects documentation)
 */
// Document loaded!
(function($) {

  Drupal.behaviors.mosaicProjDocInit = {    
    attach : function(context, settings) {
      try {
        // Check context to make sure that we are not un-neccessarily
        // resetting and re-building the book nodes.
        if (context.nodeName === '#document') {
          var $projDoc = $('.projects-doc:not(".prdoc-proc")');
          if ($projDoc.length) {
            $projDoc.each(function() {
              new Drupal.mosaic.mosaicProjDoc($(this));  
            });
          }
        }
      }
      catch (err) {
        console.log('mosaicProjDocInit errored: '+err);
      }
    }
  };


  // Run baby run!
  Drupal.mosaic.mosaicProjDoc = function($cont) {
    try {
      // Do stuff ;-)
      this.$cont = $cont.addClass('prdoc-proc');
      this.w     = $cont.outerWidth();
      var PDI    = this; // save this!

      this.orientItems(); // init orientation

      // Set events
      $(window).resize(function(e) { PDI.orientItems(); }); }
    catch (err) {
      console.log('mosaicProjDoc errored: '+err);
    }
  };


  // Adjust items on event
  Drupal.mosaic.mosaicProjDoc.prototype.orientItems = function() {
    try {
      this.w = this.$cont.outerWidth();
      
      // Intro and diagram
      if (this.w < 550) {
        this.$cont.find('.grid-12-last.diagram, .grid-12.intro').css({ 'width':'100%', 'margin':'0 0 2.5em 0'});
      }
      else {
        this.$cont.find('.grid-12-last.diagram, .grid-12.intro').attr('style', ''); //reset css
      }
      
      // Tools and utils
      if (this.w < 520) {
        this.$cont.find('.grid-8-last, .grid-8').css({ 'width':'auto', 'margin':'1.25em 0', 'padding-top': '0'}).addClass('box');
        this.$cont.find('.grid-8-last .center.btn, .grid-8 .center.btn').removeClass('hide');
        this.$cont.find('.row').hide(0);
      }
      else {
        this.$cont.find('.grid-8-last, .grid-8').attr('style', '').removeClass('box'); //reset css
        this.$cont.find('.grid-8-last .center.btn, .grid-8 .center.btn').addClass('hide');
        this.$cont.find('.row').show(0);
      }

      // Frameworks
      if (this.w < 400) {
        this.$cont.find('.grid-12-last.corl, .grid-12.nucleon').css({ 'width':'100%', 'margin':'0 0 2.5em 0'});
      }
      else {
        this.$cont.find('.grid-12-last.corl, .grid-12.nucleon').attr('style', ''); //reset css
      }      
    }
    catch (err) {
      console.log('orientItems errored: '+err);
    }
  }
  
})(jQuery);
