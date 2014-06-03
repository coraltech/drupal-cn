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
        var pretty = []; // will store all instances of mosaicPrettify

        // Initialize and setup events (hover)
        $prettify.each(function(i) {
           pretty[i] = new Drupal.mosaic.mosaicPrettify($(this));
        });

        // Run prettify - should happen after init!
        if ($prettify.length) {
          prettyPrint(); // See google-code-prettify!
        }
        
        // Correct formatting where needed
        for (var indx in pretty) {
          var p = pretty[indx]; // li get funky
          var $rows = p.$codeblock.find('ol.linenums > li');

          // ensure list items are the right width for 
          // code that overflows.
          $rows.each(function(i) {
            if (p.origWidth > p.parentW) {
              $(this).css('width', p.origWidth + 'px');
            }
          });
        }
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
      this.origWidth; // will contain pre code width
      this.parentW;   // Will contain parent width for ref.
      
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

      this.origWidth = this.$codeblock.width(); // get codeblock width (std)
      this.parentW = $parent.width() - 2; // -2 for the codeblock's borders (1px each side)

      this.$codeblock.attr('id', this.id); // add id to codeblock
      this.$codeblock.css({'overflow-x':'auto'});     
    }
    catch (err) {
      console.log('init errored: '+err);
    }
  };
  
})(jQuery);


