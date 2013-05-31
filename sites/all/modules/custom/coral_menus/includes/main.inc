<?php

function coral_menus_main_menu_loader() {
  return array(
    'menu_name' => t('main'),
    'title' => CORAL_MENUS_PREFIX . t('Main'),
    'description' => t('Primary navigation menu for Coral Nexus'),
  );
}


function coral_menus_main_links_loader() {
  return array(
    array(
      'link_title' => t('About'),
      'menu_name'  => 'main',
      'link_path'  => drupal_get_normal_path('<front>'),
    ),
    array(
      'link_title' => t('Community'),
      'menu_name'  => 'main',
      'link_path'  => drupal_get_normal_path('<front>'),
    )
  );
}


/*
    array(
      'link_title' => t('Community'),
      'menu_name'  => 'main',
      'link_path'  => drupal_get_normal_path('<front>'),
    )
*/
    
