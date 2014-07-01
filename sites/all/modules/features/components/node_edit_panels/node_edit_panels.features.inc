<?php
/**
 * @file
 * node_edit_panels.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function node_edit_panels_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
