// Registers / uses the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// Manage book form in js!
// Document loaded!
(function($) {
  Drupal.behaviors.mosaicBookFormInit = {
    attach : function(context, settings) {
      if (context.nodeName === '#document') { // only on first page load
        try { // Use try to prevent systemic failure
          Drupal.mosaic.bookFormTabsCleanup();
          Drupal.mosaic.bookFormTimelineInit();
        }
        catch(err) {
          console.log('mosaicBookFormInit reported errors! Error: '+err);
        }
      }
    }
  };


  // Make timeline collapsable and interactive on the node book edit form
  Drupal.mosaic.bookFormTimelineInit = function() {
    try {
      var $tlTitle = $('.node-form.node-book-form .field-name-field-timeline-title');
      var $tlColl  = $('.node-form.node-book-form .field-name-field-book-timeline');
      var $body    = $('.node-form.node-book-form .field-name-body');
      var $rows    = $tlColl.find('tr.draggable');
      var rows     = $rows.length;
      var editing  = 'Add';
      var input = textarea = '';

      // Determine add / edit status
      $rows.each(function() {
        if ($(this).find('input').val() || $(this).find('textarea').text()) {
          editing = 'Edit';
        }
        else {
          $tlTitle.slideUp(0);
          $tlColl.slideUp(0);
        }
      });

      // Add a button
      if (editing == 'Add') { // we do not collapse or add btns if user has timeline material added
        $body.append('<div><a href="#" class="btn tl edit closed">'+editing+' timeline</a></div>');
        $btn = $body.find('.btn.tl');
        $btn.click(function(e) { // clicketey click
          e.preventDefault();
          if ($(this).hasClass('closed')) {
            $tlTitle.slideDown(250);
            $tlColl.slideDown(250);
            $(this).removeClass('closed');
          }
          else {
            $tlTitle.slideUp(250);
            $tlColl.slideUp(250);
            $(this).addClass('closed');
          }
        });
      }
    }
    catch (err) {
      console.log('bookFormTimelineInit errored: '+err);
    }    
  };


  // Cleanup a book vertical tab text
  Drupal.mosaic.bookFormTabsCleanup = function() {
    try {
      var $formElem = $('.form-item-book-bid select:not(".bfproc")');
      if ($formElem.length > 0) {
        // Set the community documentation link to be selected (nid:32).
        //  Then trigger a change event (to load book lineage)
        $formElem.addClass('bfproc').val(32).trigger('change');

        // This gets around a bug in panels/drupal where book pages 
        //  vertical tab displays the title of our parent book
        //  twice... It is not a huge deal but in the future should
        //  be resolved in a cleaner fashion. 
        $('.vertical-tabs-list span.summary').each(function() {
          if ($(this).text() == 'Community documentationCommunity documentation') {
            $(this).before('<span class="summary mbsummary">Community documentation</span>').hide();
          }
        });
      }
    }
    catch (err) {
      console.log('bookFormCleanup errored: '+err);
    }
  };
}) (jQuery);