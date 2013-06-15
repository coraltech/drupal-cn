<?php

/**
 * Community tabs pane provides the community focused tab set
 *  that one sees on the community (Books) and Q&A related pages.
 **/
$plugin = array(
  // the title in the admin
  'title' => t('Community tabs'),                // ** default pane title **
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Coral'), -9), // We can change this category at will

  //NOTE--->> Un-comment the next line to add configs.  Talk to me if this is not clear ;-) (DW)
  //'edit form' => 'coral_community_tabs_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_community_tabs_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_community_tabs_pane_content_type_render($subtype, $conf, $context = NULL) {
  // our little list
  $items['items'] = array(
    l('<span class="icon"></span>Community documentation', 'node/32', array('html' => true, 'attributes' => array('class' => array('active lcom')))),
    l('<span class="icon"></span>Questions and answers', '<front>', array('html' => true, 'attributes' => array('class' => array('lqa'))))
  );
  $attributes = array(
    'class' => 'com-tabs-ul', // a string or indexed (string) array with the classes for the list tag
  );
  //$attributes = array();
  $block->content = theme('item_list', array('items' => $items['items'], 'attributes' => $attributes));
  return $block;
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_community_tabs_pane_content_type_edit_form($form, &$form_state) {
  //dpm($conf);  
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
function coral_community_tabs_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['field'] = $form_state['values']['field'];
}
