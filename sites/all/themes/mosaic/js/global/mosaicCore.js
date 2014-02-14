// This file will provide a central access point for mosaic components

// Registers the Mosaic namespace
Drupal.mosaic = Drupal.mosaic || {};

// Document loaded!
(function($) {

  Drupal.behaviors.mosaicInit = {
    attach : function(context, settings) {
      try {// Use try to prevent systemic failure
        if (!Drupal.mosaic.hasOwnProperty('core')) {
          Drupal.mosaic.core = new Drupal.mosaic.mosaicCore();
          Drupal.mosaic.core.objects = {}; // other components can add centralized objects here
        }
      } catch (err) {
        console.log('mosaicInit() reported errors. Error: ' + err);
      }
    }
  };
  
  
  // Core core
  Drupal.mosaic.mosaicCore = function() {
    try {
      // Honestly, there is nothing to do here.
      // This serves as a root for attaching 
      // functionality to a common object.     
    }
    catch (err) {
      console.log('mosaicCore errored: '+err);
    }
  };
  
  
  // Analyze the object and pull ID data
  // Inputs:
  //  pat (string) - a pattern to search for; defaults to /node-\d+/
  //  cls (string) - a class to replace with empty space; harvesting the integer
  Drupal.mosaic.mosaicCore.prototype.initID = function($obj, pat, cls) {
    try {
      var objPattern = pat || /node-\d+/;
      var objClass = cls || 'node-';
  
      // find this button's nid and ensure the AnswerView's  
      var classes = $obj.attr('class');
      classes = classes.split(" ");
      for (cls in classes) {
        var c = classes[cls];
        if (c.match(objPattern)) {
          return c.replace(objClass, ''); // and the nid
        }
      }
    }
    catch (err) {
      console.log('initID errored: '+err);
    }
  };
  
  
  // Create a unique ID that can be applied to an element
  Drupal.mosaic.mosaicCore.prototype.createID = function($obj, regen) {
    try {
    	var regen = regen || false;
    	if (!$obj.prop('id') || regen) {
	      var time = $.now();
	      var rand = Math.floor((Math.random() * 10000) + 1);
	      var id   = time+"-"+rand; 
	      if ($('#'+id).length) id = this.createID($obj); // already exists - create another
	      $obj.prop('id', id); // ensure the id is set
	      return id;
     	}
     	else {
     		return $obj.prop('id');
     	}
    }
    catch (err) {
      console.log('createID errored: '+err);
    }
  };
  
  
  // Get url query params
  Drupal.mosaic.mosaicCore.prototype.getQueryParams = function(url) {
    try {
      var result = {};
      var searchIndex = url.indexOf("?");
      if (searchIndex == -1 ) return result;
      var sPageURL = url.substring(searchIndex +1);
      var sURLVariables = sPageURL.split('&');
      for (var i = 0; i < sURLVariables.length; i++)
      {       
          var sParameterName = sURLVariables[i].split('=');      
          result[sParameterName[0]] = sParameterName[1];
      }
      return result;
    }
    catch (err) {
      console.log('getQueryParams errored: '+err);
    }
  };
  
  
  Drupal.mosaic.mosaicCore.prototype.ucFirst = function(str) {
    try {
      // From: http://phpjs.org/functions
      // +   original by: Kevin van Zonneveld (http://kevin.vanzonneveld.net)
      // +   bugfixed by: Onno Marsman
      // +   improved by: Brett Zamir (http://brett-zamir.me)
      // *     example 1: ucfirst('kevin van zonneveld');
      // *     returns 1: 'Kevin van zonneveld'
      str += '';
      var f = str.charAt(0).toUpperCase();
      return f + str.substr(1);
    }
    catch (err) {
      console.log('ucFirst errored: '+err);
    }
    
  };
  
  // Adapted from a post: https://gist.github.com/bradvin/2313262
	Drupal.mosaic.mosaicCore.prototype.loadScript = function (url, arg1, arg2) {
		var cache = false, callback = null;

		//arg1 and arg2 can be interchangable as either the callback function or the cache bool
		if ($.isFunction(arg1)){
			callback = arg1;
			cache = arg2 || cache;
		} else {
			cache = arg1 || cache;
			callback = arg2 || callback;
		}

		var load = true;
		//check all existing script tags in the page for the url we are trying to load
		jQuery('script[type="text/javascript"]').each(function() { return load = (url != $(this).attr('src')); });
		
		if (load) {
			//didn't find it in the page, so load it
			//equivalent to a jQuery.getScript but with control over cacheing
			jQuery.ajax({
				type: 'GET',
				url: url,
				success: callback,
				dataType: 'script',
				cache: cache
			});
		} 
	  
	  else {
	  //already loaded so just call the callback
		if (jQuery.isFunction(callback)) {
	    	callback.call(this);
	  	}
		}
	};
  
  
  Drupal.mosaic.mosaicCore.prototype.objCount = function(obj) {
  	var count = 0;

		for (var i in obj) {
		  if (obj.hasOwnProperty(i)) {
		    count++;
		  }
		}

		return count;
  };

})(jQuery);

