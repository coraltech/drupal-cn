<?php

function coral_menus_help_menu_loader() {
  return array(
    'menu_name' => 'help',
    'title' => CORAL_MENUS_PREFIX . t('Help'),
    'description' => t('Help navigation menu for Coral Nexus. Typically appears in the "Getting help" popout.'),
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
function coral_menus_help_links_loader() {
  return array(
    'com_qa'=> array(
      'link_title' => t('Community Q&A'),
      'link_path'  => 'node/8',
      'weight'     => 1,
    ),
    'contact_us' => array(
      'link_title' => t('Contact us'),
      'link_path'  => 'contact',
      'options' => array('attributes' => array('class'=>array('contact-us'))),
      'weight'     => 2,
    ),
    'documentation' => array(
      'link_title' => t('Documentation'),
      'link_path'  => 'node/32',
      'options'    => array('attributes' => array('class'=>array('documentation'))),
      'weight'     => 3,
    ),
      'command_line' => array(
        'link_title' => t('Command line usage'),
        'link_path'  => 'node/8',
        'options'    => array('attributes' => array('class'=>array('command-line'))),
        'plid'       => 'documentation',
        'weight'     => 1,
      ),
      'web_portal' => array(
        'link_title' => t('Website usage'),
        'link_path'  => 'node/8',
        'options'    => array('attributes' => array('class'=>array('web-portal'))),
        'plid'       => 'documentation',
        'weight'     => 2,
      ),
      'restful_api' => array(
        'link_title' => t('Restful API usage'),
        'link_path'  => 'node/8',
        'options'    => array('attributes' => array('class'=>array('restful-api'))),
        'plid'       => 'documentation',
        'weight'     => 3,
      ),
      'ruby_api' => array(
        'link_title' => t('Ruby API usage'),
        'link_path'  => 'node/8',
        'options'    => array('attributes' => array('class'=>array('ruby-api'))),
        'plid'       => 'documentation',
        'weight'     => 4,
      ),
    'getting_started' => array(
      'link_title' => t('Getting started'),
      'link_path'  => 'node/8',
      'weight'     => 4,
    ),
    'bug_report' => array(
      'link_title' => t('Issues and bugs!'),
      'link_path'  => 'node/8',
      'options' => array('attributes' => array('class'=>array('bug-report'))),
      'weight'     => 5,
    ),
    'sitemap' => array(
      'link_title' => t('Using SSH keys'),
      'link_path'  => 'node/8',
      'weight'     => 6,
    ),
    'upgrading_account' => array(
      'link_title' => t('Upgrading account'),
      'link_path'  => 'node/8',
      'weight'     => 7,
    )
  );
}

