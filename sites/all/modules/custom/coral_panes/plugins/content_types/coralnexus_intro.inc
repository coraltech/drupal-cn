<?php

/**
 * Coral custom breadcrumb.  Edit as needed ;-)
 */
$plugin = array(
  // the title in the admin
  'title' => t('CoralNexus introduction'),
  'single' => TRUE,
  'category' => array(t('Coral'), -9), // We can change this category at will
  'edit form' => 'coralnexus_intro_pane_content_type_edit_form',    // Edit form callback
  'render callback' => 'coralnexus_intro_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coralnexus_intro_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // Get the args ready for inspection... Achtung baby!
  $block = new stdClass;
  $block->title = (isset($conf['title']) && $conf['title']) ? '<span class="clowny-an"></span><span class="clowny-an-sml"></span>'.$conf['title'] : '<span class="clowny-an"></span><span class="clowny-an-sml"></span>'.t('What is CoralNexus?');
  $block->content = '<span class="msg">'.t('CoralNexus is an ecosystem for developing, sharing, and documenting distributed applications and cloud architectures.').'</span>';
  return $block;
}


/**
* 'Edit form' callback for the content type.
*
* Currently un-called... no edit form needed most of the time.
*/
function coralnexus_intro_pane_content_type_edit_form($form, &$form_state) {
  // The configurations as they were saved
  $conf = $form_state['conf'];

  return $form;
}


/**
* Submit function, note anything in the formstate[conf] automatically gets saved
*
* You prob. don't need this for a static content pane.
*/
function coralnexus_intro_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!

}
