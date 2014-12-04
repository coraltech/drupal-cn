// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};


// ----------------------------------------------------------------------
// Currently this is just aesthetic deco stuff...
//  It keeps the Scenarios col the same height
//  as the CORL structure image col.
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicCorlStructInit = {
    attach : function(context, settings) {
      try {
        if (context.nodeName === '#document') {
          new Drupal.mosaic.mosaicCorlStruct();
        }
      }
      catch(err) {
        console.log('mosaicHAInit errored: '+err);
      }
    }
  };


  Drupal.mosaic.mosaicCorlStruct = function() {
    try {
      this.$pane = $('.pane-corl-structure');
      this.refID = Drupal.mosaic.core.createID(this.$pane);
      this.csmin = 1000;
      var CS = this;

      // Update comp dims
      setTimeout(function() {
        CS.updateDims();
      }, 50);

      // Add events
      this.addEvents();
    }
    catch (err) {
      console.log('mosaicCorlStruct errored: '+err);
    }
  };


  Drupal.mosaic.mosaicCorlStruct.prototype.addEvents = function() {
    try {
      var CS = this;
      $(window).resize(function() {
        CS.updateDims();
      });
    }
    catch (err) {
      console.log('addEvents errored: '+err);
    }
  };


  Drupal.mosaic.mosaicCorlStruct.prototype.updateDims = function() {
    try {
      var winW = $(window).width();

      var $col1 = this.$pane.find('.grid-16');
      var $col2 = this.$pane.find('.grid-8-last');
      var c1h = $col1.outerHeight();
      var c2h = $col2.outerHeight();

      if (winW > this.csmin) {
        this.$pane.removeClass('csmin');
        $col2.children('div:first-child').css('min-height', c1h+'px'); // add height
      }
      else {
        this.$pane.addClass('csmin');
        $col2.children('div:first-child').attr('style', ''); // clear formatting
      }
    }
    catch (err) {
      console.log('updateDims errored: '+err);
    }
  };

})(jQuery);
