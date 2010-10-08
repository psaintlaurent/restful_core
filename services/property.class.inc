<?php 

/**
 * Example Property Resource  
 * 
 * Valid for the following URI's
 * 
 * /property
 * /property/image
 * /property/product
 * /property/package
 * /property/tag
 * 
 *
 */

class property extends service {
	
	private $image = NULL;
	private $product = NULL;
	private $package = NULL;
	private $tag = NULL;	

	
	public function __construct($json_data, $uri_arr, $request_method) {
		parent::__construct($json_data, $uri_arr, $request_method);		
	}
	
	public function service_default() {
		
	}
	
	protected function clean_input() {
		
		try {
			switch ($this->uri_arr[1]) {

				
				
			}
		}
		catch (ErrorException $ex) {
			
			$this->send_error($ex);
		}
	}
	
	public function product() {
		
		try {
	
			if((include_once '../../services/product.class.inc') === FALSE)
				throw new ErrorException('Missing Class Product');

			$this->uri_arr[1] = 'service_default';
			$product = new product($this->json_data, $this->uri_arr, $this->rm);
			$product->service_default();

		} catch (Exception $ex) {
			
			$this->send_error($ex);
		}
	}
	
	public function package() {
		
		try {
	
			if((include_once '../../services/package.class.inc') === FALSE)
				throw new ErrorException('Missing Class Package');

			$this->uri_arr[1] = 'service_default';
			$package = new package($this->json_data, $this->uri_arr, $this->rm);
			$package->service_default();

		} catch (Exception $ex) {
		
		    $this->send_error($ex);
		}
	}
	
	public function image() {
	
	}
	
	public function tag() {
	
	}
	
	public function __destruct() {
		
	}
}


?>