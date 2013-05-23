<?php

/**
 * Implementation of hook_menu().
 *
 * Add a settings page to configure the module.
 */
function coral_admin_menu() {
  $items['admin/config/content/coral'] = array(
    'title' => t('Coral'),
    'page callback'    => 'drupal_get_form',
    'page arguments'   => array('coral_settings_form'),
    'access arguments' => array('access administration pages'),
    'type'             => MENU_NORMAL_ITEM,
  );
  return $items;
}

/**
 * Administrative settings menu callback.
 *
 * Settings form to configure the module.
 */
function coral_settings_form($form, &$form_state) {
	$form = array();

	return system_settings_form($form);
}


