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

interface EmailAccount {

	/**
     * returns the panel id (same panel id as in \JetBackup\Core\Panel\Integration\PanelInfo::getId()).
     *
	 * @return string represents the panel.
     * @throws PanelException
	 */
	public function getPanel(): string;

	/**
     * returns the name of the email account.
     *
	 * @return string the name of the email account.
     * @throws PanelException
	 */
	public function getName(): string;

	/**
     * returns the path of the email account directory.
     *
	 * @return string the path for the email account directory.
     * @throws PanelException
	 */
	public function getPath(): string;

	/**
     * returns the quota of the email account.
     *
	 * @return int the quota of the email account.
     * @throws PanelException
	 */
	public function getQuota(): int;

	/**
     * returns the send limit of the email account.
     *
	 * @return int the send limit of the email account.
     * @throws PanelException
	 */
	public function getSendLimit(): int;

	/**
     * returns the password of the email account.
     *
	 * @return string the password of the email account.
     * @throws PanelException
	 */
	public function getPassword(): string;

	/**
     * returns the custom data of the email account (optional, can returns an empty string).
     * it includes any information that the panel needs for the email account.
     * its an internal data of the panel, it can receives whatever the panel needs,
     * the data will be backed up and restored as is.
     *
	 * @return string the custom data of the email account.
     * @throws PanelException
	 */
	public function getCustomData(): string;

	/**
     * removes the email account.
     *
	 * @throws PanelException
	 */
	public function remove();
}