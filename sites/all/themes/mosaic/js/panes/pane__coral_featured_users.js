
// This file ensures that if the community tabs are
//  shown, the Community primary link will be active

// Registers the Mosaic namespace
Drupal.coralQA = Drupal.coralQA || {};

// Document loaded!
(function($) {
  
  Drupal.behaviors.coralFeaturedUsersInit = {
    attach : function(context, settings) {
      try {
        var selectors = '.node-question.node-teaser,'; // questions
        selectors   += ' .node-answer.node-teaser,';   // answers
        selectors   += ' .node-comment.node-teaser';   // comments
        
        var $pane = $('.featured-users');
        var $content = $(selectors);
        
        if ($content.length > 1) {
          new Drupal.coralQA.coralFeaturedUsers($content, $pane);
        }
        //else {
        //  $pane.parents('.panel-pane').eq(0).hide();
        //}
      }
      catch (err) {
        console.log('coralFeaturedUsersInit() reported errors. Error: '+err);
      }
    }
  };
  

  // Gather the featured users into the pane.  
  Drupal.coralQA.coralFeaturedUsers = function($content, $pane) {
    try {
      var users = {};  // contains users data
      var counts = {}; // contains the counts
      var sorted = {}; // hash to populate by the sort
    
      $content.each(function() { // get the images together
        var $pic = $(this).find('.user-picture').eq(0);
        var href = $pic.find('a').attr('href');
        
        if (!users.hasOwnProperty(href)) {
          users[href] = $pic.clone();
        }
        
        // Keep the counts
        if (!counts.hasOwnProperty(href)) counts[href] = 1;
        else counts[href] += 1; // add to it if there.
      });
  
      var len = Object.keys(users).length;
      var i = max = 0;
      var it = '';
  
      do {
        max = 0;
        for (item in counts) {
          if (counts[item] > max) {
            max = counts[item];
            it = item;
          }
        }
        sorted[it] = users[it];
        counts[it] = 0; // lets make sure this is not a max again
        i++;
      } while(i < len);
      
      var limit = 24;
      var classes = $pane.attr('class');
      classes = classes.split(' ');
      for (cls in classes) {
        if (classes[cls].match(/^users-count-\d+/)) {
          limit = Number(classes[cls].replace('users-count-', ''));
        }
      }
  
      // We don't know what the next run may bring so 
      //  we will clear out the old content.
      //  Now, append the selected number of sorted elements
      i = 0;
      if (len) $pane.html('');
      if (len > 1) { // make sure there is more than one user featured
        this.togglePane($pane, 'show');
        for (item in sorted) {
          if (i < limit) {
            $pane.append(sorted[item]);
            i++;  
          }
        }
      }
      else { // only one user... hide the pane.
        this.togglePane($pane, 'hide');
      }
    }
    catch(err) {
      console.log('coralFeaturedUsers errored: '+err);
    }
  }
  
  
  // Show or hide the pane when needed.
  Drupal.coralQA.coralFeaturedUsers.prototype.togglePane = function($pane, op) {
    try {
      if (op == 'show') { $pane.parents('.panel-pane').eq(0).show(); }
      else { $pane.parents('.panel-pane').eq(0).hide(); }
    }
    catch (err) {
      console.log('togglePane errored: '+err);
    }
  };

  
})(jQuery);
