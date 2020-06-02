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

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface Panel {

    /**
     * Panel constructor.
     *
     * @param PanelSettings $settings holds the needed panel default settings information.
     *
     * @return Panel the new created Panel.
     */
	public function __construct(PanelSettings $settings);

	/**
     * returns the panel information (id, name, version and tier).
     *
	 * @return PanelInfo holds all the needed information about the panel.
     * @throws PanelException
	 */
	public function getInfo(): PanelInfo;

	/**
     * returns the full path of the public directory, where all the GUI files placed.
     *
	 * @return string the full path of the public directory.
     * @throws PanelException
	 */
	public function getPublicDir(): string;

	/**
     * returns the number of accounts in the panel.
     *
	 * @return int the number of accounts.
	 * @throws PanelException
	 */
	public function countAccounts(): int;

	/**
     * returns an array of the panel accounts.
     *
	 * @param int $limit the limit of the results per chunk.
	 * @param int $page the pagination number you want to receive.
	 *
	 * @return Account[] an array of the panel Account, the amount of accounts is set by the $limit variable.
     *
	 * @throws PanelException
	 */
	public function listAccounts($limit=0, $page=0): array;

	/**
     * returns the account that its username matches the passed $username parameter.
     *
	 * @param string $username the username of the desired account.
	 *
	 * @return Account|null the desired account.
	 * @throws PanelException
	 */
	public function getAccount($username):? Account;

	/**
     * creates new account.
     * if there is already an existing account with that username,
     * the function will updates the account data.
     *
	 * @param string $username the username for the new account.
	 * @param Config $config the needed config for the new account creation.
	 *
	 * @return Account the new added account.
	 * @throws PanelException
	 */
	public function createAccount($username, Config $config): Account;

	/**
     * returns the database authentication information.
     *
	 * @param int $engine the database engine (mysql/mongodb/postgresql).
     * @uses Database::ENGINE_MYSQL mysql database engine.
     * @uses Database::ENGINE_MONGODB mogodb database engine.
     * @uses Database::ENGINE_POSTGRESQL postgresql database engine.
	 *
	 * @return DatabaseAuth holds the database authentication information.
     * @throws PanelException
	 */
	public function getDatabaseAuth($engine):? DatabaseAuth;
}