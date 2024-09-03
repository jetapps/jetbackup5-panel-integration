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

	const int VERSION_44 = 44;
	const int VERSION_51 = 51;
	const int VERSION_52 = 52;
	const int VERSION_53 = 53;
	const int VERSION_54 = 54;
	const int VERSION_55 = 55;
	const int VERSION_56 = 56;
	const int VERSION_70 = 70;
	const int VERSION_71 = 71;
	const int VERSION_72 = 72;
	const int VERSION_73 = 73;
	const int VERSION_74 = 74;
	const int VERSION_80 = 80;
	const int VERSION_81 = 81;
	const int VERSION_82 = 82;
	const int VERSION_83 = 83;
	const int VERSION_84 = 84;

	const int HANDLER_CGI       = 1;
	const int HANDLER_FCGI      = 2;
	const int HANDLER_FPM       = 3;
	const int HANDLER_SUPHP     = 4;
	const int HANDLER_LSPHP     = 5;
	const int HANDLER_LSAPI     = 6;
	const int HANDLER_DSO       = 7;
	const int HANDLER_NONE      = 8;

	/**
	 * provides the PHP version.
	 *
	 * @return int|null the PHP version, return null if not needed.
	 * 
	 * @uses PHPDetails::VERSION_44 for PHP 4.4
	 * @uses PHPDetails::VERSION_51 for PHP 5.1
	 * @uses PHPDetails::VERSION_52 for PHP 5.2
	 * @uses PHPDetails::VERSION_53 for PHP 5.3
	 * @uses PHPDetails::VERSION_54 for PHP 5.4
	 * @uses PHPDetails::VERSION_55 for PHP 5.5
	 * @uses PHPDetails::VERSION_56 for PHP 5.6
	 * @uses PHPDetails::VERSION_70 for PHP 7.0
	 * @uses PHPDetails::VERSION_71 for PHP 7.1
	 * @uses PHPDetails::VERSION_72 for PHP 7.2
	 * @uses PHPDetails::VERSION_73 for PHP 7.3
	 * @uses PHPDetails::VERSION_74 for PHP 7.4
	 * @uses PHPDetails::VERSION_80 for PHP 8.0
	 * @uses PHPDetails::VERSION_81 for PHP 8.1
	 * @uses PHPDetails::VERSION_82 for PHP 8.2
	 * @uses PHPDetails::VERSION_83 for PHP 8.3
	 * @uses PHPDetails::VERSION_84 for PHP 8.4
	 */
	public function getVersion():? int;

	/**
	 * provides the PHP handler.
	 *
	 * @return int|null the PHP handler, return null if not needed.
	 * 
	 * @uses PHPDetails::HANDLER_CGI for CGI handler
	 * @uses PHPDetails::HANDLER_FCGI for FCGI (FCGId) handler
	 * @uses PHPDetails::HANDLER_FPM for FPM (FastCGI Process Manager) handler
	 * @uses PHPDetails::HANDLER_SUPHP for suPHP handler
	 * @uses PHPDetails::HANDLER_LSPHP for LSPHP handler
	 * @uses PHPDetails::HANDLER_LSAPI for LSAPI handler
	 * @uses PHPDetails::HANDLER_DSO for DSO handler
	 * @uses PHPDetails::HANDLER_NONE for none php handler
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