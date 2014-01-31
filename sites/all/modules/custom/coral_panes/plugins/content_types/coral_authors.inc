<?php

/**
 * Custom plugin to provide node statistics and info on node
 *  related pages.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Coral authors'),
  'description' => t('Displays revision author images.'),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node')
  ),
  'category' => t('Coral'),
  'edit form' => 'coral_authors_pane_content_type_edit_form',    // Edit form callback
  'render callback'  => 'coral_authors_pane_content_type_render',
);


// Renderer - uses revision_cache module.
function coral_authors_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  $node = $context[0]->data; // get the node

  $revisions = revision_cache_revision_load($node);
  $revision_hist = array();

  // Get revisions
  foreach ($revisions as $id => $revision) {
    if (!isset($revision_hist[$revision->uid])) {
      $revision_hist[$revision->uid] = $revision->name;
    }
  }
  
  // Compile user images based on the revision history
  foreach ($revision_hist as $uid => $name) {
    $user = user_load($uid);

    if ($user->uid && $user->status) {
      $revision_hist[$uid] = coral_authors_compile_default_user_image($user, 'user_thumb_small', 'View profile of '.$name);
    }
  } 
  
  $block->title = t('Authors');
  $block->content = implode('', $revision_hist);
  return $block;
}


// Admin title
function coral_authors_pane_content_type_admin_title($subtype, $conf, $context) {
  return t('Node authors edit form');
}


// Configure form
function coral_authors_pane_content_type_edit_form($form, &$form_state) {
  // Saved configurations  
  $conf = $form_state['conf'];
  return $form;
}


// Save values
function coral_authors_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['display_stats'] = $form_state['values']['display_stats'];
}


// Compiles a user image - ripped from the mosaic theme (see preprocess.inc)
function coral_authors_compile_default_user_image($user, $image_style, $title) {
  $uri = 'public://coraltechiconlg.png'; // default image
  
  if (is_numeric($user)) $user = user_load($user);
  if (is_object($user) && $user->uid) {
    if (isset($user->picture->uri)) {
      $uri = $user->picture->uri;
    }
  } 
    
  return l(
    theme(
      'image_style', 
      array(
        'style_name' => $image_style,
        'path' => $uri,
        'title' => $title
      )
    ), 
    'user/'.$user->uid, // link path
    array('html' => 'true') // we have a pic
  );
}