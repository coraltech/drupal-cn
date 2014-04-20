<?php
/**
 * @file
 * question_node_type.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function question_node_type_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:question:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'question';
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'leader' => NULL,
      'main' => NULL,
      'secondary' => NULL,
      'follower' => NULL,
      'sub_footer' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '669522ee-789a-406e-86bf-efa960c7866a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8e696df5-2c84-403f-b64c-25e3b20c73d1';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'questions-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'nid' => '%node:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8e696df5-2c84-403f-b64c-25e3b20c73d1';
    $display->content['new-8e696df5-2c84-403f-b64c-25e3b20c73d1'] = $pane;
    $display->panels['middle'][0] = 'new-8e696df5-2c84-403f-b64c-25e3b20c73d1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:question:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:question:default:full_node';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'question';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'full_node';
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
  $display->title = '';
  $display->uuid = 'd10764ed-9f4f-446f-bedf-e9209f6ec613';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-137802f3-8a29-4b03-b930-032deeaa66f4';
    $pane->panel = 'leader';
    $pane->type = 'coral_community_tabs';
    $pane->subtype = 'coral_community_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'active_tab' => '1',
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
    $pane->uuid = '137802f3-8a29-4b03-b930-032deeaa66f4';
    $display->content['new-137802f3-8a29-4b03-b930-032deeaa66f4'] = $pane;
    $display->panels['leader'][0] = 'new-137802f3-8a29-4b03-b930-032deeaa66f4';
    $pane = new stdClass();
    $pane->pid = 'new-1135bb82-5905-4d90-857d-7a977b5e5ed7';
    $pane->panel = 'main';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'teaser',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1135bb82-5905-4d90-857d-7a977b5e5ed7';
    $display->content['new-1135bb82-5905-4d90-857d-7a977b5e5ed7'] = $pane;
    $display->panels['main'][0] = 'new-1135bb82-5905-4d90-857d-7a977b5e5ed7';
    $pane = new stdClass();
    $pane->pid = 'new-8a24a82d-be06-4ee4-a847-e97667537197';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8a24a82d-be06-4ee4-a847-e97667537197';
    $display->content['new-8a24a82d-be06-4ee4-a847-e97667537197'] = $pane;
    $display->panels['main'][1] = 'new-8a24a82d-be06-4ee4-a847-e97667537197';
    $pane = new stdClass();
    $pane->pid = 'new-5d6f6010-58b2-411b-895b-aaba7320bc6d';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5d6f6010-58b2-411b-895b-aaba7320bc6d';
    $display->content['new-5d6f6010-58b2-411b-895b-aaba7320bc6d'] = $pane;
    $display->panels['secondary'][0] = 'new-5d6f6010-58b2-411b-895b-aaba7320bc6d';
    $pane = new stdClass();
    $pane->pid = 'new-54c88bfb-7182-4482-8333-f4cb36ccada6';
    $pane->panel = 'secondary';
    $pane->type = 'views_panes';
    $pane->subtype = 'tags_popular-popular_question_tags';
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
    $pane->uuid = '54c88bfb-7182-4482-8333-f4cb36ccada6';
    $display->content['new-54c88bfb-7182-4482-8333-f4cb36ccada6'] = $pane;
    $display->panels['secondary'][1] = 'new-54c88bfb-7182-4482-8333-f4cb36ccada6';
    $pane = new stdClass();
    $pane->pid = 'new-57570fff-7300-4b26-805a-b0d0cb09f588';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '57570fff-7300-4b26-805a-b0d0cb09f588';
    $display->content['new-57570fff-7300-4b26-805a-b0d0cb09f588'] = $pane;
    $display->panels['secondary'][2] = 'new-57570fff-7300-4b26-805a-b0d0cb09f588';
    $pane = new stdClass();
    $pane->pid = 'new-8de82871-d4b3-48fc-baac-c6f4b0d2d2ff';
    $pane->panel = 'secondary';
    $pane->type = 'coral_featured_users';
    $pane->subtype = 'coral_featured_users';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'users_count' => '36',
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
    $pane->uuid = '8de82871-d4b3-48fc-baac-c6f4b0d2d2ff';
    $display->content['new-8de82871-d4b3-48fc-baac-c6f4b0d2d2ff'] = $pane;
    $display->panels['secondary'][3] = 'new-8de82871-d4b3-48fc-baac-c6f4b0d2d2ff';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:question:default:full_node'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:question:default:teaser';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'question';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'teaser';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'mosaic_node_1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'leader' => NULL,
      'main' => NULL,
      'secondary' => NULL,
      'follower' => NULL,
      'sub_footer' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'bc598189-fa48-4504-a4ff-d9f0604262e7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4913eba6-1a38-4944-b42c-d850d7a70110';
    $pane->panel = 'follower';
    $pane->type = 'coral_answer_form';
    $pane->subtype = 'coral_answer_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
      ),
      'override_title' => 0,
      'override_title_text' => 'Testing',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4913eba6-1a38-4944-b42c-d850d7a70110';
    $display->content['new-4913eba6-1a38-4944-b42c-d850d7a70110'] = $pane;
    $display->panels['follower'][0] = 'new-4913eba6-1a38-4944-b42c-d850d7a70110';
    $pane = new stdClass();
    $pane->pid = 'new-4356f542-cc51-483f-9f22-6fab37028c2e';
    $pane->panel = 'follower';
    $pane->type = 'coral_best_answer_target';
    $pane->subtype = 'coral_best_answer_target';
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
    $pane->uuid = '4356f542-cc51-483f-9f22-6fab37028c2e';
    $display->content['new-4356f542-cc51-483f-9f22-6fab37028c2e'] = $pane;
    $display->panels['follower'][1] = 'new-4356f542-cc51-483f-9f22-6fab37028c2e';
    $pane = new stdClass();
    $pane->pid = 'new-d80ba59a-0467-4a66-9e0e-7d5a3c9598a7';
    $pane->panel = 'follower';
    $pane->type = 'coral_answers_target';
    $pane->subtype = 'coral_answers_target';
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
    $pane->uuid = 'd80ba59a-0467-4a66-9e0e-7d5a3c9598a7';
    $display->content['new-d80ba59a-0467-4a66-9e0e-7d5a3c9598a7'] = $pane;
    $display->panels['follower'][2] = 'new-d80ba59a-0467-4a66-9e0e-7d5a3c9598a7';
    $pane = new stdClass();
    $pane->pid = 'new-2dc7f6c8-3322-4033-8214-54c42b4964d2';
    $pane->panel = 'follower';
    $pane->type = 'coral_comment_form';
    $pane->subtype = 'coral_comment_form';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '2dc7f6c8-3322-4033-8214-54c42b4964d2';
    $display->content['new-2dc7f6c8-3322-4033-8214-54c42b4964d2'] = $pane;
    $display->panels['follower'][3] = 'new-2dc7f6c8-3322-4033-8214-54c42b4964d2';
    $pane = new stdClass();
    $pane->pid = 'new-5c82dbec-422f-431a-a465-9ab0eae3559a';
    $pane->panel = 'follower';
    $pane->type = 'coral_comments_target';
    $pane->subtype = 'coral_comments_target';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '5c82dbec-422f-431a-a465-9ab0eae3559a';
    $display->content['new-5c82dbec-422f-431a-a465-9ab0eae3559a'] = $pane;
    $display->panels['follower'][4] = 'new-5c82dbec-422f-431a-a465-9ab0eae3559a';
    $pane = new stdClass();
    $pane->pid = 'new-1b69099a-061d-4fbc-b441-a29d11b9f213';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_summary_or_trimmed',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'trim_length' => '600',
      ),
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
      'css_class' => 'body-trimmed',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1b69099a-061d-4fbc-b441-a29d11b9f213';
    $display->content['new-1b69099a-061d-4fbc-b441-a29d11b9f213'] = $pane;
    $display->panels['main'][0] = 'new-1b69099a-061d-4fbc-b441-a29d11b9f213';
    $pane = new stdClass();
    $pane->pid = 'new-20dbccce-163d-4acb-867b-25a55a12308e';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'trim_length' => 600,
      ),
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
      'css_class' => 'body-full',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '20dbccce-163d-4acb-867b-25a55a12308e';
    $display->content['new-20dbccce-163d-4acb-867b-25a55a12308e'] = $pane;
    $display->panels['main'][1] = 'new-20dbccce-163d-4acb-867b-25a55a12308e';
    $pane = new stdClass();
    $pane->pid = 'new-a35bd710-a07e-44ff-b663-2cc39b5986f0';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:file';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'file_table',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'a35bd710-a07e-44ff-b663-2cc39b5986f0';
    $display->content['new-a35bd710-a07e-44ff-b663-2cc39b5986f0'] = $pane;
    $display->panels['main'][2] = 'new-a35bd710-a07e-44ff-b663-2cc39b5986f0';
    $pane = new stdClass();
    $pane->pid = 'new-05eda440-7066-4f93-b667-4a34fc0606a9';
    $pane->panel = 'main';
    $pane->type = 'coral_node_stats';
    $pane->subtype = 'coral_node_stats';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => FALSE,
      'context' => array(
        0 => 'panelizer',
      ),
      'override_title' => 1,
      'override_title_text' => '',
      'display_stats' => array(
        1 => '1',
        2 => '2',
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
      ),
      'display_style' => '1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'right grid-12-last',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '05eda440-7066-4f93-b667-4a34fc0606a9';
    $display->content['new-05eda440-7066-4f93-b667-4a34fc0606a9'] = $pane;
    $display->panels['main'][3] = 'new-05eda440-7066-4f93-b667-4a34fc0606a9';
    $pane = new stdClass();
    $pane->pid = 'new-c7775791-2551-4b21-bd2c-cae9726bb979';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grid-12',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'c7775791-2551-4b21-bd2c-cae9726bb979';
    $display->content['new-c7775791-2551-4b21-bd2c-cae9726bb979'] = $pane;
    $display->panels['main'][4] = 'new-c7775791-2551-4b21-bd2c-cae9726bb979';
    $pane = new stdClass();
    $pane->pid = 'new-79ecefa4-64cd-4345-bb7b-0721f15bda7a';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Clearing div',
      'title' => '',
      'body' => '<div class="clear"></div>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '79ecefa4-64cd-4345-bb7b-0721f15bda7a';
    $display->content['new-79ecefa4-64cd-4345-bb7b-0721f15bda7a'] = $pane;
    $display->panels['main'][5] = 'new-79ecefa4-64cd-4345-bb7b-0721f15bda7a';
    $pane = new stdClass();
    $pane->pid = 'new-ead1f9c8-276c-470b-8f8c-710a4a09902c';
    $pane->panel = 'main';
    $pane->type = 'panels_mini';
    $pane->subtype = 'question_links_container';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'ead1f9c8-276c-470b-8f8c-710a4a09902c';
    $display->content['new-ead1f9c8-276c-470b-8f8c-710a4a09902c'] = $pane;
    $display->panels['main'][6] = 'new-ead1f9c8-276c-470b-8f8c-710a4a09902c';
    $pane = new stdClass();
    $pane->pid = 'new-435ec224-574b-480b-9e34-01973c86407d';
    $pane->panel = 'main';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'teaser',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '435ec224-574b-480b-9e34-01973c86407d';
    $display->content['new-435ec224-574b-480b-9e34-01973c86407d'] = $pane;
    $display->panels['main'][7] = 'new-435ec224-574b-480b-9e34-01973c86407d';
    $pane = new stdClass();
    $pane->pid = 'new-9d36916d-4115-4767-8c96-959e1fbf7ab4';
    $pane->panel = 'main';
    $pane->type = 'coral_add_answer';
    $pane->subtype = 'coral_add_answer';
    $pane->shown = FALSE;
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
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '9d36916d-4115-4767-8c96-959e1fbf7ab4';
    $display->content['new-9d36916d-4115-4767-8c96-959e1fbf7ab4'] = $pane;
    $display->panels['main'][8] = 'new-9d36916d-4115-4767-8c96-959e1fbf7ab4';
    $pane = new stdClass();
    $pane->pid = 'new-36559940-a81b-4f0c-8b9b-86d033619038';
    $pane->panel = 'main';
    $pane->type = 'coral_best_answer';
    $pane->subtype = 'coral_best_answer';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = '36559940-a81b-4f0c-8b9b-86d033619038';
    $display->content['new-36559940-a81b-4f0c-8b9b-86d033619038'] = $pane;
    $display->panels['main'][9] = 'new-36559940-a81b-4f0c-8b9b-86d033619038';
    $pane = new stdClass();
    $pane->pid = 'new-7ce7a6cb-3ab5-47d2-9a0a-86c3b48aefc1';
    $pane->panel = 'main';
    $pane->type = 'coral_add_comment';
    $pane->subtype = 'coral_add_comment';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $pane->uuid = '7ce7a6cb-3ab5-47d2-9a0a-86c3b48aefc1';
    $display->content['new-7ce7a6cb-3ab5-47d2-9a0a-86c3b48aefc1'] = $pane;
    $display->panels['main'][10] = 'new-7ce7a6cb-3ab5-47d2-9a0a-86c3b48aefc1';
    $pane = new stdClass();
    $pane->pid = 'new-2fffd1d2-6890-4aa9-95fb-350975e21673';
    $pane->panel = 'main';
    $pane->type = 'coral_flag_abuse_node';
    $pane->subtype = 'coral_flag_abuse_node';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 11;
    $pane->locks = array();
    $pane->uuid = '2fffd1d2-6890-4aa9-95fb-350975e21673';
    $display->content['new-2fffd1d2-6890-4aa9-95fb-350975e21673'] = $pane;
    $display->panels['main'][11] = 'new-2fffd1d2-6890-4aa9-95fb-350975e21673';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:question:default:teaser'] = $panelizer;

  return $export;
}
