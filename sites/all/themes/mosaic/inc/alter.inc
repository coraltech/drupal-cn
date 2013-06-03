<?php

$inc = DRUPAL_ROOT . '/' . drupal_get_path('theme', 'mosaic') . '/inc/';
require_once $inc . 'textfield_defaults.inc';


// --- Hooks ---

function mosaic_form_alter(&$form, &$form_state, $form_id) {
  // Add default textfield support
  mosaic_add_textfield_defaults($form_id, $form);
}


// --- Helpers ---

