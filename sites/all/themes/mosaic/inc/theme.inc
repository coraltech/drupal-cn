<?php

/**
 * Returns HTML for a menu link and submenu.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: Structured array data for a menu link.
 *
 * @ingroup themeable
 */
function mosaic_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}


/**
 * Returns HTML for a wrapper for a menu sub-tree.
 *
 * @param $variables
 *   An associative array containing:
 *   - tree: An HTML string containing the tree's items.
 *
 * @see template_preprocess_menu_tree()
 * @ingroup themeable
 */
function mosaic_menu_tree($variables) {
  return '<ul class="menu">' . $variables['tree'] . '</ul>';
}


/**
 * Returns HTML for a breadcrumb trail.
 *
 * @param $variables
 *   An associative array containing:
 *   - breadcrumb: An array containing the breadcrumb links.
 */
function mosaic_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    return '<span class="breadcrumb">' . implode(' » ', $breadcrumb) . '</span>';
  }
}


function mosaic_filter_tips($variables) {
  $tips = $variables['tips'];
  $long = $variables['long'];
  $output = '';

  $multiple = count($tips) > 1;
  if ($multiple) {
    $output = '<h2>' . t('Text Formats') . '</h2>';
  }

  if (count($tips)) {
    if ($multiple) {
      $output .= '<div class="compose-tips">';
    }
    foreach ($tips as $name => $tiplist) {
      if ($multiple) {
        $output .= '<div class="filter-type filter-' . drupal_html_class($name) . '">';
        $output .= '<h3>' . $name . '</h3>';
      }

      if (count($tiplist) > 0) {
        $output .= '<ul class="tips">';
        foreach ($tiplist as $tip) {
          // filter the toc tip out... toc added automatically
          
          if($tip['id'] == 'filter_toc') $tip['tip'] = t('Tables of contents will be added automatically.'); 
          if($tip['id'] == 'Mediawiki Format') { 
            $tip['tip'] = t('You may use the Wikimedia format: see:').
                            l('Wikimedia formatting help', 'http://www.mediawiki.org/wiki/Help:Formatting', 
                            array('attributes' => array('target' => '_blank'))); 
          }
          $output .= '<li' . ($long ? ' id="filter-' . str_replace("/", "-", $tip['id']) . '">' : '>') . $tip['tip'] . '</li>';
        }
        $output .= '</ul>';
      }

      if ($multiple) {
        $output .= '</div>';
      }
    }
    if ($multiple) {
      $output .= '</div>';
    }
  }

  return $output;
}


/**
 * Helper function that builds the nested lists of a Superfish menu.
 */
function mosaic_superfish_build($variables) {
  $output = array('content' => '');
  $id = $variables['id'];
  $menu = $variables['menu'];
  $depth = $variables['depth'];
  $trail = $variables['trail'];
  // Keep $sfsettings untouched as we need to pass it to the child menus.
  $settings = $sfsettings = $variables['sfsettings'];
  $megamenu = $settings['megamenu'];
  $total_children = $parent_children = $single_children = 0;
  $i = 1;

  // Reckon the total number of available menu items.
  foreach ($menu as $menu_item) {
    if (!isset($menu_item['link']['hidden']) || $menu_item['link']['hidden'] == 0) {
      $total_children++;
    }
  }

  foreach ($menu as $menu_item) {

    $show_children = $megamenu_wrapper = $megamenu_column = $megamenu_content = FALSE;
    $item_class = $link_options = $link_class = array();
    $mlid = $menu_item['link']['mlid'];
  
    if (!isset($menu_item['link']['hidden']) || $menu_item['link']['hidden'] == 0) {
      $item_class[] = ($trail && in_array($mlid, $trail)) ? 'active-trail' : '';

      // Add helper classes to the menu items and hyperlinks.
      $settings['firstlast'] = ($settings['dfirstlast'] == 1 && $total_children == 1) ? 0 : $settings['firstlast'];
      $item_class[] = ($settings['firstlast'] == 1) ? (($i == 1) ? 'first' : (($i == $total_children) ? 'last' : 'middle')) : '';
      $settings['zebra'] = ($settings['dzebra'] == 1 && $total_children == 1) ? 0 : $settings['zebra'];
      $item_class[] = ($settings['zebra'] == 1) ? (($i % 2) ? 'odd' : 'even') : '';
      $item_class[] = ($settings['itemcount'] == 1) ? 'sf-item-' . $i : '';
      $item_class[] = ($settings['itemdepth'] == 1) ? 'sf-depth-' . $menu_item['link']['depth'] : '';
      $link_class[] = ($settings['itemdepth'] == 1) ? 'sf-depth-' . $menu_item['link']['depth'] : '';
      $item_class[] = ($settings['liclass']) ? $settings['liclass'] : '';
      if (strpos($settings['hlclass'], ' ')) {
        $l = explode(' ', $settings['hlclass']);
        foreach ($l as $c) {
          $link_class[] = $c;
        }
      }
      else {
        $link_class[] = $settings['hlclass'];
      }
      $i++;

      // Add hyperlinks description (title) to their text.
      $show_linkdescription = ($settings['linkdescription'] == 1 && !empty($menu_item['link']['localized_options']['attributes']['title'])) ? TRUE : FALSE;
      if ($show_linkdescription) {
        if (!empty($settings['hldmenus'])) {
          $show_linkdescription = (is_array($settings['hldmenus'])) ? ((in_array($mlid, $settings['hldmenus'])) ? TRUE : FALSE) : (($mlid == $settings['hldmenus']) ? TRUE : FALSE);
        }
        if (!empty($settings['hldexclude'])) {
          $show_linkdescription = (is_array($settings['hldexclude'])) ? ((in_array($mlid, $settings['hldexclude'])) ? FALSE : $show_linkdescription) : (($settings['hldexclude'] == $mlid) ? FALSE : $show_linkdescription);
        }
        if ($show_linkdescription) {
          $menu_item['link']['title'] .= '<span class="sf-description">';
          $menu_item['link']['title'] .= (!empty($menu_item['link']['localized_options']['attributes']['title'])) ? $menu_item['link']['localized_options']['attributes']['title'] : array();
          $menu_item['link']['title'] .= '</span>';
          $link_options['html'] = TRUE;
        }
      }

      // Add custom HTML codes around the menu items.
      if ($sfsettings['wrapul'] && strpos($sfsettings['wrapul'], ',') !== FALSE) {
        $wul = explode(',', $sfsettings['wrapul']);
        // In case you just wanted to add something after the element.
        if (drupal_substr($sfsettings['wrapul'], 0) == ',') {
          array_unshift($wul, '');
        }
      }
      else {
        $wul = array();
      }

      // Add custom HTML codes around the hyperlinks.
      if ($settings['wraphl'] && strpos($settings['wraphl'], ',') !== FALSE) {
        $whl = explode(',', $settings['wraphl']);
        // The same as above
        if (drupal_substr($settings['wraphl'], 0) == ',') {
          array_unshift($whl, '');
        }
      }
      else {
        $whl = array();
      }

      // Add custom HTML codes around the hyperlinks text.
      if ($settings['wraphlt'] && strpos($settings['wraphlt'], ',') !== FALSE) {
        $whlt = explode(',', $settings['wraphlt']);
        // The same as above
        if (drupal_substr($settings['wraphlt'], 0) == ',') {
          array_unshift($whlt, '');
        }
        $menu_item['link']['title'] = $whlt[0] . check_plain($menu_item['link']['title']) . $whlt[1];
        $link_options['html'] = TRUE;
      }


      if (!empty($menu_item['link']['has_children']) && !empty($menu_item['below']) && $depth != 0) {
        // Megamenu is still beta, there is a good chance much of this will be changed.
        if (!empty($settings['megamenu_exclude'])) {
          if (is_array($settings['megamenu_exclude'])) {
            $megamenu = (in_array($mlid, $settings['megamenu_exclude'])) ? 0 : $megamenu;
          }
          else {
            $megamenu = ($settings['megamenu_exclude'] == $mlid) ? 0 : $megamenu;
          }
          // Send the result to the sub-menu.
          $sfsettings['megamenu'] = $megamenu;
        }
        if ($megamenu == 1) {
          $megamenu_wrapper = ($menu_item['link']['depth'] == $settings['megamenu_depth']) ? TRUE : FALSE;
          $megamenu_column = ($menu_item['link']['depth'] == $settings['megamenu_depth'] + 1) ? TRUE : FALSE;
          $megamenu_content = ($menu_item['link']['depth'] >= $settings['megamenu_depth'] && $menu_item['link']['depth'] <= $settings['megamenu_levels']) ? TRUE : FALSE;
        }
        // Render the sub-menu.
        $var = array(
          'id' => $id,
          'menu' => $menu_item['below'],
          'depth' => $depth, 'trail' => $trail,
          'sfsettings' => $sfsettings
        );
        $children = theme('superfish_build', $var);
        // Check to see whether it should be displayed.
        $show_children = (($menu_item['link']['depth'] <= $depth || $depth == -1) && $children['content']) ? TRUE : FALSE;
        if ($show_children) {
          // Add item counter classes.
          if ($settings['itemcounter']) {
            $item_class[] = 'sf-total-children-' . $children['total_children'];
            $item_class[] = 'sf-parent-children-' . $children['parent_children'];
            $item_class[] = 'sf-single-children-' . $children['single_children'];
          }
          // More helper classes.
          $item_class[] = ($megamenu_column) ? 'sf-megamenu-column' : '';
          $item_class[] = $link_class[] = 'menuparent';
        }
        $parent_children++;
      }
      else {
        $item_class[] = 'sf-no-children';
        $single_children++;
      }

      $item_class = implode(' ', array_filter($item_class));
      
      if (isset($menu_item['link']['localized_options']['attributes']['class'])) {
        $link_class_current = $menu_item['link']['localized_options']['attributes']['class'];
        $link_class = array_merge($link_class_current, array_filter($link_class));
      }
      $menu_item['link']['localized_options']['attributes']['class'] = $link_class;
 
      $link_options['attributes'] = $menu_item['link']['localized_options']['attributes'];
      $link_options['html'] = TRUE;
      
      // Render the menu item.
      $output['content'] .= '<li id="menu-' . $mlid . '-' . $id . '"';
      $output['content'] .= ($item_class) ? ' class="' . trim($item_class) . '">' : '>';
      $output['content'] .= ($megamenu_column) ? '<div class="sf-megamenu-column">' : '';
      $output['content'] .= isset($whl[0]) ? $whl[0] : '';
      $output['content'] .= l($menu_item['link']['title'].'<span class="arrow"></span>', $menu_item['link']['link_path'], $link_options);
      $output['content'] .= isset($whl[1]) ? $whl[1] : '';
      $output['content'] .= ($megamenu_wrapper) ? '<ul class="sf-megamenu"><li class="sf-megamenu-wrapper ' . $item_class . '">' : '';
      $output['content'] .= ($show_children) ? (isset($wul[0]) ? $wul[0] : '') : '';
      $output['content'] .= ($show_children) ? (($megamenu_content) ? '<ol>' : '<ul>') : '';
      $output['content'] .= ($show_children) ? $children['content'] : '';
      $output['content'] .= ($show_children) ? (($megamenu_content) ? '</ol>' : '</ul>') : '';
      $output['content'] .= ($show_children) ? (isset($wul[1]) ? $wul[1] : '') : '';
      $output['content'] .= ($megamenu_wrapper) ? '</li></ul>' : '';
      $output['content'] .= ($megamenu_column) ? '</div>' : '';
      $output['content'] .= '</li>';
    }
  }
  $output['total_children'] = $total_children;
  $output['parent_children'] = $parent_children;
  $output['single_children'] = $single_children;
  return $output;
}


/**
 * Theme function that renders the HTML for the tags.
 *
 * @ingroup themable
 */
function mosaic_tagclouds_weighted(&$vars) {
  $terms = $vars['terms'];

  $output = '';
  $display = variable_get('tagclouds_display_type', 'style');

  if (module_exists('i18n_taxonomy')) {
    $language = i18n_language();
  }

  if ($display=='style') {
    foreach ($terms as $term) {
      if (module_exists('i18n_taxonomy')) {
        $term_name = i18n_taxonomy_term_name($term, $language->language);
        $term_desc = tagclouds_i18n_taxonomy_term_description($term, $language->language);
      } else {
        $term_name = $term->name;
        $term_desc = $term->description;
      }
      
      $tag = filter_xss_admin($term_name);
      $attributes = array('title' => $term_desc, 'class' => array('tagclouds', 'level'.$term->weight));
      $query = array('f' => array(rawurlencode('field_tags:name') . ":" . $tag));
      $link = "<span class='tagclouds-term'>".l(
        $tag,
        'search/node/all', 
        array(
          'attributes' => $attributes,
          'query' => $query
        )
      )."</span>\n";
      $output .= $link;
    }
  }
  // @TODO: Ensure links this section makes point to the find page too vvv
  else {
    foreach ($terms as $term) {
      if (module_exists('i18n_taxonomy')) {
        $term_name = i18n_taxonomy_term_name($term, $language->language);
        $term_desc = tagclouds_i18n_taxonomy_term_description($term, $language->language);
      } else {
        $term_name = $term->name;
        $term_desc = $term->description;
      }
      if ($term->count==1 && variable_get("tagclouds_display_node_link", false)) {
        
        $output .= tagclouds_display_node_link_count($term_name, $term->tid, $term->nid, $term->count, $term_desc);
      }
      else {
        
        $output .= tagclouds_display_term_link_count($term_name, $term->tid, $term->count, $term_desc);
      }
    }
  }
  return $output;
}


/**
 * Returns HTML for help text based on file upload validators.
 *
 * @param $variables
 *   An associative array containing:
 *   - description: The normal description for this field, specified by the
 *     user.
 *   - upload_validators: An array of upload validators as used in
 *     $element['#upload_validators'].
 *
 * @ingroup themeable
 */
function mosaic_file_upload_help($variables) {
  $description = $variables['description'];
  $upload_validators = $variables['upload_validators'];

  $descriptions = array();

  if (strlen($description)) {
    $descriptions[] = '<span class="br">'.$description.'</span>';
  }
  if (isset($upload_validators['file_validate_size'])) {
    $descriptions[] = '<span class="br">'.t('Files must be less than !size.', array('!size' => '<strong>' . format_size($upload_validators['file_validate_size'][0]) . '</strong>')).'</span>';
  }
  if (isset($upload_validators['file_validate_extensions'])) {
    $descriptions[] = '<span class="br">'.t('Allowed file types: !extensions.', array('!extensions' => '<strong>' . check_plain($upload_validators['file_validate_extensions'][0]) . '</strong>')).'</span>';
  }
  if (isset($upload_validators['file_validate_image_resolution'])) {
    $max = $upload_validators['file_validate_image_resolution'][0];
    $min = $upload_validators['file_validate_image_resolution'][1];
    if ($min && $max && $min == $max) {
      $descriptions[] = '<span class="br">'.t('Images must be exactly !size pixels.', array('!size' => '<strong>' . $max . '</strong>')).'</span>';
    }
    elseif ($min && $max) {
      $descriptions[] = '<span class="br">'.t('Images must be between !min and !max pixels.', array('!min' => '<strong>' . $min . '</strong>', '!max' => '<strong>' . $max . '</strong>')).'</span>';
    }
    elseif ($min) {
      $descriptions[] = '<span class="br">'.t('Images must be larger than !min pixels.', array('!min' => '<strong>' . $min . '</strong>')).'</span>';
    }
    elseif ($max) {
      $descriptions[] = '<span class="br">'.t('Images must be smaller than !max pixels.', array('!max' => '<strong>' . $max . '</strong>')).'</span>';
    }
  }

  return implode("\n",$descriptions);
}


function mosaic_views_load_more_pager($vars) {
  global $pager_page_array, $pager_total;

  drupal_add_js(drupal_get_path('module', 'views_load_more').'/views_load_more.js');

  $tags = $vars['tags'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];

  $li_next = theme('pager_next',
    array(
      'text' => (isset($tags[3]) ? $tags[3] : t($vars['more_button_text'])),
      'element' => $element,
      'interval' => 1,
      'parameters' => $parameters,
    )
  );
  if (empty($li_next)) {
    $li_next = "";
  }

  if ($pager_total[$element] > 1) {
    $items[] = array(
      'class' => array('pager-next'),
      'data' => $li_next,
    );
    return theme('item_list',
      array(
        'items' => $items,
        'title' => NULL,
        'type' => 'ul',
        'attributes' => array('class' => array('pager', 'pager-load-more')),
      )
    );
  }
}

/**
 * Returns HTML for primary and secondary local tasks.
 *
 * @param $variables
 *   An associative array containing:
 *     - primary: (optional) An array of local tasks (tabs).
 *     - secondary: (optional) An array of local tasks (tabs).
 *
 * @ingroup themeable
 * @see menu_local_tasks()
 */
function mosaic_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs primary">';
    $variables['primary']['#suffix'] = '</ul><span class="icon icoprim"></span>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs secondary">';
    $variables['secondary']['#suffix'] = '</ul><span class="icon icosec"></span>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}


/**
 * Returns HTML for a set of links.
 *
 * @param $variables
 *   An associative array containing:
 *   - links: An associative array of links to be themed. The key for each link
 *     is used as its CSS class. Each link should be itself an array, with the
 *     following elements:
 *     - title: The link text.
 *     - href: The link URL. If omitted, the 'title' is shown as a plain text
 *       item in the links list.
 *     - html: (optional) Whether or not 'title' is HTML. If set, the title
 *       will not be passed through check_plain().
 *     - attributes: (optional) Attributes for the anchor, or for the <span>
 *       tag used in its place if no 'href' is supplied. If element 'class' is
 *       included, it must be an array of one or more class names.
 *     If the 'href' element is supplied, the entire link array is passed to
 *     l() as its $options parameter.
 *   - attributes: A keyed array of attributes for the UL containing the
 *     list of links.
 *   - heading: (optional) A heading to precede the links. May be an
 *     associative array or a string. If it's an array, it can have the
 *     following elements:
 *     - text: The heading text.
 *     - level: The heading level (e.g. 'h2', 'h3').
 *     - class: (optional) An array of the CSS classes for the heading.
 *     When using a string it will be used as the text of the heading and the
 *     level will default to 'h2'. Headings should be used on navigation menus
 *     and any list of links that consistently appears on multiple pages. To
 *     make the heading invisible use the 'element-invisible' CSS class. Do not
 *     use 'display:none', which removes it from screen-readers and assistive
 *     technology. Headings allow screen-reader and keyboard only users to
 *     navigate to or skip the links. See
 *     http://juicystudio.com/article/screen-readers-display-none.php and
 *     http://www.w3.org/TR/WCAG-TECHS/H42.html for more information.
 */
function mosaic_links($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  global $language_url;
  $output = '';

  if (count($links) > 0) {
    $output = '';

    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading.
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $output .= '<ul' . drupal_attributes($attributes) . '>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = array($key);

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class[] = 'first';
      }
      if ($i == $num_links) {
        $class[] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
          && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $class[] = 'active';
      }
      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

      if (isset($link['href'])) {
        // We need html input to get icon spans.  
        if (!isset($link['html']) || !$link['html']) $link['html'] = TRUE;
        
        // Pass in $link as $options, they share the same keys.
        $output .= l('<span class="icon"></span>'.$link['title'], $link['href'], $link);
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }

      $i++;
      $output .= "</li>";
    }

    $output .= '</ul>';
  }

  return $output;
}


/**
 * Returns HTML for an inactive facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @see l()
 *
 * @ingroup themeable
 */
function mosaic_facetapi_link_active($variables) {

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Theme function variables fro accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );

  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_deactivate_widget' => theme('facetapi_deactivate_widget', $variables),
    '!facetapi_accessible_markup' => theme('facetapi_accessible_markup', $accessible_vars),
  );
  $variables['text'] = t('!facetapi_deactivate_widget !facetapi_accessible_markup', $replacements);
  $variables['options']['html'] = TRUE;
  return theme_link($variables) . '<span class="lnktxt">'.$link_text.'</span>';
}

function mosaic_facetapi_deactivate_widget(&$vars) {
  return '(<span class="mdred">x</span>) ';
}

