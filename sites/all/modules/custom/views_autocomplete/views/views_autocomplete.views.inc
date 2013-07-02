<?php

/**
 * Implements hook_views_plugins().
 */
function views_autocomplete_views_plugins() {

  $module_path = drupal_get_path('module', 'views_autocomplete');
  $views_path  = drupal_get_path('module', 'views');

  $plugins = array(
    'module'  => 'views_autocomplete',
    'display' => array(
      'views_autocomplete' => array(
        'title'                => t('Autocomplete'),
        'admin'                => t('Autocomplete'),
        'help'                 => 'Selects referenceable entities for a entity reference field',
        'handler'              => 'views_autocomplete_plugin_display',
        'path'                 => "$module_path/views",
        'uses hook menu'       => FALSE,
        'use ajax'             => FALSE,
        'use pager'            => FALSE,
        'accept attachments'   => FALSE,
        'autocomplete display' => TRUE,
      ),
    ),
    'style' => array(
      'views_autocomplete_style' => array(
        'title'           => t('Autocomplete list'),
        'help'            => 'Returns results as a PHP array of names + rendered rows.',
        'handler'         => 'views_autocomplete_plugin_style',
        'path'            => "$module_path/views",
        'theme path'      => "$views_path/theme",
        'theme'           => 'views_view_unformatted',
        'register theme'  => FALSE,
        'uses row plugin' => TRUE,
        'uses grouping'   => TRUE,
        'uses options'    => TRUE,
        'type'            => 'autocomplete',
        'even empty'      => TRUE,
      ),
    ),
    'row' => array(
      'views_autocomplete_fields' => array(
        'title'          => t('Fields'),
        'help'           => t('Displays the fields with an optional template.'),
        'handler'        => 'views_autocomplete_plugin_row_fields',
        'path'           => "$module_path/views",
        'theme'          => 'views_view_fields',
        'theme path'     => "$views_path/theme",
        'register theme' => FALSE,
        'uses fields'    => TRUE,
        'uses options'   => TRUE,
        'type'           => 'autocomplete',
        'parent'         => 'fields',
      ),
    ),
  );

  if (module_exists('panels')) {
    $plugins['row']['views_autocomplete_panels_fields'] = array(
        'title'          => t('Panel fields'),
        'help'           => t('Displays the fields in a panel rather than using a template.'),
        'handler'        => 'panels_views_plugin_row_fields',
        'path'           => drupal_get_path('module', 'panels') . '/plugins/views',
        'theme'          => 'views_view_fields',
        'theme path'     => "$views_path/theme",
        'register theme' => FALSE,
        'uses fields'    => TRUE,
        'uses options'   => TRUE,
        'type'           => 'autocomplete',
        'parent'         => 'fields',
      );
  }

  return $plugins;
}