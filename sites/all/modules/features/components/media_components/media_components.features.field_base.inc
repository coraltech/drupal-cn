<?php
/**
 * @file
 * media_components.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function media_components_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'media'
  $field_bases['media'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'media',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'allowed_schemes' => array(
        0 => 'public',
        1 => 'private',
      ),
      'allowed_types' => array(
        0 => 'image',
        1 => 'media',
      ),
      'display_default' => 0,
      'display_field' => 0,
      'progress_indicator' => 'throbber',
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  return $field_bases;
}
