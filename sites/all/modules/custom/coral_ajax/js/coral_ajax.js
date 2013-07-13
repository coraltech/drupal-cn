(function ($) {

  Drupal.coral_ajax = Drupal.coral_ajax || {};
  
  Drupal.coral_ajax.create = function(type, entity, success, error) {
    var data = {};
    data[type] = entity;
    
    $.ajax({
      url:'/system/'+type+'.json',
      type: "POST",
      data: JSON.stringify(data),
      contentType: 'application/json',
      dataType: 'json',      
      success: success,
      error: error
    });
  };
  
  Drupal.coral_ajax.get = function(type, id, success, error) {
    $.ajax({
      url:'/system/'+type+'/'+id+'.json',
      dataType: 'json',
      success: success,
      error: error
    });
  };
  
  Drupal.coral_ajax.update = function(type, id, entity, success, error) {
    var data = {};
    data[type] = entity;
    
    $.ajax({
      url:'/system/'+type+'/'+id+'.json',
      type: "PUT",
      data: JSON.stringify(data),
      contentType: 'application/json',
      dataType: 'json',      
      success: success,
      error: error
    });
  };
  
  Drupal.coral_ajax.remove = function(type, id, success, error) {
    $.ajax({
      url:'/system/'+type+'/'+id+'.json',
      type: "DELETE",
      dataType: 'json',
      success: success,
      error: error
    });
  };
  
  Drupal.coral_ajax.view_get = function(view_name, options, success, error) {
    $.ajax({
      url:'/api/view/'+view_name+'.json',
      dataType: 'json',
      data: options,
      success: success,
      error: error
    });
  };
  
  Drupal.coral_ajax.view_render = function(view_name, options, success, error) {
    options['format_output'] = true;
    
    Drupal.coral_ajax.view_get(view_name, options, function(data) {
      success(data[0]);
    }, error);
  };
  
  //-----------------------------------------------------------------------------
  
  Drupal.coral_ajax.node_load = function(id, success, error) {
    Drupal.coral_ajax.get('node', id, success, error); 
  };
  
  Drupal.coral_ajax.node_save = function(id, entity, success, error) {
    Drupal.coral_ajax.update('node', id, entity, success, error);
  };
  
  Drupal.coral_ajax.node_create = function(entity, success, error) {
    Drupal.coral_ajax.create('node', entity, success, error);
  };
  
  Drupal.coral_ajax.node_delete = function(id, entity, success, error) {
    Drupal.coral_ajax.remove('node', id, entity, success, error);
  };
  
  Drupal.coral_ajax.user_load = function(id, success, error) {
    Drupal.coral_ajax.get('user', id, success, error); 
  };
  
  Drupal.coral_ajax.user_save = function(id, entity, success, error) {
    Drupal.coral_ajax.put('user', id, entity, success, error);
  };
  
  Drupal.coral_ajax.current_user = function(success, error) {
    Drupal.coral_ajax.view_get('current_user', {}, success, error);
  };

})(jQuery);