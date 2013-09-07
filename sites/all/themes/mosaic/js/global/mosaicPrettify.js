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

        // Initialize and setup events (hover)
        $prettify.each(function() {
          new Drupal.mosaic.mosaicPrettify($(this));
        });

        // Run prettify - do it last or boink! <- seriously
        if ($prettify.length) {
          prettyPrint(); // See google-code-prettify!
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
      this.$expand;   // will contain the (expand / close) codeblock button obj
      this.origWidth; // will contain pre code width
      
      this.id = this.getID(); // register an id
      this.init();            // kick it off!
      
      this.events = {}; 
      this.events['hover #'+this.id] = 'codeHover';
      this.events['hover #exp-'+this.id] = 'expHover';
      this.events['click #exp-'+this.id] = 'codeExpand';
      
      var mosaicPrettify = this;
      var PrettifyList = Backbone.View.extend({
        
        el: this.$parent,
        
        // Settings and conf
        mosaicPrettify: mosaicPrettify,
        
        // events
        events: mosaicPrettify.events, // keyed events
             
        // Init
        initialize: function() {
          _.bindAll(this, 'codeHover', 'codeExpand');
        },
        
        // Events
        // Code hover
        codeHover: function(ev) {
          mosaicPrettify.handleCodeHover(ev);
        },
        
        // Expand the code fully
        codeExpand: function(ev) {
          ev.preventDefault(); // no; no more!
          mosaicPrettify.handleCodeExpand(ev);
        },
        
        // Hover over the expand link
        expHover: function(ev) {
          mosaicPrettify.handleExpHover(ev);
        }
        
      });
      
      // Kick start!
      new PrettifyList();
    }
    catch(err) {
      console.log('mosaicPrettify errored: '+err);
    }
  };


  // Take care of Expand/Close hover event
  Drupal.mosaic.mosaicPrettify.prototype.handleExpHover = function(ev) {
    try { 
      var evType = ev.type; // mouseenter | mouseleave | click
      if (evType == 'mouseenter') this.$expand.addClass('hover');
      if (evType == 'mouseleave') this.$expand.removeClass('hover');
    }
    catch (err) {
      console.log('handleExpHover errored: '+err);
    }
  };


  // Update text and animate on Expand click
  Drupal.mosaic.mosaicPrettify.prototype.handleCodeExpand = function(ev) {
    try { // update text and then animate
      if (!this.$expand.hasClass('exp-processing')) {
        mp = this;
        
        this.$expand.addClass('exp-processing');
        if (this.$expand.text() == 'Expand') { 
          this.$expand.text('Close'); // update text
          this.$expand.append('<span class="arrow arrow-left"></span>'); // update arrow  
        }
        else { 
          this.$expand.text('Expand'); // and text
          this.$expand.append('<span class="arrow arrow-right"></span>'); // and arrow
        }
        // animate
        this.animateCode(ev, function() {
          mp.$expand.removeClass('exp-processing');  
        });
      }
    }
    catch (err) {
      console.log('handleCodeExpand errored: '+err);
    }
  };
  
  
  // Set the id for the codeblock
  Drupal.mosaic.mosaicPrettify.prototype.handleCodeHover = function(ev) {
    try {
      this.animateCode(ev);
    }
    catch (err) {
      console.log('handleCodeHover errored: '+err);
    }
  };


  // Handle actual code animations
  // callback used by handleCodeExpand()
  Drupal.mosaic.mosaicPrettify.prototype.animateCode = function(ev, callback) {
    try {
      mp = this;
      var scrWidth = $(this.$codeblock)[0].scrollWidth;
      var callback = (typeof(callback) == 'function') ? callback : function() {};
      
      if (ev.type == 'mouseenter') {
        if (!this.$codeblock.hasClass('expanded')) {
          this.$codeblock.css({'width':this.origWidth+'px'}); // set starting width for animate
          this.$codeblock.animate({'width':(Number(this.origWidth)+25)}, 200, 'swing', callback); // do animate
          this.$codeblock.addClass('expanded'); // add expanded class
        }
        this.$expand.fadeIn(200); // What say?
      }
      if (ev.type == 'mouseleave') {
        var cb = function() {
          if (!mp.$expand.hasClass('hover')) {
            if (mp.$expand.text() != 'Close') {
              // animate to original width
              mp.$codeblock.animate({'width':mp.origWidth}, 200, 'swing', function() {
                mp.$codeblock.css({'overflow':'hidden', 'width':'auto'}); // reset css
                mp.$codeblock.removeClass('expanded'); // reset class
                callback();
              });
            }
            mp.$expand.fadeOut(200); // goodby... your legacy lives!
          }
        };
        setTimeout(cb, 25);
      }
      if (ev.type == 'click') {
        if (this.$codeblock.hasClass('expanded-full')) {
          // animate to original width + 25 px
          this.$codeblock.animate({'width':Number(this.origWidth)+25}, 200, 'swing', function() {
            mp.$codeblock.removeClass('expanded-full'); // reset class
            callback();
          });
        }
        else {
          this.$codeblock.animate({'width':scrWidth}, 200, 'swing', callback); // do animate
          this.$codeblock.addClass('expanded-full'); // add expanded class
        }
      }
    }
    catch (err) {
      console.log('animateCode errored: '+err);
    }
  };


  // Get the textarea id 
  Drupal.mosaic.mosaicPrettify.prototype.getID = function() {
    try {
      var t = new Date; // we can use date to help uniqify the id
      var id = t.getTime()+'-'+Math.floor((Math.random()*99)+1); // add ## for extra pom
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
      this.$codeblock.attr('id', this.id); // add id to codeblock
      this.$codeblock.css({'overflow':'hidden'}); // set overflow to hidden
      this.$codeblock.wrap('<div id="crp-'+this.id+'" class="precrp">'); // add a wrapper; we can't append into the pre tag!
      $('#crp-'+this.id).prepend('<a href="#" id="exp-'+this.id+'">Expand<span class="arrow arrow-right"></span></a>');
      this.$expand = $('#exp-'+this.id).hide(); // capture and hide
      this.origWidth = this.$codeblock.width(); // get codeblock width (std)
    }
    catch (err) {
      console.log('init errored: '+err);
    }
  };
  
})(jQuery);
