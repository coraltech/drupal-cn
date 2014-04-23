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
  $display->uuid = 'd1ed4bf2-646b-4529-87d9-1f87b030fbd8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-34707adc-67bc-49a8-a224-4eb9451b8139';
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
    $pane->uuid = '34707adc-67bc-49a8-a224-4eb9451b8139';
    $display->content['new-34707adc-67bc-49a8-a224-4eb9451b8139'] = $pane;
    $display->panels['main'][0] = 'new-34707adc-67bc-49a8-a224-4eb9451b8139';
    $pane = new stdClass();
    $pane->pid = 'new-4a39adb9-abb0-4fcb-85a4-0cc8274c700f';
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
    $pane->uuid = '4a39adb9-abb0-4fcb-85a4-0cc8274c700f';
    $display->content['new-4a39adb9-abb0-4fcb-85a4-0cc8274c700f'] = $pane;
    $display->panels['main'][1] = 'new-4a39adb9-abb0-4fcb-85a4-0cc8274c700f';
    $pane = new stdClass();
    $pane->pid = 'new-830336ac-08db-44bf-bd52-6b809b98b18d';
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
    $pane->uuid = '830336ac-08db-44bf-bd52-6b809b98b18d';
    $display->content['new-830336ac-08db-44bf-bd52-6b809b98b18d'] = $pane;
    $display->panels['main'][2] = 'new-830336ac-08db-44bf-bd52-6b809b98b18d';
    $pane = new stdClass();
    $pane->pid = 'new-2e6ef27b-6efa-4990-960c-aa020e0ffb4a';
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
    $pane->uuid = '2e6ef27b-6efa-4990-960c-aa020e0ffb4a';
    $display->content['new-2e6ef27b-6efa-4990-960c-aa020e0ffb4a'] = $pane;
    $display->panels['main'][3] = 'new-2e6ef27b-6efa-4990-960c-aa020e0ffb4a';
    $pane = new stdClass();
    $pane->pid = 'new-60c2bd45-85c9-4948-982b-8f77cc4061c4';
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
    $pane->uuid = '60c2bd45-85c9-4948-982b-8f77cc4061c4';
    $display->content['new-60c2bd45-85c9-4948-982b-8f77cc4061c4'] = $pane;
    $display->panels['secondary'][0] = 'new-60c2bd45-85c9-4948-982b-8f77cc4061c4';
    $pane = new stdClass();
    $pane->pid = 'new-a7702ff1-fd85-495a-ba2b-70811ca39c24';
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
    $pane->uuid = 'a7702ff1-fd85-495a-ba2b-70811ca39c24';
    $display->content['new-a7702ff1-fd85-495a-ba2b-70811ca39c24'] = $pane;
    $display->panels['secondary'][1] = 'new-a7702ff1-fd85-495a-ba2b-70811ca39c24';
    $pane = new stdClass();
    $pane->pid = 'new-00a418be-e3c9-45e2-8da0-5259ef6b6444';
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
    $pane->uuid = '00a418be-e3c9-45e2-8da0-5259ef6b6444';
    $display->content['new-00a418be-e3c9-45e2-8da0-5259ef6b6444'] = $pane;
    $display->panels['secondary'][2] = 'new-00a418be-e3c9-45e2-8da0-5259ef6b6444';
    $pane = new stdClass();
    $pane->pid = 'new-96d74556-c8cd-4822-a697-cc3184bcda80';
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
    $pane->uuid = '96d74556-c8cd-4822-a697-cc3184bcda80';
    $display->content['new-96d74556-c8cd-4822-a697-cc3184bcda80'] = $pane;
    $display->panels['secondary'][3] = 'new-96d74556-c8cd-4822-a697-cc3184bcda80';
    $pane = new stdClass();
    $pane->pid = 'new-02687bbb-66e2-4d3c-a7db-3dbce63fc3c4';
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
    $pane->uuid = '02687bbb-66e2-4d3c-a7db-3dbce63fc3c4';
    $display->content['new-02687bbb-66e2-4d3c-a7db-3dbce63fc3c4'] = $pane;
    $display->panels['secondary'][4] = 'new-02687bbb-66e2-4d3c-a7db-3dbce63fc3c4';
    $pane = new stdClass();
    $pane->pid = 'new-b6d453c0-0306-4956-a0d2-3b818a15c8d1';
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
    $pane->uuid = 'b6d453c0-0306-4956-a0d2-3b818a15c8d1';
    $display->content['new-b6d453c0-0306-4956-a0d2-3b818a15c8d1'] = $pane;
    $display->panels['secondary'][5] = 'new-b6d453c0-0306-4956-a0d2-3b818a15c8d1';
    $pane = new stdClass();
    $pane->pid = 'new-92a400b1-a708-4fd0-bc7c-263b3b93ee1f';
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
    $pane->uuid = '92a400b1-a708-4fd0-bc7c-263b3b93ee1f';
    $display->content['new-92a400b1-a708-4fd0-bc7c-263b3b93ee1f'] = $pane;
    $display->panels['secondary'][6] = 'new-92a400b1-a708-4fd0-bc7c-263b3b93ee1f';
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
  $display->uuid = '99ab0e8a-9f73-492d-b300-c0f6ddd340d3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-106e1ca9-be85-4c51-968a-8d515659819b';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '106e1ca9-be85-4c51-968a-8d515659819b';
    $display->content['new-106e1ca9-be85-4c51-968a-8d515659819b'] = $pane;
    $display->panels['middle'][0] = 'new-106e1ca9-be85-4c51-968a-8d515659819b';
    $pane = new stdClass();
    $pane->pid = 'new-4a45b0cb-48e2-4f9b-b7ba-b78a82a0ff6f';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4a45b0cb-48e2-4f9b-b7ba-b78a82a0ff6f';
    $display->content['new-4a45b0cb-48e2-4f9b-b7ba-b78a82a0ff6f'] = $pane;
    $display->panels['middle'][1] = 'new-4a45b0cb-48e2-4f9b-b7ba-b78a82a0ff6f';
    $pane = new stdClass();
    $pane->pid = 'new-2a984539-693b-4e1c-9f26-f1a8e5b98ebe';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2a984539-693b-4e1c-9f26-f1a8e5b98ebe';
    $display->content['new-2a984539-693b-4e1c-9f26-f1a8e5b98ebe'] = $pane;
    $display->panels['middle'][2] = 'new-2a984539-693b-4e1c-9f26-f1a8e5b98ebe';
    $pane = new stdClass();
    $pane->pid = 'new-e05da29e-2877-417e-a174-1267546bb8a9';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e05da29e-2877-417e-a174-1267546bb8a9';
    $display->content['new-e05da29e-2877-417e-a174-1267546bb8a9'] = $pane;
    $display->panels['middle'][3] = 'new-e05da29e-2877-417e-a174-1267546bb8a9';
    $pane = new stdClass();
    $pane->pid = 'new-f5ddd38c-0491-40d0-9b1b-3b001ce01b4c';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'f5ddd38c-0491-40d0-9b1b-3b001ce01b4c';
    $display->content['new-f5ddd38c-0491-40d0-9b1b-3b001ce01b4c'] = $pane;
    $display->panels['middle'][4] = 'new-f5ddd38c-0491-40d0-9b1b-3b001ce01b4c';
    $pane = new stdClass();
    $pane->pid = 'new-81b8cf01-24ae-46ad-8294-a1ca7f24270b';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '81b8cf01-24ae-46ad-8294-a1ca7f24270b';
    $display->content['new-81b8cf01-24ae-46ad-8294-a1ca7f24270b'] = $pane;
    $display->panels['middle'][5] = 'new-81b8cf01-24ae-46ad-8294-a1ca7f24270b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:project:default:teaser'] = $panelizer;

  return $export;
}
