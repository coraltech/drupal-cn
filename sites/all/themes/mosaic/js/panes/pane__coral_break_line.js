
// Registers the coralQA namespace
Drupal.coralQA = Drupal.coralQA || {};

// ----------------------------------------------------------------------
// Get more questions for this view
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.coralBreakLinesInit = {    
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
        var $content = $('.node'); // Get the questions (All of them!)
        $content.each(function() {
          new Drupal.coralQA.coralBreakLines($(this));
        });
      }
      catch(err) {
        console.log('coralBreakLines reported errors! Error: '+err);
      }
    }
  };
  
  
  // Finds this questions visible answers and updates the 
  //  best answer button if it is appropriate.
  Drupal.coralQA.coralBreakLines = function($content) {
    try {
      var nodeID = this.getNodeID($content); // this content id
      var height = $content.height(); // content height
      var $limiter = $content.find('.body-'+nodeID).eq(0).parent(); // content limiter
      var $tags = $limiter.children('.pane-node-field-tags'); // tags (for finding rel position)
      var tagsPos = $tags.position();    // get tags position
      var contPos = $content.position(); // get content position
      var emptySpace = (Number(contPos.top) + Number(height)) - Number(tagsPos.top); // find empty space between the two
      
      if (emptySpace >= 50) { // more than 50 px we remove the last line break (not needed)
        var $lineBreaks = $limiter.children('.pane-coral-break-line');
        if ($lineBreaks.length > 1) { // only remove the second of two
          $lineBreaks.eq(1).remove();
        }
      }
    }
    catch (err) {
      console.log('coralBreakLines errored: '+err);
    }
  };


  // Get this content's nid
  Drupal.coralQA.coralBreakLines.prototype.getNodeID = function($content) {
    try {
      var nodeID = this.getMatch(/^node-\d+/, $content.attr('class'));
      return nodeID.replace('node-', ''); // initialize this answer's id info
    }
    catch (err) {
      console.log('getAnswerID errored: '+err);
    }  
  };

  
  // Find the class that matches the pattern
  Drupal.coralQA.coralBreakLines.prototype.getMatch = function(pattern, classes) {
    try {
      classes = classes.split(' ');
      for (cls in classes) { 
        if (classes[cls].match(pattern)) { 
          return classes[cls]; // found it! 
        }
      } 
      return ''; // no results
    }
    catch (err) {
      console.log('getMatch errored: '+err);
    }
  };  
  
})(jQuery);

