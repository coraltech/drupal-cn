<?php

/**
 * Implementation of hook_views_query_alter
 * @param type $view
 * @param type $query 
 */
function mosaic_be_views_query_alter(&$view, &$query) {
  
  if ($view->name == 'questions') { 
    $tag = '';
    
    // if we have a tag set the view conditions
    if (isset($_GET['tag'])) $tag = $_GET['tag'];
    if ($tag && $tag != '') {
      $tag = filter_xss_admin(urldecode($tag));
      //dpm($tag);
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