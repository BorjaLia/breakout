#pragma once
#include "Utils_Borja.h"
#include "Globals.h"
#include "Block.h"

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
void SaveSettings(int savedGraphics, vec::Vector2 savedWindowSize, int savedIsFullscreen);
void LoadDefaultFiles();

void BackgroundMusicManager(rend::AudioData& music);

void InitMouse(btn::Button& mouse);

void InitMainMenuContext(btn::Container& container,btn::Button buttons[]);
void InitSettingsContext(btn::Container& container, btn::Button buttons[]);
void InitCreditsContext(btn::Container& container, btn::Button buttons[]);
void InitLevelsContext(btn::Container& container, btn::Container& gridContainer, btn::Button buttons[], btn::Button gridButtons[]);

void MouseUpdate(btn::Button& mouse);

void MainMenuUpdate(btn::Button mainMenuButtons[], SubMenus& subMenu);
void LevelsUpdate(btn::Container& container, btn::Container& gridContainer, btn::Button buttons[], btn::Button gridButtons[], GameStates& gameState);
void SettingsUpdate(btn::Button settingsButtons[], SubMenus& subMenu);
void CreditsUpdate(btn::Button creditsButtons[], SubMenus& subMenu);

void MouseDraw(btn::Button mouse);

void MainMenuDraw(btn::Container mainMenuContainer,btn::Button mainMenuButtons[]);
void LevelsDraw(btn::Container levelsContainer,btn::Button levelsButtons[]);
void SettingsDraw(btn::Container settingsContainer,btn::Button settingsButtons[]);
void CreditsDraw(btn::Container creditsContainer,btn::Button creditsButtons[]);


void LoadLevel();