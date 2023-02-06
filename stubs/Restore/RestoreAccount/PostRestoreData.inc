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
namespace JetBackup\Core\Restore\RestoreAccount;

use JetBackup\Core\Panel\Integration\Account\Certificate;
use JetBackup\Core\Panel\Integration\Account\Database;
use JetBackup\Core\Panel\Integration\Account\DatabaseUser;
use JetBackup\Core\Panel\Integration\Account\Domain;
use JetBackup\Core\Panel\Integration\Account\EmailAccount;
use JetBackup\Core\Panel\Integration\Account\FTPAccount;
use JetBackup\Core\Panel\Integration\Account\Package;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

class PostRestoreData {
	
	public function setSuspended($suspended) {}
	public function getSuspended(): bool {}
	public function setPackage(Package $package) {}
	public function getPackage(): Package {}
	public function setConfig(\JetBackup\Core\Panel\Integration\Account\Config $config) {}
	public function getConfig():? \JetBackup\Core\Panel\Integration\Account\Config {}
	public function setCronJob(string $cronJob) {}
	public function getCronJob():? string {}
	public function setHomedir(string $homedir) {}
	public function getHomedir():? string {}
	public function setCertificates($certificates) {}
	public function getCertificates(): array {}
	public function addCertificate(Certificate $certificate) {}
	public function setDatabases($databases) {}
	public function getDatabases(): array {}
	public function addDatabase(Database $database) {}
	public function setDatabaseUsers($users) {}
	public function getDatabaseUsers(): array {}
	public function addDatabaseUser(DatabaseUser $user) {}
	public function setDomains($domains) {}
	public function getDomains(): array {}
	public function addDomain(Domain $domain) {}
	public function setEmails($emails) {}
	public function getEmails(): array {}
	public function addEmail(EmailAccount $email) {}
	public function setFTPs($ftps) {}
	public function getFTPs(): array {}
	public function addFTP(FTPAccount $ftp) {}
}