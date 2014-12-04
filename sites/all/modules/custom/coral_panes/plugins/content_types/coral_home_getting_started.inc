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
* 4: Save this plugin in the components > plugins > content_types folder
*
* 5: Add your new plugin to a panel
*
*/
$plugin = array(
  // the title in the admin
  'title' => t('Getting started (home)'),                // ** default pane title **
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Coral'), -9), // We can change this category at will

  //NOTE--->> Un-comment the next line to add configs.  Talk to me if this is not clear ;-) (DW)
  'edit form' => 'coral_home_getting_started_pane_content_type_edit_form',    // Edit form callback

  // Renderer function
  'render callback' => 'coral_home_getting_started_pane_content_type_render',  // Render callback

  'defaults' => array()
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_home_getting_started_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  $gstart = l('Getting started', 'docs/getting-started', array('attributes' => array('class' => array('start'))));
  $install = l('Installation', 'docs/installation', array('attributes' => array('class' => array('install'))));
  $commands = l('Commands', 'docs/commands', array('attributes' => array('class' => array('commands'))));

  $output = <<<EOF
  <p class="dkyellow strong h4 mt-0625">Install as a standalone application</p>
  <div class="shell">
    <div class="line"><span class="prompt">$></span> <span class="command">gem install corl</span></div>
  </div>
  <p class="dkyellow strong h4">Also works great with Vagrant</p>
  <div class="shell">
    <div class="line"><span class="prompt">$></span> <span class="command">vagrant plugin install corl</div>
  </div>
  <div class="center mt-125">{$install} <span class="mdgray">|</span> {$gstart} <span class="mdgray">|</span> {$commands}</div>
EOF;

  // ttlpos
  $ttl = t("Get started, it's free!");
  $block = new stdClass;
  $block->title = ($conf['ttlpos'] == '0') ? $ttl : '';
  $block->content = ($conf['ttlpos'] == '1') ? '<h2 class="pane-title">'.$ttl.'</h2>'.$output : $output;
  return $block;
}


/**
* 'Edit form' callback for the content type.
*
* Currently un-called... no edit form needed most of the time.
*/
function coral_home_getting_started_pane_content_type_edit_form($form, &$form_state) {
  //dpm($conf);
  // The configurations as they were saved
  $conf = $form_state['conf'];

  // Add your Form API (FAPI) additions here:
  $pos = array(0 => t('Inside'), 1 => t('Above'));

  $form['ttlpos'] = array(
    '#type' => 'radios',
    '#title' => t('Title position'),
    '#default_value' => $conf['ttlpos'] ? $conf['ttlpos'] : 0,
    '#options' => $pos,
    '#description' => t('When a poll is closed, visitors can no longer vote for it.'),
    '#access' => user_access('administer nodes'),
  );

  return $form;
}


/**
* Submit function, note anything in the formstate[conf] automatically gets saved
*
* You prob. don't need this for a static content pane.
*/
function coral_home_getting_started_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['field'] = $form_state['values']['field'];
  foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
