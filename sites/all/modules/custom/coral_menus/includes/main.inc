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
    'about'=> array(
      'link_title' => t('About'),
      'menu_name'  => 'main',
      'link_path'  => drupal_get_normal_path('<front>'),
      'options' => array(
        'attributes' => array(
          'id' => 'about'
        )
      )
    ),
    'community' => array(
      'link_title' => t('Community'),
      'menu_name'  => 'main',
      'link_path'  => drupal_get_normal_path('<front>'),
      'options' => array(
        'attributes' => array(
          'id' => 'community'
        )
      )
    )
  );
}
/*
    'community' => array(
      'link_title' => t('Community'),
      'menu_name'  => 'main',
      'link_path'  => drupal_get_normal_path('<front>'),
    )
*/
