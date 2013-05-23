<?php
//------------------------------------------------------------------------------
// Fields

/**
 * Return a list of the Coral base field classes.
 */
function coral_field_classes() {
  return array(
    'field' => array(
      CoralOptionField::type()     => 'CoralOptionField',
      CoralValidationField::type() => 'CoralValidationField',
      CoralPropertyField::type()   => 'CoralPropertyField'
    )
  );
}

/**
 * Implements hook_permission().
 */
function coral_field_permission() {
  $perms = array();
  foreach (coral_classes('field') as $type => $class) {
    $perms += Coral::exec($class, 'permissions', array(), array());
  }
  return $perms;
}

/**
 * Implements hook_theme().
 */
function coral_field_theme() {
  $themes = array();
  foreach (coral_classes('field') as $type => $class) {
    $themes += Coral::exec($class, 'theme', array(), array());
  }
  return $themes;
}

/**
 * Implements hook_field_info().
 */
function coral_field_info() {
  $results = array();
  foreach (coral_classes('field') as $type => $class) {
    $results[$type] = Coral::exec($class, 'info', array(), array());
  }
  return $results;
}

/**
 * Implements hook_field_is_empty().
 */
function coral_field_is_empty($item, $field) {
  $class = coral_class('field', $field['type']);
  return Coral::exec($class, 'itemEmpty', array($item), TRUE);
}

/**
 * Implements hook_field_settings_form().
 */
function coral_field_settings_form($field, $instance, $has_data) {
  $class = coral_class('field', $field['type']);
  return Coral::exec($class, 'settingsForm', array($field, $instance, $has_data), array());
}

/**
 * Implements hook_field_instance_settings_form().
 */
function coral_field_instance_settings_form($field, $instance) {
  $class = coral_class('field', $field['type']);
  return Coral::exec($class, 'instanceSettingsForm', array($field, $instance), array());
}

/**
 * Implements hook_field_load().
 */
function coral_field_load($entity_type, $entities, $field, $instances, $langcode, &$items, $age) {
  if ($class = coral_class('field', $field['type'])) {
    dpm($items, 'coral_field_load -> $items');
    foreach ($entities as $id => $entity) {
      dpm($id, 'coral_field_load -> $id');
      dpm($entity, 'coral_field_load -> $entity');
      if (isset($items[$id])) {
        $coral_field = Coral::create($class, array(
          'entity'   => $entity,
          'field'    => $field,
          'instance' => $instances[$id],
          'items'    => &$items[$id]
        ));
        Coral::exec($coral_field, 'load', array($langcode, $age));
        dpm($items[$id], 'coral_field_load -> $items[$id]');
      }
    }
  }
}

/**
 * Implements hook_field_validate().
 */
function coral_field_validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {
  dpm($items, 'coral_field_validate -> $items');
  if ($class = coral_class('field', $field['type'])) {
    $coral_field = Coral::create($class, array(
      'entity'   => $entity,
      'field'    => $field,
      'instance' => $instance,
      'items'    => $items
    ));
    Coral::exec($coral_field, 'validate', array(&$errors[$field['field_name']][$langcode], $langcode));
  }
}

/**
 * Implements hook_field_presave().
 */
function coral_field_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  dpm($items, 'coral_field_presave -> $items');
  if ($class = coral_class('field', $field['type'])) {
    $coral_field = Coral::create($class, array(
      'entity'   => $entity,
      'field'    => $field,
      'instance' => $instance,
      'items'    => &$items
    ));
    Coral::exec($coral_field, 'presave', array($langcode));
    $entity->{$field['field_name']}[$langcode] = $items;
    dpm($items, 'coral_field_presave -> $items');
  }
}

/**
 * Implements hook_field_insert().
 */
function coral_field_insert($entity_type, $entity, $field, $instance, $langcode, &$items) {
  dpm($items, 'coral_field_insert -> $items');
  if ($class = coral_class('field', $field['type'])) {
    $coral_field = Coral::create($class, array(
      'entity'   => $entity,
      'field'    => $field,
      'instance' => $instance,
      'items'    => &$items
    ));
    Coral::exec($coral_field, 'insert', array($langcode));
  }
  $context = array(
    'entity_type' => $entity_type,
    'entity'      => $entity,
    'field'       => $field,
    'instance'    => $instance,
    'langcode'    => $langcode,
  );
  drupal_alter('coral_field_insert', $items, $context);
}

/**
 * Implements hook_field_update().
 */
function coral_field_update($entity_type, $entity, $field, $instance, $langcode, &$items) {
  dpm($items, 'coral_field_update -> $items');
  if ($class = coral_class('field', $field['type'])) {
    $coral_field = Coral::create($class, array(
      'entity'   => $entity,
      'field'    => $field,
      'instance' => $instance,
      'items'    => &$items
    ));
    Coral::exec($coral_field, 'update', array($langcode));
  }
  $context = array(
    'entity_type' => $entity_type,
    'entity'      => $entity,
    'field'       => $field,
    'instance'    => $instance,
    'langcode'    => $langcode,
  );
  drupal_alter('coral_field_update', $items, $context);
}

/**
 * Implements hook_field_extra_fields().
 */
function coral_field_extra_fields() {
  $extra_fields = array();
  foreach (coral_classes('node') as $type => $class) {
    $extra_fields['node'][$type] = Coral::exec($class, 'extraFields', array(), array());
  }
  return $extra_fields;
}
