<?php
/**
 * @file
 * projects_sections_minipanels.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function projects_sections_minipanels_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}
