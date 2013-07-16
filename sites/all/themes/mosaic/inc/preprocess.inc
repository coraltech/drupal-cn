<?php
// Hooks we can preprocess
function mosaic_preprocess(&$vars, $hook) {
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
  
  // Call potential preprocessors
  $base_func = 'mosaic_preprocess_panels_pane__'.$type; //dpm($base_func);
  $full_func = 'mosaic_preprocess_panels_pane__'.$type.'__'.$subtype; //dpm($full_func);
  if (function_exists($base_func)) $base_func($vars);
  if (function_exists($full_func)) $full_func($vars);
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
      $func = '_preprocess_'.$file;
//dpm($func);
      if (function_exists($func)) $func($vars);
      if (file_exists($path.'/css/views/'.$file.'.css')) drupal_add_css($path.'/css/views/'.$file.'.css', array('group' => CSS_THEME));  
      if (file_exists($path.'/js/views/'.$file.'.js'))   drupal_add_js($path.'/js/views/'.$file.'.js', array('group' => JS_THEME));
    }
  }
  
  if (isset($vars['view']->exposed_raw_input['sort_by'])) {
    $vars['classes_array'][] = 'view-sortby-'.$vars['view']->exposed_raw_input['sort_by']; 
  }
  
  // Put any view query info to the settings array for use by other js
  mosaic_compile_views_query_data($vars);
}

// Preprocess for views fields (row - sort of)
function mosaic_preprocess_views_view_fields(&$vars) {
  //dpm($vars);
}

// Preprocess for views field
function mosaic_preprocess_views_view_field(&$vars) {
  $func = 'mosaic__preprocess_views_views_field_'.$vars['field']->field_alias;
  if (function_exists($func)) $func($vars);
}

// Preprocess the comment - add thread class
function mosaic_preprocess_comment(&$vars) {
  // Set comment title class
  $vars['title_attributes_array']['class'] = array('comment-title');

  // Depth classes
  $count  = count(explode('.', $vars['comment']->thread));
  if ($count > 10) $count = 10; // no need to go deeper than 10 lvls
  $vars['classes_array'][] = 'comment-thread-'.$count;
  
  // Compile nice "submitted" info
  //$vars['submitted'] = t('!datetime', array('!username' => $variables['author'], '!datetime' => $variables['created']));
  $au_sub = '<span class="au-sub">'.$vars['author'].'</span>';
  $po_sub = '<span class="po-sub">Posted: '.$vars['created'].'</span>';
  $vars['submitted'] = $au_sub . $po_sub;
}


// Preprocess field - add css and js where applicable
function mosaic_preprocess_field(&$variables, $hook) {
  $path = drupal_get_path('theme', 'mosaic'); 
  $element = $variables['element'];

  $files = array(
    'field__'.$element['#field_type'],
    'field__'.$element['#field_name']
  );
  foreach ($files as $file) {
//dpm($file);
    if (file_exists($path.'/css/fields/'.$file.'.css')) drupal_add_css($path.'/css/fields/'.$file.'.css', array('group' => CSS_THEME));
    if (file_exists($path.'/js/fields/'.$file.'.js')) drupal_add_js($path.'/js/fields/'.$file.'.js', array('group' => JS_THEME));
  }
}

// Ensure entity|node.tpl.php is in place: use if needed (e.g: submitted by...)
function mosaic_preprocess_entity(&$vars) {}

// Add some stuff to nodes... lots of stuff right?
function mosaic_preprocess_node(&$vars) {
  if (!isset($vars['title_attributes_array']['class'])) $vars['title_attributes_array']['class'] = '';
  if (!$vars['page']) $vars['title_attributes_array']['class'] = $vars['title_attributes_array']['class'] . ' node-teaser-title';
  $vars['title_attributes_array']['class'] = $vars['title_attributes_array']['class'] . ' node-title';
}


// Preprocess node-title panes - add icon span 
function mosaic_preprocess_panels_pane__node_title(&$vars) {
  $content  = $vars['content'];
  $position = strpos($content, '>');
  $vars['content'] = substr($content, 0, $position+1).'<span class="icon"></span>'.substr($content, $position+1);
}


// Ugh, more links!
function mosaic_preprocess_panels_pane__node_links(&$vars) {
  if (isset($vars['content']['node']['#links']['node-readmore'])) {
    unset($vars['content']['node']['#links']['node-readmore']);
  }
}


// Preprocess user pictures.
function mosaic__preprocess_views_views_field_users_node_revision_picture(&$vars) {
  //dpm($vars);
  $row   = $vars['row']; //dpm($row);
  $field = $vars['field']; //dpm($field);
  if ($vars['output'] == '') {
    if (isset($row->users_node_revision_uid)) {
      // style name
      $image_style = 'user_thumb_small';
      if (isset($field->options['image_style'])) {
        $image_style = $field->options['image_style'];
      }
      $title = '';
      if (isset($row->users_node_revision_name)) {
        $title = t('View profile of '.$row->users_node_revision_name);
      }
      
      $vars['output'] = mosaic_compile_default_user_image($row->users_node_revision_uid, $image_style, $title);
    }
  }
}

// Re-formulate the tag links to point to the page we are current on.
//  Add query params for other views to read.
function mosaic__preprocess_views_views_field_taxonomy_term_data_name(&$vars) {
  if ($vars['view']->name == 'tags_popular' && 
      $vars['view']->current_display == 'popular_question_tags') {
    $vars['output'] = l($vars['output'], 'content/questions-and-answers', array('query' => array('tag' => $vars['output'])));
    return;    
  }
  if ($vars['view']->name == 'tags_popular') { 
    $vars['output'] = l($vars['output'], drupal_get_path_alias(), array('query' => array('tag' => $vars['output'])));
    return;
  }
}

// Compile a default user picture and link
function mosaic_preprocess_user_picture(&$vars) {
  $a0 = arg(0); $a1 = arg(1); $a2 = arg(2);
 
  $account = $vars['account'];
  $title = '';
  if (isset($account->name)) {
    $title = t('View profile of '.$account->name);
  }
  
  $styles = image_styles();
  if (isset($vars['image_style']) && array_key_exists($vars['image_style'], $styles)) {
    $image_style = $vars['image_style'];
  }

  //dpm($a0);dpm($a1);dpm($a2);
  if ($a0 == 'user') { // thumbnail (larger than normal)
    $image_style = (!isset($image_style)) ? 'thumbnail' : $image_style;
    $vars['user_picture'] = mosaic_compile_default_user_image($account->uid, $image_style, $title);
  }
  else {
    $image_style = (!isset($image_style)) ? 'user_thumb_small' : $image_style;
    $vars['user_picture'] = mosaic_compile_default_user_image($account->uid, $image_style, $title);
  }
}

// Compiles a user image
function mosaic_compile_default_user_image($uid, $image_style, $title) {
  return l(
    theme(
      'image_style', 
      array(
        'style_name' => $image_style,
        'path' => 'public://coraltechiconlg.png',
        'title' => $title
      )
    ), 
    'user/'.$uid, // link path
    array('html' => 'true') // we have a pic
  );
}

// Compiles data about this view's query and puts it to the settings array
//  Settings key is [view_name]_[view_display]_[[view_arg]_[view_arg]...]
function mosaic_compile_views_query_data(&$vars) {
  
  // Views to exclude:
  //  Some views have a query alter running on them
  //  that impedes this feature's usefulness. For 
  //  this reason lets exclude those views when we can.
  $exclude = array('questions');

  // Got views? - with queries!
  if (isset($vars['view']) && isset($vars['view']->query) && !in_array($vars['view']->name, $exclude)) {
    $view  = $vars['view'];
    $query = $vars['view']->query;

    $settings = array(); // empty settings for now
    if (isset($query->pager->total_items)) {
      $settings['total_items'] = $query->pager->total_items;
    }
    if (isset($query->pager->options['items_per_page'])) {
      $settings['limit'] = $query->pager->options['items_per_page'];
    }
    
    // Compile settings key
    $args = implode('_', $view->args);
    if ($args) $args = '_'.$args;
    $key = $view->name.'_'.$view->current_display.$args;
    
    // Add da settings
    drupal_add_js(array('mosaicViews' => array($key => $settings)), 'setting');
  }
}

// Add additional classes to the panelizer view mode tpl title classes
function mosaic_preprocess_panelizer_view_mode(&$vars) {
  if (isset($vars['element']['#entity_view_mode'])) {
    $data = $vars['element']['#entity_view_mode'];
    $type = $data['entity_type'];
    $bundle = $data['bundle'];
    $mode = $data['view_mode'];
    
    $vars['title_attributes_array']['class'][] = $bundle.'-'.$type.'-pane-title';
    $vars['title_attributes_array']['class'][] = $bundle.'-'.$type.'-'.$mode.'-pane-title';
  }
}


// The main "new" questions page as seen on q&a.
function _preprocess_view__questions__new_questions(&$vars) {
  $g = $_GET;
  $output = '';
  $reset = l('reset', $g['q']);
  if (isset($g['tag'])) {
    // add a way for the user to see and reset the filtered tag
    $output .= '<div class="q-filtered-tag">';
    $output .= '<span class="filtered-by">'.t('filtered by: ').'"<span class="ftag">'.$g['tag'].'</span>"</span>';
    $output .= '<span class="reset-filter">'.$reset.'</span></div>';
    $vars['title'] = $output;
  }
}
