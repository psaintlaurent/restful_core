<?php 

/**
 * Example Group Resource  
 * 
 * Valid for the following URI's
 * 
 * /group
 *
 */

class group extends service {
	
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