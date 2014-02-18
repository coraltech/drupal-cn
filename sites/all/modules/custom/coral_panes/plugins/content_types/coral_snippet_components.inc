<?php

/**
 * Custom plugin to provide question form on wiki pages.
 *  Wiki questions will be stored in the 
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Coral snippet component count'),
  'description' => t("Pane that shows the current number of components attached to this snippet node."),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node')
  ),
  'category' => t('Coral'),
  'edit form' => 'coral_snippet_components_pane_content_type_edit_form',    // Edit form callback
  'render callback'  => 'coral_snippet_components_pane_content_type_render'
  //'defaults' => array('anon_links' => false),
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_snippet_components_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  $node = $context[0]->data;
  $comp_count = count(field_get_items('node', $node, 'field_snippet_components'));
  $comp_count = format_plural($comp_count, '<span class="cmpcnt">1</span> component', '<span class="cmpcnt">@count</span> components');
  //$comp_count_link = l($comp_count, 'node/'.$node->nid, array('attributes' => array('title' => 'Click to view components')));

  $links = array();
  $links['comp_count'] = array(
    'href' => 'node/'.$node->nid,
    'title' => $comp_count,
    'attributes' => array(
      'title' => 'Click to view components'
    )
  );

  //$links = array($comp_count_link);
  $ul = theme('links', array(
    'links' => $links,
    'attributes' => array('class' => array('links', 'inline')),
  )); 

  $block->title = t('Snippet components');
  $block->content = '<div class="snippet-comp">'.$ul.'</div>';
  return $block; 
}


// Admin title
function coral_snippet_components_pane_content_type_admin_title($subtype, $conf, $context) {
  return t('Configure snippet components');
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_snippet_components_pane_content_type_edit_form($form, &$form_state) {
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
function coral_snippet_components_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['field'] = $form_state['values']['field'];
}
