#pragma once
#include <string>
#include "Utils_Borja.h"
#include "Globals.h"
#include "Levels.h"
#include "PowerDrop.h"

//Gameplay buttons
enum class PButtons {
	PAUSE,
	RETURN,
	RETRY,
	EXIT,
	AMOUNT
};

void InitPlayContext(btn::Container& playContainer, btn::Button playButtons[]);
void PlayInputUpdate(lvl::LevelData& levelData);
void PlayUpdate(btn::Container& playContainer, btn::Button playButtons[], SubMenus& subMenu, GameStates& gameState, lvl::LevelData& activeLevel);
void PlayDraw(btn::Container& playContainer, btn::Button playButtons[], lvl::LevelData& levelData);
void PlaySounds(lvl::LevelData& levelData);

void PowerManager(lvl::LevelData& levelData);