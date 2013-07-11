<?php

/**
 * Coral custom breadcrumb.  Edit as needed ;-) 
 */
$plugin = array(
  // the title in the admin
  'title' => t('Coral back to'),
  'single' => TRUE,
  'category' => array(t('Coral'), -9), // We can change this category at will
  'edit form' => 'coral_back_to_pane_content_type_edit_form',    // Edit form callback
  'render callback' => 'coral_back_to_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_back_to_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // Get the args ready for inspection... Achtung baby!
  $a0 = arg(0);  $a1 = arg(1);  $a2 = arg(2);
  
  if (isset($context[0]) && is_object($context[0])) {
    // We have a node in the context
    if (isset($context[0]->nid)) {
      $node = $context[0];  
    }
  }
  else { // see if we have a node in the args
    if ($a0 == 'node' && is_numeric($a1)) {
      $node = node_load($a1);      
    }
    if ($a0 == 'comment' && $a1 == 'reply' && is_numeric($a2)) {
      $node = node_load($a2);
    }
  }
  // Need a node
  if (is_object($node)) {
    $inline_ttl = '';
    if (isset($conf['inline_title']) && 
        $conf['inline_title'] &&
        isset($conf['inline_title_text']) && 
        $conf['inline_title_text']) {
      $inline_ttl = '<div class="goto-title">'.trim($conf['inline_title_text']).'</div>';      
    } 
    
    $items['items'] = array(
      l($node->title, 'node/'.$node->nid),
      l('Discussion', 'node/'.$node->nid.'/talk')
    );
    
    $items = theme('item_list', $items);
    $block->content = $inline_ttl . $items;
    return $block;
  }
  return new stdClass();
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_back_to_pane_content_type_edit_form($form, &$form_state) {
  //dpm($conf);  
  // The configurations as they were saved
  $conf = $form_state['conf'];
  
  // Add your Form API (FAPI) additions here:
  $form['inline_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Format pane title inline'),
    '#default_value' => (isset($conf['inline_title'])) ? $conf['inline_title'] : FALSE 
  );
  
  $form['inline_title_text'] = array(
    '#type' => 'textfield', 
    '#title' => t('In-line title'), 
    '#default_value' => ($conf['inline_title_text']) ? $conf['inline_title_text'] : '', 
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
function coral_back_to_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  $form_state['conf']['inline_title'] = $form_state['values']['inline_title'];
  $form_state['conf']['inline_title_text'] = $form_state['values']['inline_title_text'];
}
