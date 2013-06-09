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
  'title' => t('Ask a question'),                // ** default pane title **
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Coral'), -9), // We can change this category at will

  //NOTE--->> Un-comment the next line to add configs.  Talk to me if this is not clear ;-) (DW)
  //'edit form' => 'coral_ask_question_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_ask_question_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_ask_question_pane_content_type_render($subtype, $conf, $context = NULL) {
  
  global $user;
  
  if (!$user->uid) {
    $user_login = render(drupal_get_form('user_login'));
    $question_form = '<h3>Please login or '.l('register', 'user/register')." to ask questions.</h3>";
    $question_form .= $user_login;
  }
  else {
    $node = (object) array('uid' => $user->uid, 'name' => (isset($user->name) ? $user->name : ''), 'type' => 'question', 'language' => LANGUAGE_NONE);
    $form_state['build_info']['args'] = array($node);
    form_load_include($form_state, 'inc', 'node', 'node.pages');
    $question_form = drupal_build_form('question_node_form', $form_state);

    unset($question_form['additional_settings']);
  }
  $block->title = t('Ask a question');
  $block->content = render($question_form);
  return $block; 
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_ask_question_pane_content_type_edit_form($form, &$form_state) {
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
function coral_ask_question_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['field'] = $form_state['values']['field'];
}
