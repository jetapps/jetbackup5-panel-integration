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
namespace JetBackup\Core\Panel\Integration\Account\EmailFilter;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface EmailFilter {

	/**
	 * provides the name of the email account.
	 *
	 * @return string the name of the email account.
	 */
	public function getName(): string;

	/**
	 * @return Rule[]
	 */
	public function getRules(): array;

	/**
	 * @return Action[]
	 */
	public function getActions(): array;
}