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

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface DatabaseAuth {

	/**
	 * provides the database authentication port.
	 *
	 * @return int the database auth port.
	 */
	public function getPort(): int;

	/**
	 * provides the database authentication host name.
	 *
	 * @return string the database auth host name.
	 */
	public function getHostname(): string;

	/**
	 * provides the database authentication username.
	 *
	 * @return string the database auth username.
	 */
	public function getUsername(): string;

	/**
	 * provides the database authentication password.
	 *
	 * @return string the database auth password.
	 */
	public function getPassword(): string;

	/**
	 * provides the authentication database.
	 * use only on MongoDb database type.
	 *
	 * @return string the authentication database.
	 */
	public function getAuthDatabase(): string;

	/**
	 * provides the database socket to connect to.
	 * 
	 * @return string|null
	 */
	public function getSocket():? string;

	/**
	 * provides the database engine lib directory.
	 * 
	 * @return string
	 */
	public function getLibDir(): string;

	/**
	 * returns true if the database is stored locally and false otherwise.
	 * 
	 * @return bool
	 */
	public function isLocal(): bool;
}