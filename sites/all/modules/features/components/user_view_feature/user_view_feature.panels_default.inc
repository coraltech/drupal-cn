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
  $display->uuid = '3f414a0b-bfbd-4641-adb4-9bb18accb6bb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fb733700-8dd7-4e32-9981-aa66ef83116e';
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
    $pane->uuid = 'fb733700-8dd7-4e32-9981-aa66ef83116e';
    $display->content['new-fb733700-8dd7-4e32-9981-aa66ef83116e'] = $pane;
    $display->panels['middle'][0] = 'new-fb733700-8dd7-4e32-9981-aa66ef83116e';
    $pane = new stdClass();
    $pane->pid = 'new-4e521ea6-b049-4eb1-880c-b949f54f5fb5';
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
    $pane->uuid = '4e521ea6-b049-4eb1-880c-b949f54f5fb5';
    $display->content['new-4e521ea6-b049-4eb1-880c-b949f54f5fb5'] = $pane;
    $display->panels['middle'][1] = 'new-4e521ea6-b049-4eb1-880c-b949f54f5fb5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-fb733700-8dd7-4e32-9981-aa66ef83116e';
  $mini->display = $display;
  $export['user_content'] = $mini;

  return $export;
}
