<?php
/**
 * @file
 * coral_projects_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function coral_projects_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function coral_projects_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function coral_projects_feature_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('A project node is used for listing Coral framework components.'),
      'has_title' => '1',
      'title_label' => t('Project name'),
      'help' => '',
    ),
    'project_group' => array(
      'name' => t('Project group'),
      'base' => 'node_content',
      'description' => t('Provides a central node to collect sets of projects together.  '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
