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
  'title' => t('Getting started'),                // ** default pane title **
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Coral'), -9), // We can change this category at will

  //NOTE--->> Un-comment the next line to add configs.  Talk to me if this is not clear ;-) (DW)
  //'edit form' => 'coral_getting_started_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_getting_started_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_getting_started_pane_content_type_render($subtype, $conf, $context = NULL) {
  global $user;
  
  $pricing = l('* Pricing options', '<front>');
  $more    = l('Get started', '<front>');
  $callout = 'Sign up for a ';
  $accnt = l('premium account', '<front>');
  
  $user_text = '';
  if (!$user->uid) {
    $user_text = l('Login', 'user/login') . ' or ' . l('register', 'user/register') . " to get started. It's";
  }
  else {
    $callout = 'Upgrade to a ';
    $user_text = t('In-site development is');
  }
    
  $output = <<<EOF
  <span class="clowny"></span>
  <p class="em">Two easy ways to get started with Coral Nexus</p>
  <h4 class="header command-line">Command line:</h4>
  <div class="shell">
    <div class="line"><span class="prompt">$></span> <span class="command">sudo gem install coral</span></div>
    <div class="line"><span class="prompt">$></span> <span class="command">vagrant coral create {repo} {dir}</span></div>
  </div>
  <div class="msg prepend-3 append-2"><span class="up-pointer"></span>You now have a local cluster that includes ssh access and an online dashboard!</div>
  <h4 class="header web-portal">In-site development:</h4>
  <p>{$user_text} free for all open source projects and makes creating, configuring, and sharing technology clusters easy!</p>
  <p>Need private projects? No problem. {$callout} {$accnt} and help support our growth.</p>
  <span class="pricing left">{$pricing}</span>
  <span class="more right">{$more}</span>
EOF;
  
  $block->title = t('Getting started');
  $block->content = $output;
  return $block; 
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_getting_started_pane_content_type_edit_form($form, &$form_state) {
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
function coral_getting_started_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['field'] = $form_state['values']['field'];
}
