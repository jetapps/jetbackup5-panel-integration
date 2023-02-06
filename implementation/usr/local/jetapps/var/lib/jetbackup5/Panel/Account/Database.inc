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
use JetBackup\Core\Panel\Integration\DatabaseAuth;
use JetBackup\Panel\Panel;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class Database implements \JetBackup\Core\Panel\Integration\Account\Database {

	/**
	 * provides the panel id.
	 * the panel id needs to be as follows 'MyCompany_PanelName'.
	 * e.g. 'JetApps_cPanel'.
	 *
	 * @return string represents the panel.
	 */
	public function getPanel(): string { return Panel::_getId(); }

	/**
	 * provides the name of the database.
	 *
	 * @return string the database name.
	 */
	public function getName(): string { return 'acct1_mydb'; }

	/**
	 * provides the engine of the database.
	 *
	 * @return int the database engine (see @uses for available engine types).
	 *
	 * @uses \JetBackup\Core\Panel\Integration\Account\Database::ENGINE_MYSQL mysql database engine.
	 * @uses \JetBackup\Core\Panel\Integration\Account\Database::ENGINE_MONGODB mogodb database engine.
	 * @uses \JetBackup\Core\Panel\Integration\Account\Database::ENGINE_POSTGRESQL postgresql database engine.
	 */
	public function getEngine(): int { return self::ENGINE_MYSQL; }

	/**
	 * provides the custom data of the database (optional, can return an empty string).
	 * it includes any information that the panel needs for the database.
	 * it's an internal data of the panel, it can receive whatever the panel needs,
	 * the data will be backed up and restored as is.
	 *
	 * @return string the custom data of the database.
	 */
	public function getCustomData(): string { return ''; }

	/**
	 * @return DatabaseAuth|null
	 */
	public function getAuth():? DatabaseAuth {
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

	/**
	 * removes the database.
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with removing the database.
	 */
	public function remove() {}
}