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
	 * provides the panel id.
	 * the panel id is the same panel id as in \JetBackup\Core\Panel\Integration\PanelInfo::getId().
	 *
	 * @return string represents the panel.
	 */
	public function getPanel(): string;

	/**
	 * provides the path for the config files.
	 * the path to the config files, that contains all the information about the
	 * user that the panel needs in order to create the account in the case of account restoration.
	 *
	 * @return string|null the path for the config files.
	 * @throws PanelException throws if there is an issue with getting the path.
	 */
	public function getPath():? string;

	/**
	 * provides the main domain of the account.
	 *
	 * @return string|null the account main domain.
	 */
	public function getMainDomain():? string;

	/**
	 * provides the password of the account.
	 *
	 * @return string|null the account password.
	 */
	public function getPassword():? string;

	/**
	 * provides the ip address of the account.
	 *
	 * @return string|null the account ip address.
	 */
	public function getIPAddress():? string;

	/**
	 * provides the package of the account.
	 *
	 * @return string|null the account package.
	 */
	public function getPackage():? string;

	/**
	 * provides the owner of the account.
	 *
	 * @return string|null the account owner.
	 */
	public function getOwner():? string;

	/**
	 * provides the custom data of the account (optional, can returns an empty string).
	 * it includes any information that the panel needs for the account.
	 * its an internal data of the panel, it can receives whatever the panel needs,
	 * the data will be backed up and restored as is.
	 *
	 * @return string the account custom data.
	 */
	public function getCustomData(): string;

	/**
	 * provides the email address of the account.
	 *
	 * @return string|null the account email address.
	 */
	public function getEmailAddress():? string;

	/**
	 * returns true if the account is suspended and false otherwise.
	 *
	 * @return bool is the account suspended or not.
	 */
	public function getSuspended(): bool;

	/**
	 * removes configuration files.
	 * removes any temporary configuration files that might have been created
	 * in an earlier stage by the 'getPath' function (optional).
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with removing the configuration files.
	 */
	public function remove();
}