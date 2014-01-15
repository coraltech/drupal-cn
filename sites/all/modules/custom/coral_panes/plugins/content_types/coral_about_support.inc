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
  'title' => t('About Support'),                // ** default pane title **
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Coral'), -9), // We can change this category at will

  //NOTE--->> Un-comment the next line to add configs.  Talk to me if this is not clear ;-) (DW)
  'edit form' => 'coral_about_support_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_about_support_pane_content_type_render'  // Render callback
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_about_support_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  if (!isset($conf['support_type']) || $conf['support_type'] == 'support') {
    $block->title = t('Community support');
    $block->content = coral_about_support_community_support();
  }
  else {
    $block->title = t('Support services');
    $block->content = coral_about_support_support_services();
  }
  return $block; 
}


// Community support output
function coral_about_support_community_support() {
  $output = '<p>'.l('Wiki documentation', 'node/32').'</p>';
  $output .= '<p>If you are wanting to learn more about Coral, then head over to the '.l('wiki documentation', 'node/32').'. ';
  $output .= 'Each wiki page has a discussion thread (must be logged in to see) so if you have questions or comments about something ';
  $output .= ' relating to the documents, you can bring them up there.</p>';
  
  $question = l('new question', 'node/55', array('fragment' => 'ask-question'));
  
  $output .= '<p>'.l('Community Q&A', 'node/55').'</p>';
  $output .= '<p>If you have a question, check out the '.l('community Q&A', 'node/32').'; ';
  $output .= 'Someone may have already gotten an answer to that same question. If not, then simply add a '.$question.'.';
  $output .= '  Be as specific as you can. to help others help you diagnose the issue(s).</p>';
  
  $bugz = l('Coral Tech GitHub account', 'https://github.com/coraltech');
  $output .= '<p>'.l('Bug reporting', 'https://github.com/coraltech').'</p>';
  $output .= '<p>If you think you have found a bug, please report that by clicking the issues tab above, or by navigating to the ';
  $output .= $bugz.' and filing out a bug report on the applicable project. Please be as detailed as possible regarding the nature of the issue.</p>';
  return $output;
}


// Services support output
function coral_about_support_support_services() {
  $output = '<p>We also offer personalized support packages that are tailor made for your requirements. Please contact us for more information on any of the following:</p>';
  $output .= '<h4>Personalized services</h4>';
  
  $app   = l('Application integration', '<front>');
  $cloud = l('Cloud architecture migration', '<front>');
  $train = l('Training and consulting', '<front>');
  $sys   = l('Systems analysis', '<front>');

  $list = <<<EOF
  <ul>
    <li>{$app}</li>
    <li>{$cloud}</li>
    <li>{$train}</li>
    <li>{$sys}</li>
  </ul>
EOF;
  return $output.$list;
  
}

/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_about_support_pane_content_type_edit_form($form, &$form_state) {
  //dpm($conf);  
  // The configurations as they were saved
  $conf = $form_state['conf'];
  
  // Add your Form API (FAPI) additions here:
  $form['support_type'] = array(
    '#type' => 'select',
    '#title' => t('Support type'),
    '#options' => array(
      'support' => t('Community support'),
      'services' => t('Support services'),
    ),
    '#default_value' => ($conf['support_type']) ? $conf['support_type'] : 'support',
    '#description' => t('Determine the support type (Community or Services)'),
  );
  
  return $form;
}


/**
* Submit function, note anything in the formstate[conf] automatically gets saved
* 
* You prob. don't need this for a static content pane.
*/
function coral_about_support_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  $form_state['conf']['support_type'] = $form_state['values']['support_type'];
}

