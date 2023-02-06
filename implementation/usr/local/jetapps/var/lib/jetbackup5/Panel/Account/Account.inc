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

use JetBackup\Core\Exception\PanelException;
use JetBackup\Core\Panel\Integration\Account\Package;
use JetBackup\Core\Panel\Integration\Quota;
use JetBackup\Core\Restore\RestoreAccount\PostRestoreData;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class Account implements \JetBackup\Core\Panel\Integration\Account\Account {

	/**
	 * provides the username of the account.
	 *
	 * @return string the account username.
	 */
	public function getUsername(): string { return 'acct1'; }

	/**
	 * provide informative name for the account (this field is optional and can return empty string)
	 * 
	 * @return string the account nickname
	 */
	public function getNickname(): string { return 'acct1 nickname'; }

	/**
	 * provides the main domain of the account.
	 *
	 * @return string|null the account main domain.
	 */
	public function getMainDomain():? string { return 'acct1.com'; }

	/**
	 * provides the home directory of the account.
	 *
	 * @return string the account home dir.
	 */
	public function getHomeDir(): string { return '/home/acct1'; }

	/**
	 * provide the account homedir folder owner
	 * 
	 * @return string the account homedir folder owner
	 */
	public function getHomeDirOwner(): string { return 'acct1'; }

	/**
	 * provide the account homedir folder group
	 * 
	 * @return string the account homedir folder group
	 */
	public function getHomeDirGroup(): string { return 'nobody'; }

	/**
	 * provide the homedir folder permissions (e.g. 0751)
	 * 
	 * @return int the homedir folder permissions
	 */
	public function getHomeDirPermissions(): int { return 0751; }

	/**
	 * provides the creation time of the account.
	 *
	 * @return int Unix timestamp of the creation time.
	 */
	public function getCreated(): int { return 1672524000; }

	/**
	 * provides unique id for the account
	 *
	 * @return string 
	 */
	public function getUniqueId(): string { return hash('xxh3', 'acct1|1672524000'); }

	/**
	 * provides an array of directories to exclude from the user home directory (in rsync format).
	 * everything that the panel stores in the user home directory and is not a part of
	 * the user home directory, for example mail folder.
	 * e.g. `["/imap/***","/.cagefs/***"]`
	 *
	 * @return array array of directories to exclude from the user home directory.
	 */
	public function getHomeDirExcludeList(): array { return ['/mail/***','/.cl.selector/***','/etc/*/passwd']; }

	/**
	 * returns true if the account is a reseller and false otherwise.
	 *
	 * @return bool is the account a reseller or not.
	 */
	public function isReseller(): bool { return false; }

	/**
	 * returns true if the account is suspended and false otherwise.
	 *
	 * @return bool is the account suspended or not.
	 */
	public function isSuspended(): bool { return false; }

	/**
	 * provides the needed configurations for the account creation.
	 *
	 * @return Config|null holds all the needed configurations for the account creation.
	 */
	public function getPanelConfig():? \JetBackup\Core\Panel\Integration\Account\Config { return new Config(); }

	/**
	 * provides the owner of the account.
	 *
	 * @return string|null the account owner.
	 */
	public function getOwner():? string { return 'root'; }

	/**
	 * provides the package of the account.
	 *
	 * @return Package the account's package.
	 */
	public function getPackage(): Package {
		return new class implements Package {
			public function getName(): string { return 'mypackage'; }
			public function getQuota(): int { return self::UNLIMITED; }
			public function getBandwidth(): int { return self::UNLIMITED; }
			public function getMaxInodes(): int { return self::UNLIMITED; }
			public function getMaxFTPAccounts(): int { return self::UNLIMITED; }
			public function getMaxEmailAccounts(): int { return self::UNLIMITED; }
			public function getMaxEmailForwarders(): int { return self::UNLIMITED; }
			public function getMaxDatabases(): int { return self::UNLIMITED; }
			public function getMaxSubDomains(): int { return self::UNLIMITED; }
			public function getMaxAliasDomains(): int { return self::UNLIMITED; }
			public function getMaxAddonDomains(): int { return self::UNLIMITED; }
			public function getMaxMailingLists(): int { return self::UNLIMITED; }
			public function getMaxAutoresponders(): int { return self::UNLIMITED; }
			public function getCGIAccess(): bool { return true; }
			public function getShellAccess(): bool { return true; }
			public function getCustomData(): string { return ''; }
			public function isCustom(): bool { return false; }
		};
	}

	/**
	 * provides the packages list of the account (reseller).
	 *
	 * @return AccountPackage[] the account's packages list.
	 */
	public function getPackages(): array {
		$packages = [];

		$package = new AccountPackage();
		$package->setName('mypackage');
		$package->setType(AccountPackage::TYPE_USER);

		$packages[] = $package;
		
		return $packages;
	}

	/**
	 * provides the ip address of the account.
	 *
	 * @return string|null the account ip address.
	 */
	public function getIPAddress():? string { return '1.2.3.4'; }

	/**
	 * provides the main email address of the account.
	 *
	 * @return string|null the account main email address.
	 */
	public function getMainEmailAddress():? string { return 'acct1@acct1.com'; }

	/**
	 * provides an array of the account's email accounts.
	 * if $email parameter is specified the function returns an array that contains only the specified
	 * email account information (if the email account exists),
	 * otherwise, it returns an array of all the account email accounts information.
	 *
	 * @param string $email the desired email account.
	 *
	 * @return EmailAccount[] an array of EmailAccount - holds all the needed information about the email account.
	 */
	public function getEmailAccounts($email=null): array { return [new EmailAccount()]; }

	/**
	 * adds a new email account for the account.
	 *
	 * @param EmailAccount $account the email account to add.
	 *
	 * @return EmailAccount|null the new added email account.
	 * @throws PanelException throws if there is an issue with adding the new email account for the account.
	 */
	public function addEmailAccount(\JetBackup\Core\Panel\Integration\Account\EmailAccount $account):? \JetBackup\Core\Panel\Integration\Account\EmailAccount { return new EmailAccount(); }

	/**
	 * provides an array of the account domains.
	 * if $domain parameter is specified the function provides an array that contains only the specified
	 * domain information (if the domain exists),
	 * otherwise, it provides an array of all the account domains information.
	 *
	 * @param string $domain the desired domain.
	 *
	 * @return Domain[] an array of Domain - holds all the information about the account domains.
	 */
	public function getDomains($domain=null): array { return [new Domain()]; }

	/**
	 * adds a new domain for the account.
	 *
	 * @param Domain $domain the domain to add.
	 *
	 * @return Domain|null the new added domain.
	 * @throws PanelException throws if there is an issue with adding the new domain for the account.
	 */
	public function addDomain(\JetBackup\Core\Panel\Integration\Account\Domain $domain):? \JetBackup\Core\Panel\Integration\Account\Domain { return new Domain(); }

	/**
	 * provides an array of the account databases.
	 * if $database parameter is specified the function provides an array that contains only the specified
	 * database information (if the database exists),
	 * otherwise, it provides an array of all the account databases information.
	 *
	 * @param int $db_engine the database engine (see @uses for available engine types).
	 * @uses \JetBackup\Core\Panel\Integration\Account\Database::ENGINE_MYSQL mysql database engine.
	 * @uses \JetBackup\Core\Panel\Integration\Account\Database::ENGINE_MONGODB mogodb database engine.
	 * @uses \JetBackup\Core\Panel\Integration\Account\Database::ENGINE_POSTGRESQL postgresql database engine.
	 * @param string $database the desired database name.
	 *
	 * @return Database[] array of Database - holds all the information about the database.
	 */
	public function getDatabases($db_engine, $database=null): array { return [new Database()]; }

	/**
	 * adds a new database for the account.
	 *
	 * @param Database $database the database to add.
	 *
	 * @return Database|null the new added database.
	 * @throws PanelException throws if there is an issue with adding the new database for the account.
	 */
	public function addDatabase(\JetBackup\Core\Panel\Integration\Account\Database $database):? \JetBackup\Core\Panel\Integration\Account\Database { return new Database(); }

	/**
	 * provides an array of the account database users.
	 * if $database_user parameter is specified the function provides an array that contains
	 * only the specified database user information (if the database user exists),
	 * otherwise, it provides an array of all the account database users information.
	 *
	 * @param int $db_engine the database engine (see @uses for available engine types).
	 * @uses \JetBackup\Core\Panel\Integration\Account\Database::ENGINE_MYSQL mysql database engine.
	 * @uses \JetBackup\Core\Panel\Integration\Account\Database::ENGINE_MONGODB mogodb database engine.
	 * @uses \JetBackup\Core\Panel\Integration\Account\Database::ENGINE_POSTGRESQL postgresql database engine.
	 * @param string $database_user the desired database user.
	 *
	 * @return DatabaseUser[] array of DatabaseUser - holds all the information about the database user.
	 */
	public function getDatabaseUsers($db_engine, $database_user=null): array { return [new DatabaseUser()]; }

	/**
	 * adds a new database user for the account.
	 *
	 * @param DatabaseUser $user the database user to add.
	 *
	 * @return DatabaseUser|null the new added database user.
	 * @throws PanelException throws if there is an issue with adding the new database user for the account.
	 */
	public function addDatabaseUser(\JetBackup\Core\Panel\Integration\Account\DatabaseUser $user):? \JetBackup\Core\Panel\Integration\Account\DatabaseUser { return new DatabaseUser(); }

	/**
	 * provides an array of the account certificates.
	 * if $domain parameter is specified the function provides an array that contains only the specified
	 * domain's certificate information (if the domain exists),
	 * otherwise, it provides an array of all the account certificates information.
	 *
	 * @param string $domain the domain that its certificate is needed.
	 *
	 * @return Certificate[] array of Certificate - holds all the information about the certificate.
	 */
	public function getSSLCerts($domain=null): array { return [new Certificate()]; }

	/**
	 * adds a new certificate for the account.
	 *
	 * @param Certificate $certificate the certificate to add.
	 *
	 * @return Certificate|null the new added certificate.
	 * @throws PanelException throws if there is an issue with adding the new certificate for the account.
	 */
	public function addSSLCert(\JetBackup\Core\Panel\Integration\Account\Certificate $certificate):? \JetBackup\Core\Panel\Integration\Account\Certificate { return new Certificate(); }

	/**
	 * provides the path to the account cron job file.
	 *
	 * @return string|null the path to the account cron job file.
	 */
	public function getCronJob():? string { return '/var/spool/cron/acct1'; }

	/**
	 * replaces the cron job file of the account.
	 * the function receives the path to the account cron job file
	 * and apply the cron jobs to the panel account.
	 *
	 * @param string $cronjob the path to the account cron job file.
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with replacing the cron job file for the account.
	 */
	public function setCronJob($cronjob) {}

	/**
	 * provides an array of the account ftp accounts.
	 * if $account parameter is specified the function provides an array that contains only the specified
	 * ftp account information (if the ftp account exists),
	 * otherwise, it provides an array of all the account ftp accounts information.
	 *
	 * @param string $account the desired ftp account.
	 *
	 * @return FTPAccount[] holds all the information about the ftp account.
	 */
	public function getFTPAccounts($account=null): array { return [new FTPAccount()]; }

	/**
	 * adds a new ftp account for the account.
	 *
	 * @param FTPAccount $account the ftp account to add.
	 *
	 * @return FTPAccount|null the new added ftp account.
	 * @throws PanelException throws if there is an issue with adding the new ftp account for the account.
	 */
	public function addFTPAccount(\JetBackup\Core\Panel\Integration\Account\FTPAccount $account):? \JetBackup\Core\Panel\Integration\Account\FTPAccount { return new FTPAccount(); }

	/**
	 * returns true if the account is root and false otherwise.
	 *
	 * @return bool is the account root or not.
	 */
	public function isRoot(): bool { return false; }

	/**
	 * returns true if the account is login only and false otherwise.
	 *
	 * @return bool is the account login only or not.
	 */
	public function isLoginOnly(): bool { return false; }

	/**
	 * provides the custom data of the account (optional, can return an empty string).
	 * it includes any information that the panel needs for the account.
	 * it's an internal data of the panel, it can receive whatever the panel needs,
	 * the data will be backed up and restored as is.
	 *
	 * @return string the custom data of the account.
	 */
	public function getCustomData(): string { return ''; }

	/**
	 * provides the account quota information.
	 *
	 * @return Quota the account quota information.
	 */
	public function getQuota(): Quota {
		return new class implements Quota {
			public function getDiskUsage(): int { return self::UNLIMITED; }
			public function getDiskFree(): int { return self::UNLIMITED; }
			public function getDiskTotal(): int { return self::UNLIMITED; }
			public function getInodeUsage(): int { return self::UNLIMITED; }
		};
	}

	/**
	 * removes the account.
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with removing the account.
	 */
	public function remove() {}

	/**
	 * preformed before each restore
	 * 
	 * @throws PanelException throws if there is an issue with the post restore script.
	 */
	public function preRestore() {}

	/**
	 * preformed after each restore
	 * 
	 * @param PostRestoreData $data
	 * @throws PanelException throws if there is an issue with the post restore script.
	 */
	public function postRestore(PostRestoreData $data) {}
}