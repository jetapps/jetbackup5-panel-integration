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

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface DatabaseUserPrivileges {

	/**
	 * provides the database name.
	 *
	 * @return string the database name.
	 */
	public function getDatabaseName(): string;

	/**
	 * provides the database user grants.
	 * e.g. ["INSERT","UPDATE","SELECT"]
	 *
	 * @return array an array with all the database user grants.
	 */
	public function getGrants(): array;
}