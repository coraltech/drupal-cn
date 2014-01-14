<?php

function coral_menus_about_menu_loader() {
  return array(
    'menu_name' => 'about',
    'title' => CORAL_MENUS_PREFIX . t('About'),
    'description' => t('About page sub-menu.'),
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
function coral_menus_about_links_loader() {
  return array(
    'about_coral'=> array(
      'link_title' => t('About Coral'),
      'link_path'  => 'node/929',
      'weight'     => 1,
    ),
    'team' => array(
      'link_title' => t('Team'),
      'link_path'  => '<front>',
      'weight'     => 2,
    ),
    'support' => array(
      'link_title' => t('Support'),
      'link_path'  => '<front>',
      'weight'     => 3,
    )
  );
}

