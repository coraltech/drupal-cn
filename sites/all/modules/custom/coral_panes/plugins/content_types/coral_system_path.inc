<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Coral system path'),
  'icon' => 'icon_page.png',
  'description' => t('Display the system path of this item'),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node')
  ),
  'category' => t('Coral'),
  'edit form' => 'coral_system_path_pane_content_type_edit_form',    // Edit form callback
  'render callback'  => 'coral_system_path_pane_content_type_render',
  'defaults' => array(),
);

/**
 * Output function for the 'page_title' content type.
 *
 * Outputs the page title of the current page.
 */
function coral_system_path_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  $block = new stdClass();
  $block->content = '';

  foreach ($context as $indx => $ctxt) {
    if ($ctxt->plugin == 'entity:node' && $ctxt->identifier == 'This node') {
      $node = $ctxt->data;
      $author = user_load($node->uid);
      $author = theme('username', array('account' => $author));
      $proj_type = field_get_items('node', $node, 'field_project_type');
      if (isset($proj_type)) {
        $proj_type = strtolower(token_replace('[node:field_project_type]', array('node' => $node)));
        $title = l(strtolower(token_replace('[node:field_system_name]', array('node' => $node))), 'node/'.$node->nid);
        $scan = token_scan($title);
        if (isset($scan['node']['field_system_name'])) {
          $title = l(preg_replace('/\s+/', '_', strtolower($node->title)), 'node/'.$node->nid);
        }
      }
      $block->content = $author.'<span class="mdgray">/</span><span class="strong mdgray">'.$proj_type.'</span><span class="mdgray">/</span>'.$title;
    }
  }
  return $block;
}

function coral_system_path_pane_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function coral_system_path_pane_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

