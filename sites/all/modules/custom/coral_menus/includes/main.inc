<?php

function coral_menus_main_menu_loader() {
  return array(
    'menu_name' => 'main',
    'title' => CORAL_MENUS_PREFIX . t('Main'),
    'description' => t('Primary navigation menu for Coral Nexus'),
  );
}

/**
 * Links should be defined in the format:
 * 
 * 'about'=> array(
 *   'link_title' => t('About'),
 *   'link_path'  => '<front>',
 *   'weight'     => 1,
 *   'plid'       => [parent name] // must be in this menu obviously
 *  )
 * 
 * NOTE: the attribute "id" must be set!
 * 
 **/
function coral_menus_main_links_loader() {
  return array(
    'about'=> array(
      'link_title' => t('About'),
      'link_path'  => 'node/920',
      'weight'     => 1,
    ),
    /*
      'about_project'=> array(
        'link_title' => t('About COR'),
        'link_path'  => 'node/920',
        'weight'     => 1,
        'plid'       => 'about',
      ),
      'about_team'=> array(
        'link_title' => t('About us'),
        'link_path'  => 'node/921',
        'weight'     => 1,
        'plid'       => 'about',
      ),
      'about_support'=> array(
        'link_title' => t('Support'),
        'link_path'  => 'node/922',
        'weight'     => 1,
        'plid'       => 'about',
      ),
    */
    'project' => array(
      'link_title' => t('Project'),
      'link_path'  => 'node/923',
      'weight'     => 2,
    ),
    'snippets' => array(
      'link_title' => t('Snippets'),
      'link_path'  => 'node/1037',
      'weight'     => 3, 
    ), 
    'community' => array(
      'link_title' => t('Community'),
      'link_path'  => 'node/32',
      'weight'     => 4,
    ),
    'find' => array(
      'link_title' => t('Find'),
      'link_path'  => 'search/node/all',  
      'weight'     => 5,
    )
    //'build' => array(
    //  'link_title' => t('Build'),
    //  'link_path'  => 'node/8',
    //  'weight'     => 5,
    //)
    //'test' => array(
    //  'link_title' => t('Test'),
    //  'link_path'  => 'node/8',
    //  'weight'     => 6,
    //)
  );
}

