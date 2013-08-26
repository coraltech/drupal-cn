
// This file ensures that if the community tabs are
//  shown, the Community primary link will be active

// Registers the Mosaic namespace
Drupal.coralQA = Drupal.coralQA || {};

// Document loaded!
(function($) {
  
  Drupal.behaviors.coralParentContentInit = {
    attach : function(context, settings) {
      try {
        $content = $('.pane-coral-parent-content:not(".parent-content-proc")');
        if ($content.length) {
          new Drupal.coralQA.coralParentContent($content);
        }
      }
      catch (err) {
        console.log('coralParentContentInit() reported errors. Error: '+err);
      }
    }
  };
  

  // Gather the featured users into the pane.  
  Drupal.coralQA.coralParentContent = function($content) {
    try {
      $content.addClass('parent-content-proc'); // don't process twice
      
      this.$content = $content;
      this.$title = $content.find('.pane-title').eq(0);
      this.$node = $content.find('.node').eq(0);
      
      this.refID = '';
      
      // Get ready for some fun stuff!
      this.initParentContent(); // set the refID et.ct.
      
      this.events = {};
      this.events['click .'+this.refID] = 'parentClick';
      
      coralParentContent = this;
      
      var ParentContentView = Backbone.View.extend({
        // Home
        el: this.$content,
        
        // Settings and conf
        coralParentContent: coralParentContent,
        
        // events
        events: coralParentContent.events, // keyed events
             
        // Init
        initialize: function() {
          _.bindAll(this, 'parentClick');
        },
       
        // callbacks
        parentClick: function(ev) {
          ev.preventDefault();
          coralParentContent.toggleParent(ev);
        }
      });
      new ParentContentView();

    }
    catch(err) {
      console.log('coralFeaturedUsers errored: '+err);
    }
  }
  
  Drupal.coralQA.coralParentContent.prototype.initParentContent = function() {
    try {
      // Set up a relatively safe class
      var key = 'parent-content-'+Math.floor((Math.random()*10000)+1);
      this.refID = key; // save the key
      this.$title.addClass(key); // add class
      
      // Add decorative markup
      this.$title.append('<span class="circle"><span class="arrow"></span></span>');
      
      // Hide the node to start with
      this.$node.addClass('hidden').hide()
    }
    catch (err) {
      console.log('initParentContent errored: '+err);
    }
  };


  // Show the parent content item (or hide it)
  Drupal.coralQA.coralParentContent.prototype.toggleParent = function() {
    try {
      if (this.$node.hasClass('hidden')) {
        this.$node.removeClass('hidden').slideDown(200);
        this.$title.find('.arrow').addClass('arrow-down');
      }
      else {
        this.$node.addClass('hidden').slideUp(200);
        this.$title.find('.arrow').removeClass('arrow-down');
      }
    }
    catch (err) {
      console.log('toggleParent errored: '+err);
    }
  };
  
})(jQuery);
