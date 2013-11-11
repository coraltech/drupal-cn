// This file will provide a central access point for mosaic components

// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// Document loaded!
(function($) {

  Drupal.behaviors.mosaicInit = {
    attach : function(context, settings) {
      try {// Use try to prevent systemic failure
        if (!Drupal.mosaic.hasOwnProperty('core')) {
          Drupal.mosaic.core = new Drupal.mosaic.mosaicCore();
          Drupal.mosaic.core.objects = {};
        }
      } catch (err) {
        console.log('mosaicInit() reported errors. Error: ' + err);
      }
    }
  };
  
  
  Drupal.mosaic.mosaicCore = function() {
    try {
      // shared methods      
    }
    catch (err) {
      console.log('mosaicCore errored: '+err);
    }
  };
  
  
  // Analyze the object and pull ID data
  // Inputs:
  //  pat (string) - a pattern to search for; defaults to /node-\d+/
  //  cls (string) - a class to replace with empty space; harvesting the integer
  Drupal.mosaic.mosaicCore.prototype.initID = function($obj, pat, cls) {
    try {
      var objPattern = pat || /node-\d+/;
      var objClass = cls || 'node-';
  
      // find this button's nid and ensure the AnswerView's  
      var classes = $obj.attr('class');
      classes = classes.split(" ");
      for (cls in classes) {
        var c = classes[cls];
        if (c.match(objPattern)) {
          return c.replace(objClass, ''); // and the nid
        }
      }
    }
    catch (err) {
      console.log('initID errored: '+err);
    }
  };
  
})(jQuery);