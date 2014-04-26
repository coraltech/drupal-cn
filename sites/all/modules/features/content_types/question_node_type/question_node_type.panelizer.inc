<?php
/**
 * @file
 * question_node_type.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function question_node_type_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:question:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'question';
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'leader' => NULL,
      'main' => NULL,
      'secondary' => NULL,
      'follower' => NULL,
      'sub_footer' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'cc9c20a3-08b1-454c-a8ec-67be42c35a64';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e80d778b-a574-4604-93a2-02c90b6ed9d7';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'questions-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'nid' => '%node:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e80d778b-a574-4604-93a2-02c90b6ed9d7';
    $display->content['new-e80d778b-a574-4604-93a2-02c90b6ed9d7'] = $pane;
    $display->panels['middle'][0] = 'new-e80d778b-a574-4604-93a2-02c90b6ed9d7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:question:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:question:default:full_node';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'question';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'full_node';
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
  $display->title = '';
  $display->uuid = '941e8bfe-184f-4ad3-b6de-2d15264d7f0d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-62f14548-9a77-4b35-850a-588730a9bba0';
    $pane->panel = 'leader';
    $pane->type = 'coral_community_tabs';
    $pane->subtype = 'coral_community_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'active_tab' => '1',
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
    $pane->uuid = '62f14548-9a77-4b35-850a-588730a9bba0';
    $display->content['new-62f14548-9a77-4b35-850a-588730a9bba0'] = $pane;
    $display->panels['leader'][0] = 'new-62f14548-9a77-4b35-850a-588730a9bba0';
    $pane = new stdClass();
    $pane->pid = 'new-47593d27-f0e8-4492-96e3-f05ecc845cfe';
    $pane->panel = 'main';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'teaser',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '47593d27-f0e8-4492-96e3-f05ecc845cfe';
    $display->content['new-47593d27-f0e8-4492-96e3-f05ecc845cfe'] = $pane;
    $display->panels['main'][0] = 'new-47593d27-f0e8-4492-96e3-f05ecc845cfe';
    $pane = new stdClass();
    $pane->pid = 'new-5c51aff0-d6dc-4003-9d23-29b286bed2c0';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5c51aff0-d6dc-4003-9d23-29b286bed2c0';
    $display->content['new-5c51aff0-d6dc-4003-9d23-29b286bed2c0'] = $pane;
    $display->panels['main'][1] = 'new-5c51aff0-d6dc-4003-9d23-29b286bed2c0';
    $pane = new stdClass();
    $pane->pid = 'new-b862cbf6-e619-4263-a3da-01231a702fa0';
    $pane->panel = 'secondary';
    $pane->type = 'coral_tag_search';
    $pane->subtype = 'coral_tag_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'b862cbf6-e619-4263-a3da-01231a702fa0';
    $display->content['new-b862cbf6-e619-4263-a3da-01231a702fa0'] = $pane;
    $display->panels['secondary'][0] = 'new-b862cbf6-e619-4263-a3da-01231a702fa0';
    $pane = new stdClass();
    $pane->pid = 'new-801c0ba1-48fd-459a-b4fc-5d70949f75ab';
    $pane->panel = 'secondary';
    $pane->type = 'views_panes';
    $pane->subtype = 'tags_popular-popular_question_tags';
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
    $pane->uuid = '801c0ba1-48fd-459a-b4fc-5d70949f75ab';
    $display->content['new-801c0ba1-48fd-459a-b4fc-5d70949f75ab'] = $pane;
    $display->panels['secondary'][1] = 'new-801c0ba1-48fd-459a-b4fc-5d70949f75ab';
    $pane = new stdClass();
    $pane->pid = 'new-49afa458-39a9-42ef-9d9c-de76647fa5ec';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '49afa458-39a9-42ef-9d9c-de76647fa5ec';
    $display->content['new-49afa458-39a9-42ef-9d9c-de76647fa5ec'] = $pane;
    $display->panels['secondary'][2] = 'new-49afa458-39a9-42ef-9d9c-de76647fa5ec';
    $pane = new stdClass();
    $pane->pid = 'new-f1d42555-640b-405f-9d5a-50cb425bc84e';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'f1d42555-640b-405f-9d5a-50cb425bc84e';
    $display->content['new-f1d42555-640b-405f-9d5a-50cb425bc84e'] = $pane;
    $display->panels['secondary'][3] = 'new-f1d42555-640b-405f-9d5a-50cb425bc84e';
    $pane = new stdClass();
    $pane->pid = 'new-8372db55-be6c-4351-a096-0a54f9d8b0cb';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '8372db55-be6c-4351-a096-0a54f9d8b0cb';
    $display->content['new-8372db55-be6c-4351-a096-0a54f9d8b0cb'] = $pane;
    $display->panels['secondary'][4] = 'new-8372db55-be6c-4351-a096-0a54f9d8b0cb';
    $pane = new stdClass();
    $pane->pid = 'new-28eada11-3cb2-4552-80e0-3cc446d284aa';
    $pane->panel = 'secondary';
    $pane->type = 'views_panes';
    $pane->subtype = 'related_qa-small_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '28eada11-3cb2-4552-80e0-3cc446d284aa';
    $display->content['new-28eada11-3cb2-4552-80e0-3cc446d284aa'] = $pane;
    $display->panels['secondary'][5] = 'new-28eada11-3cb2-4552-80e0-3cc446d284aa';
    $pane = new stdClass();
    $pane->pid = 'new-30682e35-9835-4e39-b363-025337b33015';
    $pane->panel = 'secondary';
    $pane->type = 'coral_featured_users';
    $pane->subtype = 'coral_featured_users';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'users_count' => '36',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '30682e35-9835-4e39-b363-025337b33015';
    $display->content['new-30682e35-9835-4e39-b363-025337b33015'] = $pane;
    $display->panels['secondary'][6] = 'new-30682e35-9835-4e39-b363-025337b33015';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:question:default:full_node'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:question:default:teaser';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'question';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'teaser';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'mosaic_node_1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'leader' => NULL,
      'main' => NULL,
      'secondary' => NULL,
      'follower' => NULL,
      'sub_footer' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'a772c561-f05e-4446-9983-05403ff440f7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c926ae0b-8cd6-486a-9aac-23c9b0ac7752';
    $pane->panel = 'follower';
    $pane->type = 'coral_answer_form';
    $pane->subtype = 'coral_answer_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
      ),
      'override_title' => 0,
      'override_title_text' => 'Testing',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c926ae0b-8cd6-486a-9aac-23c9b0ac7752';
    $display->content['new-c926ae0b-8cd6-486a-9aac-23c9b0ac7752'] = $pane;
    $display->panels['follower'][0] = 'new-c926ae0b-8cd6-486a-9aac-23c9b0ac7752';
    $pane = new stdClass();
    $pane->pid = 'new-eddd19d1-fb95-47a5-92c6-1ca49b74a9f0';
    $pane->panel = 'follower';
    $pane->type = 'coral_best_answer_target';
    $pane->subtype = 'coral_best_answer_target';
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
    $pane->uuid = 'eddd19d1-fb95-47a5-92c6-1ca49b74a9f0';
    $display->content['new-eddd19d1-fb95-47a5-92c6-1ca49b74a9f0'] = $pane;
    $display->panels['follower'][1] = 'new-eddd19d1-fb95-47a5-92c6-1ca49b74a9f0';
    $pane = new stdClass();
    $pane->pid = 'new-18786bde-d954-45d5-853c-2fd3fd117503';
    $pane->panel = 'follower';
    $pane->type = 'coral_answers_target';
    $pane->subtype = 'coral_answers_target';
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
    $pane->uuid = '18786bde-d954-45d5-853c-2fd3fd117503';
    $display->content['new-18786bde-d954-45d5-853c-2fd3fd117503'] = $pane;
    $display->panels['follower'][2] = 'new-18786bde-d954-45d5-853c-2fd3fd117503';
    $pane = new stdClass();
    $pane->pid = 'new-907fba80-fc88-4189-9477-74548280a748';
    $pane->panel = 'follower';
    $pane->type = 'coral_comment_form';
    $pane->subtype = 'coral_comment_form';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '907fba80-fc88-4189-9477-74548280a748';
    $display->content['new-907fba80-fc88-4189-9477-74548280a748'] = $pane;
    $display->panels['follower'][3] = 'new-907fba80-fc88-4189-9477-74548280a748';
    $pane = new stdClass();
    $pane->pid = 'new-de0ee3a7-fc6c-41ce-b8e1-4052b2415647';
    $pane->panel = 'follower';
    $pane->type = 'coral_comments_target';
    $pane->subtype = 'coral_comments_target';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'de0ee3a7-fc6c-41ce-b8e1-4052b2415647';
    $display->content['new-de0ee3a7-fc6c-41ce-b8e1-4052b2415647'] = $pane;
    $display->panels['follower'][4] = 'new-de0ee3a7-fc6c-41ce-b8e1-4052b2415647';
    $pane = new stdClass();
    $pane->pid = 'new-c0f9c1a1-583e-4de2-a086-3da699cf241e';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_summary_or_trimmed',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'trim_length' => '600',
      ),
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'body-trimmed',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c0f9c1a1-583e-4de2-a086-3da699cf241e';
    $display->content['new-c0f9c1a1-583e-4de2-a086-3da699cf241e'] = $pane;
    $display->panels['main'][0] = 'new-c0f9c1a1-583e-4de2-a086-3da699cf241e';
    $pane = new stdClass();
    $pane->pid = 'new-f0448c20-9041-4a07-89a9-c60a75005d38';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'trim_length' => 600,
      ),
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'body-full hide',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f0448c20-9041-4a07-89a9-c60a75005d38';
    $display->content['new-f0448c20-9041-4a07-89a9-c60a75005d38'] = $pane;
    $display->panels['main'][1] = 'new-f0448c20-9041-4a07-89a9-c60a75005d38';
    $pane = new stdClass();
    $pane->pid = 'new-4938492d-dee7-40a0-a60c-b06263bbdcba';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:file';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'file_table',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4938492d-dee7-40a0-a60c-b06263bbdcba';
    $display->content['new-4938492d-dee7-40a0-a60c-b06263bbdcba'] = $pane;
    $display->panels['main'][2] = 'new-4938492d-dee7-40a0-a60c-b06263bbdcba';
    $pane = new stdClass();
    $pane->pid = 'new-29a9f603-153b-4dcb-b2dc-87f0cd1f6053';
    $pane->panel = 'main';
    $pane->type = 'coral_node_stats';
    $pane->subtype = 'coral_node_stats';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => FALSE,
      'context' => array(
        0 => 'panelizer',
      ),
      'override_title' => 1,
      'override_title_text' => '',
      'display_stats' => array(
        1 => '1',
        2 => '2',
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
      ),
      'display_style' => '1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'right grid-12-last',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '29a9f603-153b-4dcb-b2dc-87f0cd1f6053';
    $display->content['new-29a9f603-153b-4dcb-b2dc-87f0cd1f6053'] = $pane;
    $display->panels['main'][3] = 'new-29a9f603-153b-4dcb-b2dc-87f0cd1f6053';
    $pane = new stdClass();
    $pane->pid = 'new-add86469-af19-458b-bf34-5896f9e71c7a';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grid-12',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'add86469-af19-458b-bf34-5896f9e71c7a';
    $display->content['new-add86469-af19-458b-bf34-5896f9e71c7a'] = $pane;
    $display->panels['main'][4] = 'new-add86469-af19-458b-bf34-5896f9e71c7a';
    $pane = new stdClass();
    $pane->pid = 'new-768969ac-8a6d-43b1-8b54-c0bc857fcf8b';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Clearing div',
      'title' => '',
      'body' => '<div class="clear"></div>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '768969ac-8a6d-43b1-8b54-c0bc857fcf8b';
    $display->content['new-768969ac-8a6d-43b1-8b54-c0bc857fcf8b'] = $pane;
    $display->panels['main'][5] = 'new-768969ac-8a6d-43b1-8b54-c0bc857fcf8b';
    $pane = new stdClass();
    $pane->pid = 'new-8eb3fab4-8d6a-41f7-9075-dfb180e067ad';
    $pane->panel = 'main';
    $pane->type = 'panels_mini';
    $pane->subtype = 'question_links_container';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '8eb3fab4-8d6a-41f7-9075-dfb180e067ad';
    $display->content['new-8eb3fab4-8d6a-41f7-9075-dfb180e067ad'] = $pane;
    $display->panels['main'][6] = 'new-8eb3fab4-8d6a-41f7-9075-dfb180e067ad';
    $pane = new stdClass();
    $pane->pid = 'new-1b5de25c-9ee9-40c1-803d-b17cc4625426';
    $pane->panel = 'main';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'teaser',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '1b5de25c-9ee9-40c1-803d-b17cc4625426';
    $display->content['new-1b5de25c-9ee9-40c1-803d-b17cc4625426'] = $pane;
    $display->panels['main'][7] = 'new-1b5de25c-9ee9-40c1-803d-b17cc4625426';
    $pane = new stdClass();
    $pane->pid = 'new-c6909b74-117a-47ff-88b1-6e06a15b0ed2';
    $pane->panel = 'main';
    $pane->type = 'coral_add_answer';
    $pane->subtype = 'coral_add_answer';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => FALSE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = 'c6909b74-117a-47ff-88b1-6e06a15b0ed2';
    $display->content['new-c6909b74-117a-47ff-88b1-6e06a15b0ed2'] = $pane;
    $display->panels['main'][8] = 'new-c6909b74-117a-47ff-88b1-6e06a15b0ed2';
    $pane = new stdClass();
    $pane->pid = 'new-4eb3b353-5024-42e5-8de7-6b2dbaa4d96a';
    $pane->panel = 'main';
    $pane->type = 'coral_best_answer';
    $pane->subtype = 'coral_best_answer';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = '4eb3b353-5024-42e5-8de7-6b2dbaa4d96a';
    $display->content['new-4eb3b353-5024-42e5-8de7-6b2dbaa4d96a'] = $pane;
    $display->panels['main'][9] = 'new-4eb3b353-5024-42e5-8de7-6b2dbaa4d96a';
    $pane = new stdClass();
    $pane->pid = 'new-0400195d-4983-4d2b-aaea-89ec6ff91816';
    $pane->panel = 'main';
    $pane->type = 'coral_add_comment';
    $pane->subtype = 'coral_add_comment';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $pane->uuid = '0400195d-4983-4d2b-aaea-89ec6ff91816';
    $display->content['new-0400195d-4983-4d2b-aaea-89ec6ff91816'] = $pane;
    $display->panels['main'][10] = 'new-0400195d-4983-4d2b-aaea-89ec6ff91816';
    $pane = new stdClass();
    $pane->pid = 'new-1a578d77-1d71-423d-ba24-4488a051934e';
    $pane->panel = 'main';
    $pane->type = 'coral_flag_abuse_node';
    $pane->subtype = 'coral_flag_abuse_node';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 11;
    $pane->locks = array();
    $pane->uuid = '1a578d77-1d71-423d-ba24-4488a051934e';
    $display->content['new-1a578d77-1d71-423d-ba24-4488a051934e'] = $pane;
    $display->panels['main'][11] = 'new-1a578d77-1d71-423d-ba24-4488a051934e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:question:default:teaser'] = $panelizer;

  return $export;
}
