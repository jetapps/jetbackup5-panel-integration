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
     * returns the panel id (same panel id as in \JetBackup\Core\Panel\Integration\PanelInfo::getId()).
     *
	 * @return string represents the panel.
     * @throws PanelException
	 */
	public function getPanel(): string;

	/**
     * returns the name of the database user.
     *
	 * @return string|null the database user name.
     * @throws PanelException
	 */
	public function getName():? string;

	/**
     * returns the password of the database user.
     *
	 * @return string|null the database user password.
     * @throws PanelException
	 */
	public function getPassword():? string;

	/**
     * returns the engine of the database.
     *
	 * @return int the database engine.
     *
     * @uses Database::ENGINE_MYSQL mysql database engine.
     * @uses Database::ENGINE_MONGODB mogodb database engine.
     * @uses Database::ENGINE_POSTGRESQL postgresql database engine.
     *
     * @throws PanelException
	 */
	public function getEngine(): int;

	/**
     * returns the privileges of the database user.
     *
	 * @return DatabaseUserPrivileges[] array of DatabaseUserPrivileges - holds all the needed information about the database user privileges.
     * @throws PanelException
	 */
	public function getPrivileges(): array;

	/**
     * returns the custom data of the database user (optional, can returns an empty string).
     * it includes any information that the panel needs for the database user.
     * its an internal data of the panel, it can receives whatever the panel needs,
     * the data will be backed up and restored as is.
     *
	 * @return string the custom data of the database user.
     * @throws PanelException
	 */
	public function getCustomData(): string;

	/**
     * removes the database user.
     *
     * @return void
	 * @throws PanelException
	 */
	public function remove();
}