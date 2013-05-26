// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// ---
//
// Mosaic forms will check to see if there are
//  settings for any form's textfield defaults.
//  Should only recieve requests for items that
//  implement it. Only implement on pages where
//  needed!
//
// These defaults are added via modules and 
//  themes via whatever hooks they deem fit.
//
// Add new defaults to: Drupal.mosaic.forms.defaults
//  key => value
//  selector ('#form_id .form-text') => default  <-- real
//  
// ---

// Document loaded!
(function($) {
  
  Drupal.behaviors.mosaicFormsInit = {    
    attach : function(context, settings) {
      //if (Drupal.settings.mosaic.fieldDefaults) {
        var fieldDefaults = {};//Drupal.settings.mosaic.fieldDefaults;
        
        fieldDefaults['.form-text'] = {};
        fieldDefaults['.form-text']['default'] = 'Search';
        
        for (selector in fieldDefaults) {      
          var $formElement = $(selector);
        
          for (var index = 0; index < $formElement.length; index++) {
            new Drupal.mosaic.forms($formElement[index], fieldDefaults[selector]);
          }
        }
      //}
    }
  };

  // Mosaic process
  
  Drupal.mosaic.forms = function(formElement, fieldDefaults) {
    //console.log(fieldDefaults);
        
    this.$element = $(formElement);
    
    var forms     = this;
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
        forms.process(fieldDefaults, 'blur');
        _.bindAll(this, 'blurField', 'focusField'); 
      },
      
      // Updates
      blurField:  function() { forms.process(fieldDefaults, 'blur' ); },
      focusField: function() { forms.process(fieldDefaults, 'focus'); }
    });
    
    // Kick start!
    new FieldList();
  };
  
  //---
  
  Drupal.mosaic.forms.prototype.process = function(settings, op) {
    id       = this.$element.attr('id');
    $element = this.$element;
    
    if ($element.val() === '') {
      if (op === 'blur') {
        $element.val(settings['default']);
      }
    }
      
    // Has contents
    if ($element.val() === settings['default']) {
      if (op === 'focus') {
        $element.val('');
      }
    }
  }
  
})(jQuery); 
