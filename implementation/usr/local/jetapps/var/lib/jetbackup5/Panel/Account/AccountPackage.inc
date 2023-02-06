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
namespace JetBackup\Panel\Account;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class AccountPackage implements \JetBackup\Core\Panel\Integration\Account\AccountPackage {

	private $_name;
	private $_type;
	
	/**
	 * provides the name of the package.
	 *
	 * @return string the package name.
	 */
	public function getName(): string { return $this->_name; }
	public function setName($name) { $this->_name = $name; }

	/**
	 * provides the package type.
	 *
	 * @return int the package type.
	 */
	public function getType():? int { return $this->_type; }
	public function setType($type) { $this->_type = (int) $type; }
}