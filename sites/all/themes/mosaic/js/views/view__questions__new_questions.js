
// Registers the coralQA namespace
Drupal.coralQA = Drupal.coralQA || {};

// ----------------------------------------------------------------------
// Get more questions for this view
// ----------------------------------------------------------------------
// Document loaded!
(function($) {
  Drupal.behaviors.coralNewQuestionsInit = {    
    attach : function(context, settings) {
      try { // Use try to prevent systemic failure
        var $view = $('.view-display-id-new_questions:not(".new-questions-processed")'); // Get the view
        
        if ($view.length) { // if we have it pass it in.
          new Drupal.coralQA.coralNewQuestions($view);
          $view.addClass('new-questions-processed');
        }
      }
      catch(err) {
        console.log('coralNewQuestionsInit reported errors! Error: '+err);
      }
    }
  };
  
  
  // Primary initiator of all answering related activities
  Drupal.coralQA.coralNewQuestions = function($view) {
    try {
      
      this.$view = $view; // remember the view
      this.initView();    // initialize the refID
      
      this.$more; // will contain the more link after it's made 
      this.page;  // will reference the current page
      
      // Adding events here so we can control the key    
      this.events = {};
      this.events['click .more-'+this.refID] = 'moreClick';
      
      var coralNewQuestions = this;
      var NewQuestionsView = Backbone.View.extend({
        // Home
        el: this.$view,
        
        // Settings and conf
        coralNewQuestions: coralNewQuestions,
        
        // events
        events: coralNewQuestions.events, // keyed events
             
        // Init
        initialize: function() {
          _.bindAll(this, 'moreClick');
        },
       
        // callbacks
        moreClick: function(ev) {
          ev.preventDefault();
          coralNewQuestions.handleMoreClick(ev);
        }
      });
      
      new NewQuestionsView();
    }
    catch (err) {
      console.log('coralAnswer errored: '+err);
    }
  };


  // Load the next page of results
  Drupal.coralQA.coralNewQuestions.prototype.handleMoreClick = function(ev) {
    try {
      if (!this.$more.hasClass('ajax-processing')) {
        this.getPage(this.$more); // this more button
        this.$more.addClass('ajax-processing');
        this.loadViewResults('questions', 'new_questions'); // this view
      }
    }
    catch (err) {
      console.log('handleMoreClick errored: '+err);
    }
  };


  // Set up the view and append the more link
  Drupal.coralQA.coralNewQuestions.prototype.initView = function() {
    try {
      var hide = ''; // hide class
      this.getID();  // initialize the reference ID
      this.$view.children('.item-list').children('.pager').hide();
      
      // If the view is not set, let's assume there are no more for now
      //  we can come back and revisit the possibility that this may not be hit
      if (Drupal.settings.hasOwnProperty('mosaicViews')) {
        if (Drupal.settings.mosaicViews.hasOwnProperty('questions_new_questions_'+this.refID)) {
          this.settingsID = 'questions_new_questions_'+this.refID;
          this.settings   = Drupal.settings.mosaicViews[this.settingsID];

          // Check total_item and limit count
          //  We may not need the more button
          //  Hide the regular pager...
          // And track some vars.
          var tot = this.settings.total_items;
          var cur = this.settings.limit;
          if (Number(this.settings.total_items) <= Number(this.settings.limit)) {
            tot = cur;
            hide = 'hide';
          }
          
          // Add a more button
          var btn = '<span class="btn">More questions</span>';
          var pgtot = '<span class="pgtot">(<span class="cur">'+cur+'</span>/<span class="tot">'+tot+'</span>)</span>';
          this.$view.append('<a class="questions-more more-'+this.refID+' page-1 '+hide+'" href="#">'+btn+pgtot+'<span class="no-js"><span></span></span></a>');
          this.$more = this.$view.children('.more-'+this.refID); // remember it...
        }
      }
    }
    catch (err) {
      console.log('initView errored: '+err);
    }
  };


  // Get the id of this new_questions view
  Drupal.coralQA.coralNewQuestions.prototype.getID = function() {
    try {
      // Get this view's dom id - we'll use it as a referencing id so everything stays neat.
      this.refID = this.getMatch(/^view-dom-id-/, this.$view.attr('class'));
      this.refID = this.refID.replace('view-dom-id-', '');
    }
    catch (err) {
      console.log('getID errored: '+err);
    }
  };


  // Get the current page
  Drupal.coralQA.coralNewQuestions.prototype.getPage = function($more) {
    try {
      // Get the page # from the link (first page already loaded so starts at 1)
      this.page = this.getMatch(/^page-\d+/, $more.attr('class'));
      this.page = this.page.replace('page-', '');
    }
    catch (err) {
      console.log('getPage errored: '+err);
    }
  };


  // Find the class that matches the pattern
  Drupal.coralQA.coralNewQuestions.prototype.getMatch = function(pattern, classes) {
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
  
  
  // Handles loading the answers view
  //  NOTE: It's a good idea to ALWAYS pass the arguments.  It is possible that ca.answerID may not be the one you want?
  Drupal.coralQA.coralNewQuestions.prototype.loadViewResults = function(view_name, view_display, args, callback, offset, limit) {
    try {
      var cnq = this; // for use later
      
      // @TODO: Needs to load the tag if present in the query string [tag=this-tag]
      //var args     = [args]   || [cnq.refID]; // the view args
      var callback = callback || {}; 
      var offset   = offset   || String(Number(this.page) * Number(this.settings.limit)); // current offset
      var limit    = limit    || this.settings.limit; // limit for the view results
  
      this.$more.find('.no-js').removeClass('no-js').addClass('ajax-progress');
      this.$more.find('span span').addClass('throbber');
  
      // Render the view upon the world! Go view, go!
      Drupal.coral_ajax.view_render(view_name, {
        display_id: view_display,
        args : args,
        offset : offset,
        limit : limit
      },
      function(data) { // success 
        cnq.processViewResults(data);
        if (typeof(callback) == 'function') callback(data); // fastest method: no ducktyping 
      },
      function(data) { console.log('err'); }); // failure @TODO: get a real error handler
      // and so ends the adventure of the ajax view request... the end?
    }
    catch (err) {
      console.log('loadViewResults errored: '+err);
    }
  };
  
  
  // Runs after the view succeeds in returning the next set.
  Drupal.coralQA.coralNewQuestions.prototype.processViewResults = function(data) {
    try {
      // Check get the default total items figure
      var tot = 0;
      if (this.hasOwnProperty('settings')) {
        if (this.settings.hasOwnProperty('total_items')) {
          tot = this.settings.total_items;
        }
      }
      
      var $rows = $(data).children('.view-content').children('.views-row');
      if (tot > 1 && $rows.length) {
        this.$view.children('.view-content').append($rows); // add data
        Drupal.attachBehaviors(); // get timeago et.al. to re-run on the nodes
      }
      
      this.$more.find('span span').removeClass('throbber'); // disable throbber
      this.updateMoreBtn(); // Update the more button (page-#)
    }
    catch (err) {
      console.log('processViewResults errored: '+err);
    }
  };
  
    
  // Updates the more button or removes it if we have no more items
  Drupal.coralQA.coralNewQuestions.prototype.updateMoreBtn = function() {
    try {
      if ((Number(this.page) + 1) * Number(this.settings.limit) >= Number(this.settings.total_items)) {
        this.$more.hide(); // No more to show, hide the button
      }
      else { // increment the page number
        this.$more.removeClass('page-'+this.page).addClass('page-'+String((Number(this.page) + 1)));
        this.$more.removeClass('ajax-processing'); // ok, now the user can click again!
        
        this.$more.find('.cur').text((Number(this.page) + 1) * Number(this.settings.limit));
      }
    }
    catch (err) {
      console.log('updateMoreBtn errored: '+err);
    }
  };
  
})(jQuery);

