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

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class Certificate implements \JetBackup\Core\Panel\Integration\Account\Certificate {

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
	public function getDomain(): string { return 'acct1.com'; }

	/**
	 * provides the private key of the certificate.
	 *
	 * @return string the certificate private key.
	 */
	public function getPrivateKey(): string { return ''; }

	/**
	 * provides the certificate as string.
	 *
	 * @return string the certificate.
	 */
	public function getCertificate(): string { return ''; }

	/**
	 * provides a chain of certificate authority certificates.
	 *
	 * @return string a chain of CA certificates.
	 */
	public function getCAChain(): string { return ''; }

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
	public function remove() {}
}