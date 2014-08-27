<?php
/**
 * @file
 * coral_projects_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function coral_projects_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:project:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'project';
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
      'center' => NULL,
      'leader' => NULL,
      'main' => NULL,
      'secondary' => NULL,
      'follower' => NULL,
      'sub_footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '3cbb6626-f9cf-438b-9a32-575ba85c9b76';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2e2dbc4a-211c-4f20-bbdd-070291b10a4a';
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
    $pane->uuid = '2e2dbc4a-211c-4f20-bbdd-070291b10a4a';
    $display->content['new-2e2dbc4a-211c-4f20-bbdd-070291b10a4a'] = $pane;
    $display->panels['main'][0] = 'new-2e2dbc4a-211c-4f20-bbdd-070291b10a4a';
    $pane = new stdClass();
    $pane->pid = 'new-70c2327c-3a67-4038-bd0a-701c14106eda';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '70c2327c-3a67-4038-bd0a-701c14106eda';
    $display->content['new-70c2327c-3a67-4038-bd0a-701c14106eda'] = $pane;
    $display->panels['main'][1] = 'new-70c2327c-3a67-4038-bd0a-701c14106eda';
    $pane = new stdClass();
    $pane->pid = 'new-622ca511-a0c8-4f95-a6f1-715a48c7c798';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'doc_ref_node-teaser_view';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Documentation',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '622ca511-a0c8-4f95-a6f1-715a48c7c798';
    $display->content['new-622ca511-a0c8-4f95-a6f1-715a48c7c798'] = $pane;
    $display->panels['main'][2] = 'new-622ca511-a0c8-4f95-a6f1-715a48c7c798';
    $pane = new stdClass();
    $pane->pid = 'new-339b22a4-5286-4cbe-9630-54f33cef1558';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '339b22a4-5286-4cbe-9630-54f33cef1558';
    $display->content['new-339b22a4-5286-4cbe-9630-54f33cef1558'] = $pane;
    $display->panels['main'][3] = 'new-339b22a4-5286-4cbe-9630-54f33cef1558';
    $pane = new stdClass();
    $pane->pid = 'new-13706c6b-7520-4ceb-8824-bf832a3353cd';
    $pane->panel = 'secondary';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '13706c6b-7520-4ceb-8824-bf832a3353cd';
    $display->content['new-13706c6b-7520-4ceb-8824-bf832a3353cd'] = $pane;
    $display->panels['secondary'][0] = 'new-13706c6b-7520-4ceb-8824-bf832a3353cd';
    $pane = new stdClass();
    $pane->pid = 'new-fd344a57-e6f3-4faf-ba91-436d0952fb45';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'fd344a57-e6f3-4faf-ba91-436d0952fb45';
    $display->content['new-fd344a57-e6f3-4faf-ba91-436d0952fb45'] = $pane;
    $display->panels['secondary'][1] = 'new-fd344a57-e6f3-4faf-ba91-436d0952fb45';
    $pane = new stdClass();
    $pane->pid = 'new-9c815766-93d7-4775-b544-76fdfd61a17b';
    $pane->panel = 'secondary';
    $pane->type = 'views_panes';
    $pane->subtype = 'tags_popular-popular_project_tags';
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
    $pane->uuid = '9c815766-93d7-4775-b544-76fdfd61a17b';
    $display->content['new-9c815766-93d7-4775-b544-76fdfd61a17b'] = $pane;
    $display->panels['secondary'][2] = 'new-9c815766-93d7-4775-b544-76fdfd61a17b';
    $pane = new stdClass();
    $pane->pid = 'new-e4e65a6b-6e19-4cdc-ade5-8bb806fea58b';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e4e65a6b-6e19-4cdc-ade5-8bb806fea58b';
    $display->content['new-e4e65a6b-6e19-4cdc-ade5-8bb806fea58b'] = $pane;
    $display->panels['secondary'][3] = 'new-e4e65a6b-6e19-4cdc-ade5-8bb806fea58b';
    $pane = new stdClass();
    $pane->pid = 'new-596878bc-bcc0-4441-8fe3-6f7d31070aa4';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '596878bc-bcc0-4441-8fe3-6f7d31070aa4';
    $display->content['new-596878bc-bcc0-4441-8fe3-6f7d31070aa4'] = $pane;
    $display->panels['secondary'][4] = 'new-596878bc-bcc0-4441-8fe3-6f7d31070aa4';
    $pane = new stdClass();
    $pane->pid = 'new-fda334ef-fe2e-4248-9e2e-e00b2ab568e0';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'fda334ef-fe2e-4248-9e2e-e00b2ab568e0';
    $display->content['new-fda334ef-fe2e-4248-9e2e-e00b2ab568e0'] = $pane;
    $display->panels['secondary'][5] = 'new-fda334ef-fe2e-4248-9e2e-e00b2ab568e0';
    $pane = new stdClass();
    $pane->pid = 'new-f25c680e-84ce-4f3b-b448-dab2824db2a7';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'f25c680e-84ce-4f3b-b448-dab2824db2a7';
    $display->content['new-f25c680e-84ce-4f3b-b448-dab2824db2a7'] = $pane;
    $display->panels['secondary'][6] = 'new-f25c680e-84ce-4f3b-b448-dab2824db2a7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:project:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:project:default:teaser';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'project';
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '6906e90b-a220-48c7-888f-2adfd0ecf9de';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e3ab757c-8729-4fdd-bb74-aca2893f1046';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_project_reference';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 1,
      ),
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
    $pane->uuid = 'e3ab757c-8729-4fdd-bb74-aca2893f1046';
    $display->content['new-e3ab757c-8729-4fdd-bb74-aca2893f1046'] = $pane;
    $display->panels['middle'][0] = 'new-e3ab757c-8729-4fdd-bb74-aca2893f1046';
    $pane = new stdClass();
    $pane->pid = 'new-fd936b31-6afb-4c91-b57a-0d0ba884263a';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_summary_or_trimmed',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'trim_length' => 600,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'fd936b31-6afb-4c91-b57a-0d0ba884263a';
    $display->content['new-fd936b31-6afb-4c91-b57a-0d0ba884263a'] = $pane;
    $display->panels['middle'][1] = 'new-fd936b31-6afb-4c91-b57a-0d0ba884263a';
    $pane = new stdClass();
    $pane->pid = 'new-3e3a58cf-65d3-47aa-8de5-a790336b291f';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_item_featureset';
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
    $pane->uuid = '3e3a58cf-65d3-47aa-8de5-a790336b291f';
    $display->content['new-3e3a58cf-65d3-47aa-8de5-a790336b291f'] = $pane;
    $display->panels['middle'][2] = 'new-3e3a58cf-65d3-47aa-8de5-a790336b291f';
    $pane = new stdClass();
    $pane->pid = 'new-d8e6f8a2-cd5b-4648-8ce3-04591faad613';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_documentation_reference';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 1,
      ),
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'd8e6f8a2-cd5b-4648-8ce3-04591faad613';
    $display->content['new-d8e6f8a2-cd5b-4648-8ce3-04591faad613'] = $pane;
    $display->panels['middle'][3] = 'new-d8e6f8a2-cd5b-4648-8ce3-04591faad613';
    $pane = new stdClass();
    $pane->pid = 'new-da740f8e-94ab-41f1-ac1f-a52817813cdc';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_project_repo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'da740f8e-94ab-41f1-ac1f-a52817813cdc';
    $display->content['new-da740f8e-94ab-41f1-ac1f-a52817813cdc'] = $pane;
    $display->panels['middle'][4] = 'new-da740f8e-94ab-41f1-ac1f-a52817813cdc';
    $pane = new stdClass();
    $pane->pid = 'new-33e36352-d529-4183-8b2e-3d3c01f9e74f';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_issue_queue';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '33e36352-d529-4183-8b2e-3d3c01f9e74f';
    $display->content['new-33e36352-d529-4183-8b2e-3d3c01f9e74f'] = $pane;
    $display->panels['middle'][5] = 'new-33e36352-d529-4183-8b2e-3d3c01f9e74f';
    $pane = new stdClass();
    $pane->pid = 'new-ce053424-1790-4485-b8d1-1e97fd78a05d';
    $pane->panel = 'middle';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'build_mode' => 'full',
      'identifier' => '',
      'link' => 0,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'ce053424-1790-4485-b8d1-1e97fd78a05d';
    $display->content['new-ce053424-1790-4485-b8d1-1e97fd78a05d'] = $pane;
    $display->panels['middle'][6] = 'new-ce053424-1790-4485-b8d1-1e97fd78a05d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:project:default:teaser'] = $panelizer;

  return $export;
}
