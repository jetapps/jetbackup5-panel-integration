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

interface RecordList {

	/**
	 * @return array
	 */
	public function getItems(): array;

	/**
	 * @return int
	 */
	public function getTotal(): int;
}