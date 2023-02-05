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
namespace JetBackup\Core\Panel\Integration\Account;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface PHPDetails {

	const VERSION_44 = 44;
	const VERSION_51 = 51;
	const VERSION_52 = 52;
	const VERSION_53 = 53;
	const VERSION_54 = 54;
	const VERSION_55 = 55;
	const VERSION_56 = 56;
	const VERSION_70 = 70;
	const VERSION_71 = 71;
	const VERSION_72 = 72;
	const VERSION_73 = 73;
	const VERSION_74 = 74;
	const VERSION_80 = 80;
	const VERSION_81 = 81;
	const VERSION_82 = 82;

	const HANDLER_CGI       = 1;
	const HANDLER_FCGI      = 2;
	const HANDLER_FPM       = 3;
	const HANDLER_SUPHP     = 4;
	const HANDLER_LSPHP     = 5;
	const HANDLER_LSAPI     = 6;
	const HANDLER_DSO       = 7;

	/**
	 * provides the PHP version.
	 *
	 * @return int|null the PHP version, return null if not needed.
	 * 
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::VERSION_44 for PHP 4.4
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::VERSION_51 for PHP 5.1
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::VERSION_52 for PHP 5.2
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::VERSION_53 for PHP 5.3
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::VERSION_54 for PHP 5.4
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::VERSION_55 for PHP 5.5
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::VERSION_56 for PHP 5.6
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::VERSION_70 for PHP 7.0
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::VERSION_71 for PHP 7.1
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::VERSION_72 for PHP 7.2
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::VERSION_73 for PHP 7.3
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::VERSION_74 for PHP 7.4
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::VERSION_80 for PHP 8.0
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::VERSION_81 for PHP 8.1
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::VERSION_82 for PHP 8.2
	 */
	public function getVersion():? int;

	/**
	 * provides the PHP handler.
	 *
	 * @return int|null the PHP handler, return null if not needed.
	 * 
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::HANDLER_CGI for CGI handler
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::HANDLER_FCGI for FCGI (FCGId) handler
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::HANDLER_FPM for FPM (FastCGI Process Manager) handler
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::HANDLER_SUPHP for suPHP handler
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::HANDLER_LSPHP for LSPHP handler
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::HANDLER_LSAPI for LSAPI handler
	 * @uses \JetBackup\Core\Panel\Integration\Account\PHPDetails::HANDLER_DSO for DSO handler
	 */
	public function getHandler():? int;

	/**
	 * determine if PHP was using CloudLinux or Panel native    
	 * 
	 * @return bool
	 */
	public function isCLSelector(): bool;

	/**
	 * determine if PHP was inherited from the system default PHP
	 * 
	 * @return bool
	 */
	public function isInherited(): bool;
}