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

interface AccountPackage {

	const TYPE_USER         = 1;
	const TYPE_RESELLER     = 2;

	/**
	 * provides the name of the package.
	 *
	 * @return string the package name.
	 */
	public function getName(): string;

	/**
	 * provides the package type.
	 *
	 * @return int the package type.
	 */
	public function getType():? int;
}