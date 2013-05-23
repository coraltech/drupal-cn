<?php
//------------------------------------------------------------------------------
// Constants


//------------------------------------------------------------------------------
// Option default form widget

/**
 * Coral default option widget object.
 */
class CoralOptionDefaultWidget extends CoralWidget
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() { return 'coral_option_default_widget'; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return Coral::merge(parent::info(), array(
      'label'       => t('Option'),
      'field types' => array(CoralOptionField::type()),
      'behaviors'   => array(
        'multiple values' => FIELD_BEHAVIOR_DEFAULT
      )
    ));
  }
  
  #---
  
  public static function columns() {
    return array(
      'value' => t('Value'),
      'label' => t('Label')
    );
  }
   
  //----------------------------------------------------------------------------
  // Tests
  
  
  //----------------------------------------------------------------------------
  // Forms
  
  /**
   * Return a single item form.
   */
  public function itemForm(&$form, &$form_state, $element, $id, $item, $index, $langcode) {
    $addons['value'] = coral_form_element(1, array(
        '#type'          => 'textfield',
        '#title'         => t('Value'),
        '#required'      => TRUE,
        '#default_value' => (isset($item['value']) ? $item['value'] : ''),
      ),
      "${id}-value",
      array('option-value-edit'),
      array('option-value-edit-wrapper')
    );
    $addons['label'] = coral_form_element(2, array(
        '#type'          => 'textfield',
        '#title'         => t('Label'),
        '#required'      => FALSE,
        '#default_value' => (isset($item['label']) ? $item['label'] : NULL),
      ),
      "${id}-label",
      array('option-label-edit'),
      array('option-label-edit-wrapper')
    );
    return coral_form_wrapper($addons, 'option-form');
  }
  
  //----------------------------------------------------------------------------
  // Display
  
  
  //----------------------------------------------------------------------------
  // Utilities

}
