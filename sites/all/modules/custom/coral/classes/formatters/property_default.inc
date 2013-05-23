<?php
//------------------------------------------------------------------------------
// Constants


//------------------------------------------------------------------------------
// Property formatter core

/**
 * Coral default property formatter object.
 */
class CoralPropertyDefaultFormatter extends CoralFormatter
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() { return 'coral_property_default_formatter'; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return Coral::merge(parent::info(), array(
      'label'       => t('Properties'),
      'field types' => array(CoralPropertyField::type())
    ));
  }
    
  //----------------------------------------------------------------------------
  // Tests
  
  
  //----------------------------------------------------------------------------
  // Forms
  
  
  //----------------------------------------------------------------------------
  // CRUD
  
  
  //----------------------------------------------------------------------------
  // Display
  
  public static function theme() {
    return array();
  }
  
  #---
  
  public function view($langcode, $display) {
    $elements = parent::view($langcode, $display);
    
    return $elements;
  } 
   
  //----------------------------------------------------------------------------
  // Utilities
  
}
