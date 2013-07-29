<?php

// ----------------------------------------------------------------------------------
// Implementations of hook_[form_id]__textfield_defaults 
// ----------------------------------------------------------------------------------

// Search block form defaults (header search)
function field_defaults_question_node_form__textarea_defaults($form, &$matrix) {
  $matrix['question_node_form']['selectors'] = array(
    '.pane-coral-qa-ask-question .node-question-form .text-full' => t('Question detail')
  );
}


// Node answer creation form
function field_defaults_answer_node_form__textarea_defaults($form, &$matrix) {
  $matrix['answer_node_form']['selectors'] = array(
    '.node-answer-form .text-full' => t('Answer detail')
  );
}


// Node answer creation form
function field_defaults_comment_node_form__textarea_defaults($form, &$matrix) {
  $matrix['comment_node_form']['selectors'] = array(
    '.node-comment-form .text-full' => t('Comment detail')
  );
}