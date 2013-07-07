// Registers the Mosaic namespace

// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// @TODO: Turn this into a good prototype!
// ----------------------------------------------------------------------
// Magnificent popup instantiation
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicPopularTagsInit = {    
    attach : function(context, settings) {
      
      try { // Use try to prevent systemic failure
        $tagsPane = $('.pane-tags-popular-popular-tags');
        if ($tagsPane.length > 0) {
          $tagsPane.each(function() {
            new Drupal.mosaic.popularTags($(this));  
          });
        }
      }
      catch(err) {
        console.log('mosaicPopularTagsInit reported errors! Error: '+err);
      }
    }
  };
  
  Drupal.mosaic.popularTags = function($tagsPane) {
    //console.log($tagsPane);
    
    // jQuery objects of note
    this.$tagsPane = $tagsPane; // the tags pane
    
    // Identification and settings
    var popularTags = this;
    var TagsView = Backbone.View.extend({
      // Home
      el: this.$tagsPane,
      
      // Settings and conf
      popularTags: popularTags,
      
      // Events
      events: {
        'click a.more': 'moreClick'
      },
      
      // Init the manager
      initialize: function() {
        popularTags.init(this.el);
        _.bindAll(this, 'moreClick');
      },
      
      moreClick: function(ev) {
        popularTags.moreClick(this.el, ev);
      },
      
    });
    
    new TagsView();
  };
  
  // Initialize the pane
  Drupal.mosaic.popularTags.prototype.init = function(tags) {
    $tags = $(tags); // jQ tags obj
    $tags.append('<a href="#" class="more">more</a>'); // add the more link
    $pager = $tags.find('.pager').addClass('hide'); // remove the reg pager
  };
  
  // 
  Drupal.mosaic.popularTags.prototype.moreClick = function($tags, ev) {
    // Get rid of the separator -_- 
    //console.log($tags);
    console.log(Drupal.Backbone.Collections.NodeView());
    //var viewCollection = new Drupal.Backbone.Collections.NodeView();
    //viewCollection.viewName = 'tags_popular';
    //viewCollection.fetch({success: function() {
      //console.log('fetched');
    //}});
    
    
    ev.preventDefault();
  };
  
})(jQuery);