<?php
/*
*
* JetBackup @ package
* Created By Idan Ben-Ezra
*
* Copyrights @ JetApps
* https://www.jetapps.com
*
**/
namespace JetBackup\Core\Exception;

use throwable;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class APIException extends JBException {
	private array $data;

	/**
	 * @param string $message
	 * @param array $data
	 * @param int $code
	 * @param throwable|null $previous
	 */
	public function __construct(string $message="", array $data=[], int $code = 0, throwable|null $previous=null) {
		$this->data = $data;
		parent::__construct($message, $code, $previous);
	}

	public function getData():array { return $this->data; }
}