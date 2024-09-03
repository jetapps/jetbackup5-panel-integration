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

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface Action {

	const int ACTION_DELIVER    = 1;
	const int ACTION_FAIL       = 2;
	const int ACTION_FINISH     = 3;
	const int ACTION_SAVE       = 4;
	const int ACTION_PIPE       = 5;

	/**
	 * @return int
	 */
	public function getAction():int;

	/**
	 * @return string|null
	 */
	public function getValue():string|null;
}