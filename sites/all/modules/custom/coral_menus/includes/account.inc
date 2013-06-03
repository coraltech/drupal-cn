<?php

function coral_menus_account_menu_loader() {
  return array(
    'menu_name' => 'account',
    'title' => CORAL_MENUS_PREFIX . t('Account'),
    'description' => t('Account management menu for Coral Nexus. Typically found in footer.'),
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
function coral_menus_account_links_loader() {
  return array(
    'manage_account'=> array(
      'link_title' => t('Manage account'),
      'link_path'  => 'user',
      'weight'     => 1,
    ),
    'manage_projects' => array(
      'link_title' => t('Manage projects'),
      'link_path'  => 'node/8',
      'weight'     => 2,
    ),
    'upgrade_account' => array(
      'link_title' => t('Upgrade account'),
      'link_path'  => 'node/8',
      'weight'     => 3,
    )
  );
}

