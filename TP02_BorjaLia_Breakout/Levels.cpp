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
