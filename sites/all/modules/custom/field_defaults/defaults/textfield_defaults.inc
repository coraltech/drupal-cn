<?php

// ----------------------------------------------------------------------------------
// Implementations of hook_[form_id]__textfield_defaults 
// ----------------------------------------------------------------------------------

// Search block form defaults (header search)
function field_defaults_search_block_form__textfield_defaults($form, &$matrix) {
  $matrix['search_block_form']['selectors'] = array(
    '#search-block-form .form-text' => t('Search')
  );
}


// Search form (main search page) default options
function field_defaults_search_form__textfield_defaults($form, &$matrix) {
  $options = field_defaults_textfield_get_form_options($form); // tool to load

  if ($form['#action'] == '/search/user') { // user search
    $matrix['search_form']['selectors'] = array(
      '#search-form .form-item-keys .form-text' => $options[array_rand($options)] // keywords
    );
  }
  else { // node search
    $matrix['search_form']['selectors'] = array(
      '#search-form .form-item-keys .form-text' => $options[array_rand($options)] // keywords
    );
  }
}


// tag search deafults
function field_defaults_coral_tag_search_form__textfield_defaults($form, &$matrix) {
  $matrix['coral_tag_search_form']['selectors'] = array(
    '#coral-tag-search-form .form-item-tag .form-text' => t('Tag search')
  );
}


// Node book comment form
function field_defaults_comment_node_book_form__textfield_defaults($form, &$matrix) {
  // Selectors  
  $matrix['comment_node_book_form']['selectors'] = array(
    '.pane-node-comment-form .form-item-subject .form-text' => 'Optional title',
    '.pane-coral-comment-reply .form-item-subject .form-text' => 'Optional title'
  );
  // Custom validation
  $matrix['comment_node_book_form']['validate'] = array('field_defaults_textfield_comment_node_book_form_validate');
}


// Node question creation form
function field_defaults_question_node_form__textfield_defaults($form, &$matrix) {
  $matrix['question_node_form']['selectors'] = array(
    '.node-question-form .form-item-title .form-text' => t('Question'),
    '.node-question-form .form-item-field-tags-und .form-text' => t('E.g. Tag, Tag two...')
  );
}


// Node answer creation form
function field_defaults_answer_node_form__textfield_defaults($form, &$matrix) {
  $matrix['answer_node_form']['selectors'] = array(
    '.node-answer-form .form-item-title .form-text' => t('Answer title (optional)')
  );
  // Custom validation
  $matrix['answer_node_form']['validate'] = array('field_defaults_textfield_answer_node_form_validate');
}


// Node answer creation form
function field_defaults_comment_node_form__textfield_defaults($form, &$matrix) {
  $matrix['comment_node_form']['selectors'] = array(
    '.node-comment-form .form-item-title .form-text' => t('Comment title (optional)')
  );
  // Custom validation
  $matrix['comment_node_form']['validate'] = array('field_defaults_textfield_comment_node_form_validate');
}


// Node question creation form
function field_defaults_user_login__textfield_defaults($form, &$matrix) {
    
  //print_r($matrix);
  $matrix['user_login']['selectors'] = array(
    '.qa-form .user-login input[name="name"]' => t('User name'),
    '.user-login input[name="name"]' => t('User name | Email')
  );
}


// ----------------------------------------------------------------------------------
// Implementations of hook__[form_id]__[form_action]__textfield_options
//  and also potentially hook__[form_id]__textfield_options 
// ----------------------------------------------------------------------------------

// Default options arrays for search node
function field_defaults_search_form__search_node__textfield_options($form) {
  return array( // @TODO this could be coming from top search terms!
    t('e.g. Apache2 modules'), 
    t('e.g. Hadoop cluster'),
    t('e.g. Including snippets'), 
    t('e.g. Using configurations'), 
    t('e.g. Coral cluster tutorial')
  );
}
// Defaults options for the search user
function field_defaults_search_form__search_user__textfield_options($form) {
  return array( // @TODO this could be coming from top search terms!
    t('e.g. Brian95'), 
    t('e.g. Username...'), 
    t('e.g. user5@example.com')
  );
}


// -- local helpers
// Validator for the comment node book form defaults.
//  added above ^
function field_defaults_textfield_comment_node_book_form_validate($form, &$form_state) {
  $matrix = variable_get('field_defaults_textfield_matrix', array());
  if ($form_state['values']['subject'] == $matrix[$form['#form_id']]['selectors']['.pane-node-comment-form .form-item-subject .form-text']) {
    form_set_value($form['subject'], '', $form_state);  //reset the input - dont feed in the default
  }
}


// Validator for the answer node form defaults.
//  added above ^
function field_defaults_textfield_answer_node_form_validate($form, &$form_state) {
  $matrix = variable_get('field_defaults_textfield_matrix', array());
  if ($form_state['values']['title'] == $matrix[$form['#form_id']]['selectors']['.node-answer-form .form-item-title .form-text']) {
    form_set_value($form['title'], '', $form_state);  //reset the input - dont feed in the default - let auto title do it's thing
  }
}


// Validator for the answer node form defaults.
//  added above ^
function field_defaults_textfield_comment_node_form_validate($form, &$form_state) {
  $matrix = variable_get('field_defaults_textfield_matrix', array());
  if ($form_state['values']['title'] == $matrix[$form['#form_id']]['selectors']['.node-comment-form .form-item-title .form-text']) {
    form_set_value($form['title'], '', $form_state);  //reset the input - dont feed in the default - let auto title do it's thing
  }
}


