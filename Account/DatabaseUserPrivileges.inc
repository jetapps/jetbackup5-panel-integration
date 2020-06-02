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

interface DatabaseUserPrivileges {

	/**
     * returns the database name.
     *
	 * @return string the database name.
     * @throws PanelException
	 */
	public function getDatabaseName(): string;

	/**
     * returns the database user grants.
     *
	 * @return array an array with all of the database user grants.
     * @throws PanelException
	 */
	public function getGrants(): array;
}