<?php
/**
 * @file
 * hybridauth_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function hybridauth_feature_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_hybridauth_panel_context';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'hybridauth';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'hybridauth',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Social identities';
  $display->uuid = 'de8820ca-567b-4541-8d6e-e26c45c26285';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b51a4959-7b33-4251-85cb-9646c76700d2';
    $pane->panel = 'middle';
    $pane->type = 'coral_page_title';
    $pane->subtype = 'coral_page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => 'page-title',
      'id' => 'page-title',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b51a4959-7b33-4251-85cb-9646c76700d2';
    $display->content['new-b51a4959-7b33-4251-85cb-9646c76700d2'] = $pane;
    $display->panels['middle'][0] = 'new-b51a4959-7b33-4251-85cb-9646c76700d2';
    $pane = new stdClass();
    $pane->pid = 'new-42982848-c266-4f72-bc2d-085417a6a788';
    $pane->panel = 'middle';
    $pane->type = 'pm_existing_pages';
    $pane->subtype = 'pm_existing_pages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      0 => 'task_id',
      1 => 'pane_title_from_menu',
      'task_id' => 'hybridauth',
      'pane_title_from_menu' => 0,
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '42982848-c266-4f72-bc2d-085417a6a788';
    $display->content['new-42982848-c266-4f72-bc2d-085417a6a788'] = $pane;
    $display->panels['middle'][1] = 'new-42982848-c266-4f72-bc2d-085417a6a788';
    $pane = new stdClass();
    $pane->pid = 'new-ee733ab6-6c9d-4464-9151-3638e16bd67c';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<small class="mdblue">powered by HybridAuth</small>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ee733ab6-6c9d-4464-9151-3638e16bd67c';
    $display->content['new-ee733ab6-6c9d-4464-9151-3638e16bd67c'] = $pane;
    $display->panels['middle'][2] = 'new-ee733ab6-6c9d-4464-9151-3638e16bd67c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b51a4959-7b33-4251-85cb-9646c76700d2';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_hybridauth_panel_context'] = $handler;

  return $export;
}
