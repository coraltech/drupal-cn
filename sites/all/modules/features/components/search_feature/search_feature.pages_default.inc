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
  $display->uuid = 'b60e931d-3b14-4910-b133-29d904e1ce23';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3bfcf5d4-013a-47ee-9926-191ac237b171';
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
    $pane->uuid = '3bfcf5d4-013a-47ee-9926-191ac237b171';
    $display->content['new-3bfcf5d4-013a-47ee-9926-191ac237b171'] = $pane;
    $display->panels['main'][0] = 'new-3bfcf5d4-013a-47ee-9926-191ac237b171';
    $pane = new stdClass();
    $pane->pid = 'new-5e530bc0-5545-4c95-98d3-85dfb3aed02d';
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
    $pane->uuid = '5e530bc0-5545-4c95-98d3-85dfb3aed02d';
    $display->content['new-5e530bc0-5545-4c95-98d3-85dfb3aed02d'] = $pane;
    $display->panels['main'][1] = 'new-5e530bc0-5545-4c95-98d3-85dfb3aed02d';
    $pane = new stdClass();
    $pane->pid = 'new-6f7da420-8f46-489e-9ac2-8fa5dc419741';
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
    $pane->uuid = '6f7da420-8f46-489e-9ac2-8fa5dc419741';
    $display->content['new-6f7da420-8f46-489e-9ac2-8fa5dc419741'] = $pane;
    $display->panels['main'][2] = 'new-6f7da420-8f46-489e-9ac2-8fa5dc419741';
    $pane = new stdClass();
    $pane->pid = 'new-65eb0e63-4b1d-4476-8209-7a3df1315856';
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
    $pane->uuid = '65eb0e63-4b1d-4476-8209-7a3df1315856';
    $display->content['new-65eb0e63-4b1d-4476-8209-7a3df1315856'] = $pane;
    $display->panels['secondary'][0] = 'new-65eb0e63-4b1d-4476-8209-7a3df1315856';
    $pane = new stdClass();
    $pane->pid = 'new-ce27de52-63c0-45c5-8b3e-12d2462495e4';
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
    $pane->uuid = 'ce27de52-63c0-45c5-8b3e-12d2462495e4';
    $display->content['new-ce27de52-63c0-45c5-8b3e-12d2462495e4'] = $pane;
    $display->panels['secondary'][1] = 'new-ce27de52-63c0-45c5-8b3e-12d2462495e4';
    $pane = new stdClass();
    $pane->pid = 'new-ff3c0815-aefc-4ede-930f-3c5e3011dd9f';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ff3c0815-aefc-4ede-930f-3c5e3011dd9f';
    $display->content['new-ff3c0815-aefc-4ede-930f-3c5e3011dd9f'] = $pane;
    $display->panels['secondary'][2] = 'new-ff3c0815-aefc-4ede-930f-3c5e3011dd9f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['search_node_panel_context'] = $handler;

  return $export;
}
