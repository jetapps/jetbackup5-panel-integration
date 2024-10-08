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

use JetBackup\Core\Panel\Integration\Account\DatabaseUserPrivileges as iDatabaseUserPrivileges;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class DatabaseUserPrivileges implements iDatabaseUserPrivileges {

	/**
	 * provides the database name.
	 *
	 * @return string the database name.
	 */
	public function getDatabaseName(): string { return 'acct1_mydb'; }

	/**
	 * provides the database user grants.
	 * e.g. ["INSERT","UPDATE","SELECT"]
	 *
	 * @return array an array with all the database user grants.
	 */
	public function getGrants(): array { return ["INSERT","UPDATE","SELECT"]; }
}