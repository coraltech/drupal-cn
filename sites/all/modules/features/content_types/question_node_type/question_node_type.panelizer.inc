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
  $display->uuid = 'f40278ee-41bf-4cc0-ad9d-d3fa8046682f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8392c1ab-870f-4274-b15a-677d9f3c9026';
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
    $pane->uuid = '8392c1ab-870f-4274-b15a-677d9f3c9026';
    $display->content['new-8392c1ab-870f-4274-b15a-677d9f3c9026'] = $pane;
    $display->panels['middle'][0] = 'new-8392c1ab-870f-4274-b15a-677d9f3c9026';
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
  $display->uuid = 'bc2f2f20-9cb8-4d7f-a945-d223eda26456';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-71708a08-427f-4c19-a3d9-0f3eda399e31';
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
    $pane->uuid = '71708a08-427f-4c19-a3d9-0f3eda399e31';
    $display->content['new-71708a08-427f-4c19-a3d9-0f3eda399e31'] = $pane;
    $display->panels['follower'][0] = 'new-71708a08-427f-4c19-a3d9-0f3eda399e31';
    $pane = new stdClass();
    $pane->pid = 'new-acebb156-6f6a-488b-bc29-1f95518a6c22';
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
    $pane->uuid = 'acebb156-6f6a-488b-bc29-1f95518a6c22';
    $display->content['new-acebb156-6f6a-488b-bc29-1f95518a6c22'] = $pane;
    $display->panels['follower'][1] = 'new-acebb156-6f6a-488b-bc29-1f95518a6c22';
    $pane = new stdClass();
    $pane->pid = 'new-1ee95af2-75b8-4c8e-a297-c5d0f3f7f128';
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
    $pane->uuid = '1ee95af2-75b8-4c8e-a297-c5d0f3f7f128';
    $display->content['new-1ee95af2-75b8-4c8e-a297-c5d0f3f7f128'] = $pane;
    $display->panels['follower'][2] = 'new-1ee95af2-75b8-4c8e-a297-c5d0f3f7f128';
    $pane = new stdClass();
    $pane->pid = 'new-e0f395a5-cfca-4870-9a6f-f8337bd18f1c';
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
    $pane->uuid = 'e0f395a5-cfca-4870-9a6f-f8337bd18f1c';
    $display->content['new-e0f395a5-cfca-4870-9a6f-f8337bd18f1c'] = $pane;
    $display->panels['follower'][3] = 'new-e0f395a5-cfca-4870-9a6f-f8337bd18f1c';
    $pane = new stdClass();
    $pane->pid = 'new-f31d2b8d-de76-4422-bc6e-335f71adc519';
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
    $pane->uuid = 'f31d2b8d-de76-4422-bc6e-335f71adc519';
    $display->content['new-f31d2b8d-de76-4422-bc6e-335f71adc519'] = $pane;
    $display->panels['follower'][4] = 'new-f31d2b8d-de76-4422-bc6e-335f71adc519';
    $pane = new stdClass();
    $pane->pid = 'new-13b360cf-1270-408c-8db6-da34fab4f1ea';
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
    $pane->uuid = '13b360cf-1270-408c-8db6-da34fab4f1ea';
    $display->content['new-13b360cf-1270-408c-8db6-da34fab4f1ea'] = $pane;
    $display->panels['main'][0] = 'new-13b360cf-1270-408c-8db6-da34fab4f1ea';
    $pane = new stdClass();
    $pane->pid = 'new-ddf59a3a-368a-494c-995a-3fb21f154b13';
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
      'css_class' => 'body-full',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ddf59a3a-368a-494c-995a-3fb21f154b13';
    $display->content['new-ddf59a3a-368a-494c-995a-3fb21f154b13'] = $pane;
    $display->panels['main'][1] = 'new-ddf59a3a-368a-494c-995a-3fb21f154b13';
    $pane = new stdClass();
    $pane->pid = 'new-3cb9147c-6bce-4618-90b7-176ae2b86aa4';
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
    $pane->uuid = '3cb9147c-6bce-4618-90b7-176ae2b86aa4';
    $display->content['new-3cb9147c-6bce-4618-90b7-176ae2b86aa4'] = $pane;
    $display->panels['main'][2] = 'new-3cb9147c-6bce-4618-90b7-176ae2b86aa4';
    $pane = new stdClass();
    $pane->pid = 'new-d93aee82-3170-4278-b298-e3bc3177a81e';
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
    $pane->uuid = 'd93aee82-3170-4278-b298-e3bc3177a81e';
    $display->content['new-d93aee82-3170-4278-b298-e3bc3177a81e'] = $pane;
    $display->panels['main'][3] = 'new-d93aee82-3170-4278-b298-e3bc3177a81e';
    $pane = new stdClass();
    $pane->pid = 'new-b8c6e002-b848-4309-955e-b53a4804708b';
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
    $pane->uuid = 'b8c6e002-b848-4309-955e-b53a4804708b';
    $display->content['new-b8c6e002-b848-4309-955e-b53a4804708b'] = $pane;
    $display->panels['main'][4] = 'new-b8c6e002-b848-4309-955e-b53a4804708b';
    $pane = new stdClass();
    $pane->pid = 'new-cb2451cd-3ef3-4ba2-83bd-1697584fb8e0';
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
    $pane->uuid = 'cb2451cd-3ef3-4ba2-83bd-1697584fb8e0';
    $display->content['new-cb2451cd-3ef3-4ba2-83bd-1697584fb8e0'] = $pane;
    $display->panels['main'][5] = 'new-cb2451cd-3ef3-4ba2-83bd-1697584fb8e0';
    $pane = new stdClass();
    $pane->pid = 'new-b3acd830-8fd5-4883-82d9-01e7046eed09';
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
    $pane->uuid = 'b3acd830-8fd5-4883-82d9-01e7046eed09';
    $display->content['new-b3acd830-8fd5-4883-82d9-01e7046eed09'] = $pane;
    $display->panels['main'][6] = 'new-b3acd830-8fd5-4883-82d9-01e7046eed09';
    $pane = new stdClass();
    $pane->pid = 'new-fa435657-6fa8-4feb-b4d0-46a480dbefed';
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
    $pane->uuid = 'fa435657-6fa8-4feb-b4d0-46a480dbefed';
    $display->content['new-fa435657-6fa8-4feb-b4d0-46a480dbefed'] = $pane;
    $display->panels['main'][7] = 'new-fa435657-6fa8-4feb-b4d0-46a480dbefed';
    $pane = new stdClass();
    $pane->pid = 'new-3f12b0d5-85ab-48c0-bd5a-8bda5fe8d23d';
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
    $pane->uuid = '3f12b0d5-85ab-48c0-bd5a-8bda5fe8d23d';
    $display->content['new-3f12b0d5-85ab-48c0-bd5a-8bda5fe8d23d'] = $pane;
    $display->panels['main'][8] = 'new-3f12b0d5-85ab-48c0-bd5a-8bda5fe8d23d';
    $pane = new stdClass();
    $pane->pid = 'new-d91a3d02-de46-473b-9907-ac0af75569ec';
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
    $pane->uuid = 'd91a3d02-de46-473b-9907-ac0af75569ec';
    $display->content['new-d91a3d02-de46-473b-9907-ac0af75569ec'] = $pane;
    $display->panels['main'][9] = 'new-d91a3d02-de46-473b-9907-ac0af75569ec';
    $pane = new stdClass();
    $pane->pid = 'new-ab2733db-37a2-43ac-b425-65e064779c28';
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
    $pane->uuid = 'ab2733db-37a2-43ac-b425-65e064779c28';
    $display->content['new-ab2733db-37a2-43ac-b425-65e064779c28'] = $pane;
    $display->panels['main'][10] = 'new-ab2733db-37a2-43ac-b425-65e064779c28';
    $pane = new stdClass();
    $pane->pid = 'new-07bb3eb8-8349-48b2-84d3-27ca4e29c4b8';
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
    $pane->uuid = '07bb3eb8-8349-48b2-84d3-27ca4e29c4b8';
    $display->content['new-07bb3eb8-8349-48b2-84d3-27ca4e29c4b8'] = $pane;
    $display->panels['main'][11] = 'new-07bb3eb8-8349-48b2-84d3-27ca4e29c4b8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:question:default:teaser'] = $panelizer;

  return $export;
}
