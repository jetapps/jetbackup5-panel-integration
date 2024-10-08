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
use JetBackup\Core\Panel\Integration\Account\Package;
use JetBackup\Panel\Panel;
use JetBackup\Core\Panel\Integration\Account\Config as iConfig;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class Config implements iConfig {

	/**
	 * provides the panel id.
	 * the panel id needs to be as follows 'MyCompany_PanelName'.
	 * e.g. 'JetApps_cPanel'.
	 *
	 * @return string represents the panel.
	 */
	public function getPanel(): string { return Panel::_getId(); }

	/**
	 * provides the path for the config files.
	 * the path to the config files, that contains all the information about the
	 * user that the panel needs in order to create the account in the case of account restoration.
	 *
	 * @return string|null the path for the config files.
	 * @throws PanelException throws if there is an issue with getting the path.
	 */
	public function getPath():? string { return '/path/to/account/config'; }

	/**
	 * provides the main domain of the account.
	 *
	 * @return string|null the account main domain.
	 */
	public function getMainDomain():? string { return 'acct1.com'; }

	/**
	 * provides the password of the account.
	 * the password must be linux hashed password.
	 * e.g. '$6$gCkMes6kAaTVnP9j$rdBl...S8ectusndrupAIRAdtQatY1'.
	 *
	 * @return string|null the account hashed password.
	 */
	public function getPassword():? string { return '$6$Fg5PejVYNxGTafDO$5mKgXEIBpH6ZXT5mYO9boTCPif7jgpCuu.MbOVWzwnTUYJ/iZ5WVlKEDEBmtq0jatjFQWfD8oXruxXJEQPLOW.'; }

	/**
	 * provides the ip address of the account.
	 *
	 * @return string|null the account ip address.
	 */
	public function getIPAddress():? string { return '1.2.3.4'; }

	/**
	 * provides the package of the account.
	 *
	 * @return Package the account package.
	 */
	public function getPackage(): Package {
		return new class implements Package {
			public function getName(): string { return 'mypackage'; }
			public function getQuota(): int { return self::UNLIMITED; }
			public function getBandwidth(): int { return self::UNLIMITED; }
			public function getMaxInodes(): int { return self::UNLIMITED; }
			public function getMaxFTPAccounts(): int { return self::UNLIMITED; }
			public function getMaxEmailAccounts(): int { return self::UNLIMITED; }
			public function getMaxEmailForwarders(): int { return self::UNLIMITED; }
			public function getMaxDatabases(): int { return self::UNLIMITED; }
			public function getMaxSubDomains(): int { return self::UNLIMITED; }
			public function getMaxAliasDomains(): int { return self::UNLIMITED; }
			public function getMaxAddonDomains(): int { return self::UNLIMITED; }
			public function getMaxMailingLists(): int { return self::UNLIMITED; }
			public function getMaxAutoresponders(): int { return self::UNLIMITED; }
			public function getCGIAccess(): bool { return true; }
			public function getShellAccess(): bool { return true; }
			public function getCustomData(): string { return ''; }
			public function isCustom(): bool { return false; }
		};
	}

	/**
	 * provides the owner of the account.
	 *
	 * @return string|null the account owner.
	 */
	public function getOwner():? string { return 'root'; }

	/**
	 * provides the custom data of the account (optional, can return an empty string).
	 * it includes any information that the panel needs for the account.
	 * it's an internal data of the panel, it can receive whatever the panel needs,
	 * the data will be backed up and restored as is.
	 *
	 * @return string the account custom data.
	 */
	public function getCustomData(): string { return ''; }

	/**
	 * provides the email address of the account.
	 *
	 * @return string|null the account email address.
	 */
	public function getEmailAddress():? string { return 'acct1@acct1.com'; }

	/**
	 * returns true if the account is suspended and false otherwise.
	 *
	 * @return bool is the account suspended or not.
	 */
	public function isSuspended(): bool { return false; }

	/**
	 * returns true if the account was suspended in the backup and false otherwise.
	 *
	 * @return bool is the account suspended or not.
	 */
	public function isSuspendedReal(): bool { return false; }

	/**
	 * returns true if the account is root and false otherwise.
	 *
	 * @return bool is the account root or not.
	 */
	public function isRoot(): bool { return false; }

	/**
	 * returns true if the account is reseller and false otherwise.
	 *
	 * @return bool is the account reseller or not.
	 */
	public function isReseller(): bool { return false; }

	/**
	 * return the account IP addresses
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
	 * returns true if the account is virtual account (not a linux user) and false otherwise.
	 *
	 * @return bool
	 */
	public function isVirtual(): bool { return false; }

	/**
	 * removes configuration files.
	 * removes any temporary configuration files that might have been created
	 * in an earlier stage by the 'getPath' function (optional).
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with removing the configuration files.
	 */
	public function remove():void {}
}