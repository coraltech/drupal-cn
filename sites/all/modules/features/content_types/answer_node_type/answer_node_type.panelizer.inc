<?php
/**
 * @file
 * answer_node_type.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function answer_node_type_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:answer:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'answer';
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
  $display->uuid = '20810b0f-91bf-45af-bdd9-28f5e7b4d4ea';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-750da28b-7a32-46a7-8f78-72a2e831c0e7';
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
    $pane->uuid = '750da28b-7a32-46a7-8f78-72a2e831c0e7';
    $display->content['new-750da28b-7a32-46a7-8f78-72a2e831c0e7'] = $pane;
    $display->panels['leader'][0] = 'new-750da28b-7a32-46a7-8f78-72a2e831c0e7';
    $pane = new stdClass();
    $pane->pid = 'new-a9fb6521-e204-461d-893e-76bcff959244';
    $pane->panel = 'main';
    $pane->type = 'coral_parent_content';
    $pane->subtype = 'coral_parent_content';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a9fb6521-e204-461d-893e-76bcff959244';
    $display->content['new-a9fb6521-e204-461d-893e-76bcff959244'] = $pane;
    $display->panels['main'][0] = 'new-a9fb6521-e204-461d-893e-76bcff959244';
    $pane = new stdClass();
    $pane->pid = 'new-112540df-d425-485c-8843-6ff7dcc0162b';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '112540df-d425-485c-8843-6ff7dcc0162b';
    $display->content['new-112540df-d425-485c-8843-6ff7dcc0162b'] = $pane;
    $display->panels['main'][1] = 'new-112540df-d425-485c-8843-6ff7dcc0162b';
    $pane = new stdClass();
    $pane->pid = 'new-0008b2ea-f695-4776-8947-c488508858f9';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0008b2ea-f695-4776-8947-c488508858f9';
    $display->content['new-0008b2ea-f695-4776-8947-c488508858f9'] = $pane;
    $display->panels['main'][2] = 'new-0008b2ea-f695-4776-8947-c488508858f9';
    $pane = new stdClass();
    $pane->pid = 'new-1f1b6f81-7f2d-4c58-a9f6-3405edd79db1';
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
    $pane->uuid = '1f1b6f81-7f2d-4c58-a9f6-3405edd79db1';
    $display->content['new-1f1b6f81-7f2d-4c58-a9f6-3405edd79db1'] = $pane;
    $display->panels['secondary'][0] = 'new-1f1b6f81-7f2d-4c58-a9f6-3405edd79db1';
    $pane = new stdClass();
    $pane->pid = 'new-ef43b6f9-609b-46ae-90de-64ca0dd9c85b';
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
    $pane->uuid = 'ef43b6f9-609b-46ae-90de-64ca0dd9c85b';
    $display->content['new-ef43b6f9-609b-46ae-90de-64ca0dd9c85b'] = $pane;
    $display->panels['secondary'][1] = 'new-ef43b6f9-609b-46ae-90de-64ca0dd9c85b';
    $pane = new stdClass();
    $pane->pid = 'new-2669d9dd-390b-488c-84a5-0e3704c690d0';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2669d9dd-390b-488c-84a5-0e3704c690d0';
    $display->content['new-2669d9dd-390b-488c-84a5-0e3704c690d0'] = $pane;
    $display->panels['secondary'][2] = 'new-2669d9dd-390b-488c-84a5-0e3704c690d0';
    $pane = new stdClass();
    $pane->pid = 'new-a4ce1c5e-dbb7-4ea3-9a19-28840dc8a70b';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'a4ce1c5e-dbb7-4ea3-9a19-28840dc8a70b';
    $display->content['new-a4ce1c5e-dbb7-4ea3-9a19-28840dc8a70b'] = $pane;
    $display->panels['secondary'][3] = 'new-a4ce1c5e-dbb7-4ea3-9a19-28840dc8a70b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:answer:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:answer:default:teaser';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'answer';
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
      'leader' => NULL,
      'main' => NULL,
      'secondary' => NULL,
      'follower' => NULL,
      'sub_footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'ccd96ef0-2635-4bc1-8ab8-67475f5af64e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6e5a9024-909d-4af8-9e8e-10fe34b986df';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6e5a9024-909d-4af8-9e8e-10fe34b986df';
    $display->content['new-6e5a9024-909d-4af8-9e8e-10fe34b986df'] = $pane;
    $display->panels['follower'][0] = 'new-6e5a9024-909d-4af8-9e8e-10fe34b986df';
    $pane = new stdClass();
    $pane->pid = 'new-67bb5cd2-fe58-470f-969f-b08fcc053327';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '67bb5cd2-fe58-470f-969f-b08fcc053327';
    $display->content['new-67bb5cd2-fe58-470f-969f-b08fcc053327'] = $pane;
    $display->panels['follower'][1] = 'new-67bb5cd2-fe58-470f-969f-b08fcc053327';
    $pane = new stdClass();
    $pane->pid = 'new-8903611b-c4bb-4e7b-950a-a63c162b6ddf';
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
    $pane->uuid = '8903611b-c4bb-4e7b-950a-a63c162b6ddf';
    $display->content['new-8903611b-c4bb-4e7b-950a-a63c162b6ddf'] = $pane;
    $display->panels['main'][0] = 'new-8903611b-c4bb-4e7b-950a-a63c162b6ddf';
    $pane = new stdClass();
    $pane->pid = 'new-ad00aa54-3b77-47b9-b4e8-ff7b9d14efd7';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
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
      'css_class' => 'body-full',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ad00aa54-3b77-47b9-b4e8-ff7b9d14efd7';
    $display->content['new-ad00aa54-3b77-47b9-b4e8-ff7b9d14efd7'] = $pane;
    $display->panels['main'][1] = 'new-ad00aa54-3b77-47b9-b4e8-ff7b9d14efd7';
    $pane = new stdClass();
    $pane->pid = 'new-8de6f211-efd3-4afe-ad78-330e07774da1';
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
    $pane->uuid = '8de6f211-efd3-4afe-ad78-330e07774da1';
    $display->content['new-8de6f211-efd3-4afe-ad78-330e07774da1'] = $pane;
    $display->panels['main'][2] = 'new-8de6f211-efd3-4afe-ad78-330e07774da1';
    $pane = new stdClass();
    $pane->pid = 'new-d03f2e13-4ce1-4f33-ba0a-655571db6c12';
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
    $pane->uuid = 'd03f2e13-4ce1-4f33-ba0a-655571db6c12';
    $display->content['new-d03f2e13-4ce1-4f33-ba0a-655571db6c12'] = $pane;
    $display->panels['main'][3] = 'new-d03f2e13-4ce1-4f33-ba0a-655571db6c12';
    $pane = new stdClass();
    $pane->pid = 'new-24ebc4e0-fdb9-4fde-9126-34aedf45c14d';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => '5',
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grid-12',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '24ebc4e0-fdb9-4fde-9126-34aedf45c14d';
    $display->content['new-24ebc4e0-fdb9-4fde-9126-34aedf45c14d'] = $pane;
    $display->panels['main'][4] = 'new-24ebc4e0-fdb9-4fde-9126-34aedf45c14d';
    $pane = new stdClass();
    $pane->pid = 'new-323232c4-d3a1-4c42-9c23-5004d7cb0d56';
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
    $pane->uuid = '323232c4-d3a1-4c42-9c23-5004d7cb0d56';
    $display->content['new-323232c4-d3a1-4c42-9c23-5004d7cb0d56'] = $pane;
    $display->panels['main'][5] = 'new-323232c4-d3a1-4c42-9c23-5004d7cb0d56';
    $pane = new stdClass();
    $pane->pid = 'new-c855ba6a-6989-4d8e-8f66-0b60c24cc6e9';
    $pane->panel = 'main';
    $pane->type = 'panels_mini';
    $pane->subtype = 'answer_links_container';
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
    $pane->uuid = 'c855ba6a-6989-4d8e-8f66-0b60c24cc6e9';
    $display->content['new-c855ba6a-6989-4d8e-8f66-0b60c24cc6e9'] = $pane;
    $display->panels['main'][6] = 'new-c855ba6a-6989-4d8e-8f66-0b60c24cc6e9';
    $pane = new stdClass();
    $pane->pid = 'new-332679e6-1a53-4e4f-9abe-43f22838e7dd';
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
    $pane->uuid = '332679e6-1a53-4e4f-9abe-43f22838e7dd';
    $display->content['new-332679e6-1a53-4e4f-9abe-43f22838e7dd'] = $pane;
    $display->panels['main'][7] = 'new-332679e6-1a53-4e4f-9abe-43f22838e7dd';
    $pane = new stdClass();
    $pane->pid = 'new-5cc7c213-2947-4769-9eba-a4a09ba45736';
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
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '5cc7c213-2947-4769-9eba-a4a09ba45736';
    $display->content['new-5cc7c213-2947-4769-9eba-a4a09ba45736'] = $pane;
    $display->panels['main'][8] = 'new-5cc7c213-2947-4769-9eba-a4a09ba45736';
    $pane = new stdClass();
    $pane->pid = 'new-626ca431-ce9c-4aec-baed-8b01054d30a5';
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
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = '626ca431-ce9c-4aec-baed-8b01054d30a5';
    $display->content['new-626ca431-ce9c-4aec-baed-8b01054d30a5'] = $pane;
    $display->panels['main'][9] = 'new-626ca431-ce9c-4aec-baed-8b01054d30a5';
    $pane = new stdClass();
    $pane->pid = 'new-460d2261-35cd-4406-9afe-73ec50c7673c';
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
    $pane->position = 10;
    $pane->locks = array();
    $pane->uuid = '460d2261-35cd-4406-9afe-73ec50c7673c';
    $display->content['new-460d2261-35cd-4406-9afe-73ec50c7673c'] = $pane;
    $display->panels['main'][10] = 'new-460d2261-35cd-4406-9afe-73ec50c7673c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-24ebc4e0-fdb9-4fde-9126-34aedf45c14d';
  $panelizer->display = $display;
  $export['node:answer:default:teaser'] = $panelizer;

  return $export;
}
