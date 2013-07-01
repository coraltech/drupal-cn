// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

/**
 * TOC Initiator - see also: https://github.com/dcneiner/TableOfContents
 */
// Document loaded!
(function($) {
  
  Drupal.behaviors.mosaicTocInit = {    
    attach : function(context, settings) {
      try { // use try to ensure that if this breaks/fails, it won't break other stuff.
        // Toc options
        var settings = {
          startLevel     : 2,
          depth          : 6,
          topLinks       : true,
          topLinkClass   : "toc-top",
          tocTrigger     : 4,
          tocTitle       : Drupal.t("Table of contents"),
          tocToggleState : 'hide',
          tocToggle: { 
            show:'[<span>hide</span>]', // looks odd but you need to tell it what to say
            hide:'[<span>show</span>]'  //  when hidden, show "show" else show "hide"...
          }
        };
        
        // Selectors we apply this to
        var selectors = ['.node .content', '.comment .content'];
        for (ind in selectors) {
          $items = $(selectors[ind]);
          $items.each(function(i) {
            new Drupal.mosaic.mosaicToc(this, settings);
          });  
        }
        
      }
      catch (err) {
        console.log('mosaicTocInit() reported errors... Perhaps you ordered tea? Error: '+err);
      }
    }
  };

  // mosaicToc takes the container and applies the TOC to it.  
  Drupal.mosaic.mosaicToc = function(container, settings) {
    var mosaicToc  = this;
    var settings   = settings;
    var $container = $(container);
    
    if (!$container.length) return; // whaddaya gonna do?
    
    var tocList = Backbone.View.extend({
      
      // Home
      el: $container,
      
      // Events ...
      events: {
        'click .toc-tog-state': 'tocTogClick'
      },
      
      // Init
      initialize: function() { 
        mosaicToc.process($(this.el), settings);
        _.bindAll(this, 'tocTogClick'); 
      },
      
      // Updates ...
      tocTogClick: function(ev) {
        var contID  = $(this.el).attr('id');
        var tocID   = contID.replace('container-', '');
        var $target = $(ev.currentTarget);
        var current = $target.text();
        for (state in settings.tocToggle) {
          statedata = settings.tocToggle[state];
          if (current != statedata.replace(/(<([^>]+)>)/ig,"")) {
            $target.html(settings.tocToggle[state]);
            break; 
          }
        }

        if (state == 'hide') $('#'+tocID).hide(750);
        else $('#'+tocID).show(750);
      }
    });
        
    // Kick start!
    new tocList();
  };
  
  //---
  
  // Process each textfield
  Drupal.mosaic.mosaicToc.prototype.process = function($container, settings) {
    var seed = Math.floor(Math.random() * 1000);
    this.addToc($container, settings, seed);
  };

  // return the toc title if there is one.
  //  Also adds show hide
  Drupal.mosaic.mosaicToc.prototype.tocTitle = function(settings) {
    var title = '';
    if (settings.tocTitle) {
      title += '<div class="toc-title">'+settings.tocTitle;
      if (settings.tocToggleState) {
        if (settings.tocToggle[settings.tocToggleState]) {
          title += '<span class="toc-tog-state">'+settings.tocToggle[settings.tocToggleState]+'</span>';
        }
      }
      title += '</div>';
    }
    return title;
  };
  
  // Add the TOC itself
  Drupal.mosaic.mosaicToc.prototype.addToc = function($container, settings, seed) {
    
    var tocID     = 'toc-'+seed;
    var tocContID = 'toc-container-'+seed;
    var tocTitle  = this.tocTitle(settings);
     
    
    $container.attr('id', tocContID); // set a container id so top can point to something
    settings.topLinkId = tocContID;   // id that top links point to
    
    // Setup the TOC
    var prepend = '<div class="toc-wrapper-'+seed+'">'; // init the prepend
    if (tocTitle) prepend += '<div class="toc-title">'+tocTitle+'</div>';
    prepend += '<ol id="'+tocID+'"></ol></div>';
    
    // Find if we need to add toc.
    $headers = $container.find("h1, h2, h3, h4, h5, h6");
    if ($headers.length >= settings.tocTrigger) {
      // Set and add the container and add the toc
      $container.prepend(prepend);
      var $toc = $('#'+tocID).tableOfContents($container, settings);
    
      if(settings.tocToggleState == 'hide') $toc.hide(); // set visibility state
    }
  };
  
})(jQuery);

