<?php
/**
 * @file
 * snippet_node_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function snippet_node_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_component_count'
  $field_bases['field_component_count'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_component_count',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
