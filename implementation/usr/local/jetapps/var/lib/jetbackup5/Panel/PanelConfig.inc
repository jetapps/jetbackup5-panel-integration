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

use JetBackup\Core\JetBackup;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class PanelConfig implements \JetBackup\Core\Panel\Integration\PanelConfig {

	private $_data;
	
	public function __construct() {
		$this->_data = [];
		$this->_load();
	}

	/**
	 * @return array
	 */
	public function getFields(): array {
		return ['default_owner', 'default_ip', 'default_password'];
	}

	/**
	 * @return array
	 */
	public function getProtectedFields(): array { return ['default_password']; }

	public function getDefaultOwner() { return $this->_data['default_owner'] ?? ''; }
	public function getDefaultIP() { return $this->_data['default_ip'] ?? ''; }
	public function getDefaultPassword() { return $this->_data['default_password'] ?? ''; }

	private function _load() {
		if(!file_exists(JetBackup::PANEL_CONFIG_FILE)) return;
		$this->_data = parse_ini_file(JetBackup::PANEL_CONFIG_FILE, false, INI_SCANNER_RAW);
	}

	/**
	 * validates the inputted data while saving the form
	 * 
	 * @return void
	 */
	public function validateFields(): void {}
}