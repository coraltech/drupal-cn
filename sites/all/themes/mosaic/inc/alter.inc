<?php


// --- Hooks ---

function mosaic_form_alter(&$form, &$form_state, $form_id) {
  // Lets see if this is a node type edit form.
  //  if so, lets add the type's css  
  if (str_replace('_node_form', '', $form_id) != $form_id) _mosiac_be_node_load_by_type($form['#node']);

  // Add the js - basic type
  $css_path = drupal_get_path('theme', 'mosaic').'/css/forms/form__'.$form_id;
  $js_path = drupal_get_path('theme', 'mosaic').'/js/forms/form__'.$form_id;
  
  if (file_exists($css_path.'.css')) drupal_add_css($css_path.'.css', array('group' => CSS_THEME)); // - targeted type
  if (file_exists($js_path.'.js'))  drupal_add_js($js_path.'.js', array('group' => JS_THEME));
}


// --- Helpers ---

// Stabilize the form action on the comment node book form
//  for some reason the action is not steady after the reply
//  page is set up in panels... Maybe that might be worth looking
//  into, but for now this is fine.
function mosaic_form_comment_node_book_form_alter(&$form, &$form_state) {
  $form['#action'] = '/'.current_path();  
  $form['author']['_author']['#type'] = 'hidden';
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


// Hide the wiki reference. I wish there was a better way
//  however I need to be able to add a value into that form
//  via call-ups of the form itself (see coral_wiki_ask_question).
//  So I can't use the value type. I just have to hide it...
//  This is better than nothing.
function mosaic_form_question_node_form_alter(&$form, &$form_state) {
   
}


function mosaic_node_view_alter(&$build) {
  // Change book node links (send add comment to discussion page)
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
  //dpm($form);
}

