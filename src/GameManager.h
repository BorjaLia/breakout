#pragma once
#include <string>
#include "Utils_Borja.h"
#include "MainMenuManager.h"
#include "SettingsManager.h"
#include "LevelMenuManager.h"
#include "GamePlayManager.h"
#include "EndScreenManager.h"
#include "CreditsManager.h"
#include "Globals.h"
#include "Levels.h"

void LoadDefaultFiles();

void BackgroundMusicManager(rend::AudioData& music);
void BackgroundOverlayColorRandomizer();

void InitMouse(btn::Button& mouse);
void DeInitMouse(btn::Button& mouse);
void MouseUpdate(btn::Button& mouse);
void MouseDraw(btn::Button mouse);