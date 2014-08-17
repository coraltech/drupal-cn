<?php

function coral_menus_create_menu_loader() {
  return array(
    'menu_name' => 'create',
    'title' => CORAL_MENUS_PREFIX . t('Create'),
    'description' => t('Create content menu for CoralNexus. Appears in the footer.'),
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
function coral_menus_create_links_loader() {
  return array(
    'ask'=> array(
      'link_title' => t('Ask a question'),
      'link_path'  => 'node/55',
      'weight'     => 1,
    ),
    'snippet'=> array(
      'link_title' => t('Add a snippet'),
      'link_path'  => 'node/add/snippet',
      'weight'     => 2,
    ),
    'project'=> array(
      'link_title' => t('Add a project'),
      'link_path'  => 'node/add/project',
      'weight'     => 3,
    ),
    'wiki'=> array(
      'link_title' => t('Add wiki documents'),
      'link_path'  => 'node/add/book',
      'weight'     => 4,
    )        
  );
}

