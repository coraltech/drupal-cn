<?php
/**
 * @file
 * comment_content_type.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function comment_content_type_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:comment:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'comment';
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
  $display->uuid = '9757f3eb-f7da-4344-9f46-ed17b1ebd058';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-479f94fd-0394-48ac-b3a6-6cac38671af6';
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
    $pane->uuid = '479f94fd-0394-48ac-b3a6-6cac38671af6';
    $display->content['new-479f94fd-0394-48ac-b3a6-6cac38671af6'] = $pane;
    $display->panels['leader'][0] = 'new-479f94fd-0394-48ac-b3a6-6cac38671af6';
    $pane = new stdClass();
    $pane->pid = 'new-c42f38fc-d7f3-43ef-8070-31879734e940';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c42f38fc-d7f3-43ef-8070-31879734e940';
    $display->content['new-c42f38fc-d7f3-43ef-8070-31879734e940'] = $pane;
    $display->panels['main'][0] = 'new-c42f38fc-d7f3-43ef-8070-31879734e940';
    $pane = new stdClass();
    $pane->pid = 'new-94bce751-ebe7-49d2-9760-46101cdf01c6';
    $pane->panel = 'main';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'teaser',
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
      'css_class' => 'pane-coral-comments-target loose clearfix',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '94bce751-ebe7-49d2-9760-46101cdf01c6';
    $display->content['new-94bce751-ebe7-49d2-9760-46101cdf01c6'] = $pane;
    $display->panels['main'][1] = 'new-94bce751-ebe7-49d2-9760-46101cdf01c6';
    $pane = new stdClass();
    $pane->pid = 'new-1e301196-c06b-436d-9c16-b42c2adc9cd7';
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
    $pane->uuid = '1e301196-c06b-436d-9c16-b42c2adc9cd7';
    $display->content['new-1e301196-c06b-436d-9c16-b42c2adc9cd7'] = $pane;
    $display->panels['secondary'][0] = 'new-1e301196-c06b-436d-9c16-b42c2adc9cd7';
    $pane = new stdClass();
    $pane->pid = 'new-64b082ed-92d8-4a68-b9c7-0a8f7005b609';
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
    $pane->uuid = '64b082ed-92d8-4a68-b9c7-0a8f7005b609';
    $display->content['new-64b082ed-92d8-4a68-b9c7-0a8f7005b609'] = $pane;
    $display->panels['secondary'][1] = 'new-64b082ed-92d8-4a68-b9c7-0a8f7005b609';
    $pane = new stdClass();
    $pane->pid = 'new-44640f31-d7ce-4167-81f9-48c8bd43c602';
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
    $pane->uuid = '44640f31-d7ce-4167-81f9-48c8bd43c602';
    $display->content['new-44640f31-d7ce-4167-81f9-48c8bd43c602'] = $pane;
    $display->panels['secondary'][2] = 'new-44640f31-d7ce-4167-81f9-48c8bd43c602';
    $pane = new stdClass();
    $pane->pid = 'new-b4e9402f-1d06-403d-a94c-2f35827f4077';
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
    $pane->uuid = 'b4e9402f-1d06-403d-a94c-2f35827f4077';
    $display->content['new-b4e9402f-1d06-403d-a94c-2f35827f4077'] = $pane;
    $display->panels['secondary'][3] = 'new-b4e9402f-1d06-403d-a94c-2f35827f4077';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:comment:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:comment:default:teaser';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'comment';
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
      'middle' => NULL,
      'leader' => NULL,
      'main' => NULL,
      'secondary' => NULL,
      'follower' => NULL,
      'sub_footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'eb6b0f27-9aca-4465-9a8b-2b3294772e2f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d5452c75-f9ac-4468-b98b-8950004b8802';
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
    $pane->uuid = 'd5452c75-f9ac-4468-b98b-8950004b8802';
    $display->content['new-d5452c75-f9ac-4468-b98b-8950004b8802'] = $pane;
    $display->panels['follower'][0] = 'new-d5452c75-f9ac-4468-b98b-8950004b8802';
    $pane = new stdClass();
    $pane->pid = 'new-c7d5e38d-31d2-4529-9a39-a82b0beb0cec';
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
    $pane->uuid = 'c7d5e38d-31d2-4529-9a39-a82b0beb0cec';
    $display->content['new-c7d5e38d-31d2-4529-9a39-a82b0beb0cec'] = $pane;
    $display->panels['follower'][1] = 'new-c7d5e38d-31d2-4529-9a39-a82b0beb0cec';
    $pane = new stdClass();
    $pane->pid = 'new-ca6d876f-9995-494e-9947-36df3ada38a4';
    $pane->panel = 'leader';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'markup' => 'h2',
      'id' => '',
      'class' => 'hide',
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
      'css_class' => 'comment-node-pane-title left',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ca6d876f-9995-494e-9947-36df3ada38a4';
    $display->content['new-ca6d876f-9995-494e-9947-36df3ada38a4'] = $pane;
    $display->panels['leader'][0] = 'new-ca6d876f-9995-494e-9947-36df3ada38a4';
    $pane = new stdClass();
    $pane->pid = 'new-fe30a703-266f-428e-a7c8-47700f9996c2';
    $pane->panel = 'leader';
    $pane->type = 'coral_node_stats';
    $pane->subtype = 'coral_node_stats';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => FALSE,
      'display_stats' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
      ),
      'display_style' => '3',
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
      'css_class' => 'right',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'fe30a703-266f-428e-a7c8-47700f9996c2';
    $display->content['new-fe30a703-266f-428e-a7c8-47700f9996c2'] = $pane;
    $display->panels['leader'][1] = 'new-fe30a703-266f-428e-a7c8-47700f9996c2';
    $pane = new stdClass();
    $pane->pid = 'new-1d6d2a2c-4650-4812-8555-0c46f3cec1e9';
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
    $pane->uuid = '1d6d2a2c-4650-4812-8555-0c46f3cec1e9';
    $display->content['new-1d6d2a2c-4650-4812-8555-0c46f3cec1e9'] = $pane;
    $display->panels['main'][0] = 'new-1d6d2a2c-4650-4812-8555-0c46f3cec1e9';
    $pane = new stdClass();
    $pane->pid = 'new-4bdef299-ca1b-4a1b-bbee-e56ede2ff8e6';
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
      'css_class' => 'body-full',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4bdef299-ca1b-4a1b-bbee-e56ede2ff8e6';
    $display->content['new-4bdef299-ca1b-4a1b-bbee-e56ede2ff8e6'] = $pane;
    $display->panels['main'][1] = 'new-4bdef299-ca1b-4a1b-bbee-e56ede2ff8e6';
    $pane = new stdClass();
    $pane->pid = 'new-e35ff737-ec9e-4fc6-964e-9e026495c3c9';
    $pane->panel = 'main';
    $pane->type = 'coral_flag_abuse_node';
    $pane->subtype = 'coral_flag_abuse_node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
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
    $pane->uuid = 'e35ff737-ec9e-4fc6-964e-9e026495c3c9';
    $display->content['new-e35ff737-ec9e-4fc6-964e-9e026495c3c9'] = $pane;
    $display->panels['main'][2] = 'new-e35ff737-ec9e-4fc6-964e-9e026495c3c9';
    $pane = new stdClass();
    $pane->pid = 'new-046598f5-243f-4a22-9529-6254409ec761';
    $pane->panel = 'main';
    $pane->type = 'coral_add_comment';
    $pane->subtype = 'coral_add_comment';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
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
    $pane->uuid = '046598f5-243f-4a22-9529-6254409ec761';
    $display->content['new-046598f5-243f-4a22-9529-6254409ec761'] = $pane;
    $display->panels['main'][3] = 'new-046598f5-243f-4a22-9529-6254409ec761';
    $pane = new stdClass();
    $pane->pid = 'new-0a2b9c79-2a77-4255-888e-f0cd3e8bd60d';
    $pane->panel = 'main';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
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
      'css_id' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '0a2b9c79-2a77-4255-888e-f0cd3e8bd60d';
    $display->content['new-0a2b9c79-2a77-4255-888e-f0cd3e8bd60d'] = $pane;
    $display->panels['main'][4] = 'new-0a2b9c79-2a77-4255-888e-f0cd3e8bd60d';
    $pane = new stdClass();
    $pane->pid = 'new-eca71cdf-f2b3-473f-90d0-f7e6d5d533c9';
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
      'display_style' => '3',
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'eca71cdf-f2b3-473f-90d0-f7e6d5d533c9';
    $display->content['new-eca71cdf-f2b3-473f-90d0-f7e6d5d533c9'] = $pane;
    $display->panels['main'][5] = 'new-eca71cdf-f2b3-473f-90d0-f7e6d5d533c9';
    $pane = new stdClass();
    $pane->pid = 'new-df22c438-472b-4595-ad5e-d6b9fc56f5be';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_tags';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => '10',
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'df22c438-472b-4595-ad5e-d6b9fc56f5be';
    $display->content['new-df22c438-472b-4595-ad5e-d6b9fc56f5be'] = $pane;
    $display->panels['main'][6] = 'new-df22c438-472b-4595-ad5e-d6b9fc56f5be';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:comment:default:teaser'] = $panelizer;

  return $export;
}
