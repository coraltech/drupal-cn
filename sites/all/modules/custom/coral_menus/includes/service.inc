<?php

function coral_menus_service_menu_loader() {
  return array(
    'menu_name' => 'service',
    'title' => CORAL_MENUS_PREFIX . t('Service'),
    'description' => t('Service management menu for Coral Nexus. Typically beside the primary links.'),
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
function coral_menus_service_links_loader() {
  return array(
    'pricing'=> array(
      'link_title' => t('Pricing'),
      'link_path'  => drupal_get_normal_path('user'),
      'weight'     => 1,
    ),
    'login' => array(
      'link_title' => t('Login'),
      'link_path'  => drupal_get_normal_path('user/login'),
      'weight'     => 2,
    ),
    'register' => array(
      'link_title' => t('Register'),
      'link_path'  => drupal_get_normal_path('user/register'),
      'weight'     => 3,
    ),
    'my_account' => array(
      'link_title' => t('My account'),
      'link_path'  => drupal_get_normal_path('user'),
      'weight'     => 4,
    ),
    'logout' => array(
      'link_title' => t('Logout'),
      'link_path'  => drupal_get_normal_path('user/logout'),
      'weight'     => 5,
    ),
  );
}

