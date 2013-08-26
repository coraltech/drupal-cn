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
  'title' => t('Coral parent content'),
  'description' => t('A rendering of the parent content of this question, answer, or comment.'),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
  'edit form' => 'coral_parent_content_pane_content_type_edit_form',    // Edit form callback
  'category' => t('Coral'),
  'render callback'  => 'coral_parent_content_pane_content_type_render',
);


function coral_parent_content_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // NOTE: CSS (scss) and js applied via mosaic theme as it's nice and handy   
  $content = '';
  $node = $context[0]->data;
  if (is_object($node)) {
    if ($node->type == 'answer') {
      $ref = field_get_items('node', $node, 'field_question');
    }
    elseif ($node->type == 'comment') {
      $ref = field_get_items('node', $node, 'field_content');
    }
  }
  if (is_array($ref)) {
    $node = drupal_render(node_view(node_load($ref[0]['target_id']), 'teaser'));
    $content = $node;
  }
  $block = new stdClass();
  $block->title = t('Parent content');
  $block->content = $content;
  return $block;
}

function coral_parent_content_pane_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s"', array('@s' => $context[0]->identifier));
}

function coral_parent_content_pane_content_type_edit_form($form, &$form_state) {
  // The configurations as they were saved
  $conf = $form_state['conf'];

  return $form;
}

function coral_parent_content_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['users_count'] = $form_state['values']['users_count'];
}
