<?php
//------------------------------------------------------------------------------
// Configuration core

/*
 * Coral configuration object.
 */
class CoralPageNode extends CoralNode
{
  //----------------------------------------------------------------------------
  // Properties
  
  public static function type() {          return 'page'; }
  public static function settingsTable() { return NULL; }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  
  //----------------------------------------------------------------------------
  // Definition
  
  public static function info() {
    return array(
      'name'        => t('Page'),
      'description' => t('A <em>%page</em> is a general purpose landing page.',
                          array('%page' => static::type())),
      'title_label' => t('Name'),
      'has_body'    => FALSE,
      'locked'      => FALSE
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
