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
namespace JetBackup\Panel\Account\EmailFilter;

use JetBackup\Core\Panel\Integration\Account\EmailFilter\Action as iAction;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class Action implements iAction {
	
	/**
	 * @return int
	 */
	public function getAction(): int {}

	/**
	 * @return string
	 */
	public function getValue():? string {}
}