
// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};


// ----------------------------------------------------------------------
// Magnificent popup instantiation
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicHelpInit = {    
    attach : function(context, settings) {
      
      try { // Use try to prevent systemic failure
        
        $helpMenu  = $('.pane-menu-support');
        $helpPopup = $('#pane-getting-help'); // there should be only one on the page!
        
        if ($helpMenu.length) {
          $helpMenu.each(function(i) {
            // Get a new id for this menu if it lacks one. May need an id later
            if (!$(this).attr('id')) $(this).attr('id', 'hm'+Math.floor(10000*Math.random()));
            new Drupal.mosaic.helpManager($(this), $helpPopup.attr('id'));
          });
        }
      }
      catch(err) {
        console.log('mosaicHelpInit reported errors! Error: '+err);
      }
    }
  };
  
  Drupal.mosaic.helpManager = function($menu, popupID) {
    
    // jQuery objects of note
    this.$helpMenu = $menu;
    
    // Identification and settings
    this.menuID = '#'+$menu.attr('id'); //'#'+this.$slideshow.attr('id');
    this.popupID = popupID;
    
    var helpManager = this;
    var ManagerView = Backbone.View.extend({
      // Home
      el: this.$helpMenu,
      
      // Settings and conf
      helpManager: helpManager,
      popupID: this.popupID,
      
      // Init
      initialize: function() {
        helpManager.initializeBox($(this.el), this.popupID);
      },
     
    });
    
    new ManagerView();
  }
  
  Drupal.mosaic.helpManager.prototype.initializeBox = function($helpMenu, popupID) {
    $target = $helpMenu.find('.get-help-tab');
    if ($target.attr('href') != '#'+popupID) $target.attr('href', '#'+popupID);
    
    // Open the popup that contains the menu and question/contact forms
    $target.magnificPopup({
      type:'inline',
      midClick: true, // Allow opening popup on middle mouse click. Always set it to true if you don't provide alternative source in href.
    });  
  }
  
})(jQuery);


// ----------------------------------------------------------------------
// Atlassian issue collector script that operates on the support menu.
// ----------------------------------------------------------------------
// Requires jQuery!

jQuery.ajax({
  url: "https://coraltech.atlassian.net/s/en_USpfg3b3-1988229788/6095/38/1.4.0-m2/_/download/batch/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector-embededjs/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector-embededjs.js?collectorId=0fcea230",
  type: "get",
  cache: true,
  dataType: "script"
});

window.ATL_JQ_PAGE_PROPS =  {
  "triggerFunction": function(showCollectorDialog) {
  //Requries that jQuery is available! 
  jQuery(".pane-menu-support .issues-tab").click(function(e) {
    e.preventDefault();
    showCollectorDialog();
  });
}};
