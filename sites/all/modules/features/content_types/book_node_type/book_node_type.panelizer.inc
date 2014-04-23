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
  $display->uuid = '3a772e56-5299-4b4a-9e63-2354db5e8663';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4607e3ab-d747-4406-bcbf-84d9753952c6';
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
    $pane->uuid = '4607e3ab-d747-4406-bcbf-84d9753952c6';
    $display->content['new-4607e3ab-d747-4406-bcbf-84d9753952c6'] = $pane;
    $display->panels['middle'][0] = 'new-4607e3ab-d747-4406-bcbf-84d9753952c6';
    $pane = new stdClass();
    $pane->pid = 'new-409e97c0-92f8-4c5e-9c47-d0d1cf22c3c3';
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
    $pane->uuid = '409e97c0-92f8-4c5e-9c47-d0d1cf22c3c3';
    $display->content['new-409e97c0-92f8-4c5e-9c47-d0d1cf22c3c3'] = $pane;
    $display->panels['middle'][1] = 'new-409e97c0-92f8-4c5e-9c47-d0d1cf22c3c3';
    $pane = new stdClass();
    $pane->pid = 'new-e1756898-28ec-4d3e-80db-17c3cf53c911';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e1756898-28ec-4d3e-80db-17c3cf53c911';
    $display->content['new-e1756898-28ec-4d3e-80db-17c3cf53c911'] = $pane;
    $display->panels['middle'][2] = 'new-e1756898-28ec-4d3e-80db-17c3cf53c911';
    $pane = new stdClass();
    $pane->pid = 'new-4ae02015-ad2f-47f7-b6b0-a188e1150eb0';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '4ae02015-ad2f-47f7-b6b0-a188e1150eb0';
    $display->content['new-4ae02015-ad2f-47f7-b6b0-a188e1150eb0'] = $pane;
    $display->panels['middle'][3] = 'new-4ae02015-ad2f-47f7-b6b0-a188e1150eb0';
    $pane = new stdClass();
    $pane->pid = 'new-94ce3ee6-081b-4c20-98b6-1c19cf434729';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '94ce3ee6-081b-4c20-98b6-1c19cf434729';
    $display->content['new-94ce3ee6-081b-4c20-98b6-1c19cf434729'] = $pane;
    $display->panels['middle'][4] = 'new-94ce3ee6-081b-4c20-98b6-1c19cf434729';
    $pane = new stdClass();
    $pane->pid = 'new-86ca9e21-81af-4860-95ac-4b10a305cb17';
    $pane->panel = 'middle';
    $pane->type = 'node_book_nav';
    $pane->subtype = 'node_book_nav';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'Book navigation',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '86ca9e21-81af-4860-95ac-4b10a305cb17';
    $display->content['new-86ca9e21-81af-4860-95ac-4b10a305cb17'] = $pane;
    $display->panels['middle'][5] = 'new-86ca9e21-81af-4860-95ac-4b10a305cb17';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4607e3ab-d747-4406-bcbf-84d9753952c6';
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
  $display->uuid = 'cec0a6a0-6157-4b15-8c9b-d65d2009f8c7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-91395844-b368-49aa-b912-e475c465f1e6';
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
    $pane->uuid = '91395844-b368-49aa-b912-e475c465f1e6';
    $display->content['new-91395844-b368-49aa-b912-e475c465f1e6'] = $pane;
    $display->panels['middle'][0] = 'new-91395844-b368-49aa-b912-e475c465f1e6';
    $pane = new stdClass();
    $pane->pid = 'new-3cac2109-080b-49ac-a0be-63f6341371ad';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3cac2109-080b-49ac-a0be-63f6341371ad';
    $display->content['new-3cac2109-080b-49ac-a0be-63f6341371ad'] = $pane;
    $display->panels['middle'][1] = 'new-3cac2109-080b-49ac-a0be-63f6341371ad';
    $pane = new stdClass();
    $pane->pid = 'new-ac46bdb2-35f0-47e5-8505-b03667bd8c36';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ac46bdb2-35f0-47e5-8505-b03667bd8c36';
    $display->content['new-ac46bdb2-35f0-47e5-8505-b03667bd8c36'] = $pane;
    $display->panels['middle'][2] = 'new-ac46bdb2-35f0-47e5-8505-b03667bd8c36';
    $pane = new stdClass();
    $pane->pid = 'new-0124bc4b-c049-4c2b-a818-313491dcac46';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '0124bc4b-c049-4c2b-a818-313491dcac46';
    $display->content['new-0124bc4b-c049-4c2b-a818-313491dcac46'] = $pane;
    $display->panels['middle'][3] = 'new-0124bc4b-c049-4c2b-a818-313491dcac46';
    $pane = new stdClass();
    $pane->pid = 'new-8e6dd694-8d54-4be3-8906-a8fb08362e6d';
    $pane->panel = 'middle';
    $pane->type = 'node_book_nav';
    $pane->subtype = 'node_book_nav';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'Book navigation',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '8e6dd694-8d54-4be3-8906-a8fb08362e6d';
    $display->content['new-8e6dd694-8d54-4be3-8906-a8fb08362e6d'] = $pane;
    $display->panels['middle'][4] = 'new-8e6dd694-8d54-4be3-8906-a8fb08362e6d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:book:default:teaser'] = $panelizer;

  return $export;
}
