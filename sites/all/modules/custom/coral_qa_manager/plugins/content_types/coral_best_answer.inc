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
  'title' => t('Coral best answer button'),
  'description' => t('A link allowing the question asker to select the best answer.'),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
  'category' => t('Coral'),
  'render callback'  => 'coral_best_answer_pane_content_type_render',
);


function coral_best_answer_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // NOTE: CSS (scss) and js applied via mosaic theme as it's nice and handy   
  $node = $context[0]->data;
  $content = '';
  if (isset($node->nid) && isset($node->type)) {
    if ($node->type == 'answer' || $node->type == 'question') {
      $content = '<a href="#" class="best-answer best-answer-'.$node->nid.' hide">Best answer</a>'; 
    }
  }  
    
  $block = new stdClass();
  $block->content = $content;
  return $block;
}

function coral_best_answer_pane_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s"', array('@s' => $context[0]->identifier));
}

function coral_best_answer_pane_content_type_edit_form($form, &$form_state) {
  return $form;
}

function coral_best_answer_pane_content_type_edit_form_submit($form, &$form_state) {
}
