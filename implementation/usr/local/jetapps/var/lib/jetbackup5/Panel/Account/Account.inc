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
use JetBackup\Core\Panel\Integration\Account\IPAddress;
use JetBackup\Core\Panel\Integration\Account\Package;
use JetBackup\Core\Panel\Integration\Quota;
use JetBackup\Core\Restore\RestoreAccount\PostRestoreData;
use JetBackup\Core\Panel\Integration\Account\Account as iAccount;
use JetBackup\Core\Panel\Integration\Account\Config as iConfig;
use JetBackup\Core\Panel\Integration\Account\EmailAccount as iEmailAccount;
use JetBackup\Core\Panel\Integration\Account\Domain as iDomain;
use JetBackup\Core\Panel\Integration\Account\Database as iDatabase;
use JetBackup\Core\Panel\Integration\Account\DatabaseUser as iDatabaseUser;
use JetBackup\Core\Panel\Integration\Account\Certificate as iCertificate;
use JetBackup\Core\Panel\Integration\Account\FTPAccount as iFTPAccount;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class Account implements iAccount {

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
	 * @return string the account main domain.
	 */
	public function getMainDomain(): string { return 'acct1.com'; }

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
	public function getPanelConfig():iConfig|null { return new Config(); }

	/**
	 * provides the owner of the account.
	 *
	 * @return string the account owner.
	 */
	public function getOwner():string { return 'root'; }

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
	 * provides the main email address of the account.
	 *
	 * @return string the account main email address.
	 */
	public function getMainEmailAddress():string { return 'acct1@acct1.com'; }

	/**
	 * provides an array of the account's email accounts.
	 * if $email parameter is specified the function returns an array that contains only the specified
	 * email account information (if the email account exists),
	 * otherwise, it returns an array of all the account email accounts information.
	 *
	 * @param string|null $email the desired email account.
	 *
	 * @return iEmailAccount[] an array of EmailAccount - holds all the needed information about the email account.
	 */
	public function getEmailAccounts(string|null $email=null): array { return [new EmailAccount()]; }

	/**
	 * adds a new email account for the account.
	 *
	 * @param iEmailAccount $account the email account to add.
	 *
	 * @return iEmailAccount|null the new added email account.
	 * @throws PanelException throws if there is an issue with adding the new email account for the account.
	 */
	public function addEmailAccount(iEmailAccount $account):iEmailAccount|null { return new EmailAccount(); }

	/**
	 * provides an array of the account domains.
	 * if $domain parameter is specified the function provides an array that contains only the specified
	 * domain information (if the domain exists),
	 * otherwise, it provides an array of all the account domains information.
	 *
	 * @param string|null $domain the desired domain.
	 *
	 * @return Domain[] an array of Domain - holds all the information about the account domains.
	 */
	public function getDomains(string|null $domain=null): array { return [new Domain()]; }

	/**
	 * adds a new domain for the account.
	 *
	 * @param iDomain $domain the domain to add.
	 *
	 * @return iDomain|null the new added domain.
	 * @throws PanelException throws if there is an issue with adding the new domain for the account.
	 */
	public function addDomain(iDomain $domain):iDomain|null { return new Domain(); }

	/**
	 * provides an array of the account databases.
	 * if $database parameter is specified the function provides an array that contains only the specified
	 * database information (if the database exists),
	 * otherwise, it provides an array of all the account databases information.
	 *
	 * @param int $db_engine the database engine (see @uses for available engine types).
	 * @uses iDatabase::ENGINE_MYSQL mysql database engine.
	 * @uses iDatabase::ENGINE_MONGODB mogodb database engine.
	 * @uses iDatabase::ENGINE_POSTGRESQL postgresql database engine.
	 * @param string|null $database the desired database name.
	 *
	 * @return Database[] array of Database - holds all the information about the database.
	 */
	public function getDatabases(int $db_engine, $database=null): array { return [new Database()]; }

	/**
	 * adds a new database for the account.
	 *
	 * @param iDatabase $database the database to add.
	 *
	 * @return iDatabase|null the new added database.
	 * @throws PanelException throws if there is an issue with adding the new database for the account.
	 */
	public function addDatabase(iDatabase $database):iDatabase|null { return new Database(); }

	/**
	 * provides an array of the account database users.
	 * if $database_user parameter is specified the function provides an array that contains
	 * only the specified database user information (if the database user exists),
	 * otherwise, it provides an array of all the account database users information.
	 *
	 * @param int $db_engine the database engine (see @uses for available engine types).
	 * @uses iDatabase::ENGINE_MYSQL mysql database engine.
	 * @uses iDatabase::ENGINE_MONGODB mogodb database engine.
	 * @uses iDatabase::ENGINE_POSTGRESQL postgresql database engine.
	 * @param string|null $database_user the desired database user.
	 *
	 * @return DatabaseUser[] array of DatabaseUser - holds all the information about the database user.
	 */
	public function getDatabaseUsers(int $db_engine, string|null $database_user=null): array { return [new DatabaseUser()]; }

	/**
	 * adds a new database user for the account.
	 *
	 * @param iDatabaseUser $user the database user to add.
	 *
	 * @return iDatabaseUser|null the new added database user.
	 * @throws PanelException throws if there is an issue with adding the new database user for the account.
	 */
	public function addDatabaseUser(iDatabaseUser $user):iDatabaseUser|null { return new DatabaseUser(); }

	/**
	 * provides an array of the account certificates.
	 * if $domain parameter is specified the function provides an array that contains only the specified
	 * domain's certificate information (if the domain exists),
	 * otherwise, it provides an array of all the account certificates information.
	 *
	 * @param string|null $domain the domain that its certificate is needed.
	 *
	 * @return Certificate[] array of Certificate - holds all the information about the certificate.
	 */
	public function getSSLCerts(string|null $domain=null): array { return [new Certificate()]; }

	/**
	 * adds a new certificate for the account.
	 *
	 * @param iCertificate $certificate the certificate to add.
	 *
	 * @return iCertificate|null the new added certificate.
	 * @throws PanelException throws if there is an issue with adding the new certificate for the account.
	 */
	public function addSSLCert(iCertificate $certificate):iCertificate|null { return new Certificate(); }

	/**
	 * provides the path to the account cron job file.
	 *
	 * @return string|null the path to the account cron job file.
	 */
	public function getCronJob():string|null { return '/var/spool/cron/acct1'; }

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
	public function setCronJob(string $cronjob):void {}

	/**
	 * provides an array of the account ftp accounts.
	 * if $account parameter is specified the function provides an array that contains only the specified
	 * ftp account information (if the ftp account exists),
	 * otherwise, it provides an array of all the account ftp accounts information.
	 *
	 * @param string|null $account the desired ftp account.
	 *
	 * @return FTPAccount[] holds all the information about the ftp account.
	 */
	public function getFTPAccounts(string|null $account=null): array { return [new FTPAccount()]; }

	/**
	 * adds a new ftp account for the account.
	 *
	 * @param iFTPAccount $account the ftp account to add.
	 *
	 * @return iFTPAccount|null the new added ftp account.
	 * @throws PanelException throws if there is an issue with adding the new ftp account for the account.
	 */
	public function addFTPAccount(iFTPAccount $account):iFTPAccount|null { return new FTPAccount(); }

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
	public function remove():void {}

	/**
	 * preformed before each restore
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with the post restore script.
	 */
	public function preRestore():void {}

	/**
	 * preformed after each restore
	 * 
	 * @param PostRestoreData $data
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with the post restore script.
	 */
	public function postRestore(PostRestoreData $data):void {}

	/**
	 * return the account IP addresses
	 * 
	 * @return IPAddress[]
	 */
	public function getIPAddresses(): array { 
		return [new class implements IPAddress {
			public function getIP(): string { return '8.8.8.8'; }
			public function isMain(): bool { return true; }
			public function getType(): int { return self::TYPE_IPV4; }
		}]; 
	}

	/**
	 * returns true if the account is virtual account (not a linux user) and false otherwise.
	 * 
	 * @return bool
	 */
	public function isVirtual(): bool { return false; }
}