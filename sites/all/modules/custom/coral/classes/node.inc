<?php
//------------------------------------------------------------------------------
// Coral node core

/**
 * Coral base node object.
 * 
 * NOTE: All Coral node types extend CoralNode
 */
abstract class CoralNode 
{
  //----------------------------------------------------------------------------
  // Properties
  
  protected $node = NULL;
  
  abstract public static function type();
  
  public static function settingsTable() { return 'coral_' . static::type(); }
  
  //----------------------------------------------------------------------------
  // Constructor / Destructor
  
  function __construct(&$node) {
    if ($node->type != static::type()) {
      throw new Exception('Node types do not match.');
    }
    $this->set($node);
  }
  
  //---
  
  public function set(&$node) {
    $this->node = &$node;
  }
  
  //---
  
  function __destruct() {
    
  }
  
  //----------------------------------------------------------------------------
  // Definition
  
  abstract public static function info();
  
  #---
  
  public static function insertType($info) {
    $type = static::type();
    
    # DRUPAL_DISABLED, DRUPAL_OPTIONAL, DRUPAL_REQUIRED
    variable_set("node_preview_${type}", DRUPAL_DISABLED);
    
    # status, promote, sticky, revision
    variable_set("node_options_${type}", array('status', 'revision'));
    
    # TRUE, FALSE
    variable_set("node_submitted_${type}", TRUE);
    
    # menu_get_menus()
    variable_set("menu_options_${type}", array());
    
    # menu_parent_options(menu_get_menus(), array('mlid' => 0))
    variable_set("menu_parent_${type}", '');
    
    # Create any default nodes of this type.
    foreach (static::defaultNodes() as $node_data) {
      static::create($node_data);
    }
  }
  
  #---
  
  public static function deleteType() {
    $type = static::type();
    
    variable_del("node_preview_${type}");
    variable_del("node_options_${type}");
    variable_del("node_submitted_${type}");
    variable_del("menu_options_${type}");
    variable_del("menu_parent_${type}");
  }
  
  #---
  
  public static function entityInfo(&$node_info) {
    // Add our new view mode to the list of view modes...
    $node_info['view modes'] = Coral::merge($node_info['view modes'], static::viewModes());
  }
  
  #---
  
  public static function viewModes() {
    return array();
  }
  
  #---
  
  public static function permissions() {
    $type = static::type();
    $info = node_type_get_type($type);
    
    $perms = array(
      "view own $type content" => array(
        'title' => t('%type_name: View own content', array('%type_name' => $info->name)),
      ),
      "view any $type content" => array(
        'title' => t('%type_name: View any content', array('%type_name' => $info->name)),
      )
    );
    return $perms;
  }
  
  #---
  
  public static function schema($version = 1) {
    $schema = array();
    
    switch ($version) {
      default: # Version 1
        if (!is_null(static::settingsTable())) {
          $schema[static::settingsTable()] = array(
            'description' => 'Stores Coral specific settings for nodes.',
            'fields' => array(
              'nid' => array(
                'type'        => 'int',
                'unsigned'    => TRUE,
                'not null'    => TRUE,
                'default'     => 0,
                'description' => "The node's {node}.nid.",
              ),
              'vid' => array(
                'type'        => 'int',
                'unsigned'    => TRUE,
                'not null'    => TRUE,
                'default'     => 0,
                'description' => "The node's {node}.vid.",
              ),
              // Add single property fields here
            ),          
            'primary key'  => array('vid'),
            'foreign keys' => array(
              'node' => array(
                'table'   => 'node',
                'columns' => array('nid' => 'nid'),
              ),
              'node_revision' => array(
                'table' => 'node_revision',
                'columns' => array('vid' => 'vid'),
              )
            ),
            'indexes' => array(
              'nid' => array('nid')
            )
          );
        }
    }
    return $schema;
  }

  #---
  
  public static function fields() {
    return array(
      'body' => array(
        'type'         => 'text_with_summary',
        'entity_types' => array('node'),
        'cardinality'  => 1,
        'locked'       => FALSE
      )
    );
  }
  
  #---
  
  public static function fieldInstances() {
    return array(
      'body' => array(
        'label'    => t('Body'),
        'required' => FALSE,
        'widget'   => array('type' => 'text_textarea_with_summary'),
        'settings' => array('display_summary' => TRUE),
        'display'  => array(
          'default' => array(
            'label' => 'hidden',
            'type'  => 'text_default',
          ),
          'teaser' => array(
            'label' => 'hidden',
            'type'  => 'text_summary_or_trimmed',
          )
        )
      )
    );
  }
  
  #---
  
  public static function extraFields() {
    return array();
  }
  
  #---
  
  public static function defaultNodes() {
    return array();
  }
  
  #---
  
  public function field($field_name, $delta = NULL) {
    $field_name = preg_replace('/^field_/', '', $field_name);        
    $field_key  = 'field_' . $field_name;
    
    if (is_int($delta) && $delta >= 0) {
      return $this->node->$field_key[$node->language][$delta];
    }
    $field_info = field_info_field($field_name);
    if ($field_info['cardinality'] == 1) {
      return $this->node->$field_key[$node->language][0];
    }
    return $this->node->$field_key[$node->language];
  }
   
  //----------------------------------------------------------------------------
  // Tests
  
  public static function canCreate($account = NULL) {
    global $user;
    
    if (is_null($account)) {
      $account = $user;
    }
    $node_type = static::type();
    
    return (user_access('bypass node access', $account) 
      || user_access("create ${node_type} content", $account)
    );
  }
  
  #---
  
  public function canEdit($account = NULL) {
    global $user;
    
    if (is_null($account)) {
      $account = $user;
    }
    $node_type = static::type();

    return (user_access('bypass node access', $account) 
      || user_access("edit any ${node_type} content", $account) 
      || (user_access("edit own ${node_type} content", $account) 
        && $account->uid == $this->node->uid)
    );
  }
  
  #---
  
  public function canDelete($account = NULL) {
    global $user;
    
    if (is_null($account)) {
      $account = $user;
    }
    $node_type = static::type();

    return (user_access('bypass node access', $account) 
      || user_access("delete any ${node_type} content", $account) 
      || (user_access("delete own ${node_type} content", $account) 
        && $account->uid == $this->node->uid)
    );
  }

  #---
  
  public function canView($account = NULL) {
    global $user;
    
    if (is_null($account)) {
      $account = $user;
    }
    $node_type = static::type();

    return (user_access('bypass node access', $account) 
      || user_access("view any ${node_type} content", $account) 
      || (user_access("view own ${node_type} content", $account) 
          && $account->uid == $this->node->uid)
    );  
  }
  
  //----------------------------------------------------------------------------
  // Forms
  
  public function form(&$form_state) {
    $form = array();
    $type = node_type_get_type($this->node);

    // In case we use Drupal's AHAH implementation.
    $form_state['cache'] = TRUE;

    if ($type->has_title) {
      $form['title'] = array(
        '#type'          => 'textfield',
        '#title'         => check_plain($type->title_label),
        '#required'      => TRUE,
        '#default_value' => $this->node->title,
        '#weight'        => -5,
      );
    }
    return $form;
  }
  
  #---
  
  public function validate($form, &$form_state) {
    $node = $this->node;
    $type = node_type_get_type($node->type);
    
    if ($type->has_title && empty($node->title)) {
      form_set_error('title', t('A Coral object must have a name.'));
    }
  }

  //----------------------------------------------------------------------------
  // Updates
  
  public function presave() {
    
  }
  
  #---
  
  public function insert($properties = array()) {
    if (!is_null(static::settingsTable())) {
      $fields = Coral::merge($properties, array('nid' => $this->node->nid, 'vid' => $this->node->vid));
      db_insert(static::settingsTable())->fields($fields)->execute();
    }
  }
  
  #---
  
  public function update($properties = array()) {
    if (!empty($this->node->revision)) {
      $this->insert($properties);  
    }
    elseif (!empty($properties)) {
      if (!is_null(static::settingsTable())) {
        db_update(static::settingsTable())
          ->fields($properties)
          ->condition('vid', $this->node->vid)
          ->execute();
      }
    }
  }
  
  #---
  
  public function delete() {
    if (!is_null(static::settingsTable())) {
      db_delete(static::settingsTable())
        ->condition('nid', $this->node->nid)
        ->execute();
    }
  }
  
  #---
  
  public function revisionDelete() {
    if (!is_null(static::settingsTable())) {
      db_delete(static::settingsTable())
        ->condition('vid', $this->node->vid)
        ->execute();
    }
  }
  
  #---
  
  public static function create($node_data = array()) {
    $node           = new stdClass();
    $node->type     = static::type();
    $node->language = LANGUAGE_NONE;
      
    node_object_prepare($node);
 
    $node->title = Coral::get($node_data, 'title', '');
    
    if ($path = Coral::get($node_data, 'path', NULL)) {
      $node->path  = array('alias' => $path);
    }
    
    foreach (Coral::ensureArray($node_data, 'settings') as $key => $value) {
      $node->$key = $value;
    }
    
    foreach (Coral::ensureArray($node_data, 'fields') as $field_name => $data) {
      $field_name = preg_replace('/^field_/', '', $field_name);        
      $field_key  = 'field_' . $field_name;
            
      if (!Coral::isArray($data)) {
        $field_data[$node->language] = array($data);
      }
      else {
        $field_data[$node->language] = $data;
      }
      $node->$field_key = $field_data;
    }
    node_save($node);
    return $node;
  }
  
  //----------------------------------------------------------------------------
  // Display
  
  public static function theme() {
    return array();
  }
  
  #---
  
  
  public function view($view_mode) {
    $node = $this->node;
    # Form $node->content[] array properties.  
  }
      
  //----------------------------------------------------------------------------
  // Operations
  
  public static function loadSettings($nodes) {
    $vids           = array();
    $settings       = array();
    
    $settings_table = static::settingsTable();
    
    if (!is_null($settings_table)) {
      foreach ($nodes as $nid => $node) {
        $vids[] = $node->vid;
      }
    
      if (!empty($vids)) {
        $result = db_query("SELECT * FROM {" . $settings_table . "} WHERE vid IN (:vids)",
                            array(':vids'  => $vids));
        if ($result) {
          while ($record = $result->fetchAssoc()) {
            foreach ($record as $key => $value) {
              if (!in_array($key, array('nid', 'vid'))) {
                $nodes[$record->nid]->$key = $value; // Set by reference
              }
            }
          }
        }
      }
    }
  }
  
  //----------------------------------------------------------------------------
  // Utilities
  
  /**
   * Load all defined system formats.
   */
  public static function load($conditions = array(), $callback = NULL) {
    $data  = array();
    
    $query = db_select('node', 'n')->fields('n');
    $query->condition('type', static::type());
    
    foreach ($conditions as $key => $value) {
      if (Coral::exists($value, 'op') && Coral::exists($value, 'value')) {
        $query->condition($key, $value['value'], $value['op']);  
      }
      else {
        $query->condition($key, $value);
      }
    }
    $result = $query->execute();
    
    while ($node = $result->fetchObject()) {
      $node = node_load($node->nid);
        
      $data[$node->nid] = array(
        'nid'   => $node->nid,
        'vid'   => $node->vid,
        'title' => $node->title
      );
        
      if (!is_null($callback) && is_callable($callback)) {
        $data[$node->nid] = Coral::merge(call_user_func($callback, $node), $data[$node->nid]);
      }
    }
    return $data;
  }
}
