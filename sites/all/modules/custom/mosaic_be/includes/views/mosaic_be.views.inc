<?php

/**
 * Implementation of hook_views_query_alter
 * @param type $view
 * @param type $query 
 */
function mosaic_be_views_query_alter(&$view, &$query) {
  
  if ($view->name == 'questions' || $view->name == 'documentation') {
           
    $tags = '';
    
    if ($view->current_display != 'related_node') {
      // if we have a tag set the view conditions
      if (isset($_GET['tag'])) $tags = $_GET['tag'];
      if ($tags && $tags != '') {
        $tags = filter_xss_admin(urldecode($tags));
        $tags = explode(' ', $tags);

        $conditions = array(
          0 => array(
            'field' => 'taxonomy_term_data_node.name',
            'value' => $tags,
            'operator' => 'IN'
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
    
    
    else {
      // This view display should always have the node context
      $nid = arg(1);
      if (arg(0) == 'node' && is_numeric($nid)) {
        $node = node_load($nid);
        $tags = field_get_items('node', $node, 'field_tags');
        $names = array();
        foreach ($tags as $id => $tag) {
          $tag = taxonomy_term_load($tag['tid']);
          $names[] = $tag->name;
        }
        
        if (count($names)) { // get the node's tags
          $conditions = array(); 
          $conditions[0] = array(
            'field' => 'taxonomy_term_data_node.name',
            'value' => $names,
            'operator' => 'IN'
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
  }
}