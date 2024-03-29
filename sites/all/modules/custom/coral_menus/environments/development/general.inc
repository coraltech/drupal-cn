<?php

function coral_menus_general_menu_loader() {
  return array(
    'menu_name' => 'general',
    'title' => CORAL_MENUS_PREFIX . t('General'),
    'description' => t('General navigation menu for CoralNexus. Typically appears in the footer.'),
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
function coral_menus_general_links_loader() {
  return array(
    'about_us'=> array(
      'link_title' => t('About us'),
      'link_path'  => 'node/920',
      'weight'     => 1,
    ),
    'contact_us' => array(
      'link_title' => t('Contact us'),
      'link_path'  => 'node/922',
      'weight'     => 2,
    ),
    'privacy' => array(
      'link_title' => t('Privacy policy'),
      'link_path'  => 'node/1165',
      'weight'     => 3
    ),
    'sponsors' => array(
      'link_title' => t('Sponsors'),
      'link_path'  => 'node/43',
      'weight'     => 5,
    ),
    'qa' => array(
      'link_title' => t('Q&A'),
      'link_path'  => 'node/55',
      'weight'     => 6,
    ),
    'sitemap' => array(
      'link_title' => t('Sitemap'),
      'link_path'  => 'sitemap',
      'weight'     => 7,
    ),
    'getting_help' => array(
      'link_title' => t('Getting help'),
      'link_path'  => 'node/922',
      'weight'     => 8,
    )
  );
}

