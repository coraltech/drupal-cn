// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

/**
 *
 * Mosaic prettify will ensure that the prettifier
 *  is run on all new and existing <pre class="prettyprint"> 
 *  enabled code blocks. See also, codeblock plugin in 
 *  mosaic/js/lib/tinymce/js/tinymce/plugins/codeblock
 *  and prettyprint styles in mosaic/sass/global/prettify.scss
 * 
 * @TODO: Enable the prettyfier to run on codeblocks as
 *  they are being input - real-time coloring! 
 */
// Document loaded!
(function($) {
  
  Drupal.behaviors.mosaicPrettifyInit = {    
    attach : function(context, settings) {
      try { // use try to ensure that if this breaks/fails, it won't break other stuff.
        var $prettify = $('pre.prettyprint:not("prettyprinted")');
        var pretty  = []; // will store all instances of mosaicPrettify
        var $parent = {}; // holds code's parent div
        var $rows   = {}; // holds rows in this codeblock (li)
        var p       = {}; // Holds all instances of mosaicPrettify

        var resize = function(pretty) {
          try {
            // Correct formatting where needed
            for (var indx in pretty) {
              p = pretty[indx]; // li get funky
              $rows = p.$codeblock.find('ol.linenums > li');
              $parent = p.$codeblock.parents('.container').eq(0);
              
              p.scrollW = p.$codeblock[0].scrollWidth; // get codeblock width (std)
              p.parentW = $parent.outerWidth() - 2; // -2 for the codeblock's borders (1px each side)
              
              
              // ensure list items are the right width for 
              // code that overflows.
              $rows.each(function(i) {
                if (p.scrollW > p.parentW) {
                  $(this).css('width', (p.scrollW - 45)+ 'px');
                }
                else {
                  $(this).css('width', '100%');
                }
              });
            }
          }
          catch (err) {
            console.log('resize errored: '+err);
          }
        };


        // Initialize and setup events (hover)
        $prettify.each(function(i) {
           pretty[i] = new Drupal.mosaic.mosaicPrettify($(this));
        });

        // Run prettify - should happen after init!
        if ($prettify.length) {
          prettyPrint(); // See google-code-prettify!
        }


        // Init resize and set resize event
        resize(pretty);
        $(window).resize(function() {
          resize(pretty);
        });
      }
      catch (err) {
        console.log('mosaicPrettify() reported errors: '+err);
      }
    }
  };

  // Mosaic textfieldDefault takes one textfield and ensures it is
  //  set as it should be according to the specs in textfield_defaults.inc
  Drupal.mosaic.mosaicPrettify = function($codeblock) {
    try {
      this.$parent = $codeblock.parent('div');
      this.$codeblock = $codeblock;
      this.scrollW; // will contain pre code scroll width
      this.parentW; // Will contain parent width for ref.
      
      this.id = this.getID(); // register an id
      this.init();            // go
    }
    catch(err) {
      console.log('mosaicPrettify errored: '+err);
    }
  };
  
  
  // Get the textarea id 
  Drupal.mosaic.mosaicPrettify.prototype.getID = function() {
    try {
      var t = new Date; // we can use date to help uniqify the id
      var id = t.getTime()+'-'+Math.floor((Math.random()*999)+1); // add ## for extra pom
      this.$codeblock.attr('id', 'pre-'+id); // force unique id
      return id;
    }
    catch (err) {
      console.log('getID errored: '+err);
    }
  };


  // Set the id for the codeblock
  Drupal.mosaic.mosaicPrettify.prototype.init = function() {
    try {
      // Get the parent width
      var $parent = this.$codeblock.parents('.container').eq(0);

      this.scrollW = this.$codeblock[0].scrollWidth; // get codeblock width (std)
      this.parentW = $parent.outerWidth() - 2; // -2 for the codeblock's borders (1px each side)

      this.$codeblock.attr('id', this.id); // add id to codeblock
      this.$codeblock.css({'overflow-x':'auto'});     
    }
    catch (err) {
      console.log('init errored: '+err);
    }
  };
  
})(jQuery);


