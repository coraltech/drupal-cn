<?php
//------------------------------------------------------------------------------
// Constants


//------------------------------------------------------------------------------
// Option formatter core

/**
 * Coral default option formatter object.
 */
class CoralOptionDefaultFormatter extends CoralFormatter
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() { return 'coral_option_default_formatter'; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return Coral::merge(parent::info(), array(
      'label'       => t('Option'),
      'field types' => array(CoralOptionField::type())
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
