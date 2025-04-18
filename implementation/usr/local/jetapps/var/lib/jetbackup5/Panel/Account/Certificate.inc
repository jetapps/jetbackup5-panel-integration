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
use JetBackup\Panel\Panel;
use JetBackup\Core\Panel\Integration\Account\Certificate as iCertificate;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class Certificate implements iCertificate {

	private array $_data;
	private Account $_account;

	public function __construct(Account $account, array $data) {
		$this->_data = $data;
		$this->_account = $account;
	}

	/**
	 * provides the panel id.
	 * the panel id needs to be as follows 'MyCompany_PanelName'.
	 * e.g. 'JetApps_cPanel'.
	 *
	 * @return string represents the panel.
	 */
	public function getPanel(): string { return Panel::_getId(); }

	/**
	 * provides the domain of the certificate.
	 *
	 * @return string the certificate domain.
	 */
	public function getDomain(): string { return $this->_data['domain']; }

	/**
	 * provides the private key of the certificate.
	 *
	 * @return string the certificate private key.
	 */
	public function getPrivateKey(): string { return $this->_data['private_key']; }

	/**
	 * provides the certificate as string.
	 *
	 * @return string the certificate.
	 */
	public function getCertificate(): string { return $this->_data['certificate']; }

	/**
	 * provides a chain of certificate authority certificates.
	 *
	 * @return string a chain of CA certificates.
	 */
	public function getCAChain(): string { return $this->_data['ca_bundle']; }

	/**
	 * provides the custom data of the certificate (optional, can return an empty string).
	 * it includes any information that the panel needs for the certificate.
	 * it's an internal data of the panel, it can receive whatever the panel needs,
	 * the data will be backed up and restored as is.
	 *
	 * @return string the custom data of the certificate.
	 */
	public function getCustomData(): string { return ''; }

	/**
	 * removes the certificate.
	 *
	 * @return void
	 * @throws PanelException throws if there is an issue with removing the certificate.
	 */
	public function remove():void {
		// TODO implement, remove this certificate for this account
		// e.g. DELETE FROM certificates WHERE account = '{$this->_account->getUsername()}' AND domain = '{$this->getDomain()}'
	}
}