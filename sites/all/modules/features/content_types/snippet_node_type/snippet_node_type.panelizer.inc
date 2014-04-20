<?php
/**
 * @file
 * snippet_node_type.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function snippet_node_type_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:snippet:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'snippet';
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
  $display->uuid = '45153a1d-51f2-4b4d-b795-17bc1693689f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f5b2baf0-3930-4aff-bc4a-9b68fd6f666e';
    $pane->panel = 'leader';
    $pane->type = 'coral_snippets_intro';
    $pane->subtype = 'coral_snippets_intro';
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
    $pane->uuid = 'f5b2baf0-3930-4aff-bc4a-9b68fd6f666e';
    $display->content['new-f5b2baf0-3930-4aff-bc4a-9b68fd6f666e'] = $pane;
    $display->panels['leader'][0] = 'new-f5b2baf0-3930-4aff-bc4a-9b68fd6f666e';
    $pane = new stdClass();
    $pane->pid = 'new-8e83b23a-62ac-4d5d-9ef2-b1921e2eba8f';
    $pane->panel = 'main';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full_node',
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
    $pane->uuid = '8e83b23a-62ac-4d5d-9ef2-b1921e2eba8f';
    $display->content['new-8e83b23a-62ac-4d5d-9ef2-b1921e2eba8f'] = $pane;
    $display->panels['main'][0] = 'new-8e83b23a-62ac-4d5d-9ef2-b1921e2eba8f';
    $pane = new stdClass();
    $pane->pid = 'new-16a3db40-81eb-4894-bed5-fe2a0ff15a45';
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
    $pane->uuid = '16a3db40-81eb-4894-bed5-fe2a0ff15a45';
    $display->content['new-16a3db40-81eb-4894-bed5-fe2a0ff15a45'] = $pane;
    $display->panels['secondary'][0] = 'new-16a3db40-81eb-4894-bed5-fe2a0ff15a45';
    $pane = new stdClass();
    $pane->pid = 'new-434524c6-7792-4168-ad74-b0b016163d23';
    $pane->panel = 'secondary';
    $pane->type = 'views_panes';
    $pane->subtype = 'tags_popular-popular_snippet_tags';
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
    $pane->uuid = '434524c6-7792-4168-ad74-b0b016163d23';
    $display->content['new-434524c6-7792-4168-ad74-b0b016163d23'] = $pane;
    $display->panels['secondary'][1] = 'new-434524c6-7792-4168-ad74-b0b016163d23';
    $pane = new stdClass();
    $pane->pid = 'new-ee05cdcb-919e-4677-ba82-09dc4fcf6598';
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
    $pane->uuid = 'ee05cdcb-919e-4677-ba82-09dc4fcf6598';
    $display->content['new-ee05cdcb-919e-4677-ba82-09dc4fcf6598'] = $pane;
    $display->panels['secondary'][2] = 'new-ee05cdcb-919e-4677-ba82-09dc4fcf6598';
    $pane = new stdClass();
    $pane->pid = 'new-b4325f57-f55f-4b29-8497-d3b0633db18e';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'b4325f57-f55f-4b29-8497-d3b0633db18e';
    $display->content['new-b4325f57-f55f-4b29-8497-d3b0633db18e'] = $pane;
    $display->panels['secondary'][3] = 'new-b4325f57-f55f-4b29-8497-d3b0633db18e';
    $pane = new stdClass();
    $pane->pid = 'new-6e4083f1-4ff0-463e-a792-4a8d76761d17';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '6e4083f1-4ff0-463e-a792-4a8d76761d17';
    $display->content['new-6e4083f1-4ff0-463e-a792-4a8d76761d17'] = $pane;
    $display->panels['secondary'][4] = 'new-6e4083f1-4ff0-463e-a792-4a8d76761d17';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:snippet:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:snippet:default:full_node';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'snippet';
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
      'center' => NULL,
      'middle' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'b2a2824f-65c9-42dd-946f-718f460961bb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7a09b2ce-3ebc-4b94-8745-6166b7f2f156';
    $pane->panel = 'middle';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7a09b2ce-3ebc-4b94-8745-6166b7f2f156';
    $display->content['new-7a09b2ce-3ebc-4b94-8745-6166b7f2f156'] = $pane;
    $display->panels['middle'][0] = 'new-7a09b2ce-3ebc-4b94-8745-6166b7f2f156';
    $pane = new stdClass();
    $pane->pid = 'new-14255577-37bd-4cf0-9ee4-7050c1c225f8';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '14255577-37bd-4cf0-9ee4-7050c1c225f8';
    $display->content['new-14255577-37bd-4cf0-9ee4-7050c1c225f8'] = $pane;
    $display->panels['middle'][1] = 'new-14255577-37bd-4cf0-9ee4-7050c1c225f8';
    $pane = new stdClass();
    $pane->pid = 'new-08ce003a-8faf-45ef-867d-5aba65ffb1d2';
    $pane->panel = 'middle';
    $pane->type = 'coral_flag_abuse_node';
    $pane->subtype = 'coral_flag_abuse_node';
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
    $pane->uuid = '08ce003a-8faf-45ef-867d-5aba65ffb1d2';
    $display->content['new-08ce003a-8faf-45ef-867d-5aba65ffb1d2'] = $pane;
    $display->panels['middle'][2] = 'new-08ce003a-8faf-45ef-867d-5aba65ffb1d2';
    $pane = new stdClass();
    $pane->pid = 'new-0404bd11-549f-4a85-a895-3926f9a2dce1';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '0404bd11-549f-4a85-a895-3926f9a2dce1';
    $display->content['new-0404bd11-549f-4a85-a895-3926f9a2dce1'] = $pane;
    $display->panels['middle'][3] = 'new-0404bd11-549f-4a85-a895-3926f9a2dce1';
    $pane = new stdClass();
    $pane->pid = 'new-6c9e0b55-f1dc-4e78-b326-d4e3f8f404f3';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_snippet_components';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'edit' => 'Edit',
        'delete' => 'Delete',
        'add' => 'Add',
        'description' => 1,
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '6c9e0b55-f1dc-4e78-b326-d4e3f8f404f3';
    $display->content['new-6c9e0b55-f1dc-4e78-b326-d4e3f8f404f3'] = $pane;
    $display->panels['middle'][4] = 'new-6c9e0b55-f1dc-4e78-b326-d4e3f8f404f3';
    $pane = new stdClass();
    $pane->pid = 'new-1ace2d4d-5478-4c30-83d9-8a06dd1ef3f7';
    $pane->panel = 'middle';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '1ace2d4d-5478-4c30-83d9-8a06dd1ef3f7';
    $display->content['new-1ace2d4d-5478-4c30-83d9-8a06dd1ef3f7'] = $pane;
    $display->panels['middle'][5] = 'new-1ace2d4d-5478-4c30-83d9-8a06dd1ef3f7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:snippet:default:full_node'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:snippet:default:teaser';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'snippet';
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
      'center' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'bcc7294c-fcfd-41df-9ac8-2e162e0a4d6c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6c23d77a-89a2-4560-9b51-e684e996f5cd';
    $pane->panel = 'middle';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6c23d77a-89a2-4560-9b51-e684e996f5cd';
    $display->content['new-6c23d77a-89a2-4560-9b51-e684e996f5cd'] = $pane;
    $display->panels['middle'][0] = 'new-6c23d77a-89a2-4560-9b51-e684e996f5cd';
    $pane = new stdClass();
    $pane->pid = 'new-9f5b957c-1617-492b-a576-49843c73794a';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9f5b957c-1617-492b-a576-49843c73794a';
    $display->content['new-9f5b957c-1617-492b-a576-49843c73794a'] = $pane;
    $display->panels['middle'][1] = 'new-9f5b957c-1617-492b-a576-49843c73794a';
    $pane = new stdClass();
    $pane->pid = 'new-3e0d323f-6818-48d8-b328-4361ace1ace0';
    $pane->panel = 'middle';
    $pane->type = 'coral_flag_abuse_node';
    $pane->subtype = 'coral_flag_abuse_node';
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
    $pane->uuid = '3e0d323f-6818-48d8-b328-4361ace1ace0';
    $display->content['new-3e0d323f-6818-48d8-b328-4361ace1ace0'] = $pane;
    $display->panels['middle'][2] = 'new-3e0d323f-6818-48d8-b328-4361ace1ace0';
    $pane = new stdClass();
    $pane->pid = 'new-00824765-5f46-4c9a-adb0-d174f6ff5dd1';
    $pane->panel = 'middle';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'build_mode' => 'teaser',
      'identifier' => '',
      'link' => 1,
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '00824765-5f46-4c9a-adb0-d174f6ff5dd1';
    $display->content['new-00824765-5f46-4c9a-adb0-d174f6ff5dd1'] = $pane;
    $display->panels['middle'][3] = 'new-00824765-5f46-4c9a-adb0-d174f6ff5dd1';
    $pane = new stdClass();
    $pane->pid = 'new-1cd02e81-800b-4a65-8f33-6ce356be2345';
    $pane->panel = 'middle';
    $pane->type = 'coral_snippet_components';
    $pane->subtype = 'coral_snippet_components';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '1cd02e81-800b-4a65-8f33-6ce356be2345';
    $display->content['new-1cd02e81-800b-4a65-8f33-6ce356be2345'] = $pane;
    $display->panels['middle'][4] = 'new-1cd02e81-800b-4a65-8f33-6ce356be2345';
    $pane = new stdClass();
    $pane->pid = 'new-ca7ccddf-e48a-4d25-9780-ba1029467133';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_snippet_components';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'edit' => 'Edit',
        'delete' => 'Delete',
        'add' => 'Add',
        'description' => 1,
        'view_mode' => 'full',
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'ca7ccddf-e48a-4d25-9780-ba1029467133';
    $display->content['new-ca7ccddf-e48a-4d25-9780-ba1029467133'] = $pane;
    $display->panels['middle'][5] = 'new-ca7ccddf-e48a-4d25-9780-ba1029467133';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:snippet:default:teaser'] = $panelizer;

  return $export;
}
