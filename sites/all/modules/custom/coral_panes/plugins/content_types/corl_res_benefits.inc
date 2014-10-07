<?php

/**
 * Coral custom breadcrumb.  Edit as needed ;-)
 */
$plugin = array(
  // the title in the admin
  'title' => t('CORL Researcher benefits'),
  'single' => TRUE,
  'category' => array(t('Coral'), -9), // We can change this category at will
  'edit form' => 'corl_res_benes_pane_content_type_edit_form',    // Edit form callback
  'render callback' => 'corl_res_benes_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function corl_res_benes_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // Get the args ready for inspection... Achtung baby!
  $block = new stdClass;
  $block->title = (isset($conf['title']) && $conf['title']) ? $conf['title'] : t('Researcher benefits');

  // begin content
  $content = '<h2 class="hide">'.t('Researcher corl cloud benefits').'</h2>'; // seo
  $content .= '<div class="cont"><img src="/sites/all/themes/mosaic/assets/images/research-benes.png" class="bene-img res-img"></div>';
  $content .= '<ul><li><strong>'.t('Keep everything together.').'</strong> '.t('Encapsulated projects let you keep data, research tools, and results, in handly portable packages.').'</li>';
  $content .= '<ul><li><strong>'.t('Use it however you need.').'</strong> '.t('Spin up large networks for big tasks, or small ones for smaller tasks. Stop and restart anytime.').'</li>';
  $content .= '<ul><li><strong>'.t('Realize effortless concurrency.').'</strong> '.t('Rapidly launch scripts and other apps across machines and across providers.').'</li>';
  $content .= '<ul><li><strong>'.t('Collaborate and share').'</strong> '.t('encapsulated research projects with your team for faster analysis and improved accuracy.').'</li>';
  $content .= '</ul>';
  $block->content = $content;
  return $block;
}


/**
* 'Edit form' callback for the content type.
*
* Currently un-called... no edit form needed most of the time.
*/
function corl_res_benes_pane_content_type_edit_form($form, &$form_state) {
  // The configurations as they were saved
  $conf = $form_state['conf'];

  return $form;
}


/**
* Submit function, note anything in the formstate[conf] automatically gets saved
*
* You prob. don't need this for a static content pane.
*/
function corl_res_benes_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!

}
