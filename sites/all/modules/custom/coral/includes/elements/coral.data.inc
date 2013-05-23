<?php

/**
 * Implements hook_theme().
 */
function coral_data_theme() {
  return array(
    'coral_data' => array(
      'render element' => 'element',
    ),
  );
}

/**
 * Implements hook_element_info().
 */
function coral_data_element_info() {
  $module_path = drupal_get_path('module', 'coral');
  
  return array(
    'coral_data'  => array(
      '#input'            => TRUE,
      '#value_callback'   => 'coral_data_value',
      '#process'          => array('coral_data_process'),
      '#after_build'      => array('coral_data_after_build'),
      '#element_validate' => array('coral_data_validate'),
      '#theme'            => 'coral_data',
      '#theme_wrappers'   => array('form_element'),
      '#attached'         => array(
        'css' => array("${module_path}/css/coral_data.css"),
        'js'  => array(
          "${module_path}/js/coral_data.js",
          array(
            'type' => 'setting',
            'data' => array(
              'coralData' => array(
                'formats' => Coral::formats(),
              ),
            ),
          )
        ),
      ),
    ),
  );
}

/**
 * The #value_callback for a coral_data type element.
 */
function coral_data_value(&$element, $input = FALSE, $form_state = NULL) {
  //dpm($input, 'coral_data_value -> $input');
  
  // Process any input.
  if ($input !== FALSE) {
    $return = Coral::normalize($input);
  }
  // If there is no input, set the default value.
  else {
    if (!Coral::exists($element, '#default_value')) {
      $element['#default_value'] = array();
    }
    $return = $element['#default_value'] + array(
      'format' => CORAL_TYPE_STRING,
      'data'   => ''
    );
  }
  //dpm($return, 'coral_data_value -> $return');
  return $return;
}

/**
 * Process function to expand the coral_data element type.
 *
 * Expands the file type to include Upload and Remove buttons, as well as
 * support for a default value.
 */
function coral_data_process($element, &$form_state, $form) {
  $element += coral_data_form($form, $form_state, $element, $element['#id'], $element['#value'], NULL);
  return coral_form_wrapper($element, array('coral-data', 'container-inline'));
}

/**
 * Return a single data form. (default implementation)
 * 
 * Combinations:
 * 
 * > format=undef
 * > format=bool value=(true|false)
 * > format=number value=/^\-?[\d\.]+$/
 * > format=string value
 * > format=array value=(count=/^[\d]+$/>0)
 *   -> format value?
 * > format=hash value=(count=/^[\d]+$/>0)
 *   -> key format value?
 */
function coral_data_form(&$form, &$form_state, $element, $base_id, $item, $index) {
  $format = (isset($item['format']) ? $item['format'] : NULL);
  $data   = (isset($item['data']) ? $item['data'] : NULL);
  
  $ajax_wrapper = "${base_id}-data-wrapper";
    
  $addons = array(
    '#tree' => TRUE,
  );    
  $addons['format'] = coral_form_element(-1, array(
      '#type'          => 'select',
      '#title'         => t('Format'),
      '#options'       => Coral::merge(Coral::formatOptions(TRUE), array(
        CORAL_TYPE_ARRAY => t('Array'),
        CORAL_TYPE_HASH  => t('Hash'),
        CORAL_TYPE_UNDEF => t('Undefined'),
      )),
      '#default_value' => $format,
      '#ajax'          => array(
        'callback' => 'coral_data_format_ajax_callback',
        'wrapper'  => $ajax_wrapper,
        'effect'   => 'fade',
      ),
    ), 
    "${base_id}-format", 
    'coral-format-form', 
    'coral-format'
  );
  if ($format != CORAL_TYPE_UNDEF) {
    if (is_numeric($format)) {
      $node = node_load($format);
      $addons['data'] = coral_form_element(1, $node->coral->selectedForm($data), 
        "${base_id}-" . $node->title, 
        array('coral-data-value-form', 'coral-data-' . $node->title . '-form'), 
        array('coral-value', 'coral-value-' . $node->title)
      );
    }
    elseif ($format == CORAL_TYPE_ARRAY) {
      $addons['data'] = coral_multi_item_form($form, $form_state, $element, "${base_id}-array", $data, array( 
        'form_handler' => 'coral_data_array_form',
        'form_args'    => array(),
        'column_names' => array('value'),
        'column_order' => array('value')
      ));   
    }
    elseif ($format == CORAL_TYPE_HASH) {
      $addons['data'] = coral_multi_item_form($form, $form_state, $element, "${base_id}-hash", $data, array( 
        'form_handler' => 'coral_data_hash_form',
        'form_args'    => array(),
        'column_names' => array('key', 'value'),
        'column_order' => array('key', 'value')
      ));
    }
  }
  return coral_form_wrapper($addons, array(), $ajax_wrapper);
}

/**
 * Return a multiple item array form. (default implementation)
 */
function coral_data_array_form(&$form, &$form_state, $element, $base_id, $item, $index) {
  $addons['value'] = coral_form_element(2, array(
      '#type'          => 'coral_data',
      '#title'         => t('Value'),
      '#default_value' => (isset($item['value']) ? $item['value'] : NULL)  
    ),
    "${base_id}-value", 
    'coral-array-value-form', 
    'coral-array-value'
  );
  return coral_form_wrapper($addons, 'container-inline');
}

/**
 * Return a multiple item hash form. (default implementation)
 */
function coral_data_hash_form(&$form, &$form_state, $element, $base_id, $item, $index) {
  $addons['key'] = coral_form_element(1, array(
      '#type'          => 'textfield',
      '#title'         => t('Key'),
      '#required'      => FALSE,
      '#default_value' => (isset($item['key']) ? $item['key'] : NULL) 
    ),
    "${base_id}-key", 
    'coral-hash-key-form', 
    'coral-hash-key'
  );
  $addons['value'] = coral_form_element(2, array(
      '#type'          => 'coral_data',
      '#title'         => t('Value'),
      '#default_value' => (isset($item['value']) ? $item['value'] : NULL)
    ),
    "${base_id}-value", 
    'coral-hash-value-form', 
    'coral-hash-value'
  );
  return coral_form_wrapper($addons, 'container-inline');
}

/**
 * After build function to process the coral_data element values.
 */
function coral_data_after_build($element, &$form_state) {  
  if ($form_state['process_input']) {
    $input  = drupal_array_get_nested_value($form_state['input'], $element['#parents']);
    $values = drupal_array_get_nested_value($form_state['values'], $element['#array_parents']);
    
    //dpm($input, 'coral_data_after_build -> $input');
    //dpm($values, 'coral_data_after_build -> $values');
    
    drupal_array_set_nested_value($form_state['input'], $element['#parents'], Coral::normalize($input));
    drupal_array_set_nested_value($form_state['values'], $element['#array_parents'], Coral::normalize($values));
  }
  //dpm($element, 'coral_data_after_build -> $element');
  //dpm($form_state, 'coral_data_after_build -> $form_state');
  return $element;
}

/**
 * An #element_validate callback for the coral_data element.
 */
function coral_data_validate(&$element, &$form_state) {
  //dpm($element, 'coral_data_validate -> $element');
  //dpm($form_state, 'coral_data_validate -> $form_state');
}

/**
 * Returns HTML for a coral_data element.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: A render element representing the data object.
 *
 * @ingroup themeable
 */
function theme_coral_data($variables) {
  $element = $variables['element'];

  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = (array) $element['#attributes']['class'];
  }
  $attributes['class'][] = 'form-coral-data-wrapper';

  // This wrapper is required to apply JS behaviors and CSS styling.
  $output = '';
  $output .= '<div' . drupal_attributes($attributes) . '>';
  $output .= drupal_render_children($element);
  $output .= '</div>';
  return $output;
}

/**
 * Ajax callback in response to a format selection.
 *
 * This returns the new page content to replace the page content made obsolete
 * by the form submission.
 */
function coral_data_format_ajax_callback($form, $form_state) {
  $format_select  = $form_state['triggering_element'];
  $element        = drupal_array_get_nested_value($form, array_slice($format_select['#array_parents'], 0, -1));
  
  watchdog('coral_data_format_ajax_callback -> $form', print_r($form, TRUE));
  watchdog('coral_data_format_ajax_callback -> $format_select', print_r($format_select, TRUE));
  watchdog('coral_data_format_ajax_callback -> $element', print_r($element, TRUE));
  
  return $element;
}


