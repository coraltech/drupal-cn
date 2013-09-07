
// This file will contain and serve the settings for tiny MCE

// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// Document loaded!
(function($) {
  
  // Initialize tinyMCE comps.
  Drupal.behaviors.mosaicMceInit = {
    attach : function(context, settings) {
      try { // use try to ensure that if this breaks/fails, it won't break other stuff.
        // At the moment there is not much to do here...
        $nodeForms = $('.node-form:not(".mosmce-processed")');
        $nodeForms.each(function() {
          new Drupal.mosaic.mosaicMce($(this));
        });
      }
      catch (err) {
        console.log('mosaicMceInit() reported errors. Error: '+err);
      }
    }
  };


  // Process each node form and add a WYSIWYG enable/disable link
  //  Also, attach event listener...
  Drupal.mosaic.mosaicMce = function($nodeForm) {
    try {
      this.$nodeForm = $nodeForm.addClass('mosmce-processed');
      this.$textarea = $nodeForm.find('.text-full');
      this.$submit   = $nodeForm.find('.form-submit');
      this.$wysiLink;  // will hold the link after it is created
      this.$help;      // will hold the help info
      
      this.id = this.getID(); // register an id
      
      this.events = {};
      this.events['click #btn-'+this.id] = 'wysiClick';
      this.events['click .sub-'+this.id] = 'subClick';
      this.events['click #close-help-'+this.id] = 'closeHelp';
            
      var mosaicMce = this;
      var MosaicMceView = Backbone.View.extend({
        // Home
        el: this.$nodeForm,
        
        // Settings and conf
        mosaicMce: mosaicMce,
        
        // events
        events: mosaicMce.events, // keyed events
             
        // Init
        initialize: function() {
          mosaicMce.initTextarea(mosaicMce.$textarea);
          _.bindAll(this, 'wysiClick', 'subClick', 'closeHelp');
        },
        
        // Events
        // submit button
        subClick: function(ev) {
          mosaicMce.handleSubClick(ev);
        },
        
        // wysiwyg button
        wysiClick: function(ev) {
          ev.preventDefault();
          mosaicMce.handleWysiClick(ev);
        },
        
        // Close help info
        closeHelp: function(ev) {
          ev.preventDefault();
          mosaicMce.$help.find('.close-help').fadeOut(50, function() {
            mosaicMce.$help.slideUp(100);  
          });
        }
      });
      
      new MosaicMceView();
    }
    catch (err) {
      console.log('mosaicMce errored: '+ err);
    }
  };


  // Turn off the wyiwyg before saving!
  Drupal.mosaic.mosaicMce.prototype.handleSubClick = function(ev) {
    try {
      if (!this.$wysiLink.hasClass('enable')) { // tinymce is ON
        this.toggleMce();
      }
    }
    catch (err) {
      console.log('handleSubClick errored: '+err);
    }
  };


  // Click handler for the Wysiwyg switcher
  Drupal.mosaic.mosaicMce.prototype.handleWysiClick = function(ev) {
    try {
      this.toggleMce();
    }
    catch (err) {
      console.log('handleWysiClick errored: '+ err);
    }
  };


  // Turn tinyMce on and off
  Drupal.mosaic.mosaicMce.prototype.toggleMce = function($clicked) {
    try {
      if (this.$wysiLink.hasClass('enable')) {
        tinymce.init(Drupal.mosaic.tinymceSettings('#'+this.id));
        this.$wysiLink.removeClass('enable').text('Markup');
        this.$help.find('.grid-12').removeClass('hide');
        this.$help.find('.grid-24-last').removeClass('grid-24-last').addClass('grid-12-last');
      }
      else {
        tinymce.activeEditor.remove();
        this.$wysiLink.addClass('enable').text('Wysiwyg');
        this.$help.find('.grid-12').addClass('hide');
        this.$help.find('.grid-12-last').addClass('grid-24-last').removeClass('grid-12-last');
      }
    }
    catch (err) {
      console.log('toggleMce errored: '+ err);
    } 
  };


  // Initialize the text area - add the button (link)
  Drupal.mosaic.mosaicMce.prototype.initTextarea = function($textarea) {
    try { // add clickable link
      var $wrap = $textarea.parents('.form-type-textarea').eq(0).addClass('mcetxtwrp');
      $wrap.prepend('<a href="#" id="btn-'+this.id+'" class="enable mcebtn">Wysiwyg</a>');
      
      var help = "\
      <div id='ta-help-"+this.id+"' class='ta-help clearfix'>\
      <div id='close-help-"+this.id+"' class='close-help'>x</div>\
      <div class='grid-12 hide'>\
        <p>Use <i>[shift]</i>+<i>[enter]</i> for a new paragraph.\r\n\
        Use <i>[enter]</i> for a new line.</p>\
      </div>\
      <div class='grid-24-last'>\
        <p>Did you know you can use <a href='http://www.mediawiki.org/wiki/Help:Formatting' target='_blank'>Wiki formatting</a> in your posts?</p>\
      </div>\
      </div>";
      $wrap.prepend(help);
      
      // save the new items
      this.$wysiLink = $wrap.find('#btn-'+this.id);
      this.$help     = $wrap.find('#ta-help-'+this.id);
      
      // Ensure the submit button is event handle-able
      this.$submit.addClass('sub-'+this.id);
    }
    catch (err) {
      console.log('initTextarea errored: '+err);
    }
  };


  // Get the textarea id 
  Drupal.mosaic.mosaicMce.prototype.getID = function() {
    try {
      var t = new Date;
      var id = t.getTime()+'-'+Math.floor((Math.random()*99)+1);
      
      // force unique id
      id = this.$textarea.attr('id')+'-'+id;
      
      this.$textarea.attr('id', id);
      this.$textarea.addClass('wysi-enabled'); // enable it

      return id;
    }
    catch (err) {
      console.log('getID errored: '+err);
    }
  };


  // MCE settings helpers
  // --------------------
  // Return the settings for tinymce that we want
  Drupal.mosaic.tinymceSettings = function(selector) {
    try {
      $wrapper = $(selector).parent();
      $grippie = $wrapper.find('.grippie');
      $grippie.addClass('hide');
      return {
        selector: selector,
        content_css: "/sites/all/themes/mosaic/css/global/mce_content.css",
        plugins: [
          "advlist autolink lists link charmap print preview anchor",
          "searchreplace visualblocks fullscreen",
          "insertdatetime table contextmenu paste code codeblock"
        ],
        toolbar: "undo redo | styleselect | bold italic underline | alignleft aligncenter alignright alignjustify | bullist numlist outdent indent | charmap link code codeblock"
      };
    }
    catch (err) {
      console.log('tinymceSettings errored: '+err);
    }
  };

}) (jQuery);
