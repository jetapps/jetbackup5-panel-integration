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

	private array $_data;

	public function __construct(array $data) {
		$this->_data = $data;
	}

	/**
	 * provides the username of the account.
	 *
	 * @return string the account username.
	 */
	public function getUsername(): string { return $this->_data['username']; }

	/**
	 * provide informative name for the account (this field is optional and can return empty string)
	 * 
	 * @return string the account nickname
	 */
	public function getNickname(): string { return $this->_data['nickname']; }

	/**
	 * provides the main domain of the account.
	 *
	 * @return string the account main domain.
	 */
	public function getMainDomain(): string { return $this->_data['domain']; }

	/**
	 * provides the home directory of the account.
	 *
	 * @return string the account home dir.
	 */
	public function getHomeDir(): string { return $this->_data['homedir']; }

	/**
	 * provide the account homedir folder owner
	 * 
	 * @return string the account homedir folder owner
	 */
	public function getHomeDirOwner(): string { return $this->_data['homedir_owner']; }

	/**
	 * provide the account homedir folder group
	 * 
	 * @return string the account homedir folder group
	 */
	public function getHomeDirGroup(): string { return $this->_data['homedir_group']; }

	/**
	 * provide the homedir folder permissions (e.g. 0751)
	 * 
	 * @return int the homedir folder permissions
	 */
	public function getHomeDirPermissions(): int { return $this->_data['homedir_perms']; }

	/**
	 * provides the creation time of the account.
	 *
	 * @return int Unix timestamp of the creation time.
	 */
	public function getCreated(): int { return $this->_data['creation_date']; }

	/**
	 * provides unique id for the account
	 *
	 * @return string 
	 */
	public function getUniqueId(): string { return hash('xxh3', $this->getUsername() . '|' . $this->getCreated()); }

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
	public function isReseller(): bool { return $this->_data['reseller']; }

	/**
	 * returns true if the account is suspended and false otherwise.
	 *
	 * @return bool is the account suspended or not.
	 */
	public function isSuspended(): bool { return $this->_data['suspended']; }

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
	public function getOwner():string { return $this->_data['owner']; }

	/**
	 * provides the package of the account.
	 *
	 * @return Package the account's package.
	 */
	public function getPackage(): Package {
		
		// TODO implement, load the account package
		
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
		
		// TODO implement, if the account is root or reseller fetch all available packages that is assignable to account under this account
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
	public function getMainEmailAddress():string { return $this->_data['email']; }

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
	public function getEmailAccounts(string|null $email=null): array {

		if($email) {
			// TODO implement, find the $email for that account
			// e.g. SELECT * FROM email_accounts WHERE account = '{$this->getUsername()}' AND name = '$email';
			$result = [
				'name'          => 'email@acct1.com',
				'path'          => '/path/to/mailbox',
				'quota'         => 1024, // quota in bytes
				'send_limit'    => 0,
				'password'      => '$6$Fg5PejVYNxGTafDO$5mKgXEIBpH6ZXT5mYO9boTCPif7jgpCuu.MbOVWzwnTUYJ/iZ5WVlKEDEBmtq0jatjFQWfD8oXruxXJEQPLOW.' // hashed password
			];
			//

			return [new EmailAccount($this, $result)];
		}

		// TODO implement, find all domains for that account
		// e.g. SELECT * FROM email_accounts WHERE account = '{$this->getUsername()}';
		$result = [
			[
				'name'          => 'email@acct1.com',
				'path'          => '/path/to/mailbox',
				'quota'         => 1024, // quota in bytes
				'send_limit'    => 0,
				'password'      => '$6$Fg5PejVYNxGTafDO$5mKgXEIBpH6ZXT5mYO9boTCPif7jgpCuu.MbOVWzwnTUYJ/iZ5WVlKEDEBmtq0jatjFQWfD8oXruxXJEQPLOW.' // hashed password
			],
			[
				'name'          => 'email2@acct1.com',
				'path'          => '/path/to/mailbox2',
				'quota'         => 1024, // quota in bytes
				'send_limit'    => 0,
				'password'      => '$6$Fg5PejVYNxGTafDO$5mKgXEIBpH6ZXT5mYO9boTCPif7jgpCuu.MbOVWzwnTUYJ/iZ5WVlKEDEBmtq0jatjFQWfD8oXruxXJEQPLOW.' // hashed password
			]
		];
		//

		$accounts = [];
		foreach($result as $data) $accounts[] = new EmailAccount($this, $data);
		return $accounts;
	}

	/**
	 * adds a new email account for the account.
	 *
	 * @param iEmailAccount $account the email account to add.
	 *
	 * @return iEmailAccount|null the new added email account.
	 * @throws PanelException throws if there is an issue with adding the new email account for the account.
	 */
	public function addEmailAccount(iEmailAccount $account):iEmailAccount|null {

		// TODO implement, Add/Modify this email account for that account into your panel
		
		// if domain exists in panel e.g.
		// UPDATE email_accounts
		// SET quota = '{$account->getQuota()}', ...
		// WHERE account = '{$this->getUsername()}'
		// AND name = '{$account->getName()}'

		// if domain doesn't exists in panel e.g.
		// INSERT INTO domains (`name`, `account`, `quota`, ...)
		// VALUES ('{$account->getName()}', '{$this->getUsername()}', '{$account->getQuota()}', ...)

		$accounts = $this->getEmailAccounts($account->getName());
		return $accounts[0] ?? null;
	}

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
	public function getDomains(string|null $domain=null): array { 
		
		if($domain) {
			// TODO implement, find the $domain for that account
			// e.g. SELECT * FROM domains WHERE account = '{$this->getUsername()}' AND name = '$domain';
			$result = [
				'name'          => 'acct1.com',
				'public_dir'    => 'public_html', // the public dir inside the account homedir
				'type'          => iDomain::TYPE_ADDON_DOMAIN,
				'ip'            => '1.2.3.4',
				'zone_file'     => '/var/named/acct1.com.db',
			];
			//

			return [new Domain($this, $result)];
		} 


		// TODO implement, find all domains for that account
		// e.g. SELECT * FROM domains WHERE account = '{$this->getUsername()};
		$result = [
			[
				'name'          => 'acct1.com',
				'public_dir'    => 'public_html', // the public dir inside the account homedir
				'type'          => iDomain::TYPE_MAIN_DOMAIN,
				'ip'            => '1.2.3.4',
				'zone_file'     => '/var/named/acct1.com.db',
			],
			[
				'name'          => 'acct2.com',
				'public_dir'    => 'domains/acct2.com', // the public dir inside the account homedir
				'type'          => iDomain::TYPE_ADDON_DOMAIN,
				'ip'            => '1.2.3.4',
				'zone_file'     => '/var/named/acct2.com.db',
			],
			[
				'name'          => 'sub.acct2.com',
				'public_dir'    => 'domains/sub.acct2.com', // the public dir inside the account homedir
				'type'          => iDomain::TYPE_SUBDOMAIN,
				'ip'            => '1.2.3.4',
				'zone_file'     => null,
			]
		];
		//

		$domains = [];
		foreach($result as $data) $domains[] = new Domain($this, $data);
		return $domains; 
	}

	/**
	 * adds a new domain for the account.
	 *
	 * @param iDomain $domain the domain to add.
	 *
	 * @return iDomain|null the new added domain.
	 * @throws PanelException throws if there is an issue with adding the new domain for the account.
	 */
	public function addDomain(iDomain $domain):iDomain|null {
		
		// TODO implement, Add/Modify this domain for that account into your panel

		// if domain exists in panel e.g.
		// UPDATE domains
		// SET public_dir = '{$domain->getPublicDir()}', ...
		// WHERE account = '{$this->getUsername()}'
		// AND name = '{$domain->getName()}'
		
		// if domain doesn't exists in panel e.g.
		// INSERT INTO domains (`name`, `account`, `public_dir`, ...)
		// VALUES ('{$domain->getName()}', '{$this->getUsername()}', '{$domain->getPublicDir()}', ...)

		$domains = $this->getDomains($domain->getName());
		return $domains[0] ?? null; 
	}

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
	public function getDatabases(int $db_engine, $database=null): array {

		switch($db_engine) {
			case iDatabase::ENGINE_MYSQL: $type = 'mysql'; break;
			case iDatabase::ENGINE_MONGODB: $type = 'mongodb'; break;
			case iDatabase::ENGINE_POSTGRESQL: $type = 'psql'; break;
		}
		
		if($database) {
			// TODO implement, find the $database of type $type for that account
			// e.g. SELECT * FROM databases WHERE account = '{$this->getUsername()}' AND name = '$database' AND type = '$type';
			$result = [
				'name'          => 'acct1_database1',
				'engine'        => iDatabase::ENGINE_MYSQL,
				'engine_name'   => iDatabase::ENGINE_NAME_MARIADB,
				'engine_version'=> '5.8',
			];
			//

			return [new Database($this, $result)];
		}


		// TODO implement, find all databases of type $type for that account
		// e.g. SELECT * FROM databases WHERE account = '{$this->getUsername()}' AND type = '$type';
		$result = [
			[
				'name'          => 'acct1_database1',
				'engine'        => iDatabase::ENGINE_MYSQL,
				'engine_name'   => iDatabase::ENGINE_NAME_MARIADB,
				'engine_version'=> '5.8',
			],
			[
				'name'          => 'acct1_database2',
				'engine'        => iDatabase::ENGINE_MYSQL,
				'engine_name'   => iDatabase::ENGINE_NAME_MYSQL,
				'engine_version'=> '5.8',
			],
			[
				'name'          => 'acct1_database3',
				'engine'        => iDatabase::ENGINE_MONGODB,
				'engine_name'   => iDatabase::ENGINE_NAME_MONGODB,
				'engine_version'=> '5.8',
			]
		];
		//

		$databases = [];
		foreach($result as $data) $databases[] = new Database($this, $data);
		return $databases;
	}

	/**
	 * adds a new database for the account.
	 *
	 * @param iDatabase $database the database to add.
	 *
	 * @return iDatabase|null the new added database.
	 * @throws PanelException throws if there is an issue with adding the new database for the account.
	 */
	public function addDatabase(iDatabase $database):iDatabase|null {

		// TODO implement, Add/Modify this database for that account into your panel
		
		// if database exists in panel e.g.
		// UPDATE databases
		// SET engine = '{$database->getEngine()}', ...
		// WHERE account = '{$this->getUsername()}'
		// AND name = '{$database->getName()}'

		// if database doesn't exists in panel e.g.
		// INSERT INTO databases (`name`, `account`, `engine`, ...)
		// VALUES ('{$database->getName()}', '{$this->getUsername()}', '{$database->getEngine()}', ...)

		$databases = $this->getDatabases($database->getEngine(), $database->getName());
		return $databases[0] ?? null;
	}

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
	public function getDatabaseUsers(int $db_engine, string|null $database_user=null): array {
		switch($db_engine) {
			case iDatabase::ENGINE_MYSQL: $type = 'mysql'; break;
			case iDatabase::ENGINE_MONGODB: $type = 'mongodb'; break;
			case iDatabase::ENGINE_POSTGRESQL: $type = 'psql'; break;
		}

		if($database_user) {
			// TODO implement, find the $database_user of type $type for that account
			// e.g. SELECT * FROM database_users WHERE account = '{$this->getUsername()}' AND name = '$database_user' AND type = '$type';

			$result = [
				'name'          => 'acct1_user1',
				'engine'        => iDatabase::ENGINE_MYSQL,
				'password'      => '$6$Fg5PejVYNxGTafDO$5mKgXEIBpH6ZXT5mYO9boTCPif7jgpCuu.MbOVWzwnTUYJ/iZ5WVlKEDEBmtq0jatjFQWfD8oXruxXJEQPLOW.',
				'privileges'    => [
					new DatabaseUserPrivileges([ 'database' => 'acct1_database1', 'grants' => ["INSERT","UPDATE","SELECT"] ]),
					new DatabaseUserPrivileges([ 'database' => 'acct1_database2', 'grants' => ["INSERT","UPDATE","DELETE"] ]),
				],
			];
			//

			return [new DatabaseUser($this, $result)];
		}


		// TODO implement, find all database users of type $type for that account
		// e.g. SELECT * FROM database_users WHERE account = '{$this->getUsername()}' AND type = '$type';
		$result = [
			[
				'name'          => 'acct1_user1',
				'engine'        => iDatabase::ENGINE_MYSQL,
				'password'      => '$6$Fg5PejVYNxGTafDO$5mKgXEIBpH6ZXT5mYO9boTCPif7jgpCuu.MbOVWzwnTUYJ/iZ5WVlKEDEBmtq0jatjFQWfD8oXruxXJEQPLOW.',
				'privileges'    => [
					new DatabaseUserPrivileges([ 'database' => 'acct1_database1', 'grants' => ["INSERT","UPDATE","SELECT"] ]),
					new DatabaseUserPrivileges([ 'database' => 'acct1_database2', 'grants' => ["INSERT","UPDATE","DELETE"] ]),
				],
			],
			[
				'name'          => 'acct1_user2',
				'engine'        => iDatabase::ENGINE_MONGODB,
				'password'      => '$6$Fg5PejVYNxGTafDO$5mKgXEIBpH6ZXT5mYO9boTCPif7jgpCuu.MbOVWzwnTUYJ/iZ5WVlKEDEBmtq0jatjFQWfD8oXruxXJEQPLOW.',
				'privileges'    => [],
			]
		];
		//

		$users = [];
		foreach($result as $data) $users[] = new DatabaseUser($this, $data);
		return $users;
	}

	/**
	 * adds a new database user for the account.
	 *
	 * @param iDatabaseUser $user the database user to add.
	 *
	 * @return iDatabaseUser|null the new added database user.
	 * @throws PanelException throws if there is an issue with adding the new database user for the account.
	 */
	public function addDatabaseUser(iDatabaseUser $user):iDatabaseUser|null {

		// TODO implement, Add/Modify this database user for that account into your panel

		// if database user exists in panel e.g.
		// UPDATE database_users
		// SET password = '{$user->getPassword()}', ...
		// WHERE account = '{$this->getUsername()}'
		// AND name = '{$user->getName()}'

		// if database user doesn't exists in panel e.g.
		// INSERT INTO database_users (`name`, `account`, `password`, ...)
		// VALUES ('{$user->getName()}', '{$this->getUsername()}', '{$user->getPassword()}', ...)

		$users = $this->getDatabaseUsers($user->getEngine(), $user->getName());
		return $users[0] ?? null;

	}

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
	public function getSSLCerts(string|null $domain=null): array {

		if($domain) {
			// TODO implement, find the SSL certificate for $domain for that account
			// e.g. SELECT * FROM certificates WHERE account = '{$this->getUsername()}' AND domain = '$domain';
			$result = [
				'domain'        => 'acct1.com',
				'private_key'   => '-----BEGIN PRIVATE KEY-----',
				'certificate'   => '-----BEGIN CERTIFICATE-----',
				'ca_bundle'     => '',
			];
			//

			return [new Certificate($this, $result)];
		}


		// TODO implement, find all SSL certificates for that account
		// e.g. SELECT * FROM certificates WHERE account = '{$this->getUsername()};
		$result = [
			[
				'domain'        => 'acct1.com',
				'private_key'   => '-----BEGIN PRIVATE KEY-----',
				'certificate'   => '-----BEGIN CERTIFICATE-----',
				'ca_bundle'     => '',
			],
			[
				'domain'        => 'acct2.com',
				'private_key'   => '-----BEGIN PRIVATE KEY-----',
				'certificate'   => '-----BEGIN CERTIFICATE-----',
				'ca_bundle'     => '',
			]
		];
		//

		$certs = [];
		foreach($result as $data) $certs[] = new Certificate($this, $data);
		return $certs;
	}

	/**
	 * adds a new certificate for the account.
	 *
	 * @param iCertificate $certificate the certificate to add.
	 *
	 * @return iCertificate|null the new added certificate.
	 * @throws PanelException throws if there is an issue with adding the new certificate for the account.
	 */
	public function addSSLCert(iCertificate $certificate):iCertificate|null {
		// TODO implement, Add/Modify this domain for that account into your panel
		
		// if domain exists in panel e.g.
		// UPDATE certificates
		// SET private_key = '{$certificate->getPrivateKey()}', ...
		// WHERE account = '{$this->getUsername()}'
		// AND domain = '{$certificate->getDomain()}'

		// if domain doesn't exists in panel e.g.
		// INSERT INTO domains (`domain`, `account`, `private_key`, ...)
		// VALUES ('{$certificate->getDomain()}', '{$this->getUsername()}', '{$certificate->getPrivateKey()}', ...)

		$certs = $this->getSSLCerts($certificate->getDomain());
		return $certs[0] ?? null;
	}

	/**
	 * provides the path to the account cron job file.
	 *
	 * @return string|null the path to the account cron job file.
	 */
	public function getCronJob():string|null { return '/var/spool/cron/' . $this->getUsername(); }

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
	public function setCronJob(string $cronjob):void {
		// TODO implement, copy $cronjob to the cron location
	}

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
	public function getFTPAccounts(string|null $account=null): array {
		if($account) {
			// TODO implement, find $account for that account
			// e.g. SELECT * FROM ftp_accounts WHERE account = '{$this->getUsername()}' AND name = '$account';
			$result = [
				'name'      => 'ftp@acct1.com',
				'password'  => '$6$Fg5PejVYNxGTafDO$5mKgXEIBpH6ZXT5mYO9boTCPif7jgpCuu.MbOVWzwnTUYJ/iZ5WVlKEDEBmtq0jatjFQWfD8oXruxXJEQPLOW.',
				'path'      => '/path/to/ftp/account',
			];
			//

			return [new FTPAccount($this, $result)];
		}


		// TODO implement, find all FTP accounts for that account
		// e.g. SELECT * FROM ftp_accounts WHERE account = '{$this->getUsername()};
		$result = [
			[
				'name'      => 'ftp@acct1.com',
				'password'  => '$6$Fg5PejVYNxGTafDO$5mKgXEIBpH6ZXT5mYO9boTCPif7jgpCuu.MbOVWzwnTUYJ/iZ5WVlKEDEBmtq0jatjFQWfD8oXruxXJEQPLOW.',
				'path'      => '/path/to/ftp/account',
			],
			[
				'name'      => 'ftp@acct2.com',
				'password'  => '$6$Fg5PejVYNxGTafDO$5mKgXEIBpH6ZXT5mYO9boTCPif7jgpCuu.MbOVWzwnTUYJ/iZ5WVlKEDEBmtq0jatjFQWfD8oXruxXJEQPLOW.',
				'path'      => '/path/to/ftp/account',
			]
		];
		//

		$accounts = [];
		foreach($result as $data) $accounts[] = new FTPAccount($this, $data);
		return $accounts;
	}

	/**
	 * adds a new ftp account for the account.
	 *
	 * @param iFTPAccount $account the ftp account to add.
	 *
	 * @return iFTPAccount|null the new added ftp account.
	 * @throws PanelException throws if there is an issue with adding the new ftp account for the account.
	 */
	public function addFTPAccount(iFTPAccount $account):iFTPAccount|null {
		// TODO implement, Add/Modify this FTP account for that account into your panel

		// if account exists in panel e.g.
		// UPDATE ftp_accounts
		// SET password = '{$account->getPassword()}', ...
		// WHERE account = '{$this->getUsername()}'
		// AND name = '{$account->getName()}'

		// if account doesn't exists in panel e.g.
		// INSERT INTO ftp_accounts (`name`, `account`, `password`, ...)
		// VALUES ('{$account->getName()}', '{$this->getUsername()}', '{$account->getPassword()}', ...)

		$accounts = $this->getFTPAccounts($account->getName());
		return $accounts[0] ?? null;
	}

	/**
	 * returns true if the account is root and false otherwise.
	 *
	 * @return bool is the account root or not.
	 */
	public function isRoot(): bool { return $this->_data['root']; }

	/**
	 * returns true if the account is login only and false otherwise.
	 *
	 * @return bool is the account login only or not.
	 */
	public function isLoginOnly(): bool { return $this->_data['login_only']; }

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
	public function remove():void {
		// TODO implement, delete this account from panel
		// e.g. DELETE FROM accounts WHERE username = '{$this->getUsername()}';
	}

	/**
	 * preformed before each restore
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with the post restore script.
	 */
	public function preRestore():void {
		// TODO implement, do any panel actions that needed before restore for that account occurs
	}

	/**
	 * preformed after each restore
	 * 
	 * @param PostRestoreData $data
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with the post restore script.
	 */
	public function postRestore(PostRestoreData $data):void {
		// TODO implement, do any panel actions that needed after restore for that account occurs
	}

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
	public function isVirtual(): bool { return $this->_data['virtual']; }
}