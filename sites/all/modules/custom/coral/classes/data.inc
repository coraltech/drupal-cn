<?php

//------------------------------------------------------------------------------
// Constants

define('CORAL_TYPE_UNDEF', 'undef');
define('CORAL_TYPE_BOOLEAN', 'boolean');
define('CORAL_TYPE_NUMBER', 'number');
define('CORAL_TYPE_STRING', 'string');
define('CORAL_TYPE_TEXT', 'text');
define('CORAL_TYPE_ARRAY', 'array');
define('CORAL_TYPE_HASH', 'hash');


//------------------------------------------------------------------------------
// Definition

class CoralData {
  
  /**
   * Return whether or not a property exists and is not NULL and optionally
   * whether or not it is empty (empty string/array/hash/etc...).
   */
  public static function exists($data, $property, $check_empty = TRUE) {
    if (is_array($data)) {
      if ($check_empty) {
        return (array_key_exists($property, $data) && !static::isUndef($data[$property]) && !empty($data[$property]));  
      }
      return (array_key_exists($property, $data) && !static::isUndef($data[$property]));
    }
    return FALSE;
  }
  
  /**
   * Return all of the supported configuration types.
   */
  public static function types($options = FALSE) {
    static $type_names = array();
    
    $types = array(
      CORAL_TYPE_UNDEF   => t('Undefined'),
      CORAL_TYPE_BOOLEAN => t('Boolean'),
      CORAL_TYPE_NUMBER  => t('Number'), 
      CORAL_TYPE_STRING  => t('String'),
      CORAL_TYPE_TEXT    => t('Text'), 
      CORAL_TYPE_ARRAY   => t('Array'), 
      CORAL_TYPE_HASH    => t('Hash')
    );
    if (empty($type_names)) {
      $type_names = array_keys($types);
    }
    return ($options ? $types : $type_names);
  }
  
  /**
   * Return the internal type for a given data item.
   */
  public static function type($data) {
    if (is_array($data)) {
      $associative = (bool)count(array_filter(array_keys($data), 'is_string'));
      return ( $associative ? CORAL_TYPE_HASH : CORAL_TYPE_ARRAY );
    }
    else {
      $type = gettype($data);
    
      switch ($type) {
        case 'integer':
        case 'double':
          return CORAL_TYPE_NUMBER;
        
        case 'NULL':
          return CORAL_TYPE_UNDEF;
        
        case 'boolean':
          return CORAL_TYPE_BOOLEAN;
        
        case 'string':
          if(is_numeric($data)) {
            return CORAL_TYPE_NUMBER;
          }
          elseif (preg_match('/^\s*(undef|UNDEF|Undef|nil|NIL|Nil)\s*$/', $data)) {
            return CORAL_TYPE_UNDEF;  
          }
          elseif (preg_match('/^\s*(true|TRUE|True|false|FALSE|False)\s*$/', $data)) {
            return CORAL_TYPE_BOOLEAN;
          }
          elseif (preg_match('/\n/', $data)) {
            return CORAL_TYPE_TEXT;
          }
          return CORAL_TYPE_STRING;
      }
      return $type;
    }
  }

  /**
   * Return a boolean indicating whether or not this data is undefined.
   */
  public static function isUndef($data) {
    if (is_null($data)) {
      return TRUE;
    }
    return (is_string($data) ? static::type($data) == CORAL_TYPE_UNDEF : FALSE);
  }

  /**
   * Return a boolean indicating whether or not this data is a boolean value.
   */
  public static function isBool($data) {
    if (is_bool($data)) {
      return TRUE;
    }
    return (is_string($data) ? static::type($data) == CORAL_TYPE_BOOLEAN : FALSE);
  }

  /**
   * Return a boolean indicating whether or not this data is a numeric value.
   */
  public static function isNum($data) {
    return is_numeric($data);
  }

  /**
   * Return a boolean indicating whether or not this data is a string value.
   */
  public static function isStr($data) {
    return is_string($data);
  }

  /**
   * Return a boolean indicating whether or not this data is a sequential array.
   */
  public static function isArray($data) {
    if (!is_array($data)) {
      return FALSE;
    }
    return static::type($data) == CORAL_TYPE_ARRAY;
  }
  
  /**
   * Return a boolean indicating whether or not this data is a hash (associative array).
   */
  public static function isHash($data) {
    if (!is_array($data)) {
      return FALSE;
    }
    return static::type($data) == CORAL_TYPE_HASH;
  }
  
  /**
   * Return true if the data object given is allowed in a configuration.
   */
  public static function allowed($data) {
    return in_array(static::type($data), static::types());
  }
    
  /**
   * Return a data item if it exists or a default value.
   */
  public static function get($data, $key, $default = NULL) {
    if (!$data) {
      return $default;
    }
    
    if (is_string($key)) {
      if (is_array($data) && isset($data[$key])) {
        return $data[$key];
      }
      return $default;
    }
  }
  
  /**
   * Return a data item as an array.
   */
  public static function ensureArray($data, $key, $default = array()) {
    $result = static::get($data, $key, $default);
    
    if (!is_array($result)) {
      return array($result);
    }
    return $result;
  }
    
  /**
   * Convert a data item to internal format.
   */
  public static function internalize($data) {
    switch (static::type($data)) {
      case CORAL_TYPE_UNDEF:
        $data = NULL;
        break;
        
      case CORAL_TYPE_BOOLEAN:
        if (preg_match('^\s*(true|TRUE|True)\s*$')) {
          $data = TRUE;
        }
        else {
          $data = FALSE;
        }
        break;
        
      case CORAL_TYPE_NUMBER:
        if (preg_match('/\./')) {
          $data = (double)$data;
        }
        else {
          $data = (int)$data;
        }
        break;
        
      case CORAL_TYPE_STRING:
      case CORAL_TYPE_TEXT:
        break;
       
      case CORAL_TYPE_ARRAY: 
      case CORAL_TYPE_HASH:
        foreach ($data as $key => $value) {
          $data[$key] = static::internalize($value);
        }
        break;
    }
    return $data;
  }

  /**
   * Convert a data item to external format.
   */
  public static function externalize($data) {
    switch (static::type($data)) {
      case CORAL_TYPE_UNDEF:
        $data = 'UNDEF';
        break;
        
      case CORAL_TYPE_BOOLEAN:
        if ($data) {
          $data = 'TRUE';
        }
        else {
          $data = 'FALSE';
        }
        break;
        
      case CORAL_TYPE_NUMBER:
        $data = (string)$data;
        break;
        
      case CORAL_TYPE_STRING:
      case CORAL_TYPE_TEXT:
        break;
        
      case CORAL_TYPE_ARRAY:
      case CORAL_TYPE_HASH:
        foreach ($data as $key => $value) {
          $data[$key] = static::externalize($value);
        }
        break;
    }
    return $data;
  }
    
  /**
   * Return a normalized value data object for use in the coral_data form element.
   */
  public static function normalize($input) {
    $format = $input['format'];
    $data   = NULL;
  
    switch ($format) {
      case CORAL_TYPE_UNDEF:
        $data = 'UNDEF';
        break;
      
      case CORAL_TYPE_ARRAY:
        $data = array();
        foreach ($input['data'] as &$item) {
          $data[] = static::normalize($item);
        }
        break;
      
      case CORAL_TYPE_HASH:
        $data = array();
        foreach ($input['data'] as $key => &$item) {
          $data[$key] = static::normalize($item);
        }
        break;
      
      default:
        $data = $input['data'];
    }
    return array(
      'format' => $format,
      'data'   => $data
    );
  }
  
  /**
   * Recursively merge associative arrays.
   */
  public static function merge() {
    $hashes  = func_get_args();
    $results = array_shift($hashes);
    foreach ($hashes as $data) {
      if (!empty($data)) {
        $results = static::recursiveMerge($results, $data, TRUE);
      }
    }
    return $results;
  }

  /**
   * Recursively override associative arrays.
   */
  public static function override() {
    $hashes  = func_get_args();
    $results = array_shift($hashes);
    foreach ($hashes as $data) {
      $results = static::recursiveMerge($results, $data, FALSE);
    }
    return $results;
  }

  /**
   * Recursively merge associative arrays. (actual recursive function)
   */
  protected static function recursiveMerge($data, $overrides, $merge_arrays = TRUE) {
    if (static::isUndef($overrides)) { return $data; }
    if (static::isUndef($data)) {      return $overrides; }
    
    if (static::isHash($overrides)) {
      if (static::isHash($data)) {
        // data (hash) <-> overrides (hash)
        foreach ($overrides as $name => $override) {
          if (isset($data[$name]) && !static::isUndef($data[$name])) {
            // data[name] (?!undef) <-> override (?)
            $data[$name] = static::recursiveMerge($data[$name], $override, $merge_arrays);  
          }
          else {
            // data[name] (undef) <-> override (?)
            $data[$name] = $override;
          }
        }
      }
      else {
        // data (?!undef!hash) <-> overrides (hash)
        $data = $overrides;
      }
    }
    elseif (static::isArray($overrides)) {
      if ($merge_arrays && static::isArray($data)) {
        // data (array) <-> overrides (array)
        $data = array_merge($data, $overrides);
      }
      else {
        // data (?!undef!array{unless!merge_arrays}) <-> overrides (array)
        $data = $overrides;
      }
    }
    else {
      // data (?!undef) <-> overrides (?!undef!hash!array)
      $data = $overrides;
    }
    return $data;
  }

  /**
   * Load all defined system formats.
   */
  public static function formats($reload = FALSE) {
    $formats = &drupal_static('coral_formats', array());
    
    if ($reload || empty($formats)) {
      $formats = CoralFormatNode::load(array(), 'static::formatData');
    }
    return $formats;
  }
  
  /**
   * Return array of data for format nodes.
   */
  public static function formatData($node) {
    return array(
      'form_type' => $node->coral->field('form_type'),
      'patterns'  => $node->coral->field('patterns'),
    );
  }
  
  /**
   * Return a list of format options suitable for a select list.
   */
  public static function formatOptions($reload = FALSE) {
    $formats = static::formats($reload);
    $options = array();
    
    foreach ($formats as $nid => $info) {
      $options[$nid] = $info['title'];
    }
    return $options;
  }
}
