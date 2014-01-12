<?php
/**
 * @file
 * slideshow.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function slideshow_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function slideshow_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function slideshow_node_info() {
  $items = array(
    'slideset' => array(
      'name' => t('Slideset'),
      'base' => 'node_content',
      'description' => t('Displays a list of media or image slides.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
