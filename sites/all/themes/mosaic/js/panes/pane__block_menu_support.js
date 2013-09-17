
// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};


// ----------------------------------------------------------------------
// Help tool scripts
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicHelpInit = {    
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
        
        var t = new Date;
        var id = t.getTime()+'-'+Math.floor((Math.random()*99)+1);
        
        var $helpTool = $('#pane-getting-help:not(".gh-processed")');
        var $helpMenu = $('#mini-panel-header .pane-menu-support');
        
        if ($helpTool.length && $helpMenu.length) {
          new Drupal.mosaic.helpManager(id, $helpMenu, $helpTool);
        }    
      }
      catch(err) {
        console.log('mosaicHelpInit reported errors! Error: '+err);
      }
    }
  };


  // Initialize the help tool
  Drupal.mosaic.helpManager = function(id, $menu, $tool) {
    try {
      
      this.id = id;
      
      this.$menu = $menu;
      this.$tool = $tool.addClass('gh-processed'); // say no to re-binding!
      this.$wrap; // will contain the wrapping element for the tool
      
      this.events = {};
      this.events['click .help-'+this.id] = 'helpClick';
            
      var helpManager = this;
      var ManagerView = Backbone.View.extend({
        // Home
        el: this.$menu,
        
        // Settings and conf
        helpManager: helpManager,
        
        // events
        events: helpManager.events, // keyed events
                
        // Init
        initialize: function() {
          helpManager.init();
          _.bindAll(this, 'helpClick');
        },
        
        helpClick: function(ev) {
          ev.preventDefault();
          helpManager.handleHelpClick();
        }
      });
      
      new ManagerView();
    }
    catch (err) {
      console.log('helpManager errored: '+err);
    }
  }


  // Open the help tool
  Drupal.mosaic.helpManager.prototype.openHelp = function() {
    try {
      this.$wrap.css('height', $('html')[0].scrollHeight); // set the height to the current      
      this.$wrap.fadeIn(50); // open the wrap
      this.$tool.removeClass('help-closed').fadeIn(250); // expand the tool  
    }
    catch (err) {
      console.log('openHelp errored: '+err);
    }
  };
  

  // Close the help tool
  Drupal.mosaic.helpManager.prototype.closeHelp = function(ev) {
    try {
      var hm = this;
      if (ev && ($(ev.target).hasClass('help-tool-cont') ||
          $(ev.target).hasClass('cls-help'))) {
        
        this.$tool.addClass('help-closed').fadeOut(250, function() {
          hm.$wrap.fadeOut(50);
        });
      }
    }
    catch (err) {
      console.log('closeHelp errored: '+err);
    }
  };
  
  
  // Handle click event
  Drupal.mosaic.helpManager.prototype.handleHelpClick = function() {
    try {
      if (this.$tool.hasClass('help-closed')) this.openHelp();
      else this.closeHelp(); // <-- prob never called: the btn is covered by an overlay of sorts
    }
    catch (err) {
      console.log('handleHelpClick errored: '+err);
    }
  };
  
  
  // Initialize the help tool container
  Drupal.mosaic.helpManager.prototype.init = function() {
    try {
      var hm = this;
      
      // add a suitable class to the help link
      this.$menu.find('.get-help-tab').eq(0).addClass('help-'+this.id);
      
      // hide the tool on initialization
      this.$tool.slideUp(0).addClass('help-closed');
      
      // add a wrapper
      this.$tool.wrap('<div class="help-tool-cont hcon-'+this.id+'">');
      this.$wrap = this.$tool.parent('.help-tool-cont');
      this.addCss();
      
      // clear and add clickability to the wrapper; and hide it.
      this.$wrap.off('click').click(function(ev) { hm.closeHelp(ev); }).slideUp(0);
      
      // append a close button to the forms (contact / question)
      var $clsBtn = this.$tool.find('.btn.cls-help');
      if (!$clsBtn.length) {
        this.$tool.find('.form-actions').append('<input type="button" id="close-'+this.id+'" name="op" value="Close" class="btn cls-help clsh-'+this.id+'">');
      
        $clsBtn = this.$tool.find('.btn.clsh-'+this.id); // add click handler
        $clsBtn.off('click').click(function(ev) { hm.closeHelp(ev); }).slideUp(0);
      }

    }
    catch (err) {
      console.log('init errored: '+err);
    }
  }
  
  
  // Apply basic css styles for the window
  Drupal.mosaic.helpManager.prototype.addCss = function() {
    try {
      var w = $(window).width();
      var h = $('body')[0].scrollHeight;
      var ha = $(window).height();

      // default css
      this.$wrap.css({ // wrapper
        'position': 'absolute',
        'background-color': 'rgba(0,0,0,0.5)',
        'width': '100%',
        'z-index': '20'
      });
      this.$tool.css({ // the tool
        'position':'absolute',
        'width':'810px',
        'height': '542px',
        'margin':  ((ha-542)/2)+'px '+((w-750)/2)+'px 0'
      });
    }
    catch (err) {
      console.log('addCss errored: '+err);
    }
  };
  
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
