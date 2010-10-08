<?php 

/**
 * Example Image Resource  
 * 
 * Valid for the following URI's
 * 
 * /image
 * /image/tag
 * 
 */

class Image extends service {
	
	private $tag = NULL;
	
	public function __construct($json_data, $uri_arr, $request_method) {
		parent::__construct($json_data, $uri_arr, $request_method);		
	}
	
	protected function service_default()
	{
		
	}
	
	protected function clean_input() {
		
	}
	
	public function __destruct() {
		
	}
}

?>