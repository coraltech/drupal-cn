<?php

/**
 * @file
 * Ctools content-type plugin to provide a comment-reply form (replying either
 * to a node or to another comment).
 */

// Only provide the plugin in the comment module is enabled.
$plugin = array(
  'single' => TRUE,
  'title' => t('Coral comments target'),
  'description' => t('A container within which the Ajax loaded comments get put.'),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
  'category' => t('Coral'),
  'render callback'  => 'coral_comments_target_pane_content_type_render',
);


function coral_comments_target_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // NOTE: CSS (scss) and js applied via mosaic theme as it's nice and handy
  $node = $context[0]->data;
  $block = new stdClass();
  $block->title = t('Comments');
  $content = '<div class="comments-tgt comments-tgt-'.$node->nid.' clearfix"><p>No comments have been found!</p></div>'; // default

  if (isset($node->nid) && isset($node->type)) {
    $types = array('question', 'answer', 'comment');
    if (in_array($node->type, $types)) {
      $items = field_get_items('node', $node, 'field_comment_count');
      $content = '<div class="comments-tgt comments-tgt-'.$node->nid.' clearfix empty"><p class="tgt-load">Comments are loading.</p></div>';
    }
  }  
  $block->content = $content;
  return $block;
}

function coral_comments_target_pane_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s"', array('@s' => $context[0]->identifier));
}

function coral_comments_target_pane_content_type_edit_form($form, &$form_state) {
  return $form;
}

function coral_comments_target_pane_content_type_edit_form_submit($form, &$form_state) {
}
