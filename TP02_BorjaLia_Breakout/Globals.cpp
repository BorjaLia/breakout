#include "Globals.h"

bool devMode = false;

std::string settingsFilePath = "config/Settings.txt";
std::string gameTitle = "Breakout!";

bool isFullscreen = false;

float backgroundMusicLoopTimerLimit = 160.0f;
float backgroundMusicLoopTimer = backgroundMusicLoopTimerLimit;

rend::SpriteData spr::defaultPaddleTexture = {};