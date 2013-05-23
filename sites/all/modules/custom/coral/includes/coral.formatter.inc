<?php
//------------------------------------------------------------------------------
// Formatters

/**
 * Return a list of the Coral formatter classes.
 */
function coral_formatter_classes() {
  return array(
    'formatter' => array(
      CoralOptionDefaultFormatter::type()     => 'CoralOptionDefaultFormatter',
      CoralValidationDefaultFormatter::type() => 'CoralValidationDefaultFormatter',
      CoralPropertyDefaultFormatter::type()   => 'CoralPropertyDefaultFormatter'
    )
  );
}

/**
 * Implements hook_permission().
 */
function coral_formatter_permission() {
  $perms = array();
  foreach (coral_classes('formatter') as $type => $class) {
    $perms += Coral::exec($class, 'permissions', array(), array());
  }
  return $perms;
}

/**
 * Implements hook_theme().
 */
function coral_formatter_theme() {
  $themes = array();
  foreach (coral_classes('formatter') as $type => $class) {
    $themes += Coral::exec($class, 'theme', array(), array());
  }
  return $themes;
}

/**
 * Implements hook_field_formatter_info().
 */
function coral_field_formatter_info() {
  $results = array();
  foreach (coral_classes('formatter') as $type => $class) {
    $results[$type] = Coral::exec($class, 'info', array(), array());
  }
  return $results;
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function coral_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $class = coral_class('formatter', coral_formatter_name($instance, $view_mode));
  $form  = Coral::exec($class, 'settingsForm', array($field, $instance, $view_mode, $form, &$form_state), array());
  
  $context = array(
    'field'     => $field,
    'instance'  => $instance,
    'view_mode' => $view_mode,
  );
  drupal_alter('coral_field_formatter_settings_form', $form, $form_state, $context);
  return $form;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function coral_field_formatter_settings_summary($field, $instance, $view_mode) {
  $class   = coral_class('formatter', coral_formatter_name($instance, $view_mode));
  $summary = Coral::exec($class, 'settingsSummary', array($field, $instance, $view_mode), '');
  
  $context = array(
    'field'     => $field,
    'instance'  => $instance,
    'view_mode' => $view_mode,
  );
  drupal_alter('coral_field_formatter_settings_summary', $summary, $context);
  return $summary;
}

/**
 * Implements hook_field_formatter_view().
 */
function coral_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $variables = array(
    'entity'      => $entity,
    'entity_type' => $entity_type,
    'field'       => $field,
    'instance'    => $instance,
    'langcode'    => $langcode,
    'items'       => $items,
    'display'     => $display,
    'dates'       => array(),
    'attributes'  => array(),
    'rdf_mapping' => array(),
    'add_rdf'     => module_exists('rdf'),
  );

  // If there is an RDf mapping for this field, pass it down to the theme.
  $rdf_mapping = array();
  if (!empty($entity->rdf_mapping) && function_exists('rdf_rdfa_attributes')) {
    if (!empty($entity->rdf_mapping[$field['field_name']])) {
      $variables['rdf_mapping'] = $rdf_mapping = $entity->rdf_mapping[$field['field_name']];
    }
  }

  // Give other modules a chance to prepare the entity before formatting it.
  drupal_alter('coral_formatter_pre_view', $entity, $variables);

  if ($class = coral_class('formatter', $display['type'])) {
    $coral_formatter = Coral::create($class, array(
      'entity'   => $entity,
      'field'    => $field,
      'instance' => $instance,
      'items'    => $items
    ));
  }
  return Coral::exec($coral_formatter, 'view', array($langcode, $display), array());
}

/**
 * Return a formatter name for a given instance and view mode.
 */
function coral_formatter_name($instance, $view_mode) {
  $view_mode_settings = field_view_mode_settings($instance['entity_type'], $instance['bundle']);
  $actual_mode        = (!empty($view_mode_settings[$view_mode]['custom_settings']) ? $view_mode : 'default');
  return $instance['display'][$actual_mode]['type'];
}
