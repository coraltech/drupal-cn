
// This is to help format the installation documentation page
//  It is applied currently via the book page's fe_attach field 


// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

/**
 * Responsive JS for projects-doc (see: Projects documentation)
 */
// Document loaded!
(function($) {

  Drupal.behaviors.mosaicInstallDocInit = {    
    attach : function(context, settings) {
      try {
        // Check context to make sure that we are not un-neccessarily
        // resetting and re-building the book nodes.
        if (context.nodeName === '#document') {
          var $instDoc = $('.installation-doc:not(".instdoc-proc")');
          if ($instDoc.length) {
            $instDoc.each(function() {
              new Drupal.mosaic.mosaicInstallDoc($(this));  
            });
          }
        }
      }
      catch (err) {
        console.log('mosaicInstallDocInit errored: '+err);
      }
    }
  };


  // Run baby run!
  Drupal.mosaic.mosaicInstallDoc = function($cont) {
    try {
      // Do stuff ;-)
      this.$cont = $cont.addClass('instdoc-proc');
      this.w     = $cont.outerWidth();
      var IDI    = this; // save this!

      this.orientItems(); // init orientation

      // Set events
      $(window).resize(function(e) { IDI.orientItems(); });
    }
    catch (err) {
      console.log('mosaicInstallDoc errored: '+err);
    }
  };


  // Adjust items on event
  Drupal.mosaic.mosaicInstallDoc.prototype.orientItems = function() {
    try {
      this.w = this.$cont.outerWidth();

      (this.w < 550) ? 
        this.$cont.find('.grid-14-last, .grid-10-last').css({ 'width':'100%', 'margin':'0 0 1.25em 0'}) :
        this.$cont.find('.grid-14-last, .grid-10-last').attr('style', ''); //reset css
        
      (this.w < 500) ? 
        this.$cont.find('.grid-8, .grid-16-last').css({ 'width':'100%', 'margin':'0 0 1.25em 0'}) :
        this.$cont.find('.grid-8, .grid-16-last').attr('style', ''); //reset css
    }
    catch (err) {
      console.log('orientItems errored: '+err);
    }
  };
  
})(jQuery);
