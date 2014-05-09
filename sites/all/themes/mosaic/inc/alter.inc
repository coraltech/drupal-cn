<?php


// Alters
// ------

function mosaic_form_alter(&$form, &$form_state, $form_id) {
  // Lets see if this is a node type edit form.
  //  if so, lets add the type's css  
  if (str_replace('_node_form', '', $form_id) != $form_id) {
    // Load type related styles and js  
    _mosiac_be_node_load_by_type($form['#node']);
    
    //dpm($form_id);
    
    // Load default node form and css styles
    $css_path = drupal_get_path('theme', 'mosaic').'/css/forms/form__node_form';
    $js_path = drupal_get_path('theme', 'mosaic').'/js/forms/form__node_form';
    
    if (file_exists($css_path.'.css')) drupal_add_css($css_path.'.css', array('group' => CSS_THEME)); // - targeted type
    if (file_exists($js_path.'.js'))  drupal_add_js($js_path.'.js', array('group' => JS_THEME));
  }

  // Add the js - basic type
  $css_path = drupal_get_path('theme', 'mosaic').'/css/forms/form__'.$form_id;
  $js_path = drupal_get_path('theme', 'mosaic').'/js/forms/form__'.$form_id;
  
  if (file_exists($css_path.'.css')) drupal_add_css($css_path.'.css', array('group' => CSS_THEME)); // - targeted type
  if (file_exists($js_path.'.js'))  drupal_add_js($js_path.'.js', array('group' => JS_THEME));
}


// Stabilize the form action on the comment node book form
//  for some reason the action is not steady after the reply
//  page is set up in panels... Maybe that might be worth looking
//  into, but for now this is fine.
function mosaic_form_comment_node_book_form_alter(&$form, &$form_state) {
  $form['#action'] = '/'.current_path();  
  $form['author']['_author']['#type'] = 'hidden';
}
function mosaic_form_comment_node_snippet_form_alter(&$form, &$form_state) {
  mosaic_form_comment_node_book_form_alter($form, $form_state);
}


function mosaic_form_user_login_alter(&$form, &$form_state) {
  $form['#attributes']['class'][] = 'user-login';
}


// Set Community documentation as the only possible parent book.
function mosaic_form_book_node_form_alter(&$form, &$form_state) {
  $options = $form['book']['bid']['#options'];
  foreach ($options as $id => $option) {
    if ($option == t('Community documentation')) {
      $default[$id] = $option;
      $form['book']['bid']['#options'] = $default;
      $form['book']['plid']['#title'] = t('Parent document');
      break;
    }
  }
}


// Hide the component count field from the snippet node form
function mosaic_form_snippet_node_form_alter(&$form, &$form_state) {
  $form['field_component_count']['#access'] = FALSE; // no need to see this.
  
  
  // Add custom submit hadler to add component count on submission
  $form['#submit'][] = 'mosaic_snippet_node_submit';
}


function mosaic_node_view_alter(&$build) {
  // Change book node links (send add comment to discussion page)
  // Note: this only works on non-panelized displays, for changing links in
  // panelized nodes, see function mosaic_preprocess_panels_pane__node_links(&$vars)
  if ($build['#entity_type'] == 'node' && $build['#bundle'] == 'book') {
    $node = $build['#node'];
    
    if (isset($build['links']['comment']) && $build['links']['comment']['#links']) {
      $links = $build['links']['comment']['#links'];
      unset($build['links']['comment']['#links']);
      $new_links = array();
      foreach ($links as $i => $link) {
        if ($link['title'] == 'Discussion') {
          $new_links['discussion'] = $link; 
        }
      }
      $build['links']['comment']['#links'] = $new_links;
    }
  }
}


function mosaic_form_contact_site_form_alter(&$form, &$form_state) {
  $form['subject']['#required'] = FALSE;
  $form['name']['#title'] = t('Name');
  $form['mail']['#title'] = t('Email');
}


// Handlers
// --------

function mosaic_snippet_node_submit($form, &$form_state) {
  $node  = $form_state['node'];
  $comps = $form_state['values']['field_snippet_components'][$node->language];
  $cnt   = 0;
  
  foreach ($comps as $i => $comp) {
    if (is_array($comp)) {
      $cnt++;
    }
  }
  
  // Save the number of components
  $form_state['values']['field_component_count'][$node->language][0]['value'] = (string)$cnt;
}

