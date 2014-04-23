<?php
/**
 * @file
 * wiki_documents_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function wiki_documents_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:book:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'book';
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
      'leader' => NULL,
      'main' => NULL,
      'secondary' => NULL,
      'follower' => NULL,
      'sub_footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '171f95cf-5568-4ab5-988a-038371076977';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3e006d04-4ec8-4f82-a0fd-9899315299d0';
    $pane->panel = 'leader';
    $pane->type = 'coral_community_tabs';
    $pane->subtype = 'coral_community_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'active_tab' => '0',
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
    $pane->uuid = '3e006d04-4ec8-4f82-a0fd-9899315299d0';
    $display->content['new-3e006d04-4ec8-4f82-a0fd-9899315299d0'] = $pane;
    $display->panels['leader'][0] = 'new-3e006d04-4ec8-4f82-a0fd-9899315299d0';
    $pane = new stdClass();
    $pane->pid = 'new-143b080a-ca89-4f50-95a4-90efd70f3a4c';
    $pane->panel = 'leader';
    $pane->type = 'coral_breadcrumb';
    $pane->subtype = 'coral_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'append_title' => 1,
      'override_title' => 1,
      'override_title_text' => '',
      'link_title' => 0,
      'prefix' => 'You are here:  ',
      'remove_home' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '143b080a-ca89-4f50-95a4-90efd70f3a4c';
    $display->content['new-143b080a-ca89-4f50-95a4-90efd70f3a4c'] = $pane;
    $display->panels['leader'][1] = 'new-143b080a-ca89-4f50-95a4-90efd70f3a4c';
    $pane = new stdClass();
    $pane->pid = 'new-d3149e97-b2d5-4d2a-affe-fb32187b87f1';
    $pane->panel = 'main';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'top',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd3149e97-b2d5-4d2a-affe-fb32187b87f1';
    $display->content['new-d3149e97-b2d5-4d2a-affe-fb32187b87f1'] = $pane;
    $display->panels['main'][0] = 'new-d3149e97-b2d5-4d2a-affe-fb32187b87f1';
    $pane = new stdClass();
    $pane->pid = 'new-526966a0-4ac0-4a86-a78d-fcc049e1674d';
    $pane->panel = 'main';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => 'page-title',
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
    $pane->uuid = '526966a0-4ac0-4a86-a78d-fcc049e1674d';
    $display->content['new-526966a0-4ac0-4a86-a78d-fcc049e1674d'] = $pane;
    $display->panels['main'][1] = 'new-526966a0-4ac0-4a86-a78d-fcc049e1674d';
    $pane = new stdClass();
    $pane->pid = 'new-e6dbbf05-8653-405b-845a-237a98f55bd6';
    $pane->panel = 'main';
    $pane->type = 'coral_node_stats';
    $pane->subtype = 'coral_node_stats';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => FALSE,
      'context' => array(
        0 => 'panelizer',
      ),
      'override_title' => 1,
      'override_title_text' => '',
      'display_stats' => array(
        2 => '2',
        3 => '3',
        5 => '5',
        6 => '6',
        7 => '7',
        1 => 0,
        4 => 0,
        8 => 0,
      ),
      'display_style' => '2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e6dbbf05-8653-405b-845a-237a98f55bd6';
    $display->content['new-e6dbbf05-8653-405b-845a-237a98f55bd6'] = $pane;
    $display->panels['main'][2] = 'new-e6dbbf05-8653-405b-845a-237a98f55bd6';
    $pane = new stdClass();
    $pane->pid = 'new-e327f091-2eb9-49bf-8e08-24817a9cec0a';
    $pane->panel = 'main';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full_node',
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e327f091-2eb9-49bf-8e08-24817a9cec0a';
    $display->content['new-e327f091-2eb9-49bf-8e08-24817a9cec0a'] = $pane;
    $display->panels['main'][3] = 'new-e327f091-2eb9-49bf-8e08-24817a9cec0a';
    $pane = new stdClass();
    $pane->pid = 'new-8a6ec7c7-574f-45ba-ba33-520d07c63e54';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '8a6ec7c7-574f-45ba-ba33-520d07c63e54';
    $display->content['new-8a6ec7c7-574f-45ba-ba33-520d07c63e54'] = $pane;
    $display->panels['main'][4] = 'new-8a6ec7c7-574f-45ba-ba33-520d07c63e54';
    $pane = new stdClass();
    $pane->pid = 'new-f5d9227f-d9fa-4413-a7df-2e5f1c5b98a0';
    $pane->panel = 'secondary';
    $pane->type = 'block';
    $pane->subtype = 'book_explorer-book_explorer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Topics',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f5d9227f-d9fa-4413-a7df-2e5f1c5b98a0';
    $display->content['new-f5d9227f-d9fa-4413-a7df-2e5f1c5b98a0'] = $pane;
    $display->panels['secondary'][0] = 'new-f5d9227f-d9fa-4413-a7df-2e5f1c5b98a0';
    $pane = new stdClass();
    $pane->pid = 'new-e9901b22-31ca-4bb4-8239-a1f4df60523f';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e9901b22-31ca-4bb4-8239-a1f4df60523f';
    $display->content['new-e9901b22-31ca-4bb4-8239-a1f4df60523f'] = $pane;
    $display->panels['secondary'][1] = 'new-e9901b22-31ca-4bb4-8239-a1f4df60523f';
    $pane = new stdClass();
    $pane->pid = 'new-79db93f6-eb4b-47e6-a9f0-7b7268c4e580';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '79db93f6-eb4b-47e6-a9f0-7b7268c4e580';
    $display->content['new-79db93f6-eb4b-47e6-a9f0-7b7268c4e580'] = $pane;
    $display->panels['secondary'][2] = 'new-79db93f6-eb4b-47e6-a9f0-7b7268c4e580';
    $pane = new stdClass();
    $pane->pid = 'new-8daaf689-650a-472c-acb2-ed11cd42d9eb';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '8daaf689-650a-472c-acb2-ed11cd42d9eb';
    $display->content['new-8daaf689-650a-472c-acb2-ed11cd42d9eb'] = $pane;
    $display->panels['secondary'][3] = 'new-8daaf689-650a-472c-acb2-ed11cd42d9eb';
    $pane = new stdClass();
    $pane->pid = 'new-8cf18cdd-f23b-4914-b05e-ebaecac864bd';
    $pane->panel = 'secondary';
    $pane->type = 'views_panes';
    $pane->subtype = 'related_qa-small_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '8cf18cdd-f23b-4914-b05e-ebaecac864bd';
    $display->content['new-8cf18cdd-f23b-4914-b05e-ebaecac864bd'] = $pane;
    $display->panels['secondary'][4] = 'new-8cf18cdd-f23b-4914-b05e-ebaecac864bd';
    $pane = new stdClass();
    $pane->pid = 'new-e2de38ba-d688-4fa8-b2bf-643839ba9f6c';
    $pane->panel = 'secondary';
    $pane->type = 'coral_authors';
    $pane->subtype = 'coral_authors';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
      ),
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
    $pane->uuid = 'e2de38ba-d688-4fa8-b2bf-643839ba9f6c';
    $display->content['new-e2de38ba-d688-4fa8-b2bf-643839ba9f6c'] = $pane;
    $display->panels['secondary'][5] = 'new-e2de38ba-d688-4fa8-b2bf-643839ba9f6c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:book:default'] = $panelizer;

  return $export;
}
