<?php
/*
*
* JetBackup @ package
* Created By Idan Ben-Ezra
*
* Copyrights @ JetApps
* http://www.jetapps.com
*
**/
namespace  JetBackup\Core\API;

if(!defined('__JETBACKUP__')) die('Restricted Access!');

class API {

	const string OUTPUT_TYPE_JSON = 'json';
	const string OUTPUT_TYPE_PLAIN = 'plain';

	const int STATUS_SUCCESS    = 0;
	const int STATUS_FAILED     = 1;
	const int STATUS_ERROR      = 2;
	
	public static function run(int $uid, string|null $virtual_username=null, string $output_type=self::OUTPUT_TYPE_JSON, bool $return_output=false):string {}
	public static function outputFormat(int $status=self::STATUS_FAILED, string $message='', array $data=[], string $type=self::OUTPUT_TYPE_JSON):string {}
}