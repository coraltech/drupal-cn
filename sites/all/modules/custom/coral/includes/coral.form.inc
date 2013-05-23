<?php

/**
 * Return a structured form element that can be wrapped in a div.
 */
function coral_form_element($weight, $element, $id = '', $form_classes = array(), $prefix_classes = array(), $prefix_id = '') {
  $attributes = array();
  
  if (empty($id)) {
    $id = (isset($element['#id']) ? $element['#id'] : '');
  }
  if (!empty($id)) {
    $attributes['id'] = drupal_html_id($id);
  }
  
  if (!empty($form_classes)) {
    if (!is_array($form_classes)) {
      $form_classes = array($form_classes);
    }
    $attributes['class'] = array_map('drupal_html_class', $form_classes);
  }
  
  $element = CoralData::merge($element, array(
    '#weight'     => $weight,
    '#attributes' => $attributes
  ));
  return coral_form_wrapper($element, $prefix_classes, $prefix_id);
}

/**
 * Return a form element wrapped in a id'd and/or classed div.
 */
function coral_form_wrapper($element, $classes = array(), $id = '') {
  if (!is_array($classes)) {
    $classes = array($classes);
  }
  
  $attributes = array();
  if (!empty($id)) {
    $attributes[] = ' id="' . drupal_html_id($id)  . '"';
  }
  if (!empty($classes)) {
    $attributes[] = ' class="' . implode(' ', array_map('drupal_html_class', $classes)) . '"';
  }
  
  if (!empty($attributes)) {
    $element['#prefix'] = '<div' . implode('', $attributes) . '>';
    $element['#suffix'] = '</div>';
  }
  return $element;
}

/**
 * Return a data multi item form (with new value and deletion support).
 */
function coral_multi_item_form(&$form, &$form_state, $element, $id, $items, $options = array()) {
  $module_path      = drupal_get_path('module', 'coral');
  $ajax_wrapper     = "${id}-wrapper"; 
  $classes          = Coral::ensureArray($options, 'classes');
  
  $form_handler     = Coral::get($options, 'form_handler', 'coral_data_form');
  $form_args        = Coral::ensureArray($options, 'form_args');
  $add_submit       = Coral::ensureArray($options, 'add_submit');
  $delete_submit    = Coral::ensureArray($options, 'delete_submit');
  
  $js_items         = array();
  $item_count       = count($items);
  
  if (!$item_count) {
    $items[0] = array();
  }  
  $columns          = Coral::ensureArray($options, 'column_names', array_keys($items[0]));
  $header_columns   = array_merge(array(t('weight')), $columns, array(''));
  $order            = Coral::ensureArray($options, 'column_order', array_keys($items[0]));
  $column_order     = array_merge(array(t('_weight')), $order, array(t('operations_wrapper')));
  
  $addons = coral_form_element(0, array(
      '#type'    => 'coral_table',
      '#tree'    => TRUE,
      '#header'  => $header_columns,
      '#regions' => array(
        'existing_data' => array(
          'message'    => ($item_count ? '' : t('Nothing has been added yet.')),
          'rows_order' => $column_order
        ),
        'new_data' => array(
          'title'      => t('Add'),
          'rows_order' => $column_order
        ),
      ),
    ),
    $id,
    array_merge(array('coral-table-form'), $classes),
    array(),
    $ajax_wrapper
  );
  $id = $addons['#attributes']['id'];
  
  for ($index = 1; $index <= $item_count; $index++) {
    $item   = (isset($items[$index]) ? $items[$index] : array());
    $params = array_merge(array(&$form, &$form_state, $element, $id, $item, $index), $form_args);
      
    if ($item_form = call_user_func_array($form_handler, $params)) {
      $addons[$index] = array(
        '#attributes' => array('class' => array('draggable')),
        '#region'     => 'existing_data'
      );
      $addons[$index]['_weight'] = coral_form_element(-100, array(
          '#type'          => 'textfield',
          '#title'         => t('Item weight'),
          '#title_display' => 'invisible',
          '#default_value' => (isset($item['_weight']) ? $item['_weight'] : -1),
          '#size'          => 3,
        ),
        "${id}-${index}-weight",
        array("${id}-weight", 'weight')
      );
      $addons[$index] += $item_form;
      if (empty($form_state['programmed'])) {
        $addons[$index]['operations_wrapper']['delete'] = coral_form_element(100, array(
            '#type'                    => 'submit',
            '#value'                   => t('Delete'),
            '#limit_validation_errors' => array(),
            '#submit'                  => array_merge(array('coral_form_ajax_submit'), $delete_submit),
            '#ajax'                    => array(
              'callback' => 'coral_form_operation_ajax_callback',
              'wrapper'  => $ajax_wrapper,
              'effect'   => 'fade',
            ),
          ),
          "${id}-${index}-delete",
          array("${id}-delete", 'delete-button')
        );
      }
      $js_items[$index] = $item;
    }
  }

  if (empty($form_state['programmed'])) {
    $new_index           = $item_count + 1;
    $params              = array_merge(array(&$form, &$form_state, $element, $id, array(), NULL), $form_args);
    $addons[$new_index] = array(
      '#attributes'      => array('class' => array('draggable', 'add-new')),
      '#region'          => 'new_data',
    );
    $addons[$new_index]['_weight'] = coral_form_element(-100, array(
        '#type'          => 'textfield',
        '#default_value' => $new_index,
        '#size'          => 3,
        '#title_display' => 'invisible',
        '#title'         => t('Weight for new item'),
        '#prefix'        => '<div class="add-new-placeholder">&nbsp;</div>',
      ),
      "${id}-new-weight",
      array("${id}-weight", 'weight')
    );
    $addons[$new_index] += call_user_func_array($form_handler, $params);
    $addons[$new_index]['operations_wrapper']['add'] = coral_form_element(100, array(
        '#type'                    => 'submit',
        '#value'                   => t('Add'),
        '#limit_validation_errors' => array(),
        '#submit'                  => array_merge(array('coral_form_ajax_submit'), $add_submit),
        '#ajax'                    => array(
          'callback' => 'coral_form_operation_ajax_callback',
          'wrapper'  => $ajax_wrapper,
          'effect'   => 'fade',
        ),
      ),
      "${id}-new-add",
      array("${id}-add", 'add-button')
    );
  }
    
  $addons['#attached']['css'][] = "${module_path}/css/coral_multi_item.css";
  $addons['#attached']['js'][]  = "${module_path}/js/coral_multi_item.js";
  $addons['#attached']['js'][]  = array(
    'type' => 'setting',
    'data' => array('coralMultiItemForm' => array("${id}-items" => $js_items)),
  );

  // Add tabledrag behavior.
  $addons['#attached']['drupal_add_tabledrag'][] = array($id, 'order', 'sibling', "${id}-weight");
  return $addons;
}

/**
 * Submit handler for the "Add" and "Delete" buttons of a coral_data form element.
 */
function coral_form_ajax_submit($form, &$form_state) {
  $button = $form_state['triggering_element'];
  
  watchdog('coral_form_delete_ajax_submit -> $form', print_r($form, TRUE));
  watchdog('coral_form_delete_ajax_submit -> $button', print_r($button, TRUE));
  
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax callback in response to a deletion or addition of a form element.
 *
 * This returns the new page content to replace the page content made obsolete
 * by the form submission.
 */
function coral_form_operation_ajax_callback($form, $form_state) {
  $button  = $form_state['triggering_element'];
  $element = drupal_array_get_nested_value($form, array_slice($button['#array_parents'], 0, -3));
  
  watchdog('coral_form_operation_ajax_callback -> $form', print_r($form, TRUE));
  watchdog('coral_form_operation_ajax_callback -> $button', print_r($button, TRUE));
  watchdog('coral_form_operation_ajax_callback -> $element', print_r($element, TRUE));
  
  return $element;
}

