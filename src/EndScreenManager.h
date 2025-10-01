#pragma once
#include <string>
#include "Utils_Borja.h"
#include "Globals.h"
#include "Levels.h"

// EndScreen Menu Buttons
enum class EButtons
{
	NEXT,
	LAST,
	RETRY,
	EXIT,
	AMOUNT
};

void InitEndScreenContext(btn::Container& container, btn::Button buttons[]);
void EndScreenUpdate(btn::Button endScreenButtons[], SubMenus& subMenu, GameStates& gameState, lvl::LevelData& activeLevel);
void EndScreenDraw(btn::Container endScreenContainer, btn::Button endScreenButtons[]);
