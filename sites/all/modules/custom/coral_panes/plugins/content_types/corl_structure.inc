<?php

/**
 * Coral custom breadcrumb.  Edit as needed ;-)
 */
$plugin = array(
  // the title in the admin
  'title' => t('CORL structure'),
  'single' => TRUE,
  'category' => array(t('Coral'), -9), // We can change this category at will
  'edit form' => 'corl_structure_pane_content_type_edit_form',    // Edit form callback
  'render callback' => 'corl_structure_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function corl_structure_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // Get the args ready for inspection... Achtung baby!
  $block = new stdClass;
  $block->title = (isset($conf['title']) && $conf['title']) ? $conf['title'] : t('CORL structure');
  $content = <<<EOF
<div class="row">
  <div class="corl-structure grid-16">
    <img src="/sites/all/themes/mosaic/assets/images/CORL-structure.jpg" alt="CORL structure diagram">
  </div>
  <div class="scenarios grid-8-last">
    <div>
      <div class="hdr">Scenarios</div>
      <h3>Sharable packages</h3>
      <p>Susan wants to use HBase in her department. Bob is already using HBase in his. CORL lets Bob and Susan collaborate on a reusable HBase package that they can quickly configure and deploy.</p>
      <h3>Portable projects</h3>
      <p>Albert wants to deliver flexible cloud-enabled applications to his clients. CORL lets Albert build and deliver encapsulated apps that contain all workflows, tools, and network architecture needed.</p>
      <h3>Unlimited scalability</h3>
      <p>Dianne researches stocks and needs to be able to quickly scale her computing power. CORL provides Dianne a powerful envinronment for rapidly spinning up and processing her R scripts across providers.</p>
    </div>
  </div>
</div>
EOF;
  $block->content = $content;
  return $block;
}


/**
* 'Edit form' callback for the content type.
*
* Currently un-called... no edit form needed most of the time.
*/
function corl_structure_pane_content_type_edit_form($form, &$form_state) {
  // The configurations as they were saved
  $conf = $form_state['conf'];

  return $form;
}


/**
* Submit function, note anything in the formstate[conf] automatically gets saved
*
* You prob. don't need this for a static content pane.
*/
function corl_structure_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!

}
