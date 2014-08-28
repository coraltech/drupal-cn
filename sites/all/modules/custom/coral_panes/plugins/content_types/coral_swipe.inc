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
* 4: Save this plugin in the components > plugins > content_types folder
* 
* 5: Add your new plugin to a panel
* 
*/
$plugin = array(
  // the title in the admin
  'title' => t('Swipe info'), 
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Coral'), -9), // We can change this category at will

  //NOTE--->> Un-comment the next line to add configs.  Talk to me if this is not clear ;-) (DW)
  'edit form' => 'coral_swipe_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_swipe_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_swipe_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  if (!isset($conf['message'])) {
    $conf['message'] = t('Swipe to view parent content');
  }
  if (!isset($conf['layout']) || !$conf['layout']) {
    $output = '<div class="swipeit discuss"><div><span class="icon arrow-left"></span><span class="msg">'.$conf['message'].'</span></div></div>';
  }
  else {
    $output = '<div class="swipeit search" title="'.$conf['message'].'"><div><span class="icon"></span></div></div>';
  }
  $block = new stdClass;
  $block->title = t('Swipeit');
  $block->content = $output;
  return $block; 
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_swipe_pane_content_type_edit_form($form, &$form_state) {
  //dpm($conf);  
  // The configurations as they were saved
  $conf = $form_state['conf'];
  
  $opts = array(0 => t('Discussion'), 1 => t('Search'));
  $form['layout'] = array(
    '#type' => 'radios',
    '#title' => t('Layout'),
    '#default_value' => ($conf['layout']) ? $conf['layout'] : 0,
    '#options' => $opts,
    '#description' => t('Layout method for this pane.'),
  );
  
  // Add your Form API (FAPI) additions here:
  $form['message'] = array(
    '#type' => 'textfield', 
    '#title' => t('Message'), 
    '#default_value' => ($conf['message']) ? $conf['message'] : t('Swipe to view parent content'), 
    '#size' => 60, 
    '#maxlength' => 128, 
    '#required' => FALSE,
    '#description' => t('Message is visible in discussion mode, and becomes the icon title in search mode.'),
  );
  
  return $form;
}


/**
* Submit function, note anything in the formstate[conf] automatically gets saved
* 
* You prob. don't need this for a static content pane.
*/
function coral_swipe_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  $form_state['conf']['layout'] = $form_state['values']['layout'];
  $form_state['conf']['message'] = $form_state['values']['message'];
}
