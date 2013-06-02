<?php
//------------------------------------------------------------------------------
// Constants


//------------------------------------------------------------------------------
// Coral field core

/**
 * Coral base field object.
 */
abstract class CoralField
{
  //----------------------------------------------------------------------------
  // Properties
  
  protected $entity   = NULL;
  protected $field    = array();
  protected $instance = array();
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
    
    if ($properties['field']['type'] != static::type()) {
      throw new Exception('Field types do not match.');
    }
    $this->entity   = $properties['entity'];
    $this->field    = $properties['field'];
    $this->instance = $properties['instance'];
    $this->items    = &$properties['items'];
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
      'label'             => t('Coral field'),
      'description'       => t('Stores a field value.'),
      'default_widget'    => '',
      'default_formatter' => ''
    );
  }
  
  #---
  
  public static function schema($version) {
    switch ($version) {
      default: # Version 1
        $schema = array(
          'columns' => array(
            'name' => array(
              'type'     => 'varchar',
              'length'   => 255,
              'not null' => FALSE,
              'sortable' => TRUE,
            ),
            'value' => array(
              'type'     => 'text',
              'size'     => 'big',
              'not null' => FALSE,
            )
          )
        );
    }
    return $schema;
  }

  //----------------------------------------------------------------------------
  // Tests
  
  public static function itemEmpty($item, $callback = NULL) {
    if (!is_null($item)) { # For hook_field_is_empty()
      if (!is_array($item)) {
        return FALSE;
      }
      return static::checkEmpty($item);
    }
    return TRUE;
  }
  
  #---
  
  public static function checkEmpty($item) {
    return !Coral::exists($item, 'name');  
  }
  
  #---
  
  public function isEmpty($callback = NULL) {
    if (!is_null($this->items) && !empty($this->items)) {
      foreach ($this->items as $delta => $item) {
        if (!static::itemEmpty($item, $callback)) {
          return FALSE;
        }
      }
    }
    return TRUE;
  }  
  
  //----------------------------------------------------------------------------
  // Forms
  
  public static function settingsForm($field, $instance, $has_data) {
    $form = array();
    
    return $form;
  }
  
  #---
  
  public static function instanceSettingsForm($field, $instance) {
    $form = array();
    
    return $form;  
  }
  
  #---
  
  public function validate(&$errors, $langcode) {
    //dpm($this->entity, 'validate -> $this->entity');
    //dpm($this->field, 'validate -> $this->field');
    //dpm($this->instance, 'validate -> $this->instance');
    //dpm($this->items, 'validate -> $this->items');
    //dpm($errors, 'validate -> $errors');
    //dpm($langcode, 'validate -> $langcode');
    
    if (!$this->isEmpty()) {
      foreach ($this->items as $delta => $item) {
        if (($message = $this->validateItem($item, $delta)) !== TRUE) {
          $errors[] = array(
            'error'   => 'coral_field',
            'message' => t((is_string($message) ? $message : 'Field %field did not pass validation at %index.'), array(
              '%field' => $this->instance['label'],
              '%index' => ($this->field['cardinality'] ? intval($delta + 1) : ''),
            )),
          );  
        }
      }
    }
  }
  
  #---
  
  public function validateItem($item, $delta) {
    return TRUE;
  }
  
  //----------------------------------------------------------------------------
  // CRUD
  
  public function load($langcode, $age) {
    /*dpm($this->entity, 'load -> $this->entity');
    dpm($this->field, 'load -> $this->field');
    dpm($this->instance, 'load -> $this->instance');
    dpm($this->items, 'load -> $this->items');
    dpm($langcode, 'load -> $langcode');
    dpm($age, 'load -> $age');*/
  }
  
  #---
  
  public function presave($langcode) {
    /*dpm($this->entity, 'presave -> $this->entity');
    dpm($this->field, 'presave -> $this->field');
    dpm($this->instance, 'presave -> $this->instance');
    dpm($this->items, 'presave -> $this->items');
    dpm($langcode, 'presave -> $langcode');*/
  }
  
  #---
  
  public function insert($langcode) {
    /*dpm($this->entity, 'insert -> $this->entity');
    dpm($this->field, 'insert -> $this->field');
    dpm($this->instance, 'insert -> $this->instance');
    dpm($this->items, 'insert -> $this->items');
    dpm($langcode, 'insert -> $langcode');*/
  }
  
  #---
  
  public function update($langcode) {
    /*dpm($this->entity, 'update -> $this->entity');
    dpm($this->field, 'update -> $this->field');
    dpm($this->instance, 'update -> $this->instance');
    dpm($this->items, 'update -> $this->items');
    dpm($langcode, 'update -> $langcode');*/
  }
  
  //----------------------------------------------------------------------------
  // Display
  
  public static function theme() {
    return array();
  }
  
  //----------------------------------------------------------------------------
  // Utilities
  
}
