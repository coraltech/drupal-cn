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
 * Implements hook_image_default_styles().
 */
function coral_projects_feature_image_default_styles() {
  $styles = array();

  // Exported image style: project_logo_lg.
  $styles['project_logo_lg'] = array(
    'name' => 'project_logo_lg',
    'label' => 'Project logo lg',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 200,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
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
  drupal_alter('node_info', $items);
  return $items;
}
