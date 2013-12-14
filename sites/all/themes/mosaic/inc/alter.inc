<?php


// --- Hooks ---

function mosaic_form_alter(&$form, &$form_state, $form_id) {
  // Lets see if this is a node type edit form.
  //  if so, lets add the type's css  
  if (str_replace('_node_form', '', $form_id) != $form_id) _mosiac_be_node_load_by_type($form['#node']);

  // Add the js - basic type
  $path = drupal_get_path('theme', 'mosaic').'/css/forms/form__'.$form_id;
dpm($form_id);
  if (file_exists($path.'.css')) drupal_add_css($path.'.css', array('group' => CSS_THEME)); // - targeted type
  if (file_exists($path.'.js'))  drupal_add_js($path.'.js', array('group' => JS_THEME));
}


// --- Helpers ---

// Stabilize the form action on the comment node book form
//  for some reason the action is not steady after the reply
//  page is set up in panels... Maybe that might be worth looking
//  into, but for now this is fine.
function mosaic_form_comment_node_book_form_alter(&$form, &$form_state) {
  $form['#action'] = '/'.current_path();  
  $form['author']['_author']['#type'] = 'hidden';
}


function mosaic_form_user_login_alter(&$form, &$form_state) {
  $form['#attributes']['class'][] = 'user-login';
}


function mosaic_form_book_node_form_alter(&$form, &$form_state) {
  dpm($form);
  // Gets rid of book management tools for all but admin level users.
  if (!user_access('administer book outlines') && user_access('add content to books')) {
    $form['book']['bid']['#type'] = 'hidden';  
  }
}

