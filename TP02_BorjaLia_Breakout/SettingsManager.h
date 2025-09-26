#pragma once
#include <string>
#include "Utils_Borja.h"
#include "Globals.h"
#include "Levels.h"

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

void LoadSettings();
void SaveSettings();

void InitSettingsContext(btn::Container& container, btn::Button buttons[]);
void SettingsUpdate(btn::Button settingsButtons[], SubMenus& subMenu);
void SettingsDraw(btn::Container settingsContainer, btn::Button settingsButtons[]);
