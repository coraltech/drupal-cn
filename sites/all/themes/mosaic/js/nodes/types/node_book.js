
// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

/**
 * mosaicBookInit bootstraps timelines and so on on book nodes
 */
// Document loaded!
(function($) {

  Drupal.behaviors.mosaicBookInit = {    
    attach : function(context, settings) {
      try {
        // Check context to make sure that we are not un-neccessarily
        // resetting and re-building the book nodes.
        if (context.nodeName === '#document') {
          
          var nodes = $node = {}; // Containers for the nodes and node
          var $bookTeaserNodes = $('.node-teaser.node-book').not('.bkproc');
          var $bookFullNodes   = $('.node-full-node.node-book').not('.bkproc');
          
          nodes = $.merge($bookTeaserNodes, $bookFullNodes); // merge list, teasers first
          if ($(nodes).length) {
            nodes = new Drupal.mosaic.bookNodes($(nodes));
          }
          
          $(window).resize(function(e) { 
            nodes.adjustTimelines();
          });
        }
      }
      catch (err) {
        console.log('Book Init errored: '+err);
      }
    }
  }


  // Process nodes
  Drupal.mosaic.bookNodes = function($nodes) {
    try {
      this.$nodes = $nodes;
      this.$timelines = {};

      var BN = this; // remember this...
      this.$nodes.each(function(i) { // go though each node and do what needs doing

        var $timeline = $(this).find('.pane-node-field-book-timeline'); // Get the timeline object
        BN.$timelines[i] = $timeline;

        // Teaser node
        if ($(this).hasClass('node-teaser')) {
          BN.alignTimeline($(this), $timeline);    // Align timeline items
          BN.timelineCollapse($(this), $timeline); // Provide button to expand and collapse timeline
        }

        // Full node
        if ($(this).hasClass('node-full-node')) {
          BN.alignTimeline($(this), $timeline); // Align timeline items
        }
        
        // Add processed class
        $(this).addClass('bkproc');
      });
      
      return this;
    }
    catch (err) {
      console.log('bookNodes errored: '+err);
    }
  };


  Drupal.mosaic.bookNodes.prototype.adjustTimelines = function() {
    try {
      for (timeline in this.$timelines) {
        var $timeline = this.$timelines[timeline];
        var $items = $timeline.find('.field-name-field-book-timeline').children('.field-items').children('.field-item:not(".spacer")');
        var ATL = this;

        var tlw = $timeline.outerWidth();
        if (tlw < 450) {
          $timeline.find('.field-item.spacer').hide(0);
          $timeline.find('.tline').css({'left':'2px'});

          $items.css({
            'margin-left': '4%', 
            'width':'95%', 
            'float':'none', 
            'clear':'none'
          });

          // Update some field item classes
          $items.each(function() {
            if ($(this).hasClass('even') && !$(this).hasClass('spacer')) {
              $(this).removeClass('even').addClass('odd atl'); 
            }
          });        
        }
        else {
          // Back to the default
          $timeline.find('.field-item.spacer').show(0);
          $timeline.find('.tline').attr('style', '');
          $items.attr('style', '');

          $items.each(function() {
            if ($(this).hasClass('atl')) {
              $(this).removeClass('odd atl').addClass('even');
            }
          });
        }
      };
      
      this.$nodes.each(function(i) {
        //console.log($(this));
        //console.log(ATL.$timelines[i]);
        ATL.alignTimeline($(this), ATL.$timelines[i]);
      });
    }
    catch (err) {
      console.log('adjustTimelines errored: '+err);
    }
  };


  // Add a collapse/expand button on teasers
  Drupal.mosaic.bookNodes.prototype.timelineCollapse = function($node, $timeline) {
    try {
      var $container = $timeline.parents('.pane-panels-mini.pane-book-timeline');
      var $content   = $container.children('.pane-content').slideUp(0); // initialize the content
      var tlTitle    = $container.find('.field-name-field-timeline-title > .field-items > .field-item').text(); // there can only be one

      tlTitle = tlTitle.toLowerCase(); // Lower case here...

      // Add the btn
      $container.prepend('<div><a href="#" class="btn tl closed">View '+tlTitle+'</a></div>');

      // Store it
      $container.delegate('.tl.btn', 'click', function(e) {
        e.preventDefault(); // STAAAP!
        if ($(this).hasClass('closed')) {
          $(this).removeClass('closed').text(Drupal.t('Hide ') + tlTitle);
          $content.slideDown(250);
        }
        else {
          $(this).addClass('closed').text(Drupal.t('View ') + tlTitle);
          $content.slideUp(250);
        }
      });
    }
    catch (err) {
      console.log('addButton errored: '+err);
    }
  };


  // Align items in the timeline
  Drupal.mosaic.bookNodes.prototype.alignTimeline = function($node, $timeline) {
    try {
      var BN = this; // always remember this...

      // prepend central line
      if (!$node.find('.tline').length) {
        $node.find('.field-name-field-book-timeline > .field-items').prepend('<div class="tline">');
      }
      
      if ($timeline.length) {
        // Loop through node timeline items and adjust spacing as needed
        var $items = $node.find('.field-name-field-book-timeline > .field-items > .field-item:not(".spacer")');
        var $prev  = {}  // storage prev timeline item - for comparison
        var lip    = 40; // px amount that we want the overlap of items to cover (at least)
        var cls    = '';

        $items.each(function(i) {
          var $curr = $(this); // the current item

          // First item
          if (!($prev instanceof jQuery)) { // jQuery object?
            $prev = $(this); // save it for next go round
            return true;     // next iteration
          }
          else { // we must be past #1
            // Do stuff about heights
            var ch   = $curr.innerHeight();
            var ph   = $prev.innerHeight();
            var cTop = $curr.position().top;
            var pTop = $prev.position().top;
            var cBot = cTop + ch;
            var pBot = pTop + ph;
            var $spc = $curr.prev('.field-item.spacer');
  
            // get some class - include field-item class!
            cls = ($curr.hasClass('even')) ? 'even' : 'odd';

            // Add spacer if needed
            if (!$spc.length) {
              //console.log('test');
              $curr.before('<div class="field-item '+cls+' spacer">');
            }

            // check positioning
            if (pBot >= cBot) { // previous reaches down further (or eq.) than the current
              //console.log($curr.prev('.field-item.spacer').outerHeight());
              $curr.prev('.field-item.spacer').css({
                'height': (lip + pBot - cBot) + 'px' 
              });
              //console.log((lip + pBot - cBot));
            }
            else {
              // @TODO: make this capable of sclaing the items back up
              // requires looking at how far the overlap is, and if we could
              // consolidate some of that overlap by removing height from
              // a spacer before.

              //console.log('Diff: '+(cBot - pBot));
              //if ((cBot - pBot) <= lip) {
                //console.log((Number($curr.prev('.field-item.spacer').outerHeight()) + ((cBot - pBot) - lip)) + 'px');
                //$curr.prev('.field-item.spacer').css({
                //  'height': (Number($curr.prev('.field-item.spacer').outerHeight()) + ((cBot - pBot) - lip)) + 'px'
                //});
              //}
            }

            // Set the prev to the curr
            $prev = $curr;
            return true; // break
          }
        });
      }
    }
    catch (err) {
      console.log('alignTimeline errored: '+err);
    }
  };
  
})(jQuery);
