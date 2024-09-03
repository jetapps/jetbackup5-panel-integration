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

use JetBackup\Core\Exception\ValidationException;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface PanelConfig {

	const string PROTECTED_FIELD = 'JB|HIDDEN|********************';

	/**
	 * @return array
	 */
	public function getFields(): array;

	/**
	 * @return array
	 */
	public function getProtectedFields(): array;

	/**
	 * @return void
	 * @throws ValidationException
	 */
	public function validateFields(): void;
}