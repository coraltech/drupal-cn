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
$plugin = array(
  // the title in the admin
  'title' => t('Project status'), 
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Coral'), -9), // We can change this category at will

  //NOTE--->> Un-comment the next line to add configs.  Talk to me if this is not clear ;-) (DW)
  'edit form' => 'coral_status_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_status_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_status_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  $block = new stdClass;
  $status = array('status', 'warning', 'error');  
  if (isset($conf['message']) && isset($conf['status'])) {
    $block->content = '<div class="messages '.$status[(int)$conf['status']].'"><div class="cont">'.filter_xss_admin($conf['message']).'</div></div>'; // ** Add your content here! with: _some_nifty_function() or whatever. **
  }
  return $block; 
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_status_pane_content_type_edit_form($form, &$form_state) {
  // The configurations as they were saved
  $conf = $form_state['conf'];

  // Add your Form API (FAPI) additions here:
  $form['message'] = array(
    '#type' => 'textfield', 
    '#title' => t('Message'), 
    '#default_value' => ($conf['message']) ? $conf['message'] : '', 
    '#size' => 60,
    '#maxlength' => 220, 
    '#required' => TRUE,
  );
  
  $form['status'] = array(
    '#type' => 'select',
    '#title' => t('Status'),
    '#options' => array(
      0 => t('All clear'),
      1 => t('Warning'),
      2 => t('Error')
    ),
    '#default_value' => ($conf['status']) ? $conf['status'] : 1,
    '#description' => t('Current status of the project'),
  );
  return $form;
}


/**
* Submit function, note anything in the formstate[conf] automatically gets saved
* 
* You prob. don't need this for a static content pane.
*/
function coral_status_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  $form_state['conf']['message'] = $form_state['values']['message'];
  $form_state['conf']['status'] = $form_state['values']['status'];
}