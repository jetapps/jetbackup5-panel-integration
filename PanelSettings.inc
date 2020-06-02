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

use JetBackup\Core\Exception\PanelException;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface PanelSettings {

	/**
     * returns the panel's default package.
     *
	 * @return string the default panel package.
     * @throws PanelException
	 */
	public function getDefaultPackage(): string;

	/**
     * returns the panel's default ip address.
     *
	 * @return string the default panel ip address.
     * @throws PanelException
	 */
	public function getDefaultIPAddress(): string;

	/**
     * returns the panel's default reseller.
     *
	 * @return string the default panel reseller.
     * @throws PanelException
	 */
	public function getDefaultReseller(): string;
}