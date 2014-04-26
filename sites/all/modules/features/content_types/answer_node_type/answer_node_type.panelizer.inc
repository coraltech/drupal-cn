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
  $display->uuid = '70c26115-9a55-471b-8d16-cb262a09ab81';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3bd62905-b3f6-4081-96fa-0c3d3c40f7fa';
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
    $pane->uuid = '3bd62905-b3f6-4081-96fa-0c3d3c40f7fa';
    $display->content['new-3bd62905-b3f6-4081-96fa-0c3d3c40f7fa'] = $pane;
    $display->panels['follower'][0] = 'new-3bd62905-b3f6-4081-96fa-0c3d3c40f7fa';
    $pane = new stdClass();
    $pane->pid = 'new-60f1fdc1-6c1b-457e-acd0-a2a69edc605f';
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
    $pane->uuid = '60f1fdc1-6c1b-457e-acd0-a2a69edc605f';
    $display->content['new-60f1fdc1-6c1b-457e-acd0-a2a69edc605f'] = $pane;
    $display->panels['follower'][1] = 'new-60f1fdc1-6c1b-457e-acd0-a2a69edc605f';
    $pane = new stdClass();
    $pane->pid = 'new-23cc00ce-df29-4cb5-8dcf-5ae775d83713';
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
    $pane->uuid = '23cc00ce-df29-4cb5-8dcf-5ae775d83713';
    $display->content['new-23cc00ce-df29-4cb5-8dcf-5ae775d83713'] = $pane;
    $display->panels['main'][0] = 'new-23cc00ce-df29-4cb5-8dcf-5ae775d83713';
    $pane = new stdClass();
    $pane->pid = 'new-8004998c-94af-4947-b024-a761235caf87';
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
      'css_class' => 'body-full hide',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8004998c-94af-4947-b024-a761235caf87';
    $display->content['new-8004998c-94af-4947-b024-a761235caf87'] = $pane;
    $display->panels['main'][1] = 'new-8004998c-94af-4947-b024-a761235caf87';
    $pane = new stdClass();
    $pane->pid = 'new-23042ff0-1b25-4d69-9eb2-2a05a8a39908';
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
    $pane->uuid = '23042ff0-1b25-4d69-9eb2-2a05a8a39908';
    $display->content['new-23042ff0-1b25-4d69-9eb2-2a05a8a39908'] = $pane;
    $display->panels['main'][2] = 'new-23042ff0-1b25-4d69-9eb2-2a05a8a39908';
    $pane = new stdClass();
    $pane->pid = 'new-8a520af6-b6a6-4686-9843-a796e345e602';
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
    $pane->uuid = '8a520af6-b6a6-4686-9843-a796e345e602';
    $display->content['new-8a520af6-b6a6-4686-9843-a796e345e602'] = $pane;
    $display->panels['main'][3] = 'new-8a520af6-b6a6-4686-9843-a796e345e602';
    $pane = new stdClass();
    $pane->pid = 'new-b38f7f9d-8403-4f3a-bb52-b409fb46a9a5';
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
    $pane->uuid = 'b38f7f9d-8403-4f3a-bb52-b409fb46a9a5';
    $display->content['new-b38f7f9d-8403-4f3a-bb52-b409fb46a9a5'] = $pane;
    $display->panels['main'][4] = 'new-b38f7f9d-8403-4f3a-bb52-b409fb46a9a5';
    $pane = new stdClass();
    $pane->pid = 'new-c75e5e07-0545-4f44-a44f-c511604a73fe';
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
    $pane->uuid = 'c75e5e07-0545-4f44-a44f-c511604a73fe';
    $display->content['new-c75e5e07-0545-4f44-a44f-c511604a73fe'] = $pane;
    $display->panels['main'][5] = 'new-c75e5e07-0545-4f44-a44f-c511604a73fe';
    $pane = new stdClass();
    $pane->pid = 'new-6a665fd0-7707-4f6c-8a8e-935a7a37685f';
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
    $pane->uuid = '6a665fd0-7707-4f6c-8a8e-935a7a37685f';
    $display->content['new-6a665fd0-7707-4f6c-8a8e-935a7a37685f'] = $pane;
    $display->panels['main'][6] = 'new-6a665fd0-7707-4f6c-8a8e-935a7a37685f';
    $pane = new stdClass();
    $pane->pid = 'new-5d1e1080-1c75-44ab-be1e-7498456805d8';
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
    $pane->uuid = '5d1e1080-1c75-44ab-be1e-7498456805d8';
    $display->content['new-5d1e1080-1c75-44ab-be1e-7498456805d8'] = $pane;
    $display->panels['main'][7] = 'new-5d1e1080-1c75-44ab-be1e-7498456805d8';
    $pane = new stdClass();
    $pane->pid = 'new-9d4cb0d7-bc0d-4294-95e2-9e9b611aa43a';
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
    $pane->uuid = '9d4cb0d7-bc0d-4294-95e2-9e9b611aa43a';
    $display->content['new-9d4cb0d7-bc0d-4294-95e2-9e9b611aa43a'] = $pane;
    $display->panels['main'][8] = 'new-9d4cb0d7-bc0d-4294-95e2-9e9b611aa43a';
    $pane = new stdClass();
    $pane->pid = 'new-397dc7da-116b-4729-8e92-a34e97183d62';
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
    $pane->uuid = '397dc7da-116b-4729-8e92-a34e97183d62';
    $display->content['new-397dc7da-116b-4729-8e92-a34e97183d62'] = $pane;
    $display->panels['main'][9] = 'new-397dc7da-116b-4729-8e92-a34e97183d62';
    $pane = new stdClass();
    $pane->pid = 'new-1ea95f2e-01c1-4774-bd80-40e1cabe4428';
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
    $pane->uuid = '1ea95f2e-01c1-4774-bd80-40e1cabe4428';
    $display->content['new-1ea95f2e-01c1-4774-bd80-40e1cabe4428'] = $pane;
    $display->panels['main'][10] = 'new-1ea95f2e-01c1-4774-bd80-40e1cabe4428';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b38f7f9d-8403-4f3a-bb52-b409fb46a9a5';
  $panelizer->display = $display;
  $export['node:answer:default:teaser'] = $panelizer;

  return $export;
}
