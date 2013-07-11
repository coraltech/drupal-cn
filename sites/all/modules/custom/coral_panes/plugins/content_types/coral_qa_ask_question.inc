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
  'title' => t('QA ask question'),                // ** default pane title **
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Coral'), -9), // We can change this category at will

  //NOTE--->> Un-comment the next line to add configs.  Talk to me if this is not clear ;-) (DW)
  'edit form' => 'coral_qa_ask_question_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_qa_ask_question_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_qa_ask_question_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // Message stuff
  $message = '';
  if (isset($conf['welcome']) || isset($conf['welcome'])) {
    $message .= '<div class="qa-msg grid-8"><div class="cont">';  
    if (isset($conf['welcome'])) $message .= '<h3>'.$conf['welcome'].'</h3>';
    if (isset($conf['message'])) {
      $message .= '<p>'.check_markup($conf['message']['value'], $conf['message']['format']).'</p>';
      
    }
    $message .= '</div></div>';
  } // end msg
  
  // Form stuff
  global $user;
  $form = '<div class="qa-form grid-16-last">';
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
  }
  $form .= render($question_form).'</div>'; // end form

  $block->title = '';
  $block->content = $message.$form;
  return $block; 
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_qa_ask_question_pane_content_type_edit_form($form, &$form_state) {
  //dpm($conf);  
  // The configurations as they were saved
  $conf = $form_state['conf'];
  
  // Add your Form API (FAPI) additions here:
  $form['welcome'] = array(
    '#type' => 'textfield', 
    '#title' => t('Welcome message'), 
    '#default_value' => isset($conf['welcome']) ? $conf['welcome'] : '', 
    '#size' => 60, 
    '#maxlength' => 128, 
  );
  
  $form['message'] = array(
    '#title' => t('Message'),
    '#type' => 'text_format',
    '#description' => t('A message to present to the user'),
    '#default_value' => isset($conf['message']['value']) ? $conf['message']['value'] : '',
  );
  
  return $form;
}


/**
* Submit function, note anything in the formstate[conf] automatically gets saved
* 
* You prob. don't need this for a static content pane.
*/
function coral_qa_ask_question_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  foreach ($form_state['values'] as $id => $value) 
    $form_state['conf'][$id] = $value;
}
