<?php
/**
 * @file
 * answer_node_type.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function answer_node_type_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:answer:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'answer';
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
  $display->uuid = 'e6957202-d051-49fe-afad-8d48f9f9d6f2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d740e712-731b-461d-9fb2-f9ac8f7e31a3';
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
    $pane->uuid = 'd740e712-731b-461d-9fb2-f9ac8f7e31a3';
    $display->content['new-d740e712-731b-461d-9fb2-f9ac8f7e31a3'] = $pane;
    $display->panels['leader'][0] = 'new-d740e712-731b-461d-9fb2-f9ac8f7e31a3';
    $pane = new stdClass();
    $pane->pid = 'new-2303dc95-5691-4c5e-9678-8efb05a2a8d3';
    $pane->panel = 'main';
    $pane->type = 'coral_parent_content';
    $pane->subtype = 'coral_parent_content';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2303dc95-5691-4c5e-9678-8efb05a2a8d3';
    $display->content['new-2303dc95-5691-4c5e-9678-8efb05a2a8d3'] = $pane;
    $display->panels['main'][0] = 'new-2303dc95-5691-4c5e-9678-8efb05a2a8d3';
    $pane = new stdClass();
    $pane->pid = 'new-b647c64c-2dfe-4912-889e-e6a2dc02d5bd';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b647c64c-2dfe-4912-889e-e6a2dc02d5bd';
    $display->content['new-b647c64c-2dfe-4912-889e-e6a2dc02d5bd'] = $pane;
    $display->panels['main'][1] = 'new-b647c64c-2dfe-4912-889e-e6a2dc02d5bd';
    $pane = new stdClass();
    $pane->pid = 'new-ba9740c3-2f01-455f-95d9-a565b0b86d15';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ba9740c3-2f01-455f-95d9-a565b0b86d15';
    $display->content['new-ba9740c3-2f01-455f-95d9-a565b0b86d15'] = $pane;
    $display->panels['main'][2] = 'new-ba9740c3-2f01-455f-95d9-a565b0b86d15';
    $pane = new stdClass();
    $pane->pid = 'new-00deccc7-8df5-4f72-874c-03c6b11cd387';
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
    $pane->uuid = '00deccc7-8df5-4f72-874c-03c6b11cd387';
    $display->content['new-00deccc7-8df5-4f72-874c-03c6b11cd387'] = $pane;
    $display->panels['secondary'][0] = 'new-00deccc7-8df5-4f72-874c-03c6b11cd387';
    $pane = new stdClass();
    $pane->pid = 'new-b916cdb1-a74b-42b6-bbec-75118feea8b6';
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
    $pane->uuid = 'b916cdb1-a74b-42b6-bbec-75118feea8b6';
    $display->content['new-b916cdb1-a74b-42b6-bbec-75118feea8b6'] = $pane;
    $display->panels['secondary'][1] = 'new-b916cdb1-a74b-42b6-bbec-75118feea8b6';
    $pane = new stdClass();
    $pane->pid = 'new-f904af10-d8c6-4abc-b977-730a0fc329c5';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f904af10-d8c6-4abc-b977-730a0fc329c5';
    $display->content['new-f904af10-d8c6-4abc-b977-730a0fc329c5'] = $pane;
    $display->panels['secondary'][2] = 'new-f904af10-d8c6-4abc-b977-730a0fc329c5';
    $pane = new stdClass();
    $pane->pid = 'new-653ef6fe-ed39-446f-a781-15349a5f190c';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '653ef6fe-ed39-446f-a781-15349a5f190c';
    $display->content['new-653ef6fe-ed39-446f-a781-15349a5f190c'] = $pane;
    $display->panels['secondary'][3] = 'new-653ef6fe-ed39-446f-a781-15349a5f190c';
    $pane = new stdClass();
    $pane->pid = 'new-35dcf327-bed6-4612-b6d1-e7720b16654f';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '35dcf327-bed6-4612-b6d1-e7720b16654f';
    $display->content['new-35dcf327-bed6-4612-b6d1-e7720b16654f'] = $pane;
    $display->panels['secondary'][4] = 'new-35dcf327-bed6-4612-b6d1-e7720b16654f';
    $pane = new stdClass();
    $pane->pid = 'new-e312e893-6c1d-443c-b64b-b1cce09cb43a';
    $pane->panel = 'secondary';
    $pane->type = 'views_panes';
    $pane->subtype = 'related_qa-small_list';
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
    $pane->uuid = 'e312e893-6c1d-443c-b64b-b1cce09cb43a';
    $display->content['new-e312e893-6c1d-443c-b64b-b1cce09cb43a'] = $pane;
    $display->panels['secondary'][5] = 'new-e312e893-6c1d-443c-b64b-b1cce09cb43a';
    $pane = new stdClass();
    $pane->pid = 'new-5b80722b-62eb-447b-a763-836d842675bb';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '5b80722b-62eb-447b-a763-836d842675bb';
    $display->content['new-5b80722b-62eb-447b-a763-836d842675bb'] = $pane;
    $display->panels['secondary'][6] = 'new-5b80722b-62eb-447b-a763-836d842675bb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:answer:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:answer:default:teaser';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'answer';
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
      'leader' => NULL,
      'main' => NULL,
      'secondary' => NULL,
      'follower' => NULL,
      'sub_footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '606a783e-2db4-4968-95d8-6e9a0bf55327';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-138c93ac-1da1-4673-b8d8-dd5f5b8bd602';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '138c93ac-1da1-4673-b8d8-dd5f5b8bd602';
    $display->content['new-138c93ac-1da1-4673-b8d8-dd5f5b8bd602'] = $pane;
    $display->panels['follower'][0] = 'new-138c93ac-1da1-4673-b8d8-dd5f5b8bd602';
    $pane = new stdClass();
    $pane->pid = 'new-8030c907-fee2-42a6-9450-ead48832075e';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8030c907-fee2-42a6-9450-ead48832075e';
    $display->content['new-8030c907-fee2-42a6-9450-ead48832075e'] = $pane;
    $display->panels['follower'][1] = 'new-8030c907-fee2-42a6-9450-ead48832075e';
    $pane = new stdClass();
    $pane->pid = 'new-bea6e75a-a1b2-4f04-8139-5f4ced303b27';
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
    $pane->uuid = 'bea6e75a-a1b2-4f04-8139-5f4ced303b27';
    $display->content['new-bea6e75a-a1b2-4f04-8139-5f4ced303b27'] = $pane;
    $display->panels['main'][0] = 'new-bea6e75a-a1b2-4f04-8139-5f4ced303b27';
    $pane = new stdClass();
    $pane->pid = 'new-4e567338-59ff-43d2-8873-efad36b3e41f';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
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
      'css_class' => 'body-full hide',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4e567338-59ff-43d2-8873-efad36b3e41f';
    $display->content['new-4e567338-59ff-43d2-8873-efad36b3e41f'] = $pane;
    $display->panels['main'][1] = 'new-4e567338-59ff-43d2-8873-efad36b3e41f';
    $pane = new stdClass();
    $pane->pid = 'new-24d6b196-d153-4ac3-929b-3429b6acd921';
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
    $pane->uuid = '24d6b196-d153-4ac3-929b-3429b6acd921';
    $display->content['new-24d6b196-d153-4ac3-929b-3429b6acd921'] = $pane;
    $display->panels['main'][2] = 'new-24d6b196-d153-4ac3-929b-3429b6acd921';
    $pane = new stdClass();
    $pane->pid = 'new-698dead3-4ba5-49a9-a1bb-f1280d1745db';
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
      'css_class' => 'right',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '698dead3-4ba5-49a9-a1bb-f1280d1745db';
    $display->content['new-698dead3-4ba5-49a9-a1bb-f1280d1745db'] = $pane;
    $display->panels['main'][3] = 'new-698dead3-4ba5-49a9-a1bb-f1280d1745db';
    $pane = new stdClass();
    $pane->pid = 'new-f75313a0-bcbc-462e-83db-6de161737ff0';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'f75313a0-bcbc-462e-83db-6de161737ff0';
    $display->content['new-f75313a0-bcbc-462e-83db-6de161737ff0'] = $pane;
    $display->panels['main'][4] = 'new-f75313a0-bcbc-462e-83db-6de161737ff0';
    $pane = new stdClass();
    $pane->pid = 'new-0b88a0e0-9137-48af-b47e-9eb2b1b6876f';
    $pane->panel = 'main';
    $pane->type = 'panels_mini';
    $pane->subtype = 'answer_links_container';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '0b88a0e0-9137-48af-b47e-9eb2b1b6876f';
    $display->content['new-0b88a0e0-9137-48af-b47e-9eb2b1b6876f'] = $pane;
    $display->panels['main'][5] = 'new-0b88a0e0-9137-48af-b47e-9eb2b1b6876f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:answer:default:teaser'] = $panelizer;

  return $export;
}
