<?php


// Alters
// ------

function mosaic_form_alter(&$form, &$form_state, $form_id) {
  // Lets see if this is a node type edit form.
  //  if so, lets add the type's css  
  //dpm($form_id);
  if (str_replace('_node_form', '', $form_id) != $form_id) {
    // Load type related styles and js  
    _mosiac_be_node_load_by_type($form['#node']);
    // Load default node form and css styles
    $css_path = drupal_get_path('theme', 'mosaic').'/css/forms/form__node_form';
    $js_path = drupal_get_path('theme', 'mosaic').'/js/forms/form__node_form';
    
    if (file_exists($css_path.'.css')) drupal_add_css($css_path.'.css', array('group' => CSS_THEME)); // - targeted type
    if (file_exists($js_path.'.js'))  drupal_add_js($js_path.'.js', array('group' => JS_THEME));
  }

  // Add the js - basic type
  $css_path = drupal_get_path('theme', 'mosaic').'/css/forms/form__'.$form_id;
  $js_path = drupal_get_path('theme', 'mosaic').'/js/forms/form__'.$form_id;
  
  if (file_exists($css_path.'.css')) drupal_add_css($css_path.'.css', array('group' => CSS_THEME)); // - targeted type
  if (file_exists($js_path.'.js'))  drupal_add_js($js_path.'.js', array('group' => JS_THEME));
}


// Stabilize the form action on the comment node book form
//  for some reason the action is not steady after the reply
//  page is set up in panels... Maybe that might be worth looking
//  into, but for now this is fine.
function mosaic_form_comment_node_book_form_alter(&$form, &$form_state) {
  $form['#action'] = '/'.current_path();  
  $form['author']['_author']['#type'] = 'hidden';
}
function mosaic_form_comment_node_snippet_form_alter(&$form, &$form_state) {
  mosaic_form_comment_node_book_form_alter($form, $form_state);
}


// Set destination for the login form - the page you are presently on
function mosaic_form_user_login_alter(&$form, &$form_state) {
  $menu = menu_get_item();  
  $form['#attributes']['class'][] = 'user-login';

  $form['logo'] = array(
    '#markup' => '<img class="login-logo" src="/sites/all/themes/mosaic/assets/images/Coral-Nexus-Logo-Login.jpg" /><img class="login-logo-comp hide" src="/sites/all/themes/mosaic/assets/images/Coral-Nexus-Logo-Login-comp.jpg" /><p class="right h3"><span class="mdorange">Login</span> <strong>-</strong> <span>Welcome back</span></p>',
    '#weight' => -20
  );

  // @TODO: make sure there is no destination or other Query info attached already.
  //  Could be an issue...
  if ($menu['href'] != 'user/login' && $menu['href'] != 'user/register') {
    $form['#action'] .= '?destination='.$menu['href'];
  }
}

function mosaic_form_user_pass_alter(&$form, &$form_state) {
  $menu = menu_get_item();  
  $form['#attributes']['class'][] = 'user-pass';

  $form['logo'] = array(
    '#markup' => '<img class="login-logo" src="/sites/all/themes/mosaic/assets/images/Coral-Nexus-Logo-Login.jpg" /><img class="login-logo-comp hide" src="/sites/all/themes/mosaic/assets/images/Coral-Nexus-Logo-Login-comp.jpg" /><p class="right h3"><span class="mdorange">Reset password</span> <strong>-</strong> <span>Welcome back</span></p>',
    '#weight' => -20
  );
  // @TODO: make sure there is no destination or other Query info attached already.
  //  Could be an issue...
  if ($menu['href'] != 'user/login' && $menu['href'] != 'user/register') {
    $form['#action'] .= '?destination='.$menu['href'];
  }
  
  $form['name']['#description'] = t('Enter your username or email address to recieve a password reset link.');
}

function mosaic_form_user_register_form_alter(&$form, &$form_state) {
  $menu = menu_get_item();  
  $form['#attributes']['class'][] = 'user-register';

  $form['logo'] = array(
    '#markup' => '<img class="login-logo" src="/sites/all/themes/mosaic/assets/images/Coral-Nexus-Logo-Login.jpg" /><img class="login-logo-comp hide" src="/sites/all/themes/mosaic/assets/images/Coral-Nexus-Logo-Login-comp.jpg" /><p class="right h3"><span class="mdorange">Register</span> <strong>-</strong> <span>Cloud pioneering<br> ahead</span></p>',
    '#weight' => -20
  );

  // Update a few descriptions (make em smaller)'
  $form['account']['name']['#description'] = t('Spaces, periods, hyphens, apostrophes, and underscores are allowed.');
  $form['account']['mail']['#description'] = t('Valid email address required. Email addresses are not shared publicly.');
  
  // @TODO: make sure there is no destination or other Query info attached already.
  //  Could be an issue...
  if ($menu['href'] != 'user/login' && $menu['href'] != 'user/register') {
    $form['#action'] .= '?destination='.$menu['href'];
  }
  
  $form['actions']['submit']['#value'] = t('Register');
}


// Set Community documentation as the only possible parent book.
function mosaic_form_book_node_form_alter(&$form, &$form_state) {
  $options = $form['book']['bid']['#options'];
  foreach ($options as $id => $option) {
    if ($option == t('Community documentation')) {
      $default[$id] = $option;
      $form['book']['bid']['#options'] = $default;
      $form['book']['plid']['#title'] = t('Parent document');
      break;
    }
  }
}


// Hide the component count field from the snippet node form
function mosaic_form_snippet_node_form_alter(&$form, &$form_state) {
  $form['field_component_count']['#access'] = FALSE; // no need to see this.
  
  
  // Add custom submit hadler to add component count on submission
  $form['#submit'][] = 'mosaic_snippet_node_submit';
}


function mosaic_node_view_alter(&$build) {
  // Change book node links (send add comment to discussion page)
  // Note: this only works on non-panelized displays, for changing links in
  // panelized nodes, see function mosaic_preprocess_panels_pane__node_links(&$vars)
  if ($build['#entity_type'] == 'node' && $build['#bundle'] == 'book') {
    $node = $build['#node'];
    
    if (isset($build['links']['comment']) && $build['links']['comment']['#links']) {
      $links = $build['links']['comment']['#links'];
      unset($build['links']['comment']['#links']);
      $new_links = array();
      foreach ($links as $i => $link) {
        if ($link['title'] == 'Discussion') {
          $new_links['discussion'] = $link; 
        }
      }
      $build['links']['comment']['#links'] = $new_links;
    }
  }
}


function mosaic_form_contact_site_form_alter(&$form, &$form_state) {
  $form['subject']['#required'] = FALSE;
  $form['name']['#title'] = t('Name');
  $form['mail']['#title'] = t('Email');
}


// Handlers
// --------

function mosaic_snippet_node_submit($form, &$form_state) {
  $node  = $form_state['node'];
  $comps = $form_state['values']['field_snippet_components'][$node->language];
  $cnt   = 0;
  
  foreach ($comps as $i => $comp) {
    if (is_array($comp)) {
      $cnt++;
    }
  }
  
  // Save the number of components
  $form_state['values']['field_component_count'][$node->language][0]['value'] = (string)$cnt;
}


// Update login link from local tasks
function mosaic_menu_local_tasks_alter(&$data, $router_item, $root_path) {
  $tabs = $data['tabs'][0]['output'];
  $menu = menu_get_item();
  $dest = drupal_get_destination();

  if (is_array($tabs)) {
    foreach ($tabs as $indx => $tab) {
      // Ensure login link points to user/login not just user
      if ($tab['#link']['path'] == 'user/login') {
        $data['tabs'][0]['output'][$indx]['#link']['href'] = 'user/login';
        mosaic_menu_local_tasks_user_links($data, $dest, $indx);
      }
      
      if ($tab['#link']['path'] == 'user/register') {
        $data['tabs'][0]['output'][$indx]['#link']['href'] = 'user/register';
        mosaic_menu_local_tasks_user_links($data, $dest, $indx);
      }
      
      if ($tab['#link']['path'] == 'user/password') {
        $data['tabs'][0]['output'][$indx]['#link']['href'] = 'user/password';
        mosaic_menu_local_tasks_user_links($data, $dest, $indx);
      }
    }
  }
}


// Update query destinations
function mosaic_menu_local_tasks_user_links(&$data, $dest, $indx) {
  $query = array();  
  if ($dest) {
    $query = array('query' => array(
      'destination' => $dest['destination'] // set query to the current destination
    ));
  }
  if (!is_array($data['tabs'][0]['output'][$indx]['#link']['localized_options'])) {
    $data['tabs'][0]['output'][$indx]['#link']['localized_options'] = array();
  }
  $data['tabs'][0]['output'][$indx]['#link']['localized_options'] = array_merge($data['tabs'][0]['output'][$indx]['#link']['localized_options'], $query);
}


function mosaic_user_view_alter(&$build) {
  
  $account = $build['#account'];
  
  if ($account->uid == 271) {
    dpm($build);
  }
  
  $ha = $build['hybridauth_identities'];
  $add_provider = l('Add social login providers', 'user/'.$account->uid.'/hybridauth');
  $build['hybridauth_identities']['#description'] = t('Use social login for one click login.') . '<br>' . $add_provider;
}

