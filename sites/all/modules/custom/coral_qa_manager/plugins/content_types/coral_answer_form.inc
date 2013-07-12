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
  'title' => t('Coral answer question'),
  'single' => TRUE,
  'category' => array(t('Coral'), -9), // We can change this category at will
  'description' => t('Displays the answer form for this Question node.'),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node')
  ),
  'edit form' => 'coral_answer_form_content_type_edit_form',    // Edit form callback
  'render callback' => 'coral_answer_form_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_answer_form_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  
  global $user; 
  $block = new stdClass();
  
  $question = $context[0]->data;
  if ($question->type == 'question') {
    if (!$user->uid) {
      $user_login = render(drupal_get_form('user_login'));
      $answer_form = '<h3>Please login or '.l('register', 'user/register')." to answer questions.</h3>";
      $answer_form .= $user_login;
    }
    else {
      // NOTE: add field_question here!
      $node = (object) array('uid' => $user->uid, 'name' => (isset($user->name) ? $user->name : ''), 'type' => 'answer', 'language' => LANGUAGE_NONE);
      $form_state['build_info']['args'] = array($node);
      form_load_include($form_state, 'inc', 'node', 'node.pages');
      $answer_form = drupal_build_form('answer_node_form', $form_state);
      $answer_form["field_question"][$node->language][0]['target_id']['#value'] = $question->title.' ('.$question->nid.')';
    }
    $block->title = t('Answer');
    $block->content = render($answer_form);  
  }
  return $block; 
}


/**
 * 'Edit form' callback for the content type.
 * 
 * Currently un-called... no edit form needed most of the time.
 */
function coral_answer_form_content_type_edit_form($form, &$form_state) {
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
function coral_answer_form_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['remove_home'] = $form_state['values']['remove_home'];
}
