<?php

/**
 * Community tabs pane provides the community focused tab set
 *  that one sees on the community (Books) and Q&A related pages.
 **/
$plugin = array(
  // the title in the admin
  'title' => t('Documentation welcome message'),                // ** default pane title **
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Coral'), -9), // We can change this category at will

  //NOTE--->> Un-comment the next line to add configs.  Talk to me if this is not clear ;-) (DW)
  //'edit form' => 'coral_documentation_welcome_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_documentation_welcome_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_documentation_welcome_pane_content_type_render($subtype, $conf, $context = NULL) {
  $be_bold = l('be bold', 'http://en.wikipedia.org/wiki/Wikipedia:Be_bold', array('attributes' => array('target' => '_blank')));
  $output = <<<EOF
<div class="doc-welcome">
  Welcome to the documentation wiki! This wiki is made by people just like you so {$be_bold}.
</div>
EOF;

  $block->content = $output;
  return $block;
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_documentation_welcome_pane_content_type_edit_form($form, &$form_state) {
  //dpm($conf);  
  // The configurations as they were saved
  $conf = $form_state['conf'];
  
  // Add your Form API (FAPI) additions here:
  
  
  return $form;
}


/**
* Submit function, note anything in the formstate[conf] automatically gets saved
* 
* You prob. don't need this for a static content pane.
*/
function coral_documentation_welcome_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['field'] = $form_state['values']['field'];
}
