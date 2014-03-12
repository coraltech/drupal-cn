
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
      
      try { // Use try to prevent systemic failure
        // gather slideshows
        //console.log($('.views_slideshow_cycle_main').length); = 2
        //if ($('.views_slideshow_cycle_main').length > 0) {
          //$slideshows = $('.views_slideshow_cycle_main');
          //$slideshows.each(function(i) {
            //$container = $(this).parent();
            //console.log($container);
            //new Drupal.mosaic.slideshow($(this), $container);
          //});
        //}
      }
      catch(err) {
        console.log('mosaicSlideshowInit reported errors! Error: '+err);
      }
    }
  };

  // Mosaic slideshow
  Drupal.mosaic.slideshow = function($slideshow, $container) {
    
    // jQuery objects of note
    this.$slideshow = $slideshow; // the slideshow
    this.$container = $container; // slideshow container
    
    // Identification and settings
    this.id         = '#'+$slideshow.attr('id'); //'#'+this.$slideshow.attr('id');
    this.settings   = Drupal.settings.viewsSlideshowCycle[this.id];
        
    //console.log(this.settings);
    
    // This slideshow instance - save for later
    var slideshow     = this;
    var slideshowList = Backbone.View.extend({
      
      // Home
      el: this.$container,
      
      // Slideshow settings
      slideshow:  slideshow,
      settings:   this.settings,
      $slideshow: this.$slideshow,
      $container: this.$container,

      // Events
      events: {
        'click span.pip': 'clickPip',  // click on a pip
        'hover span.pip': 'hoverPip',  // mouseover a pip
        'click span.nav': 'clickNav'   // click on prev or next
      },
      
      // Init
      initialize: function() {
        slideshow.startup(this.$container);     // Do a little init work
        slideshow.addPips(this.settings, this.$container); // Set up the nav pips
        slideshow.addNextPrev(this.settings, this.$container); // Add next previous buttons
        slideshow.updatePips(this.settings, this.$container, this.slideshow);
        _.bindAll(this, 'clickPip', 'hoverPip', 'clickNav');   // Bind the actions         
      },
      
      // Pip click event
      clickPip:  function(ev) {
        var slideID = $(ev.target).attr('id');
        slideID = slideID.replace('pip-', ''); // slide number 1 - N
        
        // Slideshow ids and settings
        var settings = Drupal.settings.viewsSlideshowCycle[slideshow.id]; // slideshow settings
        
        // Set settings for new action!
        settings.slideNum = Number(slideID);
        settings.slideshowID = settings.vss_id;
        
        // Goto slide
        Drupal.viewsSlideshowCycle.goToSlide(settings); 
      },
      
      clickNav: function(ev) {
        var settings = Drupal.settings.viewsSlideshowCycle[slideshow.id]; // slideshow settings
        settings.slideshowID = settings.vss_id;
        if ($(ev.currentTarget).hasClass('nav-next')) {
          Drupal.viewsSlideshowCycle.nextSlide(settings);
        }
        else {
          Drupal.viewsSlideshowCycle.previousSlide(settings);
        }
      },
      
      // Hover event
      hoverPip: function(ev) {
        if (ev.type == 'mouseenter') $(ev.target).addClass('hover');
        if (ev.type == 'mouseleave') $(ev.target).removeClass('hover');
      },
    });
    
    // Kick start!
    new slideshowList();
  };
  
  //---
  
  // Kickoff the slideshow
  Drupal.mosaic.slideshow.prototype.startup = function(container) {
    // We need to ensure the right size for all img containers
    var $imgs = $(container).find('img.slide-img');
    var maxW  = 0;
    $imgs.each(function() { if ($(this).width() > maxW) maxW = $(this).width(); });
    $imgs.each(function() { $(this).parent().width(maxW); });
  }
  
  // Add the clickable pips (UI)
  Drupal.mosaic.slideshow.prototype.addNextPrev = function(settings, $container) {
    if (settings.totalImages > 1) {
      var nav = '<div class="nav-cont">'; // open the container
      nav += '<span class="nav nav-prev"></span>';
      nav += '<span class="nav nav-next"></span>';
      $container.append(nav);
    }
  }
  
  // Add the clickable pips (UI)
  Drupal.mosaic.slideshow.prototype.addPips = function(settings, $container) {
    if (settings.totalImages > 1) {
      var pips = '<div class="pip-cont">'; // open the container
      for (var i = 0; i < settings.totalImages; i++) {
        pips += '<span class="pip" id="pip-'+i+'"></span>';
      }
      $container.append(pips);
    }
  }
  
  // Update pips based on the current slide
  Drupal.mosaic.slideshow.prototype.updatePips = function(settings, $container, slideshow) {

    var $pips = $container.find('.pip'); // Round up the pips
    var $counter = $container.find('.views-slideshow-slide-counter .num'); // Get the current number counter provided by views slideshow -_-
    $container.find('.views-slideshow-slide-counter').addClass('hide');    // Hide counters
    
    // Getting the current slide #
    var currentSlide = Number($counter.text()) - 1;
    if (currentSlide >= 0 && currentSlide != NaN) {
      
      // First call
      slideshow.syncPips($pips, $counter);
      
      // start the timeout which starts the interval
      setTimeout(function() {
        setInterval(function() { 
          slideshow.syncPips($pips, $counter); // Check state 
        }, 500); 
      }, 100);
    }
  }
  
  // Syncronizes pip classes with the built-in counter
  Drupal.mosaic.slideshow.prototype.syncPips = function ($pips, $counter) {
    // Reget the current slide
    curr = Number($counter.text()) - 1;

    // set the active pip
    if (!$pips.eq(curr).hasClass('active-pip')) { 
      $pips.each(function() { $(this).removeClass('active-pip'); });
      $pips.eq(curr).addClass('active-pip');
    }
  }
  
})(jQuery); 
