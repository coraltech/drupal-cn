
// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

/**
 *
 *   
 */
// Document loaded!
(function($) {
  
  Drupal.behaviors.mosaicSlideshowInit = {    
    attach : function(context, settings) {
      // gather slideshows
      if ($('.views_slideshow_cycle_main').length > 0) {
        $slideshows = $('.views_slideshow_cycle_main');
        $slideshows.each(function(i) {
          $container = $(this).parent();
          new Drupal.mosaic.slideshow($(this), $container);
        });
      }
    }
  };

  // Mosaic slideshow
  Drupal.mosaic.slideshow = function($slideshow, $container) {
    
    // jQuery objects of note
    this.$slideshow = $slideshow; // the slideshow
    this.$container = $container; // slideshow container
    this.$imgs      = $slideshow.find('img');
    
    // Identification and settings
    this.id         = '#'+this.$slideshow.attr('id');
    this.settings   = Drupal.settings.viewsSlideshowCycle[this.id];
        
    //console.log(this.settings);
    
    // This slideshow instance - save for later
    var slideshow     = this;
    var slideshowList = Backbone.View.extend({
      
      // Home
      el: this.$container,
      
      // Slideshow settings
      settings: this.settings,
      $slideshow: this.$slideshow,
      $container: this.$container,

      // Events
      events: {
        'click span.pip'     : 'clickPip',  // click on a pip
        'hover span.pip': 'hoverPip'   // mouseover a pip
      },
      
      // Init
      initialize: function() {
        slideshow.startup();     // Do a little init work
        slideshow.addPips(this.settings, this.$container); // Set up the nav pips
        slideshow.updatePips(this.settings, this.$container, this.$slideshow);
        _.bindAll(this, 'clickPip', 'hoverPip');           // Bind the actions         
      },
      
      // Pip click event
      clickPip:  function(ev) {
        var slideID = $(ev.target).attr('id');
        slideID = slideID.replace('pip-', ''); // slide number 1 - N
        
        // Slideshow ids and settings
        var fullID = slideshow.id;                              // full slideshow id
        var settings = Drupal.settings.viewsSlideshowCycle[fullID]; // slideshow settings
        
        // Set settings for new action!
        settings.slideNum = Number(slideID);
        settings.slideshowID = settings.vss_id;
        
        // Goto slide
        Drupal.viewsSlideshowCycle.goToSlide(settings); 
      },
      
      // Hover event
      hoverPip: function(ev) {
        console.log(ev.type);
        if (ev.type == 'mouseenter') $(ev.target).addClass('hover');
        if (ev.type == 'mouseleave') $(ev.target).removeClass('hover');
      },
    });
    
    // Kick start!
    new slideshowList();
  };
  
  //---
  
  // Kickoff the slideshow
  Drupal.mosaic.slideshow.prototype.startup = function() {
    // We need to ensure the right size for all img containers
    var $imgs = this.$slideshow.find('img');
    var maxW  = 0;
    $imgs.each(function() { if ($(this).width() > maxW) maxW = $(this).width(); });
    $imgs.each(function() { $(this).parent().width(maxW); });
  }
  
  // Add the clickable pips (UI)
  Drupal.mosaic.slideshow.prototype.addPips = function(settings, $container) {
    if (settings.totalImages > 1) {
      var pips = '<div class="pip-cont">'; // open the container
      for (var i = 0; i < settings.totalImages; i++) {
        pips += '<span class="pip" id="pip-'+i+'">o</span>';
      }
      $container.append(pips);
    }
  }
  
  // Update pips based on the current slide
  Drupal.mosaic.slideshow.prototype.updatePips = function(settings, $container, $slideshow) {
    //this.currentSlide = 
    this.num = 0;
    //console.log(this.num < 3);
    console.log(settings);
    console.log($container);
    console.log($slideshow);

    var check = setInterval(function() { //setInterval  
      //if (this.num < 3) {
        //console.log(settings);
      //}
    }, 10000);  
  }
  
  
})(jQuery); 
