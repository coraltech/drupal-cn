<?php
//------------------------------------------------------------------------------
// Configuration core

/*
 * Coral configuration object.
 */
class CoralQuestionNode extends CoralNode
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() {          return 'question'; }
  public static function settingsTable() { return NULL; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return array(
      'name'        => t('Question'),
      'description' => t('A <em>%question</em> is a content type used to query the community for information or input.',
                          array('%question' => static::type())),
      'title_label' => t('Question'),
      'has_body'    => TRUE,
      'locked'      => FALSE
    );
  }
  
  public static function fields() {
    $info = parent::fields();
    $info['file'] = array(
      'type'         => 'file',
      'settings'     => array(),
      'cardinality'  => 0,
      'locked'       => FALSE
    );
    /*$info['tags'] = array(
      'type'         => 'taxonomy_term_reference',
      'settings'     => array(),
      'cardinality'  => 0,
      'locked'       => FALSE,
    );*/
    return $info;
  }
    
  public static function fieldInstances() {
    $info = parent::fieldInstances(); 
    $info['file'] = array(
      'label'    => t('File'),
      'required' => FALSE,
      'settings' => array(
        'file_extensions'   => '',
        'file_directory'    => '',
        'max_filesize'      => '',
        'description_field' => 0
      ),
      'widget'   => array('type' => 'file_generic'),
      'display'  => array(
        'default' => array(
          'label' => 'hidden',
          'type'  => 'file_default',
        ),
      ),
    );/*
    $info['tags'] = array(
      'label'    => t('Tags'),
      'required' => TRUE,
      /*'settings' => array(
        'target_type' => 'taxonomy_term',
        'handler_settings' => array(
          'target_bundles' => array(
            'tags' => 'tags'
          ),
        ), 
      ),
      'widget'   => array(
        'type' => 'taxonomy_autocomplete',
        'weight' => -4,
      ),
      'display'  => array(
        'default' => array(
          'label' => 'inline',
        ),
      ),
    );*/
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
  
  public static function theme() {
    return array();
  }
  

  public function view($view_mode) {
    $node = $this->node;
    # Form $node->content[] array properties.  
  }
   
  //----------------------------------------------------------------------------
  // Operations
  
}
