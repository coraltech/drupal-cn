<?php

function coral_menus_main_menu_loader() {
  return array(
    'menu_name' => t('main'),
    'title' => CORAL_MENUS_PREFIX . t('Main'),
    'description' => t('Primary navigation menu for Coral Nexus'),
  );
}

/**
 * Links should be defined in the format:
 * 
 * 'about'=> array(
 *   'link_title' => t('About'),
 *   'link_path'  => drupal_get_normal_path('<front>'),
 *   'options' => coral_menus_link_set_attributes(array('id'=>'about'))
 *  )
 * 
 * NOTE: the attribute "id" must be set!
 * 
 **/
function coral_menus_main_links_loader() {
  return array(
    'about'=> array(
      'link_title' => t('About'),
      'link_path'  => drupal_get_normal_path('<front>'),
    ),
    'community' => array(
      'link_title' => t('Community'),
      'link_path'  => drupal_get_normal_path('<front>'),
    ),
    'find' => array(
      'link_title' => t('Find'),
      'link_path'  => drupal_get_normal_path('<front>'),
    ),
    'build' => array(
      'link_title' => t('Build'),
      'link_path'  => drupal_get_normal_path('<front>'),
    ),
    'test' => array(
      'link_title' => t('Test'),
      'link_path'  => drupal_get_normal_path('<front>'),
    )
  );
}

