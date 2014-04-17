<?php

/**
* This plugin array is more or less self documenting
* 
* To use:
* 
* 1: Simply rename the functions. Removing "generic" and adding some other 
*    useful name for this plugin, eg: SSO.
* 
* 2: Fill in the $plugin title and category below.
* 
* 3: And update the render function to use your content for $block->content
* 
* 4: Save this plugin in the ivillage_components > plugins > content_types folder
* 
* 5: Add your new plugin to a panel
* 
*/
$plugin = array(
  // the title in the admin
  'title' => t('About Coral Nexus'),                // ** default pane title **
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Coral'), -9), // We can change this category at will

  //NOTE--->> Un-comment the next line to add configs.  Talk to me if this is not clear ;-) (DW)
  'edit form' => 'coral_about_intro_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_about_intro_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_about_intro_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  /*$output = <<<EOF
<h1>About Coral Nexus</h1>
<h2>Coral Nexus tools allow your technology clusters to be portable and pluggable.</h2>
<p>Are you ready to simplify the way you work with technology clusters? The Coral Nexus platform provides a free and open source framework that enables you to rapidly spin up and configure sophisticated cluster architectures.</p>
<p>You can start from scratch or <a href='#'>find</a> an open source <a href='#'>cluster</a>, <a href='#'>module</a>, or <a href='#'>snippet</a>, to help you on your way to cluster bliss.</p>
EOF;*/
  $projects = l('projects&nbsp;page', 'node/923', array('html' => TRUE)); // main projects page
  
  $output = <<<EOF
<div class="cloud-case"></div>
<h3>Our mission is to glue the world's technologies together</h3>
<h4>We build pluggable programming frameworks that everyone can use and extend to build the apps and clouds of tomorrow! Our technologies are <u>free and open source</u> and have concurrency and extensibility in their DNA.</h4>
<h4>Our primary framework is CORL, a cloud programming framework that extends Nucleon. To learn more visit the {$projects}.</h4> 
EOF;

  $block->content = $output;
  return $block; 
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_about_intro_pane_content_type_edit_form($form, &$form_state) {
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
function coral_about_intro_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['field'] = $form_state['values']['field'];
}

