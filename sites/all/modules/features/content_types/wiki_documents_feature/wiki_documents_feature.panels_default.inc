<?php
/**
 * @file
 * wiki_documents_feature.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function wiki_documents_feature_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'book_timeline';
  $mini->category = '';
  $mini->admin_title = 'Book timeline';
  $mini->admin_description = 'Components for a book timeline (title + timeline)';
  $mini->requiredcontexts = array(
    0 => array(
      'identifier' => 'Node',
      'keyword' => 'node',
      'name' => 'entity:node',
      'entity_id' => '',
      'id' => 1,
    ),
  );
  $mini->contexts = array();
  $mini->relationships = array();
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
  $display->title = '';
  $display->uuid = 'e92bb372-613d-4835-9b15-17abc0607d8f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-676c1138-cada-44e8-a35a-ab09720c575b';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_timeline_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'requiredcontext_entity:node_1',
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
    $pane->uuid = '676c1138-cada-44e8-a35a-ab09720c575b';
    $display->content['new-676c1138-cada-44e8-a35a-ab09720c575b'] = $pane;
    $display->panels['middle'][0] = 'new-676c1138-cada-44e8-a35a-ab09720c575b';
    $pane = new stdClass();
    $pane->pid = 'new-f30b2d85-70e5-4a3d-86bb-c077b205f264';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_book_timeline';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'field_collection_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'edit' => '',
        'delete' => '',
        'add' => '',
        'description' => 0,
        'view_mode' => 'full',
      ),
      'context' => 'requiredcontext_entity:node_1',
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
    $pane->uuid = 'f30b2d85-70e5-4a3d-86bb-c077b205f264';
    $display->content['new-f30b2d85-70e5-4a3d-86bb-c077b205f264'] = $pane;
    $display->panels['middle'][1] = 'new-f30b2d85-70e5-4a3d-86bb-c077b205f264';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-676c1138-cada-44e8-a35a-ab09720c575b';
  $mini->display = $display;
  $export['book_timeline'] = $mini;

  return $export;
}
