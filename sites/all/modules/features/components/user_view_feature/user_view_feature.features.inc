<?php
/**
 * @file
 * user_view_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function user_view_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ctools_custom_content" && $api == "ctools_content") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function user_view_feature_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function user_view_feature_flag_default_flags() {
  $flags = array();
  // Exported flag: "Follow this content".
  $flags['follow'] = array(
    'content_type' => 'node',
    'title' => 'Follow this content',
    'global' => 0,
    'types' => array(
      0 => 'answer',
      1 => 'comment',
      2 => 'configuration',
      3 => 'format',
      4 => 'question',
      5 => 'book',
    ),
    'flag_short' => 'Follow',
    'flag_long' => 'Follow this content',
    'flag_message' => 'Content is followed',
    'unflag_short' => 'Unfollow',
    'unflag_long' => 'Unfollow this content',
    'unflag_message' => 'Content is unfollowed',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => 2,
      ),
      'unflag' => array(
        0 => 2,
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'user_view_feature',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}
