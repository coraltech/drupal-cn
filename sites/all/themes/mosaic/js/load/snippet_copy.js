
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
					resources[resource].$resources.before('<div class="cp-cont"><span class="copy-btn" data-clipboard-target="'+tgtID+'">Copy to clipboard</span></div>');
					var $btn = resources[resource].$resources.siblings('.cp-cont').find('.copy-btn');
					core.createID($btn); // add id to the new button
					Drupal.mosaic.core.objects.snippetNodes[node.id].resources[resource]['$copyBtn'] = $btn; // store the button

					// copy message container
					resources[resource].$resources.siblings('.cp-cont').append('<div class="copy-msg"><span class="arrow-up"></span><span class="msg"></span></div>');
					var $cpMsg = resources[resource].$resources.siblings('.cp-cont').find('.copy-msg').hide();
					core.createID($cpMsg); // add id to the cp-msg container
					Drupal.mosaic.core.objects.snippetNodes[node.id].resources[resource]['$cpMsg'] = $cpMsg;
				}

				// Load the zeroclipboard js file
				Drupal.mosaic.core.loadScript('/sites/all/themes/mosaic/js/lib/ZeroClipboard/ZeroClipboard.min.js', true,
		    	function(script, textStatus, jqXHR) { // ZeroClipboard loaded
						for (var resource in resources) {
							ZeroClipboard.config({ moviePath: "/sites/all/themes/mosaic/js/lib/ZeroClipboard/ZeroClipboard.swf" });
							var client = new ZeroClipboard(resources[resource].$copyBtn); // start zeroclipboard

							client.resource = resources[resource]; // attach a resource obj

							client.on('mouseover', function(client, args) {
								SC.updateMessage(client.resource, Drupal.t('Click to copy'));
							});

							client.on('mouseout', function(client, args) {
								SC.updateMessage(client.resource, '', 250);
							});

							client.on('complete', function(client, args) {
  							SC.updateMessage(client.resource, Drupal.t('Content copied'), 1500);
							});
						}
					}
				);
			}
		}
		catch (err) {
			console.log('snippetCopy errored: '+err);
		}
	};


	// Update the message
	Drupal.mosaic.snippetCopy.prototype.updateMessage = function(resource, message, fadeTime) {
		try {
			// Clear the message from the container after a fadeOut
			var clearMsg = function() {
				if (fadeTime != undefined && Number(fadeTime)) {
					resource.$cpMsg.fadeOut(fadeTime, function() {
						resource.$cpMsg.find('.msg').text('');
					});
				}
			};

			if (message == '') { 
				clearMsg(); // fade
			}
			else {
				resource.$cpMsg.show().find('.msg').text(message); // set and show message 
				clearMsg(); // start the fadeOut if there was one
			}
		}
		catch (err) {
			console.log('updateMessage errored: '+err);
		}
	};
	
}) (jQuery);
