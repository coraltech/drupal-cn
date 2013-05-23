<?php
//------------------------------------------------------------------------------
// Constants


//------------------------------------------------------------------------------
// Coral widget core

/**
 * Coral base widget object.
 */
abstract class CoralWidget
{
  //----------------------------------------------------------------------------
  // Properties
  
  protected $entity   = NULL;
  protected $field    = array();
  protected $instance = array();
  protected $widget   = NULL;
  protected $items    = array();
  
  #---
  
  abstract public static function type();
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  function __construct($properties) {
    $this->set($properties);
  }
  
  #---
  
  public function set($properties) {
    // TODO: Lookup entity, field, instance, and delta if they are not given.
    
    if ($properties['instance']['widget']['type'] != static::type()) {
      throw new Exception('Widget types do not match.');
    }
    $this->entity   = $properties['entity'];
    $this->field    = $properties['field'];
    $this->instance = $properties['instance'];
    $this->widget   = $this->instance['widget'];
    $this->items    = $properties['items'];
  }
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function permissions() {
    $type  = static::type();
    $perms = array();
    return $perms;
  }
  
  #---
  
  public static function info() {
    return array(
      'label'       => t('Core'),
      'field types' => array(),
      'settings'    => array(),
      'behaviors'   => array(
        'multiple values' => FIELD_BEHAVIOR_DEFAULT,
        'default value'   => FIELD_BEHAVIOR_NONE,
      ),
    );
  }
  
  #---
  
  public static function columns() {
    return array();
  }
    
  //----------------------------------------------------------------------------
  // Tests
  
  
  //----------------------------------------------------------------------------
  // Forms
  
  public static function settingsForm($field, $instance) {
    $form = array();
    
    return $form;  
  }
  
  #---
  
  public function form(&$form, &$form_state, $langcode, $delta, $element) {
    $elements   = array();
    $columns    = static::columns();
    
    $field      = $this->field;
    $field_name = $field['field_name'];
    
    $widget     = $this->widget;
     
    $id         = $form_state['build_info']['form_id'] . '-' . $field_name;
    
    if ($widget['behaviors']['multiple values'] == FIELD_BEHAVIOR_CUSTOM && ($field['cardinality'] == FIELD_CARDINALITY_UNLIMITED || $field['cardinality'] > 1)) {
      $elements += coral_multi_item_form($form, $form_state, $element, $id, $this->items, array( 
          'form_handler' => array($this, 'itemForm'),
          'form_args'    => array($langcode),
          'column_names' => array_values($columns),
          'column_order' => array_keys($columns)
        )
      );  
    }
    else {
      $elements += $this->itemForm($form, $form_state, $element, $id, $this->items[0], 0, $langcode);
    }
    dpm($form, 'form -> $form');
    dpm($form_state, 'form -> $form_state');
    dpm($elements, 'form -> $elements');
    return $elements;
  }
  
  #---
  
  public function itemForm(&$form, &$form_state, $element, $id, $item, $index, $langcode) {
    $addons = array();
    
    return $addons;
  }
  
  //----------------------------------------------------------------------------
  // Display
  
  public static function theme() {
    return array();
  }
  
  //----------------------------------------------------------------------------
  // Utilities
  
}
