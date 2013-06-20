<?php

/**
 * Load node css and js by node type being viewed (if any defined)
 * 
 * Format: node__{nid}.css
 */
function _mosiac_be_node_load_by_nid($node) {
  $type = $node->nid;
  $theme_path = drupal_get_path('theme', 'mosaic');
  
  if (file_exists($theme_path.'/css/nodes/nids/node_'.$node->nid.'.css')) drupal_add_css($theme_path.'/css/nodes/nids/node_'.$node->nid.'.css', array('group' => CSS_THEME));
  if (file_exists($theme_path.'/js/nodes/nids/node_'.$node->nid.'.js'))   drupal_add_js($theme_path.'/js/nodes/nids/node_'.$node->nid.'.js', array('group' => JS_THEME));
}

/**
 * Load node css and js by node type being viewed (if any defined)
 * 
 * Format: node__{type}.css
 */
function _mosiac_be_node_load_by_type($node) {
  $type = $node->type;
  $theme_path = drupal_get_path('theme', 'mosaic');
//dpm('node_'.$node->type.'.css');
  if (file_exists($theme_path.'/css/nodes/types/node_'.$node->type.'.css')) drupal_add_css($theme_path.'/css/nodes/types/node_'.$node->type.'.css', array('group' => CSS_THEME));
  if (file_exists($theme_path.'/js/nodes/types/node_'.$node->type.'.js'))   drupal_add_js($theme_path.'/js/nodes/types/node_'.$node->type.'.js', array('group' => JS_THEME));
}

/**
 * Load node css and js by entity mode.
 * 
 * Format: node__{type}__{mode}.css
 */
function _mosaic_be_node_load_by_mode($node, $mode) {
  $type = $node->type;
  $theme_path = drupal_get_path('theme', 'mosaic');
  
  if (file_exists($theme_path.'/css/nodes/view_modes/node_'.$node->type.'__'.$mode.'.css')) drupal_add_css($theme_path.'/css/nodes/view_modes/'.$node->type.'__'.$mode.'.css', array('group' => CSS_THEME));
  if (file_exists($theme_path.'/js/nodes/view_modes/node_'.$node->type.'__'.$mode.'.js'))   drupal_add_js($theme_path.'/js/nodes/view_modes/'.$node->type.'__'.$mode.'.js', array('group' => JS_THEME));
}

/**
 * Load nods css and js according to the spec set in the node's 
 *  fe_attach field.
 * 
 * Format: whatever_you_put_in.css|js
 */
function _mosaic_be_node_load_by_fe_attach($entity) {
  $theme_path = drupal_get_path('theme', 'mosaic');
  //dpm($entity->fe_attach);
  if (isset($entity->fe_attach[$entity->language]) && !empty($entity->fe_attach[$entity->language]) && !empty($entity->fe_attach[$entity->language][0]['value'])) {
    foreach ($entity->fe_attach[$entity->language] as $i => $element) {
      //dpm($element);
      if (file_exists($theme_path.'/css/nodes/fe_attach/'.$element['value'].'.css')) drupal_add_css($theme_path.'/css/nodes/fe_attach/'.$element['value'].'.css', array('group' => CSS_THEME));
      if (file_exists($theme_path.'/js/nodes/fe_attach/'.$element['value'].'.js'))   drupal_add_js($theme_path.'/js/nodes/fe_attach/'.$element['value'].'.js', array('group' => JS_THEME));
    }
  }
}


/**
 * Load comment css and js according to the needs of the many.
 *  God save the Queen.
 */
function _mosaic_be_comment_load_by_node($obj) {
  if (
    isset($obj) && 
    isset($obj->comment) && 
    $obj->comment == COMMENT_NODE_OPEN
  ){
    $mode = ''; // default
    // we can load comment styles on base "comments"
    //  or as they would apply to a node type + mode
    if (isset($obj->panelizer['page_manager']) && 
       isset($obj->panelizer['page_manager']->view_mode)) {
      // Add via mode if need be  
      $mode = $obj->panelizer['page_manager']->view_mode;
    }

    $files = array(
      'comments',
      'comments__'.$obj->type,
      'comments__'.$obj->type.'__'.$mode
    );
    $theme_path = drupal_get_path('theme', 'mosaic');
    foreach ($files as $file) {
      if (file_exists($theme_path.'/css/comments/'.$file.'.css')) drupal_add_css($theme_path.'/css/comments/'.$file.'.css', array('group' => CSS_THEME));
      if (file_exists($theme_path.'/js/comments/'.$file.'.js'))  drupal_add_js($theme_path.'/js/comments/'.$file.'.js', array('group' => JS_THEME));
    }
  }
}

