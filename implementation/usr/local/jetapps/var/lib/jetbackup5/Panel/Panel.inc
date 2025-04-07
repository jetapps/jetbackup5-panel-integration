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
namespace JetBackup\Panel;

use JetBackup\Core\Exception\PanelException;
use JetBackup\Core\Panel\Integration\Account\Account;
use JetBackup\Core\Panel\Integration\Account\Config;
use JetBackup\Core\Panel\Integration\Account\Database;
use JetBackup\Core\Panel\Integration\DatabaseAuth;
use JetBackup\Core\Panel\Log;
use JetBackup\Core\Panel\Integration\Panel as iPanel;
use JetBackup\Core\Panel\Integration\PanelInfo as iPanelInfo;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class Panel implements iPanel {

	/**
	 * returns unique panel id
	 * 
	 * @return string
	 */
	public static function _getId(): string { return 'CompanyName_MyPanelName'; }

	/**
	 * provides the information about the panel.
	 * the information return as PanelInfo and includes the panel id, name, version and tier.
	 *
	 * @return iPanelInfo holds all the needed information about the panel.
	 */
	public function getInfo():iPanelInfo { return new PanelInfo(); }

	/**
	 * provides the path to the public directory.
	 * returns the full path of the public directory, where all the GUI files placed within the panel fs.
	 *
	 * @return string the full path of the public directory.
	 */
	public function getPublicDir(): string { return '/usr/local/cpanel/whostmgr/docroot/templates/jetbackup5'; }

	/**
	 * provides the number of accounts in the panel.
	 *
	 * @return int the number of accounts.
	 * @throws PanelException throws if there is an issue with getting the number of accounts in the panel.
	 */
	public function countAccounts(): int {
		// TODO implement, count of all accounts
		// e.g. SELECT COUNT(*) as total FROM accounts;
		$result = 2;
		//
		return $result; 
	}

	/**
	 * provides an array of the panel accounts.
	 * the amount of accounts in the array is set by the $limit variable.
	 *
	 * @param int $limit the limit of the results per chunk.
	 * @param int $page the pagination number you want to receive.
	 *
	 * @return Account[] an array of the panel Account.
	 * @throws PanelException throws if there is an issue with getting the accounts in the panel.
	 */
	public function listAccounts($limit=0, $page=0): array {
		
		$skip = $page > 0 ? ($page-1) * $limit : 0;
		// TODO implement, fetch list of all accounts
		// e.g. SELECT * FROM accounts LIMIT $skip, $limit;
		$result = [
			[
				'username'          => 'acct1',
				'nickname'          => 'Account01',
				'domain'            => 'acct1.com',
				'homedir'           => '/home/acct1',
				'homedir_owner'     => 'acct1',
				'homedir_group'     => 'nobody',
				'homedir_perms'     => 0751,
				'creation_date'     => 1672524000,
				'root'              => false,
				'reseller'          => false,
				'suspended'         => false,
				'virtual'           => false, // is this account doesn't have linux account
				'login_only'        => false, // for account that doesn't include in backups and restore, will be able to login to UI and view all accounts under it (e.g. root) 
				'owner'             => 'root',
				'email'             => 'acct1@acct1.com',
				'password'          => '$6$Fg5PejVYNxGTafDO$5mKgXEIBpH6ZXT5mYO9boTCPif7jgpCuu.MbOVWzwnTUYJ/iZ5WVlKEDEBmtq0jatjFQWfD8oXruxXJEQPLOW.',
				'ip'                => '1.2.3.4'
			],
			[
				'username'          => 'acct2',
				'nickname'          => 'Account02',
				'domain'            => 'acct2.com',
				'homedir'           => '/home/acct2',
				'homedir_owner'     => 'acct2',
				'homedir_group'     => 'nobody',
				'homedir_perms'     => 0751,
				'creation_date'     => 1672524000,
				'root'              => false,
				'reseller'          => false,
				'suspended'         => false,
				'virtual'           => false, // is this account doesn't have linux account
				'login_only'        => false, // for account that doesn't include in backups and restore, will be able to login to UI and view all accounts under it (e.g. root) 
				'owner'             => 'root',
				'email'             => 'acct2@acct2.com',
				'password'          => '$6$Fg5PejVYNxGTafDO$5mKgXEIBpH6ZXT5mYO9boTCPif7jgpCuu.MbOVWzwnTUYJ/iZ5WVlKEDEBmtq0jatjFQWfD8oXruxXJEQPLOW.',
				'ip'                => '1.2.3.4'
			],
		];
		//
		
		$accounts = [];
		foreach($result as $data) $accounts[] = new \JetBackup\Panel\Account\Account($data);
		return $accounts; 
	}

	/**
	 * provides the desired account information.
	 *
	 * @param string $username the username of the desired account.
	 *
	 * @return Account|null includes all the information about the desired account.
	 * @throws PanelException throws if there is an issue with getting the account.
	 */
	public function getAccount($username):? Account {

		// TODO implement, fetch list of all accounts
		// e.g. SELECT * FROM accounts WHERE username = '$username';
		$result = [
			'username'          => 'acct1',
			'nickname'          => 'Account01',
			'domain'            => 'acct1.com',
			'homedir'           => '/home/acct1',
			'homedir_owner'     => 'acct1',
			'homedir_group'     => 'nobody',
			'homedir_perms'     => 0751,
			'creation_date'     => 1672524000,
			'root'              => false,
			'reseller'          => false,
			'suspended'         => false,
			'virtual'           => false, // is this account doesn't have linux account
			'login_only'        => false, // for account that doesn't include in backups and restore, will be able to login to UI and view all accounts under it (e.g. root) 
			'owner'             => 'root',
			'email'             => 'acct1@acct1.com',
			'password'          => '$6$Fg5PejVYNxGTafDO$5mKgXEIBpH6ZXT5mYO9boTCPif7jgpCuu.MbOVWzwnTUYJ/iZ5WVlKEDEBmtq0jatjFQWfD8oXruxXJEQPLOW.',
			'ip'                => '1.2.3.4'
		];
		//

		return new \JetBackup\Panel\Account\Account($result); 
	}

	/**
	 * creates new account.
	 * if there is already an existing account with that username,
	 * the function will update the account data.
	 *
	 * @param string $username the username for the new account.
	 * @param Config $config the needed config for the new account creation.
	 *
	 * @return Account the new added account.
	 * @throws PanelException throws if there is an issue with creating the accounts.
	 */
	public function createAccount($username, Config $config): Account {

		// TODO implement, Add/Modify this account into your panel

		// if account exists in panel e.g.
		// UPDATE account
		// SET domain = '{$config->getMainDomain()}', ...
		// WHERE username = '$username'

		// if account doesn't exists in panel e.g.
		// INSERT INTO accounts (`username`, `domain`, ...)
		// VALUES ('$username', '{$config->getMainDomain()}', ...)

		return $this->getAccount($username);
	}

	/**
	 * provides the database authentication information.
	 *
	 * @param int $engine the database engine (see @uses for available engine types).
	 * @uses Database::ENGINE_MYSQL mysql database engine.
	 * @uses Database::ENGINE_MONGODB mogodb database engine.
	 * @uses Database::ENGINE_POSTGRESQL postgresql database engine.
	 *
	 * @throws PanelException
	 * @return DatabaseAuth|null holds the database authentication information.
	 */
	public function getDatabaseAuth($engine):? DatabaseAuth {
		
		if($engine == Database::ENGINE_MYSQL) {
			return new class implements DatabaseAuth {
				public function getPort(): int { return 3306; }
				public function getHostname(): string { return 'localhost'; }
				public function getUsername(): string { return 'root'; }
				public function getPassword(): string { return '123456'; }
				public function getAuthDatabase(): string { return ''; }
				public function getSocket(): ?string { return null; }
				public function getLibDir(): string { return '/var/lib/mysql'; }
				public function isLocal(): bool { return true; }
			};
		}
		
		return null;
	}

	/**
	 * @param Log $logger
	 */
	public function setLogger(Log $logger) {}
	
	public function postDisasterRecovery() {}
}