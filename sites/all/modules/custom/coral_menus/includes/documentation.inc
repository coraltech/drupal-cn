<?php

function coral_menus_documentation_menu_loader() {
  return array(
    'menu_name' => 'documentation',
    'title' => CORAL_MENUS_PREFIX . t('Documentation'),
    'description' => t('Document navigation menu for Coral Nexus. Typically seen in footer.'),
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
function coral_menus_documentation_links_loader() {
  return array(
    'command_line'=> array(
      'link_title' => t('Command line'),
      'link_path'  => drupal_get_normal_path('<front>'),
      'weight'     => 1,
    ),
    'web_portal' => array(
      'link_title' => t('Web portal'),
      'link_path'  => drupal_get_normal_path('<front>'),
      'weight'     => 2,
    ),
    'restful_api' => array(
      'link_title' => t('Restful API'),
      'link_path'  => drupal_get_normal_path('<front>'),
      'weight'     => 3,
    ),
    'ruby_api' => array(
      'link_title' => t('Ruby API'),
      'link_path'  => drupal_get_normal_path('<front>'),
      'weight'     => 4,
    )
  );
}

