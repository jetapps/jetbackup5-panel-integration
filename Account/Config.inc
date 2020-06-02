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

interface Config {

	/**
     * returns the panel id (same panel id as in \JetBackup\Core\Panel\Integration\PanelInfo::getId()).
     *
	 * @return string represents the panel.
     * @throws PanelException
	 */
	public function getPanel(): string;

	/**
     * returns the path for the config files, that contains all the information about the
     * user that the panel needs in order to create the account in the case of account restoration.
     *
	 * @return string|null the path for the config files.
     * @throws PanelException
	 */
	public function getPath():? string;

	/**
     * returns the main domain of the account.
     *
	 * @return string|null the account main domain.
     * @throws PanelException
	 */
	public function getMainDomain():? string;

	/**
     * returns the password of the account.
     *
	 * @return string|null the account password.
     * @throws PanelException
	 */
	public function getPassword():? string;

	/**
     * returns the ip address of the account.
     *
	 * @return string|null the account ip address.
     * @throws PanelException
	 */
	public function getIPAddress():? string;

	/**
     * returns the package of the account.
     *
	 * @return string|null the account package.
     * @throws PanelException
	 */
	public function getPackage():? string;

	/**
     * returns the owner of the account.
     *
	 * @return string|null the account owner.
     * @throws PanelException
	 */
	public function getOwner():? string;

	/**
     * returns the custom data of the account (optional, can returns an empty string).
     * it includes any information that the panel needs for the account.
     * its an internal data of the panel, it can receives whatever the panel needs,
     * the data will be backed up and restored as is.
     *
	 * @return string the account custom data.
     * @throws PanelException
	 */
	public function getCustomData(): string;

	/**
     * returns the email address of the account.
     *
	 * @return string|null the account email address.
     * @throws PanelException
	 */
	public function getEmailAddress():? string;

	/**
     * returns true if the account is suspended and false otherwise.
     *
	 * @return bool is the account suspended or not.
     * @throws PanelException
	 */
	public function getSuspended(): bool;

	/**
     * removes any temporary configuration files that might have been created
     * in an earlier stage by the 'getPath' function (optional).
     *
     * @return void
	 * @throws PanelException
	 */
	public function remove();
}