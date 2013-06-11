<?php

$inc = DRUPAL_ROOT . '/' . drupal_get_path('theme', 'mosaic') . '/inc/';
require_once $inc . 'textfield_defaults.inc';


// --- Hooks ---

function mosaic_form_alter(&$form, &$form_state, $form_id) {
  // Lets see if this is a node type edit form.
  //  if so, lets add the type's css  
  if (str_replace('_node_form', '', $form_id) != $form_id) _mosiac_be_node_load_by_type($form['#node']); 
  
  // Add default textfield support
  mosaic_add_textfield_defaults($form_id, $form);
}


// --- Helpers ---

function mosaic_form_user_login_alter(&$form, &$form_state, $form_id) {
  $form['name']['#size'] = 45;
  $form['pass']['#size'] = 45;
  $form['#prefix'] = str_replace('<h3>Login using social networks</h3>', '', $form['#prefix']); 
}


function mosaic_form_question_node_form_alter(&$form, &$form_state, $form_id) {
  //print_r($form);
  $form['title']['#size'] = 45;
  $form['field_tags']['und']['#size'] = 45; //['#size'] = 45;
}
  