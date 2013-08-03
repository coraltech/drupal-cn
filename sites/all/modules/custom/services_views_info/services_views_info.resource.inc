<?php
/**
 * @file
 * Callbacks for services module resource hooks.
 */

/**
 * Callback for getting views information resources.
 *
 * @param $view_name
 *   String. The views name.
 * @param $display_id
 *   String (optional). The views display name.
 * @param $args
 *   Array (optional). A list of arguments to pass to the view.
 *
 * @return
 *  Array. $view data to return.
 */
function services_views_info_get($view_name, $display_id = 'default', $args = array()) {
  $data = array();
  $view = views_get_view($view_name);

  $view->set_display($display_id);
  $view->set_arguments($args);
  $view->pre_execute();
  $view->execute();
  
  $query = $view->query;
  if (isset($query->limit) && isset($query->pager->total_items)) {
    $data = array(
      'limit' => $query->limit, 
      'total_items' => $query->pager->total_items,
      'view_name' => $view->name,
      'current_display' => $display_id,
      'args' => $args
    );
  }

  return $data;
}

