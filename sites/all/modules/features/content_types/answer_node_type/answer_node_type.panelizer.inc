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
  $display->uuid = 'a293925c-754e-4c7b-8f08-20898280df2d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2d5c2e69-9098-43c4-b5f2-a7eeec174f52';
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
    $pane->uuid = '2d5c2e69-9098-43c4-b5f2-a7eeec174f52';
    $display->content['new-2d5c2e69-9098-43c4-b5f2-a7eeec174f52'] = $pane;
    $display->panels['leader'][0] = 'new-2d5c2e69-9098-43c4-b5f2-a7eeec174f52';
    $pane = new stdClass();
    $pane->pid = 'new-0fd17927-7a1a-4056-b51b-72dc95bf35a7';
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
    $pane->uuid = '0fd17927-7a1a-4056-b51b-72dc95bf35a7';
    $display->content['new-0fd17927-7a1a-4056-b51b-72dc95bf35a7'] = $pane;
    $display->panels['main'][0] = 'new-0fd17927-7a1a-4056-b51b-72dc95bf35a7';
    $pane = new stdClass();
    $pane->pid = 'new-f3afceb5-aa8b-4f2f-8071-ec55e803d1d2';
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
    $pane->uuid = 'f3afceb5-aa8b-4f2f-8071-ec55e803d1d2';
    $display->content['new-f3afceb5-aa8b-4f2f-8071-ec55e803d1d2'] = $pane;
    $display->panels['main'][1] = 'new-f3afceb5-aa8b-4f2f-8071-ec55e803d1d2';
    $pane = new stdClass();
    $pane->pid = 'new-f099708f-47ab-4ccd-8806-d0eaa365d1c9';
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
    $pane->uuid = 'f099708f-47ab-4ccd-8806-d0eaa365d1c9';
    $display->content['new-f099708f-47ab-4ccd-8806-d0eaa365d1c9'] = $pane;
    $display->panels['main'][2] = 'new-f099708f-47ab-4ccd-8806-d0eaa365d1c9';
    $pane = new stdClass();
    $pane->pid = 'new-b734ed43-122f-496e-8106-6af65bb3d5ce';
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
    $pane->uuid = 'b734ed43-122f-496e-8106-6af65bb3d5ce';
    $display->content['new-b734ed43-122f-496e-8106-6af65bb3d5ce'] = $pane;
    $display->panels['secondary'][0] = 'new-b734ed43-122f-496e-8106-6af65bb3d5ce';
    $pane = new stdClass();
    $pane->pid = 'new-e648ed25-5801-4923-874e-c76db595b8e2';
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
    $pane->uuid = 'e648ed25-5801-4923-874e-c76db595b8e2';
    $display->content['new-e648ed25-5801-4923-874e-c76db595b8e2'] = $pane;
    $display->panels['secondary'][1] = 'new-e648ed25-5801-4923-874e-c76db595b8e2';
    $pane = new stdClass();
    $pane->pid = 'new-25444c51-47b9-46ce-bc15-3e2c1030c132';
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
    $pane->uuid = '25444c51-47b9-46ce-bc15-3e2c1030c132';
    $display->content['new-25444c51-47b9-46ce-bc15-3e2c1030c132'] = $pane;
    $display->panels['secondary'][2] = 'new-25444c51-47b9-46ce-bc15-3e2c1030c132';
    $pane = new stdClass();
    $pane->pid = 'new-24c4abae-4162-4c9a-9355-2b41f59bcd7b';
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
    $pane->uuid = '24c4abae-4162-4c9a-9355-2b41f59bcd7b';
    $display->content['new-24c4abae-4162-4c9a-9355-2b41f59bcd7b'] = $pane;
    $display->panels['secondary'][3] = 'new-24c4abae-4162-4c9a-9355-2b41f59bcd7b';
    $pane = new stdClass();
    $pane->pid = 'new-4040b222-cc8b-40c3-8183-621d3d2c1870';
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
    $pane->uuid = '4040b222-cc8b-40c3-8183-621d3d2c1870';
    $display->content['new-4040b222-cc8b-40c3-8183-621d3d2c1870'] = $pane;
    $display->panels['secondary'][4] = 'new-4040b222-cc8b-40c3-8183-621d3d2c1870';
    $pane = new stdClass();
    $pane->pid = 'new-220ab723-4f54-43cd-9eb9-ef01b7ed2f85';
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
    $pane->uuid = '220ab723-4f54-43cd-9eb9-ef01b7ed2f85';
    $display->content['new-220ab723-4f54-43cd-9eb9-ef01b7ed2f85'] = $pane;
    $display->panels['secondary'][5] = 'new-220ab723-4f54-43cd-9eb9-ef01b7ed2f85';
    $pane = new stdClass();
    $pane->pid = 'new-3908e340-e3cd-4568-8124-5434baff5c85';
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
    $pane->uuid = '3908e340-e3cd-4568-8124-5434baff5c85';
    $display->content['new-3908e340-e3cd-4568-8124-5434baff5c85'] = $pane;
    $display->panels['secondary'][6] = 'new-3908e340-e3cd-4568-8124-5434baff5c85';
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
  $display->uuid = '0e6a1b58-0096-432a-b404-2cfad581575b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e1cf6925-3e1e-4e98-99d6-d8638887f3c2';
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
    $pane->uuid = 'e1cf6925-3e1e-4e98-99d6-d8638887f3c2';
    $display->content['new-e1cf6925-3e1e-4e98-99d6-d8638887f3c2'] = $pane;
    $display->panels['follower'][0] = 'new-e1cf6925-3e1e-4e98-99d6-d8638887f3c2';
    $pane = new stdClass();
    $pane->pid = 'new-2d0fec5a-8622-42ef-9773-1b4336b9e86f';
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
    $pane->uuid = '2d0fec5a-8622-42ef-9773-1b4336b9e86f';
    $display->content['new-2d0fec5a-8622-42ef-9773-1b4336b9e86f'] = $pane;
    $display->panels['follower'][1] = 'new-2d0fec5a-8622-42ef-9773-1b4336b9e86f';
    $pane = new stdClass();
    $pane->pid = 'new-7d7e81b0-de0c-4fc4-9989-23383d7de528';
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
    $pane->uuid = '7d7e81b0-de0c-4fc4-9989-23383d7de528';
    $display->content['new-7d7e81b0-de0c-4fc4-9989-23383d7de528'] = $pane;
    $display->panels['main'][0] = 'new-7d7e81b0-de0c-4fc4-9989-23383d7de528';
    $pane = new stdClass();
    $pane->pid = 'new-66b60046-f124-494a-ac10-1b8a455d91c4';
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
    $pane->uuid = '66b60046-f124-494a-ac10-1b8a455d91c4';
    $display->content['new-66b60046-f124-494a-ac10-1b8a455d91c4'] = $pane;
    $display->panels['main'][1] = 'new-66b60046-f124-494a-ac10-1b8a455d91c4';
    $pane = new stdClass();
    $pane->pid = 'new-c16d2fed-9a19-4721-b703-b52b360707fc';
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
    $pane->uuid = 'c16d2fed-9a19-4721-b703-b52b360707fc';
    $display->content['new-c16d2fed-9a19-4721-b703-b52b360707fc'] = $pane;
    $display->panels['main'][2] = 'new-c16d2fed-9a19-4721-b703-b52b360707fc';
    $pane = new stdClass();
    $pane->pid = 'new-81789390-f49d-4bb7-b3c5-e9c5070126c7';
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
    $pane->uuid = '81789390-f49d-4bb7-b3c5-e9c5070126c7';
    $display->content['new-81789390-f49d-4bb7-b3c5-e9c5070126c7'] = $pane;
    $display->panels['main'][3] = 'new-81789390-f49d-4bb7-b3c5-e9c5070126c7';
    $pane = new stdClass();
    $pane->pid = 'new-b5f0764d-e0f9-4981-9fca-c46604ef360d';
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
    $pane->uuid = 'b5f0764d-e0f9-4981-9fca-c46604ef360d';
    $display->content['new-b5f0764d-e0f9-4981-9fca-c46604ef360d'] = $pane;
    $display->panels['main'][4] = 'new-b5f0764d-e0f9-4981-9fca-c46604ef360d';
    $pane = new stdClass();
    $pane->pid = 'new-6f7eab85-d8d8-487d-9979-5aa3836bdd93';
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
    $pane->uuid = '6f7eab85-d8d8-487d-9979-5aa3836bdd93';
    $display->content['new-6f7eab85-d8d8-487d-9979-5aa3836bdd93'] = $pane;
    $display->panels['main'][5] = 'new-6f7eab85-d8d8-487d-9979-5aa3836bdd93';
    $pane = new stdClass();
    $pane->pid = 'new-b555832d-1c9b-46d6-b4be-5a2aa796dbe8';
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
    $pane->uuid = 'b555832d-1c9b-46d6-b4be-5a2aa796dbe8';
    $display->content['new-b555832d-1c9b-46d6-b4be-5a2aa796dbe8'] = $pane;
    $display->panels['main'][6] = 'new-b555832d-1c9b-46d6-b4be-5a2aa796dbe8';
    $pane = new stdClass();
    $pane->pid = 'new-3276465e-41c0-4410-886b-fc509c604ae0';
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
    $pane->uuid = '3276465e-41c0-4410-886b-fc509c604ae0';
    $display->content['new-3276465e-41c0-4410-886b-fc509c604ae0'] = $pane;
    $display->panels['main'][7] = 'new-3276465e-41c0-4410-886b-fc509c604ae0';
    $pane = new stdClass();
    $pane->pid = 'new-4c9456a2-d159-4038-98bc-0b82e52f4e20';
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
    $pane->uuid = '4c9456a2-d159-4038-98bc-0b82e52f4e20';
    $display->content['new-4c9456a2-d159-4038-98bc-0b82e52f4e20'] = $pane;
    $display->panels['main'][8] = 'new-4c9456a2-d159-4038-98bc-0b82e52f4e20';
    $pane = new stdClass();
    $pane->pid = 'new-0ca4fb77-7e15-4c37-a327-6953d4a90b38';
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
    $pane->uuid = '0ca4fb77-7e15-4c37-a327-6953d4a90b38';
    $display->content['new-0ca4fb77-7e15-4c37-a327-6953d4a90b38'] = $pane;
    $display->panels['main'][9] = 'new-0ca4fb77-7e15-4c37-a327-6953d4a90b38';
    $pane = new stdClass();
    $pane->pid = 'new-5b44429a-e2bf-4b86-8cb8-2186e8cf1a06';
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
    $pane->uuid = '5b44429a-e2bf-4b86-8cb8-2186e8cf1a06';
    $display->content['new-5b44429a-e2bf-4b86-8cb8-2186e8cf1a06'] = $pane;
    $display->panels['main'][10] = 'new-5b44429a-e2bf-4b86-8cb8-2186e8cf1a06';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b5f0764d-e0f9-4981-9fca-c46604ef360d';
  $panelizer->display = $display;
  $export['node:answer:default:teaser'] = $panelizer;

  return $export;
}
