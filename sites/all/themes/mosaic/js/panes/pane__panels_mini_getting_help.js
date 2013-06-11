
// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// ----------------------------------------------------------------------
// Help mini-panel js handlers go here
// ----------------------------------------------------------------------
//  All we are really trying to do in this file is
//   respond to clicked menu items.  Only a few
//   menu items are handled here (maybe 3)
//
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicHelpPanelInit = {    
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
        $panel = $('#pane-getting-help');
        if ($panel.length > 0) {
          new Drupal.mosaic.helpPanelManager($panel);
        }
      }
      catch(err) {
        console.log('mosaicHelpPanelInit reported errors! Error: '+err);
      }
    }
  };
  
  Drupal.mosaic.helpPanelManager = function($panel) {
    
    // jQuery objects of note
    this.$panel = $panel;
    
    // Identification and settings
    var helpPanelManager = this;
    var PanelView = Backbone.View.extend({
      // Home
      el: this.$panel,
      
      // Settings and conf
      helpPanelManager: helpPanelManager,
      
      // events
      events: {
        'click .sf-menu a': 'menuClick'
      },
      
      // Init
      initialize: function() {
        helpPanelManager.initializeForms(this.el);
         _.bindAll(this, 'menuClick');
      },
      
      menuClick: function(ev) {
        $handled = false;
        $clicked = $(ev.target);
        
        // Contact us switches forms between 
        //  contact and ask a question.
        if ($clicked.hasClass('contact-us')) {
          //console.log($clicked.text());
          if ($clicked.text() == 'Contact us') $clicked.text('Ask a question');
          else { $clicked.text('Contact us'); }
          $panes = $(this.el).find('.panel-col-last .panel-pane');
          $panes.each(function(i) {
            if ($(this).hasClass('hide')) {
              $(this).removeClass('hide');
            }
            else {
              $(this).addClass('hide');
            }
          });
          $handled = true;
        }
        if ($handled) return false;
      }
    });
    // Instantiate the panel view object
    new PanelView();
  }
  
  Drupal.mosaic.helpPanelManager.prototype.initializeForms = function(panel) {
    // Get rid of the separator -_- 
    $(panel).find('.panel-col-last .panel-separator').remove();
  }
  
})(jQuery);
