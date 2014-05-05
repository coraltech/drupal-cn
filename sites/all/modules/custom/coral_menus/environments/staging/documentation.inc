<?php

function coral_menus_documentation_menu_loader() {
  return array(
    'menu_name' => 'documentation',
    'title' => CORAL_MENUS_PREFIX . t('Documentation'),
    'description' => t('Document navigation menu for CoralNexus. Typically seen in footer.'),
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
    'commands'=> array(
      'link_title' => t('Commands'),
      'link_path'  => '<front>',
      'weight'     => 1,
    ),
    'architecture' => array(
      'link_title' => t('Architecture'),
      'link_path'  => 'node/37',
      'weight'     => 2,
    ),
    'requirements' => array(
      'link_title' => t('Requirements'),
      'link_path'  => 'node/1329',
      'weight'     => 3,
    ),
    'cluster' => array(
      'link_title' => t('Creating your first cloud'),
      'link_path'  => 'node/40',
      'weight'     => 4,
    ),
    'plugins' => array(
      'link_title' => t('Developing plugins'),
      'link_path'  => 'node/1172',
      'weight'     => 5,
    ),
    'api_ref' => array(
      'link_title' => t('API References'),
      'link_path'  => 'node/39',
      'weight'     => 5,
    )
  );
}

