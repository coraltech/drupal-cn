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
  $display->uuid = '7cd1aba4-573b-45f9-8047-38e554b3de68';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0e1611e0-bead-4c63-b839-8cadf3ff3cbd';
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
    $pane->uuid = '0e1611e0-bead-4c63-b839-8cadf3ff3cbd';
    $display->content['new-0e1611e0-bead-4c63-b839-8cadf3ff3cbd'] = $pane;
    $display->panels['bottom'][0] = 'new-0e1611e0-bead-4c63-b839-8cadf3ff3cbd';
    $pane = new stdClass();
    $pane->pid = 'new-26ca03c8-d4e9-42f8-80d0-0c0b81d80372';
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
    $pane->uuid = '26ca03c8-d4e9-42f8-80d0-0c0b81d80372';
    $display->content['new-26ca03c8-d4e9-42f8-80d0-0c0b81d80372'] = $pane;
    $display->panels['bottom'][1] = 'new-26ca03c8-d4e9-42f8-80d0-0c0b81d80372';
    $pane = new stdClass();
    $pane->pid = 'new-831ad93f-836b-45be-a1a1-98d044fc8de7';
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
    $pane->uuid = '831ad93f-836b-45be-a1a1-98d044fc8de7';
    $display->content['new-831ad93f-836b-45be-a1a1-98d044fc8de7'] = $pane;
    $display->panels['bottom'][2] = 'new-831ad93f-836b-45be-a1a1-98d044fc8de7';
    $pane = new stdClass();
    $pane->pid = 'new-ae67a2a2-99d0-40c3-9741-098947b62dc8';
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
    $pane->uuid = 'ae67a2a2-99d0-40c3-9741-098947b62dc8';
    $display->content['new-ae67a2a2-99d0-40c3-9741-098947b62dc8'] = $pane;
    $display->panels['bottom'][3] = 'new-ae67a2a2-99d0-40c3-9741-098947b62dc8';
    $pane = new stdClass();
    $pane->pid = 'new-0cae8400-9d69-4e5b-9971-fd9b19766222';
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
    $pane->uuid = '0cae8400-9d69-4e5b-9971-fd9b19766222';
    $display->content['new-0cae8400-9d69-4e5b-9971-fd9b19766222'] = $pane;
    $display->panels['bottom'][4] = 'new-0cae8400-9d69-4e5b-9971-fd9b19766222';
    $pane = new stdClass();
    $pane->pid = 'new-aeef48ed-5802-4418-a9a5-e613c067564f';
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
    $pane->uuid = 'aeef48ed-5802-4418-a9a5-e613c067564f';
    $display->content['new-aeef48ed-5802-4418-a9a5-e613c067564f'] = $pane;
    $display->panels['left'][0] = 'new-aeef48ed-5802-4418-a9a5-e613c067564f';
    $pane = new stdClass();
    $pane->pid = 'new-8ea6b9cf-3e19-4c2b-8216-3540fb9419bf';
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
    $pane->uuid = '8ea6b9cf-3e19-4c2b-8216-3540fb9419bf';
    $display->content['new-8ea6b9cf-3e19-4c2b-8216-3540fb9419bf'] = $pane;
    $display->panels['left'][1] = 'new-8ea6b9cf-3e19-4c2b-8216-3540fb9419bf';
    $pane = new stdClass();
    $pane->pid = 'new-571b6d67-4543-4dbd-adcb-ddc2ed4fda71';
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
    $pane->uuid = '571b6d67-4543-4dbd-adcb-ddc2ed4fda71';
    $display->content['new-571b6d67-4543-4dbd-adcb-ddc2ed4fda71'] = $pane;
    $display->panels['right'][0] = 'new-571b6d67-4543-4dbd-adcb-ddc2ed4fda71';
    $pane = new stdClass();
    $pane->pid = 'new-da94d86c-5b7d-44b0-bccc-d79f8a5c4fdd';
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
    $pane->uuid = 'da94d86c-5b7d-44b0-bccc-d79f8a5c4fdd';
    $display->content['new-da94d86c-5b7d-44b0-bccc-d79f8a5c4fdd'] = $pane;
    $display->panels['top'][0] = 'new-da94d86c-5b7d-44b0-bccc-d79f8a5c4fdd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-da94d86c-5b7d-44b0-bccc-d79f8a5c4fdd';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_3'] = $handler;

  return $export;
}
