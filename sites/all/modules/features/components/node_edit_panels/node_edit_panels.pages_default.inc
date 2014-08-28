<?php
/**
 * @file
 * node_edit_panels.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function node_edit_panels_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Default create',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
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
  $display->title = '';
  $display->uuid = '7018f54b-5b99-4d8c-8349-92f1ab31ee70';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1039c561-9aa9-47b1-9979-4d669d880987';
    $pane->panel = 'middle';
    $pane->type = 'coral_page_title';
    $pane->subtype = 'coral_page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => 'page-title',
      'id' => 'page-title',
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
    $pane->uuid = '1039c561-9aa9-47b1-9979-4d669d880987';
    $display->content['new-1039c561-9aa9-47b1-9979-4d669d880987'] = $pane;
    $display->panels['middle'][0] = 'new-1039c561-9aa9-47b1-9979-4d669d880987';
    $pane = new stdClass();
    $pane->pid = 'new-1a73dc52-e50e-4232-98ef-652dfe557360';
    $pane->panel = 'middle';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
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
    $pane->uuid = '1a73dc52-e50e-4232-98ef-652dfe557360';
    $display->content['new-1a73dc52-e50e-4232-98ef-652dfe557360'] = $pane;
    $display->panels['middle'][1] = 'new-1a73dc52-e50e-4232-98ef-652dfe557360';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1039c561-9aa9-47b1-9979-4d669d880987';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context_2';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Default edit',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'node/*/edit',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
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
  $display->title = 'Editing &raquo; %node:title';
  $display->uuid = 'a323206c-8ba9-4f61-88d4-02c4e3ec7707';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6711f0e8-214d-4522-98c5-563d99e620e2';
    $pane->panel = 'middle';
    $pane->type = 'coral_page_title';
    $pane->subtype = 'coral_page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => 'page-title',
      'id' => 'page-title',
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
    $pane->uuid = '6711f0e8-214d-4522-98c5-563d99e620e2';
    $display->content['new-6711f0e8-214d-4522-98c5-563d99e620e2'] = $pane;
    $display->panels['middle'][0] = 'new-6711f0e8-214d-4522-98c5-563d99e620e2';
    $pane = new stdClass();
    $pane->pid = 'new-3c85e76f-022d-4aee-89b5-b9b926ff497c';
    $pane->panel = 'middle';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
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
    $pane->uuid = '3c85e76f-022d-4aee-89b5-b9b926ff497c';
    $display->content['new-3c85e76f-022d-4aee-89b5-b9b926ff497c'] = $pane;
    $display->panels['middle'][1] = 'new-3c85e76f-022d-4aee-89b5-b9b926ff497c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6711f0e8-214d-4522-98c5-563d99e620e2';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context_4';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Project create',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'project' => 'project',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
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
  $display->uuid = '9b6adea5-c5bd-4195-a3fc-17d95a58069e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d33977c9-c030-4ecd-9740-00eee78a292c';
    $pane->panel = 'leader';
    $pane->type = 'coral_page_title';
    $pane->subtype = 'coral_page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => 'page-title',
      'id' => 'page-title',
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
    $pane->uuid = 'd33977c9-c030-4ecd-9740-00eee78a292c';
    $display->content['new-d33977c9-c030-4ecd-9740-00eee78a292c'] = $pane;
    $display->panels['leader'][0] = 'new-d33977c9-c030-4ecd-9740-00eee78a292c';
    $pane = new stdClass();
    $pane->pid = 'new-97059025-1b18-449c-8290-bea2703ce8a3';
    $pane->panel = 'main';
    $pane->type = 'node_form_title';
    $pane->subtype = 'node_form_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
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
    $pane->uuid = '97059025-1b18-449c-8290-bea2703ce8a3';
    $display->content['new-97059025-1b18-449c-8290-bea2703ce8a3'] = $pane;
    $display->panels['main'][0] = 'new-97059025-1b18-449c-8290-bea2703ce8a3';
    $pane = new stdClass();
    $pane->pid = 'new-90af2da2-d925-410c-a510-2b9bf45b1a59';
    $pane->panel = 'main';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_system_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
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
    $pane->uuid = '90af2da2-d925-410c-a510-2b9bf45b1a59';
    $display->content['new-90af2da2-d925-410c-a510-2b9bf45b1a59'] = $pane;
    $display->panels['main'][1] = 'new-90af2da2-d925-410c-a510-2b9bf45b1a59';
    $pane = new stdClass();
    $pane->pid = 'new-e2763e2e-4ef5-455d-b153-270668f4a29c';
    $pane->panel = 'main';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
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
    $pane->uuid = 'e2763e2e-4ef5-455d-b153-270668f4a29c';
    $display->content['new-e2763e2e-4ef5-455d-b153-270668f4a29c'] = $pane;
    $display->panels['main'][2] = 'new-e2763e2e-4ef5-455d-b153-270668f4a29c';
    $pane = new stdClass();
    $pane->pid = 'new-45d7e7d4-9a5a-43b6-a767-6c2561273c9f';
    $pane->panel = 'main';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_item_featureset';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
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
    $pane->uuid = '45d7e7d4-9a5a-43b6-a767-6c2561273c9f';
    $display->content['new-45d7e7d4-9a5a-43b6-a767-6c2561273c9f'] = $pane;
    $display->panels['main'][3] = 'new-45d7e7d4-9a5a-43b6-a767-6c2561273c9f';
    $pane = new stdClass();
    $pane->pid = 'new-e0a928e3-2b80-47e3-8200-417d8b96bb41';
    $pane->panel = 'secondary';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_project_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
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
    $pane->uuid = 'e0a928e3-2b80-47e3-8200-417d8b96bb41';
    $display->content['new-e0a928e3-2b80-47e3-8200-417d8b96bb41'] = $pane;
    $display->panels['secondary'][0] = 'new-e0a928e3-2b80-47e3-8200-417d8b96bb41';
    $pane = new stdClass();
    $pane->pid = 'new-0377232f-4f19-44a7-8d77-2ac7a7007c02';
    $pane->panel = 'secondary';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
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
    $pane->uuid = '0377232f-4f19-44a7-8d77-2ac7a7007c02';
    $display->content['new-0377232f-4f19-44a7-8d77-2ac7a7007c02'] = $pane;
    $display->panels['secondary'][1] = 'new-0377232f-4f19-44a7-8d77-2ac7a7007c02';
    $pane = new stdClass();
    $pane->pid = 'new-b737ecc1-21a3-485a-9111-aa5f0dd3aec0';
    $pane->panel = 'secondary';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
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
    $pane->uuid = 'b737ecc1-21a3-485a-9111-aa5f0dd3aec0';
    $display->content['new-b737ecc1-21a3-485a-9111-aa5f0dd3aec0'] = $pane;
    $display->panels['secondary'][2] = 'new-b737ecc1-21a3-485a-9111-aa5f0dd3aec0';
    $pane = new stdClass();
    $pane->pid = 'new-69cd2b0d-ca96-4ed2-9b35-54d73c3bf383';
    $pane->panel = 'secondary';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_project_reference';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
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
    $pane->uuid = '69cd2b0d-ca96-4ed2-9b35-54d73c3bf383';
    $display->content['new-69cd2b0d-ca96-4ed2-9b35-54d73c3bf383'] = $pane;
    $display->panels['secondary'][3] = 'new-69cd2b0d-ca96-4ed2-9b35-54d73c3bf383';
    $pane = new stdClass();
    $pane->pid = 'new-0db97062-dbfd-4749-b8e9-ad3453cc1166';
    $pane->panel = 'secondary';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_documentation_reference';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
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
    $pane->uuid = '0db97062-dbfd-4749-b8e9-ad3453cc1166';
    $display->content['new-0db97062-dbfd-4749-b8e9-ad3453cc1166'] = $pane;
    $display->panels['secondary'][4] = 'new-0db97062-dbfd-4749-b8e9-ad3453cc1166';
    $pane = new stdClass();
    $pane->pid = 'new-3cc1ea41-556e-4a49-944d-643dcabe5134';
    $pane->panel = 'secondary';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_project_repo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
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
    $pane->uuid = '3cc1ea41-556e-4a49-944d-643dcabe5134';
    $display->content['new-3cc1ea41-556e-4a49-944d-643dcabe5134'] = $pane;
    $display->panels['secondary'][5] = 'new-3cc1ea41-556e-4a49-944d-643dcabe5134';
    $pane = new stdClass();
    $pane->pid = 'new-0046ea8a-648f-46d6-968b-61b26b581447';
    $pane->panel = 'secondary';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_issue_queue';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
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
    $pane->uuid = '0046ea8a-648f-46d6-968b-61b26b581447';
    $display->content['new-0046ea8a-648f-46d6-968b-61b26b581447'] = $pane;
    $display->panels['secondary'][6] = 'new-0046ea8a-648f-46d6-968b-61b26b581447';
    $pane = new stdClass();
    $pane->pid = 'new-5e3a4888-4eea-4c55-9d60-640f150dc8d8';
    $pane->panel = 'sub_footer';
    $pane->type = 'node_form_log';
    $pane->subtype = 'node_form_log';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
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
    $pane->uuid = '5e3a4888-4eea-4c55-9d60-640f150dc8d8';
    $display->content['new-5e3a4888-4eea-4c55-9d60-640f150dc8d8'] = $pane;
    $display->panels['sub_footer'][0] = 'new-5e3a4888-4eea-4c55-9d60-640f150dc8d8';
    $pane = new stdClass();
    $pane->pid = 'new-df42f960-eb6a-4d54-a898-e286286e89d5';
    $pane->panel = 'sub_footer';
    $pane->type = 'node_form_publishing';
    $pane->subtype = 'node_form_publishing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
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
    $pane->uuid = 'df42f960-eb6a-4d54-a898-e286286e89d5';
    $display->content['new-df42f960-eb6a-4d54-a898-e286286e89d5'] = $pane;
    $display->panels['sub_footer'][1] = 'new-df42f960-eb6a-4d54-a898-e286286e89d5';
    $pane = new stdClass();
    $pane->pid = 'new-c535a01c-0450-4d31-a016-862b1fa73542';
    $pane->panel = 'sub_footer';
    $pane->type = 'node_form_comment';
    $pane->subtype = 'node_form_comment';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
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
    $pane->uuid = 'c535a01c-0450-4d31-a016-862b1fa73542';
    $display->content['new-c535a01c-0450-4d31-a016-862b1fa73542'] = $pane;
    $display->panels['sub_footer'][2] = 'new-c535a01c-0450-4d31-a016-862b1fa73542';
    $pane = new stdClass();
    $pane->pid = 'new-e2efb7bb-3266-4936-b67f-719f888ead18';
    $pane->panel = 'sub_footer';
    $pane->type = 'node_form_buttons';
    $pane->subtype = 'node_form_buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
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
    $pane->uuid = 'e2efb7bb-3266-4936-b67f-719f888ead18';
    $display->content['new-e2efb7bb-3266-4936-b67f-719f888ead18'] = $pane;
    $display->panels['sub_footer'][3] = 'new-e2efb7bb-3266-4936-b67f-719f888ead18';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_4'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panelizer_node';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panelizer_node';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Page',
    'contexts' => array(),
    'relationships' => array(),
    'context' => 'argument_entity_id:node_1',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'page' => 'page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $export['node_view_panelizer_node'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panelizer_node_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panelizer_node';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Image slide',
    'contexts' => array(),
    'relationships' => array(),
    'context' => 'argument_entity_id:node_1',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'image_slide' => 'image_slide',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $export['node_view_panelizer_node_2'] = $handler;

  return $export;
}
