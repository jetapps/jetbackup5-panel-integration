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

interface PanelInfo {

	/**
	 * returns the panel id (namespace_name - e.g. MyCompany_PanelName).
     *
	 * @return string the panel id.
     * @throws PanelException
	 */
	public function getId(): string;

	/**
	 * returns the panel name (e.g. PanelName).
     *
	 * @return string the panel name
     * @throws PanelException
	 */
	public function getName(): string;

	/**
	 * returns the panel current version (e.g. 1.0.0).
     *
	 * @return string the panel current version
     * @throws PanelException
	 */
	public function getVersion(): string;

	/**
	 * returns the panel current tier (e.g. STABLE, BETA or EDGE).
     *
	 * @return string the panel current tier
     * @throws PanelException
	 */
	public function getTier(): string;
}