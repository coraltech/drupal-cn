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
  'edit form' => 'coral_community_tabs_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_community_tabs_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_community_tabs_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // our little list
  $com_class = array('lcom');
  $lqa_class = array('lqa');

  // Set active class as appropriate.
  if (isset($conf['active_tab'])) {
    if ($conf['active_tab'] == '1') { $lqa_class[] = 'tab-active'; }
    else { $com_class[] = 'tab-active'; } 
  }
  
  $items['items'] = array(
    l('<span class="icon"></span>Community documentation', 'node/32', array('html' => true, 'attributes' => array('class' => $com_class))),
    l('<span class="icon"></span>Questions and answers', 'node/55', array('html' => true, 'attributes' => array('class' => $lqa_class)))
  );
  
  $attributes = array(
    'class' => 'com-tabs-ul', // a string or indexed (string) array with the classes for the list tag
  );
  
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
  $active = array('0' => t('Community'), '1'=> t('Questions'));
  $form['active_tab'] = array(
    '#type' => 'radios',
    '#title' => t('Active tab'),
    '#default_value' => isset($conf['active_tab']) ? $conf['active_tab'] : '0',
    '#options' => $active,
    '#description' => t('Determines which tab is "active"'),
  );
  
  return $form;
}


/**
* Submit function, note anything in the formstate[conf] automatically gets saved
* 
* You prob. don't need this for a static content pane.
*/
function coral_community_tabs_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  $form_state['conf']['active_tab'] = $form_state['values']['active_tab'];
}
