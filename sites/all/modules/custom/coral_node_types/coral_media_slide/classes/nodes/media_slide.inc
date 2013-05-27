<?php
//------------------------------------------------------------------------------
// Configuration core

/*
 * Coral configuration object.
 */
class CoralMediaSlideNode extends CoralNode
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() {          return 'media_slide'; }
  public static function settingsTable() { return NULL; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return array(
      'name'        => t('Media slide'),
      'description' => t('A <em>%media_slide</em> is a video centric content type meant to be shown in groups (within views).',
                          array('%media_slide' => static::type())),
      'title_label' => t('Slide name'),
      'has_body'    => TRUE,
      'locked'      => FALSE
    );
  }
  
	public static function fields() {
	  $info = parent::fields();
    $info['media'] = array(
      'type'     => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
        'allowed_types'      => array('image', 'media'),
        'allowed_schemes'    => array('public', 'private'),
      ),
      'cardinality'  => 1,
      'locked'       => FALSE
    );
    return $info;
	}
		
	public static function fieldInstances() {
    $info = parent::fieldInstances(); 
    $info['media'] = array(
      'label'    => t('Media'),
      'required' => FALSE,
      'widget'   => array('type' => 'media_generic'),
      'display'  => array(
        'default' => array(
          'label' => 'hidden',
          'type'  => 'media',
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
