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
  'title' => t('Coral account management'),                // ** default pane title **
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Coral'), -9), // We can change this category at will

  //NOTE--->> Un-comment the next line to add configs.  Talk to me if this is not clear ;-) (DW)
  //'edit form' => 'coral_account_management_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_account_management_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_account_management_pane_content_type_render($subtype, $conf, $context = NULL) {
  global $user;  
  
  $user_manage = 'user/login';
  if ($user->uid) {
    $user_manage = 'user';
  }
    
  $output = <<<EOF
<span class='icon'></span>
<h2 class='pane-title'>Account manangement and privacy</h2>
<p class='small'>Account and projects secured with SSL encryption.</p>
EOF;

  // our little list
  $accnt_list['items'] = array(
    l('Manage your account', $user_manage),
    l('Clusters', '<front>'),
    l('Modules', '<front>')
  );
  $accnt_attr = array(
    'class' => 'account-list', // a string or indexed (string) array with the classes for the list tag
  );
  
  $accnt = '<div class="set"><h4>Account manangement</h4>';
  $accnt .= theme('item_list', array('items' => $accnt_list['items'], 'attributes' => $accnt_attr)).'</div>';
  
  $privacy_list['items'] = array(
    l('Managing project keys', '<front'),
    l('Privacy policy', '<front')
  );
  $privacy_attr = array(
    'class' => 'privacy-list', // a string or indexed (string) array with the classes for the list tag
  );
  $privacy = '<div class="set"><h4>Privacy manangement</h4>';
  $privacy .= theme('item_list', array('items' => $privacy_list['items'], 'attributes' => $privacy_attr)).'</div>';
  
  $block->content = $output . $accnt . $privacy;
  return $block; 
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_account_management_pane_content_type_edit_form($form, &$form_state) {
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
function coral_account_management_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['field'] = $form_state['values']['field'];
}
