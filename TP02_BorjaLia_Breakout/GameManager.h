#pragma once
#include "Utils_Borja.h"
#include "Globals.h"

enum class GameStates {

	MAIN_MENU,
	PLAYING
};

enum class SubMenus {

	MAIN,
	SETTINGS,
	LEVEL_SELECTOR,
	CREDTIS,
	EXIT

};

// Main Menu Buttons
enum class MMButtons
{
	PLAY,
	SETTINGS,
	CREDITS,
	EXIT,
	AMOUNT
};

// Levels Menu Buttons
enum class LButtons
{
	EXIT,
	AMOUNT
};

// Settings Menu Buttons
enum class SButtons
{
	RENDERER,
	APPLY,
	EXIT,
	AMOUNT
};

// Credits Menu Buttons
enum class CButtons
{
	EXIT,
	AMOUNT
};

void LoadSettings();
void LoadDefaultFiles();

void InitMainMenuContext(btn::Container& container,btn::Button buttons[]);
void InitSettingsContext(btn::Container& container, btn::Button buttons[]);
void InitCreditsContext(btn::Container& container, btn::Button buttons[]);
void InitLevelsContext(btn::Container& container, btn::Button buttons[]);

void MainMenuUpdate(btn::Button mainMenuButtons[], SubMenus& subMenu);
void LevelsUpdate(btn::Button levelsButtons[], SubMenus& subMenu, GameStates& gameState);
void SettingsUpdate(btn::Button settingsButtons[], SubMenus& subMenu);
void CreditsUpdate(btn::Button creditsButtons[], SubMenus& subMenu);

void MainMenuDraw(btn::Container mainMenuContainer,btn::Button mainMenuButtons[]);