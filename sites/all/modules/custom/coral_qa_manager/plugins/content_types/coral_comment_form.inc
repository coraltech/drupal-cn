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
  'title' => t('Coral comment form'),
  'single' => TRUE,
  'category' => array(t('Coral'), -9), // We can change this category at will
  'description' => t('Displays the comment form for this node.'),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node')
  ),
  'edit form' => 'coral_comment_form_content_type_edit_form',    // Edit form callback
  'render callback' => 'coral_comment_form_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_comment_form_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  
  global $user; 
  $block = new stdClass();
  
  $context_node = $context[0]->data;
  $types = array('question', 'answer', 'comment');
  if (in_array($context_node->type, $types)) {
    $comment_start = '<div class="comment-form comment-form-'.$context_node->nid.'">';
    $comment_end = '</div>';
    
    if (!$user->uid) {
      $user_login = render(drupal_get_form('user_login'));
      $answer_form = '<h3>Please login or '.l('register', 'user/register')." to post comments.</h3>";
      $answer_form .= $user_login;
    }
    else {
      // NOTE: add field_question here!
      $node = (object) array('uid' => $user->uid, 'name' => (isset($user->name) ? $user->name : ''), 'type' => 'comment', 'language' => LANGUAGE_NONE);
      $form_state['build_info']['args'] = array($node);
      form_load_include($form_state, 'inc', 'node', 'node.pages');
      $comment_form = drupal_build_form('comment_node_form', $form_state);
      $comment_form["field_content"][$node->language][0]['target_id']['#value'] = $context_node->title.' ('.$context_node->nid.')';
    }
    
    $block->title = t('Comment');
    $block->content = $comment_start.render($comment_form).$comment_end;  
  }
  return $block; 
}


/**
 * 'Edit form' callback for the content type.
 * 
 * Currently un-called... no edit form needed most of the time.
 */
function coral_comment_form_content_type_edit_form($form, &$form_state) {
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
function coral_comment_form_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['remove_home'] = $form_state['values']['remove_home'];
}
