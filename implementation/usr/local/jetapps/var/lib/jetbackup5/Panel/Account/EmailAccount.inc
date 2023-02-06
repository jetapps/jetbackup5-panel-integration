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
namespace JetBackup\Panel\Account;

use JetBackup\Core\Exception\PanelException;
use JetBackup\Core\Panel\Integration\Account\EmailFilter\EmailFilter;
use JetBackup\Panel\Panel;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class EmailAccount implements \JetBackup\Core\Panel\Integration\Account\EmailAccount {

	/**
	 * provides the panel id.
	 * the panel id needs to be as follows 'MyCompany_PanelName'.
	 * e.g. 'JetApps_cPanel'.
	 *
	 * @return string represents the panel.
	 */
	public function getPanel(): string { return Panel::_getId(); }

	/**
	 * provides the name of the email account.
	 *
	 * @return string the name of the email account.
	 */
	public function getName(): string { return 'email@acct1.com'; }

	/**
	 * provides the path of the email account directory.
	 *
	 * @return string the path for the email account directory.
	 */
	public function getPath(): string { return '/path/to/mailbox'; }

	/**
	 * provides the quota of the email account.
	 *
	 * @return int the quota of the email account.
	 */
	public function getQuota(): int { return 0; }

	/**
	 * provides the "send limit" of the email account.
	 *
	 * @return int the "send limit" of the email account.
	 */
	public function getSendLimit(): int { return 0; }

	/**
	 * provides the password of the email account.
	 * the password must be linux hashed password.
	 * e.g. '$6$gCkMes6kAaTVnP9j$rdBl...S8ectusndrupAIRAdtQatY1'.
	 *
	 * @return string the email account hashed password.
	 */
	public function getPassword(): string { return '$6$Fg5PejVYNxGTafDO$5mKgXEIBpH6ZXT5mYO9boTCPif7jgpCuu.MbOVWzwnTUYJ/iZ5WVlKEDEBmtq0jatjFQWfD8oXruxXJEQPLOW.'; }

	/**
	 * @return EmailFilter[]
	 */
	public function getFilters(): array {
		return [new \JetBackup\Panel\Account\EmailFilter\EmailFilter()];
	}

	/**
	 * provides the custom data of the email account (optional, can return an empty string).
	 * it includes any information that the panel needs for the email account.
	 * it's an internal data of the panel, it can receive whatever the panel needs,
	 * the data will be backed up and restored as is.
	 *
	 * @return string the custom data of the email account.
	 */
	public function getCustomData(): string { return ''; }

	/**
	 * removes the email account.
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with removing the email account.
	 */
	public function remove() {}
}