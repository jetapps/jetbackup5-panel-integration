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

interface PanelInfo {

	/**
	 * provides the panel id.
	 * the the panel id needs to be as follow 'namespace_name'.
	 * e.g. 'MyCompany_PanelName'.
	 *
	 * @return string the panel id.
	 */
	public function getId(): string;

	/**
	 * provides the panel name.
	 * e.g. 'PanelName'.
	 *
	 * @return string the panel name
	 */
	public function getName(): string;

	/**
	 * provides the panel current version.
	 * e.g. '1.0.0'.
	 *
	 * @return string the panel current version
	 */
	public function getVersion(): string;

	/**
	 * provides the panel current tier.
	 * e.g. 'STABLE', 'BETA' or 'EDGE'.
	 *
	 * @return string the panel current tier
	 */
	public function getTier(): string;
}