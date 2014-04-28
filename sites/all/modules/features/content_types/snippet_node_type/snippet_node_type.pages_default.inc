<?php
/**
 * @file
 * snippet_node_type.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function snippet_node_type_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context_3';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Snippet create',
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
              'snippet' => 'snippet',
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
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a679adbf-ae63-412b-8df1-f0b3a1b4a6ed';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b943ffdf-e858-491a-91d9-06afc43c81c5';
    $pane->panel = 'bottom';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_snippet_components';
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
    $pane->uuid = 'b943ffdf-e858-491a-91d9-06afc43c81c5';
    $display->content['new-b943ffdf-e858-491a-91d9-06afc43c81c5'] = $pane;
    $display->panels['bottom'][0] = 'new-b943ffdf-e858-491a-91d9-06afc43c81c5';
    $pane = new stdClass();
    $pane->pid = 'new-665120ba-8d5e-4d67-9307-310c76868150';
    $pane->panel = 'bottom';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '665120ba-8d5e-4d67-9307-310c76868150';
    $display->content['new-665120ba-8d5e-4d67-9307-310c76868150'] = $pane;
    $display->panels['bottom'][1] = 'new-665120ba-8d5e-4d67-9307-310c76868150';
    $pane = new stdClass();
    $pane->pid = 'new-192548e7-3f35-491b-9964-c0409dc217bb';
    $pane->panel = 'bottom';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '192548e7-3f35-491b-9964-c0409dc217bb';
    $display->content['new-192548e7-3f35-491b-9964-c0409dc217bb'] = $pane;
    $display->panels['bottom'][2] = 'new-192548e7-3f35-491b-9964-c0409dc217bb';
    $pane = new stdClass();
    $pane->pid = 'new-4ec2c9af-7a9c-4a4b-8a94-ef03eb846c3e';
    $pane->panel = 'bottom';
    $pane->type = 'node_form_comment';
    $pane->subtype = 'node_form_comment';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '4ec2c9af-7a9c-4a4b-8a94-ef03eb846c3e';
    $display->content['new-4ec2c9af-7a9c-4a4b-8a94-ef03eb846c3e'] = $pane;
    $display->panels['bottom'][3] = 'new-4ec2c9af-7a9c-4a4b-8a94-ef03eb846c3e';
    $pane = new stdClass();
    $pane->pid = 'new-c99b9611-a4c7-403d-a1d2-e0d26849b347';
    $pane->panel = 'bottom';
    $pane->type = 'node_form_buttons';
    $pane->subtype = 'node_form_buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'c99b9611-a4c7-403d-a1d2-e0d26849b347';
    $display->content['new-c99b9611-a4c7-403d-a1d2-e0d26849b347'] = $pane;
    $display->panels['bottom'][4] = 'new-c99b9611-a4c7-403d-a1d2-e0d26849b347';
    $pane = new stdClass();
    $pane->pid = 'new-efb031ba-bc38-4b70-b15a-c903a830e742';
    $pane->panel = 'left';
    $pane->type = 'node_form_title';
    $pane->subtype = 'node_form_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'efb031ba-bc38-4b70-b15a-c903a830e742';
    $display->content['new-efb031ba-bc38-4b70-b15a-c903a830e742'] = $pane;
    $display->panels['left'][0] = 'new-efb031ba-bc38-4b70-b15a-c903a830e742';
    $pane = new stdClass();
    $pane->pid = 'new-76ece71a-2da3-4021-b0a9-0ade9dc0f01c';
    $pane->panel = 'left';
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
    $pane->uuid = '76ece71a-2da3-4021-b0a9-0ade9dc0f01c';
    $display->content['new-76ece71a-2da3-4021-b0a9-0ade9dc0f01c'] = $pane;
    $display->panels['left'][1] = 'new-76ece71a-2da3-4021-b0a9-0ade9dc0f01c';
    $pane = new stdClass();
    $pane->pid = 'new-29e28b2b-989b-4434-870b-d6f4e7d3fe9a';
    $pane->panel = 'right';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:body';
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
    $pane->uuid = '29e28b2b-989b-4434-870b-d6f4e7d3fe9a';
    $display->content['new-29e28b2b-989b-4434-870b-d6f4e7d3fe9a'] = $pane;
    $display->panels['right'][0] = 'new-29e28b2b-989b-4434-870b-d6f4e7d3fe9a';
    $pane = new stdClass();
    $pane->pid = 'new-9efbf8a4-722e-4f33-95c4-5245078ceb89';
    $pane->panel = 'top';
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
    $pane->uuid = '9efbf8a4-722e-4f33-95c4-5245078ceb89';
    $display->content['new-9efbf8a4-722e-4f33-95c4-5245078ceb89'] = $pane;
    $display->panels['top'][0] = 'new-9efbf8a4-722e-4f33-95c4-5245078ceb89';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9efbf8a4-722e-4f33-95c4-5245078ceb89';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_3'] = $handler;

  return $export;
}
