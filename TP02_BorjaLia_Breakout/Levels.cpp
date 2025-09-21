#include "Levels.h"

void lvl::LoadLevelData(LevelData& levelData)
{
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
