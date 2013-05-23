
// Protect the global namespace and set up $ = JQuery.
(function($) {

  // Define Drupal bahaviors.
  Drupal.behaviors.coralDataInit = {
      attach: function(context, settings) {
        var coreSettings = Drupal.settings.coralCore;
        var dataSettings = Drupal.settings.coralData;
        
        var $formElement = $('.coral-data').once('coral-data');
        
        for (var index = 0; index < $formElement.length; index++) {
          new Drupal.coral.data($formElement[index], coreSettings, dataSettings);
        }
      }
  };
  
  // Define Coral data object.
  Drupal.coral.data = function(formElement, coreSettings, dataSettings) {
    // General properties.
    var $data        = this;
    
    this.$formBase   = $(formElement);
    this.$formatForm = this.$formBase.find('.coral-format-form');
    
    this.formats     = dataSettings.formats;    
    
    // Display settings.
    this.updateValues();
    
    // Event handlers.
    this.$formatForm.change(function() {
      $data.updateValues();
    });
  };
  
  Drupal.coral.data.prototype.updateValues = function() {
    var activeData = this.elementData[this.$formatForm.val()];
        
    this.$formBase.find('.coral-value').addClass('value-hidden');
    
    if (typeof activeData !== 'undefined' && activeData['form_class']) {
      var activeValueClass = '.' + activeData['form_class'];
      this.$formBase.find(activeValueClass).removeClass('value-hidden').addClass('value-active');
    }
  };

})(jQuery);
