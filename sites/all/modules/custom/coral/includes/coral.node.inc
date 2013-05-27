<?php

//------------------------------------------------------------------------------
// Nodes

/**
 * Return a list of the Coral node classes.
 */
function coral_node_classes() {
  return array(
    'node' => array(
      CoralFormatNode::type() => 'CoralFormatNode',
      CoralConfigNode::type() => 'CoralConfigNode'
    )
  );
}

/**
 * Ensures a Coral class is instantiated of a certain type for a given node.
 */
function coral_node_ensure(&$node) {
  $class = coral_class('node', $node->type);
  Coral::ensure($node, 'coral', $class, $node);
}

/**
 * Syncronize all coralized node class fields.
 */
function coral_node_field_update($type = NULL) {
  if (is_null($type)) {
    $class_map = coral_classes('node');
  }
  else {
    $class_map = array($type => coral_class('node', $type));
  }
  
  foreach ($class_map as $node_type => $class) {
    // Create all the fields we are adding to our content type.
    foreach (Coral::exec($class, 'fields', array(), array()) as $name => $field) {
      $field['field_name'] = $name;
      $exists = field_info_field($name);
      if (empty($exists)) {
        field_create_field($field);
      }
    }
    // Create all the instances for our fields.
    foreach (Coral::exec($class, 'fieldInstances', array(), array()) as $name => $instance) {
      $exists = field_info_instance('node', $name, $node_type);
      if (empty($exists)) {
        $instance['field_name']  = $name;
        $instance['entity_type'] = 'node';
        $instance['bundle']      = $node_type;
        field_create_instance($instance);
      }
    }
  }  
}

/**
 * Implements hook_permission().
 */
function coral_node_permission() {
  $perms = array();
  foreach (node_permissions_get_configured_types() as $type) {
    if ($class = coral_class('node', $type)) {
      $perms += Coral::exec($class, 'permissions', array(), array());
    }
  }
  return $perms;
}

/**
 * Implements hook_theme().
 */
function coral_node_theme() {
  $themes = array();
  foreach (coral_classes('node') as $type => $class) {
    $themes += Coral::exec($class, 'theme', array(), array());
  }
  return $themes;
}

/**
 * Implements hook_entity_info_alter().
 */
function coral_node_entity_info_alter(&$entity_info) {
  if (!isset($entity_info['node'])) {
    $entity_info['node'] = array();
  }
  foreach (coral_classes('node') as $type => $class) {
    Coral::exec($class, 'entityInfo', array(&$entity_info['node']));
  }
}

/**
 * Implements hook_node_info().
 */
function coral_node_info() {
  $results = array();
  foreach (coral_classes('node') as $type => $class) {
    $results[$type] = Coral::exec($class, 'info', array(), array());
    if (!empty($results[$type]) && Coral::isHash($results[$type])) {
      $results[$type] = $results[$type] + array('base' => 'coral_node_class');
    }
  }
  return $results;
}

/**
 * Implements hook_node_type_insert().
 */
function coral_node_type_insert($content_type) {
  $type = $content_type->type;
  if ($class = coral_class('node', $type)) {
    coral_node_field_update($type);
    Coral::exec($class, 'insertType', array($content_type));
  }
}

/**
 * Implements hook_node_access().
 */
function coral_node_access($node, $op, $account) {
  $type   = is_string($node) ? $node : $node->type;
  $result = NODE_ACCESS_IGNORE;

  if (in_array($type, node_permissions_get_configured_types())) {
    if ($class = coral_class('node', $type)) {
      switch ($op) {
        case 'create':
          $result = Coral::exec($class, 'canCreate', array($account), NODE_ACCESS_IGNORE);
          break;
          
        case 'update':
          if (is_object($node)) {
            coral_node_ensure($node);
            $result = Coral::exec($node->coral, 'canEdit', array($account), NODE_ACCESS_IGNORE);
          }
          break;
        
        case 'delete':
          if (is_object($node)) {
            coral_node_ensure($node);
            $result = Coral::exec($node->coral, 'canDelete', array($account), NODE_ACCESS_IGNORE);
          }
          break;
        
        case 'view':
          if (is_object($node)) {
            coral_node_ensure($node);
            $result = Coral::exec($node->coral, 'canView', array($account), NODE_ACCESS_IGNORE);
          }
          break;
        
        default:
          $result = TRUE;
      }
    }
  }
  return ($result == NODE_ACCESS_IGNORE 
    ? $result 
    : ($result ? NODE_ACCESS_ALLOW : NODE_ACCESS_DENY)
  );
}

/**
 * Implements hook_load().
 */
function coral_node_class_load($nodes) {
  $node_map = array();
  foreach ($nodes as &$node) {
    $node_map[$node->type][] = &$node;
  }
  foreach ($node_map as $type => $items) {
    $class = coral_class('node', $type);
    Coral::exec($class, 'loadSettings', array($items));
    
    foreach ($items as $node) {
      coral_node_ensure($nodes[$node->nid]);
    }
  }
}

/**
 * Implements hook_form().
 */
function coral_node_class_form($node, &$form_state) {
  coral_node_ensure($node);
  $form = Coral::exec($node->coral, 'form', array(&$form_state));
  return $form;
}

/**
 * Implements hook_validate().
 */
function coral_node_class_validate($node, $form, &$form_state) {
  coral_node_ensure($node);
  Coral::exec($node->coral, 'validate', array($form, &$form_state));
}

/**
 * Implements hook_node_presave().
 */
function coral_node_presave($node) {
  if (coral_class('node', $node->type)) {
    coral_node_ensure($node);
    Coral::exec($node->coral, 'presave');
  }
}

/**
 * Implements hook_insert().
 */
function coral_node_class_insert($node) {
  coral_node_ensure($node);
  Coral::exec($node->coral, 'insert');
}

/**
 * Implements hook_update().
 */
function coral_node_class_update($node) {
  coral_node_ensure($node);
  Coral::exec($node->coral, 'update');
}

/**
 * Implements hook_delete().
 */
function coral_node_class_delete($node) {
  coral_node_ensure($node);
  Coral::exec($node->coral, 'delete');
}

/**
 * Implements hook_node_revision_delete().
 */
function coral_node_revision_delete($node) {
  if (coral_class('node', $node->type)) {
    coral_node_ensure($node);
    Coral::exec($node->coral, 'revisionDelete');
  }
}

/**
 * Implements hook_view().
 */
function coral_node_class_view($node, $view_mode) {
  coral_node_ensure($node);
  Coral::exec($node->coral, 'view', array($view_mode));
  return $node;
}
