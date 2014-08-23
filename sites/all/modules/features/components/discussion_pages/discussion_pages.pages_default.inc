<?php
/**
 * @file
 * discussion_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function discussion_pages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'comment_reply_panel_context';
  $handler->task = 'comment_reply';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Comment reply default',
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
  $display->layout = 'mosaic_node_1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'leader' => NULL,
      'main' => NULL,
      'secondary' => NULL,
      'follower' => NULL,
      'sub_footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Commenting on <em>%comment:subject</em>';
  $display->uuid = '624de6d4-9c28-4661-8d37-e660ee4b1b81';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8eb46f0d-572d-444c-b240-a4ecacadf503';
    $pane->panel = 'leader';
    $pane->type = 'coral_swipe';
    $pane->subtype = 'coral_swipe';
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
    $pane->uuid = '8eb46f0d-572d-444c-b240-a4ecacadf503';
    $display->content['new-8eb46f0d-572d-444c-b240-a4ecacadf503'] = $pane;
    $display->panels['leader'][0] = 'new-8eb46f0d-572d-444c-b240-a4ecacadf503';
    $pane = new stdClass();
    $pane->pid = 'new-4fecff38-e5e6-4237-af74-670d38237ae5';
    $pane->panel = 'main';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => 'page-title',
      'id' => '',
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
    $pane->uuid = '4fecff38-e5e6-4237-af74-670d38237ae5';
    $display->content['new-4fecff38-e5e6-4237-af74-670d38237ae5'] = $pane;
    $display->panels['main'][0] = 'new-4fecff38-e5e6-4237-af74-670d38237ae5';
    $pane = new stdClass();
    $pane->pid = 'new-82ef6ccb-12ff-4db7-9711-20967fe29370';
    $pane->panel = 'main';
    $pane->type = 'entity_view';
    $pane->subtype = 'comment';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:comment_3',
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
    $pane->uuid = '82ef6ccb-12ff-4db7-9711-20967fe29370';
    $display->content['new-82ef6ccb-12ff-4db7-9711-20967fe29370'] = $pane;
    $display->panels['main'][1] = 'new-82ef6ccb-12ff-4db7-9711-20967fe29370';
    $pane = new stdClass();
    $pane->pid = 'new-72856e66-b50c-461d-9c6d-f694241a5adf';
    $pane->panel = 'main';
    $pane->type = 'coral_comment_reply';
    $pane->subtype = 'coral_comment_reply';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => FALSE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '72856e66-b50c-461d-9c6d-f694241a5adf';
    $display->content['new-72856e66-b50c-461d-9c6d-f694241a5adf'] = $pane;
    $display->panels['main'][2] = 'new-72856e66-b50c-461d-9c6d-f694241a5adf';
    $pane = new stdClass();
    $pane->pid = 'new-ccbba76b-af91-47b3-b1ce-aace68c08083';
    $pane->panel = 'main';
    $pane->type = 'coral_back_to';
    $pane->subtype = 'coral_back_to';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inline_title' => 1,
      'title' => NULL,
      'override_title' => 1,
      'override_title_text' => '',
      'inline_title_text' => 'Back to &raquo;',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'ccbba76b-af91-47b3-b1ce-aace68c08083';
    $display->content['new-ccbba76b-af91-47b3-b1ce-aace68c08083'] = $pane;
    $display->panels['main'][3] = 'new-ccbba76b-af91-47b3-b1ce-aace68c08083';
    $pane = new stdClass();
    $pane->pid = 'new-4acdc696-cbed-448c-8a3b-8a4144b365ce';
    $pane->panel = 'secondary';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full_node',
      'context' => 'argument_entity_id:node_2',
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
    $pane->uuid = '4acdc696-cbed-448c-8a3b-8a4144b365ce';
    $display->content['new-4acdc696-cbed-448c-8a3b-8a4144b365ce'] = $pane;
    $display->panels['secondary'][0] = 'new-4acdc696-cbed-448c-8a3b-8a4144b365ce';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['comment_reply_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'comment_reply_panel_context_2';
  $handler->task = 'comment_reply';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Snippet comment reply',
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
          'context' => 'argument_entity_id:node_2',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'mosaic_node_1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'leader' => NULL,
      'main' => NULL,
      'secondary' => NULL,
      'follower' => NULL,
      'sub_footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Commenting on <em>%comment:subject</em>';
  $display->uuid = 'c32ca23a-9d94-4389-ac1f-4dfce9cab155';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-651a4efa-3a23-40e3-b638-538ffa111253';
    $pane->panel = 'leader';
    $pane->type = 'coral_swipe';
    $pane->subtype = 'coral_swipe';
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
    $pane->uuid = '651a4efa-3a23-40e3-b638-538ffa111253';
    $display->content['new-651a4efa-3a23-40e3-b638-538ffa111253'] = $pane;
    $display->panels['leader'][0] = 'new-651a4efa-3a23-40e3-b638-538ffa111253';
    $pane = new stdClass();
    $pane->pid = 'new-74ea88df-c49d-4bdb-96fb-e9abe411b936';
    $pane->panel = 'main';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => 'page-title',
      'id' => '',
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
    $pane->uuid = '74ea88df-c49d-4bdb-96fb-e9abe411b936';
    $display->content['new-74ea88df-c49d-4bdb-96fb-e9abe411b936'] = $pane;
    $display->panels['main'][0] = 'new-74ea88df-c49d-4bdb-96fb-e9abe411b936';
    $pane = new stdClass();
    $pane->pid = 'new-60872e21-22b7-41ee-945b-ce7ac1cf7dd9';
    $pane->panel = 'main';
    $pane->type = 'entity_view';
    $pane->subtype = 'comment';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:comment_3',
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
    $pane->uuid = '60872e21-22b7-41ee-945b-ce7ac1cf7dd9';
    $display->content['new-60872e21-22b7-41ee-945b-ce7ac1cf7dd9'] = $pane;
    $display->panels['main'][1] = 'new-60872e21-22b7-41ee-945b-ce7ac1cf7dd9';
    $pane = new stdClass();
    $pane->pid = 'new-be616184-ce32-416c-bed4-b55cd4481f4a';
    $pane->panel = 'main';
    $pane->type = 'coral_comment_reply';
    $pane->subtype = 'coral_comment_reply';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => FALSE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'be616184-ce32-416c-bed4-b55cd4481f4a';
    $display->content['new-be616184-ce32-416c-bed4-b55cd4481f4a'] = $pane;
    $display->panels['main'][2] = 'new-be616184-ce32-416c-bed4-b55cd4481f4a';
    $pane = new stdClass();
    $pane->pid = 'new-208793a2-942e-42ff-959b-a52d37be4703';
    $pane->panel = 'main';
    $pane->type = 'coral_back_to';
    $pane->subtype = 'coral_back_to';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inline_title' => 1,
      'title' => NULL,
      'override_title' => 1,
      'override_title_text' => '',
      'inline_title_text' => 'Back to &raquo;',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '208793a2-942e-42ff-959b-a52d37be4703';
    $display->content['new-208793a2-942e-42ff-959b-a52d37be4703'] = $pane;
    $display->panels['main'][3] = 'new-208793a2-942e-42ff-959b-a52d37be4703';
    $pane = new stdClass();
    $pane->pid = 'new-0cfa7b1f-63c5-41f4-8ebe-f26006fd6b48';
    $pane->panel = 'secondary';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'markup' => 'none',
      'id' => '',
      'class' => 'page-title',
      'context' => 'argument_entity_id:node_2',
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
    $pane->uuid = '0cfa7b1f-63c5-41f4-8ebe-f26006fd6b48';
    $display->content['new-0cfa7b1f-63c5-41f4-8ebe-f26006fd6b48'] = $pane;
    $display->panels['secondary'][0] = 'new-0cfa7b1f-63c5-41f4-8ebe-f26006fd6b48';
    $pane = new stdClass();
    $pane->pid = 'new-e9c5ad6d-2353-4399-9c05-5a6014e5774b';
    $pane->panel = 'secondary';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'teaser',
      'context' => 'argument_entity_id:node_2',
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
    $pane->uuid = 'e9c5ad6d-2353-4399-9c05-5a6014e5774b';
    $display->content['new-e9c5ad6d-2353-4399-9c05-5a6014e5774b'] = $pane;
    $display->panels['secondary'][1] = 'new-e9c5ad6d-2353-4399-9c05-5a6014e5774b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['comment_reply_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_node_talk_panel_context';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'node_talk';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Node talk',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'node-talk',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'mosaic_node_1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'leader' => NULL,
      'main' => NULL,
      'secondary' => NULL,
      'follower' => NULL,
      'sub_footer' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Discussing <em>%node:title</em>';
  $display->uuid = '635389ef-9aba-4bf3-a6cc-1b4b28a7639a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9d1e786f-30ae-4123-8e9e-752c324fffc6';
    $pane->panel = 'leader';
    $pane->type = 'coral_community_tabs';
    $pane->subtype = 'coral_community_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'active_tab' => '0',
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
    $pane->uuid = '9d1e786f-30ae-4123-8e9e-752c324fffc6';
    $display->content['new-9d1e786f-30ae-4123-8e9e-752c324fffc6'] = $pane;
    $display->panels['leader'][0] = 'new-9d1e786f-30ae-4123-8e9e-752c324fffc6';
    $pane = new stdClass();
    $pane->pid = 'new-46a0e0db-f87e-4d51-a3c0-352452c50f61';
    $pane->panel = 'leader';
    $pane->type = 'coral_swipe';
    $pane->subtype = 'coral_swipe';
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
    $pane->uuid = '46a0e0db-f87e-4d51-a3c0-352452c50f61';
    $display->content['new-46a0e0db-f87e-4d51-a3c0-352452c50f61'] = $pane;
    $display->panels['leader'][1] = 'new-46a0e0db-f87e-4d51-a3c0-352452c50f61';
    $pane = new stdClass();
    $pane->pid = 'new-edf834c4-398d-4f39-a9c7-79e3fd798f88';
    $pane->panel = 'main';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => 'page-title',
      'id' => '',
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
    $pane->uuid = 'edf834c4-398d-4f39-a9c7-79e3fd798f88';
    $display->content['new-edf834c4-398d-4f39-a9c7-79e3fd798f88'] = $pane;
    $display->panels['main'][0] = 'new-edf834c4-398d-4f39-a9c7-79e3fd798f88';
    $pane = new stdClass();
    $pane->pid = 'new-10ac56f3-4481-485d-a92f-1a36e7dec8d3';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'discussion_comments-talk';
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
    $pane->uuid = '10ac56f3-4481-485d-a92f-1a36e7dec8d3';
    $display->content['new-10ac56f3-4481-485d-a92f-1a36e7dec8d3'] = $pane;
    $display->panels['main'][1] = 'new-10ac56f3-4481-485d-a92f-1a36e7dec8d3';
    $pane = new stdClass();
    $pane->pid = 'new-4ebf1cc0-1c62-4e04-99d8-eb56ea01a4ef';
    $pane->panel = 'main';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'anon_links' => 0,
      'context' => 'argument_entity_id:node_1',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4ebf1cc0-1c62-4e04-99d8-eb56ea01a4ef';
    $display->content['new-4ebf1cc0-1c62-4e04-99d8-eb56ea01a4ef'] = $pane;
    $display->panels['main'][2] = 'new-4ebf1cc0-1c62-4e04-99d8-eb56ea01a4ef';
    $pane = new stdClass();
    $pane->pid = 'new-3122d58a-9609-4fd8-b4fc-3dbc8eec4d8c';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'user-login';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Log in to join discussion',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '3122d58a-9609-4fd8-b4fc-3dbc8eec4d8c';
    $display->content['new-3122d58a-9609-4fd8-b4fc-3dbc8eec4d8c'] = $pane;
    $display->panels['main'][3] = 'new-3122d58a-9609-4fd8-b4fc-3dbc8eec4d8c';
    $pane = new stdClass();
    $pane->pid = 'new-74544be8-36fe-4d21-bc8a-88edd08df560';
    $pane->panel = 'secondary';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full_node',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '74544be8-36fe-4d21-bc8a-88edd08df560';
    $display->content['new-74544be8-36fe-4d21-bc8a-88edd08df560'] = $pane;
    $display->panels['secondary'][0] = 'new-74544be8-36fe-4d21-bc8a-88edd08df560';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_node_talk_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_node_talk_panel_context_2';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'node_talk';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Snippet talk',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'node-talk',
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
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'mosaic_node_1';
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
  $display->title = 'Discussing <em>%node:title</em>';
  $display->uuid = '4f5a6f96-ac78-43ce-8440-b8e0d6406f54';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9f416b58-cc5e-42b2-9530-27e8698af814';
    $pane->panel = 'leader';
    $pane->type = 'coral_swipe';
    $pane->subtype = 'coral_swipe';
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
    $pane->uuid = '9f416b58-cc5e-42b2-9530-27e8698af814';
    $display->content['new-9f416b58-cc5e-42b2-9530-27e8698af814'] = $pane;
    $display->panels['leader'][0] = 'new-9f416b58-cc5e-42b2-9530-27e8698af814';
    $pane = new stdClass();
    $pane->pid = 'new-581d8337-675e-4907-b01a-2c660fa2404e';
    $pane->panel = 'main';
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
    $pane->uuid = '581d8337-675e-4907-b01a-2c660fa2404e';
    $display->content['new-581d8337-675e-4907-b01a-2c660fa2404e'] = $pane;
    $display->panels['main'][0] = 'new-581d8337-675e-4907-b01a-2c660fa2404e';
    $pane = new stdClass();
    $pane->pid = 'new-6f833792-1d5b-4626-b556-7377b014df52';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'discussion_comments-talk';
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
    $pane->uuid = '6f833792-1d5b-4626-b556-7377b014df52';
    $display->content['new-6f833792-1d5b-4626-b556-7377b014df52'] = $pane;
    $display->panels['main'][1] = 'new-6f833792-1d5b-4626-b556-7377b014df52';
    $pane = new stdClass();
    $pane->pid = 'new-b9f53d35-9024-4f96-81ae-7fe8beb79683';
    $pane->panel = 'main';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'anon_links' => 0,
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = 'b9f53d35-9024-4f96-81ae-7fe8beb79683';
    $display->content['new-b9f53d35-9024-4f96-81ae-7fe8beb79683'] = $pane;
    $display->panels['main'][2] = 'new-b9f53d35-9024-4f96-81ae-7fe8beb79683';
    $pane = new stdClass();
    $pane->pid = 'new-3beb6cd2-483d-446f-b6c8-cfe86b038eaf';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'user-login';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Log in to join discussion',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '3beb6cd2-483d-446f-b6c8-cfe86b038eaf';
    $display->content['new-3beb6cd2-483d-446f-b6c8-cfe86b038eaf'] = $pane;
    $display->panels['main'][3] = 'new-3beb6cd2-483d-446f-b6c8-cfe86b038eaf';
    $pane = new stdClass();
    $pane->pid = 'new-3b1ab8ef-9b15-4fd8-8f85-d58c0499a8e1';
    $pane->panel = 'secondary';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'teaser',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '3b1ab8ef-9b15-4fd8-8f85-d58c0499a8e1';
    $display->content['new-3b1ab8ef-9b15-4fd8-8f85-d58c0499a8e1'] = $pane;
    $display->panels['secondary'][0] = 'new-3b1ab8ef-9b15-4fd8-8f85-d58c0499a8e1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_node_talk_panel_context_2'] = $handler;

  return $export;
}
