<?php
//------------------------------------------------------------------------------
// Constants


//------------------------------------------------------------------------------
// Property default form widget

/**
 * Coral default property widget object.
 */
class CoralPropertyDefaultWidget extends CoralWidget
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() { return 'coral_property_default_widget'; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return Coral::merge(parent::info(), array(
      'label'       => t('Properties'),
      'field types' => array(CoralPropertyField::type()),
      'behaviors'   => array(
        'multiple values' => FIELD_BEHAVIOR_CUSTOM
      )
    ));
  }
  
  #---
  
  public static function columns() {
    return array(
      'name'  => t('Property'),
      'value' => t('Value')
    );
  }
   
  //----------------------------------------------------------------------------
  // Tests
  
  
  //----------------------------------------------------------------------------
  // Forms
  
  /**
   * Combinations:
   * 
   * > name format=undef
   * > name format=bool value=(true|false)
   * > name format=number value=/^\-?[\d\.]+$/
   * > name format=string value
   * > name format=array value=(count=/^[\d]+$/>0)
   *    -> format value?
   * > name format=hash value=(count=/^[\d]+$/>0)
   *    -> name format value?
   */
  public function itemForm(&$form, &$form_state, $element, $id, $item, $index, $langcode) {
    $addons['name'] = coral_form_element(1, array(
        '#type'          => 'textfield',
        '#title'         => t('Property'),
        '#required'      => TRUE,
        '#default_value' => (isset($item['name']) ? $item['name'] : ''),
      ),
      "${id}-name",
      array('name-edit'),
      array('name-edit-wrapper')
    );
    $addons['value'] = coral_form_element(2, array(
      '#type'          => 'coral_data',
      '#title'         => t('Value'),
      '#default_value' => (isset($item['value']) ? $item['value'] : NULL),
    ),
      "${id}-value",
      array('value-edit'),
      array('value-edit-wrapper')
    );
    return coral_form_wrapper($addons, 'property-form');
  }
  
  //----------------------------------------------------------------------------
  // Display
  
  
  //----------------------------------------------------------------------------
  // Utilities

}
