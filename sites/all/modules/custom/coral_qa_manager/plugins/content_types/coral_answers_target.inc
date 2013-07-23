<?php

/**
 * @file
 * Ctools content-type plugin to provide a comment-reply form (replying either
 * to a node or to another comment).
 */

// Only provide the plugin in the comment module is enabled.
$plugin = array(
  'single' => TRUE,
  'title' => t('Coral answers target'),
  'description' => t('A container within which the Ajax loaded answers get put.'),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
  'category' => t('Coral'),
  'render callback'  => 'coral_answers_target_pane_content_type_render',
);


function coral_answers_target_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // NOTE: CSS (scss) and js applied via mosaic theme as it's nice and handy   
  $node = $context[0]->data;
  $block = new stdClass();
  $block->title = t('Answers');
  $content = '<div class="answers-tgt answers-tgt-'.$node->nid.' clearfix"><p>No answers have been found!</p></div>'; // default
  
  if (isset($node->nid) && isset($node->type)) {
    if ($node->type == 'question') {
      $items = field_get_items('node', $node, 'field_answer_count');
      if (count($items) && isset($items[0]['value']) && is_numeric($items[0]['value']) && (int)$items[0]['value'] > 0) {
        $view = views_get_view('answers');
        $view->set_display('new_answers');
        $view->set_arguments(array($node->nid));
        $view->pre_execute();
        $view->execute();
        $content = '<div class="answers-tgt answers-tgt-'.$node->nid.'">'.$view->render().'</div>';
      }
    }
  }  
  $block->content = $content;
  return $block;
}

function coral_answers_target_pane_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s"', array('@s' => $context[0]->identifier));
}

function coral_answers_target_pane_content_type_edit_form($form, &$form_state) {
  return $form;
}

function coral_answers_target_pane_content_type_edit_form_submit($form, &$form_state) {
}
