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

interface FTPAccount {

	/**
     * provides the panel id.
     * the panel id is the same panel id as in \JetBackup\Core\Panel\Integration\PanelInfo::getId().
     *
	 * @return string represents the panel.
	 */
	public function getPanel(): string;

	/**
     * provides the quota of the ftp account.
     *
	 * @return int the quota of the ftp account.
	 */
	public function getQuota(): int;

	/**
     * provides the name of the ftp account.
     *
	 * @return string the name of the ftp account.
	 */
	public function getName(): string;

	/**
     * provides the password of the ftp account.
     *
	 * @return string the password of the ftp account.
	 */
	public function getPassword(): string;

	/**
     * provides the path of the ftp account.
     *
	 * @return string the path of the ftp account.
	 */
	public function getPath(): string;

	/**
     * provides the custom data of the ftp account (optional, can returns an empty string).
     * it includes any information that the panel needs for the ftp account.
     * its an internal data of the panel, it can receives whatever the panel needs,
     * the data will be backed up and restored as is.
     *
	 * @return string the custom data of the ftp account.
	 */
	public function getCustomData(): string;

	/**
     * removes the ftp account.
     *
	 * @return void
	 * @throws PanelException throws if there is an issue with removing the ftp account.
	 */
	public function remove();
}