// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

/**
 * Responsive JS for projects-doc (see: Projects documentation)
 */
// Document loaded!
(function($) {

  Drupal.behaviors.mosaicUseCasesInit = {    
    attach : function(context, settings) {
      try {
        // Check context to make sure that we are not un-neccessarily
        // resetting and re-building the book nodes.
        if (context.nodeName === '#document') {
          var $useCases = $('.use-cases:not(".ucproc")');
          if ($useCases.length) {
            $useCases.each(function() {
              new Drupal.mosaic.mosaicUseCases($(this));  
            });
          }
        }
      }
      catch (err) {
        console.log('mosaicUseCasesInit errored: '+err);
      }
    }
  };


  Drupal.mosaic.mosaicUseCases = function($useCase) {
    try {
      this.$useCase = $useCase;

      var MUC = this;
      $(window).resize(function() {
        MUC.resize();
      }); 
      
      
    }
    catch (err) {
      console.log('mosaicUseCases errored: '+err);
    }
  };
  
  
  Drupal.mosaic.mosaicUseCases.prototype.resize = function() {
    try {
      var w = this.$useCase.outerWidth();
      console.log(w);
      if (w < 500) {
        this.$useCase.find('.left.center, .right.center').css({
          'width':'100%',
          'float':'none',
          'margin-bottom':'1.25em'
        });
      }
      else {
        this.$useCase.find('.left.center, .right.center').attr('style', '');
      }
    }
    catch (err) {
      console.log('resize errored: '+err);
    }
  };
  

})(jQuery);
