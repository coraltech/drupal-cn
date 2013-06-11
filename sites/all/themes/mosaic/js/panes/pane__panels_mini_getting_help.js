
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
    this.$panel = $panel; // the mini-panel that holds the popup contents
    
    // Identification and settings
    var helpPanelManager = this;
    var PanelView = Backbone.View.extend({
      // Home
      el: this.$panel,
      
      // Settings and conf
      helpPanelManager: helpPanelManager,
      
      // Events
      events: {
        'click .sf-menu a': 'menuClick'
      },
      
      // Init the manager
      initialize: function() {
        helpPanelManager.initializeForms(this.el);
         _.bindAll(this, 'menuClick');
      },
      
      // Default help menu item click
      menuClick: function(ev) {
        handled = false; // we will let the click pass if it isnt handled below
        $clicked = $(ev.target); // target the user clicked on (jQuery)
        
        // Contact us  --  switches forms between 
        //  contact and ask a question.
        if ($clicked.hasClass('contact-us')) {
          helpPanelManager.contactClick($clicked, $(this.el));// Contact link clicked
          handled = true;// this is js handled
        }
        
        // Bug report  --  turns off the magnificPopup
        //  and clicks the bug report button ;-)
        else if ($clicked.hasClass('bug-report')) {
          helpPanelManager.bugClick();// Bug link clicked
          handled = true;// this is js handled
        }
        
        if (handled) return false; // don't execute the click event for real
      }
    });
    // Instantiate the panel view object
    new PanelView();
  };
  
  Drupal.mosaic.helpPanelManager.prototype.initializeForms = function(panel) {
    // Get rid of the separator -_- 
    $(panel).find('.panel-col-last .panel-separator').remove();
  };
  
  // Manages click handling of 'Contact us / Ask question' link
  Drupal.mosaic.helpPanelManager.prototype.contactClick = function($clicked, $panel) {
    if ($clicked.text() == 'Contact us') $clicked.text('Ask a question');
    else { $clicked.text('Contact us'); }
    $panes = $panel.find('.panel-col-last .panel-pane');
    
    // Go through panes
    $panes.each(function(i) {
      if ($(this).hasClass('hide')) {
        $(this).removeClass('hide');
      }
      else {
        $(this).addClass('hide');
      }
    });
  };
  
  // Manages click handling of 'Issues and bugs!' link.
  //  simply closes the current popup and opens the issue manager
  Drupal.mosaic.helpPanelManager.prototype.bugClick = function() {
    // close the mfp - http://stackoverflow.com/a/16919889/1857689
    var magnificPopup = $.magnificPopup.instance;
    magnificPopup.close();
          
    // click the issues tab         
    $('a.issues-tab').trigger('click');
  };
  
})(jQuery);
