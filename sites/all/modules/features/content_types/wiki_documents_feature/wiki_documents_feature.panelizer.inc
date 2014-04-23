<?php
/**
 * @file
 * wiki_documents_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function wiki_documents_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:book:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'book';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'mosaic_landing_responsive';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'leader' => NULL,
      'main' => NULL,
      'secondary' => NULL,
      'follower' => NULL,
      'sub_footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'e1cadefc-9a28-491e-9840-cc4f352f87a2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2f25f902-f01c-40c6-9bef-b9e1ed2f795c';
    $pane->panel = 'leader';
    $pane->type = 'coral_community_tabs';
    $pane->subtype = 'coral_community_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'active_tab' => '0',
      'override_title' => 0,
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
    $pane->uuid = '2f25f902-f01c-40c6-9bef-b9e1ed2f795c';
    $display->content['new-2f25f902-f01c-40c6-9bef-b9e1ed2f795c'] = $pane;
    $display->panels['leader'][0] = 'new-2f25f902-f01c-40c6-9bef-b9e1ed2f795c';
    $pane = new stdClass();
    $pane->pid = 'new-6e759a37-ac53-4ba3-9ae8-d090f287a9b5';
    $pane->panel = 'leader';
    $pane->type = 'coral_breadcrumb';
    $pane->subtype = 'coral_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'append_title' => 1,
      'override_title' => 1,
      'override_title_text' => '',
      'link_title' => 0,
      'prefix' => 'You are here:  ',
      'remove_home' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6e759a37-ac53-4ba3-9ae8-d090f287a9b5';
    $display->content['new-6e759a37-ac53-4ba3-9ae8-d090f287a9b5'] = $pane;
    $display->panels['leader'][1] = 'new-6e759a37-ac53-4ba3-9ae8-d090f287a9b5';
    $pane = new stdClass();
    $pane->pid = 'new-d8e7190c-71f4-42ed-be68-beb7c57e1a6e';
    $pane->panel = 'main';
    $pane->type = 'coral_wiki_ask_question';
    $pane->subtype = 'coral_wiki_ask_question';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
      ),
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'top',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd8e7190c-71f4-42ed-be68-beb7c57e1a6e';
    $display->content['new-d8e7190c-71f4-42ed-be68-beb7c57e1a6e'] = $pane;
    $display->panels['main'][0] = 'new-d8e7190c-71f4-42ed-be68-beb7c57e1a6e';
    $pane = new stdClass();
    $pane->pid = 'new-3a6447f6-215d-495d-9a73-f040a2b8f8f5';
    $pane->panel = 'main';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => 'page-title',
      'context' => 'panelizer',
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
    $pane->uuid = '3a6447f6-215d-495d-9a73-f040a2b8f8f5';
    $display->content['new-3a6447f6-215d-495d-9a73-f040a2b8f8f5'] = $pane;
    $display->panels['main'][1] = 'new-3a6447f6-215d-495d-9a73-f040a2b8f8f5';
    $pane = new stdClass();
    $pane->pid = 'new-89057c05-7e5e-4d96-a3e5-248a23724fdd';
    $pane->panel = 'main';
    $pane->type = 'coral_node_stats';
    $pane->subtype = 'coral_node_stats';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => FALSE,
      'context' => array(
        0 => 'panelizer',
      ),
      'override_title' => 1,
      'override_title_text' => '',
      'display_stats' => array(
        2 => '2',
        3 => '3',
        5 => '5',
        6 => '6',
        7 => '7',
        1 => 0,
        4 => 0,
        8 => 0,
      ),
      'display_style' => '2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '89057c05-7e5e-4d96-a3e5-248a23724fdd';
    $display->content['new-89057c05-7e5e-4d96-a3e5-248a23724fdd'] = $pane;
    $display->panels['main'][2] = 'new-89057c05-7e5e-4d96-a3e5-248a23724fdd';
    $pane = new stdClass();
    $pane->pid = 'new-57efbfa6-7fe7-4ce9-915f-81f831d40537';
    $pane->panel = 'main';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full_node',
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '57efbfa6-7fe7-4ce9-915f-81f831d40537';
    $display->content['new-57efbfa6-7fe7-4ce9-915f-81f831d40537'] = $pane;
    $display->panels['main'][3] = 'new-57efbfa6-7fe7-4ce9-915f-81f831d40537';
    $pane = new stdClass();
    $pane->pid = 'new-33699525-4ec5-424d-8e11-57aca637ca31';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'sharethis-sharethis_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Share | ',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '33699525-4ec5-424d-8e11-57aca637ca31';
    $display->content['new-33699525-4ec5-424d-8e11-57aca637ca31'] = $pane;
    $display->panels['main'][4] = 'new-33699525-4ec5-424d-8e11-57aca637ca31';
    $pane = new stdClass();
    $pane->pid = 'new-c68080f0-081b-4e8f-933f-7d3fef3014b4';
    $pane->panel = 'secondary';
    $pane->type = 'block';
    $pane->subtype = 'book_explorer-book_explorer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Topics',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c68080f0-081b-4e8f-933f-7d3fef3014b4';
    $display->content['new-c68080f0-081b-4e8f-933f-7d3fef3014b4'] = $pane;
    $display->panels['secondary'][0] = 'new-c68080f0-081b-4e8f-933f-7d3fef3014b4';
    $pane = new stdClass();
    $pane->pid = 'new-31ac586e-1a48-49ca-8eec-aa95f24b6df4';
    $pane->panel = 'secondary';
    $pane->type = 'views_panes';
    $pane->subtype = 'related_qa-small_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '31ac586e-1a48-49ca-8eec-aa95f24b6df4';
    $display->content['new-31ac586e-1a48-49ca-8eec-aa95f24b6df4'] = $pane;
    $display->panels['secondary'][1] = 'new-31ac586e-1a48-49ca-8eec-aa95f24b6df4';
    $pane = new stdClass();
    $pane->pid = 'new-c12afa0a-2b26-4216-a14f-52ae15bf62b1';
    $pane->panel = 'secondary';
    $pane->type = 'coral_authors';
    $pane->subtype = 'coral_authors';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c12afa0a-2b26-4216-a14f-52ae15bf62b1';
    $display->content['new-c12afa0a-2b26-4216-a14f-52ae15bf62b1'] = $pane;
    $display->panels['secondary'][2] = 'new-c12afa0a-2b26-4216-a14f-52ae15bf62b1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:book:default'] = $panelizer;

  return $export;
}