/**
 * plugin.js
 *
 * Copyright, Moxiecode Systems AB
 * Released under LGPL License.
 *
 * License: http://www.tinymce.com/license
 * Contributing: http://www.tinymce.com/contributing
 */

/*jshint unused:false */
/*global tinymce:true */

/**
 * Example plugin that adds a toolbar button and menu item.
 */
tinymce.PluginManager.add('codeblock', function(editor, url) {
	
	// Add a button that opens a window
	editor.addButton('codeblock', {
		text: 'Codeblock',
		icon: false,
		onclick: function() {
			// Open window
			win = editor.windowManager.open({
				title: 'Codeblock',
				body: 
				[{
          type: 'listbox',
          text: 'Language',
          name: 'codelanguage',
          icon: false,
          values: [
            {text: 'Auto', value: 'auto'},
            {text: 'Ruby', value: 'ruby'},
            {text: 'Puppet', value: 'puppet'},
            {text: 'Bash', value: 'bash'},
            {text: 'R source', value: 'rs'},
            {text: 'R documentation', value: 'rd'},
          ],
          onPostRender: function() {
            // Select the second item by default
            this.value('auto');
          }
        },
				{
				  type: 'textbox', 
				  name: 'codeblock', 
				  multiline: true,
          minWidth: editor.getParam("code_dialog_width", 600),
          minHeight: editor.getParam("code_dialog_height", 500),
          value: editor.selection.getContent()
				}],
				onsubmit: function(e) {
				  var lang = 'lang-' + win.find('#codelanguage').value();
				  if (lang == 'lang-auto') lang = ''; // unset lang on auto

					// Insert content when the window form is submitted
					editor.insertContent('<code class="prettyprint '+lang+'">'+e.data.codeblock+'</code>');
				}
			});
		}
	});
	
	

	// Adds a menu item to the tools menu
	/*editor.addMenuItem('codeblock', {
		text: 'Example code plugin',
		context: 'tools',
		onclick: function() {
			// Open window with a specific url
			editor.windowManager.open({
				title: 'TinyMCE site',
				url: 'http://www.tinymce.com',
				width: 800,
				height: 600,
				buttons: [{
					text: 'Close',
					onclick: 'close'
				}]
			});
		}
	});*/
});