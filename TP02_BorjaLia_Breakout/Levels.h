#pragma once

#include "Utils_Borja.h"
#include "Globals.h"
#include "Paddle.h"
#include "Ball.h"
#include "Block.h"

namespace lvl {


	struct LevelData {

		pdl::Paddle paddle;
		bll::Ball ball;

		int blockAmount;

		blk::Block blocks[100];
	};

	void LoadLevelData(LevelData& levelData);
	int BlocksLeft(LevelData levelData);

}
