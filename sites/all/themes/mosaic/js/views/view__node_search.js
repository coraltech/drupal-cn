// Registers the Mosaic namespace

// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};


// Document loaded!
(function($) {
  Drupal.behaviors.mosaicNodeSearchInit = {    
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
        
        // Manage the search rows as needed
        var $view = $('.pane-node-search-node-search-results');
        if ($view.length > 0) {
          new Drupal.mosaic.nodeSearchManager($view);
        }
        
        // See: https://drupal.org/comment/8432125#comment-8432125
        var $facetLists = $('.facet-pane ul');
        if ($facetLists.length > 0) {
          $facetLists.each(function() {
            new Drupal.mosaic.facetManager($(this));  
          });
        }
        
        // Current search block 
        // Note: The limited functionality and the relatedness to
        // search itself is why I am putting this here instead
        // of it's own pane js file. (eg. pane_block__current_search...)
        var $currentSearch = $('.pane-current-search-standard');
        if ($currentSearch.length > 0) {
          new Drupal.mosaic.currentSearchManager($currentSearch);
        }
      }
      catch(err) {
        console.log('mosaicNodeSearchInit reported errors! Error: '+err);
      }
    }
  };


  Drupal.mosaic.nodeSearchManager = function($view) {
    try {
      // jQuery objects of note
      this.$view = $view;
      
      //this.events = {}; \r\n this.events['click .more-'+this.refID] = 'moreClick';
      
      // Identification and settings
      var nodeSearchManager = this;
      var SearchView = Backbone.View.extend({
        // Home
        el: this.$view,
        
        // Settings and conf
        nodeSearchManager: nodeSearchManager,
        
        // Init
        initialize: function() {
          nodeSearchManager.initializeResults();
          //_.bindAll(this, 'menuClick');
        }
      });
      // Instantiate the panel view object
      new SearchView();
    }
    catch (err) {
      console.log('nodeSearchManager errored: '+err);
    }
  };


  // Init - Hide the body field if excerpt is present et.al.
  Drupal.mosaic.nodeSearchManager.prototype.initializeResults = function() {
    try {
      $rows = this.$view.find('.views-row');
      $rows.each(function() {
        // Only there if keywords searched
        $excerpt = $(this).find('.views-field-search-api-excerpt');
        if ($.trim($excerpt.text()) != '') $(this).find('.views-field-body').hide();
      });
    }
    catch(err) {
      console.log('initializeResults errored: '+err);
    }
  };


  // Manage facet panes
  // Undo the damage done by facet api's own js... >.<
  // This would not be necc. if facet api didnt prevent addition
  // of links in an active facet link via the theme functions.
  Drupal.mosaic.facetManager = function($facetList) {
    try {
      var $active = $facetList.find('.facetapi-active');
      $active.each(function() {
        var $linkParent = $(this).parent('li');
        var $activeLink = $linkParent.find('.lnktxt');
        var $resetLink = $linkParent.find('a');
        var href = $resetLink.attr('href');
        $activeLink.html('<a href="'+href+'" title="Reset '+$activeLink.text()+' filter" rel="nofollow">'+$activeLink.text()+' (<span class="mdred">x</span>)</a>');
      });
    }
    catch (err) {
      console.log('facetManager errored: '+err);
    }
  };


  // Manage current search block
  // Correct a few items when needed
  Drupal.mosaic.currentSearchManager = function($pane) {
    try {
      // Manipulate the active facet list items to be links
      var $active = $pane.find('.current-search-item-active li');
      var $anchor = '';
      var params = Drupal.mosaic.core.getQueryParams(document.URL);
      var keys = Object.keys(params);
      var pstr = []; // new param string
      
      $active.each(function() {
        $anchor = $(this).find('a');
        
        if (!$anchor.length) { // Must be keywords here...
          for (key in keys) {
            pstr[key] = keys[key]+'='+params[keys[key]];
          }
          pstr = pstr.join('&');
          $(this).html('<a href="/search/node/all?'+pstr+'" title="Reset '+$(this).text()+' filter" rel="nofollow">(<span class="mdred">x</span>) '+$(this).text()+'</a>');
        }
        
        // A facet (with an anchor)
        else {
          var href = $(this).find('a').attr('href');
          var $lnktxt = $(this).find('.lnktxt');
          $lnktxt.html('<a href="'+href+'" title="Reset '+$lnktxt.text()+' filter" rel="nofollow">'+$lnktxt.text()+'</a>');
        }
      });
      
      // Detach the Current search item text so we can add it inside
      //  the active item item list. Makes it easier to get the items in line.
      var $searchItemText = $pane.find('.current-search-item-text').detach();
      var $activeItems    = $pane.find('.current-search-item-active .item-list'); 
      $activeItems.find('li').addClass('active-item');
      $activeItems.find('ul').append('<li class="reset"><a href="/search/node/all" class="small" rel="nofollow">Reset search</a></li>');
      $activeItems.prepend($searchItemText); // re-add the Search intro text (Search found ...)
    }
    catch (err) {
      console.log('currentSearchManager errored: '+err);
    }
  };
  
})(jQuery);
