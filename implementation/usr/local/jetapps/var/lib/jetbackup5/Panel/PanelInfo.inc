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
namespace JetBackup\Panel;

use JetBackup\Core\Panel\Integration\PanelInfo as iPanelInfo;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class PanelInfo implements iPanelInfo {

	/**
	 * provides the panel id.
	 * the panel id needs to be as follows 'MyCompany_PanelName'.
	 * e.g. 'JetApps_cPanel'.
	 *
	 * @return string the panel id.
	 */
	public function getId(): string { return 'JetApps_cPanel'; }

	/**
	 * provides the panel name.
	 * e.g. 'PanelName'.
	 *
	 * @return string the panel name
	 */
	public function getName(): string { return 'cPanel'; }

	/**
	 * provides the panel current version.
	 * e.g. '1.0.0'.
	 *
	 * @return string the panel current version
	 */
	public function getVersion(): string { return '5.3.0'; }

	/**
	 * provides the panel current tier.
	 * e.g. 'STABLE', 'BETA', 'EDGE' or 'ALPHA'.
	 *
	 * @return string the panel current tier
	 */
	public function getTier(): string { return 'ALPHA'; }
}