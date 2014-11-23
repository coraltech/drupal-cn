// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};


// ----------------------------------------------------------------------
// Coral user script. Controls header user pane interactions - the menu
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicUserInit = {
    attach : function(context, settings) {
      try {
        if (context.nodeName === '#document') {
          new Drupal.mosaic.mosaicUser();
        }
      }
      catch(err) {
        console.log('mosaicUserInit errored: '+err);
      }
    }
  };


  // Main starter
  Drupal.mosaic.mosaicUser = function() {
    try {
      this.initUser();
      this.addOverlay();
      this.addEvents();
    }
    catch (err) {
      console.log('mosaicUser errored: '+err);
    }
  };


  Drupal.mosaic.mosaicUser.prototype.addEvents = function() {
    try {
      var MU = this;
      this.$btn.off('click').click(function(ev) {
        if (!MU.$menu.hasClass('open')) {
          MU.showMenu();
        }
        else {
          MU.hideMenu();
        }
      });


      // Setup an overlay click event
      this.$overlay.off('click').click(function() {
        MU.hideOverlay();
        MU.hideMenu();
      });
    }
    catch (err) {
      console.log('addEvents errored: '+err);
    }
  };


  // Show user menu on user button click
  Drupal.mosaic.mosaicUser.prototype.showMenu = function() {
    try {
      this.showOverlay();

      // First slide it down
      this.$menu.slideDown(0).css({'position':'absolute', 'z-index':'9'}).addClass('open');
    }
    catch (err) {
      console.log('showMenu errored: '+err);
    }
  };


  // Hide the user menu
  Drupal.mosaic.mosaicUser.prototype.hideMenu = function() {
    try {
      this.hideOverlay();
      this.$menu.slideUp(0).attr('style', '').removeClass('open');
    }
    catch (err) {
      console.log('showMenu errored: '+err);
    }
  };


  // Gather info from the pane
  Drupal.mosaic.mosaicUser.prototype.initUser = function() {
    try {
      this.$pane = $('header .pane-coral-user');
      this.$menu = this.$pane.find('.item-list ul');
      this.$btn  = this.$pane.find('.resp > span');
    }
    catch (err) {
      console.log('initUser errored: '+err);
    }
  };


  // Add an(other) overlay to page (cant use mboverlay as we get nasty event mixing)
  Drupal.mosaic.mosaicUser.prototype.addOverlay = function() {
    try {
      var $overlay = $('.mu-over');
      if (!$overlay.length) {
        $('body').append('<div class="mu-over hidden"></div>');
        $overlay = $('body').children('.mu-over');

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
  Drupal.mosaic.mosaicUser.prototype.updateOverlay = function(display) {
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
  Drupal.mosaic.mosaicUser.prototype.showOverlay = function() {
    try {
      $('.pane-coral-user').css({'z-index': '9'});
      this.updateOverlay('show');
    }
    catch (err) {
      console.log('showOverlay errored: '+err);
    }
  };


  // Hide overlay
  Drupal.mosaic.mosaicUser.prototype.hideOverlay = function() {
    try {
      $('.pane-coral-user').attr('style', '');
      this.updateOverlay('hide');
    }
    catch (err) {
      console.log('hideOverlay errored: '+err);
    }
  };

})(jQuery);
