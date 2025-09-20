#pragma once
#include <iostream>
#include "Utils_Borja.h"

extern bool devMode;

extern std::string settingsFilePath;
extern std::string gameTitle;

extern bool isFullscreen;

extern float backgroundMusicLoopTimerLimit;
extern float backgroundMusicLoopTimer;

extern int currentLevel;
extern int currentScore;

extern bool isGamePaused;

namespace spr {

	extern rend::SpriteData defaultPaddleTexture;

	extern rend::SpriteData fastPaddleTexture;
	extern rend::SpriteData slowPaddleTexture;
	extern rend::SpriteData mirrorPaddleTexture;

}