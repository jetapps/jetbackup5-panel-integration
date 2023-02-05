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

interface Package {

	const UNLIMITED = -1;

	/**
	 * provide the package name
	 * 
	 * @return string
	 */
	public function getName(): string;

	/**
	 * provide the package quota in bytes or unlimited (see @uses for unlimited) 
	 * 
	 * @return int
	 * 
	 * @uses Package::UNLIMITED for unlimited quota
	 */
	public function getQuota(): int;

	/**
	 * provide the package bandwidth in bytes or unlimited (see @uses for unlimited)
	 *
	 * @return int
	 * 
	 * @uses Package::UNLIMITED for unlimited bandwidth
	 */
	public function getBandwidth(): int;

	/**
	 * provide the package maximum inode usage (see @uses for unlimited)
	 * 
	 * @return int
	 * 
	 * @uses Package::UNLIMITED for unlimited inodes
	 */
	public function getMaxInodes(): int;

	/**
	 * provide the package maximum FTP accounts (see @uses for unlimited)
	 *
	 * @return int
	 *
	 * @uses Package::UNLIMITED for unlimited FTP accounts
	 */
	public function getMaxFTPAccounts(): int;

	/**
	 * provide the package maximum Email accounts (see @uses for unlimited)
	 *
	 * @return int
	 *
	 * @uses Package::UNLIMITED for unlimited email accounts
	 */
	public function getMaxEmailAccounts(): int;

	/**
	 * provide the package maximum Email forwarders (see @uses for unlimited)
	 *
	 * @return int
	 *
	 * @uses Package::UNLIMITED for unlimited email forwarders
	 */
	public function getMaxEmailForwarders(): int;

	/**
	 * provide the package maximum Databases (see @uses for unlimited)
	 *
	 * @return int
	 *
	 * @uses Package::UNLIMITED for unlimited databases
	 */
	public function getMaxDatabases(): int;

	/**
	 * provide the package maximum Sub-Domains (see @uses for unlimited)
	 *
	 * @return int
	 *
	 * @uses Package::UNLIMITED for unlimited sub-domains
	 */
	public function getMaxSubDomains(): int;

	/**
	 * provide the package maximum Domain aliases (pointers) (see @uses for unlimited)
	 *
	 * @return int
	 *
	 * @uses Package::UNLIMITED for unlimited domain aliases
	 */
	public function getMaxAliasDomains(): int;

	/**
	 * provide the package maximum Additional domains  (see @uses for unlimited)
	 *
	 * @return int
	 *
	 * @uses Package::UNLIMITED for unlimited additional domains
	 */
	public function getMaxAddonDomains(): int;

	/**
	 * provide the package maximum Mailing lists (see @uses for unlimited)
	 *
	 * @return int
	 *
	 * @uses Package::UNLIMITED for unlimited mailing lists
	 */
	public function getMaxMailingLists(): int;

	/**
	 * provide the package maximum Auto responders (see @uses for unlimited)
	 *
	 * @return int
	 *
	 * @uses Package::UNLIMITED for unlimited auto responders
	 */
	public function getMaxAutoresponders(): int;

	/**
	 * returns true if the package has CGI access and false otherwise.
	 * 
	 * @return bool
	 */
	public function getCGIAccess(): bool;

	/**
	 * returns true if the package has shell access and false otherwise.
	 * 
	 * @return bool
	 */
	public function getShellAccess(): bool;

	/**
	 * provides the custom data of the ftp account (optional, can return an empty string).
	 * it includes any information that the panel needs for the ftp account.
	 * it's an internal data of the panel, it can receive whatever the panel needs,
	 * the data will be backed up and restored as is.
	 *
	 * @return string the custom data of the ftp account.
	 */
	public function getCustomData(): string;

	/**
	 * returns true if the package is custom package and false otherwise (whatever this package exists on the server or not).
	 * 
	 * @return bool
	 */
	public function isCustom(): bool;

}