<?php
//------------------------------------------------------------------------------
// Configuration core

/**
 * Coral configuration object.
 */
class CoralConfigNode extends CoralNode
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() {          return 'configuration'; }
  public static function settingsTable() { return NULL; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return array(
      'name'        => t('Configuration'),
      'description' => t('A <em>%config</em> is an object that contains a recursive property definition.',
                          array('%config' => static::type())),
      'title_label' => t('Name'),
      'has_body'    => FALSE,
      'locked'      => FALSE
    );
  }
  
  #---
  
  public static function fields() {
    return array(
      'properties' => array(
        'type'         => CoralPropertyField::type(),
        'cardinality'  => FIELD_CARDINALITY_UNLIMITED,
        'locked'       => FALSE
      )
    );
  }
  
  #---
  
  public static function fieldInstances() {
    return array(
      'properties' => array(
        'label'    => t('Properties'),
        'required' => TRUE,
        'widget'   => array('type' => CoralPropertyDefaultWidget::type()),
        'display'  => array(
          'default' => array(
            'label' => 'hidden',
            'type'  => CoralPropertyDefaultFormatter::type(),
          )
        )
      )
    );
  }
  
  //----------------------------------------------------------------------------
  // Tests
  
    
  //----------------------------------------------------------------------------
  // Forms
  
  
  //----------------------------------------------------------------------------
  // Updates

  
  //----------------------------------------------------------------------------
  // Display
  
   
  //----------------------------------------------------------------------------
  // Operations
  
}
