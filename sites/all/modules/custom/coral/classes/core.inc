<?php
coral_include('classes/data');

//------------------------------------------------------------------------------
// Core functionality

class Coral extends CoralData {

  /**
   * Ensure an object is attached to the given object or array.
   */
  public static function ensure(&$object, $property, $class, $properties = array()) {
    if (static::isHash($object)) {
      if (!isset($object[$property]) || !$object[$property] instanceof $class) {
        $object[$property] = static::create($class, $properties);
      }
      elseif (!is_null($properties)) {
        static::exec($object[$property], 'set', array(&$properties));
      }
    }
    elseif(is_object($object)) {
      if (!property_exists($object, $property) || !$object->$property || !$object->$property instanceof $class) {
        $object->$property = static::create($class, $properties);
      }
      elseif (!is_null($properties)) {
        static::exec($object->$property, 'set', array(&$properties));
      }
    }
  }

  /**
   * Create a new Coral object of a given class.
   */
  public static function create($class, $properties = array()) {
    $saved_variables = variable_get('coral_object_class_variables');
    
    $class_name = strtolower($class);
    $variable   = "${class_name}_class";
    
    if (!in_array($variable, $saved_variables)) {
      array_push($saved_variables, $variable);
      variable_set('coral_object_class_variables', $saved_variables);
    }
    
    $class = variable_get($variable, $class);
    return new $class($properties);  
  }

  /**
   * Execute a Coral object method if it exists.
   */
  public static function exec($object, $method, $params = array(), $default = NULL) {
    if ((is_object($object) || is_string($object)) && method_exists($object, $method)) {
      return call_user_func_array(array($object, $method), $params);
    }
    return $default;
  }
}
