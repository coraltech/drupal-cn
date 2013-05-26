<?php

// --- Hooks ---

function mosaic_form_alter(&$form, &$form_state, $form_id) {
  _mosaic_add_textfield_defaults($form_id); // Add default textfield support
}


// --- Helpers ---

/**
 * Add textfield default text via client-side js
 *  - see mosaicForms.js
 * 
 * Adds default text to text fields by adding settings
 *  to the Drupal.settings.mosaic.fieldDefaults array.
 */
function _mosaic_add_textfield_defaults($form_id) {
  $matrix = array(); // storage for selector statements
  
  switch ($form_id) {
    // NOTE: Put selectors in order from most to least specific.
    case 'search_form':
      $matrix['search_form'] = array(
        '#search-form .form-item-keys .form-text' => 'e.g. Apache2' // keywords
        //'#search-form .form-text' => 'Search terms',
      );
      break;

    case 'search_block_form':
      $matrix['search_block_form'] = array(
        '#search-block-form .form-text' => 'Search'
      );
      break;
    default: break; 
  }
  
  $field_defaults = array();
  foreach ($matrix as $form => $selectors) {
    foreach ($selectors as $selector => $default) {
      $field_defaults[$selector]['default'] = $default;
    }
  }
  
  // Add the settings
  if (count($field_defaults)) {
    drupal_add_js(array('mosaic' => array('fieldDefaults' => $field_defaults)), 'setting');
  }
}
