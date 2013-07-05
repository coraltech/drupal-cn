<?php


/**
 * Add textfield default text automatically with js
 *  - see mosaicForms.js
 * 
 * Processes and add default text to text fields by adding settings
 *  to the Drupal.settings.field_defaults.textfieldDefaults array.
 */
function field_defaults_textfield_add_defaults($form_id, &$form) {
  $matrix = variable_get('field_defaults_textfield_matrix', array());  
  
  // Hook is composed:  hook_[form_id]__textfield_defaults($form, &$matrix)
  $hook = $form_id.'__textfield_defaults';

  // Call up all texfield defaults from any modules that
  $modules = module_implements($hook);
  
  //  implement them.
  foreach ($modules as $module) {
    $function = $module.'_'.$hook;
    $function($form, $matrix); // let modules populate the matrix
  }  

  // Storage container for found defaults: these are added to Drupal.settings 
  $field_defaults = array();
  
  field_defaults_textfield_validation($matrix, $form_id, $form);
  field_defaults_textfield_submission($matrix, $form_id, $form);
  
  foreach ($matrix as $frm => $defaults) {
    if (isset($defaults['selectors'])) {
      foreach ($defaults['selectors'] as $selector => $default) {
        $field_defaults[$selector]['default'] = $default;
      }
    }
  }

  // Save the updated matrix
  variable_set('field_defaults_textfield_matrix', $matrix);

  // Add to Drupal.settings
  if (count($field_defaults)) {
    drupal_add_js(array('field_defaults' => array('textfieldDefaults' => $field_defaults)), 'setting');
  }
}



// Determine if we need to validate this form
//  Attach validation routine as approp.
function field_defaults_textfield_validation($matrix, $form_id, &$form) {
  $vhandler = FALSE;
  
  // We have validation routines
  if (isset($matrix[$form_id]['validate'])) {
    $vhandler = $matrix[$form_id]['validate'];
    if (is_array($vhandler)) {
      foreach ($vhandler as $handler) {
        $form['#validate'][] = $handler;
      }
    }
    if (is_string($vhandler)) {
      if (function_exists($vhandler)) {
        $form['#validate'][] = $vhandler;
      }
    }
  }
  
  // No validation routines specified, add the default.
  if (!$vhandler) {
    $form['#validate'][] = 'field_defaults_textfield_validate';
  }
}


// Primary validation handler - ensures the user does not submit the default
//  Validation and submit handlers should be at the top level to prevent WSOD
function field_defaults_textfield_validate($form, &$form_state) {
  // Current state of the textfield_defaults  
  $matrix = variable_get('field_defaults_textfield_matrix', array());
  if (empty($matrix[$form['#form_id']])) return; // do we have anything to process?

  // This form's defaults
  // need to check they are not submitting defaults
  $defaults = $matrix[$form['#form_id']];
  
  if ($defaults) {
    $options = field_defaults_textfield_get_form_options($form);
    $search_values = field_defaults_textfield_get_search_values($form_state);    
    
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


// Determine if we need to do any submit handling of this form
//  You must send in custom submit handlers.  None are provided by default.
function field_defaults_textfield_submission($matrix, $form_id, &$form) {
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


// Options arrays for field defaults
//  allows you to randomly select from a set of defaults
function field_defaults_textfield_get_form_options($form) {
  // Most specific options (by form and action)
  // These follow the convention:
  // - hook__[form_id]__textfield_options  *or*
  // - hook__[form_id]__[form_action]__textfield_options
  $hooks = array(
    $form['#form_id'].'__'.field_defaults_translate_action($form).'__textfield_options', // most specific
    $form['#form_id'].'__textfield_options' // least specific
  );
  foreach ($hooks as $id => $hook) {
    // Allow modules to attach 
    foreach (module_implements($hook) as $module) {
      $function = $module.'_'.$hook;
      $options = $function($form);   // return the first set found: most specific first!
      if (is_array($options)) break; // Ignore less specifc options - if they exist
    }
    if (isset($options)) return $options;
  }
  return array();
}


// Return the values that we intend to screen
//  back to the default validator.
function field_defaults_textfield_get_search_values($form_state) {
  // we dont need to look at these values
  $ignore = array( 'form_build_id', 'form_token', 'form_id', 'op', 'submit' );
  $values = $form_state['values'];
    
  // Container to hold the items we will be screening:
  //  we dont know what field we are looking for... 
  //  jQuery tags is what we have -_-
  //  ^^^ Could be a good @TODO: could we key by some sort of id?
  $search_values = array(); 
    
  // Screen out the items we dont look at
  foreach ($values as $id => $value) {
    if (!in_array($id, $ignore)) {
      $search_values[$id] = $value;
    }
  }
  return $search_values;
}
