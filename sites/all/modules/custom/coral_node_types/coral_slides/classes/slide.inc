<?php
//------------------------------------------------------------------------------
// Configuration core

/*
 * Coral configuration object.
 */
abstract class CoralSlideNode extends CoralNode
{ 
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function fields() {
	  $info = parent::fields();
    $info['fe_attach'] = array(
      'type'         => 'text',
      'settings'     => array(),
      'cardinality'  => 1,
      'locked'       => FALSE
    );
    return $info;
	}
		
	public static function fieldInstances() {
    $info = parent::fieldInstances();
    $info['fe_attach'] = array(
      'label' => t('Fe attach'),
      'required' => FALSE,
      'description' => t('Some description'),
      'widget'   => array('type' => 'text_textfield'),
    );
    return $info; 
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
