// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

/**
 *
 * Mosaic forms will check to see if there are
 *  settings for any form's textfield defaults.
 *  Should only recieve requests for items that
 *  implement it. Only implement on pages where
 *  needed!
 *
 * These defaults are added via modules and 
 *  themes via whatever hooks they deem fit.
 *
 * Add new defaults to: 
 * 
 * Drupal.settings.mosaic.fieldDefaults:
 * 
 *  - fieldDefaults['.selector']['default'] = 'Default text';
 *  
*/
// Document loaded!
(function($) {
  
  Drupal.behaviors.mosaicTocInit = {    
    attach : function(context, settings) {
      try { // use try to ensure that if this breaks/fails, it won't break other stuff.
        if (Drupal.settings.mosaic.tocDefaults) {
          for (toc in Drupal.settings.mosaic.tocDefaults) {
            new Drupal.mosaic.mosaicToc(toc, Drupal.settings.mosaic.tocDefaults); 
          }
        }
      }
      catch (err) {
        console.log('mosaicTocInit() reported errors... Perhaps you ordered tea? Error: '+err);
      }
    }
  };

  // Mosaic textfieldDefault takes one textfield and ensures it is
  //  set as it should be according to the specs in textfield_defaults.inc
  Drupal.mosaic.mosaicToc = function(tocElement, tocDefaults) {
    var mosaicToc = this;
    // The tocElement refers to the ID that unifies the
    //  header (the actual) with an anchor with the same href (+#)
    var $header_element = $('#'+tocElement);
    var $toc_anchor = $('.toc a[href="#'+tocElement+'"]');
    this.$toc = $toc_anchor.parents('.toc');
    this.$parent = $(this.$toc).parent();

    var tocList = Backbone.View.extend({
      
      // Home
      el: this.$parent,
      toc: this.$toc,
      
      // Events ... null
      
      // Init
      initialize: function() { 
        mosaicToc.process(this.toc, tocElement, tocDefaults);
        //_.bindAll(this, 'blurField', 'focusField'); 
      },
      
      // Updates ... null
    });
        
    // Kick start!
    new tocList();
  };
  
  //---
  
  // Process each textfield
  Drupal.mosaic.mosaicToc.prototype.process = function($toc, tocElement, tocDefaults) {
    //console.log(tocElement);
    //console.log(tocDefaults);
    // establish unique ids for this .toc
    var tocSeed = Math.floor(1000*Math.random());
    $toc.attr('id', $toc.attr('id')+'_'+tocSeed);
    
    $tocItems = $toc.find('li a');
    $tocItems.each(function(i) {
      var id = $(this).attr('href');
      $item = $(id);
      var tagName = $item.prop('tagName');
      $top = $item.next();
      $top.removeClass('hide').addClass('toc-'+tagName).find('a').attr('href', '#'+$toc.attr('id'));
    });    
  }
})(jQuery);

