<?php
//------------------------------------------------------------------------------
// Widgets

/**
 * Return a list of the Coral base widget classes.
 */
function coral_widget_classes() {
  return array(
    'widget' => array(
      CoralOptionDefaultWidget::type()     => 'CoralOptionDefaultWidget',
      CoralValidationDefaultWidget::type() => 'CoralValidationDefaultWidget',
      CoralPropertyDefaultWidget::type()   => 'CoralPropertyDefaultWidget'
    )
  );
}

/**
 * Implements hook_permission().
 */
function coral_widget_permission() {
  $perms = array();
  foreach (coral_classes('widget') as $type => $class) {
    $perms += Coral::exec($class, 'permissions', array(), array());
  }
  return $perms;
}

/**
 * Implements hook_theme().
 */
function coral_widget_theme() {
  $themes = array();
  foreach (coral_classes('widget') as $type => $class) {
    $themes += Coral::exec($class, 'theme', array(), array());
  }
  return $themes;
}

/**
 * Implements hook_field_widget_info().
 */
function coral_field_widget_info() {
  $results = array();
  foreach (coral_classes('widget') as $type => $class) {
    $results[$type] = Coral::exec($class, 'info', array(), array());
  }
  return $results;
}

/**
 * Implements hook_field_widget_settings_form().
 */
function coral_field_widget_settings_form($field, $instance) {
  $class = coral_class('widget', $instance['widget']['type']);
  return Coral::exec($class, 'settingsForm', array($field, $instance), array());
}

/**
 * Implements hook_field_widget_form().
 */
function coral_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  if ($class = coral_class('widget', $instance['widget']['type'])) {
    $coral_widget = Coral::create($class, array(
      'entity'   => $element['#entity'],
      'field'    => $field,
      'instance' => $instance,
      'items'    => $items
    ));
    return Coral::exec($coral_widget, 'form', array(&$form, &$form_state, $langcode, $delta, $element));
  }
}

/**
 * Implements hook_field_widget_error().
 */
function coral_field_widget_error($element, $error, $form, &$form_state) {
  dpm($element, 'coral_field_widget_error -> $element');
}
