#pragma once
#include <string>
#include "Utils_Borja.h"
#include "MainMenu.h"
#include "Globals.h"
#include "Levels.h"



// Levels Menu Buttons
enum class LButtons
{
	EXIT,
	AMOUNT
};

enum class Levels {
	LEVEL1,
	LEVEL2,
	LEVEL3,
	LEVEL4,
	AMOUNT
};

// Settings Menu Buttons
enum class SButtons
{
	RENDERER,
	FULLSCREEN,
	RESOLUTION,
	USE_POWERS,
	KEY_UP,
	KEY_LEFT,
	KEY_RIGHT,
	APPLY,
	EXIT,
	AMOUNT
};

// EndScreen Menu Buttons
enum class EButtons
{
	NEXT,
	LAST,
	RETRY,
	EXIT,
	AMOUNT
};

// Credits Menu Buttons
enum class CButtons
{
	EXIT,
	AMOUNT
};

//Gameplay buttons
enum class PButtons {
	PAUSE,
	RETURN,
	RETRY,
	EXIT,
	AMOUNT
};

void LoadSettings();
void SaveSettings();
void LoadDefaultFiles();

void BackgroundMusicManager(rend::AudioData& music);

void InitMouse(btn::Button& mouse);
void DeInitMouse(btn::Button& mouse);

void InitSettingsContext(btn::Container& container, btn::Button buttons[]);
void InitEndScreenContext(btn::Container& container, btn::Button buttons[]);
void InitCreditsContext(btn::Container& container, btn::Button buttons[]);
void InitLevelsContext(btn::Container& container, btn::Container& gridContainer, btn::Button buttons[], btn::Button gridButtons[]);

void InitPlayContext(btn::Container& playContainer, btn::Button playButtons[]);

void MouseUpdate(btn::Button& mouse);

void LevelsUpdate(btn::Container& container, btn::Container& gridContainer, btn::Button levelsButtons[], btn::Button gridButtons[], SubMenus& subMenu, GameStates& gameState);
void SettingsUpdate(btn::Button settingsButtons[], SubMenus& subMenu);
void EndScreenUpdate(btn::Button endScreenButtons[], SubMenus& subMenu, GameStates& gameState, lvl::LevelData& activeLevel);
void CreditsUpdate(btn::Button creditsButtons[], SubMenus& subMenu);

void PlayInputUpdate(lvl::LevelData& levelData);
void PlayUpdate(btn::Container& playContainer, btn::Button playButtons[], SubMenus& subMenu, GameStates& gameState, lvl::LevelData& activeLevel);

void MouseDraw(btn::Button mouse);

void LevelsDraw(btn::Container& container, btn::Container& gridContainer, btn::Button buttons[], btn::Button gridButtons[]);
void SettingsDraw(btn::Container settingsContainer,btn::Button settingsButtons[]);
void EndScreenDraw(btn::Container endScreenContainer,btn::Button endScreenButtons[]);
void CreditsDraw(btn::Container creditsContainer,btn::Button creditsButtons[]);

void PlayDraw(btn::Container& playContainer, btn::Button playButtons[], lvl::LevelData& levelData);

void PlaySounds(lvl::LevelData& levelData);

void LoadLevel(lvl::LevelData& levelData);
void SaveLevel(lvl::LevelData& levelData);
void InitLevel(lvl::LevelData& levelData);
void ResetLevel(lvl::LevelData& levelData);

void PowerManager(lvl::LevelData& levelData);