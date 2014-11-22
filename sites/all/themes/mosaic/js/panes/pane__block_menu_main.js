
// This file controls advanced behaviors of the primary menus (Main | Service)

// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// ----------------------------------------------------------------------
// Primary menus scripts
// ----------------------------------------------------------------------
// Document loaded!
(function($) {

  Drupal.behaviors.mosaicMainMenuInit = {
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
        if (context.nodeName === '#document') { // only on doc loaded
          new Drupal.mosaic.mosaicMainMenu();
        }
      }
      catch (err) {
        console.log('mosaicMainMenuInit errored: '+err);
      }
    }
  };


  // Main menu
  Drupal.mosaic.mosaicMainMenu = function() {
    try {
      // Start up
      this.initMenu();

      // Add overlay
      this.addOverlay();

      // Add events
      this.addEvents();
    }
    catch (err) {
      console.log('mosaicMainMenu errored: '+err);
    }
  };


  // Get data
  Drupal.mosaic.mosaicMainMenu.prototype.initMenu = function() {
    try {
      var MM = this;

      this.$menu = $('header .pane-menu-main'); // Get main menu
      this.$menu.each(function() { // there should only be one... but to be sure
        var $ul = $(this).find('.pane-content > ul'); // only get the top lvl...

        if (!$(this).find('.respond').length) {       // already added?
          var msg = Drupal.t('Menu');
          $ul.before('<span class="respond"><span class="icon"></span><span class="txt">'+msg+'</span></span>');
        }

        MM.$mainMenu = $ul;
        MM.$mainIcon = $(this).find('.respond');
      });
    }
    catch (err) {
      console.log('init errored: '+err);
    }
  };


  // Add events
  Drupal.mosaic.mosaicMainMenu.prototype.addEvents = function() {
    try {
      var MM = this;

      if (this.$mainIcon.length) {

        // Set main menu click handler
        this.$mainIcon.off('click').click(function() {
          if (!MM.$mainMenu.hasClass('open')) {
            MM.showMenu(MM.$mainMenu);
          }
          else {
            MM.hideOverlay();
            MM.hideMenu(MM.$mainMenu);
          }
        });

      }


      // On re-size past tablet width, undo changes
      $(window).resize(function() {
        var winW = $(window).width();
        if (winW > 768) {
          MM.hideOverlay();
          MM.$mainMenu.attr('style', '').removeClass('open');
        }
      });


      // Overlay is not ready for 1/2 second after page is loaded
      this.$overlay.off('click').click(function() {
        MM.hideOverlay();
        MM.hideMenu(MM.$mainMenu);
      });

    }
    catch (err) {
      console.log('addEvents errored: '+err);
    }
  };


  // Show a menu
  Drupal.mosaic.mosaicMainMenu.prototype.showMenu = function($menu) {
    try {
      this.showOverlay();
      var top = '';
      var left = '';
      if (!$('header').hasClass('collapsed')) {
        top = '80px';
        left = '35px';
      }
      else {
        top = '50px';
        left = '-15px';
      }
      $menu.slideDown(0).css({'position':'absolute', 'top':top, 'left':left, 'z-index':'9'}).addClass('open');
    }
    catch (err) {
      console.log('showMenu errored: '+err);
    }
  };


    // Hide a menu
  Drupal.mosaic.mosaicMainMenu.prototype.hideMenu = function($menu) {
    try {
      this.hideOverlay();
      $menu.slideUp(0).attr('style', '').removeClass('open');
    }
    catch (err) {
      console.log('hideMenu errored: '+err);
    }
  };


  // Add an(other) overlay to page (cant use mboverlay as we get some event mixing)
  Drupal.mosaic.mosaicMainMenu.prototype.addOverlay = function() {
    try {
      var $overlay = $('.mm-over');
      if (!$overlay.length) {
        $('body').append('<div class="mm-over hidden"></div>');
        $overlay = $('body').children('.mm-over');

        var height = $(document).height();
        $overlay.css({
          'height': height+'px',
          'width': '100%',
          'background': '#000000',
          'position': 'absolute',
          'top': 0,
          'left': 0,
          'z-index': 7,
          'display': 'none'
        });
      }

      this.$overlay = $overlay; // set the overlay in the object
    }
    catch (err) {
      console.log('addOverlay errored: '+err);
    }
  };


  // Update overlay
  Drupal.mosaic.mosaicMainMenu.prototype.updateOverlay = function(display) {
    try {
      if (this.$overlay.length) {
        if (display == 'show') {
          this.$overlay.fadeTo(0, .35);
        }
        else {
          this.$overlay.fadeTo(0, 0).hide();
        }
      }
      this.$overlay.css({'height': $(document).height()+'px'});
    }
    catch (err) {
      console.log('updateOverlay errored: '+err);
    }
  };


  // Show overlay
  Drupal.mosaic.mosaicMainMenu.prototype.showOverlay = function() {
    try {
      $('.pane-main-menu').css({'z-index': '9'});
      this.updateOverlay('show');
    }
    catch (err) {
      console.log('showOverlay errored: '+err);
    }
  };


  // Hide overlay
  Drupal.mosaic.mosaicMainMenu.prototype.hideOverlay = function() {
    try {
      $('.pane-main-menu').attr('style', '');
      this.updateOverlay('hide');
    }
    catch (err) {
      console.log('hideOverlay errored: '+err);
    }
  };

})(jQuery);
