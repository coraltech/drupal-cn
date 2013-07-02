<?php

/**
 * Coral custom breadcrumb.  Edit as needed ;-) 
 */
$plugin = array(
  // the title in the admin
  'title' => t('Coral tag search'),
  'single' => TRUE,
  'category' => array(t('Coral'), -9), // We can change this category at will
  'edit form' => 'coral_tag_search_pane_content_type_edit_form',    // Edit form callback
  'render callback' => 'coral_tag_search_pane_content_type_render'  // Render callback
);


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function coral_tag_search_pane_content_type_render($subtype, $conf, $context = NULL) {
  $block->title = t('Tag search');
  $block->content = drupal_render(drupal_get_form('coral_tag_search_form'));
  return $block; 
}

function coral_tag_search_form($form, &$form_state) {
  $form['tag'] = array(
    '#type' => 'textfield', 
    '#title' => '', 
    '#size' => 30, 
    '#maxlength' => 60,
    '#autocomplete_path' => 'services/tagsearch',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Go',
  );
  return $form;
}

/**
 * Tag search form redirects to the search page!
 * ----
 * Be sure to look at the facetapi readme for detail
 * on using the query parameters.  It's helpfulness cannot 
 * be overstated.
 */
function coral_tag_search_form_submit($form, &$form_state) {
  $tag = filter_xss_admin($form_state['values']['tag']);
  $form_state['redirect'] = array(
    'search/node/all',
    array('query' => array('f' => array(rawurlencode('field_tags:name') . ":" . $tag)))
  );
}


/**
 * 'Edit form' callback for the content type.
 * 
 * Currently un-called... no edit form needed most of the time.
 */
function coral_tag_search_pane_content_type_edit_form($form, &$form_state) {
  // The configurations as they were saved
  $conf = $form_state['conf'];
  
  // Add your Form API (FAPI) additions here:
  return $form;
}


/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * 
 * You prob. don't need this for a static content pane.
 */
function coral_tag_search_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['remove_home'] = $form_state['values']['remove_home'];
}
