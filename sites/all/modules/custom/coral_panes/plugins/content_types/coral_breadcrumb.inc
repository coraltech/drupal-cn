<?php

/**
 * Coral custom breadcrumb.  Edit as needed ;-) 
 */
$plugin = array(
  // the title in the admin
  'title' => t('Coral breadcrumb'),
  'single' => TRUE,
  'category' => array(t('Coral'), -9), // We can change this category at will
  'edit form' => 'coral_breadcrumb_pane_content_type_edit_form',    // Edit form callback
  'render callback' => 'coral_breadcrumb_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_breadcrumb_pane_content_type_render($subtype, $conf, $context = NULL) {
  $item = menu_get_item();
  $current_breadcrumb = drupal_get_breadcrumb();
  
  if (isset($conf['remove_home']) && $conf['remove_home']) {
    array_shift($current_breadcrumb);
  }
  
  if (isset($conf['append_title']) && $conf['append_title']) {
    if (isset($item['href']) && isset($item['title'])) {
      if (isset($conf['link_title']) && $conf['link_title']) { 
        $current_breadcrumb[] = l($item['title'], $item['href']);
      }
      else {
        $current_breadcrumb[] = $item['title'];
      }
    }
  }
  
  $prefix = '';
  if (isset($conf['prefix']) && $conf['prefix']) {
    $prefix = '<span class="bcprefix">'.$conf['prefix'].'</span>';
  }
  
  $block->title = t('Breadcrumb');
  $block->content = $prefix.theme('breadcrumb', array('breadcrumb' => $current_breadcrumb));
  return $block; 
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_breadcrumb_pane_content_type_edit_form($form, &$form_state) {
  //dpm($conf);  
  // The configurations as they were saved
  $conf = $form_state['conf'];
  
  // Add your Form API (FAPI) additions here:
  $form['remove_home'] = array(
    '#type' => 'checkbox',
    '#title' => t('Remove default "Home" link'),
    '#default_value' => (isset($conf['remove_home'])) ? $conf['remove_home'] : TRUE
  );
  $form['append_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Append current node title'),
    '#default_value' => (isset($conf['append_title'])) ? $conf['append_title'] : TRUE 
  );
  $form['link_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Format node title as a link'),
    '#default_value' => (isset($conf['link_title'])) ? $conf['link_title'] : FALSE 
  );
  $form['prefix'] = array(
    '#type' => 'textfield', 
    '#title' => t('Breadcrumb prefix text'), 
    '#default_value' => (isset($conf['prefix'])) ? $conf['prefix'] : '', 
    '#size' => 30, 
    '#maxlength' => 60, 
  );
  
  return $form;
}


/**
* Submit function, note anything in the formstate[conf] automatically gets saved
* 
* You prob. don't need this for a static content pane.
*/
function coral_breadcrumb_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  $form_state['conf']['remove_home'] = $form_state['values']['remove_home'];
  $form_state['conf']['append_title'] = $form_state['values']['append_title'];
  $form_state['conf']['link_title'] = $form_state['values']['link_title'];
  $form_state['conf']['prefix'] = $form_state['values']['prefix'];
}
