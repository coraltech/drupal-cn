<?php

/**
 * Implementation of hook_views_query_alter
 * @param type $view
 * @param type $query 
 */
function mosaic_be_views_query_alter(&$view, &$query) {
  if ($view->name == 'questions') {
      
    $query_string = $_SERVER['QUERY_STRING'];
    $query_string = explode('=', $query_string);
    
    // if we have a tag set the view conditions
    if (isset($query_string[1])) {
      $tag = filter_xss_admin(urldecode($query_string[1]));
      $conditions = array(
        0 => array(
          'field' => 'taxonomy_term_data_node.name',
          'value' => $tag,
          'operator' => '='
        )      
      );
      // Set the query (this one is on [0])
      $query->where[0] = array(
        'conditions' => $conditions,
        'args' => array(),
        'type' => 'AND'
      );
    }
  }
}