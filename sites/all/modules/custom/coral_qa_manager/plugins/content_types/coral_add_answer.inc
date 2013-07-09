<?php

/**
 * @file
 * Ctools content-type plugin to provide a comment-reply form (replying either
 * to a node or to another comment).
 */

// Only provide the plugin in the comment module is enabled.
$plugin = array(
  'single' => TRUE,
  'title' => t('Coral answer button'),
  'description' => t('A link allowing users to answer this question.'),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
  'category' => t('Coral'),
  'render callback'  => 'coral_answer_button_form_content_type_render',
  'defaults' => array('anon_links' => false),
);


function coral_answer_button_form_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = $context[0]->data;
  $content = '';
  if (isset($node->nid) && isset($node->type)) {
    if ($node->type == 'question') {
      $content = '<a href="/node/add/answer/'.$node->nid.'?field_question='.$node->nid.'" title="Answer this question" class="btn">Answer<span class="icon"></span></a>';
    }
  }  
    
  $block = new stdClass();
  $block->content = $content; //comment_reply($node, ($comment ? $comment->cid : NULL));
  return $block;
}

function coral_answer_button_form_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s"', array('@s' => $context[0]->identifier));
}

function coral_answer_button_form_content_type_edit_form($form, &$form_state) {
  return $form;
}

function coral_answer_button_form_content_type_edit_form_submit($form, &$form_state) {
}
