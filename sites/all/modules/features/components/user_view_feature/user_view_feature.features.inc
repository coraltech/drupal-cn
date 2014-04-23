<?php
/**
 * @file
 * user_view_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function user_view_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ctools_custom_content" && $api == "ctools_content") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function user_view_feature_views_api($module = NULL, $api = NULL) {
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
      4 => 'project',
      5 => 'question',
      6 => 'snippet',
      7 => 'book',
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
    'module' => 'user_view_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function user_view_feature_image_default_styles() {
  $styles = array();

  // Exported image style: user_thumb_small.
  $styles['user_thumb_small'] = array(
    'name' => 'user_thumb_small',
    'label' => 'user_thumb_small',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 30,
          'height' => 30,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
