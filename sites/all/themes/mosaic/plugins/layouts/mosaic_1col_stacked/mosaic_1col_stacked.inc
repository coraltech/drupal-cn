<?php
/**
 * @file
 * Plugin definition for iVillage global site layout.
 */

$plugin = array(
  'title' => t('1 column stacked template'),
  'theme' => 'mosaic-1col-stacked',
  'category' => 'Component',
  'icon' => 'screenshot.png',
  'regions' => array(
    'top' => t('Top'),
    'center' => t('Center'),
    'bottom' => t('Bottom'),
  ),
);