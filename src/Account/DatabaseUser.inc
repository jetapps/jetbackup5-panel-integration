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
	 * the panel id needs to be as follows 'MyCompany_PanelName'.
	 * e.g. 'JetApps_cPanel'.
	 *
	 * @return string represents the panel.
	 */
	public function getPanel(): string;

	/**
	 * provides the name of the database user.
	 *
	 * @return string|null the database username.
	 */
	public function getName():string|null;

	/**
	 * provides the password of the database user.
	 * the password must be database engine hashed password.
	 * e.g. '*40ADE30845F3...30869DC5CC4B'.
	 *
	 * @return string|null the database user hashed password.
	 */
	public function getPassword():string|null;

	/**
	 * provides the engine of the database.
	 *
	 * @return int the database engine (see @uses for available engine types).
	 *
	 * @uses Database::ENGINE_MYSQL mysql database engine.
	 * @uses Database::ENGINE_MONGODB mogodb database engine.
	 * @uses Database::ENGINE_POSTGRESQL postgresql database engine.
	 */
	public function getEngine(): int;

	/**
	 * provides the privileges of the database user.
	 *
	 * @return DatabaseUserPrivileges[] array of DatabaseUserPrivileges - holds all the needed information about the database user privileges.
	 */
	public function getPrivileges(): array;

	/**
	 * provides the custom data of the database user (optional, can return an empty string).
	 * it includes any information that the panel needs for the database user.
	 * it's an internal data of the panel, it can receive whatever the panel needs,
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
	public function remove():void;
}