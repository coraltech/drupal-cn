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
  $base_func = 'mosaic_preprocess_panels_pane__'.$type;  // dpm($base_func);
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
      if (function_exists($func)) $func($vars);
      if (file_exists($path.'/css/views/'.$file.'.css')) drupal_add_css($path.'/css/views/'.$file.'.css', array('group' => CSS_THEME));  
      if (file_exists($path.'/js/views/'.$file.'.js'))   drupal_add_js($path.'/js/views/'.$file.'.js', array('group' => JS_THEME));
    }
  }
  
  if (isset($vars['view']->exposed_raw_input['sort_by'])) {
    $vars['classes_array'][] = 'view-sortby-'.$vars['view']->exposed_raw_input['sort_by']; 
  }
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
  // set comment title class
  $vars['title_attributes_array']['class'] = array('comment-title');

  $count  = count(explode('.', $vars['comment']->thread));
  if ($count > 10) $count = 10; // no need to go deeper than 10 lvls
  $vars['classes_array'][] = 'comment-thread-'.$count;
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
  $vars['title_attributes_array']['class'] = 'node-title';
}


// Preprocess node-title panes - add icon span 
function mosaic_preprocess_panels_pane__node_title(&$vars) {
  $content  = $vars['content'];
  $position = strpos($content, '>');
  $vars['content'] = substr($content, 0, $position+1).'<span class="icon"></span>'.substr($content, $position+1);
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

// Compile a default user picture and link
function mosaic_preprocess_user_picture(&$vars) {
  $a0 = arg(0); $a1 = arg(1); $a2 = arg(2);
  
  $account = $vars['account'];
  $title = '';
  if (isset($account->name)) {
    $title = t('View profile of '.$account->name);
  }
  //dpm($a0);dpm($a1);dpm($a2);
  if ($a0 == 'user') { // thumbnail (larger than normal)
    $image_style = 'thumbnail';
    $vars['user_picture'] = mosaic_compile_default_user_image($account->uid, $image_style, $title);
  }
  else {
    $image_style = 'user_thumb_small';
    $vars['user_picture'] = mosaic_compile_default_user_image($account->uid, $image_style, $title);
  }
}

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





