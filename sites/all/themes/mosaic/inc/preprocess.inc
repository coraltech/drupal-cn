<?php
// Hooks we can preprocess
function mosaic_preprocess(&$vars, $hook) {
//dpm($hook);
}

// Include includes - used to ensure mosaic_preprocess_node(&$vars)
// includes node files for section intros...
coral_include(array('includes'), 'inc', array('module' => 'mosaic_be'));

/**
 * Preprocess variables for html.tpl.php
 */
function mosaic_preprocess_html(&$vars) {
  global $language;

  // First check if libraries module exists.
  // Look for html5 and responsive js files for IE. Use them if found, else
  // use external source.
  if (module_exists('libraries', 1.0)) {
    $respond_path = libraries_get_path('Respond') . '/respond.min.js';
    $html5_path = libraries_get_path('html5') . '/html5.js';
    $vars['mosaic_lib']['ie']['respond_path'] = file_exists($respond_path) ? base_path() . $respond_path : 'https://raw.github.com/scottjehl/Respond/master/respond.min.js';
    $vars['mosaic_lib']['ie']['html5_path'] = file_exists($html5_path) ? base_path() . $html5_path : 'http://html5shim.googlecode.com/svn/trunk/html5.js';
  }
  if (module_exists('rdf')) {
    $vars['doctype'] = '<!DOCTYPE html PUBLIC "-//W3C//DTD HTML+RDFa 1.1//EN">' . "\n";
    $vars['rdf']->version = 'version="HTML+RDFa 1.1"';
    $vars['rdf']->namespaces = $vars['rdf_namespaces'];
    $vars['rdf']->profile = ' profile="' . $vars['grddl_profile'] . '"';
  }
  else {
    $vars['doctype'] = '<!DOCTYPE html>' . "\n";

    if (!isset($vars['rdf'])) {
      $vars['rdf'] = new stdClass();
    }

    $vars['rdf']->version = '';
    $vars['rdf']->namespaces = '';
    $vars['rdf']->profile = '';
  }

  // Attributes for html element.
  $vars['html_attributes'] = 'lang="' . $language->language . '" dir="' . $language->dir . '"';
}

// Add form id theme hook suggestions.
function mosaic_preprocess_form(&$vars) {
  $vars['theme_hook_suggestions'][] = 'form_'.$vars['element']['#form_id'];
}

/**
 * Pane css and js file attachment:
 *
 * All panes must run through this function
 *  so it should be able to capture the lions
 *  share of the attachment workload.
 *
 * All css and js added by this function will
 *  be seeking files in the following format:
 *
 * pane__{pane_type}.(css|js)  * or *
 * pane__{pane_type}_{pane_subtype}.(css|js)
 *
 * eg. pane__block_superfish_1.css
 *
 * All files must exist within the "panes"
 *  folder (w/in css|js) to be included here.
 *
 */
function mosaic_preprocess_panels_pane(&$vars) {
  global $base_path;

  $path     = drupal_get_path('theme', 'mosaic');
  $join     = '_';
  $root     = 'pane__';
  $type     = str_replace('-', $join, $vars['pane']->type);            // dpm($type);
  $subtype  = $join.str_replace(array('-', ':'), $join, $vars['pane']->subtype);   // dpm($subtype);
  $base_css_file = $root.$type.'.css';
  $base_js_file  = $root.$type.'.js';
  $css_file = $root.$type.$subtype.'.css';
  $js_file  = $root.$type.$subtype.'.js';

//dpm($css_file);

  // Add the css - basic type
  if (file_exists($path.'/css/panes/'.$base_css_file)) drupal_add_css($path.'/css/panes/'.$base_css_file, array('group' => CSS_THEME)); // - targeted type
  if (file_exists($path.'/css/panes/'.$css_file))      drupal_add_css($path.'/css/panes/'.$css_file, array('group' => CSS_THEME));

  // Add the js - basic type
  if (file_exists($path.'/js/panes/'.$base_js_file)) drupal_add_js($path.'/js/panes/'.$base_js_file, array('group' => JS_THEME)); // - targeted type
  if (file_exists($path.'/js/panes/'.$js_file))      drupal_add_js($path.'/js/panes/'.$js_file, array('group' => JS_THEME));

  // Add layout types
  $layout = $vars['display']->layout;
  if (file_exists($path.'/css/layouts/'.$layout.'.css')) drupal_add_css($path.'/css/layouts/'.$layout.'.css', array('group' => CSS_THEME)); // - targeted layout
  if (file_exists($path.'/js/layouts/'.$layout.'.js'))   drupal_add_css($path.'/js/layouts/'.$layout.'.js', array('group' => JS_THEME));

  // Call potential preprocessors
  $base_func = 'mosaic_preprocess_panels_pane__'.$type; //dpm($base_func);
  $full_func = 'mosaic_preprocess_panels_pane__'.$type.'__'.$subtype; //dpm($full_func);
  if (function_exists($base_func)) $base_func($vars);
  if (function_exists($full_func)) $full_func($vars);
}


/**
 * Implements hook_preprocess_views_view().
 */
function mosaic_preprocess_views_view(&$vars) {
  $path = drupal_get_path('theme', 'mosaic');
  if(isset($vars['view']->name)) {
    $files = array(
      'view__' . $vars['view']->name . '__' . $vars['view']->current_display,
      'view__' . $vars['view']->name
    );
    foreach($files as $i => $file) {
//dpm($file);
      $func = '_preprocess_'.$file;
//dpm($func);
      if (function_exists($func)) $func($vars);
      if (file_exists($path.'/css/views/'.$file.'.css')) drupal_add_css($path.'/css/views/'.$file.'.css', array('group' => CSS_THEME));
      if (file_exists($path.'/js/views/'.$file.'.js'))   drupal_add_js($path.'/js/views/'.$file.'.js', array('group' => JS_THEME));
    }
  }

  if (isset($vars['view']->exposed_raw_input['sort_by'])) {
    $vars['classes_array'][] = 'view-sortby-'.$vars['view']->exposed_raw_input['sort_by'];
  }

  // Put any view query info to the settings array for use by other js
  mosaic_compile_views_query_data($vars);
}

// Preprocess for views fields (row - sort of)
function mosaic_preprocess_views_view_fields(&$vars) {
  //dpm($vars);
}


// Preprocess for views field
function mosaic_preprocess_views_view_field(&$vars) {
  // By alias
  $func = 'mosaic__preprocess_views_views_field_'.$vars['field']->field_alias;

  if (function_exists($func)) $func($vars);

  // By real field name
  if ($vars['field']->real_field != $vars['field']->field_alias) {
    $func = 'mosaic__preprocess_views_views_field_'.$vars['field']->real_field; //dpm($func);
    if (function_exists($func)) $func($vars);
  }
}


// Preprocess the comment - add thread class
function mosaic_preprocess_comment(&$vars) {
  // Set comment title class
  $vars['title_attributes_array']['class'] = array('comment-title');

  // Depth classes
  $count  = count(explode('.', $vars['comment']->thread));
  if ($count > 10) $count = 10; // no need to go deeper than 10 lvls
  $vars['classes_array'][] = 'comment-thread-'.$count;

  // Compile nice "submitted" info
  $au_sub = '<span class="au-sub">'.$vars['author'].'</span>';
  $po_sub = '<span class="po-sub">Posted: '.$vars['created'].'</span>';
  $vars['submitted'] = $au_sub . $po_sub;
}


// Preprocess field - add css and js where applicable
function mosaic_preprocess_field(&$variables, $hook) {
  $path = drupal_get_path('theme', 'mosaic');
  $element = $variables['element'];

  $files = array(
    'field__'.$element['#field_type'],
    'field__'.$element['#field_name']
  );
//dpm($files);

  $func = 'mosaic_preprocess_'.$element['#field_type'];
  if (function_exists($func)) $func($vars);

  $func = 'mosaic_preprocess_'.$element['#field_name'];
  if (function_exists($func)) $func($variables);
//dpm($func);
  foreach ($files as $file) {
    if (file_exists($path.'/css/fields/'.$file.'.css')) drupal_add_css($path.'/css/fields/'.$file.'.css', array('group' => CSS_THEME));
    if (file_exists($path.'/js/fields/'.$file.'.js')) drupal_add_js($path.'/js/fields/'.$file.'.js', array('group' => JS_THEME));
  }
}

// Ensure entity|node.tpl.php is in place: use if needed (e.g: submitted by...)
function mosaic_preprocess_entity(&$vars) {

}

// Add some stuff to nodes... lots of stuff right?
function mosaic_preprocess_node(&$vars) {
  if (!isset($vars['title_attributes_array']['class'])) $vars['title_attributes_array']['class'] = '';
  if (!$vars['page']) $vars['title_attributes_array']['class'] = $vars['title_attributes_array']['class'] . ' node-teaser-title';
  $vars['title_attributes_array']['class'] = $vars['title_attributes_array']['class'] . ' node-title';

  // Nodes
  $node = $vars['node'];
  if (!empty($node->nid) && is_numeric($node->nid)) {
    // Load css and js files as needed by the theme
    //  note files are loaded w theme level settings._mosiac_be_node_load_by_nid($entity);              // Load by node id
    _mosiac_be_node_load_by_nid($node);              // Load by node id
    _mosiac_be_node_load_by_type($node);             // Load by node type
    _mosaic_be_node_load_by_mode($node, $vars['view_mode']); // Load by view modes
    _mosaic_be_node_load_by_fe_attach($node);        // Load by fe_attach field (added on node create form)
  }
}


// Preprocess node-title panes - add icon span
function mosaic_preprocess_panels_pane__node_title(&$vars) {
  $content  = $vars['content'];
  $position = strpos($content, '>');
  $vars['content'] = substr($content, 0, $position+1).'<span class="icon"></span>'.substr($content, $position+1);
}


// Ugh, more links!
function mosaic_preprocess_panels_pane__node_links(&$vars) {

  $context = $vars['display']->context;
  $context = array_pop($context);

  if (isset($context) && isset($context->data)) {
    $node = $context->data;
  }

  if (isset($node)) {
    switch ($node->type) {
      case 'question':
      case 'answer':
      case 'comment':
        if (isset($vars['content']['node']['#links']['node-readmore'])) {
          unset($vars['content']['node']['#links']['node-readmore']);
        }
        if (isset($vars['content']['flag']['#links']['flag-abuse_node'])) {
          unset($vars['content']['flag']['#links']['flag-abuse_node']);
        }
        break;


      case 'snippet':
      case 'book':
        $links = array();

        // Rem flag link for re-addition via pane.
        if (isset($vars['content']['flag']['#links']['flag-abuse_node'])) {
          unset($vars['content']['flag']['#links']['flag-abuse_node']);
        }

        //Modify comment links - rem Add comment
        if (isset($vars['content']['comment']['#links'])) {
          $links = $vars['content']['comment']['#links'];
        }

        unset($vars['content']['comment']['#links']);
        $new_links = array();
        foreach ($links as $i => $link) {
          if ($link['title'] == 'Discussion') {
            $comment_count = '0';
            if (isset($node->comment_count)) {
              $comment_count = $node->comment_count;
            }
            $link['title'] = $link['title'].' ('.$comment_count.')';
            $new_links['discussion'] = $link;
          }
        }
        $vars['content']['comment']['#links'] = $new_links;
        break;

      default: break;
    }
  }
}


// Add nid to the body field
function mosaic_preprocess_panels_pane__entity_field___node_body(&$vars) {
  if (isset($vars['content']['#object']) && isset($vars['content']['#object']->nid)) {
    $nid = $vars['content']['#object']->nid;
    $vars['classes_array'][] = 'body-'.$nid;
  }
}


// Update user questions pane title to be possessive.
function mosaic_preprocess_panels_pane__views_panes___user_content_user_questions_fields(&$vars) {
  // Build a nicer pane title than say, Questions...
  $user_name = $vars['user']->panelizer['page_manager']->display->context['panelizer']->title;

  // Add icon holder for the cloud Q's and get a decent prefix to the name
  $title = '<span class="icon"></span>'.mosaic_possessive($user_name)." questions";
  $vars['title'] = $title;
}

function mosaic_preprocess_panels_pane__views_panes___user_content_user_snippets_fields(&$vars) {
  // Build a nicer pane title than say, Questions...
  $user_name = $vars['user']->panelizer['page_manager']->display->context['panelizer']->title;

  // Add icon holder for the cloud Q's and get a decent prefix to the name
  $title = '<span class="icon"></span>'.mosaic_possessive($user_name)." snippets";
  $vars['title'] = $title;
}


// Add a span for additional styling of the pane title
function mosaic_preprocess_panels_pane__views_panes___doc_ref_node_teaser_view(&$vars) {
  $vars['title'] = '<span>'.$vars['title'].'</span>';
}


// Convert the user image token pane content to display a usable image
function mosaic_preprocess_panels_pane__token___node_user_image(&$vars) {
  $user = $vars['user'];
  if (isset($user->name)) {
    $title = t('View profile of '.$user->name);
  }
  else {
    $title = t('View profile');
  }
  $vars['content'] = mosaic_compile_default_user_image($user, 'user_thumb_small', $title);
}


// Preprocess login block.
function mosaic_preprocess_panels_pane__block___user_login(&$vars) {
  $menu = menu_get_item();

  $links = array();
  $links['register'] = array(
    'href' => 'user/register',
    'title' => t("Register, it's free!"),
    'attributes' => array(
      'title' => 'Sign up and have fun'
    ),
    'query' => array(
      'destination' => $menu['href']
    )
  );
  $links['pass'] = array(
    'href' => 'user/password',
    'title' => t("Request new password"),
    'attributes' => array(
      'title' => 'New passwords are also free!'
    ),
    'query' => array(
      'destination' => $menu['href']
    )
  );

  //$links = array($comp_count_link);
  $ul = theme('links', array(
    'links' => $links,
    'attributes' => array('class' => array('login-links', 'links', 'inline')),
  ));

  $vars['content']['links']['#markup'] = $ul;
}


function mosaic_preprocess_panels_pane__user_signature(&$vars) {
  if (isset($vars['user'])) {
    $user = $vars['user']->uid; // the user looking
    $accnt = $vars['display']->args[0];

    // The user viewing and the signature author
    //  are the same.
    if ($user === $accnt) {
      if (!$vars['content']['user_signature']['#signature']) {
        $vars['content']['user_signature']['#signature'] = t('You have not added a signature.').' '.l('Edit your profile', 'user/'.$user.'/edit').' '.t('to update your account.');
      }
    }
    // else they are not
    else {
      if (!$vars['content']['user_signature']['#signature']) {
        $vars['content']['user_signature']['#signature'] = 'No signature found.';
      }
    }
  }
}


// Answer count output manipulation - add prefix
function mosaic__preprocess_views_views_field_field_answer_count_value(&$vars) {
  $vars['output'] = '<span class="cnt">'.$vars['output'].'</span><span class="txt">'.format_plural($vars['output'], ' answer', ' answers').'</span>';
}


// Answer count output manipulation - add prefix
function mosaic__preprocess_views_views_field_field_data_field_snippet_components_delta(&$vars) {
  $out = $vars['output'];
  $cnt = 1 + $out;
  $vars['output'] = '<span class="cnt">'.$cnt.'</span><span class="txt">'.format_plural($cnt, ' component', ' components').'</span>';
}


// Preprocess user pictures.
function mosaic__preprocess_views_views_field_users_node_revision_picture(&$vars) {
  //dpm($vars);
  $row   = $vars['row']; //dpm($row);
  $field = $vars['field']; //dpm($field);
  if ($vars['output'] == '') {
    if (isset($row->users_node_revision_uid)) {
      // style name
      $image_style = 'user_thumb_small';
      if (isset($field->options['image_style'])) {
        $image_style = $field->options['image_style'];
      }
      $title = '';
      if (isset($row->users_node_revision_name)) {
        $title = t('View profile of '.$row->users_node_revision_name);
      }

      $vars['output'] = mosaic_compile_default_user_image($row->users_node_revision_uid, $image_style, $title);
    }
  }
}


// Processess the user image for the user_image search field
// See coral_solr_fields module.
function mosaic__preprocess_views_views_field_user_image(&$vars) {
  $data = $vars['row']->_entity_properties;

  $allowed_types = array('answer', 'comment', 'question');

  if (in_array($data['type'], $allowed_types)) {
    $user = user_load($data['author']);

    if (isset($user->name)) {
      $title = 'View '.mosaic_possessive($user->name).' profile';
      $image_style = 'user_thumb_small';
      $vars['output'] = mosaic_compile_default_user_image($user, $image_style, $title);
    }

  }
  else {
    $vars['output'] = '';
  }

}

// Handles title field preprocessing
// @TODO: this can go...
function mosaic__preprocess_views_views_field_title(&$vars) {
  if ($vars['view']->name == 'projects') {
    if (isset($vars['row']->field_field_project_home_page[0]['raw']['url'])) {
      $proj_home = $vars['row']->field_field_project_home_page[0]['raw']['url'];
      $vars['output'] = l($vars['field']->last_render_text, $proj_home, array('attributes' => array('target'=>'_blank')));
    }
  }
}

// Re-formulate the tag links to point to the page we are current on.
//  Add query params for other views to read.
function mosaic__preprocess_views_views_field_taxonomy_term_data_name(&$vars) {
  $tags = '';
  $found = FALSE;

  //dpm($vars);
  if (isset($_GET['tag'])) {
    $tags = $_GET['tag'];
    if ($tags && $tags != '') {
      $tags = filter_xss_admin(rawurldecode($tags));
      $tags = explode('+', $tags); // note: this has to come in as %2B from the url!

      $reset = array();
      foreach ($tags as $id => $tag) {
        if ($tag != $vars['output']) {
          $reset[] = $tag;
        }
        else {
          $found = TRUE;
        }
      }
      if (!$found) $reset[] = $vars['output']; // add this one too
      $tags = implode('+', $reset);
    }
  }
  else {
    $tags = $vars['output'];
  }

  // Popular question tags should point to the questions page
  $path = drupal_get_path_alias();
  if ($vars['view']->name == 'tags_popular' &&
      $vars['view']->current_display == 'popular_question_tags') {
    $path = 'content/questions-and-answers';
  }

  if ($vars['view']->name == 'tags_popular' &&
    $vars['view']->current_display == 'popular_snippet_tags') {
    $path = 'content/snippets';
  }

  if ($vars['view']->name == 'tags_popular' &&
    $vars['view']->current_display == 'popular_project_tags') {
    $path = 'content/coralnexus-projects';
  }

  // see also mosaic_tagclouds_weighted(&$vars) for info on encoding solr fields
  $class = 'tag-term';
  if ($found) $class = 'tag-active';

  if ($tags) {
    $vars['output'] = l($vars['output'], $path, array('query' => array('tag' => $tags), 'attributes' => array('class' => array($class))));
  }
  else {
    $vars['output'] = l($vars['output'], $path, array('attributes' => array('class' => array($class))));
  }

  return;
}


// Preprocess snippet component count field
function mosaic__preprocess_views_views_field_field_component_count_value(&$vars) {
  // Add component(s) text as necc.
  $vars['output'] = format_plural($vars['output'], '<span class="cnt">1</span> component', '<span class="cnt">@count</span> components');
}


// Preprocess the field locked field to present itself as an icon with hover text.
function mosaic_preprocess_field_locked(&$vars) {
  if ($vars['items'][0]['#markup'] == 'Lock') {
    $vars['items'][0]['#markup'] = '<span class="icon field-locked" title="Node editing locked">Node editing locked</span>';
  }
  else {
    $vars['items'][0]['#markup'] = ''; // show nothing if unlocked...
  }
}


// The documentation reference is basically a link from a
//  project page to a related documentation page that
//  talks about the project.
function mosaic_preprocess_field_documentation_reference(&$vars) {
  $node = $vars['element']['#object'];
  $doc_ref = field_get_items('node', $node, 'field_documentation_reference');

  if (isset($doc_ref[0]) && isset($doc_ref[0]['target_id'])) {
    $vars['items'][0]['#markup'] = '<span class="more">'.l('Learn more', 'node/'.$node->nid).'</span><span class="hide">'.$vars['items'][0]['#markup'].'</span>';
  }
}


// Preprocess project reference to display atomic units of the system path
function mosaic_preprocess_field_project_reference(&$vars) {
  $items = $vars['element']['#items'];
  foreach ($items as $indx => $item) {
    $node = $item['entity'];
    $user = user_load($node->uid);
    $user_link = theme('username', array('account' => $user));
    $proj_type = field_get_items('node', $node, 'field_project_type');
    if (isset($proj_type)) {
      $proj_type = strtolower(token_replace('[node:field_project_type]', array('node' => $node)));
      $title = l(strtolower(token_replace('[node:field_system_name]', array('node' => $node))), 'node/'.$node->nid);
    }
    $vars['items'][$indx]['#markup'] = $user_link.'<span class="mdgray">/</span><span class="strong mdgray">'.$proj_type.'</span><span class="mdgray">/</span>'.$title;
  }
}


// Point tags links to correct location (PORTAL-948)
function mosaic_preprocess_field_tags(&$vars) {
  $items = $vars['items'];
  $node  = $vars['element']['#object'];

  $tags = array();
  // fetch tags
  if (isset($_GET['tag'])) {
    $tags = $_GET['tag'];
    if ($tags && $tags != '') {
      $tags = filter_xss_admin(rawurldecode($tags));
      $tags = explode('+', $tags); // note: this has to come in as %2B from the url!
    }
  }

  // Book has no special page, use find
  if ($node->type == 'book') {
    foreach ($items as $indx => $item) {
      $tag = $item['#title'];
      $vars['items'][$indx]['#href'] = 'search/node/all';
      $vars['items'][$indx]['#options']['query'] = array('f' => array('type:book', rawurlencode('field_tags:name') . ":" . $tag));
    }
  }

  // Questions has its own page
  if ($node->type == 'question') {
    foreach ($items as $indx => $item) {
      $tag = $item['#title'];
      $t = implode('+', array_merge($tags, array($tag)));
      $vars['items'][$indx]['#href'] = 'content/questions-and-answers';
      $vars['items'][$indx]['#options']['query'] = array('tag' => $t);
    }
  }

  // Answers does not
  if ($node->type == 'answer') {
    foreach ($items as $indx => $item) {
      $tag = rawurldecode($item['#title']);
      $vars['items'][$indx]['#href'] = 'search/node/all';
      $vars['items'][$indx]['#options']['query'] = array('f' => array('type:answer', rawurlencode('field_tags:name') . ":" . $tag));
    }
  }

  // Comments does not - indeed comments do not show their tags though they are tagged
  if ($node->type == 'comment') {
    foreach ($items as $indx => $item) {
      $tag = rawurldecode($item['#title']);
      $vars['items'][$indx]['#href'] = 'search/node/all';
      $vars['items'][$indx]['#options']['query'] = array('f' => array('type:comment', rawurlencode('field_tags:name') . ":" . $tag));
    }
  }

  // Snippets does
  if ($node->type == 'snippet') {
    foreach ($items as $indx => $item) {
      $tag = $item['#title'];
      $t = implode('+', array_merge($tags, array($tag)));
      $vars['items'][$indx]['#href'] = 'content/snippets';
      $vars['items'][$indx]['#options']['query'] = array('tag' => $t);
    }
  }


  // Projects does
  if ($node->type == 'project') {
    foreach ($items as $indx => $item) {
      $tag = $item['#title'];
      $t = implode('+', array_merge($tags, array($tag)));
      $vars['items'][$indx]['#href'] = 'content/coralnexus-projects';
      $vars['items'][$indx]['#options']['query'] = array('tag' => $t);
    }
  }
}


function mosaic_preprocess_book_navigation(&$vars) {
  if ($vars['tree'] && $vars['has_links']) {
    $vars['tree_class'] = 'grid-16-last';
  }
  if ($vars['tree'] && !$vars['has_links']) {
    $vars['tree_class'] = 'grid-24-last';
  }

  if ($vars['tree'] && $vars['prev_url'] && $vars['next_url']) {
    $vars['btn_class'] = 'grid-4-last';
  }
  elseif ($vars['tree'] && ($vars['prev_url'] || $vars['next_url'])) {
    $vars['btn_class'] = 'grid-8-last';
  }
  elseif (!$vars['tree'] && $vars['prev_url'] && $vars['next_url']) {
    $vars['btn_class'] = 'grid-12-last';
  }
  else {
    $vars['btn_class'] = 'grid-24-last';
  }
}

// Compile a default user picture and link
function mosaic_preprocess_user_picture(&$vars) {
  $a0 = arg(0); $a1 = arg(1); $a2 = arg(2);

  $account = $vars['account'];
  $title = '';
  if (isset($account->name)) {
    $title = t('View profile of '.$account->name);
  }

  $styles = image_styles();
  if (isset($vars['image_style']) && array_key_exists($vars['image_style'], $styles)) {
    $image_style = $vars['image_style'];
  }

  if ($a0 == 'user') { // thumbnail (larger than normal)
    $image_style = (!isset($image_style)) ? 'thumbnail' : $image_style;
    $vars['user_picture'] = mosaic_compile_default_user_image($account->uid, $image_style, $title);
  }
  else {
    $image_style = (!isset($image_style)) ? 'user_thumb_small' : $image_style;
    $vars['user_picture'] = mosaic_compile_default_user_image($account->uid, $image_style, $title);
  }
}


// Compiles a user image
function mosaic_compile_default_user_image($user, $image_style, $title) {
  $uri = 'public://coraltechiconlg.png'; // default image

  if (is_numeric($user)) $user = user_load($user);
  if (is_object($user) && $user->uid) {
    if (isset($user->picture->uri)) {
      $uri = $user->picture->uri;
    }
  }

  return l(
    theme(
      'image_style',
      array(
        'style_name' => $image_style,
        'path' => $uri,
        'title' => $title
      )
    ),
    'user/'.$user->uid, // link path
    array('html' => 'true') // we have a pic
  );
}

// Compiles data about this view's query and puts it to the settings array
//  Settings key is [view_name]_[view_display]_[[view_arg]_[view_arg]...]
function mosaic_compile_views_query_data(&$vars) {

  // Views to exclude:
  //  Some views have a query alter running on them
  //  that impedes this feature's usefulness. For
  //  this reason lets exclude those views when we can.
  $exclude = array(); //array('questions');

  // Got views? - with queries!
  if (isset($vars['view']) && isset($vars['view']->query) && !in_array($vars['view']->name, $exclude)) {
    $view  = $vars['view'];

    $query = $vars['view']->query;

    $settings = array(); // empty settings for now
    if (isset($query->pager->total_items)) {
      $settings['total_items'] = $query->pager->total_items;
    }
    if (isset($query->pager->options['items_per_page'])) {
      $settings['limit'] = $query->pager->options['items_per_page'];
    }

    // Compile settings key
    $args = implode('_', $view->args);
    if ($args) $args = '_'.$args;     // key by passed argument
    else $args = '_'.$vars['dom_id']; //  or use the view dom id to differentiate instances when necc.

    $key = $view->name.'_'.$view->current_display.$args;

    // Add da settings
    drupal_add_js(array('mosaicViews' => array($key => $settings)), 'setting');
  }
}

// Add additional classes to the panelizer view mode tpl title classes
function mosaic_preprocess_panelizer_view_mode(&$vars) {
  if (isset($vars['element']['#entity_view_mode'])) {
    $element = $vars['element'];
    $node = $element['#node'];
    $data = $element['#entity_view_mode'];
    $type = $data['entity_type'];
    $bundle = $data['bundle'];
    $mode = $data['view_mode'];
//dpm($element);
    $vars['title_attributes_array']['class'][] = $bundle.'-'.$type.'-pane-title';
    $vars['title_attributes_array']['class'][] = $bundle.'-'.$type.'-'.$mode.'-pane-title';

    /*if ($bundle == 'project') {
      $uri = $element['field_logo']['#items'][0]['uri'];
      $image_style = 'project_logo_lg';
      $title = $vars['title'];
      $logo = theme(
        'image_style',
        array(
          'style_name' => $image_style,
          'path' => $uri,
          'title' => $title
        ));

      $vars['title'] = $logo . $vars['title'];
    }*/
  }
}


// The main "new" questions page as seen on q&a.
function _preprocess_view__questions__new_questions(&$vars) {
  $g = $_GET;
  $output = '';
  $reset_all = l('reset', $g['q'], array('attributes' => array('title' => t('Reset all'))));
  if (isset($g['tag'])) {
    $tags = $g['tag'];
    $tags = explode('+', $tags);

    $reset = array();
    $tag_links = array();
    $path = drupal_get_path_alias();

    // foreach tags
    foreach ($tags as $id => $tag) {
      $reset = array();
      // find the tags that ought to go into the new reset link
      foreach ($tags as $i => $t) {
        if ($t != $tag) {
          $reset[] = $t;
        }
      }
      if (count($tags) == 1) {
        $reset[] = '';
      }
      if (count($reset)) {
        // compile the link for this tag
        $r = implode('+', $reset);
        if ($r != '') {
          $tag_links[] = l($tag.'<small>(x)</small>', $path, array('attributes' => array('title' => t('Reset').' '.$tag), 'html' => TRUE, 'query' => array('tag' => $r)));
        }
        else {
          $tag_links[] = l($tag.'<small>(x)</small>', $path, array('attributes' => array('title' => t('Reset').' '.$tag), 'html' => TRUE));
        }
      }
    }
    $tag_links = implode(', ', $tag_links);

    // add a way for the user to see and reset the filtered tag
    $output .= '<div class="q-filtered-tag">';
    $output .= '<span class="filtered-by">'.t('filtered by: ').'<span class="ftag">'.$tag_links.'</span></span>';
    $output .= '<span class="reset-filter">'.$reset_all.'</span></div>';
    $vars['title'] = $output;
  }
}


// The main "new" snippets page views
function _preprocess_view__snippets__new_snippets(&$vars) {
  // we are simply using the same tag processing method from the questions view
  _preprocess_view__questions__new_questions($vars);
}


// Main projects view display
function _preprocess_view__project_listings__project_listings(&$vars) {
  _preprocess_view__questions__new_questions($vars);
}

/**
 * Process variables for user-profile.tpl.php.
 *
 * The $variables array contains the following arguments:
 * - $account
 *
 * @see user-profile.tpl.php
 */
function mosaic_preprocess_user_profile(&$variables) {
  $account = $variables['elements']['#account'];

  // Helpful $user_profile variable for templates.
  foreach (element_children($variables['elements']) as $key) {
    $variables['user_profile'][$key] = $variables['elements'][$key];
  }

  // Hide the user picture since we output it separately.
  hide($variables['user_profile']['user_picture']);

  // Hide the useless gigya site profile info...
  hide($variables['user_profile']['gigya']['site']);

  // Preprocess fields.
  field_attach_preprocess('user', $account, $variables['elements'], $variables);
}


// Determine possessiveness
function mosaic_possessive($name) {
  $last = substr($name, -1);

  // Add icon holder for the cloud Q's and get a decent prefix to the name
  if ($last === 's') {
    return $name."'";
  }
  else {
    return $name."'s";
  }
}


// Remove explicite height and width paramters on images
function mosaic_preprocess_image(&$variables) {
  foreach (array('width', 'height') as $key) {
    unset($variables[$key]);
  }
}
