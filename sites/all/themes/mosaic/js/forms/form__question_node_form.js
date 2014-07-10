// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// ----------------------------------------------------------------------
// Snippet form processing
// ----------------------------------------------------------------------
(function($) { // doc loaded
  Drupal.behaviors.mosaicQuestionNodeFormInit = {    
    attach : function(context, settings) { // play it again Sam...
      try { // Use try to prevent systemic failure
        // Disregard node-form instances that are right under
        // the body tag... this is a panels issue: it wraps
        // the page in a form. -_-
        var $nodeForm = $('.node-question-form').filter(function(index) { //:not(".qnfproc")
          return !$(this).parent('body').length;
        });
        $nodeForm.each(function() {
          //console.log($(this));
          new Drupal.mosaic.nodeQuestionFormManager($(this));
        }); 
      }
      catch (err) {
        console.log('mosaicQuestionNodeFormInit errored: '+err);
      }
    }
  };


  // Control for the question node form
  Drupal.mosaic.nodeQuestionFormManager = function($form) {
    try {
      this.$addFile = $form.find('.form-type-managed-file label');

      var QFM = this;
      this.$addFile.each(function(i) {
        QFM.toggleFileView($(this));    
      });
    }

    catch (err) {
      console.log('nodeQuestionFormManger errored: '+err);
    }
  };


  // View file inputs
  Drupal.mosaic.nodeQuestionFormManager.prototype.toggleFileView = function($add) {
    $add.off('click').click(function() {
       if ($add.hasClass('open')) {
         $add.removeClass('open').siblings('div').hide();
       }
       else {
         $add.addClass('open').siblings('div').show();
       }
    });
  };
  
})(jQuery);

