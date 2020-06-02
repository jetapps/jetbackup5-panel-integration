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
use JetBackup\Core\Panel\Integration\Quota;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface Account {

	/**
     * returns the username of the account.
     *
	 * @return string the account username.
     * @throws PanelException
	 */
	public function getUsername(): string;

	/**
     * returns the main domain of the account.
     *
	 * @return string|null the account main domain.
     * @throws PanelException
	 */
	public function getMainDomain():? string;

	/**
     * returns the home directory of the account.
     *
	 * @return string the account home dir.
     * @throws PanelException
	 */
	public function getHomeDir(): string;

	/**
     * returns the creation time of the account.
     *
	 * @return int Unix timestamp of the creation time.
     * @throws PanelException
	 */
	public function getCreated(): int;

	/**
     * returns an array of all the directories to exclude from the user home directory.
     * everything that is not a part of the user directory like mail folder etc.
     *
	 * @return array array of directories to exclude from the user home directory.
     * @throws PanelException
	 */
	public function getHomeDirExcludeList(): array;

	/**
     * returns true if the account is a reseller and false otherwise.
     *
	 * @return bool is the account a reseller or not.
     * @throws PanelException
	 */
	public function isReseller(): bool;

	/**
     * returns true if the account is suspended and false otherwise.
	 *
	 * @return bool is the account suspended or not.
     * @throws PanelException
	 */
	public function isSuspended(): bool;

	/**
     * returns the needed configurations for the account creation.
     *
	 * @return Config|null holds all the needed configurations for the account creation.
     * @throws PanelException
	 */
	public function getPanelConfig():? Config;

	/**
     * returns the owner of the account.
     *
	 * @return string|null the account owner.
     * @throws PanelException
	 */
	public function getOwner():? string;

	/**
     * returns the package of the account.
     *
	 * @return string|null the account's package.
     * @throws PanelException
	 */
	public function getPackage():? string;

	/**
     * returns the ip address of the account.
     *
	 * @return string|null the account ip address.
     * @throws PanelException
	 */
	public function getIPAddress():? string;

	/**
     * returns the main email address of the account.
     *
	 * @return string|null the account main email address.
	 * @throws PanelException
	 */
	public function getMainEmailAddress():? string;

	/**
     * returns an array of the account email accounts.
     * if $email parameter is specified the function returns an array that contains only the specified
     * email account information (if the email account exists),
     * otherwise, it returns an array of all the account email accounts information.
     *
     * @param string $email the desired email account.
     *
	 * @return EmailAccount[] an array of EmailAccount - holds all the needed information about the email account.
	 * @throws PanelException
	 */
	public function getEmailAccounts($email=null): array;

	/**
     * adds a new email account for the account.
     *
	 * @param EmailAccount $account the email account to add.
	 *
	 * @return EmailAccount|null the new added email account.
	 * @throws PanelException
	 */
	public function addEmailAccount(EmailAccount $account):? EmailAccount;

	/**
     * returns an array of the account domains.
     * if $domain parameter is specified the function returns an array that contains only the specified
     * domain information (if the domain exists),
     * otherwise, it returns an array of all the account domains information.
     *
	 * @param string $domain the desired domain.
	 *
	 * @return Domain[]|null an array of Domain - holds all the information about the account domains.
	 * @throws PanelException
	 */
	public function getDomains($domain=null):? array;

	/**
     * adds a new domain for the account.
     *
	 * @param Domain $domain the domain to add.
	 *
	 * @return Domain|null the new added domain.
	 * @throws PanelException
	 */
	public function addDomain(Domain $domain):? Domain;

	/**
     * returns an array of the account databases.
     * if $database parameter is specified the function returns an array that contains only the specified
     * database information (if the database exists),
     * otherwise, it returns an array of all the account databases information.
     *
	 * @param int $db_engine the database engine (mysql/mongodb/postgresql).
     * @uses Database::ENGINE_MYSQL mysql database engine.
     * @uses Database::ENGINE_MONGODB mogodb database engine.
     * @uses Database::ENGINE_POSTGRESQL postgresql database engine.
     * @param string $database the desired database name.
     *
	 * @return Database[] array of Database - holds all the information about the database.
	 * @throws PanelException
	 */
	public function getDatabases($db_engine, $database=null): array;

	/**
     * adds a new database for the account.
     *
	 * @param Database $database the database to add.
	 *
	 * @return Database|null the new added database.
	 * @throws PanelException
	 */
	public function addDatabase(Database $database):? Database;

	/**
     * returns an array of the account database users.
     * if $database_user parameter is specified the function returns an array that contains
     * only the specified database user information (if the database user exists),
     * otherwise, it returns an array of all the account database users information.
     *
	 * @param int $db_engine the database engine (mysql/mongodb/postgresql).
     * @uses Database::ENGINE_MYSQL mysql database engine.
     * @uses Database::ENGINE_MONGODB mogodb database engine.
     * @uses Database::ENGINE_POSTGRESQL postgresql database engine.
     * @param string $database_user the desired database user.
     *
	 * @return DatabaseUser[] array of DatabaseUser - holds all the information about the database user.
	 * @throws PanelException
	 */
	public function getDatabaseUsers($db_engine, $database_user=null): array;

	/**
     * adds a new database user for the account.
     *
	 * @param DatabaseUser $user the database user to add.
	 *
	 * @return DatabaseUser|null the new added database user.
	 * @throws PanelException
	 */
	public function addDatabaseUser(DatabaseUser $user):? DatabaseUser;

	/**
     * returns an array of the account certificates.
     * if $domain parameter is specified the function returns an array that contains only the specified
     * domain's certificate information (if the domain exists),
     * otherwise, it returns an array of all the account certificates information.
     *
     * @param string $domain the domain that its certificate is needed.
     *
	 * @return Certificate[] array of Certificate - holds all the information about the certificate.
	 * @throws PanelException
	 */
	public function getSSLCerts($domain=null): array;

	/**
     * adds a new certificate for the account.
     *
	 * @param Certificate $certificate the certificate to add.
	 *
	 * @return Certificate|null the new added certificate.
	 * @throws PanelException
	 */
	public function addSSLCert(Certificate $certificate):? Certificate;

	/**
     * returns the path to the account cron job file.
     *
	 * @return string|null the path to the account cron job file.
	 * @throws PanelException
	 */
	public function getCronJob():? string;

	/**
     * returns an array of the account ftp accounts.
     * if $account parameter is specified the function returns an array that contains only the specified
     * ftp account information (if the ftp account exists),
     * otherwise, it returns an array of all the account ftp accounts information.
     *
     * @param string $account the desired ftp account.
     *
	 * @return FTPAccount[] holds all the information about the ftp account.
	 * @throws PanelException
	 */
	public function getFTPAccounts($account=null): array;

	/**
     * adds a new ftp account for the account.
     *
	 * @param FTPAccount $account the ftp account to add.
	 *
	 * @return FTPAccount|null the new added ftp account.
	 * @throws PanelException
	 */
	public function addFTPAccount(FTPAccount $account):? FTPAccount;

	/**
     * returns true if the account is root and false otherwise.
     *
	 * @return bool is the account root or not.
     * @throws PanelException
	 */
	public function isRoot(): bool;

	/**
     * returns the custom data of the account (optional, can returns an empty string).
     * it includes any information that the panel needs for the account.
     * its an internal data of the panel, it can receives whatever the panel needs,
     * the data will be backed up and restored as is.
     *
	 * @return string the custom data of the account.
     * @throws PanelException
	 */
	public function getCustomData(): string;

	/**
     * returns the account quota information.
     *
	 * @return Quota the account quota information.
     * @throws PanelException
	 */
	public function getQuota(): Quota;

	/**
     * removes the account.
     *
     * @return void
	 * @throws PanelException
	 */
	public function remove();
}