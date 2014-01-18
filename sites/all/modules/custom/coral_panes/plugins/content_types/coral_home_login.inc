<?php

$plugin = array(
  // the title in the admin
  'title' => t('Login (home)'),                // ** default pane title **
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Coral'), -9), // We can change this category at will

  //NOTE--->> Un-comment the next line to add configs.  Talk to me if this is not clear ;-) (DW)
  'edit form' => 'coral_home_login_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_home_login_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_home_login_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  global $user;
      
  $log = l('Login', 'user/login');
  $fog = l('Forgot password', 'user/password');
  $reg = l('Register', 'user/register');
  $wik = l('wiki docs', 'node/32');
  $com = l('community Q&A', 'node/55');
  
  $output = '<div class="login-sep grid-24-last"></div>';
  
  if (!$user->uid) {
    $output .= '<div class="grid-4 prepend-2">'.l('Sign up', 'user/login', array('attributes' => array('class' => array('btn')))).'</div>';
    $output .= '<div class="grid-5"><ul><li>'.$log.'</li><li>'.$fog.'</li></ul></div>';
    $output .= '<div class="append-1 grid-12-last"><p>Signup to recieve updates, edit and discuss '.$wik.', and post to the '.$com.'. No registration required to use Coral.</p></div>';
  }
  
  $block->title = t('Sign up');
  $block->content = $output;
  return $block; 
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_home_login_pane_content_type_edit_form($form, &$form_state) {
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
function coral_home_login_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['field'] = $form_state['values']['field'];
}
