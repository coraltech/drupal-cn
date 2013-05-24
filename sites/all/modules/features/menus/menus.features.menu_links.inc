<?php
/**
 * @file
 * menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-account:<front>
  $menu_links['menu-account:<front>'] = array(
    'menu_name' => 'menu-account',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Manage projects',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'manage-projects',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: menu-account:user
  $menu_links['menu-account:user'] = array(
    'menu_name' => 'menu-account',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Manage account',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: menu-documentation:<front>
  $menu_links['menu-documentation:<front>'] = array(
    'menu_name' => 'menu-documentation',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Command line',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'command-line',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-general:<front>
  $menu_links['menu-general:<front>'] = array(
    'menu_name' => 'menu-general',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'About us',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'about',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: user-menu:<front>
  $menu_links['user-menu:<front>'] = array(
    'menu_name' => 'user-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Pricing',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'pricing',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: user-menu:user
  $menu_links['user-menu:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: user-menu:user/login
  $menu_links['user-menu:user/login'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Log in',
    'options' => array(),
    'module' => 'system',
    'hidden' => -1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'user',
  );
  // Exported menu link: user-menu:user/logout
  $menu_links['user-menu:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
  );
  // Exported menu link: user-menu:user/register
  $menu_links['user-menu:user/register'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Create new account',
    'options' => array(),
    'module' => 'system',
    'hidden' => -1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'user',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About us');
  t('Command line');
  t('Create new account');
  t('Log in');
  t('Log out');
  t('Manage account');
  t('Manage projects');
  t('Pricing');
  t('User account');


  return $menu_links;
}
