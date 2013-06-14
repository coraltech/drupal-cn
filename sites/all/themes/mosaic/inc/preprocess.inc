<?php
// Hooks we can preprocess
function mosaic_preprocess (&$vars, $hook) {
//dpm($hook);
}

/**
 * Pane css and js file attachment:
 * 
 * All panes must run through this function 
 *  so it should be able to capture the lions
 *  share of the attachment workload.
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
  global $base_path;
  
  $path     = drupal_get_path('theme', 'mosaic');  
  $join     = '_';  
  $root     = 'pane__';
  $type     = str_replace('-', $join, $vars['pane']->type);            // dpm($type);
  $subtype  = $join.str_replace('-', $join, $vars['pane']->subtype);   // dpm($subtype);
  $base_css_file = $root.$type.'.css';
  $base_js_file  = $root.$type.'.js';
  $css_file = $root.$type.$subtype.'.css';
  $js_file  = $root.$type.$subtype.'.js';

  //dpm($css_file);
  
  // Add the css - basic type
  if (file_exists($path.'/css/panes/'.$base_css_file)) drupal_add_css($path.'/css/panes/'.$base_css_file, array('group' => CSS_THEME)); // - targeted type
  if (file_exists($path.'/css/panes/'.$css_file))      drupal_add_css($path.'/css/panes/'.$css_file, array('group' => CSS_THEME));
  
  // Add the js - basic type
  if (file_exists($path.'/js/panes/'.$base_js_file)) drupal_add_js($path.'/js/panes/'.$base_js_file, array('group' => JS_THEME)); // - targeted type
  if (file_exists($path.'/js/panes/'.$js_file))      drupal_add_js($path.'/js/panes/'.$js_file, array('group' => JS_THEME));
  
  // Add layout types
  $layout = $vars['display']->layout;
  if (file_exists($path.'/css/layouts/'.$layout.'.css')) drupal_add_css($path.'/css/layouts/'.$layout.'.css', array('group' => CSS_THEME)); // - targeted layout
  if (file_exists($path.'/js/layouts/'.$layout.'.js'))   drupal_add_css($path.'/js/layouts/'.$layout.'.js', array('group' => JS_THEME));
}



/**
 * Implements hook_preprocess_views_view().
 */
function mosaic_preprocess_views_view(&$vars) {
  $path = drupal_get_path('theme', 'mosaic');  
  
   if(isset($vars['view']->name)) {
    $files = array(
      'view__' . $vars['view']->name . '__' . $vars['view']->current_display,
      'view__' . $vars['view']->name
    );
    foreach($files as $i => $file) {
//dpm($file);
      if (function_exists('_preprocess_'.$file)) $func($file);
      if (file_exists($path.'/css/views/'.$file.'.css')) drupal_add_css($path.'/css/views/'.$file.'.css', array('group' => CSS_THEME));  
      if (file_exists($path.'/js/views/'.$file.'.js'))   drupal_add_js($path.'/js/views/'.$file.'.js', array('group' => JS_THEME));
    }
  }
}


// Ensure entity|node.tpl.php is in place: use if needed (e.g: submitted by...)
function mosaic_preprocess_entity(&$vars) {}
function mosaic_preprocess_node(&$vars) {}






