<?php

/**
 * Coral custom breadcrumb.  Edit as needed ;-)
 */
$plugin = array(
  // the title in the admin
  'title' => t('CORL Developer benefits'),
  'single' => TRUE,
  'category' => array(t('Coral'), -9), // We can change this category at will
  'edit form' => 'corl_dev_benes_pane_content_type_edit_form',    // Edit form callback
  'render callback' => 'corl_dev_benes_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function corl_dev_benes_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // Get the args ready for inspection... Achtung baby!
  $block = new stdClass;
  $block->title = (isset($conf['title']) && $conf['title']) ? $conf['title'] : t('Organizational benefits');

  // begin content
  $content = '<h2 class="hide">'.t('Developer corl cloud benefits').'</h2>'; // seo
  $content .= '<div class="cont"><img src="/sites/all/themes/mosaic/assets/images/dev-benes.png" class="bene-img dev-img"></div>';
  $content .= '<ul class="mb-0"><li class="mb-0625"><strong>'.t('Play on the cloud.').'</strong> '.t('Quickly try out applications and application bundles. Save, stop and re-start anytime.').'</li></ul>';
  $content .= '<ul class="mb-0"><li class="mb-0625"><strong>'.t('Extend and override anything.').'</strong> '.t('Pluggable object model ensures you can build whatever you need, faster.').'</li></ul>';
  $content .= '<ul class="mb-0"><li class="mb-0625"><strong>'.t('Enjoy standardized environments').'</strong> '.t('across teams and across providers. Works great with vagrant too!').'</li></ul>';
  $content .= '<ul class="mb-0"><li class="mb-0 pb-0625"><strong>'.t('Use it how you want.').'</strong> '.t('Software can be used as an IT management application or as a feature rich development library.').'</li></ul>';
  $block->content = $content;
  return $block;
}


/**
* 'Edit form' callback for the content type.
*
* Currently un-called... no edit form needed most of the time.
*/
function corl_dev_benes_pane_content_type_edit_form($form, &$form_state) {
  // The configurations as they were saved
  $conf = $form_state['conf'];

  return $form;
}


/**
* Submit function, note anything in the formstate[conf] automatically gets saved
*
* You prob. don't need this for a static content pane.
*/
function corl_dev_benes_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!

}
