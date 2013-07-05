// Registers the Mosaic namespace
Drupal.field_defaults = Drupal.field_defaults || {};

/**
 *
 * Mosaic forms will check to see if there are
 *  settings for any form's textfield defaults.
 *  Should only recieve requests for items that
 *  implement it. Only implement on pages where
 *  needed!
 *
 * These defaults are added via modules and 
 *  themes via whatever hooks they deem fit.
 *
 * Add new defaults to: 
 * 
 * Drupal.settings.mosaic.fieldDefaults:
 * 
 *  - fieldDefaults['.selector']['default'] = 'Default text';
 *  
*/
// Document loaded!
(function($) {
  
  Drupal.behaviors.fieldDefaultsTextfieldInit = {    
    attach : function(context, settings) {
      try { // use try to ensure that if this breaks/fails, it won't break other stuff.
        if (Drupal.settings.field_defaults.textfieldDefaults) {
          var textfieldDefaults = Drupal.settings.field_defaults.textfieldDefaults;
        
          for (selector in textfieldDefaults) {      
            var $formElement = $(selector);
            //console.log(selector);
            for (var index = 0; index < $formElement.length; index++) {
              new Drupal.field_defaults.textfieldDefault($formElement[index], textfieldDefaults[selector]);
            }
          }
        }
      }
      catch (err) {
        console.log('fieldDefaultsTextfieldInit() reported errors! Error: '+err);
      }
    }
  };

  // Mosaic textfieldDefault takes one textfield and ensures it is
  //  set as it should be according to the specs in textfield_defaults.inc
  // @TODO: make this able to handle Form API defaults as well as passed in defaults.
  Drupal.field_defaults.textfieldDefault = function(formElement, fieldDefaults) {
    this.$element = $(formElement);
    var textfieldDefault = this;
    
    var FieldList = Backbone.View.extend({
      
      // Home
      el: this.$element,
      
      // Events
      events: {
        'focusin': 'focusField',
        'focusout': 'blurField'
      },
      
      // Init
      initialize: function() { 
        textfieldDefault.process(fieldDefaults, 'blur', true);
        _.bindAll(this, 'blurField', 'focusField'); 
      },
      
      // Updates
      blurField:  function() { textfieldDefault.process(fieldDefaults, 'blur' ); },
      focusField: function() { textfieldDefault.process(fieldDefaults, 'focus'); }
    });
    
    // Kick start!
    new FieldList();
  };
  
  //---
  
  // Process each textfield
  Drupal.field_defaults.textfieldDefault.prototype.process = function(settings, op, init) {
    
    // Runtime baby!
    init = init || false;
    var id   = this.$element.attr('id');
    var $elm = this.$element;
    var val  = $elm.val();
    
    // Field is blurring  
    if (op == 'blur') {
      if (val == settings['default']) { // value is already ok
        $elm.addClass('field-default'); // add the default class
      }
      if (val != settings['default']) { // value is not eq to settings
        if (init && $elm.val() == '') { // do we override? yes on initialization of the page
          // @TODO: Check and see if what IS there is the default
          $elm.val(settings['default']).addClass('field-default');
        }
        else {
          if (val == '') { // they are leaving it blank
            $elm.val(settings['default']).addClass('field-default');
          }
        }
      }
    }
    
    // User is focusing
    if (op == 'focus') { 
      if (val == settings['default']) { // we only work on it if its in a default state
        $elm.val('').removeClass('field-default');
      }      
    }
  }
})(jQuery);

