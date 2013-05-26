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
		return array(
      'media' => array(
        'type'         => 'media',
        'settings'     => array(),
        'cardinality'  => 1,
        'locked'       => FALSE
      ),
    );
	}
		
	public static function fieldInstances() {
		return array(
      'media' => array(
        'label'    => t('Media'),
        'required' => FALSE,
        'widget'   => array('type' => 'media_generic'),
        'display'  => array(
          'default' => array(
            'label' => 'hidden',
            'type'  => 'media',
          )
        )
      ),
    );
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
