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

use JetBackup\Core\Exception\PanelException;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface Certificate {

	/**
     * returns the panel id (same panel id as in \JetBackup\Core\Panel\Integration\PanelInfo::getId()).
     *
	 * @return string represents the panel.
     * @throws PanelException
	 */
	public function getPanel(): string;

	/**
     * returns the domain of the certificate.
     *
	 * @return string the certificate domain.
     * @throws PanelException
	 */
	public function getDomain(): string;

	/**
     * returns the private key of the certificate.
     *
	 * @return string the certificate private key.
     * @throws PanelException
	 */
	public function getPrivateKey(): string;

	/**
     * returns the certificate as string.
     *
	 * @return string the certificate.
     * @throws PanelException
	 */
	public function getCertificate(): string;

	/**
     * returns a chain of certificate authority certificates.
     *
	 * @return string a chain of CA certificates.
     * @throws PanelException
	 */
	public function getCAChain(): string;

	/**
     * returns the custom data of the certificate (optional, can returns an empty string).
     * it includes any information that the panel needs for the certificate.
     * its an internal data of the panel, it can receives whatever the panel needs,
     * the data will be backed up and restored as is.
     *
	 * @return string the custom data of the certificate.
     * @throws PanelException
	 */
	public function getCustomData(): string;

	/**
     * removes the certificate.
     *
	 * @throws PanelException
	 */
	public function remove();
}