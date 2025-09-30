#include "Levels.h"

void lvl::NextAvailablePowerDrop(LevelData& levelData)
{
	levelData.availablePowerDrop++;
	if (levelData.availablePowerDrop == levelData.powerDropAmount) {
		levelData.availablePowerDrop = 0;
	}
}

int lvl::BlocksLeft(LevelData levelData)
{
	int remaining = 0;
	for (int b = 0; b < levelData.blockAmount; b++)
	{
		if (levelData.blocks[b].isActive) {
			remaining++;
		}
	}
	return remaining;
}

void lvl::LoadLevel(lvl::LevelData& levelData)
{

	//for (int i = 0; i < 8; i++)
	//{
	//	levelData.blocks[i].pos = { 0.5f + ((float)((i - levelData.blockAmount / 2) * levelData.blocks[i].size.x) * 1.5f), 0.7f };
	//	//levelData.blocks[i].pos = { 0.5f + ((float)(i- levelData.blockAmount/2.0f) / 10.0f),0.7f };
	//	if (levelData.blockAmount % 2 == 0) {
	//		levelData.blocks[i].pos.x += levelData.blocks[i].size.x / 1.33f;
	//	}
	//}

	pwr::largePowerTimer = pwr::largePowerTimerLimit;
	pwr::mirrorPowerTimer = pwr::mirrorPowerTimerLimit;
	pwr::homingPowerTimer = pwr::homingPowerTimerLimit;
	pwr::comboPowerTimer = pwr::comboPowerTimerLimit;

	pwr::multiplyPowerActivation = false;

	pwr::isLargePowerActive = false;
	pwr::isMirrorPowerActive = false;
	pwr::isHomingPowerActive = false;
	pwr::isComboPowerActive = false;
	pwr::isMultiplyPowerActive = false;

	pwr::isLargePowerActiveChange = false;
	pwr::isMirrorPowerActiveChange = false;
	pwr::isHomingPowerActiveChange = false;
	pwr::isComboPowerActiveChange = false;
	pwr::isMultiplyPowerActiveChange = false;

	pwr::isLargePowerDeActiveChange = false;
	pwr::isMirrorPowerDeActiveChange = false;
	pwr::isHomingPowerDeActiveChange = false;
	pwr::isComboPowerDeActiveChange = false;
	pwr::isMultiplyPowerDeActiveChange = false;

	for (int i = 0; i < levelData.powerDropAmount; i++)
	{
		pwr::Reset(levelData.powerDrops[i]);
	}

	std::string levelFile = "data/level.txt";

	levelData.blockAmount = 0;
	int m = 0;

	switch ((Levels)(currentLevel - 1))
	{
	case Levels::LEVEL1: {

		levelData.id = 1;

		levelFile = "data/level1.txt";

		levelData.paddle = pdl::Paddle();
		levelData.ball = bll::Ball();

		levelData.blockAmount = 24;

		for (int i = 0; i < 24; i++)
		{
			if (m >= 8) {
				m = 0;
			}
			levelData.blocks[i].isActive = true;
			levelData.blocks[i].heldPowerType = pwr::PowerType::NONE;

			levelData.blocks[i].color = LIME;
			levelData.blocks[i].playSound = false;
			levelData.blocks[i].activeSound = blk::blockHitSound;

			levelData.blocks[i].pos = { 0.5f + ((float)((m - 8 / 2) * levelData.blocks[i].size.x) * 1.5f), 0.6f };
			levelData.blocks[i].pos.x += levelData.blocks[i].size.x / 1.33f;
			levelData.blocks[i].heldPowerType = pwr::PowerType::MIRROR;

			if (i >= 8) {
				levelData.blocks[i].heldPowerType = pwr::PowerType::LARGE;
				levelData.blocks[i].pos.y += 0.15f;
				levelData.blocks[i].color = PINK;
			}
			if (i >= 16) {
				levelData.blocks[i].heldPowerType = pwr::PowerType::HOMING;
				levelData.blocks[i].pos.y += 0.15f;
				levelData.blocks[i].color = YELLOW;
			}
			m++;
		}

		//levelData.blocks[3].heldPowerType = pwr::PowerType::HOMING;

		break;
	}
	case Levels::LEVEL2: {

		levelData.id = 2;

		levelFile = "data/level2.txt";

		levelData.paddle = pdl::Paddle();
		levelData.ball = bll::Ball();

		levelData.blockAmount = 38;

		for (int i = 0; i < 24; i++)
		{
			if (m >= 8) {
				m = 0;
			}

			levelData.blocks[i].maxHitPoints = 2;
			levelData.blocks[i].color = WHITE;
			levelData.blocks[i].pos = { 0.5f + ((float)((m - 8 / 2) * levelData.blocks[i].size.x) * 1.5f), 0.45f };
			levelData.blocks[i].pos.x += levelData.blocks[i].size.x / 1.33f;

			if (i >= 8) {
				levelData.blocks[i].pos.y += 0.175f;
			}
			if (i >= 16) {
				levelData.blocks[i].pos.y += 0.175f;
			}
			m++;
		}
		m = 0;
		for (int i = 24; i < levelData.blockAmount; i++)
		{
			if (m >= 7) {
				m = 0;
			}

			levelData.blocks[i].maxHitPoints = 1;
			levelData.blocks[i].color = WHITE;
			levelData.blocks[i].pos = { 0.5f + ((float)((m - 7 / 2) * levelData.blocks[i].size.x) * 1.5f), 0.525f };
			//levelData.blocks[i].pos.x += levelData.blocks[i].size.x;

			if (i >= 31) {
				levelData.blocks[i].pos.y += 0.175f;
			}
			m++;
		}

		break;
	}
	case Levels::LEVEL3: {

		levelData.id = 3;

		levelFile = "data/level3.txt";

		levelData.paddle = pdl::Paddle();
		levelData.ball = bll::Ball();

		levelData.blockAmount = 1;

		levelData.blocks[0].pos = { 0.5,0.5 };
		levelData.blocks[0].size = { 0.3,0.2 };
		levelData.blocks[0].maxHitPoints = 1;


		break;
	}
	case Levels::LEVEL4: {
		levelData.id = 4;

		levelFile = "data/level4.txt";
		break;
	}
	case Levels::AMOUNT:
		break;
	default:
		break;
	}

	if (!sett::usePowers) {
		for (int i = 0; i < levelData.blockAmount; i++)
		{
			levelData.blocks[i].heldPowerType = pwr::PowerType::NONE;
		}
	}

	levelData.hiScore = stoi(utl::SearchInFile(levelFile.c_str(), "best_score"));
	levelData.bestTime = stoi(utl::SearchInFile(levelFile.c_str(), "best_time"));

	InitLevel(levelData);

	levelTimer = 0;
}

void lvl::SaveLevel(lvl::LevelData& levelData)
{
	std::string levelFile = "data/level.txt";

	switch ((Levels)(levelData.id - 1))
	{
	case Levels::LEVEL1: {
		levelFile = "data/level1.txt";

		levelData.hiScore = currentScore;
		levelData.bestTime = levelTimer;
		break;
	}
	case Levels::LEVEL2: {
		levelFile = "data/level2.txt";

		levelData.hiScore = currentScore;
		levelData.bestTime = levelTimer;
		break;
	}
	case Levels::LEVEL3: {
		levelFile = "data/level3.txt";

		levelData.hiScore = currentScore;
		levelData.bestTime = levelTimer;
		break;
	}
	case Levels::LEVEL4: {
		levelFile = "data/level4.txt";

		levelData.hiScore = currentScore;
		levelData.bestTime = levelTimer;
		break;
	}
	case Levels::AMOUNT:
		break;

	default:
		break;
	}
	utl::SaveToFile(levelFile.c_str(), "best_score", currentScore);
	utl::SaveToFile(levelFile.c_str(), "best_time", levelTimer);
}

void lvl::InitLevel(lvl::LevelData& levelData)
{

	pdl::Reset(levelData.paddle);
	bll::Reset(levelData.ball);
	pdl::Init(levelData.paddle);
	bll::Init(levelData.ball);


	for (int i = 0; i < levelData.blockAmount; i++)
	{
		blk::Init(levelData.blocks[i]);
	}
}

void lvl::ResetLevel(lvl::LevelData& levelData) {
	pdl::Reset(levelData.paddle);
	bll::Reset(levelData.ball);

	for (int i = 0; i < levelData.blockAmount; i++)
	{
		blk::Reset(levelData.blocks[i]);
	}
	LoadLevel(levelData);
}