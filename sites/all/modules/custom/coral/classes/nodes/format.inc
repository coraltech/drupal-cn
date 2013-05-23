<?php
//------------------------------------------------------------------------------
// Format node type

/**
 * Coral format object.
 */
class CoralFormatNode extends CoralNode
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() {          return 'format'; }
  public static function settingsTable() { return NULL; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return array(
      'name'        => t('Format'),
      'description' => t('A <em>%format</em> is an object that contains a specification for a data value format.',
                          array('%format' => static::type())),
      'title_label' => t('Name'),
      'has_body'    => FALSE,
      'locked'      => FALSE
    );
  }
  
  #---
  
  public static function fields() {
    return array(
      'form_type' => array(
        'type'         => 'list_text',
        'settings'     => array(
          'allowed_values' => static::formTypes(),
        ),
        'cardinality'  => 1,
        'locked'       => FALSE
      ),
      'select_options' => array(
        'type'        => CoralOptionField::type(),
        'cardinality' => FIELD_CARDINALITY_UNLIMITED,
        'locked'      => FALSE
      ),
      'patterns' => array(
        'type'        => CoralValidationField::type(),
        'cardinality' => FIELD_CARDINALITY_UNLIMITED,
        'locked'      => FALSE
      )
    );
  }
  
  #---
  
  public static function fieldInstances() {
    return array(
      'form_type' => array(
        'label'    => t('Form type'),
        'required' => TRUE,
        'widget'   => array('type' => 'options_select'),
        'display'  => array(
          'default' => array(
            'label' => 'hidden',
            'type'  => 'list_default',
          )
        )
      ),
      'select_options' => array(
        'label'    => t('Select options'),
        'required' => FALSE,
        'widget'   => array('type' => CoralOptionDefaultWidget::type()),
        'display'  => array(
          'default' => array(
            'label' => 'hidden',
            'type'  => CoralOptionDefaultFormatter::type(),
          )
        )
      ),
      'patterns' => array(
        'label'    => t('Validation criteria'),
        'required' => FALSE,
        'widget'   => array('type' => CoralValidationDefaultWidget::type()),
        'display'  => array(
          'default' => array(
            'label' => 'hidden',
            'type'  => CoralValidationDefaultFormatter::type(),
          )
        )
      )
    );
  }

  #---
  
  public static function defaultNodes() {
    return array(
      array(
        'title'  => t('Boolean'),
        'path'   => 'format/boolean',
        'fields' => array(
          'form_type' => 'select',
          'select_options' => array(
            array('value' => 'true', 'label' => t('True')),
            array('value' => 'false', 'label' => t('False')),
          )
        )
      ),
      array(
        'title'  => t('Number'),
        'path'   => 'format/number',
        'fields' => array(
          'form_type' => 'textfield',
          'patterns'  => array(
            array('pattern' => '^\-?[0-9\.]+$', 'error_message' => t('Field %field must be a number at %index.')),
          )
        )
      ),
      array(
        'title'  => t('String'),
        'path'   => 'format/string',
        'fields' => array(
          'form_type' => 'textfield'
        )
      ),
      array(
        'title'  => t('Multi line text'),
        'path'   => 'format/text',
        'fields' => array(
          'form_type' => 'textarea'
        )
      ),
    );
  }
  
  //----------------------------------------------------------------------------
  // Tests
  
    
  //----------------------------------------------------------------------------
  // Forms
  
  public function validate($form, &$form_state) {
    parent::validate($form, $form_state);
    
    $node      = $this->node;
    $form_type = $node->field_form_type[$node->language][0]['value'];
    
    if (in_array($form_type, array('select'))) {
      dpm($form, 'validate -> $form');
      //form_set_error('field_options[' . $node->language . ']', t('Selection field must have options defined.'));
    }
  }
  
  #---
  
  public function selectedForm($value = NULL, $form = array()) {
    $node      = $this->node;
    $form_type = $node->field_form_type[$node->language][0]['value'];
    
    $form['#default_value'] = $value;
    
    switch ($form_type) {
      case 'select':
        $form['#type']    = 'select';
        $form['#options'] = $this->options();
        break;
        
      case 'textfield':
        $form['#type'] = 'textfield';
        break;
        
      case 'textarea':
        $form['#type'] = 'textarea';
        $form += array(
          '#cols' => 30,
          '#rows' => 3,
        );
        break;
    }

    return $form;
  }
  
  //----------------------------------------------------------------------------
  // Updates

  
  //----------------------------------------------------------------------------
  // Display
  
   
  //----------------------------------------------------------------------------
  // Operations
  
  public function validateInput($input) {
    $node      = $this->node;
    $patterns  = $node->field_patterns[$node->language];
    $errors    = array();
    
    if (!empty($patterns)) {
      foreach ($patterns as $delta => $item) {
        $regexp = '/' . $item['pattern'] . '/';
        if (!preg_match($regexp, $input)) {
          $errors[] = $item['message'];
        }
      }
    }
    return $errors;
  }  
  
  //----------------------------------------------------------------------------
  // Utilities
  
  public static function formTypes() {
    return array(
      'select'    => t('Select from multiple values'),
      'textfield' => t('Single line textfield'),
      'textarea'  => t('Multi line textarea')
    );
  }
  
  #---
  
  public function options() {
    $node    = $this->node;
    $options = $node->field_select_options[$node->language];
    $results = array();
    
    foreach ($options as $delta => $item) {
      $label = (Coral::exists($item, 'label') ? 'label' : 'value');
      $results[$item['value']] = t($item[$label]);
    }
    return $results;
  }
}
