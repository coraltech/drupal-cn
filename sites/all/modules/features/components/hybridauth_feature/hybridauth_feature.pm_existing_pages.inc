<?php
/**
 * @file
 * hybridauth_feature.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function hybridauth_feature_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'hybridauth';
  $pm_existing_page->label = 'HybridAuth';
  $pm_existing_page->context = 'entity|user|uid';
  $pm_existing_page->paths = 'user/%user/hybridauth';
  $export['hybridauth'] = $pm_existing_page;

  return $export;
}
