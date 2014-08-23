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
  $display->uuid = '24c8d4ff-2617-40cd-8f1a-2607df62a898';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-952fb6d6-b129-43fe-890a-9fedba774be3';
    $pane->panel = 'bottom';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '952fb6d6-b129-43fe-890a-9fedba774be3';
    $display->content['new-952fb6d6-b129-43fe-890a-9fedba774be3'] = $pane;
    $display->panels['bottom'][0] = 'new-952fb6d6-b129-43fe-890a-9fedba774be3';
    $pane = new stdClass();
    $pane->pid = 'new-55476115-4bc0-4f93-a6fa-b6afa9e6d7fd';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '55476115-4bc0-4f93-a6fa-b6afa9e6d7fd';
    $display->content['new-55476115-4bc0-4f93-a6fa-b6afa9e6d7fd'] = $pane;
    $display->panels['bottom'][1] = 'new-55476115-4bc0-4f93-a6fa-b6afa9e6d7fd';
    $pane = new stdClass();
    $pane->pid = 'new-26a9f537-e688-476c-b5ae-25049048a09c';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '26a9f537-e688-476c-b5ae-25049048a09c';
    $display->content['new-26a9f537-e688-476c-b5ae-25049048a09c'] = $pane;
    $display->panels['bottom'][2] = 'new-26a9f537-e688-476c-b5ae-25049048a09c';
    $pane = new stdClass();
    $pane->pid = 'new-1f11fc25-208d-4e80-be08-b689b035fd2b';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '1f11fc25-208d-4e80-be08-b689b035fd2b';
    $display->content['new-1f11fc25-208d-4e80-be08-b689b035fd2b'] = $pane;
    $display->panels['bottom'][3] = 'new-1f11fc25-208d-4e80-be08-b689b035fd2b';
    $pane = new stdClass();
    $pane->pid = 'new-958e218a-9a88-4200-b3fa-ae1bb5ee13d4';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '958e218a-9a88-4200-b3fa-ae1bb5ee13d4';
    $display->content['new-958e218a-9a88-4200-b3fa-ae1bb5ee13d4'] = $pane;
    $display->panels['bottom'][4] = 'new-958e218a-9a88-4200-b3fa-ae1bb5ee13d4';
    $pane = new stdClass();
    $pane->pid = 'new-2e92350d-2b50-49b0-a68a-77e6cbef5dfb';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '2e92350d-2b50-49b0-a68a-77e6cbef5dfb';
    $display->content['new-2e92350d-2b50-49b0-a68a-77e6cbef5dfb'] = $pane;
    $display->panels['bottom'][5] = 'new-2e92350d-2b50-49b0-a68a-77e6cbef5dfb';
    $pane = new stdClass();
    $pane->pid = 'new-7373ddd0-007c-4d92-82e9-1ea8b3344382';
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
    $pane->uuid = '7373ddd0-007c-4d92-82e9-1ea8b3344382';
    $display->content['new-7373ddd0-007c-4d92-82e9-1ea8b3344382'] = $pane;
    $display->panels['left'][0] = 'new-7373ddd0-007c-4d92-82e9-1ea8b3344382';
    $pane = new stdClass();
    $pane->pid = 'new-15594b6e-6ea4-4776-be7d-1e3a099c4c7c';
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
    $pane->uuid = '15594b6e-6ea4-4776-be7d-1e3a099c4c7c';
    $display->content['new-15594b6e-6ea4-4776-be7d-1e3a099c4c7c'] = $pane;
    $display->panels['left'][1] = 'new-15594b6e-6ea4-4776-be7d-1e3a099c4c7c';
    $pane = new stdClass();
    $pane->pid = 'new-454750c1-5035-4cc4-bf76-0a76af783cc1';
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
    $pane->uuid = '454750c1-5035-4cc4-bf76-0a76af783cc1';
    $display->content['new-454750c1-5035-4cc4-bf76-0a76af783cc1'] = $pane;
    $display->panels['right'][0] = 'new-454750c1-5035-4cc4-bf76-0a76af783cc1';
    $pane = new stdClass();
    $pane->pid = 'new-97c8ea2f-bd90-4e15-8a26-9e3224bcdab2';
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
    $pane->uuid = '97c8ea2f-bd90-4e15-8a26-9e3224bcdab2';
    $display->content['new-97c8ea2f-bd90-4e15-8a26-9e3224bcdab2'] = $pane;
    $display->panels['top'][0] = 'new-97c8ea2f-bd90-4e15-8a26-9e3224bcdab2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-97c8ea2f-bd90-4e15-8a26-9e3224bcdab2';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_3'] = $handler;

  return $export;
}
