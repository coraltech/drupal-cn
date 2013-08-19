<?php

/**
* This plugin array is more or less self documenting
* 
* To use:
* 
* 1: Simply rename the functions. Removing "generic" and adding some other 
*    useful name for this plugin, eg: SSO.
* 
* 2: Fill in the $plugin title and category below.
* 
* 3: And update the render function to use your content for $block->content
* 
* 4: Save this plugin in the ivillage_components > plugins > content_types folder
* 
* 5: Add your new plugin to a panel
* 
*/

/**
 * Coral custom breadcrumb.  Edit as needed ;-) 
 */
$plugin = array(
  // the title in the admin
  'title' => t('Coral break line'),
  'single' => TRUE,
  'category' => array(t('Coral'), -9), // We can change this category at will
  'description' => t('Outputs a line break of with a configurable line-height.'),
  'edit form' => 'coral_break_line_content_type_edit_form',    // Edit form callback
  'render callback' => 'coral_break_line_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_break_line_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  $block = new stdClass();
  $line_height = ($conf['line_height']) ? $conf['line_height'] . 'em' : '1.25em';
  $block->title = t('Break line');
  $block->content = '<br style="line-height: '.$line_height.'" />';
  return $block; 
}


/**
 * 'Edit form' callback for the content type.
 * 
 * Currently un-called... no edit form needed most of the time.
 */
function coral_break_line_content_type_edit_form($form, &$form_state) {
  // The configurations as they were saved
  $conf = $form_state['conf'];
  
  $form['line_height'] = array(
    '#type' => 'select',
    '#title' => t('Line break line-height'),
    '#options' => coral_break_line_get_heights(),
    '#default_value' => ($conf['line_height']) ? $conf['line_height'] : '1.25', 
    '#description' => t('Set this value to determine the amount of space this element will take up.'),
  );
  
  // Add your Form API (FAPI) additions here:
  return $form;
}


/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * 
 * You prob. don't need this for a static content pane.
 */
function coral_break_line_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  $form_state['conf']['line_height'] = $form_state['values']['line_height'];
}


function coral_break_line_get_heights() {
  $heights = array();
  $height = .5;
  do {
    $heights[(string)$height] = (string)$height;
    $height = $height + .15;
  } while($height < 2);
  return $heights;  
}
