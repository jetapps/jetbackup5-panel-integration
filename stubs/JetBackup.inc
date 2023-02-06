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
namespace JetBackup\Core;

use JetBackup\Core\Panel\Integration\DatabaseAuth;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class JetBackup {
	const JETBACKUP_IDENTITY = '';

	const BASE_PATH = '';
	const VAR_PATH = '';
	const LIB_PATH = '';
	const LOG_PATH = '';
	const RUN_PATH = '';
	const WWW_PATH = '';
	const DOCROOT_PATH = '';
	const ETC_PATH = '';
	const USR_PATH = '';
	const BIN_PATH = '';
	const TMP_PATH = '';
	const PLUGIN_PATH = '';
	const INSTALL_PATH = '';
	const SHOWCASE_PATH = '';
	const CORE_PATH = '';
	const PANEL_PATH = '';
	const BACKUPS_CONF_PATH = '';
	const CLONES_CONF_PATH = '';
	const TRDPARTY_PATH = '';
	const PANEL_CONFIG_FILE = '';

	/**
	 * @return DatabaseAuth
	 */
	public static function getDatabaseAuth() {}
}