
// This file ensures that if the community tabs are
//  shown, the Community primary link will be active

// Registers the Mosaic namespace
Drupal.coralQA = Drupal.coralQA || {};

// Document loaded!
(function($) {

  Drupal.behaviors.coralParentContentInit = {
    attach : function(context, settings) {
      try {
        var $content = $('.pane-coral-parent-content:not(".parent-content-proc")');
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
      this.$nodeTitle = this.$node.children('h2');

      this.nodeType = '';
      this.refID = '';

      // Get ready for some fun stuff!
      this.initParentContent(); // set the refID et.ct.

      this.events = {};
      this.events['click .'+this.refID] = 'parentClick';

      var coralParentContent = this;

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
  };

  Drupal.coralQA.coralParentContent.prototype.initParentContent = function() {
    try {
      // Set up a relatively safe class
      var key = 'parent-content-'+Math.floor((Math.random()*10000)+1);
      var arrow = 'arrow-down';
      var action = 'Hide';

      this.refID = key; // save the key
      this.$title.addClass(key); // add class

      var classes = this.$node.attr('class');
      classes = classes.split(' ');
      for (cls in classes) {
        if (classes[cls].match(/node-(question|answer|comment)/)) {
          this.nodeType = classes[cls].replace('node-', '');
        }
      }

      // Add decorative markup
      this.$title.append('<span class="circle"><span class="arrow '+arrow+'"></span></span>');
      this.$title.attr('title', action+' the '+this.nodeType+': '+$.trim(this.$nodeTitle.text()));
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
        this.$title.attr('title', this.$title.attr('title').replace(/^View/, 'Hide'));
      }
      else {
        this.$node.addClass('hidden').slideUp(200);
        this.$title.find('.arrow').removeClass('arrow-down');
        this.$title.attr('title', this.$title.attr('title').replace(/^Hide/, 'View'));
      }
    }
    catch (err) {
      console.log('toggleParent errored: '+err);
    }
  };

})(jQuery);
