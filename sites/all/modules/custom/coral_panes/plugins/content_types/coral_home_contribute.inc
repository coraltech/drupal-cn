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
  'title' => t('Contribute (home)'),                // ** default pane title **
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Coral'), -9), // We can change this category at will

  //NOTE--->> Un-comment the next line to add configs.  Talk to me if this is not clear ;-) (DW)
  //'edit form' => 'coral_home_contribute_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_home_contribute_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_home_contribute_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  $patch = l('submitting patches', '/');
  $bug = l('bug reports', '/');
  $qa = l('community Q&A', 'node/55');
  
  $output = <<<EOF
  <div class="home-contrib-cont">
    <div>
      <span class="public-work"></span>
      <h4>Sponsor development</h4>
      <p>Help make Coral even better by sponsoring development of new cloud framework and application integrations, feature additions, and core improvements.</p>
      <a href="/" class="btn">Become a sponsor</a>
    </div>
    <div>
      <span class="troubleshoot"></span>
      <h4>Troubleshooting</h4>
      <p>Support the project by {$patch}, {$bug}, and or simply helping others in the {$qa}.</p>
    </div>
  </div>
EOF;
  
  $block->title = t('Contribute');
  $block->content = $output;
  return $block; 
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_home_contribute_pane_content_type_edit_form($form, &$form_state) {
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
function coral_home_contribute_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['field'] = $form_state['values']['field'];
}
