<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('User edit link'),
  'icon' => 'icon_user.png',
  'description' => t('User profile edit link user.'),
  'required context' => new ctools_context_required(t('User'), 'user'),
  'render callback' => 'coral_user_edit_link_content_type_render',
  'category' => t('User'),
);

function coral_user_edit_link_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;

  if (empty($context->data)) {
    return;
  }

  $account = clone $context->data;

  $link = '';
  if ($user->uid == $account->uid) {
    $link = l('Edit profile', 'user/'.$account->uid.'/edit');
  }

  $block->content = $link;
  return $block;
}

/**
 * Display the administrative title for a panel pane in the drag & drop UI
 */
function coral_user_edit_link_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" user picture', array('@s' => $context->identifier));
}

function coral_user_edit_link_content_type_edit_form($form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
  return $form;
}
