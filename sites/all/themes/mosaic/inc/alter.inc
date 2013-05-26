<?php

// --- Hooks ---

function mosaic_form_alter(&$form, &$form_state, $form_id) {
  // Add default textfield support
  _mosaic_add_textfield_defaults($form_id, $form);
}


// --- Helpers ---

/**
 * Add textfield default text via client-side js
 *  - see mosaicForms.js
 * 
 * Adds default text to text fields by adding settings
 *  to the Drupal.settings.mosaic.fieldDefaults array.
 */
function _mosaic_add_textfield_defaults($form_id, $form) {
  $matrix = array(); // storage for selector statements
  
  // Search form keywords default options
  $search_form_node_defaults = array( // @TODO this could be coming from top search terms!
    'e.g. Apache2 modules', 
    'e.g. Hadoop cluster', 
    'e.g. Including snippets', 
    'e.g. Using configurations', 
    'e.g. Coral cluster tutorial'
  );
  
  $search_form_user_defaults = array( // @TODO this could be coming from top search terms!
    'e.g. Brian95', 
    'e.g. Username...', 
    'e.g. user5@example.com' 
    //'e.g. Using configurations', 
    //'e.g. Coral cluster tutorial'
  );
  
  switch ($form_id) {
    // NOTE: Put selectors in order from most to least specific.
    
    // --- Search form
    case 'search_form':
      if ($form['#action'] == '/search/user') { // user search
        $matrix['search_form'] = array(
          '#search-form .form-item-keys .form-text' => $search_form_user_defaults[array_rand($search_form_user_defaults)] // keywords
        );
      }
      else { // node search
        $matrix['search_form'] = array(
          '#search-form .form-item-keys .form-text' => $search_form_node_defaults[array_rand($search_form_node_defaults)] // keywords
        );
      }
      break;
    
    // --- Search block form (header)  
    case 'search_block_form':
      $matrix['search_block_form'] = array(
        '#search-block-form .form-text' => 'Search'
      );
      break;

    default: break; 
  }
  
  $field_defaults = array();
  foreach ($matrix as $frm => $selectors) {
    foreach ($selectors as $selector => $default) {
      $field_defaults[$selector]['default'] = $default;
    }
  }
  
  // Add the settings
  if (count($field_defaults)) {
    drupal_add_js(array('mosaic' => array('fieldDefaults' => $field_defaults)), 'setting');
  }
}
