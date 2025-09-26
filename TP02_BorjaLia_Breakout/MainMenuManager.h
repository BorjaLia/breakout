#pragma once
#include <string>
#include "Utils_Borja.h"
#include "Globals.h"
#include "Levels.h"

// Main Menu Buttons
enum class MMButtons
{
	PLAY,
	SETTINGS,
	CREDITS,
	EXIT,
	AMOUNT
};

void InitMainMenuContext(btn::Container& container, btn::Button buttons[]);
void MainMenuUpdate(btn::Button mainMenuButtons[], SubMenus& subMenu);
void MainMenuDraw(btn::Container mainMenuContainer, btn::Button mainMenuButtons[]);
