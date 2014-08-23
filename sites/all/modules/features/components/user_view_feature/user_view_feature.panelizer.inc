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
  $display->uuid = '530f2e80-896a-4482-bb48-7d7b8ac43408';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f8e331c6-09b9-4265-a315-99efbcebdf5a';
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
    $pane->uuid = 'f8e331c6-09b9-4265-a315-99efbcebdf5a';
    $display->content['new-f8e331c6-09b9-4265-a315-99efbcebdf5a'] = $pane;
    $display->panels['follower'][0] = 'new-f8e331c6-09b9-4265-a315-99efbcebdf5a';
    $pane = new stdClass();
    $pane->pid = 'new-7ff93dc6-8a10-406a-8bae-7b83d6a92283';
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
    $pane->uuid = '7ff93dc6-8a10-406a-8bae-7b83d6a92283';
    $display->content['new-7ff93dc6-8a10-406a-8bae-7b83d6a92283'] = $pane;
    $display->panels['follower'][1] = 'new-7ff93dc6-8a10-406a-8bae-7b83d6a92283';
    $pane = new stdClass();
    $pane->pid = 'new-84074820-2bc5-438b-bd8c-b394872308b4';
    $pane->panel = 'leader';
    $pane->type = 'panels_mini';
    $pane->subtype = 'user_header';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '84074820-2bc5-438b-bd8c-b394872308b4';
    $display->content['new-84074820-2bc5-438b-bd8c-b394872308b4'] = $pane;
    $display->panels['leader'][0] = 'new-84074820-2bc5-438b-bd8c-b394872308b4';
    $pane = new stdClass();
    $pane->pid = 'new-4a0bdbac-b2bd-415e-8031-2751090f4322';
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
    $pane->uuid = '4a0bdbac-b2bd-415e-8031-2751090f4322';
    $display->content['new-4a0bdbac-b2bd-415e-8031-2751090f4322'] = $pane;
    $display->panels['main'][0] = 'new-4a0bdbac-b2bd-415e-8031-2751090f4322';
    $pane = new stdClass();
    $pane->pid = 'new-70f3043f-5d49-4af8-b2be-4a54b9629a16';
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
      'css_class' => 'grid-11-last prepend-1',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '70f3043f-5d49-4af8-b2be-4a54b9629a16';
    $display->content['new-70f3043f-5d49-4af8-b2be-4a54b9629a16'] = $pane;
    $display->panels['secondary'][0] = 'new-70f3043f-5d49-4af8-b2be-4a54b9629a16';
    $pane = new stdClass();
    $pane->pid = 'new-b0ba6270-463c-45c6-a5bb-6d4777e8b0f6';
    $pane->panel = 'secondary';
    $pane->type = 'block';
    $pane->subtype = 'menu-create';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'compare_users',
          'settings' => array(
            'equality' => '1',
          ),
          'context' => array(
            0 => 'panelizer',
            1 => 'logged-in-user',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Add content',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'prepend-1 grid-11',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b0ba6270-463c-45c6-a5bb-6d4777e8b0f6';
    $display->content['new-b0ba6270-463c-45c6-a5bb-6d4777e8b0f6'] = $pane;
    $display->panels['secondary'][1] = 'new-b0ba6270-463c-45c6-a5bb-6d4777e8b0f6';
    $pane = new stdClass();
    $pane->pid = 'new-b2a4029a-c883-4542-bdeb-5165c445bb16';
    $pane->panel = 'secondary';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_biography';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'Biography',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'left prepend-1 mb-25',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b2a4029a-c883-4542-bdeb-5165c445bb16';
    $display->content['new-b2a4029a-c883-4542-bdeb-5165c445bb16'] = $pane;
    $display->panels['secondary'][2] = 'new-b2a4029a-c883-4542-bdeb-5165c445bb16';
    $pane = new stdClass();
    $pane->pid = 'new-5d6fce35-92cd-46c7-a389-479c74d8199a';
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
    $pane->uuid = '5d6fce35-92cd-46c7-a389-479c74d8199a';
    $display->content['new-5d6fce35-92cd-46c7-a389-479c74d8199a'] = $pane;
    $display->panels['sub_footer'][0] = 'new-5d6fce35-92cd-46c7-a389-479c74d8199a';
    $pane = new stdClass();
    $pane->pid = 'new-67496107-3b44-49bd-8855-14c7777e4e86';
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
    $pane->uuid = '67496107-3b44-49bd-8855-14c7777e4e86';
    $display->content['new-67496107-3b44-49bd-8855-14c7777e4e86'] = $pane;
    $display->panels['sub_footer'][1] = 'new-67496107-3b44-49bd-8855-14c7777e4e86';
    $pane = new stdClass();
    $pane->pid = 'new-9ed55bf6-f615-455b-95c3-592ede75f305';
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
    $pane->uuid = '9ed55bf6-f615-455b-95c3-592ede75f305';
    $display->content['new-9ed55bf6-f615-455b-95c3-592ede75f305'] = $pane;
    $display->panels['sub_footer'][2] = 'new-9ed55bf6-f615-455b-95c3-592ede75f305';
    $pane = new stdClass();
    $pane->pid = 'new-363b4e09-fc66-4303-bbca-ddb4ceb058ba';
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
    $pane->uuid = '363b4e09-fc66-4303-bbca-ddb4ceb058ba';
    $display->content['new-363b4e09-fc66-4303-bbca-ddb4ceb058ba'] = $pane;
    $display->panels['sub_footer'][3] = 'new-363b4e09-fc66-4303-bbca-ddb4ceb058ba';
    $pane = new stdClass();
    $pane->pid = 'new-b8ded516-043b-4c14-b302-2a7ddac4d497';
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
    $pane->uuid = 'b8ded516-043b-4c14-b302-2a7ddac4d497';
    $display->content['new-b8ded516-043b-4c14-b302-2a7ddac4d497'] = $pane;
    $display->panels['sub_footer'][4] = 'new-b8ded516-043b-4c14-b302-2a7ddac4d497';
    $pane = new stdClass();
    $pane->pid = 'new-4bf0bbc7-e716-4e38-8be0-9bf352182780';
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
    $pane->uuid = '4bf0bbc7-e716-4e38-8be0-9bf352182780';
    $display->content['new-4bf0bbc7-e716-4e38-8be0-9bf352182780'] = $pane;
    $display->panels['sub_footer'][5] = 'new-4bf0bbc7-e716-4e38-8be0-9bf352182780';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['user:user:default'] = $panelizer;

  return $export;
}
