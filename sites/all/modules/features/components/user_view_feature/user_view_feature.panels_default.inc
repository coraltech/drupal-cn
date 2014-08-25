<?php
/**
 * @file
 * user_view_feature.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function user_view_feature_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'user_content';
  $mini->category = 'User';
  $mini->admin_title = 'User content';
  $mini->admin_description = 'A mini panel that we can use to wrap tabs around user content view displays.';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => array(
        'panel_tab_id_pattern' => 'region',
      ),
    ),
    'middle' => array(
      'style' => 'tabs',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '69d68a75-9b49-4fe4-98c8-013ba63f8104';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8f672f74-7c7a-42bd-8af9-df63a6403a58';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_content-user_questions_fields';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8f672f74-7c7a-42bd-8af9-df63a6403a58';
    $display->content['new-8f672f74-7c7a-42bd-8af9-df63a6403a58'] = $pane;
    $display->panels['middle'][0] = 'new-8f672f74-7c7a-42bd-8af9-df63a6403a58';
    $pane = new stdClass();
    $pane->pid = 'new-cd3eaac1-2976-4d0d-9be4-fb08c0e52b12';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_content-user_snippets_fields';
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
    $pane->uuid = 'cd3eaac1-2976-4d0d-9be4-fb08c0e52b12';
    $display->content['new-cd3eaac1-2976-4d0d-9be4-fb08c0e52b12'] = $pane;
    $display->panels['middle'][1] = 'new-cd3eaac1-2976-4d0d-9be4-fb08c0e52b12';
    $pane = new stdClass();
    $pane->pid = 'new-0243bc80-6658-49c4-9cec-206931a51b46';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_content-panel_pane_1';
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
    $pane->uuid = '0243bc80-6658-49c4-9cec-206931a51b46';
    $display->content['new-0243bc80-6658-49c4-9cec-206931a51b46'] = $pane;
    $display->panels['middle'][2] = 'new-0243bc80-6658-49c4-9cec-206931a51b46';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8f672f74-7c7a-42bd-8af9-df63a6403a58';
  $mini->display = $display;
  $export['user_content'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'user_header';
  $mini->category = 'user';
  $mini->admin_title = 'User header';
  $mini->admin_description = 'Groups a few user related panes that display together';
  $mini->requiredcontexts = array(
    0 => array(
      'identifier' => 'User',
      'keyword' => 'user',
      'name' => 'user',
      'type' => 'select',
      'uid' => '',
      'id' => 1,
    ),
  );
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'mosaic_1col_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'center' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a26c3628-3531-4c26-ab2b-e5b609de2f3a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4cb7fb49-f5be-44b8-a4f3-5ea472acf95a';
    $pane->panel = 'top';
    $pane->type = 'user_picture';
    $pane->subtype = 'user_picture';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'requiredcontext_user_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'left mr-1',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4cb7fb49-f5be-44b8-a4f3-5ea472acf95a';
    $display->content['new-4cb7fb49-f5be-44b8-a4f3-5ea472acf95a'] = $pane;
    $display->panels['top'][0] = 'new-4cb7fb49-f5be-44b8-a4f3-5ea472acf95a';
    $pane = new stdClass();
    $pane->pid = 'new-3ebd1c5d-084d-452c-952e-29473a3100ae';
    $pane->panel = 'top';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_display_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'requiredcontext_user_1',
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
    $pane->uuid = '3ebd1c5d-084d-452c-952e-29473a3100ae';
    $display->content['new-3ebd1c5d-084d-452c-952e-29473a3100ae'] = $pane;
    $display->panels['top'][1] = 'new-3ebd1c5d-084d-452c-952e-29473a3100ae';
    $pane = new stdClass();
    $pane->pid = 'new-b9d08eee-22b1-4b3a-851c-217e710749ce';
    $pane->panel = 'top';
    $pane->type = 'token';
    $pane->subtype = 'user:last-login';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'requiredcontext_user_1',
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
    $pane->uuid = 'b9d08eee-22b1-4b3a-851c-217e710749ce';
    $display->content['new-b9d08eee-22b1-4b3a-851c-217e710749ce'] = $pane;
    $display->panels['top'][2] = 'new-b9d08eee-22b1-4b3a-851c-217e710749ce';
    $pane = new stdClass();
    $pane->pid = 'new-e154c00a-dcaa-4822-b4b4-34fa1347403d';
    $pane->panel = 'top';
    $pane->type = 'coral_break_line';
    $pane->subtype = 'coral_break_line';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'line_height' => '4.1',
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
    $pane->uuid = 'e154c00a-dcaa-4822-b4b4-34fa1347403d';
    $display->content['new-e154c00a-dcaa-4822-b4b4-34fa1347403d'] = $pane;
    $display->panels['top'][3] = 'new-e154c00a-dcaa-4822-b4b4-34fa1347403d';
    $pane = new stdClass();
    $pane->pid = 'new-c9927c2d-215b-4d1a-8dd3-2b4cae602e79';
    $pane->panel = 'top';
    $pane->type = 'token';
    $pane->subtype = 'user:name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'requiredcontext_user_1',
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'c9927c2d-215b-4d1a-8dd3-2b4cae602e79';
    $display->content['new-c9927c2d-215b-4d1a-8dd3-2b4cae602e79'] = $pane;
    $display->panels['top'][4] = 'new-c9927c2d-215b-4d1a-8dd3-2b4cae602e79';
    $pane = new stdClass();
    $pane->pid = 'new-c31203c7-82ce-4575-8a87-44d089868540';
    $pane->panel = 'top';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'c31203c7-82ce-4575-8a87-44d089868540';
    $display->content['new-c31203c7-82ce-4575-8a87-44d089868540'] = $pane;
    $display->panels['top'][5] = 'new-c31203c7-82ce-4575-8a87-44d089868540';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3ebd1c5d-084d-452c-952e-29473a3100ae';
  $mini->display = $display;
  $export['user_header'] = $mini;

  return $export;
}
