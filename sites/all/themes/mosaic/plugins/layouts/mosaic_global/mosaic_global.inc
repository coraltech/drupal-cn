<?php
/**
 * @file
 * Plugin definition for iVillage global site layout.
 */

$plugin = array(
  'title' => t('Global site template'),
  'theme' => 'mosaic-global',
  'category' => 'Global',
  'icon' => 'screenshot.png',
  'regions' => array(
    'header' => t('Header'),
    'main' => t('Main'),
    'footer' => t('Footer'),
  ),
);