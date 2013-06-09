<?php

$inc = DRUPAL_ROOT . '/' . drupal_get_path('theme', 'mosaic') . '/inc/';
require_once $inc . 'textfield_defaults.inc';


// --- Hooks ---

function mosaic_form_alter(&$form, &$form_state, $form_id) {
  // Add default textfield support
  //print_r($form_id);
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
  