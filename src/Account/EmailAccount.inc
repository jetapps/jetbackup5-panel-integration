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
namespace JetBackup\Core\Panel\Integration\Account;

use JetBackup\Core\Exception\PanelException;
use JetBackup\Core\Panel\Integration\Account\EmailFilter\EmailFilter;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface EmailAccount {

	/**
	 * provides the panel id.
	 * the panel id needs to be as follows 'MyCompany_PanelName'.
	 * e.g. 'JetApps_cPanel'.
	 *
	 * @return string represents the panel.
	 */
	public function getPanel(): string;

	/**
	 * provides the name of the email account.
	 *
	 * @return string the name of the email account.
	 */
	public function getName(): string;

	/**
	 * provides the path of the email account directory.
	 *
	 * @return string the path for the email account directory.
	 */
	public function getPath(): string;

	/**
	 * provides the quota of the email account.
	 *
	 * @return int the quota of the email account.
	 */
	public function getQuota(): int;

	/**
	 * provides the "send limit" of the email account.
	 *
	 * @return int the "send limit" of the email account.
	 */
	public function getSendLimit(): int;

	/**
	 * provides the password of the email account.
	 * the password must be linux hashed password.
	 * e.g. '$6$gCkMes6kAaTVnP9j$rdBl...S8ectusndrupAIRAdtQatY1'.
	 *
	 * @return string the email account hashed password.
	 */
	public function getPassword(): string;

	/**
	 * @return EmailFilter[]
	 */
	public function getFilters(): array;

	/**
	 * provides the custom data of the email account (optional, can return an empty string).
	 * it includes any information that the panel needs for the email account.
	 * it's an internal data of the panel, it can receive whatever the panel needs,
	 * the data will be backed up and restored as is.
	 *
	 * @return string the custom data of the email account.
	 */
	public function getCustomData(): string;

	/**
	 * removes the email account.
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with removing the email account.
	 */
	public function remove():void;
}