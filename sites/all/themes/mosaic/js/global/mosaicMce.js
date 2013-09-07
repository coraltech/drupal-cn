
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
      
      this.id = this.getID(); // register an id
      
      this.events = {};
      this.events['click #btn-'+this.id] = 'wysiClick';
      this.events['click .sub-'+this.id] = 'subClick';
            
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
          _.bindAll(this, 'wysiClick', 'subClick');
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
        this.$wysiLink.removeClass('enable').text('MARKUP');
      }
      else {
        tinymce.activeEditor.remove();
        this.$wysiLink.addClass('enable').text('WYSIWYG');
      }
    }
    catch (err) {
      console.log('toggleMce errored: '+ err);
    } 
  };


  // Initialize the text area - add the button (link)
  Drupal.mosaic.mosaicMce.prototype.initTextarea = function($textarea) {
    try { // add clickable link
      var $wrap = $textarea.parents('.form-type-textarea');
      $wrap.prepend('<a href="#" id="btn-'+this.id+'" class="enable">WYSIWYG</a>');
      
      // save the link forever!
      this.$wysiLink = $wrap.find('#btn-'+this.id);
      
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
