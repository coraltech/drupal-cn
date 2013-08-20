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

function coral_node_stats_pane_content_styles() {
  return array(
    '1' => t('Gray'),
    '2' => t('Yellow'),
    '3' => t('Unstyled')
  );
}

function coral_node_stats_pane_content_stats() {
  return array(
    '1' => t('Last editor'),
    '2' => t('Last edited'),
    '3' => t('Number of edits'),
    '4' => t('Number of answers'),
    '5' => t('Number of comments'),
    '6' => t('Number of revisions'),
    '7' => t('Number of children'),
    '8' => t('Link to node')
  );
}

function coral_node_stats_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  $stats = array();
  $style = FALSE;
  
  if (isset($conf['display_style'])) {
    $style = $conf['display_style'];
  }
  
  foreach ($context as $id => $c) {
    if (isset($c->keyword) && ($c->keyword == 'node') && isset($c->data)) {
      $node = $c->data;
    }
  }
  
  if (!isset($node->nid)) return new stdClass(); // abort
  
  $no_settings = TRUE; // allows us to show all items if none are set
  
  if (isset($conf['display_stats'])) { // is there anything set?
    foreach ($conf['display_stats'] as $id => $stat) {
      if (isset($conf['display_stats'][$id]) && $conf['display_stats'][$id]) {
        $no_settings = FALSE;
        break;
      }
    }
  }
  
  if ($no_settings) { // any checks
    coral_node_stats_node_last_editor($node, $stats);
    coral_node_stats_node_last_edit($node, $stats);
    coral_node_stats_node_edits($node, $stats);
    coral_node_stats_node_answers($node, $stats);
    coral_node_stats_node_comments($node, $stats);
    coral_node_stats_node_revisions($node, $stats);
    coral_node_stats_node_children($node, $stats);
    coral_node_stats_node_link($node, $stats);
  }
  else {
    if (isset($conf['display_stats']['1']) && $conf['display_stats']['1']) coral_node_stats_node_last_editor($node, $stats);
    if (isset($conf['display_stats']['2']) && $conf['display_stats']['2']) coral_node_stats_node_last_edit($node, $stats);
    if (isset($conf['display_stats']['3']) && $conf['display_stats']['3']) coral_node_stats_node_edits($node, $stats);
    if (isset($conf['display_stats']['4']) && $conf['display_stats']['4']) coral_node_stats_node_answers($node, $stats);
    if (isset($conf['display_stats']['5']) && $conf['display_stats']['5']) coral_node_stats_node_comments($node, $stats);
    if (isset($conf['display_stats']['6']) && $conf['display_stats']['6']) coral_node_stats_node_revisions($node, $stats);
    if (isset($conf['display_stats']['7']) && $conf['display_stats']['7']) coral_node_stats_node_children($node, $stats);
    if (isset($conf['display_stats']['8']) && $conf['display_stats']['8']) coral_node_stats_node_link($node, $stats);
  }
  //coral_node_stats_node_type($node, $stats);
  
  $block->title = t('Node statistics');
  $block->content = coral_node_stats_process_stats($stats, $node, $style); 
  return $block;
}

function coral_node_stats_pane_content_type_admin_title($subtype, $conf, $context) {
  return t('Node stats edit form');
}

function coral_node_stats_pane_content_type_edit_form($form, &$form_state) {
  // Saved configurations  
  $conf = $form_state['conf'];

  // Allow the admin to determine the stats to show in the pane
  $stats = coral_node_stats_pane_content_stats();
  $form['display_stats'] = array(
    '#type' => 'checkboxes',
    '#options' => $stats,
    '#title' => t('Selete statistics to include. Select to none to include all.'),
    '#default_value' => isset($conf['display_stats']) ? $conf['display_stats'] : $stats,
  );
  
  // Allow choice of styles
  $styles = coral_node_stats_pane_content_styles();
  $form['display_style'] = array(
    '#type' => 'radios',
    '#title' => t('Display style'),
    '#default_value' => isset($conf['display_style']) ? $conf['display_style'] : '1',
    '#options' => $styles,
    '#description' => t('Statistics pane style settings.'),
  );
  
  
  return $form;
}

function coral_node_stats_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  $form_state['conf']['display_stats'] = $form_state['values']['display_stats'];
  $form_state['conf']['display_style'] = $form_state['values']['display_style'];
}


//----------------------------------
// Helpers for loading stats
//----------------------------------


function coral_node_stats_node_link($node, &$stats) {
  if (isset($node->nid)) {
    $stats['node']['node_link'] = array(
      'class' => 'node-link',
      'title' => '',
      'data'  => l('View this '.strtolower(node_type_get_name($node)), 'node/'.$node->nid)
    );
  }
}


// Node type
function coral_node_stats_node_type($node, &$stats) {
  // node type - not currently in use
  if (isset($node->type)) {
    $stats['node']['node_type'] = array(
      'class' => 'node-type',
      'title' => t('Type: '),
      'data'  => node_type_get_name($node),
    );
  }
}


// Time of last edit
function coral_node_stats_node_last_edit($node, &$stats) {
  // Last edit 
  if (isset($node->revision_timestamp)) {
    $stats['node']['last_edit'] = array(
      'class' => 'edit',
      'title' => t('Edited:'),
      'data'  => format_date($node->revision_timestamp, 'short'),
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
        'class' => 'editor',
        'title' => t('Last editor:'),
        'data'  => theme('user_picture', array('account'=>$rev_editor, 'image_style'=>'user_thumb_small')).theme('username', array('account'=>$rev_editor)),
      );
      
      // This is actually used by some js so don't touch
      //  And keep it hidden; keep it safe lol
      //  ref: pane__coral_best_answer.js
      $stats['node']['editor_info'] = array(
        'class' => 'editor_info editor_info-'.$node->nid.' hide',
        'title' => $rev_editor->uid,
        'data'  => $rev_editor->name
      );
    }
  }
}


// Number of new revisions
function coral_node_stats_node_edits($node, &$stats) {
  $revs = revision_cache_revision_load($node);
    
  $stats['node']['edits'] = array(
    'class' => 'edits',
    'title' => t('Edits:'),
    'data'  => count($revs),
  );
}


// Number of answers
function coral_node_stats_node_answers($node, &$stats) {
  // Number of answers for this node
  if ($node->type == 'question') {
    $best_answer = field_get_items('node', $node, 'field_answer');
    $best_icon = '';
    if (isset($best_answer[0]['target_id'])) {
      $best_icon = '<span class="best-ans-ico"></span>';      
    }
    
    $answer_count = field_get_items('node', $node, 'field_answer_count');
    if (isset($answer_count[0]['value'])) {
      $stats['node']['answer_count'] = array(
        'class' => 'answers',
        'title' => t('Answers:'),
        'data'  => $answer_count[0]['value'].$best_icon,
      );
    }
  }
}


function coral_node_stats_node_comments($node, &$stats) {
  // Comment count - are comments open
  // Only book content uses "real" comments
  if ($node->type == 'book' && isset($node->comment_count) && $node->comment_original_value == COMMENT_NODE_OPEN) {
    $stats['node']['comment_count'] = array(
      'class' => 'comments',
      'title' => t('Comments: '),
      'data'  => $node->comment_count,
    );
  }
  else {
    $comment_count = field_get_items('node', $node, 'field_comment_count');
    $comment_count = $comment_count[0]['value'];
    $stats['node']['comment_count'] = array(
      'class' => 'comments',
      'title' => t('Comments: '),
      'data'  => $comment_count,
    );
  }
}


function coral_node_stats_node_revisions($node, &$stats) {
  // This one needs some access checks, eh?
  if (_node_revision_access($node)) {
    $stats['node']['revisions'] = array(
      'class' => 'revisions',
      'title' => 'View ',
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
        'class'  => 'children',
        'title' => t('Sub pages: '),
        'data'  => $book_count,
      );
    }
  }
}


// Primary processor of stat data
function coral_node_stats_process_stats($stats, $node, $style) {
  // we can have multiple different data items
  //  for each type of stats eg: revisions
  $stat_rows = array();
  $set = '';
  
  foreach ($stats as $set => $data) {
    $stat_rows[$set] = array();  
    if (count($data)) {
      foreach ($data as $statid => $data) {
        $stat_rows[$set][$statid] = theme(
          array('coral_stat__'.$statid, 'coral_stat'), 
          array(
            'stat_title' => $data['title'],
            'data' => $data['data'],
            'node' => $node,
            'class' => $data['class']
          )
        );
      }
    }
  }
  
  $stat_styles = coral_node_stats_pane_content_styles();
  if (isset($style) && $style) $style = strtolower($stat_styles[$style]);
  else $style = strtolower($stat_styles['1']);
    
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
      $output .= theme(array('coral_stat_set__'.$set, 'coral_stat_set'), array('markup' => $set_markup, 'set_name' => $set, 'style' => $style));
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

