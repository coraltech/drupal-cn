<?php

/**
 * @file
 * Best answer button - See also the js in the mosaic theme: pane__coral_best_answer.js
 *  
 * NOTE: This pane should be attached to the question AND the answer because we can only 
 *  be sure that a question will be loaded on the page.  We don't know if any answers
 *  will be loaded at run time... Best be safe than sorry.
 * 
 */
// Only provide the plugin in the comment module is enabled.
$plugin = array(
  'single' => TRUE,
  'title' => t('Coral featured users'),
  'description' => t('A JS activated pane where conversation participants are displayed.'),
  //'required context' => array(
  //  new ctools_context_required(t('Node'), 'node'),
  //),
  'edit form' => 'coral_featured_users_pane_content_type_edit_form',    // Edit form callback
  'category' => t('Coral'),
  'render callback'  => 'coral_featured_users_pane_content_type_render',
);


function coral_featured_users_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // NOTE: CSS (scss) and js applied via mosaic theme as it's nice and handy   
  //$node = $context[0]->data;
  $conf['users_count'] = (isset($conf['users_count'])) ? $conf['users_count'] : '24';
  $content = '<div class="featured-users users-count-'.$conf['users_count'].'"></div>';

  $block = new stdClass();
  $block->title = t('Featured users');
  $block->content = $content;
  return $block;
}

function coral_featured_users_pane_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s"', array('@s' => $context[0]->identifier));
}

function coral_featured_users_pane_content_type_edit_form($form, &$form_state) {
  // The configurations as they were saved
  $conf = $form_state['conf'];
  
  $form['users_count'] = array(
    '#type' => 'textfield', 
    '#title' => t('User image limit'), 
    '#default_value' => (isset($conf['users_count'])) ? $conf['users_count'] : '24', 
    '#size' => 2, 
    '#maxlength' => 2,
    '#description' => t('Please enter a positive integer (1-99)'),
  );

  return $form;
}

function coral_featured_users_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  $form_state['conf']['users_count'] = $form_state['values']['users_count'];
}
