<?php

/**
 * Database Singleton
 * 
 *
 */
class db {

  private static $dbh = NULL;
  private static $caller_id = NULL;
  
  private function __construct() {
  	
  }
  
  public static function get_dbh() {
  	
      if(self::$dbh == NULL) 
      {
		self::$dbh = new PDO("pgsql:host=localhost;dbname=".DBNAME, DBUSER, DBPASS, array(PDO::ATTR_PERSISTENT => TRUE));
		$stmt = self::$dbh->prepare('SELECT id FROM open_availability.user WHERE name = :name AND password = md5(:password)'); //yes md5 is a bad idea but this is just for fun
		$stmt->bindParam('name', $_SERVER['PHP_AUTH_USER']);
		$stmt->bindParam('password', $_SERVER['PHP_AUTH_PW']);
		$stmt->execute();
		$row = $stmt->FetchAll(PDO::FETCH_ASSOC);		

		self::$dbh->caller_id = $row[0]['id'];
      }
      return self::$dbh;
  }
  
  
  private function __destruct() {

  }
  
}


?>