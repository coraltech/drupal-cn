<?php
/**
 * @file
 * comment_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function comment_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function comment_content_type_node_info() {
  $items = array(
    'comment' => array(
      'name' => t('Comment'),
      'base' => 'node_content',
      'description' => t('A node based comment.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
