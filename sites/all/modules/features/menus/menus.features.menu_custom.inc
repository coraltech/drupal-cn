<?php
/**
 * @file
 * menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'The <em>Management</em> menu contains links for administrative tasks.',
  );
  // Exported menu: menu-account.
  $menus['menu-account'] = array(
    'menu_name' => 'menu-account',
    'title' => 'Account',
    'description' => 'User account management links.',
  );
  // Exported menu: menu-documentation.
  $menus['menu-documentation'] = array(
    'menu_name' => 'menu-documentation',
    'title' => 'Documentation',
    'description' => 'Documentation menu that lives in the footer.',
  );
  // Exported menu: menu-general.
  $menus['menu-general'] = array(
    'menu_name' => 'menu-general',
    'title' => 'General',
    'description' => 'An all-pupose menu that lives in the footer.',
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Account');
  t('An all-pupose menu that lives in the footer.');
  t('Documentation');
  t('Documentation menu that lives in the footer.');
  t('General');
  t('Main menu');
  t('Management');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('The <em>Management</em> menu contains links for administrative tasks.');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('User account management links.');
  t('User menu');


  return $menus;
}
