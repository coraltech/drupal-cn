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
  $display->uuid = '7e466433-fa2c-422c-b224-54f1faccf320';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3523e0bd-c81f-47bb-b0dd-d39543241930';
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
    $pane->uuid = '3523e0bd-c81f-47bb-b0dd-d39543241930';
    $display->content['new-3523e0bd-c81f-47bb-b0dd-d39543241930'] = $pane;
    $display->panels['bottom'][0] = 'new-3523e0bd-c81f-47bb-b0dd-d39543241930';
    $pane = new stdClass();
    $pane->pid = 'new-2b57ac6c-0146-4528-a4ba-60be0ab8b677';
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
    $pane->uuid = '2b57ac6c-0146-4528-a4ba-60be0ab8b677';
    $display->content['new-2b57ac6c-0146-4528-a4ba-60be0ab8b677'] = $pane;
    $display->panels['bottom'][1] = 'new-2b57ac6c-0146-4528-a4ba-60be0ab8b677';
    $pane = new stdClass();
    $pane->pid = 'new-2812b8af-a706-44fc-ac27-f35eb56b3467';
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
    $pane->uuid = '2812b8af-a706-44fc-ac27-f35eb56b3467';
    $display->content['new-2812b8af-a706-44fc-ac27-f35eb56b3467'] = $pane;
    $display->panels['bottom'][2] = 'new-2812b8af-a706-44fc-ac27-f35eb56b3467';
    $pane = new stdClass();
    $pane->pid = 'new-1381f483-576a-4c13-8d99-3b58e92672ff';
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
    $pane->uuid = '1381f483-576a-4c13-8d99-3b58e92672ff';
    $display->content['new-1381f483-576a-4c13-8d99-3b58e92672ff'] = $pane;
    $display->panels['bottom'][3] = 'new-1381f483-576a-4c13-8d99-3b58e92672ff';
    $pane = new stdClass();
    $pane->pid = 'new-7a94ba9f-ba18-4c4c-99bf-d19d2e9e8f19';
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
    $pane->uuid = '7a94ba9f-ba18-4c4c-99bf-d19d2e9e8f19';
    $display->content['new-7a94ba9f-ba18-4c4c-99bf-d19d2e9e8f19'] = $pane;
    $display->panels['bottom'][4] = 'new-7a94ba9f-ba18-4c4c-99bf-d19d2e9e8f19';
    $pane = new stdClass();
    $pane->pid = 'new-d936b623-1994-449a-aa62-26cd3b070821';
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
    $pane->uuid = 'd936b623-1994-449a-aa62-26cd3b070821';
    $display->content['new-d936b623-1994-449a-aa62-26cd3b070821'] = $pane;
    $display->panels['left'][0] = 'new-d936b623-1994-449a-aa62-26cd3b070821';
    $pane = new stdClass();
    $pane->pid = 'new-c6c288d2-84b7-4a49-b2f6-b796e0873e7d';
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
    $pane->uuid = 'c6c288d2-84b7-4a49-b2f6-b796e0873e7d';
    $display->content['new-c6c288d2-84b7-4a49-b2f6-b796e0873e7d'] = $pane;
    $display->panels['left'][1] = 'new-c6c288d2-84b7-4a49-b2f6-b796e0873e7d';
    $pane = new stdClass();
    $pane->pid = 'new-0ea63bc4-484e-4443-9814-b67848d906fc';
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
    $pane->uuid = '0ea63bc4-484e-4443-9814-b67848d906fc';
    $display->content['new-0ea63bc4-484e-4443-9814-b67848d906fc'] = $pane;
    $display->panels['right'][0] = 'new-0ea63bc4-484e-4443-9814-b67848d906fc';
    $pane = new stdClass();
    $pane->pid = 'new-acd88251-0060-407b-b0b5-4ed8cf3721f9';
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
    $pane->uuid = 'acd88251-0060-407b-b0b5-4ed8cf3721f9';
    $display->content['new-acd88251-0060-407b-b0b5-4ed8cf3721f9'] = $pane;
    $display->panels['top'][0] = 'new-acd88251-0060-407b-b0b5-4ed8cf3721f9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-acd88251-0060-407b-b0b5-4ed8cf3721f9';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_3'] = $handler;

  return $export;
}
