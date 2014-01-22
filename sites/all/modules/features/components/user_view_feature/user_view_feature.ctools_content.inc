<?php
/**
 * @file
 * user_view_feature.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function user_view_feature_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'user_edit_link';
  $content->admin_title = 'User edit link';
  $content->admin_description = '';
  $content->category = 'User';
  $content->settings = array(
    'admin_title' => 'User edit link',
    'title' => '',
    'body' => '<a href="user/%user:uid/edit">Edit profile</a>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $export['user_edit_link'] = $content;

  return $export;
}
