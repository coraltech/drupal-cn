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
  $display->uuid = '6bf9384f-7ad0-4fdc-9a77-6ccd0ea56330';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-55262a57-5763-4326-8f02-9ea2cca420a8';
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
    $pane->uuid = '55262a57-5763-4326-8f02-9ea2cca420a8';
    $display->content['new-55262a57-5763-4326-8f02-9ea2cca420a8'] = $pane;
    $display->panels['leader'][0] = 'new-55262a57-5763-4326-8f02-9ea2cca420a8';
    $pane = new stdClass();
    $pane->pid = 'new-b3f0c8ff-02e6-4088-a413-24d18da88902';
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
    $pane->uuid = 'b3f0c8ff-02e6-4088-a413-24d18da88902';
    $display->content['new-b3f0c8ff-02e6-4088-a413-24d18da88902'] = $pane;
    $display->panels['leader'][1] = 'new-b3f0c8ff-02e6-4088-a413-24d18da88902';
    $pane = new stdClass();
    $pane->pid = 'new-515228b8-9ab0-4619-9c0f-c4976d305b2a';
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
    $pane->uuid = '515228b8-9ab0-4619-9c0f-c4976d305b2a';
    $display->content['new-515228b8-9ab0-4619-9c0f-c4976d305b2a'] = $pane;
    $display->panels['main'][0] = 'new-515228b8-9ab0-4619-9c0f-c4976d305b2a';
    $pane = new stdClass();
    $pane->pid = 'new-ed467599-061a-43f8-98a2-f5ef179463a7';
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
    $pane->uuid = 'ed467599-061a-43f8-98a2-f5ef179463a7';
    $display->content['new-ed467599-061a-43f8-98a2-f5ef179463a7'] = $pane;
    $display->panels['main'][1] = 'new-ed467599-061a-43f8-98a2-f5ef179463a7';
    $pane = new stdClass();
    $pane->pid = 'new-7080513d-fd94-4ada-97b1-81430d1e6838';
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
    $pane->uuid = '7080513d-fd94-4ada-97b1-81430d1e6838';
    $display->content['new-7080513d-fd94-4ada-97b1-81430d1e6838'] = $pane;
    $display->panels['main'][2] = 'new-7080513d-fd94-4ada-97b1-81430d1e6838';
    $pane = new stdClass();
    $pane->pid = 'new-1f272eae-5b30-4071-969b-db9e43c035b8';
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
    $pane->uuid = '1f272eae-5b30-4071-969b-db9e43c035b8';
    $display->content['new-1f272eae-5b30-4071-969b-db9e43c035b8'] = $pane;
    $display->panels['main'][3] = 'new-1f272eae-5b30-4071-969b-db9e43c035b8';
    $pane = new stdClass();
    $pane->pid = 'new-0bd10a22-d023-41fa-bd3b-5955d2b104bb';
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
    $pane->uuid = '0bd10a22-d023-41fa-bd3b-5955d2b104bb';
    $display->content['new-0bd10a22-d023-41fa-bd3b-5955d2b104bb'] = $pane;
    $display->panels['main'][4] = 'new-0bd10a22-d023-41fa-bd3b-5955d2b104bb';
    $pane = new stdClass();
    $pane->pid = 'new-941bfbae-12ce-490b-a936-7572204617e6';
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
    $pane->uuid = '941bfbae-12ce-490b-a936-7572204617e6';
    $display->content['new-941bfbae-12ce-490b-a936-7572204617e6'] = $pane;
    $display->panels['secondary'][0] = 'new-941bfbae-12ce-490b-a936-7572204617e6';
    $pane = new stdClass();
    $pane->pid = 'new-61eef53f-dfa5-4b83-a402-8f04eaafdd98';
    $pane->panel = 'secondary';
    $pane->type = 'views_panes';
    $pane->subtype = 'related_projects-related_node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '61eef53f-dfa5-4b83-a402-8f04eaafdd98';
    $display->content['new-61eef53f-dfa5-4b83-a402-8f04eaafdd98'] = $pane;
    $display->panels['secondary'][1] = 'new-61eef53f-dfa5-4b83-a402-8f04eaafdd98';
    $pane = new stdClass();
    $pane->pid = 'new-fe959289-c045-43b2-8b40-2a5a18426df6';
    $pane->panel = 'secondary';
    $pane->type = 'views_panes';
    $pane->subtype = 'related_snippets-related_node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'fe959289-c045-43b2-8b40-2a5a18426df6';
    $display->content['new-fe959289-c045-43b2-8b40-2a5a18426df6'] = $pane;
    $display->panels['secondary'][2] = 'new-fe959289-c045-43b2-8b40-2a5a18426df6';
    $pane = new stdClass();
    $pane->pid = 'new-906d8214-07f3-4ef0-8ebc-e3cde9f5c425';
    $pane->panel = 'secondary';
    $pane->type = 'views_panes';
    $pane->subtype = 'documentation-related_node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '906d8214-07f3-4ef0-8ebc-e3cde9f5c425';
    $display->content['new-906d8214-07f3-4ef0-8ebc-e3cde9f5c425'] = $pane;
    $display->panels['secondary'][3] = 'new-906d8214-07f3-4ef0-8ebc-e3cde9f5c425';
    $pane = new stdClass();
    $pane->pid = 'new-3cfbde87-4da2-4de8-999c-b848ed913c95';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '3cfbde87-4da2-4de8-999c-b848ed913c95';
    $display->content['new-3cfbde87-4da2-4de8-999c-b848ed913c95'] = $pane;
    $display->panels['secondary'][4] = 'new-3cfbde87-4da2-4de8-999c-b848ed913c95';
    $pane = new stdClass();
    $pane->pid = 'new-cf3e1fda-ebf7-46f1-a147-cb19d1402081';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'cf3e1fda-ebf7-46f1-a147-cb19d1402081';
    $display->content['new-cf3e1fda-ebf7-46f1-a147-cb19d1402081'] = $pane;
    $display->panels['secondary'][5] = 'new-cf3e1fda-ebf7-46f1-a147-cb19d1402081';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:book:default'] = $panelizer;

  return $export;
}
