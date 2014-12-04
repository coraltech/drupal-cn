// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};


// ----------------------------------------------------------------------
// Handles js for the CORL benefits mini panel
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicCORLBenesInit = {
    attach : function(context, settings) {
      try {
        if (context.nodeName === '#document') {
          new Drupal.mosaic.mosaicCORLBenes();
        }
      }
      catch(err) {
        console.log('mosaicHAInit errored: '+err);
      }
    }
  };


  // Start working on the benes!
  Drupal.mosaic.mosaicCORLBenes = function() {
    try {
      this.init();
      this.formatBenes();
      this.addEvents();
    }
    catch (err) {
      console.log('mosaicCORLBenes errored: '+err);
    }
  };


  // Gather the data
  Drupal.mosaic.mosaicCORLBenes.prototype.init = function() {
    try {
      this.$miniPanel = $('.pane-corl-benefits');
      this.$tabsNav = this.$miniPanel.find('.ui-tabs-nav');
      this.$tabsLI = this.$tabsNav.find('li');
      this.winW = $(window).width();
      this.speed = 0;

      this.iconize(); // set up icons
      this.insertAccordTabs(); // set up horiz accordion
    }
    catch (err) {
      console.log('init errored: '+err);
    }
  };


  // Adds icons into tabs
  Drupal.mosaic.mosaicCORLBenes.prototype.iconize = function() {
    try {
      var CB = this;
      var $a = '';   // holds an anchor jQ obj.
      var cTab = ''; // current tab
      var img = '';  // stores an image html string

      this.$tabsLI.each(function() {
        $a = $(this).children('a');
        cTab = $a.text();
        switch (cTab) {
          case 'Organizations':
            img = '<img src="/sites/all/themes/mosaic/assets/images/org-benes.png" alt="CORL for Organizations" title="CORL for Organizations">';
            $a.html('<span class="hide">'+$a.text()+'</span>').append(img);
            break;

          case 'Developers':
            img = '<img src="/sites/all/themes/mosaic/assets/images/dev-benes.png" alt="CORL for Organizations" title="CORL for Organizations">';
            $a.html('<span class="hide">'+$a.text()+'</span>').append(img);
            break;

          case 'Researchers':
            img = '<img src="/sites/all/themes/mosaic/assets/images/research-benes.png" alt="CORL for Organizations" title="CORL for Organizations">';
            $a.html('<span class="hide">'+$a.text()+'</span>').append(img);
            break;

          default: break;
        }
      });
    }
    catch (err) {
      console.log('iconize errored: '+err);
    }
  };


  Drupal.mosaic.mosaicCORLBenes.prototype.addEvents = function() {
    try {
      var CB = this;
      $(window).resize(function() {
        CB.winW = $(window).width();
        CB.formatBenes();
      });

      this.$accordTabs.off('click').click(function(ev) {
        CB.accordClick($(this));
      });
    }
    catch (err) {
      console.log('addEvents errored: '+err);
    }
  };


  Drupal.mosaic.mosaicCORLBenes.prototype.formatBenes = function() {
    try {
      // get tabs centered
      //...


      if (this.winW < 765) { // too narrow for a good tabbed display, lets use accordion
        this.$tabsNav.hide();
        this.$accordTabs.show(); // show the accordion layout
        this.$miniPanel.addClass('cbmin');
      }
      else {
        this.$tabsNav.show();
        this.$accordTabs.hide(); // hide accordion tabs
        this.$miniPanel.removeClass('cbmin');
      }
    }
    catch (err) {
      console.log('formatBenes errored: '+err);
    }
  };


  Drupal.mosaic.mosaicCORLBenes.prototype.insertAccordTabs = function() {
    try {
      var section = '';  // section label (human readable)
      var $section = ''; // Content section jQuery obj
      var label = '';    // aria label
      var CB = this;     // a copy of this

      this.$tabsLI.each(function() {
        label    = $(this).attr('aria-labelledby');
        section  = $(this).find('.hide').text();
        $section = CB.$miniPanel.find('.ui-tabs-panel[aria-labelledby="'+label+'"]');
        $section.before('<div class="horiz-acc hdr pointer benes-'+section.toLowerCase()+'" aria-labelledby="'+label+'"><div class="icon"></div>'+section+'</div>');
      });

      this.$accordTabs = this.$miniPanel.find('.horiz-acc').hide(); // save the tabs
    }
    catch (err) {
      console.log('insertAccordTabs errored: '+err);
    }
  };


  Drupal.mosaic.mosaicCORLBenes.prototype.accordClick = function($obj) {
    try {
      // get the requested section aria label
      var request = $obj.attr('aria-labelledby');
      // get the requested section obj
      var $request = this.$miniPanel.find('.ui-tabs-panel[aria-labelledby="'+request+'"]');

      if ($request.attr('aria-expanded') == 'false') {
        this.$miniPanel.find('.ui-tabs-panel[aria-expanded="true"]').attr('aria-expanded', 'false').attr('aria-hidden', 'true').slideUp(this.speed);
        $request.attr('aria-expanded', 'true').attr('aria-hidden', 'false').slideDown(this.speed);
      }
    }
    catch (err) {
      console.log('accordClick errored: '+err);
    }
  };

})(jQuery);
