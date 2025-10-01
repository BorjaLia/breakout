#pragma once
#include <iostream>
#include "Utils_Borja.h"
#include "PowerDrop.h"

enum class GameStates {

	MAIN_MENU,
	PLAYING
};

enum class SubMenus {

	MAIN,
	SETTINGS,
	LEVEL_SELECTOR,
	CREDTIS,
	ENDSCREEN,
	EXIT
};

extern bool changedSettings;

namespace sett{

	extern rend::GraphicsLib graphics;

	extern rend::WindowType windowType;
	extern rend::Resolution resolution;

	extern bool usePowers;

	extern ctrl::Key keyUp;
	extern ctrl::Key keyLeft;
	extern ctrl::Key keyRight;

	extern bool changingKeyUp;
	extern bool changingKeyLeft;
	extern bool changingKeyRight;
}

extern float frameRate;

extern bool devMode;
extern bool devModeChange;

extern std::string settingsFilePath;
extern std::string gameTitle;

extern bool isFullscreen;

extern float backgroundMusicLoopTimerLimit;
extern float backgroundMusicLoopTimer;

extern int currentLevel;
extern int currentScore;

extern float levelTimer;

namespace pwr {

	extern float largeMultiplier;
	extern float comboMultiplier;

	extern float largePowerTimerLimit;
	extern float mirrorPowerTimerLimit;
	extern float homingPowerTimerLimit;
	extern float comboPowerTimerLimit;

	extern float largePowerTimer;
	extern float mirrorPowerTimer;
	extern float homingPowerTimer;
	extern float comboPowerTimer;

	extern bool multiplyPowerActivation;

	extern bool isLargePowerActive;
	extern bool isMirrorPowerActive;
	extern bool isHomingPowerActive;
	extern bool isComboPowerActive;
	extern bool isMultiplyPowerActive;

	extern bool isLargePowerActiveChange;
	extern bool isMirrorPowerActiveChange;
	extern bool isHomingPowerActiveChange;
	extern bool isComboPowerActiveChange;
	extern bool isMultiplyPowerActiveChange;

	extern bool isLargePowerDeActiveChange;
	extern bool isMirrorPowerDeActiveChange;
	extern bool isHomingPowerDeActiveChange;
	extern bool isComboPowerDeActiveChange;
	extern bool isMultiplyPowerDeActiveChange;

	extern float comboPowerMultiplier;
}

extern bool isGamePaused;

extern int minBallAngle;
extern int maxBallAngle;

namespace bg {
	extern Color backgroundOverlayColor;
	extern rend::SpriteData defaultBackgroundOverlayTexture;
}

namespace fg {
	extern Color mainTitlesColor;
}

namespace spr {

	extern rend::SpriteData defaultPaddleTexture;

	extern rend::SpriteData fastPaddleTexture;
	extern rend::SpriteData slowPaddleTexture;
	extern rend::SpriteData mirrorPaddleTexture;

}

namespace pwr {

	extern rend::SpriteData largePowerDropTexture;
	extern rend::SpriteData largePowerIcon;

	extern rend::SpriteData mirrorPowerDropTexture;
	extern rend::SpriteData mirrorPowerIcon;

	extern rend::SpriteData homingPowerDropTexture;
	extern rend::SpriteData homingPowerIcon;

	extern rend::SpriteData comboPowerDropTexture;
	extern rend::SpriteData comboPowerIcon;
}

namespace blk {

	extern	rend::SpriteData normalTexture;
	extern	rend::SpriteData largeTexture;
	extern	rend::SpriteData mirrorTexture;
	extern	rend::SpriteData homingTexture;
	extern	rend::SpriteData multiplyTexture;
	extern	rend::SpriteData comboTexture;

	extern	rend::SpriteData fullTexture;
	extern	rend::SpriteData mediumTexture;
	extern	rend::SpriteData depletedTexture;

	extern rend::AudioData blockHitSound;
	extern rend::AudioData blockBrokenSound;
	extern rend::AudioData blockBrokenPowerSound;
}

namespace menu {

	extern	rend::SpriteData playButtonTexture;
	extern	rend::SpriteData playButtonHoveredTexture;
	extern	rend::SpriteData settingsButtonTexture;
	extern	rend::SpriteData settingsButtonHoveredTexture;
	extern	rend::SpriteData creditsButtonTexture;
	extern	rend::SpriteData creditsButtonHoveredTexture;
	extern	rend::SpriteData exitButtonTexture;
	extern	rend::SpriteData exitButtonHoveredTexture;
	extern	rend::SpriteData applyButtonTexture;
	extern	rend::SpriteData applyButtonHoveredTexture;
}

void InitLocalDefaults();
void DeInitLocalDefaults();