#include "Globals.h"

bool shouldReset = true;

rend::GraphicsLib sett::graphics = (rend::GraphicsLib)0;

bool sett::fullscreen = 0;
vec::Vector2 sett::resolution = {1920,1080};

bool sett::usePowers = 1;

ctrl::Key sett::keyUp = (ctrl::Key)87;
ctrl::Key sett::keyLeft = (ctrl::Key)65;
ctrl::Key sett::keyRight = (ctrl::Key)68;

bool sett::changingKeyUp = false;
bool sett::changingKeyLeft = false;
bool sett::changingKeyRight = false;

bool devMode = false;

std::string settingsFilePath = "config/Settings.txt";
std::string gameTitle = "Breakout!";

bool isFullscreen = false;

float backgroundMusicLoopTimerLimit = 160.0f;
float backgroundMusicLoopTimer = backgroundMusicLoopTimerLimit;

int currentLevel = 1;
int currentScore = 0;

float levelTimer = 0;

float pwr::largeMultiplier = 1.5f;
float pwr::comboMultiplier = 2.0f;

float pwr::largePowerTimerLimit = 10;
float pwr::mirrorPowerTimerLimit = 10;
float pwr::homingPowerTimerLimit = 10;
float pwr::comboPowerTimerLimit = 10;

float pwr::largePowerTimer = largePowerTimerLimit;
float pwr::mirrorPowerTimer = mirrorPowerTimerLimit;
float pwr::homingPowerTimer = homingPowerTimerLimit;
float pwr::comboPowerTimer = comboPowerTimerLimit;

bool pwr::multiplyPowerActivation = false;

bool pwr::isLargePowerActive = false;
bool pwr::isMirrorPowerActive = false;
bool pwr::isHomingPowerActive = false;
bool pwr::isComboPowerActive = false;
bool pwr::isMultiplyPowerActive = false;

bool pwr::isLargePowerActiveChange = false;
bool pwr::isMirrorPowerActiveChange = false;
bool pwr::isHomingPowerActiveChange = false;
bool pwr::isComboPowerActiveChange = false;
bool pwr::isMultiplyPowerActiveChange = false;

bool pwr::isLargePowerDeActiveChange = false;
bool pwr::isMirrorPowerDeActiveChange = false;
bool pwr::isHomingPowerDeActiveChange = false;
bool pwr::isComboPowerDeActiveChange = false;
bool pwr::isMultiplyPowerDeActiveChange = false;

bool isGamePaused = false;

int minBallAngle = -60;
int maxBallAngle = 60;

rend::SpriteData spr::defaultPaddleTexture = {};

rend::SpriteData blk::normalTexture;
rend::SpriteData blk::largeTexture;
rend::SpriteData blk::mirrorTexture;
rend::SpriteData blk::homingTexture;
rend::SpriteData blk::multiplyTexture;
rend::SpriteData blk::comboTexture;

rend::SpriteData blk::fullTexture;
rend::SpriteData blk::mediumTexture;
rend::SpriteData blk::depletedTexture;

rend::AudioData blk::blockHitSound;
rend::AudioData blk::blockBrokenSound;
rend::AudioData blk::blockBrokenPowerSound;

rend::SpriteData menu::playButtonTexture;
rend::SpriteData menu::playButtonHoveredTexture;
rend::SpriteData menu::settingsButtonTexture;
rend::SpriteData menu::settingsButtonHoveredTexture;
rend::SpriteData menu::creditsButtonTexture;
rend::SpriteData menu::creditsButtonHoveredTexture;
rend::SpriteData menu::exitButtonTexture;
rend::SpriteData menu::exitButtonHoveredTexture;
rend::SpriteData menu::applyButtonTexture;
rend::SpriteData menu::applyButtonHoveredTexture;

void InitLocalDefaults()
{

	//drw::InitSpriteData(spr::defaultPaddleTexture);


	//drw::InitSpriteData(blk::normalTexture);
	//drw::InitSpriteData(blk::largeTexture);
	//drw::InitSpriteData(blk::smallTexture);
	//drw::InitSpriteData(blk::fastTexture);
	//drw::InitSpriteData(blk::slowTexture);
	//drw::InitSpriteData(blk::mirrorTexture);

	//drw::InitSpriteData(blk::fullTexture);
	//drw::InitSpriteData(blk::mediumTexture);
	//drw::InitSpriteData(blk::depletedTexture);

	blk::blockHitSound.file = "res/audio/ButtonClick.wav";
	blk::blockBrokenSound.file = "res/audio/ButtonClick.wav";
	blk::blockBrokenPowerSound.file = "res/audio/ButtonClick.wav";

	snd::Init(blk::blockHitSound);
	snd::Init(blk::blockBrokenSound);
	snd::Init(blk::blockBrokenPowerSound);

	menu::playButtonTexture.file = "res/sprites/playButtonTexture.png";
	menu::playButtonHoveredTexture.file = "res/sprites/playButtonHoverTexture.png";
	menu::settingsButtonTexture.file = "res/sprites/settingsButtonTexture.png";
	menu::settingsButtonHoveredTexture.file = "res/sprites/settingsButtonHoverTexture.png";
	menu::creditsButtonTexture.file = "res/sprites/creditsButtonTexture.png";
	menu::creditsButtonHoveredTexture.file = "res/sprites/creditsButtonHoverTexture.png";
	menu::exitButtonTexture.file = "res/sprites/exitButtonTexture.png";
	menu::exitButtonHoveredTexture.file = "res/sprites/exitButtonHoverTexture.png";
	menu::applyButtonTexture.file = "res/sprites/applyButtonTexture.png";
	menu::applyButtonHoveredTexture.file = "res/sprites/applyButtonHoverTexture.png";

	drw::InitSpriteData(menu::playButtonTexture);
	drw::InitSpriteData(menu::playButtonHoveredTexture);
	drw::InitSpriteData(menu::settingsButtonTexture);
	drw::InitSpriteData(menu::settingsButtonHoveredTexture);
	drw::InitSpriteData(menu::creditsButtonTexture);
	drw::InitSpriteData(menu::creditsButtonHoveredTexture);
	drw::InitSpriteData(menu::exitButtonTexture);
	drw::InitSpriteData(menu::exitButtonHoveredTexture);
	drw::InitSpriteData(menu::applyButtonTexture);
	drw::InitSpriteData(menu::applyButtonHoveredTexture);
}

void DeInitLocalDefaults()
{
	/*drw::DeInitSpriteData(spr::defaultPaddleTexture);

	drw::DeInitSpriteData(blk::normalTexture);
	drw::DeInitSpriteData(blk::largeTexture);
	drw::DeInitSpriteData(blk::smallTexture);
	drw::DeInitSpriteData(blk::fastTexture);
	drw::DeInitSpriteData(blk::slowTexture);
	drw::DeInitSpriteData(blk::mirrorTexture);

	drw::DeInitSpriteData(blk::fullTexture);
	drw::DeInitSpriteData(blk::mediumTexture);
	drw::DeInitSpriteData(blk::depletedTexture);

	snd::DeInit(blk::blockHitSound);
	snd::DeInit(blk::blockBrokenSound);
	snd::DeInit(blk::blockBrokenPowerSound);*/

	drw::DeInitSpriteData(menu::playButtonTexture);
	drw::DeInitSpriteData(menu::playButtonHoveredTexture);
	drw::DeInitSpriteData(menu::settingsButtonTexture);
	drw::DeInitSpriteData(menu::settingsButtonHoveredTexture);
	drw::DeInitSpriteData(menu::creditsButtonTexture);
	drw::DeInitSpriteData(menu::creditsButtonHoveredTexture);
	drw::DeInitSpriteData(menu::exitButtonTexture);
	drw::DeInitSpriteData(menu::exitButtonHoveredTexture);
	drw::DeInitSpriteData(menu::applyButtonTexture);
	drw::DeInitSpriteData(menu::applyButtonHoveredTexture);
}
