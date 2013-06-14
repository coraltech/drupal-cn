<?php

/**
 * Add textfield default text automatically with js
 *  - see mosaicForms.js
 * 
 * Adds default text to text fields by adding settings
 *  to the Drupal.settings.mosaic.fieldDefaults array.
 */
function mosaic_add_textfield_defaults($form_id, &$form) {
  
  $matrix = variable_get('mosaic_texfield_defaults_matrix', array());  
//dpm($matrix);
  
  // Process the defaults and add to the matrix if exists
  $defaults = 'mosaic__'.$form_id.'__defaults';
  if (function_exists($defaults)) $defaults = $defaults($form, $matrix);
  
  // Storage container for found defaults: these are added to Drupal.settings 
  $field_defaults = array();
  foreach ($matrix as $frm => $selectors) {
    if (!in_array('mosaic_textfield_defaults_validate', $form['#validate'])) {
      $form['#validate'][] = 'mosaic_textfield_defaults_validate';
    }  

    foreach ($selectors as $selector => $default) {
      $field_defaults[$selector]['default'] = $default;
    }
  }
  
  // Save the updated matrix
  variable_set('mosaic_texfield_defaults_matrix', $matrix);
  
  // Add to Drupal.settings
  if (count($field_defaults)) {
    drupal_add_js(array('mosaic' => array('fieldDefaults' => $field_defaults)), 'setting');
  }
}


//------------------------------------------
// --- Options arrays for field defaults ---
// Allows you to randomly select from a set of defaults
//
// These follow the convention:
// - mosaic__[form_id]__defaults_options  *or*
// - mosaic__[form_id]__[form_action]__defaults_options
// -----------------------------------------
function mosaic_get_form_options($form) {
  // Most specific options (by form and action)
  $options = 'mosaic__'.$form['#form_id'].'__'.mosaic_translate_action($form).'__defaults_options';
  if (function_exists($options)) return $options();
  
  // Options to apply to the form
  $options = 'mosaic__'.$form['#form_id'].'__defaults_options';
  if (function_exists($options)) return $options();
  
  return array();
}


// Primary validation handler - ensures the user does not submit the default
function mosaic_textfield_defaults_validate($form, &$form_state) {
  // Current state of the textfield_defaults  
  $matrix = variable_get('mosaic_texfield_defaults_matrix', array());
  if (empty($matrix[$form['#form_id']])) return; // do we have anything to process?
  
  // we dont need to look at these values
  $ignore = array(
    'form_build_id',
    'form_token',
    'form_id',
    'op',
    'submit'
  );
  
  // This form's defaults
  // need to check they are not submitting defaults
  $defaults = $matrix[$form['#form_id']];
  if ($defaults) {
    $action = mosaic_translate_action($form);  
    $values = $form_state['values'];
    
    // Container to hold the items we will be screening:
    //  we dont know what field we are looking for... 
    //  jQuery tags is what we have -_-
    //  ^^^ Could be a good @TODO
    $search_values = array(); 
    
    // Screen out the items we dont look at
    foreach ($values as $id => $value) {
      if (!in_array($id, $ignore)) {
        $search_values[$id] = $value;
      }
    } 
    
    // Lets see if there are any defaults left
    foreach ($search_values as $id => $value) {
      // Options functions should be named mosaic__[form_id]__defaults_options
      // Or more specifically: mosaic__[form_id]__[form_action]__defaults_options
      $options = 'mosaic__'.$form['#form_id'].'__'.$action.'__defaults_options';
      if (function_exists($options)) {
        $options = $options();
      }
      else {
        // Less specific function
        $options = 'mosaic_'.$form['#form_id'].'__defaults_options';  
        if (function_exists($options)) {
          $options = $options();
        }
      }
      
      // Test to see if it is a default
      $options = (is_array($options)) ? $options : array();       
      if (in_array($value, $matrix[$form['#form_id']])) {
        form_set_error($id, t('You cannot submit default values.'));
        return;
      }
      
      // Testing the optionally defined options array
      if (count($options) > 1) {
        if (in_array($value, $options)) {
          form_set_error($id, t('You cannot submit default values.'));
          return;
        }
      }
    }
  }
}


// --- Form defaults ---

// Search block form defaults (header search)
function mosaic__search_block_form__defaults($form, &$matrix) {
  $matrix['search_block_form'] = array(
    '#search-block-form .form-text' => 'Search'
  );
}


// Search form (main search page) default options
function mosaic__search_form__defaults($form, &$matrix) {
  $options = mosaic_get_form_options($form);

  if ($form['#action'] == '/search/user') { // user search
    $matrix['search_form'] = array(
      '#search-form .form-item-keys .form-text' => $options[array_rand($options)] // keywords
    );
  }
  else { // node search
    $matrix['search_form'] = array(
      '#search-form .form-item-keys .form-text' => $options[array_rand($options)] // keywords
    );
  }
}


// Node question creation form (currently not used)
function mosaic__question_node_form__defaults($form, &$matrix) {
  $matrix['question_node_form'] = array(
    '#question-node-form .form-item-title .form-text' => 'State your question',
    '#question-node-form .form-item-field-tags-und .form-text' => 'E.g. Tag, Tag two, Tres...'
  );
}


// --- True helpers --- bless their hearts
// Default options arrays for search node
function mosaic__search_form__search_node__defaults_options() {
  return array( // @TODO this could be coming from top search terms!
    'e.g. Apache2 modules', 
    'e.g. Hadoop cluster',
    'e.g. Including snippets', 
    'e.g. Using configurations', 
    'e.g. Coral cluster tutorial'
  );
}
// Defaults options for the search user
function mosaic__search_form__search_user__defaults_options() {
  return array( // @TODO this could be coming from top search terms!
    'e.g. Brian95', 
    'e.g. Username...', 
    'e.g. user5@example.com'
  );
}
// END main search form helpers


// Returns $form actions with / replaced with _ 
function mosaic_translate_action($form) {
  $action = explode('/', $form['#action']); 
  array_shift($action);
  return implode('_', $action);
}




