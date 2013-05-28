<?php
//------------------------------------------------------------------------------
// Configuration core

/*
 * Coral configuration object.
 */
class CoralImageSlideNode extends CoralSlideNode
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() {          return 'image_slide'; }
  public static function settingsTable() { return NULL; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return array(
      'name'        => t('Image slide'),
      'description' => t('A <em>%image_slide</em> is an image and markup centric content type meant to be shown in groups (within views).',
                          array('%image_slide' => static::type())),
      'title_label' => t('Slide name'),
      'has_body'    => TRUE,
      'locked'      => FALSE
    );
  }
  
	public static function fields() {
	  $info = parent::fields();
    $info['file'] = array(
      'type'         => 'file',
      'settings'     => array(),
      'cardinality'  => 1,
      'locked'       => FALSE
    );
    return $info;
	}
		
	public static function fieldInstances() {
    $info = parent::fieldInstances(); 
    $info['file'] = array(
      'label'    => t('File'),
      'required' => FALSE,
      'settings' => array(
        'file_extensions'   => 'png jpg jpeg',
        'file_directory'    => '',
        'max_filesize'      => '',
        'description_field' => 0
      ),
      'widget'   => array('type' => 'file_generic'),
      'display'  => array(
        'default' => array(
          'label' => 'hidden',
          'type'  => 'file_default',
        )
      )
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
