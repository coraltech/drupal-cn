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
  $display->uuid = '593d520c-f9db-425b-b87f-8707332832d7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9cb9ebc9-9ed9-4393-a567-32bfbdfdabb5';
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
    $pane->uuid = '9cb9ebc9-9ed9-4393-a567-32bfbdfdabb5';
    $display->content['new-9cb9ebc9-9ed9-4393-a567-32bfbdfdabb5'] = $pane;
    $display->panels['middle'][0] = 'new-9cb9ebc9-9ed9-4393-a567-32bfbdfdabb5';
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
  $display->uuid = '23405c60-c432-4697-800d-26180d92b58f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b3cfa9e2-09b6-43ca-9d74-a0efa8f4aca4';
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
    $pane->uuid = 'b3cfa9e2-09b6-43ca-9d74-a0efa8f4aca4';
    $display->content['new-b3cfa9e2-09b6-43ca-9d74-a0efa8f4aca4'] = $pane;
    $display->panels['leader'][0] = 'new-b3cfa9e2-09b6-43ca-9d74-a0efa8f4aca4';
    $pane = new stdClass();
    $pane->pid = 'new-2050a324-1eb1-4484-9d82-4e634348606a';
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
    $pane->uuid = '2050a324-1eb1-4484-9d82-4e634348606a';
    $display->content['new-2050a324-1eb1-4484-9d82-4e634348606a'] = $pane;
    $display->panels['main'][0] = 'new-2050a324-1eb1-4484-9d82-4e634348606a';
    $pane = new stdClass();
    $pane->pid = 'new-259ca92a-ac43-4968-90c2-ae3dbb10e5dc';
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
    $pane->uuid = '259ca92a-ac43-4968-90c2-ae3dbb10e5dc';
    $display->content['new-259ca92a-ac43-4968-90c2-ae3dbb10e5dc'] = $pane;
    $display->panels['main'][1] = 'new-259ca92a-ac43-4968-90c2-ae3dbb10e5dc';
    $pane = new stdClass();
    $pane->pid = 'new-be8bbd40-3960-4080-8349-3319d1a773f4';
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
    $pane->uuid = 'be8bbd40-3960-4080-8349-3319d1a773f4';
    $display->content['new-be8bbd40-3960-4080-8349-3319d1a773f4'] = $pane;
    $display->panels['secondary'][0] = 'new-be8bbd40-3960-4080-8349-3319d1a773f4';
    $pane = new stdClass();
    $pane->pid = 'new-78ae6855-bff3-4812-b826-1ad18e532603';
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
    $pane->uuid = '78ae6855-bff3-4812-b826-1ad18e532603';
    $display->content['new-78ae6855-bff3-4812-b826-1ad18e532603'] = $pane;
    $display->panels['secondary'][1] = 'new-78ae6855-bff3-4812-b826-1ad18e532603';
    $pane = new stdClass();
    $pane->pid = 'new-ff3bc4ee-10f9-4fe7-9075-27b3d9ef1902';
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
    $pane->uuid = 'ff3bc4ee-10f9-4fe7-9075-27b3d9ef1902';
    $display->content['new-ff3bc4ee-10f9-4fe7-9075-27b3d9ef1902'] = $pane;
    $display->panels['secondary'][2] = 'new-ff3bc4ee-10f9-4fe7-9075-27b3d9ef1902';
    $pane = new stdClass();
    $pane->pid = 'new-e1ee9f5b-5504-4df2-a020-c1a807a06aff';
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
    $pane->uuid = 'e1ee9f5b-5504-4df2-a020-c1a807a06aff';
    $display->content['new-e1ee9f5b-5504-4df2-a020-c1a807a06aff'] = $pane;
    $display->panels['secondary'][3] = 'new-e1ee9f5b-5504-4df2-a020-c1a807a06aff';
    $pane = new stdClass();
    $pane->pid = 'new-c5a0b3c4-1063-4d67-9396-551ccbbdfc07';
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
    $pane->uuid = 'c5a0b3c4-1063-4d67-9396-551ccbbdfc07';
    $display->content['new-c5a0b3c4-1063-4d67-9396-551ccbbdfc07'] = $pane;
    $display->panels['secondary'][4] = 'new-c5a0b3c4-1063-4d67-9396-551ccbbdfc07';
    $pane = new stdClass();
    $pane->pid = 'new-e2bed9b4-eca4-407d-b9c4-60492fb673f1';
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
    $pane->uuid = 'e2bed9b4-eca4-407d-b9c4-60492fb673f1';
    $display->content['new-e2bed9b4-eca4-407d-b9c4-60492fb673f1'] = $pane;
    $display->panels['secondary'][5] = 'new-e2bed9b4-eca4-407d-b9c4-60492fb673f1';
    $pane = new stdClass();
    $pane->pid = 'new-15a94dc3-9861-4da5-b568-4e3466c35706';
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
    $pane->uuid = '15a94dc3-9861-4da5-b568-4e3466c35706';
    $display->content['new-15a94dc3-9861-4da5-b568-4e3466c35706'] = $pane;
    $display->panels['secondary'][6] = 'new-15a94dc3-9861-4da5-b568-4e3466c35706';
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
  $display->uuid = '3c2a5eba-72c9-4401-8328-f7deed31a4ac';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2bc4cd17-259e-420e-9154-c528db2fbc50';
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
    $pane->uuid = '2bc4cd17-259e-420e-9154-c528db2fbc50';
    $display->content['new-2bc4cd17-259e-420e-9154-c528db2fbc50'] = $pane;
    $display->panels['follower'][0] = 'new-2bc4cd17-259e-420e-9154-c528db2fbc50';
    $pane = new stdClass();
    $pane->pid = 'new-c135801f-a1c6-4757-80f4-a8306f30dee5';
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
    $pane->uuid = 'c135801f-a1c6-4757-80f4-a8306f30dee5';
    $display->content['new-c135801f-a1c6-4757-80f4-a8306f30dee5'] = $pane;
    $display->panels['follower'][1] = 'new-c135801f-a1c6-4757-80f4-a8306f30dee5';
    $pane = new stdClass();
    $pane->pid = 'new-f29dd96c-ebf8-443d-9793-333cdeac2e39';
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
    $pane->uuid = 'f29dd96c-ebf8-443d-9793-333cdeac2e39';
    $display->content['new-f29dd96c-ebf8-443d-9793-333cdeac2e39'] = $pane;
    $display->panels['follower'][2] = 'new-f29dd96c-ebf8-443d-9793-333cdeac2e39';
    $pane = new stdClass();
    $pane->pid = 'new-55d24dbb-8508-4cea-b1b2-cfe830e212f5';
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
    $pane->uuid = '55d24dbb-8508-4cea-b1b2-cfe830e212f5';
    $display->content['new-55d24dbb-8508-4cea-b1b2-cfe830e212f5'] = $pane;
    $display->panels['follower'][3] = 'new-55d24dbb-8508-4cea-b1b2-cfe830e212f5';
    $pane = new stdClass();
    $pane->pid = 'new-5fe48bf5-0789-4c70-917f-b11f2402e851';
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
    $pane->uuid = '5fe48bf5-0789-4c70-917f-b11f2402e851';
    $display->content['new-5fe48bf5-0789-4c70-917f-b11f2402e851'] = $pane;
    $display->panels['follower'][4] = 'new-5fe48bf5-0789-4c70-917f-b11f2402e851';
    $pane = new stdClass();
    $pane->pid = 'new-59d44c9d-f1f3-4683-9dbc-4d4b754d1f3c';
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
    $pane->uuid = '59d44c9d-f1f3-4683-9dbc-4d4b754d1f3c';
    $display->content['new-59d44c9d-f1f3-4683-9dbc-4d4b754d1f3c'] = $pane;
    $display->panels['main'][0] = 'new-59d44c9d-f1f3-4683-9dbc-4d4b754d1f3c';
    $pane = new stdClass();
    $pane->pid = 'new-f0e54560-7bf9-4e3b-b560-5934b3779898';
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
      'css_class' => 'body-full hide',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f0e54560-7bf9-4e3b-b560-5934b3779898';
    $display->content['new-f0e54560-7bf9-4e3b-b560-5934b3779898'] = $pane;
    $display->panels['main'][1] = 'new-f0e54560-7bf9-4e3b-b560-5934b3779898';
    $pane = new stdClass();
    $pane->pid = 'new-6518ee32-2541-440b-8c0c-1aba15f0ca3f';
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
    $pane->uuid = '6518ee32-2541-440b-8c0c-1aba15f0ca3f';
    $display->content['new-6518ee32-2541-440b-8c0c-1aba15f0ca3f'] = $pane;
    $display->panels['main'][2] = 'new-6518ee32-2541-440b-8c0c-1aba15f0ca3f';
    $pane = new stdClass();
    $pane->pid = 'new-feccb004-9e55-4906-9236-de55b6a145c5';
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
    $pane->uuid = 'feccb004-9e55-4906-9236-de55b6a145c5';
    $display->content['new-feccb004-9e55-4906-9236-de55b6a145c5'] = $pane;
    $display->panels['main'][3] = 'new-feccb004-9e55-4906-9236-de55b6a145c5';
    $pane = new stdClass();
    $pane->pid = 'new-432cda85-0219-4b07-93fb-55b45800be62';
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
    $pane->uuid = '432cda85-0219-4b07-93fb-55b45800be62';
    $display->content['new-432cda85-0219-4b07-93fb-55b45800be62'] = $pane;
    $display->panels['main'][4] = 'new-432cda85-0219-4b07-93fb-55b45800be62';
    $pane = new stdClass();
    $pane->pid = 'new-2a962248-a94d-4782-aca7-9ba711578281';
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
    $pane->uuid = '2a962248-a94d-4782-aca7-9ba711578281';
    $display->content['new-2a962248-a94d-4782-aca7-9ba711578281'] = $pane;
    $display->panels['main'][5] = 'new-2a962248-a94d-4782-aca7-9ba711578281';
    $pane = new stdClass();
    $pane->pid = 'new-12c89904-052e-4e74-87ab-4e9fab8eef35';
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
    $pane->uuid = '12c89904-052e-4e74-87ab-4e9fab8eef35';
    $display->content['new-12c89904-052e-4e74-87ab-4e9fab8eef35'] = $pane;
    $display->panels['main'][6] = 'new-12c89904-052e-4e74-87ab-4e9fab8eef35';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:question:default:teaser'] = $panelizer;

  return $export;
}
