<?php

/**
 * Coral custom breadcrumb.  Edit as needed ;-) 
 */
$plugin = array(
  // the title in the admin
  'title' => t('Coral user'),
  'single' => TRUE,
  'category' => array(t('Coral'), -9), // We can change this category at will
  'edit form' => 'coral_user_pane_content_type_edit_form',    // Edit form callback
  'render callback' => 'coral_user_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_user_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // Get the args ready for inspection... Achtung baby!
  global $user;
  $block = new stdClass();
  if ($user->uid) {
    $welcome = '';  
    if (isset($conf['welcome_text'])) {
      $welcome = '<span class="welcome">'.filter_xss_admin($conf['welcome_text']).'</span>';
    }  
    $img = theme('user_picture', array('account' => $user, 'image_style' => 'user_thumb_small'));
    $block->content = $welcome.$img.theme('username', array('account' => $user));  
  }
  return $block;
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_user_pane_content_type_edit_form($form, &$form_state) {
  //dpm($conf);  
  // The configurations as they were saved
  $conf = $form_state['conf'];
  
  // Add your Form API (FAPI) additions here:
  $form['welcome_text'] = array(
    '#type' => 'textfield', 
    '#title' => t('Welcome text'), 
    '#default_value' => ($conf['welcome_text']) ? $conf['welcome_text'] : '', 
    '#size' => 30, 
    '#maxlength' => 60, 
  );

  return $form;
}


/**
* Submit function, note anything in the formstate[conf] automatically gets saved
* 
* You prob. don't need this for a static content pane.
*/
function coral_user_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  $form_state['conf']['welcome_text'] = $form_state['values']['welcome_text'];
}
