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

interface Database {

    /**
     * mysql database engine.
     * @var int
     */
	const ENGINE_MYSQL      = 1;
    /**
     * mogodb database engine.
     * @var int
     */
	const ENGINE_MONGODB    = 2;
    /**
     * postgresql database engine.
     * @var int
     */
	const ENGINE_POSTGRESQL = 3;

	/**
     * an array of all the database engines types.
     * @var int[]
     */
	const ENGINES = [self::ENGINE_MYSQL,self::ENGINE_MONGODB,self::ENGINE_POSTGRESQL];
	/**
     * an array of all the database engines names.
     * @var string[]
     */
	const ENGINE_NAMES = [
		self::ENGINE_MYSQL          => 'MySQL',
		self::ENGINE_MONGODB        => 'MongoDB',
		self::ENGINE_POSTGRESQL     => 'PostgreSQL',
	];

	/**
     * provides the panel id.
     * the panel id is the same panel id as in \JetBackup\Core\Panel\Integration\PanelInfo::getId().
     *
	 * @return string represents the panel.
	 */
	public function getPanel(): string;

	/**
     * provides the name of the database.
     *
	 * @return string the database name.
	 */
	public function getName(): string;

	/**
     * provides the engine of the database.
     *
	 * @return int the database engine (see @uses for available engine types).
     *
     * @uses \JetBackup\Core\Panel\Integration\Account\Database::ENGINE_MYSQL mysql database engine.
     * @uses \JetBackup\Core\Panel\Integration\Account\Database::ENGINE_MONGODB mogodb database engine.
     * @uses \JetBackup\Core\Panel\Integration\Account\Database::ENGINE_POSTGRESQL postgresql database engine.
	 */
	public function getEngine(): int;

	/**
     * provides the custom data of the database (optional, can returns an empty string).
     * it includes any information that the panel needs for the database.
     * its an internal data of the panel, it can receives whatever the panel needs,
     * the data will be backed up and restored as is.
     *
	 * @return string the custom data of the database.
	 */
	public function getCustomData(): string;

	/**
     * removes the database.
     *
     * @return void
	 * @throws PanelException throws if there is an issue with removing the database.
	 */
	public function remove();
}