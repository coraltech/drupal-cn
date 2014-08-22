<?php
/**
 * @file
 * book_node_type.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function book_node_type_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:book:default:full_node';
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
  $panelizer->view_mode = 'full_node';
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
  $display->uuid = 'de115e36-b1c9-4f2b-aab6-84ce96c1f9a5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5557945a-b5dc-437b-a9bf-c105dba2bcb4';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_locked';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5557945a-b5dc-437b-a9bf-c105dba2bcb4';
    $display->content['new-5557945a-b5dc-437b-a9bf-c105dba2bcb4'] = $pane;
    $display->panels['middle'][0] = 'new-5557945a-b5dc-437b-a9bf-c105dba2bcb4';
    $pane = new stdClass();
    $pane->pid = 'new-7e9dd557-8bdd-4e57-be76-5862c644d79f';
    $pane->panel = 'middle';
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
    $pane->uuid = '7e9dd557-8bdd-4e57-be76-5862c644d79f';
    $display->content['new-7e9dd557-8bdd-4e57-be76-5862c644d79f'] = $pane;
    $display->panels['middle'][1] = 'new-7e9dd557-8bdd-4e57-be76-5862c644d79f';
    $pane = new stdClass();
    $pane->pid = 'new-8f336474-1df6-478a-b46b-dd9142bd7411';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_timeline_title';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8f336474-1df6-478a-b46b-dd9142bd7411';
    $display->content['new-8f336474-1df6-478a-b46b-dd9142bd7411'] = $pane;
    $display->panels['middle'][2] = 'new-8f336474-1df6-478a-b46b-dd9142bd7411';
    $pane = new stdClass();
    $pane->pid = 'new-d356dd8c-679a-4d08-81b1-10cc0783d008';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_book_timeline';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'd356dd8c-679a-4d08-81b1-10cc0783d008';
    $display->content['new-d356dd8c-679a-4d08-81b1-10cc0783d008'] = $pane;
    $display->panels['middle'][3] = 'new-d356dd8c-679a-4d08-81b1-10cc0783d008';
    $pane = new stdClass();
    $pane->pid = 'new-e0fa7df0-6077-4cd5-ab03-e194e8b94c55';
    $pane->panel = 'middle';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grid-14',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'e0fa7df0-6077-4cd5-ab03-e194e8b94c55';
    $display->content['new-e0fa7df0-6077-4cd5-ab03-e194e8b94c55'] = $pane;
    $display->panels['middle'][4] = 'new-e0fa7df0-6077-4cd5-ab03-e194e8b94c55';
    $pane = new stdClass();
    $pane->pid = 'new-961f787b-0e58-4fb6-a277-58399ce16a9d';
    $pane->panel = 'middle';
    $pane->type = 'coral_node_stats';
    $pane->subtype = 'coral_node_stats';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => FALSE,
      'display_stats' => array(
        2 => '2',
        3 => '3',
        1 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
      ),
      'display_style' => '1',
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
      'css_class' => 'grid-10-last',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '961f787b-0e58-4fb6-a277-58399ce16a9d';
    $display->content['new-961f787b-0e58-4fb6-a277-58399ce16a9d'] = $pane;
    $display->panels['middle'][5] = 'new-961f787b-0e58-4fb6-a277-58399ce16a9d';
    $pane = new stdClass();
    $pane->pid = 'new-4cc5d6e9-bcbf-4e7d-9e65-69da7d656193';
    $pane->panel = 'middle';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'build_mode' => 'full',
      'identifier' => '',
      'link' => 1,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper clear clearfix',
      'css_id' => '',
    );
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '4cc5d6e9-bcbf-4e7d-9e65-69da7d656193';
    $display->content['new-4cc5d6e9-bcbf-4e7d-9e65-69da7d656193'] = $pane;
    $display->panels['middle'][6] = 'new-4cc5d6e9-bcbf-4e7d-9e65-69da7d656193';
    $pane = new stdClass();
    $pane->pid = 'new-a6f6f460-affb-432b-93f8-ac7eb8ae22b9';
    $pane->panel = 'middle';
    $pane->type = 'node_book_nav';
    $pane->subtype = 'node_book_nav';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'Navigation',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'a6f6f460-affb-432b-93f8-ac7eb8ae22b9';
    $display->content['new-a6f6f460-affb-432b-93f8-ac7eb8ae22b9'] = $pane;
    $display->panels['middle'][7] = 'new-a6f6f460-affb-432b-93f8-ac7eb8ae22b9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5557945a-b5dc-437b-a9bf-c105dba2bcb4';
  $panelizer->display = $display;
  $export['node:book:default:full_node'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:book:default:teaser';
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
  $display->uuid = '693dee7c-27bd-42e9-b276-64463be0fd2e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-386e16f7-024d-476e-9523-f86c1cc9a8a0';
    $pane->panel = 'middle';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '386e16f7-024d-476e-9523-f86c1cc9a8a0';
    $display->content['new-386e16f7-024d-476e-9523-f86c1cc9a8a0'] = $pane;
    $display->panels['middle'][0] = 'new-386e16f7-024d-476e-9523-f86c1cc9a8a0';
    $pane = new stdClass();
    $pane->pid = 'new-ccf8752d-7ce9-47db-b2c0-4831a62bfde9';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'book_timeline';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ccf8752d-7ce9-47db-b2c0-4831a62bfde9';
    $display->content['new-ccf8752d-7ce9-47db-b2c0-4831a62bfde9'] = $pane;
    $display->panels['middle'][1] = 'new-ccf8752d-7ce9-47db-b2c0-4831a62bfde9';
    $pane = new stdClass();
    $pane->pid = 'new-7c8e119f-bf5e-4c9b-b21b-6447a023bf41';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_timeline_title';
    $pane->shown = FALSE;
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7c8e119f-bf5e-4c9b-b21b-6447a023bf41';
    $display->content['new-7c8e119f-bf5e-4c9b-b21b-6447a023bf41'] = $pane;
    $display->panels['middle'][2] = 'new-7c8e119f-bf5e-4c9b-b21b-6447a023bf41';
    $pane = new stdClass();
    $pane->pid = 'new-1552c923-1aec-4658-b5d4-e4027f35e5f3';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_book_timeline';
    $pane->shown = FALSE;
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '1552c923-1aec-4658-b5d4-e4027f35e5f3';
    $display->content['new-1552c923-1aec-4658-b5d4-e4027f35e5f3'] = $pane;
    $display->panels['middle'][3] = 'new-1552c923-1aec-4658-b5d4-e4027f35e5f3';
    $pane = new stdClass();
    $pane->pid = 'new-effc692f-800c-496d-a978-0fe6dd8ba885';
    $pane->panel = 'middle';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grid-14',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'effc692f-800c-496d-a978-0fe6dd8ba885';
    $display->content['new-effc692f-800c-496d-a978-0fe6dd8ba885'] = $pane;
    $display->panels['middle'][4] = 'new-effc692f-800c-496d-a978-0fe6dd8ba885';
    $pane = new stdClass();
    $pane->pid = 'new-38602890-c003-4e3e-9cc1-1c32ef4a56a1';
    $pane->panel = 'middle';
    $pane->type = 'coral_node_stats';
    $pane->subtype = 'coral_node_stats';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => FALSE,
      'display_stats' => array(
        2 => '2',
        3 => '3',
        1 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
      ),
      'display_style' => '1',
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
      'css_class' => 'grid-10-last',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '38602890-c003-4e3e-9cc1-1c32ef4a56a1';
    $display->content['new-38602890-c003-4e3e-9cc1-1c32ef4a56a1'] = $pane;
    $display->panels['middle'][5] = 'new-38602890-c003-4e3e-9cc1-1c32ef4a56a1';
    $pane = new stdClass();
    $pane->pid = 'new-e68795d8-601f-4094-ba5a-c18e2393c3b6';
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
      'link' => 1,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper clear clearfix',
      'css_id' => '',
    );
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'e68795d8-601f-4094-ba5a-c18e2393c3b6';
    $display->content['new-e68795d8-601f-4094-ba5a-c18e2393c3b6'] = $pane;
    $display->panels['middle'][6] = 'new-e68795d8-601f-4094-ba5a-c18e2393c3b6';
    $pane = new stdClass();
    $pane->pid = 'new-565e3d99-bdeb-4543-81a7-113cddb50c22';
    $pane->panel = 'middle';
    $pane->type = 'node_book_nav';
    $pane->subtype = 'node_book_nav';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'Navigation',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '565e3d99-bdeb-4543-81a7-113cddb50c22';
    $display->content['new-565e3d99-bdeb-4543-81a7-113cddb50c22'] = $pane;
    $display->panels['middle'][7] = 'new-565e3d99-bdeb-4543-81a7-113cddb50c22';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:book:default:teaser'] = $panelizer;

  return $export;
}
