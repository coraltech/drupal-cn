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
  $display->uuid = '2eace156-6b60-468e-a779-1bbb112d49e0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-eafee779-9641-46cc-a37e-e7d15eee9dc6';
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
    $pane->uuid = 'eafee779-9641-46cc-a37e-e7d15eee9dc6';
    $display->content['new-eafee779-9641-46cc-a37e-e7d15eee9dc6'] = $pane;
    $display->panels['leader'][0] = 'new-eafee779-9641-46cc-a37e-e7d15eee9dc6';
    $pane = new stdClass();
    $pane->pid = 'new-ececef3d-e729-4ef5-9058-b34d061d4eae';
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
    $pane->uuid = 'ececef3d-e729-4ef5-9058-b34d061d4eae';
    $display->content['new-ececef3d-e729-4ef5-9058-b34d061d4eae'] = $pane;
    $display->panels['main'][0] = 'new-ececef3d-e729-4ef5-9058-b34d061d4eae';
    $pane = new stdClass();
    $pane->pid = 'new-ce6b18fa-c928-4462-bf01-ca4cfc0615ad';
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
    $pane->uuid = 'ce6b18fa-c928-4462-bf01-ca4cfc0615ad';
    $display->content['new-ce6b18fa-c928-4462-bf01-ca4cfc0615ad'] = $pane;
    $display->panels['main'][1] = 'new-ce6b18fa-c928-4462-bf01-ca4cfc0615ad';
    $pane = new stdClass();
    $pane->pid = 'new-3f9c61b0-149b-4909-a3f4-5adc4a8eea8f';
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
    $pane->uuid = '3f9c61b0-149b-4909-a3f4-5adc4a8eea8f';
    $display->content['new-3f9c61b0-149b-4909-a3f4-5adc4a8eea8f'] = $pane;
    $display->panels['main'][2] = 'new-3f9c61b0-149b-4909-a3f4-5adc4a8eea8f';
    $pane = new stdClass();
    $pane->pid = 'new-ebdeba51-b369-44ca-8b27-5e60b99177aa';
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
    $pane->uuid = 'ebdeba51-b369-44ca-8b27-5e60b99177aa';
    $display->content['new-ebdeba51-b369-44ca-8b27-5e60b99177aa'] = $pane;
    $display->panels['main'][3] = 'new-ebdeba51-b369-44ca-8b27-5e60b99177aa';
    $pane = new stdClass();
    $pane->pid = 'new-e1b94c5a-dd88-441c-b016-f743bff3f3ca';
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
    $pane->uuid = 'e1b94c5a-dd88-441c-b016-f743bff3f3ca';
    $display->content['new-e1b94c5a-dd88-441c-b016-f743bff3f3ca'] = $pane;
    $display->panels['secondary'][0] = 'new-e1b94c5a-dd88-441c-b016-f743bff3f3ca';
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
  $display->uuid = '2d50ba62-c93b-40d0-8f50-0f5d1631196d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8184bd85-847e-4d6b-ba70-a62a2648ecec';
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
    $pane->uuid = '8184bd85-847e-4d6b-ba70-a62a2648ecec';
    $display->content['new-8184bd85-847e-4d6b-ba70-a62a2648ecec'] = $pane;
    $display->panels['leader'][0] = 'new-8184bd85-847e-4d6b-ba70-a62a2648ecec';
    $pane = new stdClass();
    $pane->pid = 'new-d61b17a2-2800-411e-9287-325452c2614f';
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
    $pane->uuid = 'd61b17a2-2800-411e-9287-325452c2614f';
    $display->content['new-d61b17a2-2800-411e-9287-325452c2614f'] = $pane;
    $display->panels['main'][0] = 'new-d61b17a2-2800-411e-9287-325452c2614f';
    $pane = new stdClass();
    $pane->pid = 'new-42b180e3-f93f-491e-bbe7-15e491076561';
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
    $pane->uuid = '42b180e3-f93f-491e-bbe7-15e491076561';
    $display->content['new-42b180e3-f93f-491e-bbe7-15e491076561'] = $pane;
    $display->panels['main'][1] = 'new-42b180e3-f93f-491e-bbe7-15e491076561';
    $pane = new stdClass();
    $pane->pid = 'new-f6b2fd22-bf0c-4ab0-ba60-f8105efece04';
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
    $pane->uuid = 'f6b2fd22-bf0c-4ab0-ba60-f8105efece04';
    $display->content['new-f6b2fd22-bf0c-4ab0-ba60-f8105efece04'] = $pane;
    $display->panels['main'][2] = 'new-f6b2fd22-bf0c-4ab0-ba60-f8105efece04';
    $pane = new stdClass();
    $pane->pid = 'new-527d6296-4576-43d8-9f5f-7a7a055de836';
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
    $pane->uuid = '527d6296-4576-43d8-9f5f-7a7a055de836';
    $display->content['new-527d6296-4576-43d8-9f5f-7a7a055de836'] = $pane;
    $display->panels['main'][3] = 'new-527d6296-4576-43d8-9f5f-7a7a055de836';
    $pane = new stdClass();
    $pane->pid = 'new-be47f2e6-9775-4329-9fb5-1e5ec645b75b';
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
    $pane->uuid = 'be47f2e6-9775-4329-9fb5-1e5ec645b75b';
    $display->content['new-be47f2e6-9775-4329-9fb5-1e5ec645b75b'] = $pane;
    $display->panels['secondary'][0] = 'new-be47f2e6-9775-4329-9fb5-1e5ec645b75b';
    $pane = new stdClass();
    $pane->pid = 'new-096c4957-8f0c-400e-9ec5-129aa4c955ab';
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
    $pane->uuid = '096c4957-8f0c-400e-9ec5-129aa4c955ab';
    $display->content['new-096c4957-8f0c-400e-9ec5-129aa4c955ab'] = $pane;
    $display->panels['secondary'][1] = 'new-096c4957-8f0c-400e-9ec5-129aa4c955ab';
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
  $display->uuid = 'bc3b6fc3-c870-4457-80a6-130d1f276ff4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-32efe199-01ba-4322-aaf1-3b69f6d64834';
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
    $pane->uuid = '32efe199-01ba-4322-aaf1-3b69f6d64834';
    $display->content['new-32efe199-01ba-4322-aaf1-3b69f6d64834'] = $pane;
    $display->panels['leader'][0] = 'new-32efe199-01ba-4322-aaf1-3b69f6d64834';
    $pane = new stdClass();
    $pane->pid = 'new-f2e087ff-d9e9-4a7c-adad-abb45edd5a87';
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
    $pane->uuid = 'f2e087ff-d9e9-4a7c-adad-abb45edd5a87';
    $display->content['new-f2e087ff-d9e9-4a7c-adad-abb45edd5a87'] = $pane;
    $display->panels['leader'][1] = 'new-f2e087ff-d9e9-4a7c-adad-abb45edd5a87';
    $pane = new stdClass();
    $pane->pid = 'new-b08c554b-6a0d-4a41-af5a-c139a5afe6be';
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
    $pane->uuid = 'b08c554b-6a0d-4a41-af5a-c139a5afe6be';
    $display->content['new-b08c554b-6a0d-4a41-af5a-c139a5afe6be'] = $pane;
    $display->panels['main'][0] = 'new-b08c554b-6a0d-4a41-af5a-c139a5afe6be';
    $pane = new stdClass();
    $pane->pid = 'new-f13d3d7c-074e-43e1-9185-68d6faf88a63';
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
    $pane->uuid = 'f13d3d7c-074e-43e1-9185-68d6faf88a63';
    $display->content['new-f13d3d7c-074e-43e1-9185-68d6faf88a63'] = $pane;
    $display->panels['main'][1] = 'new-f13d3d7c-074e-43e1-9185-68d6faf88a63';
    $pane = new stdClass();
    $pane->pid = 'new-951adb16-27d7-412c-a778-d1f90f76ada1';
    $pane->panel = 'main';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
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
    $pane->uuid = '951adb16-27d7-412c-a778-d1f90f76ada1';
    $display->content['new-951adb16-27d7-412c-a778-d1f90f76ada1'] = $pane;
    $display->panels['main'][2] = 'new-951adb16-27d7-412c-a778-d1f90f76ada1';
    $pane = new stdClass();
    $pane->pid = 'new-6df79014-bafd-4955-8553-f2c22480cd46';
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
    $pane->uuid = '6df79014-bafd-4955-8553-f2c22480cd46';
    $display->content['new-6df79014-bafd-4955-8553-f2c22480cd46'] = $pane;
    $display->panels['secondary'][0] = 'new-6df79014-bafd-4955-8553-f2c22480cd46';
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
  $display->uuid = '6e6945f2-e2be-4fe1-bcc7-a607babb1518';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d1474f03-2fc3-4520-9be9-89fc77868fe7';
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
    $pane->uuid = 'd1474f03-2fc3-4520-9be9-89fc77868fe7';
    $display->content['new-d1474f03-2fc3-4520-9be9-89fc77868fe7'] = $pane;
    $display->panels['leader'][0] = 'new-d1474f03-2fc3-4520-9be9-89fc77868fe7';
    $pane = new stdClass();
    $pane->pid = 'new-772ba7dd-fca8-4642-9fb5-876101f5a80a';
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
    $pane->uuid = '772ba7dd-fca8-4642-9fb5-876101f5a80a';
    $display->content['new-772ba7dd-fca8-4642-9fb5-876101f5a80a'] = $pane;
    $display->panels['main'][0] = 'new-772ba7dd-fca8-4642-9fb5-876101f5a80a';
    $pane = new stdClass();
    $pane->pid = 'new-6e4623e5-ff7b-4589-b12a-843c891657f7';
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
    $pane->uuid = '6e4623e5-ff7b-4589-b12a-843c891657f7';
    $display->content['new-6e4623e5-ff7b-4589-b12a-843c891657f7'] = $pane;
    $display->panels['main'][1] = 'new-6e4623e5-ff7b-4589-b12a-843c891657f7';
    $pane = new stdClass();
    $pane->pid = 'new-d4af0f52-55f9-46fe-a2aa-2021492af871';
    $pane->panel = 'main';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
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
    $pane->uuid = 'd4af0f52-55f9-46fe-a2aa-2021492af871';
    $display->content['new-d4af0f52-55f9-46fe-a2aa-2021492af871'] = $pane;
    $display->panels['main'][2] = 'new-d4af0f52-55f9-46fe-a2aa-2021492af871';
    $pane = new stdClass();
    $pane->pid = 'new-201d2dbf-10ff-40bd-99d3-6e1d8be654a3';
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
    $pane->uuid = '201d2dbf-10ff-40bd-99d3-6e1d8be654a3';
    $display->content['new-201d2dbf-10ff-40bd-99d3-6e1d8be654a3'] = $pane;
    $display->panels['secondary'][0] = 'new-201d2dbf-10ff-40bd-99d3-6e1d8be654a3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_node_talk_panel_context_2'] = $handler;

  return $export;
}
