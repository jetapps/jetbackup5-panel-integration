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

defined( '__JETBACKUP__' ) or die( 'Restricted access' );

interface Rule {

	const int PART_FROM             = 1;
	const int PART_SUBJECT          = 2;
	const int PART_TO               = 3;
	const int PART_REPLY            = 4;
	const int PART_BODY             = 5;
	const int PART_HEADER           = 6;
	const int PART_RECIPIENT        = 7;
	const int PART_NOT_DELIVERED    = 8;
	const int PART_IS_ERROR         = 9;
	const int PART_LIST_ID          = 10;
	const int PART_SPAM_STATUS      = 11;
	const int PART_SPAM_BAR         = 12;
	const int PART_SPAM_SCORE       = 13;

	const int MATCH_CONTAINS        = 1;
	const int MATCH_REGEX           = 2;
	const int MATCH_NOT_CONTAINS    = 3;
	const int MATCH_EQUALS          = 4;
	const int MATCH_BEGINS_WITH     = 5;
	const int MATCH_ENDS_WITH       = 6;
	const int MATCH_NOT_BEGINS_WITH = 7;
	const int MATCH_NOT_ENDS_WITH   = 8;
	const int MATCH_NOT_REGEX       = 9;
	const int MATCH_IS_ABOVE        = 10;
	const int MATCH_IS_NOT_ABOVE    = 11;
	const int MATCH_IS_BELOW        = 12;
	const int MATCH_IS_NOT_BELOW    = 13;

	const int CONDITION_OR          = 1;
	const int CONDITION_AND         = 2;

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