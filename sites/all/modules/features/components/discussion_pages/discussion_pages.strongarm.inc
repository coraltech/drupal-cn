<?php
/**
 * @file
 * discussion_pages.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function discussion_pages_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_talk_book';
  $strongarm->value = 1;
  $export['comment_talk_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_talk_snippet';
  $strongarm->value = 1;
  $export['comment_talk_snippet'] = $strongarm;

  return $export;
}
