<?php
/**
 * @file
 * question_node_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function question_node_type_ctools_plugin_api($module = NULL, $api = NULL) {
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
function question_node_type_node_info() {
  $items = array(
    'question' => array(
      'name' => t('Question'),
      'base' => 'node_content',
      'description' => t('A <em>Questions</em> is a content type used to query the community for information or input.'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
  );
  return $items;
}
