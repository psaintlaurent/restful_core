<?php 

/**
 * Example Package Resource  
 * 
 * Valid for the following URI's
 * 
 * /package
 * /package/product
 * 
 */

class package extends service {
	
	private $product = NULL;
	
	public function __construct($json_data, $uri_arr, $request_method) {
		parent::__construct($json_data, $uri_arr, $request_method);		
	}
	
	public function service_default() {
			if($this->rm == '_GET') {
			try {			
				
				$stmt = $this->dbh->prepare('SELECT * FROM schema1.property_package_list(:caller_id, :user_id_in, :property_id_in, :qtext, :limit) AS (json_data text);', array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
				
				$stmt->bindParam('caller_id', $this->dbh->caller_id);			
				$stmt->bindParam('user_id_in', $this->uid); 
				$stmt->bindParam('property_id_in', $this->property_id);
				$stmt->bindParam('qtext', $this->qtext);
				$stmt->bindParam('limit', $this->limit);

				if($stmt->execute()){
				header('Content-type: application/json');
					do {
						$row = $stmt->fetch(PDO::FETCH_NUM, PDO::FETCH_ORI_NEXT, PDO::FETCH_ASSOC);
						echo $row[0];
					}
					while($row !== FALSE);
				}
				else throw new PDOException();
			}
			catch (PDOException $ex) {
					$this->send_error($ex);
			}			
		}
	}
	
	protected function clean_input() {
		
		try {
			
			switch ($this->uri_arr[1]) {
				
				case 'service_default':
					$this->uid = (isset($this->json_data->uid) && filter_var($this->json_data->uid, FILTER_VALIDATE_INT)) ? $this->json_data->uid : $this->dbh->caller_id;
					$this->qtext = (isset($this->json_data->qtext)) ? filter_var($this->json_data->qtext, FILTER_SANITIZE_STRING | FILTER_SANITIZE_SPECIAL_CHARS) : ' ';
					$this->property_id = (isset($this->json_data->property_id) && filter_var($this->json_data->property_id, FILTER_VALIDATE_INT)) ? $this->json_data->property_id : NULL;
				default: 					
					break;
			}
			
		} catch (Exception $ex) {		
			$this->send_error($ex);
		}
	}
	
	public function __destruct() {
		
	}
}

?>