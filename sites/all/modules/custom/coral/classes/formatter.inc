<?php
//------------------------------------------------------------------------------
// Constants


//------------------------------------------------------------------------------
// Coral formatter core

/**
 * Coral base formatter object.
 */
abstract class CoralFormatter
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
    
    $this->entity   = $properties['entity'];
    $this->field    = $properties['field'];
    $this->instance = $properties['instance'];
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
      'label'       => t('Formatter'),
      'field types' => array(),
      'settings'    => array(),
    );
  }
    
  //----------------------------------------------------------------------------
  // Tests
  
  
  //----------------------------------------------------------------------------
  // Forms
  
  public static function settingsForm($field, $instance, $view_mode, $form, &$form_state) {
    $elements  = array();
    
    return $elements;  
  }
  
  #---
  
  public static function settingsSummary($field, $instance, $view_mode) {
    $summary   = '';
    
    return $summary;
  }
  
  //----------------------------------------------------------------------------
  // CRUD
  
  
  //----------------------------------------------------------------------------
  // Display
  
  public static function theme() {
    return array();
  }
  
  #---
  
  public function view($langcode, $display) {
    $elements = array();
    
    return $elements;
  } 
   
  //----------------------------------------------------------------------------
  // Utilities
  
}
