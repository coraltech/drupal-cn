
// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

/**
 * mosaicSnippetInit bootstraps ace editor on snippet component resource fields
 */
// Document loaded!

(function($) {

  Drupal.behaviors.mosaicSnippetCopyInit = {    
    attach : function(context, settings) {
    	try {
    		var core  = Drupal.mosaic.core;
    		var nodes = core.objects.snippetNodes;

    		if (context === '#snippet-copy') {
	    		for (var node in nodes) { // each node is a snippetNode object
	    			new Drupal.mosaic.snippetCopy(nodes[node]);
					}
    		}
			}
			catch (err) {
				console.log('mosaicSnippetCopyInit errored: '+err);
			}
		}
	};


	// Attach ZeroCopy to all node resources
	Drupal.mosaic.snippetCopy = function(node) {
		try {
			var SC = this;
			var resources = node.resources; // the resources on this node
			var core = Drupal.mosaic.core;  // easy access
			
			// If there are no resources do nothing
			// @TODO: get this working in edit mode
			//  atm the adding of new resource components kills it.
			if (core.objCount(resources) && node.mode === 'read') {

				// Add and store the copy link
				for (var resource in resources) {
					// get target id 
					var tgtID = core.createID($('#'+resource).find('.field-item:not(".ace_editor")'));
					resources[resource].$resources.before('<button class="copy-btn" data-clipboard-target="'+tgtID+'">Copy to clipboard</button>');
					var $btn = resources[resource].$resources.siblings('button.copy-btn'); 
					var btnID = core.createID($btn); // add id to the new button
					Drupal.mosaic.core.objects.snippetNodes[node.id].resources[resource]['$copyBtn'] = $btn; // store the button
				}

				// Load the zeroclipboard js file
				Drupal.mosaic.core.loadScript('/sites/all/themes/mosaic/js/lib/ZeroClipboard/ZeroClipboard.min.js', true,
		    	function(script, textStatus, jqXHR) { // ZeroClipboard loaded
						for (var resource in resources) {
							ZeroClipboard.config({ moviePath: "/sites/all/themes/mosaic/js/lib/ZeroClipboard/ZeroClipboard.swf" });
							var client = new ZeroClipboard(resources[resource].$copyBtn); // start zeroclipboard
						}
					}
				);
			}
		}
		catch (err) {
			console.log('snippetCopy errored: '+err);
		}
	};
	
}) (jQuery);
