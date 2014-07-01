<?php
/**
 * @file
 * section_intro_node_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function section_intro_node_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function section_intro_node_type_image_default_styles() {
  $styles = array();

  // Exported image style: project_logo_md.
  $styles['project_logo_md'] = array(
    'name' => 'project_logo_md',
    'label' => 'Project logo 150x150',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 150,
          'height' => '',
          'upscale' => 1,
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
function section_intro_node_type_node_info() {
  $items = array(
    'section_intro' => array(
      'name' => t('Section intro'),
      'base' => 'node_content',
      'description' => t('The section intro content type is used to add a blurb or other info onto other pages. Add these nodes via panelizer.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
