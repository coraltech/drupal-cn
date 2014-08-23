<?php
/**
 * @file
 * search_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function search_feature_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'search_node_panel_context';
  $handler->task = 'search';
  $handler->subtask = 'node';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default search',
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
  $display->title = 'Search %keywords:html_safe';
  $display->uuid = '7adc0934-f28d-4a6f-ad4e-4b2e97c2326c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a4fa6f89-a981-4417-8dfc-743ff49dade7';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'search-form';
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
    $pane->uuid = 'a4fa6f89-a981-4417-8dfc-743ff49dade7';
    $display->content['new-a4fa6f89-a981-4417-8dfc-743ff49dade7'] = $pane;
    $display->panels['main'][0] = 'new-a4fa6f89-a981-4417-8dfc-743ff49dade7';
    $pane = new stdClass();
    $pane->pid = 'new-e12b4b67-0a9e-4055-9ffc-3d6be7b73525';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'current_search-standard';
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
    $pane->uuid = 'e12b4b67-0a9e-4055-9ffc-3d6be7b73525';
    $display->content['new-e12b4b67-0a9e-4055-9ffc-3d6be7b73525'] = $pane;
    $display->panels['main'][1] = 'new-e12b4b67-0a9e-4055-9ffc-3d6be7b73525';
    $pane = new stdClass();
    $pane->pid = 'new-7c738092-57ae-4804-a9d5-ae54341a4474';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'node_search-node_search_results';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'items_per_page' => '25',
      'context' => array(
        0 => 'argument_string_1',
      ),
      'override_title' => 1,
      'override_title_text' => '',
      'fields_override' => array(
        'nid' => 0,
        'author' => 0,
        'title' => 1,
        'type' => 0,
        'user_image' => 1,
        'url' => 1,
        'changed' => 1,
        'body' => 1,
        'search_api_excerpt' => 1,
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7c738092-57ae-4804-a9d5-ae54341a4474';
    $display->content['new-7c738092-57ae-4804-a9d5-ae54341a4474'] = $pane;
    $display->panels['main'][2] = 'new-7c738092-57ae-4804-a9d5-ae54341a4474';
    $pane = new stdClass();
    $pane->pid = 'new-d3fe92d9-3bf7-4ba3-a857-b71969a29caa';
    $pane->panel = 'secondary';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Content type',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'facet-pane facet-types',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd3fe92d9-3bf7-4ba3-a857-b71969a29caa';
    $display->content['new-d3fe92d9-3bf7-4ba3-a857-b71969a29caa'] = $pane;
    $display->panels['secondary'][0] = 'new-d3fe92d9-3bf7-4ba3-a857-b71969a29caa';
    $pane = new stdClass();
    $pane->pid = 'new-b445eb79-77d1-4f0e-a658-55ac320e87c2';
    $pane->panel = 'secondary';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-R2AEH1rq0GDt4tPXW5YJy8gBEbPVTgPU';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Tags',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'facet-pane facet-tags',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b445eb79-77d1-4f0e-a658-55ac320e87c2';
    $display->content['new-b445eb79-77d1-4f0e-a658-55ac320e87c2'] = $pane;
    $display->panels['secondary'][1] = 'new-b445eb79-77d1-4f0e-a658-55ac320e87c2';
    $pane = new stdClass();
    $pane->pid = 'new-2c0820df-ba5e-45d0-8add-9636924b12aa';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2c0820df-ba5e-45d0-8add-9636924b12aa';
    $display->content['new-2c0820df-ba5e-45d0-8add-9636924b12aa'] = $pane;
    $display->panels['secondary'][2] = 'new-2c0820df-ba5e-45d0-8add-9636924b12aa';
    $pane = new stdClass();
    $pane->pid = 'new-30b1af2b-6686-4eea-8590-e0864ccf1a24';
    $pane->panel = 'secondary';
    $pane->type = 'coral_swipe';
    $pane->subtype = 'coral_swipe';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'message' => 'Swipe to view facets',
      'layout' => '1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'search',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '30b1af2b-6686-4eea-8590-e0864ccf1a24';
    $display->content['new-30b1af2b-6686-4eea-8590-e0864ccf1a24'] = $pane;
    $display->panels['secondary'][3] = 'new-30b1af2b-6686-4eea-8590-e0864ccf1a24';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['search_node_panel_context'] = $handler;

  return $export;
}
