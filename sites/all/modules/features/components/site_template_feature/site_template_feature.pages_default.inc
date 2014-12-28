<?php
/**
 * @file
 * site_template_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function site_template_feature_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default',
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
  $display->layout = 'mosaic_global';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
      'footer' => NULL,
      'sub_header' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a60ffc2a-2bea-4d42-bab9-9ec01083cdd2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-edaa567f-6ce7-4fc2-9a60-a43d623c2242';
    $pane->panel = 'footer';
    $pane->type = 'panels_mini';
    $pane->subtype = 'footer';
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
    $pane->uuid = 'edaa567f-6ce7-4fc2-9a60-a43d623c2242';
    $display->content['new-edaa567f-6ce7-4fc2-9a60-a43d623c2242'] = $pane;
    $display->panels['footer'][0] = 'new-edaa567f-6ce7-4fc2-9a60-a43d623c2242';
    $pane = new stdClass();
    $pane->pid = 'new-ae6039d9-1c58-4794-a3ed-189e59d2ad80';
    $pane->panel = 'header';
    $pane->type = 'panels_mini';
    $pane->subtype = 'getting_help';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'pane-getting-help',
      'css_class' => 'hide',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ae6039d9-1c58-4794-a3ed-189e59d2ad80';
    $display->content['new-ae6039d9-1c58-4794-a3ed-189e59d2ad80'] = $pane;
    $display->panels['header'][0] = 'new-ae6039d9-1c58-4794-a3ed-189e59d2ad80';
    $pane = new stdClass();
    $pane->pid = 'new-59420432-edce-46ec-833a-5a7e56853ee5';
    $pane->panel = 'header';
    $pane->type = 'panels_mini';
    $pane->subtype = 'header';
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
    $pane->uuid = '59420432-edce-46ec-833a-5a7e56853ee5';
    $display->content['new-59420432-edce-46ec-833a-5a7e56853ee5'] = $pane;
    $display->panels['header'][1] = 'new-59420432-edce-46ec-833a-5a7e56853ee5';
    $pane = new stdClass();
    $pane->pid = 'new-1fc98087-bc78-40bc-8138-0356925a6052';
    $pane->panel = 'header';
    $pane->type = 'panels_mini';
    $pane->subtype = 'top_menus';
    $pane->shown = FALSE;
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '1fc98087-bc78-40bc-8138-0356925a6052';
    $display->content['new-1fc98087-bc78-40bc-8138-0356925a6052'] = $pane;
    $display->panels['header'][2] = 'new-1fc98087-bc78-40bc-8138-0356925a6052';
    $pane = new stdClass();
    $pane->pid = 'new-e3fd24ab-fdf0-4ac6-90c4-c996c317f48c';
    $pane->panel = 'main';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
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
    $pane->uuid = 'e3fd24ab-fdf0-4ac6-90c4-c996c317f48c';
    $display->content['new-e3fd24ab-fdf0-4ac6-90c4-c996c317f48c'] = $pane;
    $display->panels['main'][0] = 'new-e3fd24ab-fdf0-4ac6-90c4-c996c317f48c';
    $pane = new stdClass();
    $pane->pid = 'new-5990088e-af81-44f9-bfa9-aac7ff040e2f';
    $pane->panel = 'main';
    $pane->type = 'page_help';
    $pane->subtype = 'page_help';
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
    $pane->uuid = '5990088e-af81-44f9-bfa9-aac7ff040e2f';
    $display->content['new-5990088e-af81-44f9-bfa9-aac7ff040e2f'] = $pane;
    $display->panels['main'][1] = 'new-5990088e-af81-44f9-bfa9-aac7ff040e2f';
    $pane = new stdClass();
    $pane->pid = 'new-ba32504f-e689-44ca-8c14-b359e32ba2fe';
    $pane->panel = 'main';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
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
    $pane->uuid = 'ba32504f-e689-44ca-8c14-b359e32ba2fe';
    $display->content['new-ba32504f-e689-44ca-8c14-b359e32ba2fe'] = $pane;
    $display->panels['main'][2] = 'new-ba32504f-e689-44ca-8c14-b359e32ba2fe';
    $pane = new stdClass();
    $pane->pid = 'new-0da140f5-6db2-4633-ae53-57f3fea3913c';
    $pane->panel = 'sub_header';
    $pane->type = 'coral_status';
    $pane->subtype = 'coral_status';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'message' => 'CoralNexus software is currently in Alpha release state. It\'s not a good idea to use this software in mission critical situations just yet.',
      'status' => '1',
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
    $pane->uuid = '0da140f5-6db2-4633-ae53-57f3fea3913c';
    $display->content['new-0da140f5-6db2-4633-ae53-57f3fea3913c'] = $pane;
    $display->panels['sub_header'][0] = 'new-0da140f5-6db2-4633-ae53-57f3fea3913c';
    $pane = new stdClass();
    $pane->pid = 'new-c93c3911-c525-4708-9909-ce5ee29f90fd';
    $pane->panel = 'sub_header';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
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
    $pane->uuid = 'c93c3911-c525-4708-9909-ce5ee29f90fd';
    $display->content['new-c93c3911-c525-4708-9909-ce5ee29f90fd'] = $pane;
    $display->panels['sub_header'][1] = 'new-c93c3911-c525-4708-9909-ce5ee29f90fd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context'] = $handler;

  return $export;
}
