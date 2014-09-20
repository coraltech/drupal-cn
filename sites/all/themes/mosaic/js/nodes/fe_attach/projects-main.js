// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

/**
 * Responsive JS for projects-doc (see: Projects documentation)
 */
// Document loaded!
(function($) {

  Drupal.behaviors.mosaicProjMainInit = {
    attach : function(context, settings) {
      try {
        // Check context to make sure that we are not un-neccessarily
        // resetting and re-building the book nodes.
        if (context.nodeName === '#document') {
          new Drupal.mosaic.mosaicProjTabs(); // Find results per tab and add # to tab text
          new Drupal.mosaic.mosaicProjZap(); // add pizzaz to section title
        }
      }
      catch (err) {
        console.log('mosaicProjDocInit errored: '+err);
      }
    }
  };


  Drupal.mosaic.mosaicProjZap = function() {
    try {
      // wrap title text in a span
      $('.ui-tabs > h3').html('<span>'+$('.ui-tabs > h3').text()+'</span>');
    }
    catch (err) {
      console.log('mosaicProjZap errored: '+ err);
    }
  };


  // Run baby run!
  Drupal.mosaic.mosaicProjTabs = function() {
    try {
      // Get main project tabs
      var $tabs = $('.ui-tabs-nav li a');
      if (!$tabs.length) return; // break if nothing found

      var tabsCategories = [];

      // get view data
      var data = Drupal.settings.mosaicViews;

      // Current project types
      var projTypes = [
        'Component',
        'Framework',
        'Network',
        'Package',
        'Tools'
      ];

      var names = [
        'Components',
        'Frameworks',
        'Networks',
        'Packages',
        'Tools'
      ];

      var projCount = [];
      for (var i = 0; i < projTypes.length; i++) {
        projCount[projTypes[i]] = Drupal.settings.mosaicViews['project_listings_project_listings_'+projTypes[i]].total_items;
      }

      $tabs.each(function(i) {
        var indx = $.inArray($(this).text(), names);
        if (indx > -1) { // we have a winner!
          $(this).html($(this).text() + ' (<span class="ltyellow">'+projCount[projTypes[indx]]+'</span>)');
        }
      });
    }
    catch (err) {
      console.log('mosaicProjDoc errored: '+err);
    }
  };

})(jQuery);
