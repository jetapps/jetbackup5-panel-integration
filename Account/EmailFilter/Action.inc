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
namespace JetBackup\Core\Panel\Integration\Account\EmailFilter;

use JetBackup\Core\Exception\PanelException;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface Action {

	const ACTION_DELIVER    = 1;
	const ACTION_FAIL       = 2;
	const ACTION_FINISH     = 3;
	const ACTION_SAVE       = 4;
	const ACTION_PIPE       = 5;

	/**
	 * @return int
	 */
	public function getAction(): int;

	/**
	 * @return string
	 */
	public function getValue():? string;
}