// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};


// ----------------------------------------------------------------------
// Handles a few js changes that happen on the front page
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicCNFrontInit = {
    attach : function(context, settings) {
      try {
        if (context.nodeName === '#document') {
          new Drupal.mosaic.mosaicCNFront();
        }
      }
      catch(err) {
        console.log('mosaicHAInit errored: '+err);
      }
    }
  };


  // Set it off!
  Drupal.mosaic.mosaicCNFront = function() {
    try {
      this.init();   // gather data
      this.prime();  // first run
      this.events(); // event handlers
    }
    catch (err) {
      console.log('mosaicCNFront errored: '+err);
    }
  };


  // Prepare the data
  Drupal.mosaic.mosaicCNFront.prototype.init = function() {
    try {
      this.speed     = 500;
      this.showText  = Drupal.t("Sign up");
      this.hideText  = Drupal.t("Hide form");
      this.msgText   = Drupal.t("Join the CORL community!");

      this.$leader   = $('.leader');
      this.$register = $('.leader .pane-coral-register');

      this.$leader.append('<div class="resp-msg"><span class="btn">'+this.showText+'</span><span class="msg">'+this.msgText+'</span></div>');
      this.$respMsgBtn  = this.$leader.find('.resp-msg .btn');
    }
    catch (err) {
      console.log('init errored: '+err);
    }
  };


  // Run through things the first time.
  Drupal.mosaic.mosaicCNFront.prototype.prime = function() {
    try {
      this.update();
    }
    catch (err) {
      console.log('prime errored: '+err);
    }
  };


  // Set events
  Drupal.mosaic.mosaicCNFront.prototype.events = function() {
    try {
      var CNF = this;
      $(window).resize(function() {
        CNF.update();
      });

      this.$respMsgBtn.off('click').click(function() {
        if ($(this).text() == CNF.showText) {
          CNF.$register.slideDown(CNF.speed);
          CNF.$respMsgBtn.text(CNF.hideText);
        }
        else {
          CNF.$register.slideUp(CNF.speed);
          CNF.$respMsgBtn.text(CNF.showText);
        }
      });

    }
    catch (err) {
      console.log('events errored: '+err);
    }
  };


  // Update the components on width changes
  Drupal.mosaic.mosaicCNFront.prototype.update = function() {
    try {
      this.winW = $(window).width();
      if (this.winW < 675) { // hide mode for upper registration pane
        this.$leader.addClass('cnfmin');
        this.$register.slideUp(this.speed);
        this.$respMsgBtn.text(this.showText).parent('.resp-msg').slideDown(this.speed / 2);
      }
      else {
        this.$leader.removeClass('cnfmin');
        this.$register.slideDown(this.speed);
        this.$respMsgBtn.parent('.resp-msg').slideUp(this.speed);
      }
    }
    catch (err) {
      console.log('update errored: '+err);
    }
  };

})(jQuery);
