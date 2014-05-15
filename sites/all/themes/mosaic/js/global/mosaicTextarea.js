// This file will contain and serve the settings for tiny MCE

// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// Document loaded!
(function($) {
  
  // Initialize tinyMCE comps.
  Drupal.behaviors.mosaicTextareaInit = {
    attach : function(context, settings) {
      try { // use try to ensure that if this breaks/fails, it won't break other stuff.
        // At the moment there is not much to do here...
        var $nodeForms = $('.node-form:not(".mostxt-processed")');
        // Filter out forms that have <body> as their parent.
        //  it's a case of Panelitis!
        $nodeForms = $nodeForms.filter(function() { return !$(this).parent('body').length; }); 
        $nodeForms.each(function() {
          new Drupal.mosaic.mosaicTextarea($(this));
        });
      }
      catch (err) {
        console.log('mosaicTextareaInit() reported errors. Error: '+err);
      }
    }
  };

 // Process each node form and add a WYSIWYG enable/disable link
  //  Also, attach event listener...
  Drupal.mosaic.mosaicTextarea = function($nodeForm) {
    try {
      this.$nodeForm = $nodeForm.addClass('mostxt-processed');
      this.$textarea = $nodeForm.find('.field-name-body .text-full');
      
      this.id = Drupal.mosaic.mosaicCore.prototype.createID(this.$textarea); // register an id
      
      this.events = {};
      this.events['click #close-help-'+this.id] = 'closeHelp';
      
      var mosaicTextarea = this;
      var MosaicTextareaView = Backbone.View.extend({
        // Home
        el: this.$nodeForm,
        
        // Settings and conf
        mosaicTextarea: mosaicTextarea,
        
        // events
        events: mosaicTextarea.events, // keyed events
             
        // Init
        initialize: function() {
          mosaicTextarea.initTextarea(mosaicTextarea.$textarea);
          _.bindAll(this, 'closeHelp');
        },
        
        // Close help info
        closeHelp: function(ev) {
          ev.preventDefault();
          mosaicTextarea.$help.find('.close-help').fadeOut(50, function() {
            mosaicTextarea.$help.slideUp(100);  
          });
        }
      });
      
      new MosaicTextareaView();
    }
    catch (err) {
      console.log('mosiacTextarea errored: '+err);
    }
  };
  
    // Initialize the text area - add the button (link)
  Drupal.mosaic.mosaicTextarea.prototype.initTextarea = function($textarea) {
    try { // add clickable link
      var $wrap = $textarea.parents('.form-type-textarea').eq(0).addClass('mcetxtwrp');
      var help = "\
      <div id='ta-help-"+this.id+"' class='ta-help clearfix'>\
      <div id='close-help-"+this.id+"' class='close-help'>x</div>\
      <div class='grid-24-last'>\
        <p>Did you know you can use <a href='http://www.mediawiki.org/wiki/Help:Formatting' target='_blank'>Wiki formatting</a> and <a href='http://daringfireball.net/projects/markdown/syntax' target='_blank'>Markdown formatting</a> in your posts?</p>\
      </div>\
      </div>";
      $wrap.prepend(help);
      
      // save the new items
      this.$help     = $wrap.find('#ta-help-'+this.id);
    }
    catch (err) {
      console.log('initTextarea errored: '+err);
    }
  };
})(jQuery);

