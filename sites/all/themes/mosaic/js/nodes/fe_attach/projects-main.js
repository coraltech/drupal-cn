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
          new Drupal.mosaic.mosaicProjMain();
        }
      }
      catch (err) {
        console.log('mosaicProjDocInit errored: '+err);
      }
    }
  };


  // Run baby run!
  Drupal.mosaic.mosaicProjMain = function() {
    try {
      // Get main project tabs
      var $tabs = $('.ui-tabs-nav li a');
      if (!$tabs.length) return; // break if nothing found

      var tabsCategories = [];

      // get view data
      var data = Drupal.settings.mosaicViews;

      // Current project types
      var projTypes = [
        'Components',
        'Frameworks',
        'Networks',
        'Packages',
        'Plugins',
        'Tools'
      ];

      var projCount = [];
      for (var i in projTypes) {
        projCount[projTypes[i]] = Drupal.settings.mosaicViews['project_listings_project_listings_'+projTypes[i]].total_items;
      }

      $tabs.each(function() {
        if ($.inArray($(this).text(), projTypes) > -1) { // we have a winner!
          $(this).html($(this).text() + ' (<span class="mdblue">'+projCount[$(this).text()]+'</span>)');
        }
      });
    }
    catch (err) {
      console.log('mosaicProjDoc errored: '+err);
    }
  };

})(jQuery);
