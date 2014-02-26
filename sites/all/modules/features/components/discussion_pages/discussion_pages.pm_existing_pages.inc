<?php
/**
 * @file
 * discussion_pages.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function discussion_pages_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'node_talk';
  $pm_existing_page->label = 'Node talk';
  $pm_existing_page->context = 'entity|node|nid';
  $pm_existing_page->paths = 'node/%node/talk';
  $export['node_talk'] = $pm_existing_page;

  return $export;
}
