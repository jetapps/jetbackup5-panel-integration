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

interface PanelSettings {

	/**
	 * provides the panel's default package.
	 *
	 * @return string the default panel package.
	 */
	public function getDefaultPackage(): string;

	/**
	 * provides the panel's default ip address.
	 *
	 * @return string the default panel ip address.
	 */
	public function getDefaultIPAddress(): string;

	/**
	 * provides the panel's default reseller.
	 *
	 * @return string the default panel reseller.
	 */
	public function getDefaultReseller(): string;
}