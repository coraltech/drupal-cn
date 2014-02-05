<?php

/**
 * Custom plugin to provide question form on wiki pages.
 *  Wiki questions will be stored in the 
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Coral wiki question form'),
  'description' => t("Question form that is preconfigured to reference the wiki page where it was created."),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node')
  ),
  'category' => t('Coral'),
  'edit form' => 'coral_wiki_questions_pane_content_type_edit_form',    // Edit form callback
  'render callback'  => 'coral_wiki_questions_pane_content_type_render',
  //'defaults' => array('anon_links' => false),
);


/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function coral_wiki_questions_pane_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  global $user;
  
  $button = '<span class="ask-btn">Have a question<span class="icon"></span></span>';
  
  if (!$user->uid) {
    $user_login = render(drupal_get_form('user_login'));
    $question_form = '<h3>Please login or '.l('register', 'user/register')." to ask questions.</h3>";
    $question_form .= $user_login;
  }
  else {
    $node = (object) array('uid' => $user->uid, 'name' => (isset($user->name) ? $user->name : ''), 'type' => 'question', 'language' => LANGUAGE_NONE);
    $form_state['build_info']['args'] = array($node);

    form_load_include($form_state, 'inc', 'node', 'node.pages');
    $question_form = drupal_build_form('question_node_form', $form_state);
    $node = $context[0]->data; // get node from context
    
    if (isset($node->field_tags) && count($node->field_tags) > 0) { // has tags?
      $wiki_tags = field_get_items('node', $node, 'field_tags', LANGUAGE_NONE);
      $tids = array(); // holds wiki doc tids for lookup later
      $term_str = array();

      if (count($wiki_tags) > 0) {
        foreach ($wiki_tags as $id => $tid) { $tids[] = $tid['tid']; } // add to register
        $terms = taxonomy_term_load_multiple($tids); // load tags
        foreach ($terms as $tid => $term) { // compile list
          $term_str[] = $term->name; // list item
        }
        // Set question terms to start with those of the book page
        $question_form['field_tags'][LANGUAGE_NONE]['#value'] = implode(', ', $term_str); // set items
      }
    }
  }
  $block->title = t('Wiki questions');
  $block->content = $button . '<div class="wiki-ask-question hide">'.render($question_form).'</div>';
  return $block; 
}


// Admin title
function coral_wiki_questions_pane_content_type_admin_title($subtype, $conf, $context) {
  return t('Wiki page question form');
}


/**
* 'Edit form' callback for the content type.
* 
* Currently un-called... no edit form needed most of the time.
*/
function coral_wiki_questions_pane_content_type_edit_form($form, &$form_state) {
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
function coral_wiki_questions_pane_content_type_edit_form_submit($form, &$form_state) {
  // Values have to be moved to conf or they won't be there when you get back bon hommie!
  //$form_state['conf']['field'] = $form_state['values']['field'];
}
