<?php
//------------------------------------------------------------------------------
// Constants


//------------------------------------------------------------------------------
// Validation default form widget

/**
 * Coral default validation widget object.
 */
class CoralValidationDefaultWidget extends CoralWidget
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() { return 'coral_validation_default_widget'; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return Coral::merge(parent::info(), array(
      'label'       => t('Validation criteria'),
      'field types' => array(CoralValidationField::type()),
      'settings'    => array(),
      'behaviors'   => array(
        'multiple values' => FIELD_BEHAVIOR_DEFAULT
      )
    ));
  }
  
  #---
  
  public static function columns() {
    return array(
      'pattern'       => t('Pattern'),
      'error_message' => t('Error message')
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
    $addons['pattern'] = coral_form_element(1, array(
        '#type'          => 'textfield',
        '#title'         => t('Pattern'),
        '#required'      => FALSE,
        '#default_value' => (isset($item['pattern']) ? $item['pattern'] : ''),
      ),
      "${id}-pattern",
      array('pattern'),
      array('pattern-wrapper')
    );
    $addons['error_message'] = coral_form_element(2, array(
        '#type'          => 'textarea',
        '#title'         => t('Error message'),
        '#required'      => FALSE,
        '#default_value' => (isset($item['error_message']) ? $item['error_message'] : NULL),
      ),
      "${id}-error-message",
      array('error-message-edit'),
      array('error-message-edit-wrapper')
    );
    return coral_form_wrapper($addons, 'pattern-form');
  }
  
  //----------------------------------------------------------------------------
  // Display
  
  
  //----------------------------------------------------------------------------
  // Utilities

}
