<?php
/**
 * @file
 * user_view_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function user_view_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'user:user:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'user';
  $panelizer->panelizer_key = 'user';
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
      'sub_footer' => array(
        'panel_tab_id_pattern' => 'region',
      ),
      'follower' => NULL,
    ),
    'follower' => array(
      'style' => 'default',
    ),
    'sub_footer' => array(
      'style' => 'tabs',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0e1d26f2-3be3-4e4c-808f-eddebb3f87f5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bdc6b6e8-87bf-4fb1-8d2e-b85ded4e606e';
    $pane->panel = 'follower';
    $pane->type = 'panels_mini';
    $pane->subtype = 'user_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'bdc6b6e8-87bf-4fb1-8d2e-b85ded4e606e';
    $display->content['new-bdc6b6e8-87bf-4fb1-8d2e-b85ded4e606e'] = $pane;
    $display->panels['follower'][0] = 'new-bdc6b6e8-87bf-4fb1-8d2e-b85ded4e606e';
    $pane = new stdClass();
    $pane->pid = 'new-0170beed-8ca6-406d-8ec2-6f468de493b4';
    $pane->panel = 'follower';
    $pane->type = 'coral_user_bookmarks_intro';
    $pane->subtype = 'coral_user_bookmarks_intro';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'clear',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0170beed-8ca6-406d-8ec2-6f468de493b4';
    $display->content['new-0170beed-8ca6-406d-8ec2-6f468de493b4'] = $pane;
    $display->panels['follower'][1] = 'new-0170beed-8ca6-406d-8ec2-6f468de493b4';
    $pane = new stdClass();
    $pane->pid = 'new-8a6c828e-ae73-48f1-8e7a-ccf83f2cf04f';
    $pane->panel = 'leader';
    $pane->type = 'token';
    $pane->subtype = 'user:picture';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'left',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8a6c828e-ae73-48f1-8e7a-ccf83f2cf04f';
    $display->content['new-8a6c828e-ae73-48f1-8e7a-ccf83f2cf04f'] = $pane;
    $display->panels['leader'][0] = 'new-8a6c828e-ae73-48f1-8e7a-ccf83f2cf04f';
    $pane = new stdClass();
    $pane->pid = 'new-a5dd8358-c0d5-4c87-b57d-ca42b056b23e';
    $pane->panel = 'leader';
    $pane->type = 'token';
    $pane->subtype = 'user:name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'left',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a5dd8358-c0d5-4c87-b57d-ca42b056b23e';
    $display->content['new-a5dd8358-c0d5-4c87-b57d-ca42b056b23e'] = $pane;
    $display->panels['leader'][1] = 'new-a5dd8358-c0d5-4c87-b57d-ca42b056b23e';
    $pane = new stdClass();
    $pane->pid = 'new-3a6507da-fba6-427e-a2d6-e64de300c735';
    $pane->panel = 'leader';
    $pane->type = 'token';
    $pane->subtype = 'user:last-login';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'left',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3a6507da-fba6-427e-a2d6-e64de300c735';
    $display->content['new-3a6507da-fba6-427e-a2d6-e64de300c735'] = $pane;
    $display->panels['leader'][2] = 'new-3a6507da-fba6-427e-a2d6-e64de300c735';
    $pane = new stdClass();
    $pane->pid = 'new-a69ef6af-8a98-4773-a671-abc2fd5d815a';
    $pane->panel = 'leader';
    $pane->type = 'coral_user_edit_link';
    $pane->subtype = 'coral_user_edit_link';
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
    $pane->uuid = 'a69ef6af-8a98-4773-a671-abc2fd5d815a';
    $display->content['new-a69ef6af-8a98-4773-a671-abc2fd5d815a'] = $pane;
    $display->panels['leader'][3] = 'new-a69ef6af-8a98-4773-a671-abc2fd5d815a';
    $pane = new stdClass();
    $pane->pid = 'new-89f11263-2f0d-4c0b-8c8a-b5bed9ce4568';
    $pane->panel = 'main';
    $pane->type = 'user_profile';
    $pane->subtype = 'user_profile';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '89f11263-2f0d-4c0b-8c8a-b5bed9ce4568';
    $display->content['new-89f11263-2f0d-4c0b-8c8a-b5bed9ce4568'] = $pane;
    $display->panels['main'][0] = 'new-89f11263-2f0d-4c0b-8c8a-b5bed9ce4568';
    $pane = new stdClass();
    $pane->pid = 'new-74a0e6d6-29b0-4df6-b2a7-887fce0d451d';
    $pane->panel = 'secondary';
    $pane->type = 'block';
    $pane->subtype = 'menu-general';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'General',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'prepend-2 grid-8',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '74a0e6d6-29b0-4df6-b2a7-887fce0d451d';
    $display->content['new-74a0e6d6-29b0-4df6-b2a7-887fce0d451d'] = $pane;
    $display->panels['secondary'][0] = 'new-74a0e6d6-29b0-4df6-b2a7-887fce0d451d';
    $pane = new stdClass();
    $pane->pid = 'new-16fba3f0-33e8-4976-b777-e210b699656e';
    $pane->panel = 'secondary';
    $pane->type = 'user_signature';
    $pane->subtype = 'user_signature';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'Signature',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'prepend-2 grid-12',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '16fba3f0-33e8-4976-b777-e210b699656e';
    $display->content['new-16fba3f0-33e8-4976-b777-e210b699656e'] = $pane;
    $display->panels['secondary'][1] = 'new-16fba3f0-33e8-4976-b777-e210b699656e';
    $pane = new stdClass();
    $pane->pid = 'new-7d505a1b-b0f4-4d42-8dca-0df88051ea99';
    $pane->panel = 'sub_footer';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_bookmarks-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '7d505a1b-b0f4-4d42-8dca-0df88051ea99';
    $display->content['new-7d505a1b-b0f4-4d42-8dca-0df88051ea99'] = $pane;
    $display->panels['sub_footer'][0] = 'new-7d505a1b-b0f4-4d42-8dca-0df88051ea99';
    $pane = new stdClass();
    $pane->pid = 'new-41cc69ee-251a-4a21-b85d-e200361bcb8b';
    $pane->panel = 'sub_footer';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_bookmarks-user_bookmarked_snippets';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Snippets',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '41cc69ee-251a-4a21-b85d-e200361bcb8b';
    $display->content['new-41cc69ee-251a-4a21-b85d-e200361bcb8b'] = $pane;
    $display->panels['sub_footer'][1] = 'new-41cc69ee-251a-4a21-b85d-e200361bcb8b';
    $pane = new stdClass();
    $pane->pid = 'new-c2b35fce-cdab-48a2-b629-f0f7ee992f64';
    $pane->panel = 'sub_footer';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_bookmarks-user_bookmarked_wiki';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'c2b35fce-cdab-48a2-b629-f0f7ee992f64';
    $display->content['new-c2b35fce-cdab-48a2-b629-f0f7ee992f64'] = $pane;
    $display->panels['sub_footer'][2] = 'new-c2b35fce-cdab-48a2-b629-f0f7ee992f64';
    $pane = new stdClass();
    $pane->pid = 'new-02a50631-51fc-4dc3-9f72-134ee493d758';
    $pane->panel = 'sub_footer';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_bookmarks-user_bookmarked_questions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '02a50631-51fc-4dc3-9f72-134ee493d758';
    $display->content['new-02a50631-51fc-4dc3-9f72-134ee493d758'] = $pane;
    $display->panels['sub_footer'][3] = 'new-02a50631-51fc-4dc3-9f72-134ee493d758';
    $pane = new stdClass();
    $pane->pid = 'new-cedb1dea-da6b-445c-9ce6-f87c0b60d37e';
    $pane->panel = 'sub_footer';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_bookmarks-user_bookmarked_answers';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'cedb1dea-da6b-445c-9ce6-f87c0b60d37e';
    $display->content['new-cedb1dea-da6b-445c-9ce6-f87c0b60d37e'] = $pane;
    $display->panels['sub_footer'][4] = 'new-cedb1dea-da6b-445c-9ce6-f87c0b60d37e';
    $pane = new stdClass();
    $pane->pid = 'new-68ac0aec-7f5c-4ba6-9dd1-d5fe5307adff';
    $pane->panel = 'sub_footer';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_bookmarks-user_bookmarked_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '68ac0aec-7f5c-4ba6-9dd1-d5fe5307adff';
    $display->content['new-68ac0aec-7f5c-4ba6-9dd1-d5fe5307adff'] = $pane;
    $display->panels['sub_footer'][5] = 'new-68ac0aec-7f5c-4ba6-9dd1-d5fe5307adff';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['user:user:default'] = $panelizer;

  return $export;
}
