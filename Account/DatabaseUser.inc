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

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface DatabaseUser {

	/**
	 * provides the panel id.
	 * the panel id is the same panel id as in \JetBackup\Core\Panel\Integration\PanelInfo::getId().
	 *
	 * @return string represents the panel.
	 */
	public function getPanel(): string;

	/**
	 * provides the name of the database user.
	 *
	 * @return string|null the database user name.
	 */
	public function getName():? string;

	/**
	 * provides the password of the database user.
	 *
	 * @return string|null the database user password.
	 */
	public function getPassword():? string;

	/**
	 * provides the engine of the database.
	 *
	 * @return int the database engine (see @uses for available engine types).
	 *
	 * @uses \JetBackup\Core\Panel\Integration\Account\Database::ENGINE_MYSQL mysql database engine.
	 * @uses \JetBackup\Core\Panel\Integration\Account\Database::ENGINE_MONGODB mogodb database engine.
	 * @uses \JetBackup\Core\Panel\Integration\Account\Database::ENGINE_POSTGRESQL postgresql database engine.
	 */
	public function getEngine(): int;

	/**
	 * provides the privileges of the database user.
	 *
	 * @return DatabaseUserPrivileges[] array of DatabaseUserPrivileges - holds all the needed information about the database user privileges.
	 */
	public function getPrivileges(): array;

	/**
	 * provides the custom data of the database user (optional, can returns an empty string).
	 * it includes any information that the panel needs for the database user.
	 * its an internal data of the panel, it can receives whatever the panel needs,
	 * the data will be backed up and restored as is.
	 *
	 * @return string the custom data of the database user.
	 */
	public function getCustomData(): string;

	/**
	 * removes the database user.
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with removing the database user.
	 */
	public function remove();
}