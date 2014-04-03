<?php

/**
 * @file
 * Ctools content-type plugin to provide a comment-reply form (replying either
 * to a node or to another comment).
 */

// Only provide the plugin in the comment module is enabled.
$plugin = array(
  'single' => TRUE,
  'title' => t('Coral comment button'),
  'description' => t('A link allowing users to comment on this content.'),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
  'category' => t('Coral'),
  'render callback'  => 'coral_comment_button_form_content_type_render',
);


function coral_comment_btn_get_class() {
  global $user;
  if (!$user->uid) { return 'anon'; }
  return '';
}

function coral_comment_button_form_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // NOTE: CSS (scss) and js applied via mosaic theme as it's nice and handy   
  $node = $context[0]->data;
  $content = '';
  if (isset($node->nid) && isset($node->type)) {
    $types = array('question', 'answer', 'comment');
    if (in_array($node->type, $types)) {
      $num_com = field_get_items('node', $node, 'field_comment_count');
      if (isset($num_com[0]['value'])) {
        $num_com = $num_com[0]['value'];
      }
      else {
        $num_com = '0';
      }
      $content = '<a href="/node/add/comment/'.$node->nid.'?field_content='.$node->nid.'" title="View and add comments" class="btn comment comment-'.$node->nid.' comments-hidden '.coral_comment_btn_get_class().'">';
      $content .= '<span class="icon"></span><span class="text">Comments</span> <span class="ans-count">('.$num_com.')</span><span class="circle"><span class="arrow"></span></span></a>';
    }
  }  
    
  $block = new stdClass();
  $block->content = $content; //comment_reply($node, ($comment ? $comment->cid : NULL));
  return $block;
}

function coral_comment_button_form_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s"', array('@s' => $context[0]->identifier));
}

function coral_comment_button_form_content_type_edit_form($form, &$form_state) {
  return $form;
}

function coral_comment_button_form_content_type_edit_form_submit($form, &$form_state) {
}
