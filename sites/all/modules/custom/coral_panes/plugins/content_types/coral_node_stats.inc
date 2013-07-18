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
  
  coral_node_stats_node_last_editor($node, $stats);
  coral_node_stats_node_last_edit($node, $stats);
  //coral_node_stats_node_type($node, $stats);
  coral_node_stats_node_edits($node, $stats);
  coral_node_stats_node_answers($node, $stats);
  coral_node_stats_node_comments($node, $stats);
  coral_node_stats_node_revisions($node, $stats);
  coral_node_stats_node_children($node, $stats);

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
//----------------------------------


// Node type
function coral_node_stats_node_type($node, &$stats) {
  if (!isset($stats['node'])) $stats['node'] = array();
  
  // Comment count - are comments open
  if (isset($node->type)) {
    $stats['node']['node_type'] = array(
      'title'  => t('Type: '),
      'data'   => node_type_get_name($node),
    );
  }
}


// Time of last edit
function coral_node_stats_node_last_edit($node, &$stats) {
  // Last edit 
  if (isset($node->revision_timestamp)) {
    $stats['node']['last_edit'] = array(
      'title' => t('Edited:'),
      'data' => format_date($node->revision_timestamp, 'short'),
    );
  }
}


// Last editor
function coral_node_stats_node_last_editor($node, &$stats) {
  // Last editor 
  if (isset($node->revision_uid)) {
    $rev_editor = user_load($node->revision_uid); 
    if (isset($rev_editor) && (int)$rev_editor->uid > 0) {
      $stats['node']['last_editor'] = array(
        'title' => t('Last editor:'),
        'data' => theme('username', array('account'=>$rev_editor)),
      );
    }
  }
}


// Number of new revisions
function coral_node_stats_node_edits($node, &$stats) {
  $revs = revision_cache_revision_load($node);
    
  $stats['node']['edits'] = array(
    'title' => t('Edits:'),
    'data'  => count($revs),
  );
}


// Number of answers
function coral_node_stats_node_answers($node, &$stats) {
  // Number of answers for this node
  if ($node->type == 'question') {
    $answer_count = field_get_items('node', $node, 'field_answer_count');
    if (isset($answer_count[0]['value'])) {
      $stats['node']['answer_count'] = array(
        'title' => t('Answers:'),
        'data'  => $answer_count[0]['value'],
      );
    }
  }
}


function coral_node_stats_node_comments($node, &$stats) {
  // Comment count - are comments open
  // Only book content uses "real" comments
  if ($node->type == 'book' && isset($node->comment_count) && $node->comment_original_value == COMMENT_NODE_OPEN) {
    $stats['node']['comment_count'] = array(
      'title'  => t('Comments: '),
      'data'   => $node->comment_count,
    );
  }
  else {
    $comment_count = field_get_items('node', $node, 'field_comment_count');
    $comment_count = $comment_count[0]['value'];
    $stats['node']['comment_count'] = array(
      'title'  => t('Comments: '),
      'data'   => $comment_count,
    );
  }
}


function coral_node_stats_node_revisions($node, &$stats) {
  // This one needs some access checks, eh?
  if (_node_revision_access($node)) {
    $stats['node']['revisions'] = array(
      'title' => 'View',
      'data'  => l('revisions', 'node/'.$node->nid.'/revisions'),
    );
  }
}


// Book children count
function coral_node_stats_node_children($node, &$stats) {
  // Book data
  if (isset($node->book)) {
    $book_count = count(coral_node_stats_book_children(book_link_load($node->book['mlid'])));
    if (isset($book_count) && $book_count) {
      $stats['node']['child_pages'] = array(
        'title' => t('Sub pages: '),
        'data'  => $book_count,
      );
    }
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


// Gather book children
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

