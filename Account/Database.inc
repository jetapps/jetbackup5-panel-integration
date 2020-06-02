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
     * returns the panel id (same panel id as in \JetBackup\Core\Panel\Integration\PanelInfo::getId()).
     *
	 * @return string represents the panel.
     * @throws PanelException
	 */
	public function getPanel(): string;

	/**
     * returns the name of the database.
     *
	 * @return string the database name.
     * @throws PanelException
	 */
	public function getName(): string;

	/**
     * returns the engine of the database.
     *
	 * @return int the database engine (mysql/mongodb/postgresql).
     *
     * @uses Database::ENGINE_MYSQL mysql database engine.
     * @uses Database::ENGINE_MONGODB mogodb database engine.
     * @uses Database::ENGINE_POSTGRESQL postgresql database engine.
     *
     * @throws PanelException
	 */
	public function getEngine(): int;

	/**
     * returns the custom data of the database (optional, can returns an empty string).
     * it includes any information that the panel needs for the database.
     * its an internal data of the panel, it can receives whatever the panel needs,
     * the data will be backed up and restored as is.
     *
	 * @return string the custom data of the database.
     * @throws PanelException
	 */
	public function getCustomData(): string;

	/**
     * removes the database.
     *
     * @return void
	 * @throws PanelException
	 */
	public function remove();
}