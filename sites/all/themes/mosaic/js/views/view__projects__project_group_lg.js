// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// Hides and shows featuresets on projects
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicProjectsGroupInit = {
    attach : function(context, settings) {
      try {
        if (context.nodeName === '#document') {
          var $pane = $('.pane-projects-project-group-lg');
          new Drupal.mosaic.projectGroup(context, $pane);
        }
      }
      catch(err) {
        console.log('mosaicProjectGroupInit reported errors! Error: '+err);
      }
    }
  };


  // There really isn't that much to do here but fire it up baby!
  Drupal.mosaic.projectGroup = function(context, $pane) {
    try {
      this.init(context, $pane);
    }
    catch (err) {
      console.log('projectGroup errored: '+err);
    }
  };


  // Initialize the objects
  Drupal.mosaic.projectGroup.prototype.init = function(context, $pane) {
    try {
      // find: node-teaser node-project
      this.$pane = $pane;
      this.$nodes = this.$pane.find('.node-project');

      var pg = this;
      this.$nodes.each(function(i) {
        var $node = pg.$nodes.eq(i); // this project node
        var $learn = $node.find('.pane-node-field-documentation-reference .more a');
        var $features = $node.find('.pane-node-field-item-featureset');
        pg.setClick($learn, $features);
      });
    }
    catch (err) {
      console.log('Init errored: '+err);
    }
  };


  // Enable feature viewing click handler
  Drupal.mosaic.projectGroup.prototype.setClick = function($learn, $features) {
    try {
      var pg = this;

      // Set click handler - quick and dirty
      $learn.off('click').click(function(ev) {
        ev.preventDefault();
        $features.show();
        $learn.off('click').text(Drupal.t('Learn even more')); // no more click handler coverage
        pg.initClose($learn, $features);
      });
    }
    catch (err) {
      console.log('setClick errored: '+err);
    }
  };


  // Add closing button and set events
  Drupal.mosaic.projectGroup.prototype.initClose = function($learn, $features) {
    try {
      var pg = this;
      var $cls = $features.css('position', 'relative').prepend('<div class="mbclose">x</div>').children('.mbclose');
      $cls.css({
        'cursor': 'pointer',
        'position': 'absolute',
        'z-index': 9,
        'font-size': '2em',
        'right': '-14px',
        'top': '-14px',
      });

      $cls.off('click').click(function() {
        $features.hide();
        $cls.remove();
        pg.setClick($learn, $features);
        $learn.text(Drupal.t('Learn more'));
      });
    }
    catch (err) {
      console.log('initClose errored: '+err);
    }
  };

})(jQuery);

