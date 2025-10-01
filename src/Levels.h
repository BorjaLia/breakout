#pragma once

#include "Utils_Borja.h"
#include "Globals.h"
#include "Paddle.h"
#include "Ball.h"
#include "Block.h"


enum class Levels {
	LEVEL1,
	LEVEL2,
	LEVEL3,
	LEVEL4,
	AMOUNT
};

namespace lvl {


	struct LevelData {

		int id = 0;

		int hiScore = 0;
		float bestTime = 0;

		pdl::Paddle paddle;
		bll::Ball ball;

		int blockAmount;

		blk::Block blocks[70];

		int powerDropAmount = 10;
		int availablePowerDrop = 0;
		pwr::PowerDrop powerDrops[10];
	};

	void NextAvailablePowerDrop(LevelData& levelData);
	int BlocksLeft(LevelData levelData);


	void LoadLevel(lvl::LevelData& levelData);
	void SaveLevel(lvl::LevelData& levelData);
	void InitLevel(lvl::LevelData& levelData);
	void ResetLevel(lvl::LevelData& levelData);
}
