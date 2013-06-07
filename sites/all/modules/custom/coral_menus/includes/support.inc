<?php

function coral_menus_support_menu_loader() {
  return array(
    'menu_name' => 'support',
    'title' => CORAL_MENUS_PREFIX . t('Support'),
    'description' => t('Support menu for Coral Nexus. Typically found at top of the site.'),
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
function coral_menus_support_links_loader() {
  return array(
    'get_help'=> array(
      'link_title' => t('Get help'),
      'link_path'  => 'node/8',
      'weight'     => 1,
      'options' => array('attributes' => array('class'=> array('get-help-tab'))),
    ),
    'issues' => array(
      'link_title' => t('Issues?'),
      'link_path'  => 'node/8',
      'weight'     => 2,
      'options' => array('attributes' => array('class'=> array('issues-tab'))),
    ),
  );
}

