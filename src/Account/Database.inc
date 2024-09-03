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
use JetBackup\Core\Panel\Integration\DatabaseAuth;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface Database {

	/**
	 * mysql database engine.
	 * @var int
	 */
	const int ENGINE_MYSQL      = 1;
	/**
	 * mogodb database engine.
	 * @var int
	 */
	const int ENGINE_MONGODB    = 2;
	/**
	 * postgresql database engine.
	 * @var int
	 */
	const int ENGINE_POSTGRESQL = 3;

	const int ENGINE_NAME_MYSQL       = 1;
	const int ENGINE_NAME_MARIADB     = 2;
	const int ENGINE_NAME_MONGODB     = 3;
	const int ENGINE_NAME_POSTGRESQL  = 4;

	/**
	 * an array of all the database engines types.
	 * @var int[]
	 */
	const array ENGINES = [self::ENGINE_MYSQL,self::ENGINE_MONGODB,self::ENGINE_POSTGRESQL];
	/**
	 * an array of all the database engines names.\
	 * @var string[]
	 */
	const array ENGINE_NAMES = [
		self::ENGINE_MYSQL          => 'MySQL',
		self::ENGINE_MONGODB        => 'MongoDB',
		self::ENGINE_POSTGRESQL     => 'PostgreSQL',
	];

	const array ENGINE_SUFFIX = [
		self::ENGINE_MYSQL          => 'mysql',
		self::ENGINE_MONGODB        => 'mdb',
		self::ENGINE_POSTGRESQL     => 'psql',
	];

	const array ENGINE_NAME_NAMES = [
		self::ENGINE_NAME_MYSQL         => 'MySQL',
		self::ENGINE_NAME_MARIADB       => 'MariaDB',
		self::ENGINE_NAME_MONGODB       => 'MongoDB',
		self::ENGINE_NAME_POSTGRESQL    => 'PostgreSQL',
	];

	/**
	 * provides the panel id.
	 * the panel id needs to be as follows 'MyCompany_PanelName'.
	 * e.g. 'JetApps_cPanel'.
	 *
	 * @return string represents the panel.
	 */
	public function getPanel():string;

	/**
	 * provides the name of the database.
	 *
	 * @return string the database name.
	 */
	public function getName():string;

	/**
	 * provides the engine of the database.
	 *
	 * @return int the database engine (see @uses for available engine types).
	 *
	 * @uses Database::ENGINE_MYSQL mysql database engine.
	 * @uses Database::ENGINE_MONGODB mogodb database engine.
	 * @uses Database::ENGINE_POSTGRESQL postgresql database engine.
	 */
	public function getEngine():int;

	/**
	 * provides the engine name of the database.
	 * 
	 * @return int the database engine name (see @uses for available engine types).
	 *
	 * @uses Database::ENGINE_NAME_MYSQL mysql database engine name.
	 * @uses Database::ENGINE_NAME_MARIADB mariadb database engine name.
	 * @uses Database::ENGINE_NAME_MONGODB mongodb database engine name.
	 * @uses Database::ENGINE_NAME_POSTGRESQL postresql database engine name.
	 */
	public function getEngineName():int;

	/**
	 * @return string
	 */
	public function getEngineVersion():string;

	/**
	 * provides the custom data of the database (optional, can return an empty string).
	 * it includes any information that the panel needs for the database.
	 * it's an internal data of the panel, it can receive whatever the panel needs,
	 * the data will be backed up and restored as is.
	 *
	 * @return string the custom data of the database.
	 */
	public function getCustomData(): string;

	/**
	 * @return DatabaseAuth|null
	 */
	public function getAuth():DatabaseAuth|null;

	/**
	 * removes the database.
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with removing the database.
	 */
	public function remove():void;
}