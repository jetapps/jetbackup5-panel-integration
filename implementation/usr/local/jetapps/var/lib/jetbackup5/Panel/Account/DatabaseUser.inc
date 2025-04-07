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
use JetBackup\Core\Panel\Integration\Account\Database as iDatabase;
use JetBackup\Core\Panel\Integration\Account\DatabaseUser as iDatabaseUser;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class DatabaseUser implements iDatabaseUser {

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
	 * provides the name of the database user.
	 *
	 * @return string|null the database username.
	 */
	public function getName():? string { return $this->_data['name']; }

	/**
	 * provides the password of the database user.
	 * the password must be database engine hashed password.
	 * e.g. '*40ADE30845F3...30869DC5CC4B'.
	 *
	 * @return string|null the database user hashed password.
	 */
	public function getPassword():? string { return $this->_data['password']; }

	/**
	 * provides the engine of the database.
	 *
	 * @return int the database engine (see @uses for available engine types).
	 *
	 * @uses iDatabase::ENGINE_MYSQL mysql database engine.
	 * @uses iDatabase::ENGINE_MONGODB mogodb database engine.
	 * @uses iDatabase::ENGINE_POSTGRESQL postgresql database engine.
	 */
	public function getEngine(): int { return $this->_data['engine']; }

	/**
	 * provides the privileges of the database user.
	 *
	 * @return DatabaseUserPrivileges[] array of DatabaseUserPrivileges - holds all the needed information about the database user privileges.
	 */
	public function getPrivileges(): array { return $this->_data['privileges']; }

	/**
	 * provides the custom data of the database user (optional, can return an empty string).
	 * it includes any information that the panel needs for the database user.
	 * it's an internal data of the panel, it can receive whatever the panel needs,
	 * the data will be backed up and restored as is.
	 *
	 * @return string the custom data of the database user.
	 */
	public function getCustomData(): string { return ''; }

	/**
	 * removes the database user.
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with removing the database user.
	 */
	public function remove():void {
		// TODO implement, remove this database user for this account
		// e.g. DELETE FROM database_users WHERE account = '{$this->_account->getUsername()}' AND name = '{$this->getName()}'
	}
}