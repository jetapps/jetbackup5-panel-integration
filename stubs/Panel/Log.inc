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
namespace JetBackup\Core\Panel;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class Log {
	public function logMessage($message) {}
	public function logDebug($message) {}
	public function logError($message) {}
}