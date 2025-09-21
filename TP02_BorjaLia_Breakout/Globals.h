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

extern float levelTimer;

extern bool isGamePaused;

namespace spr {

	extern rend::SpriteData defaultPaddleTexture;

	extern rend::SpriteData fastPaddleTexture;
	extern rend::SpriteData slowPaddleTexture;
	extern rend::SpriteData mirrorPaddleTexture;

}

namespace blk {

	extern	rend::SpriteData normalTexture;
	extern	rend::SpriteData largeTexture;
	extern	rend::SpriteData smallTexture;
	extern	rend::SpriteData fastTexture;
	extern	rend::SpriteData slowTexture;
	extern	rend::SpriteData mirrorTexture;

	extern	rend::SpriteData fullTexture;
	extern	rend::SpriteData mediumTexture;
	extern	rend::SpriteData depletedTexture;

	extern rend::AudioData blockHitSound;
	extern rend::AudioData blockBrokenSound;
	extern rend::AudioData blockBrokenPowerSound;

}