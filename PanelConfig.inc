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

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface PanelConfig {

	const PROTECTED_FIELD = 'JB|HIDDEN|********************';

	/**
	 * @return array
	 */
	public function getFields(): array;

	/**
	 * @return array
	 */
	public function getProtectedFields(): array;
}