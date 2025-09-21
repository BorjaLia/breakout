#include "Globals.h"

bool devMode = false;

std::string settingsFilePath = "config/Settings.txt";
std::string gameTitle = "Breakout!";

bool isFullscreen = false;

float backgroundMusicLoopTimerLimit = 160.0f;
float backgroundMusicLoopTimer = backgroundMusicLoopTimerLimit;

int currentLevel = 1;
int currentScore = 0;

float levelTimer = 0;

bool isGamePaused = false;

rend::SpriteData spr::defaultPaddleTexture = {};


rend::SpriteData blk::normalTexture;
rend::SpriteData blk::largeTexture;
rend::SpriteData blk::smallTexture;
rend::SpriteData blk::fastTexture;
rend::SpriteData blk::slowTexture;
rend::SpriteData blk::mirrorTexture;

rend::SpriteData blk::fullTexture;
rend::SpriteData blk::mediumTexture;
rend::SpriteData blk::depletedTexture;

rend::AudioData blk::blockHitSound;
rend::AudioData blk::blockBrokenSound;
rend::AudioData blk::blockBrokenPowerSound;