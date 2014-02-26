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
  'title' => t('Snippet introduction'),                // ** default pane title **
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Coral'), -9), // We can change this category at will

  //NOTE--->> Un-comment the next line to add configs.  Talk to me if this is not clear ;-) (DW)
  'edit form' => 'coral_snippets_intro_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_snippets_intro_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_snippets_intro_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  global $user;
  
  $btn = FALSE;
  if (node_access('create', 'snippet', $user)) {
    $btn = l('Add a snippet', 'node/add/snippet', array('attributes' => array('class' => array('add'))));
  }
  else {
    $btn = l('Add a snippet', 'user/login', array('attributes' => array('class' => array('add'))));  
  }

  $output = <<<EOF
  <div class="container">
    <div class="grid-20">
      <span class="info"></span>
      <p>Snippets are educational code resources that should be helpful in understanding the COR framework. Snippets shave time off adding features to your cloud definitions, modules, profiles, etc. Snippets should be tagged by language(s) and purpose.</p>
    </div>
    {$btn}
  </div>
EOF;
  $block->title = t('Snippet intro');
  $block->content = $output;
  return $block; 
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_snippets_intro_pane_content_type_edit_form($form, &$form_state) {
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
function coral_snippets_intro_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['field'] = $form_state['values']['field'];
}
