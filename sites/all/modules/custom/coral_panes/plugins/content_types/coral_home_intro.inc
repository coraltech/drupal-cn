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
  'title' => t('Coral Nexus Intro'), 
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Coral'), -9), // We can change this category at will

  //NOTE--->> Un-comment the next line to add configs.  Talk to me if this is not clear ;-) (DW)
  //'edit form' => 'coral_about_intro_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_home_intro_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_home_intro_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  $output = <<<EOF
<div class="home-intro-container">
  <div class="home-intro-content">
    <h2>Coral is a free and open source cloud development framework.</h2>
    <div class="clearfix">
      <div class="left grid-12">
        <ul>
          <li>Pluggable highly configurable architecture.</li>
          <li>Deploy clusters locally or to the cloud provider of your choice.</li>
          <li>All cluster stage changes controlled through Git for reliability and accountability.</li>
        </ul>
      </div>
      <div class="left grid-12-last">
        <ul>
          <li>Configuration states compiled to JSON for ease of use by humans and machines.</li>
          <li>Architecture provides inheritance and cascading configurations support.</li>
          <li>Built with industry leading technologies: Vagrant, Puppet, Ruby, Git, JSON</li>
        </ul>
        <a class="more" href="/">Learn more</a>
      </div>
    </div>
    <div class="shade-line"></div>
    <div class="home-intro-left"></div>
    <div class="home-intro-right"></div>
  </div>
</div>
EOF;

  $block->content = $output;
  return $block; 
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_home_intro_pane_content_type_edit_form($form, &$form_state) {
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
function coral_home_intro_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['field'] = $form_state['values']['field'];
}
