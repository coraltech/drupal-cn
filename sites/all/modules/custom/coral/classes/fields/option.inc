<?php
//------------------------------------------------------------------------------
// Constants


//------------------------------------------------------------------------------
// Option value core

/**
 * Coral option value object.
 */
class CoralOptionField extends CoralField 
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() { return 'coral_option'; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return Coral::merge(parent::info(), array(
      'label'       => t('Option value and label'),
      'description' => t('Stores a option value and label.')
    ));
  }
  
  #---
  
  public static function schema($version) {
    switch ($version) {
      default: # Version 1
        $schema = array(
          'columns' => array(
            'value' => array(
              'type'     => 'varchar',
              'length'   => 255,
              'not null' => FALSE,
              'sortable' => FALSE,
            ),
            'label' => array(
              'type'     => 'varchar',
              'length'   => 255,
              'not null' => FALSE,
              'sortable' => FALSE,
            )
          )
        );
    }
    return $schema;
  }
 
  //----------------------------------------------------------------------------
  // Tests
  
  public static function checkEmpty($item) {
    return !Coral::exists($item, 'value') && !Coral::exists($item, 'label');
  }
  
  //----------------------------------------------------------------------------
  // Forms
  
  public function validateItem($item, $delta) {
    if (!Coral::exists($item, 'value')) {
      return 'Option value is required at index %index.';
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
