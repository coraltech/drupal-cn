<?php

/**
 * Implements hook_theme().
 */
function coral_table_theme() {
  return array(
    'coral_table' => array(
      'render element' => 'elements',
    ),
  );
}

/**
 * Implements hook_element_info().
 */
function coral_table_element_info() {
  return array(
    'coral_table' => array(
      '#pre_render' => array('coral_table_pre_render'),
      '#theme'      => 'coral_table',      
      '#regions'    => array('' => array()),
    ),
  );
}

/**
 * Pre-render callback for coral_table elements.
 */
function coral_table_pre_render($elements) {
  $js_settings = array();

  // For each region, build the tree structure from the weight and parenting
  // data contained in the flat form structure, to determine row order and
  // indentation.
  $regions = $elements['#regions'];
  $tree    = array('' => array('name' => '', 'children' => array()));
  $trees   = array_fill_keys(array_keys($regions), $tree);

  $parents = array();
  $list    = drupal_map_assoc(element_children($elements));

  // Iterate on rows until we can build a known tree path for all of them.
  while ($list) {
    foreach ($list as $name) {
      $row = &$elements[$name];
      
      if (isset($row['parent_wrapper'])) {
        $parent = $row['parent_wrapper']['parent']['#value'];
      }
      elseif (isset($row['parent'])) {
        $parent = $row['parent']['#value'];
      }
      else {
        $parent = array();
      }
      
      // Proceed if parent is known.
      if (empty($parent) || isset($parents[$parent])) {
        // Grab parent, and remove the row from the next iteration.
        $parents[$name] = $parent ? array_merge($parents[$parent], array($parent)) : array();
        unset($list[$name]);

        // Determine the region for the row.
        $region_name = $row['#region'];

        // Add the element in the tree.
        $target = &$trees[$region_name][''];
        foreach ($parents[$name] as $key) {
          $target = &$target['children'][$key];
        }
        $target['children'][$name] = array('name' => $name, 'weight' => $row['_weight']['#value']);

        // Add tabledrag indentation to the first row cell.
        if ($depth = count($parents[$name])) {
          $children = element_children($row);
          $cell     = current($children);
          $row[$cell]['#prefix'] = theme('indentation', array('size' => $depth)) . (isset($row[$cell]['#prefix']) ? $row[$cell]['#prefix'] : '');
        }

        // Add row id and associate JS settings.
        $id = drupal_html_class($name);
        $row['#attributes']['id'] = $id;
        if (isset($row['#js_settings'])) {
          $row['#js_settings'] += array(
            'name'   => $name,
            'region' => $region_name,
          );
          $js_settings[$id] = $row['#js_settings'];
        }
      }
    }
  }
  // Determine rendering order from the tree structure.
  foreach ($regions as $region_name => $region) {
    $elements['#regions'][$region_name]['rows_order'] = array_reduce($trees[$region_name], '_coral_reduce_order');
  }

  $elements['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => array('coralTableRowData' => $js_settings),
  );

  return $elements;
}

/**
 * Returns HTML for Coral tables.
 *
 * @param $variables
 *   An associative array containing:
 *   - elements: An associative array containing a Form API structure to be
 *     rendered as a table.
 *
 * @ingroup themeable
 */
function theme_coral_table($variables) {
  $elements    = $variables['elements'];
  $table       = array();
  $js_settings = array();

  // Add table headers and attributes.
  foreach (array('header', 'attributes') as $key) {
    if (isset($elements["#$key"])) {
      $table[$key] = $elements["#$key"];
    }
  }

  // Determine the colspan to use for region rows, by checking the number of
  // columns in the headers.
  $columns_count = 0;
  foreach ($table['header'] as $header) {
    $columns_count += (is_array($header) && isset($header['colspan']) ? $header['colspan'] : 1);
  }

  // Render rows, region by region.
  foreach ($elements['#regions'] as $region_name => $region) {
    $region_name_class = drupal_html_class($region_name);

    // Add region rows.
    if (isset($region['title'])) {
      $table['rows'][] = array(
        'class' => array('region-title', 'region-' . $region_name_class . '-title'),
        'no_striping' => TRUE,
        'data' => array(
          array('data' => $region['title'], 'colspan' => $columns_count),
        ),
      );
    }
    if (isset($region['message'])) {
      $class = (empty($region['rows_order']) ? 'region-empty' : 'region-populated');
      $table['rows'][] = array(
        'class' => array('region-message', 'region-' . $region_name_class . '-message', $class),
        'no_striping' => TRUE,
        'data' => array(
          array('data' => $region['message'], 'colspan' => $columns_count),
        ),
      );
    }

    // Add form rows, in the order determined at pre-render time.
    foreach ($region['rows_order'] as $name) {
      $element = $elements[$name];

      $row = array('data' => array());
      if (isset($element['#attributes'])) {
        $row += $element['#attributes'];
      }

      // Render children as table cells.
      foreach (element_children($element) as $cell_key) {
        $child = &$element[$cell_key];
        // Do not render a cell for children of #type 'value'.
        if (!(isset($child['#type']) && $child['#type'] == 'value')) {
          $cell = array('data' => drupal_render($child));
          if (isset($child['#cell_attributes'])) {
            $cell += $child['#cell_attributes'];
          }
          $row['data'][] = $cell;
        }
      }
      $table['rows'][] = $row;
    }
  }

  return theme('table', $table);
}

/**
 * Determines the rendering order of an array representing a tree.
 *
 * Callback for array_reduce() within coral_table_pre_render().
 */
function _coral_reduce_order($array, $a) {
  $array = !isset($array) ? array() : $array;
  if ($a['name']) {
    $array[] = $a['name'];
  }
  if (!empty($a['children'])) {
    uasort($a['children'], 'drupal_sort_weight');
    $array = array_merge($array, array_reduce($a['children'], '_coral_reduce_order'));
  }
  return $array;
}


