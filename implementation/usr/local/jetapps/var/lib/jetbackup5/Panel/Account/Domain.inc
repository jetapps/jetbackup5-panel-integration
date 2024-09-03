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

use JetBackup\Core\Exception\PanelException;
use JetBackup\Core\Panel\Integration\Account\IPAddress;
use JetBackup\Core\Panel\Integration\Account\PHPDetails;
use JetBackup\Panel\Panel;
use JetBackup\Core\Panel\Integration\Account\Domain as iDomain;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class Domain implements \JetBackup\Core\Panel\Integration\Account\Domain {
	
	/**
	 * provides the panel id.
	 * the panel id needs to be as follows 'MyCompany_PanelName'.
	 * e.g. 'JetApps_cPanel'.
	 *
	 * @return string represents the panel.
	 */
	public function getPanel(): string { return Panel::_getId(); }

	/**
	 * provides the name of the domain.
	 *
	 * @return string the domain name.
	 */
	public function getName(): string { return 'acct1.com'; }

	/**
	 * provides the public directory of the domain.
	 *
	 * @return string the public directory of the domain.
	 */
	public function getPublicDir(): string { return 'public_html'; }

	/**
	 * provides the type of the domain.
	 *
	 * @return int the domain type (see @uses for available domain types).
	 *
	 * @uses iDomain::TYPE_MAIN_DOMAIN main domain type.
	 * @uses iDomain::TYPE_ADDON_DOMAIN addon domain type.
	 * @uses iDomain::TYPE_SUBDOMAIN subdomain type.
	 * @uses iDomain::TYPE_ALIAS alias domain type.
	 * @uses iDomain::TYPE_DNS_ONLY DNS only domain type.
	 * @uses iDomain::TYPE_REDIRECT redirect domain type.
	 */
	public function getType(): int { return iDomain::TYPE_MAIN_DOMAIN; }

	/**
	 * provides the account IP
	 * 
	 * @return string|null
	 */
	public function getIPAddress():? string { return '1.2.3.4'; }

	/**
	 * provides the parent domain of the domain.
	 *
	 * @return iDomain|null the parent domain of this domain.
	 * @throws PanelException
	 */
	public function getParent():iDomain|null { return null; }

	/**
	 * provides the path to the zone file of the domain.
	 *
	 * @return null|string the path to the zone file of the domain.
	 */
	public function getZoneFile():string|null { return '/var/named/acct1.com.db'; }

	/**
	 * provides the domain php details
	 * 
	 * @return PHPDetails|null
	 */
	public function getPHPDetails():PHPDetails|null {
		return new class implements PHPDetails {
			public function getVersion(): ?int { return self::VERSION_81; }
			public function getHandler(): ?int { return self::HANDLER_FCGI; }
			public function isCLSelector(): bool { return false; }
			public function isInherited(): bool { return false; }
		};
	}

	/**
	 * provides the custom data of the domain (optional, can return an empty string).
	 * it includes any information that the panel needs for the domain.
	 * it's an internal data of the panel, it can receive whatever the panel needs,
	 * the data will be backed up and restored as is.
	 *
	 * @return string the custom data of the domain.
	 */
	public function getCustomData(): string { return ''; }

	/**
	 * removes the domain.
	 * it receives a boolean parameter that indicates whether you want to remove the domain data or not.
	 *
	 * @param bool $remove_data indicate if you want to remove the domain data or not.
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with removing the domain.
	 */
	public function remove(bool $remove_data=false):void {}

	/**
	 * return the domain IP addresses
	 *
	 * @return IPAddress[]
	 */
	public function getIPAddresses(): array {
		return [new class implements IPAddress {
			public function getIP(): string { return '8.8.8.8'; }
			public function isMain(): bool { return true; }
			public function getType(): int { return self::TYPE_IPV4; }
		}];
	}

	/**
	 * returns the redirect URL when domain type is iDomain::TYPE_REDIRECT
	 * 
	 * @return string|null
	 */
	public function getRedirectURL(): string|null { return 'https://google.com'; }

	/**
	 * returns the redirect code when domain type is iDomain::TYPE_REDIRECT
	 * 
	 * @return int|null
	 */
	public function getRedirectCode(): int|null { return 301; }
}