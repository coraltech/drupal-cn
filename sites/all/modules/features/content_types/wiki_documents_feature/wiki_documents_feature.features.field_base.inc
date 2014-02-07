<?php
/**
 * @file
 * wiki_documents_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function wiki_documents_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_locked'
  $field_bases['field_locked'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_locked',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Unlock',
        1 => 'Lock',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
