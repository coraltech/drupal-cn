<?php
/**
 * @file
 * comment_content_type.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function comment_content_type_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:comment:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'comment';
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
  $display->uuid = 'd23a6892-db04-4feb-a219-de213b8d8702';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-53aaae91-b710-40e3-8efa-8c4deba04e97';
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
    $pane->uuid = '53aaae91-b710-40e3-8efa-8c4deba04e97';
    $display->content['new-53aaae91-b710-40e3-8efa-8c4deba04e97'] = $pane;
    $display->panels['leader'][0] = 'new-53aaae91-b710-40e3-8efa-8c4deba04e97';
    $pane = new stdClass();
    $pane->pid = 'new-3e64bd16-494c-4563-a9a9-1f6df7515061';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3e64bd16-494c-4563-a9a9-1f6df7515061';
    $display->content['new-3e64bd16-494c-4563-a9a9-1f6df7515061'] = $pane;
    $display->panels['main'][0] = 'new-3e64bd16-494c-4563-a9a9-1f6df7515061';
    $pane = new stdClass();
    $pane->pid = 'new-48e433ea-f914-4020-9379-97cc60e441bb';
    $pane->panel = 'main';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'teaser',
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
      'css_class' => 'pane-coral-comments-target loose clearfix',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '48e433ea-f914-4020-9379-97cc60e441bb';
    $display->content['new-48e433ea-f914-4020-9379-97cc60e441bb'] = $pane;
    $display->panels['main'][1] = 'new-48e433ea-f914-4020-9379-97cc60e441bb';
    $pane = new stdClass();
    $pane->pid = 'new-d8dd421f-3f52-4f56-911f-72a88f74054d';
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
    $pane->uuid = 'd8dd421f-3f52-4f56-911f-72a88f74054d';
    $display->content['new-d8dd421f-3f52-4f56-911f-72a88f74054d'] = $pane;
    $display->panels['secondary'][0] = 'new-d8dd421f-3f52-4f56-911f-72a88f74054d';
    $pane = new stdClass();
    $pane->pid = 'new-51fbc132-e933-421f-9472-aaef722c443e';
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
    $pane->uuid = '51fbc132-e933-421f-9472-aaef722c443e';
    $display->content['new-51fbc132-e933-421f-9472-aaef722c443e'] = $pane;
    $display->panels['secondary'][1] = 'new-51fbc132-e933-421f-9472-aaef722c443e';
    $pane = new stdClass();
    $pane->pid = 'new-1a060e59-aeeb-4b34-aba4-e32fc63a5937';
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
    $pane->uuid = '1a060e59-aeeb-4b34-aba4-e32fc63a5937';
    $display->content['new-1a060e59-aeeb-4b34-aba4-e32fc63a5937'] = $pane;
    $display->panels['secondary'][2] = 'new-1a060e59-aeeb-4b34-aba4-e32fc63a5937';
    $pane = new stdClass();
    $pane->pid = 'new-8e1352c0-85d9-4835-b5b9-f4827e47e93a';
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
    $pane->uuid = '8e1352c0-85d9-4835-b5b9-f4827e47e93a';
    $display->content['new-8e1352c0-85d9-4835-b5b9-f4827e47e93a'] = $pane;
    $display->panels['secondary'][3] = 'new-8e1352c0-85d9-4835-b5b9-f4827e47e93a';
    $pane = new stdClass();
    $pane->pid = 'new-36765956-6e3f-469d-ac52-d3ce877e4000';
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
    $pane->uuid = '36765956-6e3f-469d-ac52-d3ce877e4000';
    $display->content['new-36765956-6e3f-469d-ac52-d3ce877e4000'] = $pane;
    $display->panels['secondary'][4] = 'new-36765956-6e3f-469d-ac52-d3ce877e4000';
    $pane = new stdClass();
    $pane->pid = 'new-dac58d8c-dada-486f-ad29-71563c46870d';
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
    $pane->uuid = 'dac58d8c-dada-486f-ad29-71563c46870d';
    $display->content['new-dac58d8c-dada-486f-ad29-71563c46870d'] = $pane;
    $display->panels['secondary'][5] = 'new-dac58d8c-dada-486f-ad29-71563c46870d';
    $pane = new stdClass();
    $pane->pid = 'new-e899ed85-0228-4046-8855-b875a8fdadfa';
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
    $pane->uuid = 'e899ed85-0228-4046-8855-b875a8fdadfa';
    $display->content['new-e899ed85-0228-4046-8855-b875a8fdadfa'] = $pane;
    $display->panels['secondary'][6] = 'new-e899ed85-0228-4046-8855-b875a8fdadfa';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:comment:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:comment:default:teaser';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'comment';
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
      'middle' => NULL,
      'leader' => NULL,
      'main' => NULL,
      'secondary' => NULL,
      'follower' => NULL,
      'sub_footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '99f8ec0a-d809-4e4b-9187-75b41b4751bf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ada8be9b-ba21-46fb-8378-c10ce3813782';
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
    $pane->uuid = 'ada8be9b-ba21-46fb-8378-c10ce3813782';
    $display->content['new-ada8be9b-ba21-46fb-8378-c10ce3813782'] = $pane;
    $display->panels['follower'][0] = 'new-ada8be9b-ba21-46fb-8378-c10ce3813782';
    $pane = new stdClass();
    $pane->pid = 'new-b0189297-cf49-4332-a601-d21c1ae69ecc';
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
    $pane->uuid = 'b0189297-cf49-4332-a601-d21c1ae69ecc';
    $display->content['new-b0189297-cf49-4332-a601-d21c1ae69ecc'] = $pane;
    $display->panels['follower'][1] = 'new-b0189297-cf49-4332-a601-d21c1ae69ecc';
    $pane = new stdClass();
    $pane->pid = 'new-19b3f94a-cf14-42b4-bf04-3621562d6df8';
    $pane->panel = 'leader';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'markup' => 'h2',
      'id' => '',
      'class' => 'hide',
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
      'css_class' => 'comment-node-pane-title left',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '19b3f94a-cf14-42b4-bf04-3621562d6df8';
    $display->content['new-19b3f94a-cf14-42b4-bf04-3621562d6df8'] = $pane;
    $display->panels['leader'][0] = 'new-19b3f94a-cf14-42b4-bf04-3621562d6df8';
    $pane = new stdClass();
    $pane->pid = 'new-5d8b6b3f-958e-47ce-a8ec-6273808d7f76';
    $pane->panel = 'leader';
    $pane->type = 'coral_node_stats';
    $pane->subtype = 'coral_node_stats';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => FALSE,
      'display_stats' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
      ),
      'display_style' => '3',
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
      'css_class' => 'right',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5d8b6b3f-958e-47ce-a8ec-6273808d7f76';
    $display->content['new-5d8b6b3f-958e-47ce-a8ec-6273808d7f76'] = $pane;
    $display->panels['leader'][1] = 'new-5d8b6b3f-958e-47ce-a8ec-6273808d7f76';
    $pane = new stdClass();
    $pane->pid = 'new-c1246974-6bdc-4587-ab55-2fe8629744f2';
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
    $pane->uuid = 'c1246974-6bdc-4587-ab55-2fe8629744f2';
    $display->content['new-c1246974-6bdc-4587-ab55-2fe8629744f2'] = $pane;
    $display->panels['main'][0] = 'new-c1246974-6bdc-4587-ab55-2fe8629744f2';
    $pane = new stdClass();
    $pane->pid = 'new-5196634b-c2b7-40a9-87ee-c75048e1ca4b';
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
      'css_class' => 'body-full',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5196634b-c2b7-40a9-87ee-c75048e1ca4b';
    $display->content['new-5196634b-c2b7-40a9-87ee-c75048e1ca4b'] = $pane;
    $display->panels['main'][1] = 'new-5196634b-c2b7-40a9-87ee-c75048e1ca4b';
    $pane = new stdClass();
    $pane->pid = 'new-bac8f0f8-8ffa-4bb7-bc5c-a3a76eb608e9';
    $pane->panel = 'main';
    $pane->type = 'coral_flag_abuse_node';
    $pane->subtype = 'coral_flag_abuse_node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'bac8f0f8-8ffa-4bb7-bc5c-a3a76eb608e9';
    $display->content['new-bac8f0f8-8ffa-4bb7-bc5c-a3a76eb608e9'] = $pane;
    $display->panels['main'][2] = 'new-bac8f0f8-8ffa-4bb7-bc5c-a3a76eb608e9';
    $pane = new stdClass();
    $pane->pid = 'new-d73a3e25-634a-4cdd-95f6-b4d9e42be939';
    $pane->panel = 'main';
    $pane->type = 'coral_add_comment';
    $pane->subtype = 'coral_add_comment';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'd73a3e25-634a-4cdd-95f6-b4d9e42be939';
    $display->content['new-d73a3e25-634a-4cdd-95f6-b4d9e42be939'] = $pane;
    $display->panels['main'][3] = 'new-d73a3e25-634a-4cdd-95f6-b4d9e42be939';
    $pane = new stdClass();
    $pane->pid = 'new-3f834008-9b8b-4b62-a7f8-27ce9c853c16';
    $pane->panel = 'main';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
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
      'css_id' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '3f834008-9b8b-4b62-a7f8-27ce9c853c16';
    $display->content['new-3f834008-9b8b-4b62-a7f8-27ce9c853c16'] = $pane;
    $display->panels['main'][4] = 'new-3f834008-9b8b-4b62-a7f8-27ce9c853c16';
    $pane = new stdClass();
    $pane->pid = 'new-3fd05c61-53a0-42c0-b253-a86c7989520b';
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
      'display_style' => '3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'left',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '3fd05c61-53a0-42c0-b253-a86c7989520b';
    $display->content['new-3fd05c61-53a0-42c0-b253-a86c7989520b'] = $pane;
    $display->panels['main'][5] = 'new-3fd05c61-53a0-42c0-b253-a86c7989520b';
    $pane = new stdClass();
    $pane->pid = 'new-7db38c72-ed1c-4fd9-b206-ae8ec131690e';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_tags';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => '10',
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '7db38c72-ed1c-4fd9-b206-ae8ec131690e';
    $display->content['new-7db38c72-ed1c-4fd9-b206-ae8ec131690e'] = $pane;
    $display->panels['main'][6] = 'new-7db38c72-ed1c-4fd9-b206-ae8ec131690e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:comment:default:teaser'] = $panelizer;

  return $export;
}
