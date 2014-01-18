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
      'link_path'  => 'node/929',
      'weight'     => 1,
    ),
    'project' => array(
      'link_title' => t('Project'),
      'link_path'  => 'node/932',
      'weight'     => 2,
    ), 
    'community' => array(
      'link_title' => t('Community'),
      'link_path'  => 'node/32',
      'weight'     => 3,
    ),
    'find' => array(
      'link_title' => t('Find'),
      'link_path'  => 'search/node/all',  
      'weight'     => 4,
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

