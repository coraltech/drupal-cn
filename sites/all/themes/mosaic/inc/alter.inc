<?php




// --- Hooks ---

function mosaic_form_alter(&$form, &$form_state, $form_id) {
  require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'mosaic') . '/inc/textfield_defaults.inc';
  
  // Lets see if this is a node type edit form.
  //  if so, lets add the type's css  
  if (str_replace('_node_form', '', $form_id) != $form_id) _mosiac_be_node_load_by_type($form['#node']); 
  //dpm($form_id);
  // Add default textfield support
  mosaic_add_textfield_defaults($form_id, $form);
}


// --- Helpers ---

// Stabilize the form action on the comment node book form
//  for some reason the action is not steady after the reply
//  page is set up in panels... Maybe that might be worth looking
//  into, but for now this is fine.
function mosaic_form_comment_node_book_form_alter(&$form, &$form_state) {
  $form['#action'] = '/'.current_path();  
}
