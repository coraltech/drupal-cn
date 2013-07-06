<?php


// Determine if we need to validate this form
//  Attach validation routine as approp.
function field_defaults_textarea_validation($matrix, $form_id, &$form) {
  field_defaults_validation($matrix, $form_id, $form, 'textarea');
}


// Primary validation handler - ensures the user does not submit the default
//  Validation and submit handlers should be at the top level to prevent WSOD
function field_defaults_textarea_validate($form, &$form_state) {
  field_defaults_validate($form, $form_state, 'textarea');
}


// Determine if we need to do any submit handling of this form
//  You must send in custom submit handlers.  None are provided by default.
function field_defaults_textarea_submission($matrix, $form_id, &$form) {
  field_defaults_submission($matrix, $form_id, &$form);
}


// Options arrays for field defaults
//  allows you to randomly select from a set of defaults
function field_defaults_textarea_get_form_options($form) {
  return field_defaults_get_form_options($form, 'textarea');
}



