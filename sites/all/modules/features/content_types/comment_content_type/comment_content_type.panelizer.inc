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
  $display->uuid = 'f8305121-a84f-47b4-9bb2-45834d09ccc7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-da6294f6-aa87-4da3-976e-fa59f907d91f';
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
    $pane->uuid = 'da6294f6-aa87-4da3-976e-fa59f907d91f';
    $display->content['new-da6294f6-aa87-4da3-976e-fa59f907d91f'] = $pane;
    $display->panels['leader'][0] = 'new-da6294f6-aa87-4da3-976e-fa59f907d91f';
    $pane = new stdClass();
    $pane->pid = 'new-d7f2f69b-325e-4518-92ac-6e0e854cb430';
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
    $pane->uuid = 'd7f2f69b-325e-4518-92ac-6e0e854cb430';
    $display->content['new-d7f2f69b-325e-4518-92ac-6e0e854cb430'] = $pane;
    $display->panels['main'][0] = 'new-d7f2f69b-325e-4518-92ac-6e0e854cb430';
    $pane = new stdClass();
    $pane->pid = 'new-0b1261de-1326-47e6-8c76-4f772a4b7ec2';
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
    $pane->uuid = '0b1261de-1326-47e6-8c76-4f772a4b7ec2';
    $display->content['new-0b1261de-1326-47e6-8c76-4f772a4b7ec2'] = $pane;
    $display->panels['main'][1] = 'new-0b1261de-1326-47e6-8c76-4f772a4b7ec2';
    $pane = new stdClass();
    $pane->pid = 'new-ed06c453-f9f0-4cd3-ac3d-1899594217e2';
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
    $pane->uuid = 'ed06c453-f9f0-4cd3-ac3d-1899594217e2';
    $display->content['new-ed06c453-f9f0-4cd3-ac3d-1899594217e2'] = $pane;
    $display->panels['secondary'][0] = 'new-ed06c453-f9f0-4cd3-ac3d-1899594217e2';
    $pane = new stdClass();
    $pane->pid = 'new-5888b5be-b405-45c7-825e-e638a47fcc4b';
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
    $pane->uuid = '5888b5be-b405-45c7-825e-e638a47fcc4b';
    $display->content['new-5888b5be-b405-45c7-825e-e638a47fcc4b'] = $pane;
    $display->panels['secondary'][1] = 'new-5888b5be-b405-45c7-825e-e638a47fcc4b';
    $pane = new stdClass();
    $pane->pid = 'new-e96c7112-5fb7-4eaf-bedc-28788bddb58d';
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
    $pane->uuid = 'e96c7112-5fb7-4eaf-bedc-28788bddb58d';
    $display->content['new-e96c7112-5fb7-4eaf-bedc-28788bddb58d'] = $pane;
    $display->panels['secondary'][2] = 'new-e96c7112-5fb7-4eaf-bedc-28788bddb58d';
    $pane = new stdClass();
    $pane->pid = 'new-2381c9d4-8679-460f-91ff-69c45f248562';
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
    $pane->uuid = '2381c9d4-8679-460f-91ff-69c45f248562';
    $display->content['new-2381c9d4-8679-460f-91ff-69c45f248562'] = $pane;
    $display->panels['secondary'][3] = 'new-2381c9d4-8679-460f-91ff-69c45f248562';
    $pane = new stdClass();
    $pane->pid = 'new-0a8c5d64-eec0-40f7-a6d6-217e6d8b509d';
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
    $pane->uuid = '0a8c5d64-eec0-40f7-a6d6-217e6d8b509d';
    $display->content['new-0a8c5d64-eec0-40f7-a6d6-217e6d8b509d'] = $pane;
    $display->panels['secondary'][4] = 'new-0a8c5d64-eec0-40f7-a6d6-217e6d8b509d';
    $pane = new stdClass();
    $pane->pid = 'new-dc575078-155c-487f-a11f-6507650efdc6';
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
    $pane->uuid = 'dc575078-155c-487f-a11f-6507650efdc6';
    $display->content['new-dc575078-155c-487f-a11f-6507650efdc6'] = $pane;
    $display->panels['secondary'][5] = 'new-dc575078-155c-487f-a11f-6507650efdc6';
    $pane = new stdClass();
    $pane->pid = 'new-3d867d8c-9be8-4a6d-8188-c23f51f4904b';
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
    $pane->uuid = '3d867d8c-9be8-4a6d-8188-c23f51f4904b';
    $display->content['new-3d867d8c-9be8-4a6d-8188-c23f51f4904b'] = $pane;
    $display->panels['secondary'][6] = 'new-3d867d8c-9be8-4a6d-8188-c23f51f4904b';
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
  $display->uuid = '14b6f55d-fcca-4fff-b75c-9ff455dc44ed';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ab1fd9d3-ef33-4ee3-98ed-ee26320d2035';
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
    $pane->uuid = 'ab1fd9d3-ef33-4ee3-98ed-ee26320d2035';
    $display->content['new-ab1fd9d3-ef33-4ee3-98ed-ee26320d2035'] = $pane;
    $display->panels['follower'][0] = 'new-ab1fd9d3-ef33-4ee3-98ed-ee26320d2035';
    $pane = new stdClass();
    $pane->pid = 'new-ff59ef35-53ce-4e30-962a-2f82f64eeca3';
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
    $pane->uuid = 'ff59ef35-53ce-4e30-962a-2f82f64eeca3';
    $display->content['new-ff59ef35-53ce-4e30-962a-2f82f64eeca3'] = $pane;
    $display->panels['follower'][1] = 'new-ff59ef35-53ce-4e30-962a-2f82f64eeca3';
    $pane = new stdClass();
    $pane->pid = 'new-f161855d-a7ef-4dae-a777-55936246b8e1';
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
    $pane->uuid = 'f161855d-a7ef-4dae-a777-55936246b8e1';
    $display->content['new-f161855d-a7ef-4dae-a777-55936246b8e1'] = $pane;
    $display->panels['leader'][0] = 'new-f161855d-a7ef-4dae-a777-55936246b8e1';
    $pane = new stdClass();
    $pane->pid = 'new-04e17f0e-53fd-4a29-aac0-fccf6298c576';
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
    $pane->uuid = '04e17f0e-53fd-4a29-aac0-fccf6298c576';
    $display->content['new-04e17f0e-53fd-4a29-aac0-fccf6298c576'] = $pane;
    $display->panels['leader'][1] = 'new-04e17f0e-53fd-4a29-aac0-fccf6298c576';
    $pane = new stdClass();
    $pane->pid = 'new-57494efe-2489-4e2c-8df7-e8f1096c1088';
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
    $pane->uuid = '57494efe-2489-4e2c-8df7-e8f1096c1088';
    $display->content['new-57494efe-2489-4e2c-8df7-e8f1096c1088'] = $pane;
    $display->panels['main'][0] = 'new-57494efe-2489-4e2c-8df7-e8f1096c1088';
    $pane = new stdClass();
    $pane->pid = 'new-87210c57-7824-4c67-8e95-291ea3b6563a';
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
    $pane->uuid = '87210c57-7824-4c67-8e95-291ea3b6563a';
    $display->content['new-87210c57-7824-4c67-8e95-291ea3b6563a'] = $pane;
    $display->panels['main'][1] = 'new-87210c57-7824-4c67-8e95-291ea3b6563a';
    $pane = new stdClass();
    $pane->pid = 'new-2e7dff25-59bd-4973-af1b-cab4401e3dd2';
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
    $pane->uuid = '2e7dff25-59bd-4973-af1b-cab4401e3dd2';
    $display->content['new-2e7dff25-59bd-4973-af1b-cab4401e3dd2'] = $pane;
    $display->panels['main'][2] = 'new-2e7dff25-59bd-4973-af1b-cab4401e3dd2';
    $pane = new stdClass();
    $pane->pid = 'new-3615b04a-425f-4293-91a6-98350623984d';
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
    $pane->uuid = '3615b04a-425f-4293-91a6-98350623984d';
    $display->content['new-3615b04a-425f-4293-91a6-98350623984d'] = $pane;
    $display->panels['main'][3] = 'new-3615b04a-425f-4293-91a6-98350623984d';
    $pane = new stdClass();
    $pane->pid = 'new-001e6933-7df1-4051-b044-b72bb9b3bc31';
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
    $pane->uuid = '001e6933-7df1-4051-b044-b72bb9b3bc31';
    $display->content['new-001e6933-7df1-4051-b044-b72bb9b3bc31'] = $pane;
    $display->panels['main'][4] = 'new-001e6933-7df1-4051-b044-b72bb9b3bc31';
    $pane = new stdClass();
    $pane->pid = 'new-85875123-8cc1-444c-a910-d097fdf634af';
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
    $pane->uuid = '85875123-8cc1-444c-a910-d097fdf634af';
    $display->content['new-85875123-8cc1-444c-a910-d097fdf634af'] = $pane;
    $display->panels['main'][5] = 'new-85875123-8cc1-444c-a910-d097fdf634af';
    $pane = new stdClass();
    $pane->pid = 'new-9dd1cde3-f628-49e9-b0c1-979f9c62161c';
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
    $pane->uuid = '9dd1cde3-f628-49e9-b0c1-979f9c62161c';
    $display->content['new-9dd1cde3-f628-49e9-b0c1-979f9c62161c'] = $pane;
    $display->panels['main'][6] = 'new-9dd1cde3-f628-49e9-b0c1-979f9c62161c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:comment:default:teaser'] = $panelizer;

  return $export;
}
