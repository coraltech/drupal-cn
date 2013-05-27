<?php
//------------------------------------------------------------------------------
// Configuration core

/*
 * Coral configuration object.
 */
class CoralSlideNode extends CoralNode
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() {          return 'slide'; }
  public static function settingsTable() { return NULL; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return array(
      'name'        => t('Slide'),
      'description' => t('A <em>%slide</em> is a media centric content type meant to be shown in groups (within views).',
                          array('%slide' => static::type())),
      'title_label' => t('Name'),
      'has_body'    => TRUE,
      'locked'      => FALSE
    );
  }
	
	public static function fields() {
	  $info = parent::fields();
    $info['media'] = array(
      'type'         => 'media',
      'settings'     => array(),
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
  
  /*
   * 
   * 'media_generic' => array(
      'label' => t('Media file selector'),
      'field types' => array('media', 'file', 'image'),
      'settings' => array(
        'progress_indicator' => 'throbber',
        'allowed_types' => array('image'),
        'allowed_schemes' => array('public', 'private'),
      ),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_DEFAULT,
        'default value' => FIELD_BEHAVIOR_NONE,
      ),
   * 
   */

  
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
