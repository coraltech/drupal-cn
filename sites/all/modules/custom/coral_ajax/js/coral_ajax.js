(function ($) {

  Drupal.coral_ajax = Drupal.coral_ajax || {};
  
  Drupal.coral_ajax.get = function(type, id, success, error) {
    $.ajax({
      url:'/system/'+type+'/'+id+'.json',
      dataType: 'json',
      success: success,
      error: error
    });
  };
  
  Drupal.coral_ajax.put = function(type, id, entity, success, error) {
    $.ajax({
      url:'/system/'+type+'/'+id,
      type: "PUT",
      data: entity,
      success: success,
      error: error
    });
  };
  
  Drupal.coral_ajax.view_get = function(view_name, options, success, error) {
    
    var data = {};
    if (options.hasOwnProperty('args'))          data['args'] = options['args'];    
    if (options.hasOwnProperty('limit'))         data['limit'] = options['limit'];
    if (options.hasOwnProperty('offset'))        data['offset'] = options['offset'];
    if (options.hasOwnProperty('filters'))       data['filters'] = options['filters'];
    if (options.hasOwnProperty('format_output')) data['format_output'] = options['format_output'];
    
    $.ajax({
      url:'/api/view/'+view_name+'.json',
      dataType: 'json',
      data: data,
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
    Drupal.ajax_lib.put('node', id, entity, success, error);
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