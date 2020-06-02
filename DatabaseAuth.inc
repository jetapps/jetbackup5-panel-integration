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
namespace JetBackup\Core\Panel\Integration;

use JetBackup\Core\Exception\PanelException;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface DatabaseAuth {

	/**
     * returns the database authentication port.
     *
	 * @return int the database auth port.
     * @throws PanelException
	 */
	public function getPort(): int;

	/**
     * returns the database authentication host name.
     *
	 * @return string the database auth host name.
     * @throws PanelException
	 */
	public function getHostname(): string;

	/**
     * returns the database authentication username.
     *
	 * @return string the database auth username.
     * @throws PanelException
	 */
	public function getUsername(): string;

	/**
     * returns the database authentication password.
     *
	 * @return string the database auth password.
     * @throws PanelException
	 */
	public function getPassword(): string;

	/**
     * returns the authentication database.
	 * use only on MongoDb database type.
	 *
	 * @return string the authentication database.
     * @throws PanelException
	 */
	public function getAuthDatabase(): string;
}