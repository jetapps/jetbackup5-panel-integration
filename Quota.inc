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
namespace JetBackup\Core\Panel\Integration;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface Quota {

	/**
     * provides the disk usage quota.
     *
	 * @return int the disk usage quota, if the panel doesn't support disk space usage return -1.
	 */
	public function getDiskUsage(): int;

	/**
     * provides the free disk quota.
     *
	 * @return int the free disk quota, if the panel doesn't support free disk space information return -1.
	 */
	public function getDiskFree(): int;

	/**
     * provides the total disk quota.
     *
	 * @return int the total disk quota, if the panel doesn't support total disk space information return -1.
	 */
	public function getDiskTotal(): int;

	/**
     * provides the inode usage quota.
     *
	 * @return int the inode usage quota, if the panel doesn't support inode usage return -1.
	 */
	public function getInodeUsage(): int;
}