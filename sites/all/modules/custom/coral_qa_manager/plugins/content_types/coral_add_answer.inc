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
);


function coral_answer_button_form_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // NOTE: CSS (scss) and js applied via mosaic theme as it's nice and handy   
  $node = $context[0]->data;
  $content = '';
  if (isset($node->nid) && isset($node->type)) {
    if ($node->type == 'question') {
      $num_ans = field_get_items('node', $node, 'field_answer_count');
      $best_ans = field_get_items('node', $node, 'field_answer');

      if (isset($num_ans[0]['value'])) {
        $num_ans = $num_ans[0]['value'];
      }
      else {
        $num_ans = '0';
      }
      
      if (isset($best_ans[0]['target_id'])) {
        $best_ans = '<span class="best"></span>';
      }
      else {
        $best_ans = '';
      }
      
      $content = '<a href="/node/add/answer/'.$node->nid.'?field_question='.$node->nid.'" title="View and submit answers to this question" class="btn answer answer-'.$node->nid.' answers-hidden">';
      $content .= '<span class="icon"></span><span class="text">Answers</span> '.$best_ans.' <span class="ans-count">('.$num_ans.')</span><span class="circle"><span class="arrow"></span></span></a>';
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
