
// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

/**
 * mosaicSnippetInit bootstraps ace editor on snippet component resource fields
 */
// Document loaded!
(function($) {

  Drupal.behaviors.mosaicSnippetInit = {    
    attach : function(context, settings) {
    	try {

 				// Get the id of the context element
 				var contextID = $(context).prop('id');

				//var keys = Object.keys(context); for (key in keys) { console.log(keys[key]+': '+context[keys[key]]); }

 				// Check context to make sure that we are not
 				// un-neccessarily resetting and re-building 
 				// the snippetNodes.
 				if (context.nodeName === '#document' || contextID === 'snippet-node-form') {

	 				var snippetNodes = new Drupal.mosaic.snippetNodes(); // start controller for nodes
					var acePath = '/sites/all/themes/mosaic/js/lib/ace/src-noconflict';

	    		// Fetch all snippet nodes
	    		$snippetNodes = $('.node-snippet, .node-snippet-form').filter(function(index) {
	     			return (!$(this).parent('body').length); // sans panels goofs
	     		});

	    		if ($snippetNodes.length > 0) {

	    			//console.log(Drupal.mosaic.core);
	    			// Load any available snippetNodes from the global core
	    			if (!Drupal.mosaic.core.objects.hasOwnProperty('snippetNodes')) {
	    				Drupal.mosaic.core.objects['snippetNodes'] = {};
	    			}

	    			if (typeof ace === 'undefined') { // where is ace
	    				Drupal.mosaic.core.loadScript(acePath + '/ace.js', true,
	    					function(script, textStatus, jqXHR) { /* ace is loaded! */
	    						// Ensure proper base Path on intial load
	    						ace.config.set("basePath", acePath);
	    						snippetNodes.updateNodes($snippetNodes);
	    					}
	    				);
	    			}
	    			else {
	    				snippetNodes.updateNodes($snippetNodes);
	    			}
	    		}
    		}
    	}
    	catch (err) {
    		console.log('mosaicSnippetInit errored: '+err);
    	}
    }
  };


  // A container for useful snippet node functionality
  Drupal.mosaic.snippetNodes = function($nodes) {
  	try { return this; }
  	catch (err) { console.log('snippetNodes errored: '+err); }
  };
 

  // Backbone structure of the snippet node
  Drupal.mosaic.snippetNode = function($node) {
  	try {
  		this.$node = $node;
  		this.initNode($node); // prepare the node for processing
  		this.resources = this.getResources();
			this.events = this.getResourceEvents();

			// Auto save settings
			this.save = true;
			this.saveInterval = 1000;

			// Update textareas on submit - prob not needed
			if (this.mode === 'edit') {
				this.$node.on('submit', function() {
					this.updateResources();
				});
			}

			var snippetNode = this; // Snippet node manager
      var SnippetNodeView = Backbone.View.extend({ // the view
        // Home
        el: this.$node,

        // Save settings and conf
        snippetNode: snippetNode,

        // events
        events: snippetNode.events,

        // Init
        initialize: function() {
					snippetNode.startEditors(); // enables editors
					snippetNode.autoSave();     // keeps textareas sychronized
          _.bindAll(this, 'updateLanguage', 'updateResource'); // attach event handlers
        },

        // Update the ace editor with new language settings
        updateLanguage: function(ev) { 
          snippetNode.setLanguage(ev);
        },

        // Prepare to add a new resource item
        updateResource: function(ev) {
        	snippetNode.updateResource(ev);
        }
      });

      // Instantiate the panel view object
      new SnippetNodeView();
  	}
  	catch (err) {
  		console.log('snippetNode errored: '+err);
  	}
  };


	//-------------
	// Prototypes
	//-------------


	// Snippet Node(s) 
	// ----------------

	// Update all nodes
	Drupal.mosaic.snippetNodes.prototype.updateNodes = function($nodes) {
    try {
    	this.resetNodes(); // reset nodes

    	// compile snippet node obj
			$nodes.each(function() {
				var node = new Drupal.mosaic.snippetNode($(this));
				Drupal.mosaic.core.objects.snippetNodes[node.id] = node;	
			});
		}
		catch (err) {
			console.log('updateNodes errored: '+err);
		}
	};


	// reset nodes
	Drupal.mosaic.snippetNodes.prototype.resetNodes = function($nodes) {
		try { Drupal.mosaic.core.objects.snippetNodes = {}; }
		catch (err) { console.log('snippetNodes errored: '+err); }
	};


	// Snippet Node 
	// --------------

	// Start editor
	Drupal.mosaic.snippetNode.prototype.startEditors = function() {
		try {
			// Cycle through resources and compile ace settings
			for (resource in this.resources) {
				var rObj = this.resources[resource];
				
				var textarea = (this.mode === 'edit') ? rObj.$resources.find('textarea') : rObj.$resources.find('.field-item');
				var textareaValue = (this.mode === 'edit') ? textarea.val() : textarea.text();
				var mode = this.getLanguage(rObj);
				var readOnly = (this.mode === 'edit') ? false : true;
				var editDiv = $('<div>', {
					position: 'absolute',
					width: textarea.width(),
					height: textarea.height(),
					'class': textarea.attr('class')
				}).insertBefore(textarea);

				// Start the editor
				var editor = ace.edit(editDiv[0]);
				editor.setOptions({ 
					maxLines: 500,
					minLines: 10
				})
				editor.renderer.setShowGutter(true);
        editor.setReadOnly(readOnly);
        editor.setFontSize(16);
        editor.getSession().setValue(textareaValue);
        editor.getSession().setMode(mode);

  			//@TODO: find a cool theme
  			editor.setTheme("ace/theme/github");

  			// Save the editor!
  			this.resources[resource].editor = editor;

  			// Hide a few things - needs to happen after editor is done
  			textarea.siblings('.grippie').hide();
  			textarea.hide();
			}
		}
		catch (err) {
			console.log('startEditor errored: '+err);
		}
	};


	// Ensure that textareas are kept up to date
	Drupal.mosaic.snippetNode.prototype.autoSave = function() {
		try {
			// Saving only needed on edit forms
			if (this.mode === 'edit' && this.save) {
				SNode = this; // update the native textareas every second or so.
				this.interval = setInterval(function() { SNode.updateResource(); }, this.saveInterval);
			}
		}
		catch (err) {
			console.log('autoSave errored: '+err);
		}
	};


	// Get's the language settings from rObj - a resource object
	Drupal.mosaic.snippetNode.prototype.getLanguage = function(rObj) {
		try { // mode is the ace langauge mode - not to be confused with the snippetNode.mode
			var mode = '_none';
			if (this.mode === 'edit') { 
				mode = rObj.$language.find('select').val();
				if (mode === '_none') mode = "ace/mode/text"; 
			}
			else {
				mode = rObj.$language.find('.field-item').text();
				if (!mode) mode = 'Text';
				mode = this.getModePath(mode); // translate label to path
			}
			return mode;
		}
		catch (err) {
			console.log('getLanguage errored: '+err);
		}
	};


	// Update the editor language
	Drupal.mosaic.snippetNode.prototype.setLanguage = function(ev) {
		try {
			// Resources are tracked by the resource field id
			// the language field resides beside the resources field.
			// The currentTarget is a select within the language field.
			var tgtResource = $(ev.currentTarget).parents('.field-name-field-component-language').siblings('.field-name-field-component-resources').prop('id');
			var mode = $(ev.currentTarget).val();
			
			// default to text not _none
			mode = (mode === '_none') ? 'ace/mode/text' : mode;
			this.resources[tgtResource].editor.getSession().setMode(mode);
		}
		catch (err) {
			console.log('updateLanguage errored: '+err);
		}
	};


	// Perform resource updates - send data to textareas
	Drupal.mosaic.snippetNode.prototype.updateResource = function(ev) {
		try {
			// False alarm, begin saving again
			if (ev && ev.type === 'mouseleave') { 
				this.autoSave(); 
				return;
			}
			
			// stop auto saving
			if (ev && ev.type === 'mouseenter') { 
				clearInterval(this.interval);
			}
			
			// Update resource textareas with editor session data
			for (resources in this.resources) {
				var val = this.resources[resources].editor.getSession().getValue();
				this.resources[resources].$resources.find('.form-textarea').val(val);
			}
		}
		catch (err) {
			console.log('updateResource errored: '+err);
		}
	};

	
	// Get all resources for this node
	Drupal.mosaic.snippetNode.prototype.getResources = function() {
		try {
			var resources = {};
			var $resources = this.$node.find('.field-name-field-component-resources');

			$resources.each(function() {
				var id = Drupal.mosaic.core.createID($(this)); // get or create the id
				resources[id] = { // set default settings
					id: id,
					$resources: $(this),
					$language: $(this).siblings('.field-name-field-component-language'),
					editor: {}
				};
			});
			return resources;			
		}
		catch (err) {
			console.log('getResources errored: '+err);
		}
	};


	// Get resource events settings
	Drupal.mosaic.snippetNode.prototype.getResourceEvents = function() {
		try {
			// Each resource has a language selector
			var events = {};

			// We only need events on edit
			if (this.mode === 'edit') {
				for (resource in this.resources) {
					events['change #'+this.resources[resource].$language.find('select').prop('id')] = 'updateLanguage';
				}

				// Hovering over buttons
				events['hover .form-submit'] = 'updateResource';
			}
			return events;
		}
		catch (err) {
			console.log('getResourceEvents errored: '+err);
		}
	};


	// Initialize a snippetNode
  Drupal.mosaic.snippetNode.prototype.initNode = function($node) {
  	try {
  		// Set a few initial params and a resources placeholder
  		this.id = Drupal.mosaic.core.createID($node);
  		this.mode = ($node.find('.form-actions').length) ? 'edit' : 'read';
  		this.resources = {};

  		// Button to add a new resource
  		if (this.mode === 'edit') this.$addMore = $node.find('.field-add-more-submit');
  	}
  	catch (err) {
  		console.log('initNode errored: '+err);
  	}
  };
  
  
  Drupal.mosaic.snippetNode.prototype.getModePath = function(label) {
  	try {
  		// Languages we support editing of.
  		var paths = {
				'Ruby':'ace/mode/ruby',
				'Puppet':'ace/mode/ruby',
				'Yaml':'ace/mode/yaml',
				'JSON':'ace/mode/json',
				'Text':'ace/mode/text'
			};
			
			// return path
			if (label) {
				var keys = Object.keys(paths);
				var loc = $.inArray(label, keys);
				return paths[keys[loc]];
			}
			return paths;
  	}
  	catch (err) {
  		console.log('translateModeLabel errored: '+err);
  	}
  };

})(jQuery);
