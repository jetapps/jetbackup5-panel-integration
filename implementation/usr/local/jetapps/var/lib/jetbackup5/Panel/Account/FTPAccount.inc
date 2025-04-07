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
use JetBackup\Panel\Panel;
use JetBackup\Core\Panel\Integration\Account\FTPAccount as iFTPAccount;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class FTPAccount implements iFTPAccount {

	private array $_data;
	private Account $_account;

	public function __construct(Account $account, array $data) {
		$this->_data = $data;
		$this->_account = $account;
	}

	/**
	 * provides the panel id.
	 * the panel id needs to be as follows 'MyCompany_PanelName'.
	 * e.g. 'JetApps_cPanel'.
	 *
	 * @return string represents the panel.
	 */
	public function getPanel(): string { return Panel::_getId(); }

	/**
	 * provides the quota of the ftp account.
	 *
	 * @return int the quota of the ftp account.
	 */
	public function getQuota(): int { return 0; }

	/**
	 * provides the name of the ftp account.
	 *
	 * @return string the name of the ftp account.
	 */
	public function getName(): string { return $this->_data['name']; }

	/**
	 * provides the password of the ftp account.
	 * the password must be linux hashed password.
	 * e.g. '$6$gCkMes6kAaTVnP9j$rdBl...S8ectusndrupAIRAdtQatY1'.
	 *
	 * @return string the ftp account hashed password.
	 */
	public function getPassword(): string { return $this->_data['password']; }

	/**
	 * provides the path of the ftp account.
	 *
	 * @return string the path of the ftp account.
	 */
	public function getPath(): string { return $this->_data['path']; }

	/**
	 * provides the custom data of the ftp account (optional, can return an empty string).
	 * it includes any information that the panel needs for the ftp account.
	 * it's an internal data of the panel, it can receive whatever the panel needs,
	 * the data will be backed up and restored as is.
	 *
	 * @return string the custom data of the ftp account.
	 */
	public function getCustomData(): string { return ''; }

	/**
	 * removes the ftp account.
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with removing the ftp account.
	 */
	public function remove():void {
		// TODO implement, remove this ftp account for this account
		// e.g. DELETE FROM ftp_accounts WHERE account = '{$this->_account->getUsername()}' AND name = '{$this->getName()}'
	}
}