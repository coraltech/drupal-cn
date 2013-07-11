<?php

/**
 * Custom plugin to provide node statistics and info on node
 *  related pages.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Coral node statistics'),
  'description' => t('Displays details about "this" node.'),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node')
  ),
  'category' => t('Coral'),
  'edit form' => 'coral_node_stats_pane_content_type_edit_form',    // Edit form callback
  'render callback'  => 'coral_node_stats_pane_content_type_render',
  'defaults' => array('anon_links' => false),
);


function coral_node_stats_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {

  $stats = array();
  
  foreach ($context as $id => $c) {
    if (isset($c->keyword) && ($c->keyword == 'node') && isset($c->data)) {
      $node = $c->data;
    }
  }
  
  if (!isset($node->nid)) return new stdClass(); // abort
  
  // load cached revision data
  coral_node_stats_revision_data($node, $stats); 
  coral_node_stats_node_data($node, $stats);

  $block->title = t('Node statistics');
  $block->content = coral_node_stats_process_stats($stats, $node); 
  return $block;
}

function coral_node_stats_pane_content_type_admin_title($subtype, $conf, $context) {
  return t('Node stats edit form');
}

function coral_node_stats_pane_content_type_edit_form($form, &$form_state) {
  return $form;
}

function coral_node_stats_pane_content_type_edit_form_submit($form, &$form_state) {}

//----------------------------------
// Helpers for loading stats
//---------------------------------

// Helper to load node data
function coral_node_stats_node_data($node, &$stats) {
  //dpm($node);
  //dpm($stats);

  // Comment count - are comments open
  if (isset($node->comment_count) && $node->comment == COMMENT_NODE_OPEN) {
    $stats['node']['comment_count'] = array(
      'title' => t('Comments: '),
      'data'  => $node->comment_count
    );
  }

  // Book data
  if (isset($node->book)) {
    $book_count = count(coral_node_stats_book_children(book_link_load($node->book['mlid'])));
    if (isset($book_count) && $book_count) {
      $stats['node']['child_pages'] = array(
        'title' => t('Sub pages: '),
        'data'  => $book_count
      );
    }
  }
}

// Helper to load the revisions data
function coral_node_stats_revision_data($node, &$stats) {
  if (!isset($stats['revisions'])) $stats['revisions'] = array();  
  $revs = revision_cache_revision_load($node);
  
  // Last editor 
  if (isset($node->revision_uid)) {
    $rev_editor = user_load($node->revision_uid); 
    if (isset($rev_editor) && (int)$rev_editor->uid > 0) {
      $stats['revisions']['last_editor'] = array(
        'title' => t('Last editor:'),
        'data' => theme('username', array('account'=>$rev_editor))
      );
    }
  }
  
  // Last edit 
  if (isset($node->revision_timestamp)) {
    $stats['revisions']['last_edit'] = array(
      'title' => t('Edited:'),
      'data' => format_date($node->revision_timestamp, 'short')
    );
  }

  $stats['revisions']['edits'] = array(
    'title' => t('Edits:'),
    'data'  => count($revs)
  );
  
  // This one needs some access checks, eh?
  if (_node_revision_access($node)) {
    $stats['revisions']['view'] = array(
      'title' => 'View',
      'data'  => l('revisions', 'node/'.$node->nid.'/revisions'),
    );
  }
}


// Primary processor of stat data
function coral_node_stats_process_stats($stats, $node) {
  // we can have multiple different data items
  //  for each type of stats eg: revisions
  $stat_rows = array();
  foreach ($stats as $set => $data) {
    $stat_rows[$set] = array();  
    if (count($data)) {
      foreach ($data as $statid => $data) {
        $stat_rows[$set][$statid] = theme(array('coral_stat__'.$statid, 'coral_stat'), array('stat_title' => $data['title'], 'data' => $data['data'], 'node' => $node));
      }
    }
  }

  $output = '';
  foreach ($stat_rows as $set => $data) {
    $set_markup = '';
    foreach ($data as $statid => $statdata) {
      $set_markup .= $statdata;
    }
    
    // wrap this set
    if (isset($set_markup)) {
      $set = trim($set);
      
      $patterns = array (
        '/\W+/',         // match any non-alpha-numeric character sequence, except underscores
        '~\xe2\x80\x93~' // match dash
      );

      $replaces = array ('_', '_');

      $result = trim(preg_replace($patterns, $replaces, $set));
      $output .= theme(array('coral_stat_set__'.$set, 'coral_stat_set'), array('markup' => $set_markup, 'set_name' => $set));
    }
  }
  return $output;  
}


function coral_node_stats_book_children($book_link) {
  $flat = book_get_flat_menu($book_link);

  $children = array();

  if ($book_link['has_children']) {
    // Walk through the array until we find the current page.
    do {
      $link = array_shift($flat);
    } while ($link && ($link['mlid'] != $book_link['mlid']));
    // Continue though the array and collect the links whose parent is this page.
    while (($link = array_shift($flat)) && $link['plid'] == $book_link['mlid']) {
      $data['link'] = $link;
      $data['below'] = '';
      $children[] = $data;
    }
  }
  return $children;
}

