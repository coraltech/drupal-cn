
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
            new Drupal.mosaic.bookNodes($(nodes));
          }
        }
      }
      catch (err) {
        console.log('Book Init errored: '+err);
      }
    }
  }
  
  Drupal.mosaic.bookNodes = function($nodes) {
    try {
      var BN = this; // remember this...
      $nodes.each(function() { // go though each node and do what needs doing

        var $timeline = $(this).find('.pane-node-field-book-timeline'); // Get the timeline object

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
    }
    catch (err) {
      console.log('bookNodes errored: '+err);
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
  }


  // Align items in the timeline
  Drupal.mosaic.bookNodes.prototype.alignTimeline = function($node, $timeline) {
    try {
      var BN = this; // always remember this...
      
      // prepend central line
      $('.field-name-field-book-timeline > .field-items').prepend('<div class="tline">');
      
      if ($timeline.length) {
        // Loop through timeline items and adjust as needed
        var $items = $('.field-name-field-book-timeline > .field-items > .field-item');
        var $prev  = {}  // storage prev timeline item - for comparison
        var lip    = 40; // px amount that we want the overlap of items to cover (at least)
        var cls    = '';

        $items.each(function() {
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

            // get some class - include field-item class!
            cls = ($curr.hasClass('even')) ? 'even' : 'odd';

            // Add spacer
            $curr.before('<div class="field-item '+cls+' spacer">');

            if (pBot >= cBot) { // previous reaches down further (or eq.) than the current
              $curr.prev('.field-item.spacer').css({
                'height': (lip + pBot - cBot) + 'px' 
              });
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
  }
  
})(jQuery);
