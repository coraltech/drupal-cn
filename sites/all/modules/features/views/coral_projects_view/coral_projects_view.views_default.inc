<?php
/**
 * @file
 * coral_projects_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function coral_projects_view_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'coral_projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Coral projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Coral projects';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'clearfix';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_project_documentation' => 'field_project_documentation',
    'field_project_home_page' => 'field_project_home_page',
    'field_project_repo' => 'field_project_repo',
  );
  $handler->display->display_options['row_options']['separator'] = ' | ';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<span class=\'icon\'></span>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 0;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'project_type' => 'project_type',
    'tags' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Project repo */
  $handler->display->display_options['fields']['field_project_repo']['id'] = 'field_project_repo';
  $handler->display->display_options['fields']['field_project_repo']['table'] = 'field_data_field_project_repo';
  $handler->display->display_options['fields']['field_project_repo']['field'] = 'field_project_repo';
  $handler->display->display_options['fields']['field_project_repo']['label'] = '';
  $handler->display->display_options['fields']['field_project_repo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_repo']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_project_repo']['alter']['text'] = '<a href=\'[field_project_repo-url]\'>Repo</a>';
  $handler->display->display_options['fields']['field_project_repo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_repo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_repo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_repo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_repo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_repo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_repo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_repo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_repo']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_project_repo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_repo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_repo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_repo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_repo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_repo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_repo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_repo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_repo']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_project_repo']['field_api_classes'] = 0;
  /* Field: Content: Project documentation */
  $handler->display->display_options['fields']['field_project_documentation']['id'] = 'field_project_documentation';
  $handler->display->display_options['fields']['field_project_documentation']['table'] = 'field_data_field_project_documentation';
  $handler->display->display_options['fields']['field_project_documentation']['field'] = 'field_project_documentation';
  $handler->display->display_options['fields']['field_project_documentation']['label'] = '';
  $handler->display->display_options['fields']['field_project_documentation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_documentation']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_project_documentation']['alter']['text'] = '<a href=\'[field_project_documentation-url]\'>Docs</a>';
  $handler->display->display_options['fields']['field_project_documentation']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_documentation']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_documentation']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_documentation']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_documentation']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_documentation']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_documentation']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_documentation']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_documentation']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_project_documentation']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_documentation']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_documentation']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_documentation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_documentation']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_documentation']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_documentation']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_documentation']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_documentation']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_project_documentation']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class=\'proj-links\'>[field_project_repo] | [field_project_documentation]</div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['glossary'] = 0;
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['arguments']['name']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['name']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['name']['add_table'] = 0;
  $handler->display->display_options['arguments']['name']['require_value'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );

  /* Display: Coral projects */
  $handler = $view->new_display('panel_pane', 'Coral projects', 'panel_pane_1');
  $handler->display->display_options['pane_title'] = 'Coral projects';
  $handler->display->display_options['pane_description'] = 'Coral projects';
  $handler->display->display_options['pane_category']['name'] = 'Coral';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'name' => array(
      'type' => 'user',
      'context' => 'entity:file.basename',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Taxonomy term: Name',
    ),
  );
  $export['coral_projects'] = $view;

  return $export;
}
