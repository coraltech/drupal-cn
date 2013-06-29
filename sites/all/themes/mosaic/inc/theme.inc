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


/**
 * Theme the output of the Back to Top link.
 *
 * This way users can easily add an image instead of using the CSS
 * arrow up as we have in the module.
 *
 * @param $toc A TOC object with the options and levels.
 *
 * @return Rendered HTML to be displayed.
 */
function mosaic_tableofcontents_back_to_top($variables) {
  $toc = $variables['toc'];
  
  $label = check_plain($toc['back_to_top']['label']);
  $anchor = check_plain($toc['back_to_top']['anchor']);
  return "<div class='toc-back-to-top hide'><a href='#{$anchor}'><span>{$label}</span></a></div>";
}


/**
 * Theme the output of a table of contents.
 *
 * @param $toc A TOC object with the options, table of contents, headers, and files.
 *
 * @return Rendered HTML to be displayed.
 */
function mosaic_tableofcontents_toc($variables) {
  $toc = $variables['toc'];

  // This stuff allows us to find the various toc on the front end
  //  Add the toc to Drupal.settings.mosaicToc so we can read it
  if (isset($toc['header']['h'][0]->ident)) {
    $first_title_id = $toc['header']['h'][0]->ident;
    $settings = array('mosaic' => array('tocDefaults' => array($first_title_id => $toc)));
    drupal_add_js($settings, 'setting');
  }  
  
  // Escape adding the toc if we are below the min limit
  if (!isset($toc['header']['h'])) $toc['header']['h'] = array();
  if ((int)$toc['on_off']['min_limit'] > count($toc['header']['h'])) return '';
  
  // TODO: we should only define the id="toc" for the first TOC
  if ($toc['back_to_top']['anchor']) {
    $id = ' id="' . check_plain($toc['back_to_top']['anchor']) . '"';
  }
  else {
    $id = '';
  }
  $output = "<div{$id} class='toc'>\n";
  if ($toc['box']['title'] != '<none>') {
    // TODO: at this time, the hideshow works with all TOCs at once
    $hs = ($toc['box']['hide_show']) ? '<span class="toc-toggle-message">&nbsp;</span>' : '';
    $output .= "<div class='toc-title'>" . t($toc['box']['title']) . $hs . "</div>\n";
  }

  $list = $toc['numbering']['method'] == 4 ? 'ol' : 'ul';
  $output .= "<div class='toc-list'>\n<$list>\n";

  $has_content = FALSE;

  // Process nested lists.
  $level = $toc['box']['minlevel'];
  if (!isset($toc['header']['h'])) {
    $toc['header']['h'] = array();
  }
  foreach ($toc['header']['h'] as $index => $h) {

    $cur_level = $h->level;
    if ($cur_level >= $toc['box']['minlevel'] && $cur_level <= $toc['box']['maxlevel']) {
      $has_content = TRUE;

      // Be sure to deal with skipping between non-adjacent h levels.
      if ($cur_level > $level) {
        do {
          $output .= "\n<" . $list . ">\n";
          ++$level;
        } while ($cur_level > $level);
      }
      elseif ($cur_level < $level) {
        do {
          $output .= "</li>\n</" . $list . ">\n";
          --$level;
        } while ($cur_level < $level);
        $output .= "</li>\n";
      }
      elseif ($index != 0) { // we know that $cur_level == $level here
        // Close list items at the same level (except the very first time)
        $output .= "</li>\n";
      }

      if ($h->number) {
        $number = '<span class="toc-number">' . $h->number . '</span>';
      }
      else {
        $number = '';
      }
      $list_class = 'toc-level-' . ($level - $toc['box']['minlevel'] + 1);

      $title = strip_tags($h->title, $toc['header']['allowed']);

      // insert the li element
      $output .= "\t<li class=\"$list_class\">";
      $output .= "<a href=\"#" . $h->ident . "\">" . $number . $title . "</a>";
    }
  }
  // Did we recurse back out? If not, close open lists.
  for (; $level > $toc['box']['minlevel']; --$level) {
    $output .= "</li>\n</" . $list . ">\n";
  }
  $output .= "</li>\n";

  if (!$has_content) {
    // this happens when all the header levels are either too small or too large
    // and if there is no attachment either
    return '';
  }

  $output .= "</" . $list . ">\n</div>\n</div>";

  return theme('tableofcontents_toc_text', array('toc' => $toc, 'output' => $output));
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