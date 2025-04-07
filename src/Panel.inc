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
namespace JetBackup\Core\Panel\Integration;

use JetBackup\Core\Exception\PanelException;
use JetBackup\Core\Panel\Integration\Account\Account;
use JetBackup\Core\Panel\Integration\Account\Config;
use JetBackup\Core\Panel\Integration\Account\Database;
use JetBackup\Core\Panel\Log;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface Panel {

	/**
	 * provides the information about the panel.
	 * the information return as PanelInfo and includes the panel id, name, version and tier.
	 *
	 * @return PanelInfo holds all the needed information about the panel.
	 */
	public function getInfo(): PanelInfo;

	/**
	 * provides the path to the public directory.
	 * returns the full path of the public directory, where all the GUI files placed.
	 *
	 * @return string the full path of the public directory.
	 */
	public function getPublicDir(): string;

	/**
	 * provides the number of accounts in the panel.
	 *
	 * @return int the number of accounts.
	 * @throws PanelException throws if there is an issue with getting the number of accounts in the panel.
	 */
	public function countAccounts(): int;

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
	public function listAccounts(int $limit=0, int $page=0): array;

	/**
	 * provides the desired account information.
	 *
	 * @param string $username the username of the desired account.
	 *
	 * @return Account|null includes all the information about the desired account.
	 * @throws PanelException throws if there is an issue with getting the account.
	 */
	public function getAccount(string $username):Account|null;

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
	public function createAccount(string $username, Config $config): Account;

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
	public function getDatabaseAuth(int $engine):DatabaseAuth|null;

	/**
	 * @param Log $logger
	 */
	public function setLogger(Log $logger);

	/**
	 * Handle all the panel-related operations that are needed for each panel after a Disaster Recovery.
	 *
	 * @throws PanelException
	 */
	public function postDisasterRecovery();
}