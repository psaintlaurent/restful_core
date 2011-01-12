<?php

global $_PUT, $_DELETE; //create global variables for holding PUT and DELETE requests
date_default_timezone_set('America/New_York');

if($_SERVER['REQUEST_METHOD'] == 'PUT') {
	parse_str(file_get_contents("php://input"), $_PUT);
	$_REQUEST['json_data'] = $_PUT['json_data'];
} elseif($_SERVER['REQUEST_METHOD'] == 'DELETE') {
	parse_str(file_get_contents("php://input"), $_DELETE);
	$_REQUEST['json_data'] = $_DELETE['json_data'];
}

if (!isset($PHP_AUTH_USER)) {
    header('WWW-Authenticate: Basic realm="MyRealm"');
    header('HTTP/1.0 401 Unauthorized');
    echo json_encode(array('error'=>'Authentication Required'));
    exit;
}

require_once('../../library/service.class.inc');
require_once('../../library/db.class.inc');

try {
	
	$request_uri = preg_replace(array('/\?.*/', '/\/rest/'), '', $_SERVER['REQUEST_URI']);  //strip out input parameters from the request uri
	$invalid_methods = array('__construct', '__destruct');
	$uri_arr = explode('/', trim($request_uri, '/'));

	if((include_once '../../services/'.$uri_arr[0].'.class.inc') === FALSE)
		throw new ErrorException();
	
	$json_data = (isset($_REQUEST['json_data'])) ? $_REQUEST['json_data']: NULL; 
	$service = new $uri_arr[0]($json_data, $uri_arr, $_SERVER['REQUEST_METHOD']);
	
	if(method_exists($service, $uri_arr[1]) && !in_array($uri_arr[1], $invalid_methods))
		$service->$uri_arr[1]();
	else if(isset($uri_arr[1]))
		throw new ErrorException();
	else
		$service->service_default();
}
catch (ErrorException $e) {
	
	header("HTTP/1.0 404 Not Found");
	exit();
}









?>
