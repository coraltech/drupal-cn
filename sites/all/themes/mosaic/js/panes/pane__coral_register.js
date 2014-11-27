// This file controls advanced behaviors of the custom registration pane

// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// ----------------------------------------------------------------------
// Primary menus scripts
// ----------------------------------------------------------------------
// Document loaded!
(function($) {

  Drupal.behaviors.mosaicRegisterInit = {
    attach : function(context, settings) {
      try {
        if (context.nodeName === '#document') { // only on doc loaded
          var $regPanes = $('.pane-coral-register'); // all registration panes
          $regPanes.each(function() { // one by one they go
            new Drupal.mosaic.mosaicRegisterManager($(this));
          });
        }
      }
      catch (err) {
        console.log('mosaicRegisterInit errored: '+err);
      }
    }
  };


  // Initialize the registry pane
  Drupal.mosaic.mosaicRegisterManager = function($pane) {
    try {

      // jQuery objects of note
      this.$pane = $pane;

      // Ensure each pane is uniquely identified
      this.refID = Drupal.mosaic.core.createID(this.$pane);
      this.init();

      // Adding events here so we can control the key
      this.events = {};
      this.events['click .viewpass-'+this.refID+' .form-checkbox'] = 'viewPassClick';
      this.events['keydown .passtxt-'+this.refID+' input'] = 'passtxtKeydown';
      this.events['keydown .pass-'+this.refID+' input'] = 'passwordKeydown';
      this.events['blur .user-'+this.refID+' input'] = 'usernameSearch';
      this.events['blur .mail-'+this.refID+' input'] = 'emailValidate';
      this.events['blur .pass-'+this.refID+' input'] = 'passValidate';
      this.events['blur .passtxt-'+this.refID+' input'] = 'passValidate';
      this.events['click .submit-'+this.refID] = 'formSubmit';

      // Identification and settings
      var regManager = this;
      var RegView = Backbone.View.extend({
        // Home
        el: this.$pane,

        // Settings and conf
        regManager: regManager,

        // events
        events: regManager.events,

        // Init
        initialize: function() {
          _.bindAll(this, 'viewPassClick', 'passtxtKeydown', 'passwordKeydown', 'usernameSearch', 'emailValidate', 'passValidate', 'formSubmit');
        },

        // Password view toggle
        viewPassClick: function(ev) {
          regManager.viewPassClick();
        },

        // Password text field
        passtxtKeydown: function(ev) {
          regManager.passtxtKeydown(ev);
        },

        // Password field
        passwordKeydown: function(ev) {
          regManager.passwordKeydown(ev);
        },

        // Username field search (AJAX)
        usernameSearch: function(ev) {
          regManager.usernameSearch(ev);
        },

        // Validate the email
        emailValidate: function(ev) {
          regManager.emailValidate(ev);
        },

        // Validate the email
        passValidate: function(ev) {
          regManager.passValidate(ev);
        },

        // Submit the form
        formSubmit: function(ev) {
          regManager.formSubmit(ev);
        }
      });
      // Instantiate the panel view object
      new RegView();
    }
    catch (err) {
      console.log('mosaicRegister errored: '+err);
    }
  };


  // Set useful classes
  Drupal.mosaic.mosaicRegisterManager.prototype.init = function() {
    try {
      var append = '<div class="staticon"></div>';

      // Set up some classes - track a few objects
      this.$username  = this.$pane.find('.form-item-name').addClass('user-'+this.refID).append(append);
      this.$usermail  = this.$pane.find('.form-item-mail').addClass('mail-'+this.refID).append(append);
      this.$password  = this.$pane.find('.form-item-pass').addClass('pass-'+this.refID).append(append);
      this.$passtext  = this.$pane.find('.form-item-passtxt').addClass('passtxt-'+this.refID).append(append);
      this.$viewPass  = this.$pane.find('.form-item-viewpass').addClass('viewpass-'+this.refID);
      this.$register  = this.$pane.find('.form-submit').addClass('submit-'+this.refID);
      this.$regStatus = this.$pane.find('.reg-status');
    }
    catch (err) {
      console.log('init errored: '+err);
    }
  };


  // Submit the form if it is ready
  Drupal.mosaic.mosaicRegisterManager.prototype.formSubmit = function(ev) {
    try {
      // All fields must be ok to send
      if (!this.$username.hasClass('ok') ||
          !this.$usermail.hasClass('ok') ||
          !this.$password.hasClass('ok')) {
        ev.preventDefault(); // or we stop the sending
      }
    }
    catch (err) {
      console.log('formSubmit errored: '+err);
    }
  };


  // PreValidate the textfield input
  Drupal.mosaic.mosaicRegisterManager.prototype.preValidate = function(ev, cls) {
    try {
      if ($(ev.currentTarget).hasClass('field-default')) {
        $(ev.currentTarget).parent('.form-item').removeClass('ok').removeClass('error');
        this.resetMessages(cls);
        return false;
      }
      return true;
    }
    catch (err) {
      console.log('preValidate errored: '+err);
    }
  };


  // Validate the password
  Drupal.mosaic.mosaicRegisterManager.prototype.passValidate = function(ev) {
    try {
      // prevalidate only works for the passtext field
      if (!this.preValidate(ev, 'password')) {
        this.$password.removeClass('ok').removeClass('error');
        this.$password.find('input').val('');
        return;
      }

      // We have to check the password field manually - it has no default class
      if ($(ev.currentTarget).parent('.form-item').hasClass('form-item-pass')) {
        if (!$(ev.currentTarget).val().length) {
          this.$password.removeClass('ok').removeClass('error');
          RM = this;
          setTimeout (function() {
            RM.$passtext.find('.form-text').trigger('focusout');
          }, 250);
          return;
        }
      }

      var regex = /^[a-zA-Z0-9!@#$%^&*\_\-]{7,20}$/;
      if (!regex.test($(ev.currentTarget).val())) { // doesn't pass
        var objs = [this.$password.find('input'), this.$passtext.find('input')];
        this.requestFailure('<div class="password">Please enter a valid password.</div>', 'password', objs);
      }
      else {
        // these two are kept in sync - Cannot accept default values
        if (this.$passtext.find('.form-text').hasClass('field-default')) {
          this.$password.removeClass('ok').removeClass('error').val('');
        }
        else {
          this.requestAccepted(this.$password.find('input'), 'password');
          this.requestAccepted(this.$passtext.find('input'), 'password');
        }
      }
    }
    catch (err) {
      console.log('passValidate errored: '+err);
    }
  };


  // Validate the email address before sending it in.
  Drupal.mosaic.mosaicRegisterManager.prototype.emailValidate = function(ev) {
    try {
      if (!this.preValidate(ev, 'email')) return;

      var email = $(ev.currentTarget).val();
      var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
      if (!regex.test(email)) {
        this.requestFailure('<div class="email">Please enter a valid email.</div>','email', $(ev.currentTarget));
      }
      else {
        this.requestAccepted($(ev.currentTarget), 'email');
      }
    }
    catch (err) {
      console.log('emailValidate errored: '+err);
    }
  };


  // Do a lookup to see if the name is taken
  Drupal.mosaic.mosaicRegisterManager.prototype.usernameSearch = function(ev) {
    try {
      if (!this.preValidate(ev, 'username')) return;

      var RM = this;
      var request = $(ev.currentTarget).val();
      if (request.length < 3) {
        this.requestFailure('<div class="username">Username must be 3 charcters or more!</div>', 'username', $(ev.currentTarget));
      }
      else {
        $.ajax({
          url:'/services/namesearch/'+request,
          dataType: 'json',
          success: function(data, status, jqXHR) {
            if (data.accepted != true) {
              RM.requestFailure('<div class="username">Username is already taken.</div>', 'username',$(ev.currentTarget));
            }
            else {
              RM.requestAccepted($(ev.currentTarget), 'username');
            }
          },
          error: function() {
            RM.requestFailure('<div class="username">Oops! Something went wrong here.</div>', 'username',$(ev.currentTarget));
          }
        });
      }
    }
    catch (err) {
      console.log('usernameSearch errored: '+err);
    }
  };


  // Manage status after acceptance on the field
  Drupal.mosaic.mosaicRegisterManager.prototype.requestAccepted = function($obj, cls) {
    try {
      $obj.parent('.form-item').removeClass('error').addClass('ok');
      this.resetMessages(cls);
    }
    catch (err) {
      console.log('requestAccepted errored: '+err);
    }
  };


  // Reset a class of messages
  Drupal.mosaic.mosaicRegisterManager.prototype.resetMessages = function(cls) {
    try {
      this.$regStatus.find('.'+cls).remove();
      if (!this.$regStatus.find('div').length) { // any more errors?
        this.$regStatus.removeClass('error').addClass('hide');
      }
    }
    catch (err) {
      console.log('resetMessages errored: '+err);
    }
  };


  // Manage status after declining field input
  Drupal.mosaic.mosaicRegisterManager.prototype.requestFailure = function(text, cls, objs) {
    try {
      if (objs.length === 1) { // coming in as a jQuery object
        objs.parent('.form-item').addClass('error').removeClass('ok');
      }
      else { // array of jQ objects
        $.each(objs, function(i) {
          $(this).parent('.form-item').addClass('error').removeClass('ok');
        });
      }
      this.$regStatus.find('.'+cls).remove(); // eliminate old messages
      this.$regStatus.addClass('error').removeClass('hide').prepend(text);
      this.rotate();
    }
    catch (err) {
      console.log('requestFailure errored: '+err);
    }
  };


  // Rotate status messages
  Drupal.mosaic.mosaicRegisterManager.prototype.rotate = function() {
    try {
      this.$msgs = this.$regStatus.find('div');
      this.msgCount = this.$msgs.length;
      this.rotateInterval = clearInterval(this.rotateInterval);

      if (this.msgCount > 1) { // start rotating
        var $start = this.$regStatus.find('.current');
        if (!$start.length) {
          $start = this.$msgs.eq(0).addClass('current');
        }

        // Hide all not current
        this.$msgs.each(function() {
          if (!$(this).hasClass('current')) {
            $(this).hide();
          }
        });

        // Rotations!
        var RM = this;
        this.$regStatus.addClass('rotating');
        this.rotateInterval = setInterval(function() {
          // Clear interval if we now have less than 2
          if (RM.$regStatus.find('div').length < 2) {
            return clearInterval(RM.rotateInterval);
          }

          // Animate the messages
          var $cur = RM.$regStatus.find('.current');
          var $nxt = $cur.next();
          $cur.fadeOut(750).removeClass('current');
          if (!$nxt.length) {
            $nxt = RM.$regStatus.find('div').eq(0);
          }
          $nxt.fadeIn(750).addClass('current');
        }, 2500);
      }
    }
    catch (err) {
      console.log('rotate errored: '+err);
    }
  };


  // Handle clicks to the viewPassword checkbox
  Drupal.mosaic.mosaicRegisterManager.prototype.viewPassClick = function(ev) {
    try {
      // If checked, the user wants to view the password
      if (!this.$viewPass.find('input').prop('checked')) {
        this.$password.show();
        this.$passtext.hide();
      }
      else { // they don't
        this.$password.hide();
        this.$passtext.show();
      }
    }
    catch (err) {
      console.log('viewPassClick errored: '+err);
    }
  };


  // Sync the textbased pass field with the real password field
  Drupal.mosaic.mosaicRegisterManager.prototype.passtxtKeydown = function(ev) {
    try {
      var RM = this;

      // We need to set a timeout to ensure the browser has enough time to
      //  register the change. Not using a timeout results in being 1 char behind.
      setTimeout(function() {
        if (!RM.$passtext.find('.form-text').hasClass('field-default')) {
          RM.$password.find('.form-text').val(RM.$passtext.find('.form-text').val());
        }
      }, 250);
    }
    catch (err) {
      console.log('passtxtKeydown errored: '+err);
    }
  };


  // Sync the the passtxt field with the reg password field
  Drupal.mosaic.mosaicRegisterManager.prototype.passwordKeydown = function(ev) {
    try {
      var RM = this;

      // We need to set a timeout to ensure the browser has enough time to
      //  register the change. Not using a timeout results in being 1 char behind.
      setTimeout(function() {
        RM.$passtext.find('.form-text').val(RM.$password.find('.form-text').val()).removeClass('field-default');
      }, 250);
    }
    catch (err) {
      console.log('passtxtKeydown errored: '+err);
    }
  };

})(jQuery);