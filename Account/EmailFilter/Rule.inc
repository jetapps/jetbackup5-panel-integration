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
namespace JetBackup\Core\Panel\Integration\Account\EmailFilter;

use JetBackup\Core\Exception\PanelException;

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface Rule {

	const PART_FROM             = 1;
	const PART_SUBJECT          = 2;
	const PART_TO               = 3;
	const PART_REPLY            = 4;
	const PART_BODY             = 5;
	const PART_HEADER           = 6;
	const PART_RECIPIENT        = 7;
	const PART_NOT_DELIVERED    = 8;
	const PART_IS_ERROR         = 9;
	const PART_LIST_ID          = 10;
	const PART_SPAM_STATUS      = 11;
	const PART_SPAM_BAR         = 12;
	const PART_SPAM_SCORE       = 13;

	const MATCH_CONTAINS        = 1;
	const MATCH_REGEX           = 2;
	const MATCH_NOT_CONTAINS    = 3;
	const MATCH_EQUALS          = 4;
	const MATCH_BEGINS_WITH     = 5;
	const MATCH_ENDS_WITH       = 6;
	const MATCH_NOT_BEGINS_WITH = 7;
	const MATCH_NOT_ENDS_WITH   = 8;
	const MATCH_NOT_REGEX       = 9;
	const MATCH_IS_ABOVE        = 10;
	const MATCH_IS_NOT_ABOVE    = 11;
	const MATCH_IS_BELOW        = 12;
	const MATCH_IS_NOT_BELOW    = 13;

	const CONDITION_OR          = 1;
	const CONDITION_AND         = 2;

	/**
	 * @return int
	 */
	public function getPart(): int;

	/**
	 * @return int
	 */
	public function getMatch(): int;

	/**
	 * @return string
	 */
	public function getValue(): string;

	/**
	 * @return int
	 */
	public function getCondition(): int;
}