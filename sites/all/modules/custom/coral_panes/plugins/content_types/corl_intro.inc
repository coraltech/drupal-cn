<?php

/**
 * Coral custom breadcrumb.  Edit as needed ;-)
 */
$plugin = array(
  // the title in the admin
  'title' => t('CORL introduction'),
  'single' => TRUE,
  'category' => array(t('Coral'), -9), // We can change this category at will
  'edit form' => 'corl_intro_pane_content_type_edit_form',    // Edit form callback
  'render callback' => 'corl_intro_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function corl_intro_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // Get the args ready for inspection... Achtung baby!
  $block = new stdClass;
  $block->title = (isset($conf['title']) && $conf['title']) ? $conf['title'] : t('What is CoralNexus?');
  $block->content = '<h2 class="hide">'.t('CORL is a flexible cloud development and management framework').'</h2>';
  $block->content .= '<img src="/sites/all/themes/mosaic/assets/images/os-cloud-glue.png" title="CORL is cloud glue" alt="CORL is cloud glue" class="mb-25 img-full">';
  $block->content .= '<img src="/sites/all/themes/mosaic/assets/images/os-cloud-glue-mob.png" title="CORL is cloud glue" alt="CORL is cloud glue" class="mb-125 img-mob">';
  return $block;
}


/**
* 'Edit form' callback for the content type.
*
* Currently un-called... no edit form needed most of the time.
*/
function corl_intro_pane_content_type_edit_form($form, &$form_state) {
  // The configurations as they were saved
  $conf = $form_state['conf'];

  return $form;
}


/**
* Submit function, note anything in the formstate[conf] automatically gets saved
*
* You prob. don't need this for a static content pane.
*/
function corl_intro_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!

}
