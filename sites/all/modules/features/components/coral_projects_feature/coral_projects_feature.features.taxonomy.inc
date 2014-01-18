<?php
/**
 * @file
 * coral_projects_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function coral_projects_feature_taxonomy_default_vocabularies() {
  return array(
    'project_type' => array(
      'name' => 'Project type',
      'machine_name' => 'project_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
