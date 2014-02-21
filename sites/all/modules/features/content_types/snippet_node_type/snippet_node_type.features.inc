<?php
/**
 * @file
 * snippet_node_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function snippet_node_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
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
function snippet_node_type_node_info() {
  $items = array(
    'snippet' => array(
      'name' => t('Snippet'),
      'base' => 'node_content',
      'description' => t('A snippet is a set of COR related code blocks that together do something useful.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
