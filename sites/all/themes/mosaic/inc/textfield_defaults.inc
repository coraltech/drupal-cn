<?php

/**
 * Add textfield default text automatically with js
 *  - see mosaicForms.js
 * 
 * Adds default text to text fields by adding settings
 *  to the Drupal.settings.mosaic.fieldDefaults array.
 */
function mosaic_add_textfield_defaults($form_id, &$form) {
  //dpm($form_id);   
  $matrix = variable_get('mosaic_texfield_defaults_matrix', array());  
  
  // Process the defaults and add to the matrix if exists
  $defaults = 'mosaic__'.$form_id.'__defaults';
//dpm($defaults);
  if (function_exists($defaults)) { $defaults = $defaults($form, $matrix); }

  // Storage container for found defaults: these are added to Drupal.settings 
  $field_defaults = array();
  
  mosaic_textfield_defaults_validation($matrix, $form_id, $form);
  mosaic_textfield_defaults_submission($matrix, $form_id, $form);
  
  foreach ($matrix as $frm => $defaults) {
    if (isset($defaults['selectors'])) {
      foreach ($defaults['selectors'] as $selector => $default) {
        $field_defaults[$selector]['default'] = $default;
      }
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


// Determine if we need to validate this form
//  Attach validation routine as approp.
function mosaic_textfield_defaults_validation($matrix, $form_id, &$form) {
  $validate = FALSE;
  
  // We have validation routines
  if (isset($matrix[$form_id]['validate'])) {
    $validate = $matrix[$form_id]['validate'];
    if (is_array($validate)) {
      foreach ($validate as $handler) {
        $form['#validate'][] = $handler;
      }
    }
    if (is_string($validate)) {
      if (function_exists($validate)) {
        $form['#validate'][] = $validate;
      }
    }
  }
  
  // no validation routines specified, add the default.
  if (!$validate) {
    $form['#validate'][] = 'mosaic_textfield_defaults_validate';
  }
}


// Determine if we need to validate this form
//  You can send in custom validators in the defaults settings
function mosaic_textfield_defaults_submission($matrix, $form_id, &$form) {
  if (isset($matrix[$form_id])) {
    $settings = $matrix[$form_id];
    if (isset($settings['submit'])) {
      if (is_string($settings['submit'])) {
        $settings['submit'] = array($settings['submit']);
      }
      foreach ($settings['submit'] as $submit_handler) {
        if (function_exists($submit_handler) && !in_array($submit_handler, $form['#submit'])) {
          $form['#submit'][] = $submit_handler;          
        }
      }
    }
  }
}


// Return the values that we intend to screen
function mosaic_textfield_defaults_get_search_values($form_state) {
  // we dont need to look at these values
  $ignore = array(
    'form_build_id',
    'form_token',
    'form_id',
    'op',
    'submit'
  );
  
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
  return $search_values;
}


// Returns any default options that may exist for this form
function mosaic_texfield_defaults_get_defaults_options($form) {
  // Options functions should be named mosaic__[form_id]__defaults_options
  // Or more specifically: mosaic__[form_id]__[form_action]__defaults_options
  $action = mosaic_translate_action($form);
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
  if (is_array($options)) return $options;
  return FALSE;   
}


// Primary validation handler - ensures the user does not submit the default
function mosaic_textfield_defaults_validate($form, &$form_state) {
  // Current state of the textfield_defaults  
  $matrix = variable_get('mosaic_texfield_defaults_matrix', array());
  if (empty($matrix[$form['#form_id']])) return; // do we have anything to process?

  // This form's defaults
  // need to check they are not submitting defaults
  $defaults = $matrix[$form['#form_id']];
  
  if ($defaults) {
    $options = mosaic_texfield_defaults_get_defaults_options($form);
    $search_values = mosaic_textfield_defaults_get_search_values($form_state);    
    
    // Lets see if there are any defaults left
    foreach ($search_values as $id => $value) {
            
      // Test to see if it is a default
      if (array_search($value, $matrix[$form['#form_id']]['selectors'], TRUE)) {
        form_set_error($id, t('You cannot submit default values (1).'));
        return;
      }

      // Testing the optionally defined options array
      $options = (is_array($options)) ? $options : array();
      if (count($options) > 1) {
        if (array_search($value, $options, TRUE)) {
          form_set_error($id, t('You cannot submit default values (2).'));
          return;
        }
      }
    }
  }
}


// --- Form defaults ---

// Search block form defaults (header search)
function mosaic__search_block_form__defaults($form, &$matrix) {
  $matrix['search_block_form']['selectors'] = array(
    '#search-block-form .form-text' => t('Search')
  );
}


// Search form (main search page) default options
function mosaic__search_form__defaults($form, &$matrix) {
  $options = mosaic_get_form_options($form);

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
function mosaic__coral_tag_search_form__defaults($form, &$matrix) {
  $matrix['coral_tag_search_form']['selectors'] = array(
    '#coral-tag-search-form .form-item-tag .form-text' => t('Tag search')
  );
}


// Node book comment form
function mosaic__comment_node_book_form__defaults($form, &$matrix) {
  // Selectors  
  $matrix['comment_node_book_form']['selectors'] = array(
    '.pane-node-comment-form .form-item-subject .form-text' => 'Optional title',
    '.pane-coral-comment-reply .form-item-subject .form-text' => 'Optional title'
  );
  // Custom validation
  $matrix['comment_node_book_form']['validate'] = array('mosaic_textfield_comment_node_book_form_validate');
}


// Node question creation form (currently not used)
function mosaic__question_node_form__defaults($form, &$matrix) {
  $matrix['question_node_form']['selectors'] = array(
    '#question-node-form .form-item-title .form-text' => t('State your question'),
    '#question-node-form .form-item-field-tags-und .form-text' => t('E.g. Tag, Tag two, Tres...')
  );
}


// --- True helpers --- bless their hearts
// Default options arrays for search node
function mosaic__search_form__search_node__defaults_options() {
  return array( // @TODO this could be coming from top search terms!
    t('e.g. Apache2 modules'), 
    t('e.g. Hadoop cluster'),
    t('e.g. Including snippets'), 
    t('e.g. Using configurations'), 
    t('e.g. Coral cluster tutorial')
  );
}
// Defaults options for the search user
function mosaic__search_form__search_user__defaults_options() {
  return array( // @TODO this could be coming from top search terms!
    t('e.g. Brian95'), 
    t('e.g. Username...'), 
    t('e.g. user5@example.com')
  );
}
// END main search form helpers


// Returns $form actions with / replaced with _ 
function mosaic_translate_action($form) {
  $action = explode('/', $form['#action']); 
  array_shift($action);
  return implode('_', $action);
}


// Validator for the comment node book form defaults.
function mosaic_textfield_comment_node_book_form_validate($form, &$form_state) {
  $matrix = variable_get('mosaic_texfield_defaults_matrix', array());
  if ($form_state['values']['subject'] == $matrix[$form['#form_id']]['selectors']['.pane-node-comment-form .form-item-subject .form-text']) {
    form_set_value($form['subject'], '', &$form_state); //reset the input - dont feed in the default
  }
}






