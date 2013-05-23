<?php
/**
 * @file
 * Plugin definition for iVillage global site layout.
 */

$plugin = array(
  'title' => t('Default landing page template'),
  'theme' => 'mosaic-landing-1',
  'category' => 'Landing',
  'icon' => 'screenshot.png',
  'admin css' => '../../../css/global/grid.css',
  'regions' => array(
    'leader' => t('Leader'),
    'main' => t('Main'),
    'secondary' => t('Secondary'),
    'follower' => t('Follower'),
  ),
);