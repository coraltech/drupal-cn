<?php

/**
 * Coral custom breadcrumb.  Edit as needed ;-)
 */
$plugin = array(
  // the title in the admin
  'title' => t('Coral register'),
  'single' => TRUE,
  'category' => array(t('Coral'), -9), // We can change this category at will
  'edit form' => 'coral_register_pane_content_type_edit_form',    // Edit form callback
  'render callback' => 'coral_register_pane_content_type_render'  // Render callback
);


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function coral_register_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  // 0 = Blue | 1 = Naked
  $theme = ($conf['theme'] == '0') ? 'blue' : 'naked';
  $blurb = ($conf['blurb']) ? $conf['blurb'] : '';

  $block = new stdClass;
  $block->title = t('User register');
  $form = drupal_get_form('coral_register_form');
  $block->content = '<div class="regthm theme-'.$theme.'"><div class="blurb">'.$blurb.'</div>'.drupal_render($form).'</div>';
  return $block;
}

function coral_register_form($form, &$form_state) {
  $tos = l('terms of service', 'docs/terms-service');
  $priv = l('privacy policy', 'docs/privacy-policy');

  $form['status'] = array(
    '#markup' => '<div class="reg-status hide"></div>'
  );
  $form['name'] = array(
    '#title' => t('Username'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );
  $form['mail'] = array(
    '#title' => t('Email'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );
  $form['passtxt'] = array(
    '#title' => t('Password'),
    '#type' => 'textfield',
    '#maxlength' => 64,
    '#size' => 15,
    '#description' => t('Password may contain 7-20 alphanumeric and special characters !@#$%^&*_-'),
  );
  $form['pass'] = array(
    '#title' => t('Password'),
    '#type' => 'password',
    '#maxlength' => 64,
    '#size' => 15,
    '#description' => t('Password may contain 7-20 alphanumeric and special characters !@#$%^&*_-'),
  );
  $form['viewpass'] = array(
    '#type' => 'checkbox',
    '#title' => t('View pass.'),
    '#attributes' => array('checked' => 'checked', 'tabindex' => 4),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Sign up'),
  );
  $form['extras'] = array(
    '#markup' => l('Login', 'user/login', array('attributes'=>array('class'=>array('login'))))
  );
  $form['policy'] = array(
    '#markup' => '<div class="policy">'.t('Use of our service consitutes an exceptance of our ').$tos.t(' and ').$priv.'</div>'
  );
  return $form;
}


// Validate the registration form
function coral_register_form_validate($form, &$form_state) {
  // Validate name
  //print_r($form_state);
  $nameStatus = _coral_panes_namesearch($form_state['values']['name'], 'text');
  if (!$nameStatus['accepted']) {
    form_set_error('name', 'Selected username is not valid');
  }

  // Validate email
  $matches = array();
  $pattern = '/^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/';
  preg_match($pattern, $form_state['values']['mail'], $matches);
  if (!count($matches)) {
    form_set_error('mail', 'Email address is not valid');
  }

  // Validate password
  $matches = array();
  $pattern = '/^[a-zA-Z0-9!@#$%^&*\_\-]{7,20}$/';
  preg_match($pattern, $form_state['values']['pass'], $matches);
  if (!count($matches)) {
    form_set_error('pass');
    form_set_error('passtxt');
    drupal_set_message('Password is not valid.', 'error');
  }
}


/**
 * Tag search form redirects to the search page!
 * ----
 * Be sure to look at the facetapi readme for detail
 * on using the query parameters.  It's helpfulness cannot
 * be overstated.
 */
function coral_register_form_submit($form, &$form_state) {
  $pass = '';
  $edit = array(
    'name' => $form_state['values']['name'],
    'pass' => $form_state['values']['pass'],
    'mail' => $form_state['values']['mail'],
    'init' => $form_state['values']['mail'],
    'status' => 1,
    'access' => REQUEST_TIME,
  );
  $user = user_save(drupal_anonymous_user(), $edit);
  if ($user->uid) { // save successful
    drupal_set_message('Registration successful.');
  }
  else {
    drupal_set_message('Registration failed.', 'error');
  }
}


/**
 * 'Edit form' callback for the content type.
 *
 * Currently un-called... no edit form needed most of the time.
 */
function coral_register_pane_content_type_edit_form($form, &$form_state) {
  // The configurations as they were saved
  $conf = $form_state['conf'];

  $theme = array(0 => t('Blue'), 1 => t('Naked'));

   $form['theme'] = array(
    '#type' => 'radios',
    '#title' => t('Pane theme'),
    '#default_value' => isset($conf['theme']) ? $conf['theme'] : 1,
    '#options' => $theme,
    '#description' => t('Select the theme for this display.'),
  );

  $form['blurb'] = array(
    '#type' => 'textfield',
    '#title' => t('Signup message'),
    '#default_value' => isset($conf['blurb']) ? $conf['blurb'] : '',
    '#size' => 60,
    '#maxlength' => 140,
    '#required' => FALSE,
  );


  // Add your Form API (FAPI) additions here:
  return $form;
}


/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 *
 * You prob. don't need this for a static content pane.
 */
function coral_register_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
