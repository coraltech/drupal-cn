<?php
//------------------------------------------------------------------------------
// Constants


//------------------------------------------------------------------------------
// Property core

/**
 * Coral property object.
 */
class CoralPropertyField extends CoralField 
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() { return 'coral_property'; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return Coral::merge(parent::info(), array(
      'label'       => t('Property field'),
      'description' => t('Stores a recursive name / value property.')
    ));
  }
  
  #---
  
  public static function schema($version) {
    switch ($version) {
      default: # Version 1
        $schema = Coral::merge(parent::schema($version), array(
          'columns' => array(
            'format' => array(
              'type'     => 'varchar',
              'length'   => 45,
              'not null' => FALSE,
              'sortable' => TRUE,
            ),
          )
        ));
    }
    return $schema;
  }
 
  //----------------------------------------------------------------------------
  // Tests
  
  
  //----------------------------------------------------------------------------
  // Forms
  
  
  //----------------------------------------------------------------------------
  // CRUD
  
  public function load($langcode, $age) {
    dpm($this->entity, 'load -> $this->entity');
    dpm($this->field, 'load -> $this->field');
    dpm($this->instance, 'load -> $this->instance');
    dpm($this->items, 'load -> $this->items');
    dpm($langcode, 'load -> $langcode');
    dpm($age, 'load -> $age');
    
    foreach ($this->items as $delta => $item) {
      $this->items[$delta]['value'] = drupal_json_decode($item['value']);
    }
    
    dpm($this->items, 'load -> $this->items');
  }
  
  #---
  
  public function presave($langcode) {
    dpm($this->entity, 'presave -> $this->entity');
    dpm($this->field, 'presave -> $this->field');
    dpm($this->instance, 'presave -> $this->instance');
    dpm($this->items, 'presave -> $this->items');
    dpm($langcode, 'presave -> $langcode');
    
    foreach ($this->items as $delta => $item) {
      $this->items[$delta]['value'] = drupal_json_encode($item['value']);
    }
    
    dpm($this->items, 'presave -> $this->items');
  }
  
  //----------------------------------------------------------------------------
  // Display
  
  
  //----------------------------------------------------------------------------
  // Utilities

}
