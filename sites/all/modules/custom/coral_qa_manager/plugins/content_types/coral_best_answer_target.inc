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
  'title' => t('Coral best answer target'),
  'description' => t('A target pane where the selected best answer will appear.'),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
  'category' => t('Coral'),
  'render callback'  => 'coral_best_answer_target_content_type_render',
);


function coral_best_answer_target_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // NOTE: CSS (scss) and js applied via mosaic theme as it's nice and handy   
  $node = $context[0]->data;
  $content = '<div class="best-ans-tgt best-ans-tgt-'.$node->nid.'"></div>';
  if (isset($node->nid) && isset($node->type)) {
    if ($node->type == 'question') {
      $answer = field_get_items('node', $node, 'field_answer');
      if (isset($answer[0]) && isset($answer[0]['target_id']) && is_numeric($answer[0]['target_id'])) {
        $answer = drupal_render(node_view(node_load($answer[0]['target_id']), 'teaser'));
        $content = '<div class="best-ans-tgt best-ans-tgt-'.$node->nid.'"><h2 class="selected-title">Selected answer</h2>'.$answer.'</div>';
      }
    }
  }  
    
  $block = new stdClass();
  $block->title = t('');
  $block->content = $content;
  return $block;
}

function coral_best_answer_target_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s"', array('@s' => $context[0]->identifier));
}

function coral_best_answer_target_content_type_edit_form($form, &$form_state) {
  return $form;
}

function coral_best_answer_target_content_type_edit_form_submit($form, &$form_state) {
}
