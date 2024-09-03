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

interface IPAddress {

	const int TYPE_IPV4 = 1;
	const int TYPE_IPV6 = 2;
	
	/**
	 * provides the IP Address.
	 *
	 * @return string the IP Address.
	 */
	public function getIP(): string;

	/**
	 * @return bool main IP or not
	 */
	public function isMain(): bool;

	/**
	 * provides the type of the IP (ipv4 or ipv6).
	 *
	 * @return int the type of the IP.
	 */
	public function getType(): int;
}