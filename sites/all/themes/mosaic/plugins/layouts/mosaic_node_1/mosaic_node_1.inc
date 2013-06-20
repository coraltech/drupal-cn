<?php
/**
 * @file
 * Plugin definition for iVillage global site layout.
 */

$plugin = array(
  'title' => t('Default node layout template'),
  'theme' => 'mosaic-node-1',
  'category' => 'Landing',
  'icon' => 'screenshot.png',
  'admin css' => '../../../css/global/grid.css',
  'regions' => array(
    'leader' => t('Leader'),
    'main' => t('Main'),
    'secondary' => t('Secondary'),
    'follower' => t('Follower'),
    'sub_footer' => t('Sub footer'),
  ),
);