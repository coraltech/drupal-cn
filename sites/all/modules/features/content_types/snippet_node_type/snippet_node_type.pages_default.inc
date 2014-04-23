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
  $display->uuid = '11e94c8a-fcef-483b-8721-221c5629233c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b444b887-8040-4bbc-9e06-97a0b68645b6';
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
    $pane->uuid = 'b444b887-8040-4bbc-9e06-97a0b68645b6';
    $display->content['new-b444b887-8040-4bbc-9e06-97a0b68645b6'] = $pane;
    $display->panels['bottom'][0] = 'new-b444b887-8040-4bbc-9e06-97a0b68645b6';
    $pane = new stdClass();
    $pane->pid = 'new-ae40ab3e-0732-4e75-8771-5be92f8f04b5';
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
    $pane->uuid = 'ae40ab3e-0732-4e75-8771-5be92f8f04b5';
    $display->content['new-ae40ab3e-0732-4e75-8771-5be92f8f04b5'] = $pane;
    $display->panels['bottom'][1] = 'new-ae40ab3e-0732-4e75-8771-5be92f8f04b5';
    $pane = new stdClass();
    $pane->pid = 'new-fdfa29ec-4e80-43e0-a1df-72bea0e6ed81';
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
    $pane->uuid = 'fdfa29ec-4e80-43e0-a1df-72bea0e6ed81';
    $display->content['new-fdfa29ec-4e80-43e0-a1df-72bea0e6ed81'] = $pane;
    $display->panels['bottom'][2] = 'new-fdfa29ec-4e80-43e0-a1df-72bea0e6ed81';
    $pane = new stdClass();
    $pane->pid = 'new-0e6c62c9-7f08-48a6-9a53-dbc5fced1d9a';
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
    $pane->uuid = '0e6c62c9-7f08-48a6-9a53-dbc5fced1d9a';
    $display->content['new-0e6c62c9-7f08-48a6-9a53-dbc5fced1d9a'] = $pane;
    $display->panels['bottom'][3] = 'new-0e6c62c9-7f08-48a6-9a53-dbc5fced1d9a';
    $pane = new stdClass();
    $pane->pid = 'new-3bd83640-8a9d-4674-9b26-a99e244413a6';
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
    $pane->uuid = '3bd83640-8a9d-4674-9b26-a99e244413a6';
    $display->content['new-3bd83640-8a9d-4674-9b26-a99e244413a6'] = $pane;
    $display->panels['bottom'][4] = 'new-3bd83640-8a9d-4674-9b26-a99e244413a6';
    $pane = new stdClass();
    $pane->pid = 'new-f7a2a985-3fc7-4f3e-b9fc-a8d818d6ef11';
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
    $pane->uuid = 'f7a2a985-3fc7-4f3e-b9fc-a8d818d6ef11';
    $display->content['new-f7a2a985-3fc7-4f3e-b9fc-a8d818d6ef11'] = $pane;
    $display->panels['left'][0] = 'new-f7a2a985-3fc7-4f3e-b9fc-a8d818d6ef11';
    $pane = new stdClass();
    $pane->pid = 'new-59b962c4-972c-4f1a-870a-a0e317622adf';
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
    $pane->uuid = '59b962c4-972c-4f1a-870a-a0e317622adf';
    $display->content['new-59b962c4-972c-4f1a-870a-a0e317622adf'] = $pane;
    $display->panels['left'][1] = 'new-59b962c4-972c-4f1a-870a-a0e317622adf';
    $pane = new stdClass();
    $pane->pid = 'new-6eac8e20-08eb-4d32-b945-148d51bcd508';
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
    $pane->uuid = '6eac8e20-08eb-4d32-b945-148d51bcd508';
    $display->content['new-6eac8e20-08eb-4d32-b945-148d51bcd508'] = $pane;
    $display->panels['right'][0] = 'new-6eac8e20-08eb-4d32-b945-148d51bcd508';
    $pane = new stdClass();
    $pane->pid = 'new-e327dd55-c809-4bcf-a93f-4bb622899ffa';
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
    $pane->uuid = 'e327dd55-c809-4bcf-a93f-4bb622899ffa';
    $display->content['new-e327dd55-c809-4bcf-a93f-4bb622899ffa'] = $pane;
    $display->panels['top'][0] = 'new-e327dd55-c809-4bcf-a93f-4bb622899ffa';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e327dd55-c809-4bcf-a93f-4bb622899ffa';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_3'] = $handler;

  return $export;
}
