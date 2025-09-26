#pragma once
#include <string>
#include "Utils_Borja.h"
#include "Globals.h"
#include "Levels.h"

// Levels Menu Buttons
enum class LButtons
{
	EXIT,
	AMOUNT
};

void InitLevelsContext(btn::Container& container, btn::Container& gridContainer, btn::Button buttons[], btn::Button gridButtons[]);
void LevelsUpdate(btn::Container& container, btn::Container& gridContainer, btn::Button levelsButtons[], btn::Button gridButtons[], SubMenus& subMenu, GameStates& gameState);
void LevelsDraw(btn::Container& container, btn::Container& gridContainer, btn::Button buttons[], btn::Button gridButtons[]);
