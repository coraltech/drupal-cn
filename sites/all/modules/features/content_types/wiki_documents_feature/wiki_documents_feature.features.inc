<?php
/**
 * @file
 * wiki_documents_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function wiki_documents_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function wiki_documents_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function wiki_documents_feature_node_info() {
  $items = array(
    'book' => array(
      'name' => t('Wiki page'),
      'base' => 'node_content',
      'description' => t('<em>Wiki pages</em> have a built-in hierarchical navigation. Use for community handbooks or tutorials.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
