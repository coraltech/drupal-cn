// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};


// ----------------------------------------------------------------------
// Hybrid auth scripts;
//  Only affects the auth in the header at the moment.
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicHAInit = {
    attach : function(context, settings) {
      try {
        if (context.nodeName === '#document') {
          new Drupal.mosaic.hybridAuth();
        }
      }
      catch(err) {
        console.log('mosaicHAInit errored: '+err);
      }
    }
  };


  // Main starter
  Drupal.mosaic.hybridAuth = function() {
    try {
      this.init(); // gather data
      this.orientItems(); // first update

      var HA = this;

      // Resize event
      $(window).resize(function() {
        HA.orientItems();
        HA.cleanUp();
      });

      // Scroll event - mosaicHeader.js can change things for us.
      $(window).scroll(function() {
        HA.stateRespond();
        HA.cleanUp();
      });

      // Simple click event handling
      this.$respLink.off('click').click(function(ev) {
        HA.respLinkClick(ev);
      });

    }
    catch (err) {
      console.log('hybridAuth errored: '+err);
    }

  };


  // Perform minor cleanup ops
  Drupal.mosaic.hybridAuth.prototype.cleanUp = function() {
    try {
      if (this.$haPaneContent.children('.close').length) {
        this.$haPaneContent.children('.close').remove();
      }
    }
    catch (err) {
      console.log('cleanUp errored: '+err);
    }
  };


  // Show detail
  Drupal.mosaic.hybridAuth.prototype.show = function() {
    try {
      this.$haPaneContent.removeClass('hide');
      this.initClose(); // initialize the close btn
    }
    catch (err) {
      console.log('close errored: '+err);
    }
  };


  // Close block
  Drupal.mosaic.hybridAuth.prototype.close = function() {
    try {
      this.$close.remove();
      this.$haPaneContent.addClass('hide');
    }
    catch (err) {
      console.log('close errored: '+err);
    }
  };


  // Init the close button
  Drupal.mosaic.hybridAuth.prototype.initClose = function() {
    try {
      this.$haPaneContent.prepend('<span class="close">X</span>');
      this.$close = this.$haPaneContent.children('.close');

      var HA = this;
      this.$close.click(function() {
        HA.close();
      });
    }
    catch (err) {
      console.log('initClose errored: '+err);
    }
  };


  // set up the header hybridauth block
  Drupal.mosaic.hybridAuth.prototype.init = function() {
    try {
      // header nested HA pane
      this.$haPane = $('header .pane-hybridauth-hybridauth');
      this.$haPaneContent = this.$haPane.children('.pane-content');

      // Add login / reg links in the header
      this.addLinks();
    }
    catch (err) {
      console.log('init errored: '+err);
    }
  };


  // Orient items to account for changing screen dimensions
  Drupal.mosaic.hybridAuth.prototype.orientItems = function() {
    try {
      this.winWidth = $(window).width();

      if (this.winWidth < 950) { // too narrow to show full content
        this.miniMode(1);

        // Things are getting extremely narrow
        if (this.winWidth < 668) {
          this.miniMode(2);
        }
      }
      else {
        if (!$('header').hasClass('collapsed')) {
          this.miniMode(0);
        }
      }
    }
    catch (err) {
      console.log('orientItems errored: '+err);
    }
  };


  // Respond to changes in the header state
  Drupal.mosaic.hybridAuth.prototype.stateRespond = function() {
    try {
      Drupal.mosaic.core.objects.mosaicHeader = Drupal.mosaic.core.objects.mosaicHeader || 'open';
      if (Drupal.mosaic.core.objects.mosaicHeader.state === 'collapsed') {
        if (this.winWidth < 668) {
          this.miniMode(2);
        }
        else {
          this.miniMode(1);
        }
      }
      else {
        if (this.winWidth < 950) { // too narrow to show full content
          this.miniMode(1);

          // Things are getting extremely narrow
          if (this.winWidth < 668) {
            this.miniMode(2);
          }
        }
        else {
          this.miniMode(0);
        }
      }
    }
    catch (err) {
      console.log('stateRespond errored: '+err);
    }
  };


  // Start/end the minimode
  Drupal.mosaic.hybridAuth.prototype.miniMode = function(level) {
    try {
      if (level === 1) { // first stage of minification
        this.$haPane.addClass('resp');
        this.$haPaneContent.removeClass('center').addClass('hide');
        this.$respLink.removeClass('hide').text('Login / Register').removeClass('center');
      }
      else if (level === 2) { // center the responsive link
        this.$haPaneContent.addClass('center');
        this.$respLink.text('Login').addClass('center');
      }
      else { // clear mini formatting
        this.$haPane.removeClass('resp');
        this.$haPaneContent.removeClass('hide');
        this.$respLink.addClass('hide');
      }
    }
    catch (err) {
      console.log('enableMiniMode errored: '+err);
    }
  };


  // Add login links
  Drupal.mosaic.hybridAuth.prototype.addLinks = function() {
    try {
      // RespLink is a link that appears in screens too narrow to
      //  show full hybridauth info.
      var respLink = '<a href="#" class="resplink hide">Login / Register</a>';

      // Login and register are prepended too.
      var loginLink = '<a href="/user/login">Login</a>';
      var registerLink = '<a href="/user/register">Register</a>';
      var linkList = '<ul class="links inline"><li>'+loginLink+' <span class="ltgray">/</span> '+registerLink+'</li></ul>';

      this.$haPane.prepend(respLink);
      this.$haPaneContent.prepend(linkList);
      this.$respLink = this.$haPane.children('.resplink'); // save this link
    }
    catch(err) {
      console.log('addLinks errored: '+err);
    }
  };


  // Act on responsive link click event
  Drupal.mosaic.hybridAuth.prototype.respLinkClick = function(ev) {
    try {
      ev.preventDefault();
      if (this.$haPaneContent.hasClass('hide')) {
        this.show();
      }
      else {
        this.close();
      }
    }
    catch (err) {
      console.log('respLinkClick errored: '+err);
    }
  };

})(jQuery);