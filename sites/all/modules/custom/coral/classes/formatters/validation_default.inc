<?php
//------------------------------------------------------------------------------
// Constants


//------------------------------------------------------------------------------
// Validation formatter core

/**
 * Coral default validation formatter object.
 */
class CoralValidationDefaultFormatter extends CoralFormatter
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() { return 'coral_validation_default_formatter'; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return Coral::merge(parent::info(), array(
      'label'       => t('Validation criteria'),
      'field types' => array(CoralValidationField::type())
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
