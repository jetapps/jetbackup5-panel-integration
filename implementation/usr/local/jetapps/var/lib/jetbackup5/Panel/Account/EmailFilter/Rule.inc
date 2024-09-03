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

use JetBackup\Core\Panel\Integration\Account\EmailFilter\Rule as iRule;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class Rule implements iRule {
	
	/**
	 * @return int
	 */
	public function getPart(): int {}

	/**
	 * @return int
	 */
	public function getMatch(): int {}

	/**
	 * @return string
	 */
	public function getValue(): string {}

	/**
	 * @return int
	 */
	public function getCondition(): int {}
}