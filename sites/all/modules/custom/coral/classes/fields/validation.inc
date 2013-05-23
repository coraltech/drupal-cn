<?php
//------------------------------------------------------------------------------
// Constants


//------------------------------------------------------------------------------
// Validation core

/**
 * Coral validation object.
 */
class CoralValidationField extends CoralField 
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() { return 'coral_validation'; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return Coral::merge(parent::info(), array(
      'label'       => t('Validation criteria'),
      'description' => t('Stores a validation regex and error message.')
    ));
  }
  
  #---
  
  public static function schema($version) {
    switch ($version) {
      default: # Version 1
        $schema = array(
          'columns' => array(
            'pattern' => array(
              'type'     => 'varchar',
              'length'   => 255,
              'not null' => FALSE,
              'sortable' => FALSE,
            ),
            'error_message' => array(
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
  
  public static function checkEmpty($item) {
    return !Coral::exists($item, 'pattern') && !Coral::exists($item, 'error_message');
  }
  
  //----------------------------------------------------------------------------
  // Forms
  
  public function validateItem($item, $delta) {
    if (!Coral::exists($item, 'pattern')) {
      return 'Pattern is required at index %index.';
    }
    return TRUE;
  }
  
  //----------------------------------------------------------------------------
  // CRUD
  
  
  //----------------------------------------------------------------------------
  // Display
  
  
  //----------------------------------------------------------------------------
  // Utilities

}
