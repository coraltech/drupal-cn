<?php

/**
 * Primary css and js file attachment hook.
 * 
 * All panes must run through this function 
 *  so it should be able to capture the lions
 *  share of the attachment workload.
 * 
 * Common attachment types:
 *  - block
 * 
 * All css and js added by this function will 
 *  be seeking files in the following format:
 * 
 * pane__{pane_type}.(css|js)  * or *
 * pane__{pane_type}_{pane_subtype}.(css|js)
 * 
 * eg. pane__block_superfish_1.css
 * 
 * All files must exist within the "panes"
 *  folder (w/in css|js) to be included here.
 *  
 */
function mosaic_preprocess_panels_pane(&$vars) {
  $path     = drupal_get_path('theme', 'mosaic');  
  $join     = '_';  
  $root     = 'pane__';
  $type     = str_replace('-', $join, $vars['pane']->type);
  $subtype  = $join.str_replace('-', $join, $vars['pane']->subtype);
  $base_css_file = $root.$type;
  $base_js_file  = $root.$type;
  $css_file = $root.$type.$subtype.'.css';
  $js_file  = $root.$type.$subtype.'.js';

  //dpm($css_file);
  
  // Add the css - basic type
  if (file_exists($path.'/css/panes/'.$base_css_file)) {
    drupal_add_css($path.'/css/panes/'.$base_css_file);  
  } // - targeted type
  if (file_exists($path.'/css/panes/'.$css_file)) {
    drupal_add_css($path.'/css/panes/'.$css_file);  
  }
  
  // Add the js - basic type
  if (file_exists($path.'/js/panes/'.$base_js_file)) {
    drupal_add_js($path.'/js/panes/'.$base_js_file);
  } // - targeted type
  if (file_exists($path.'/js/panes/'.$js_file)) {
    drupal_add_js($path.'/js/panes/'.$js_file);
  }
}