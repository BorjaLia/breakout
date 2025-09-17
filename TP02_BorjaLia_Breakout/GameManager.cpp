#include "GameManager.h"

void LoadSettings()
{
	rend::activeGraphics = (rend::GraphicsLib)stoi(utl::SearchInFile(settingsFilePath.c_str(), "graphics"));
	rend::nextGraphics = rend::activeGraphics;

	rend::windowSize.x = stoi(utl::SearchInFile(settingsFilePath.c_str(), "resolution_width"));
	rend::windowSize.y = stoi(utl::SearchInFile(settingsFilePath.c_str(), "resolution_height"));
}

void LoadDefaultFiles()
{
	rend::defaultContainerTexture.file = "res/sprites/Background.png";

	rend::defaultButtonMainTexture.file = "res/sprites/NoTexture.png";
	rend::defaultButtonHoveredTexture.file = "res/sprites/NoTexture.png";

	rend::defaultButtonClickDownSound.file = "res/audio/ButtonClick.wav";
	rend::defaultButtonClickUpSound.file = "res/audio/ButtonClick.wav";
	rend::defaultButtonHoverSound.file = "res/audio/ButtonHover.wav";
}

void InitMainMenuContext(btn::Container& container, btn::Button buttons[])
{
	container.pos = { 0.5,0.5 };
	container.size = { 1.8,1.1 };
	container.isRendered = true;
	container.useTexture = true;
	container.texture = rend::defaultContainerTexture;

	btn::Init(container);

	for (int b = 0; b < (int)MMButtons::AMOUNT; b++)
	{
		buttons[b].signalTimerLimit = 0.1f;
		buttons[b].size = { 0.2,0.1 };
		buttons[b].clickedOffset = { -0.4,0 };
		buttons[b].useText = false;
		buttons[b].useSprite = true;
	}


	buttons[(int)MMButtons::PLAY].text = "Play";
	buttons[(int)MMButtons::PLAY].pos = { 0.1,0.65 };

	btn::Init(buttons[(int)MMButtons::PLAY], container, true);

	buttons[(int)MMButtons::PLAY].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)MMButtons::PLAY].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)MMButtons::PLAY].hoveredSound = rend::defaultButtonHoverSound;

	buttons[(int)MMButtons::PLAY].mainTexture.file = "res/sprites/playButtonTexture.png";
	buttons[(int)MMButtons::PLAY].hoveredTexture.file = "res/sprites/playButtonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)MMButtons::PLAY].mainTexture);
	drw::InitSpriteData(buttons[(int)MMButtons::PLAY].hoveredTexture);

	buttons[(int)MMButtons::SETTINGS].text = "Settings";
	buttons[(int)MMButtons::SETTINGS].pos = { 0.1,0.5 };

	btn::Init(buttons[(int)MMButtons::SETTINGS], container, true);

	buttons[(int)MMButtons::SETTINGS].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)MMButtons::SETTINGS].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)MMButtons::SETTINGS].hoveredSound = rend::defaultButtonHoverSound;

	buttons[(int)MMButtons::SETTINGS].mainTexture.file = "res/sprites/settingsButtonTexture.png";
	buttons[(int)MMButtons::SETTINGS].hoveredTexture.file = "res/sprites/settingsButtonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)MMButtons::SETTINGS].mainTexture);
	drw::InitSpriteData(buttons[(int)MMButtons::SETTINGS].hoveredTexture);



	buttons[(int)MMButtons::CREDITS].text = "Credits";
	buttons[(int)MMButtons::CREDITS].pos = { 0.1,0.35 };

	btn::Init(buttons[(int)MMButtons::CREDITS], container, true);

	buttons[(int)MMButtons::CREDITS].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)MMButtons::CREDITS].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)MMButtons::CREDITS].hoveredSound = rend::defaultButtonHoverSound;

	buttons[(int)MMButtons::CREDITS].mainTexture.file = "res/sprites/creditsButtonTexture.png";
	buttons[(int)MMButtons::CREDITS].hoveredTexture.file = "res/sprites/creditsButtonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)MMButtons::CREDITS].mainTexture);
	drw::InitSpriteData(buttons[(int)MMButtons::CREDITS].hoveredTexture);



	buttons[(int)MMButtons::EXIT].text = "Exit";
	buttons[(int)MMButtons::EXIT].pos = { 0.1,0.2 };

	btn::Init(buttons[(int)MMButtons::EXIT], container, true);

	buttons[(int)MMButtons::EXIT].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)MMButtons::EXIT].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)MMButtons::EXIT].hoveredSound = rend::defaultButtonHoverSound;

	buttons[(int)MMButtons::EXIT].mainTexture.file = "res/sprites/exitButtonTexture.png";
	buttons[(int)MMButtons::EXIT].hoveredTexture.file = "res/sprites/exitButtonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)MMButtons::EXIT].mainTexture);
	drw::InitSpriteData(buttons[(int)MMButtons::EXIT].hoveredTexture);

}

void InitSettingsContext(btn::Container& container, btn::Button buttons[])
{
	container.pos = { 0.5,0.5 };
	container.size = { 1.8,1.1 };
	container.isRendered = true;
	container.useTexture = true;
	container.texture = rend::defaultContainerTexture;

	btn::Init(container);

	for (int b = 0; b < (int)SButtons::AMOUNT; b++)
	{
		buttons[b].signalTimerLimit = 0.1f;
		buttons[b].size = { 0.2,0.1 };
		buttons[b].clickedOffset = { -0.4,0 };
		buttons[b].useText = false;
		buttons[b].useSprite = true;
	}

	buttons[(int)SButtons::RENDERER].text = "Renderer";
	buttons[(int)SButtons::RENDERER].pos = { 0.8,0.8 };
	buttons[(int)SButtons::RENDERER].clickedOffset = { 0,-0.1f };
	buttons[(int)SButtons::RENDERER].useText = true;
	buttons[(int)SButtons::RENDERER].textColor = WHITE;

	btn::Init(buttons[(int)SButtons::RENDERER], container, true);

	buttons[(int)SButtons::RENDERER].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)SButtons::RENDERER].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)SButtons::RENDERER].hoveredSound = rend::defaultButtonHoverSound;

	buttons[(int)SButtons::RENDERER].mainTexture.file = "res/sprites/buttonTexture.png";
	buttons[(int)SButtons::RENDERER].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)SButtons::RENDERER].mainTexture);
	drw::InitSpriteData(buttons[(int)SButtons::RENDERER].hoveredTexture);


	buttons[(int)SButtons::EXIT].text = "Exit";
	buttons[(int)SButtons::EXIT].pos = { 0.1,0.2 };

	btn::Init(buttons[(int)SButtons::EXIT], container, true);

	buttons[(int)SButtons::EXIT].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)SButtons::EXIT].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)SButtons::EXIT].hoveredSound = rend::defaultButtonHoverSound;

	buttons[(int)SButtons::EXIT].mainTexture.file = "res/sprites/exitButtonTexture.png";
	buttons[(int)SButtons::EXIT].hoveredTexture.file = "res/sprites/exitButtonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)SButtons::EXIT].mainTexture);
	drw::InitSpriteData(buttons[(int)SButtons::EXIT].hoveredTexture);
}

void InitCreditsContext(btn::Container& container, btn::Button buttons[])
{
	container.pos = { 0.5,0.5 };
	container.size = { 1.8,1.1 };
	container.isRendered = true;
	container.useTexture = true;
	container.texture = rend::defaultContainerTexture;

	btn::Init(container);

	for (int b = 0; b < (int)CButtons::AMOUNT; b++)
	{
		buttons[b].signalTimerLimit = 0.1f;
		buttons[b].size = { 0.2,0.1 };
		buttons[b].clickedOffset = { -0.4,0 };
		buttons[b].useText = false;
		buttons[b].useSprite = true;
	}

	buttons[(int)CButtons::EXIT].text = "Exit";
	buttons[(int)CButtons::EXIT].pos = { 0.1,0.2 };

	btn::Init(buttons[(int)CButtons::EXIT], container, true);

	buttons[(int)CButtons::EXIT].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)CButtons::EXIT].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)CButtons::EXIT].hoveredSound = rend::defaultButtonHoverSound;

	buttons[(int)CButtons::EXIT].mainTexture.file = "res/sprites/exitButtonTexture.png";
	buttons[(int)CButtons::EXIT].hoveredTexture.file = "res/sprites/exitButtonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)CButtons::EXIT].mainTexture);
	drw::InitSpriteData(buttons[(int)CButtons::EXIT].hoveredTexture);
}

void InitLevelsContext(btn::Container& container, btn::Button buttons[])
{
	container.pos = { 0.5,0.5 };
	container.size = { 1.8,1.1 };
	container.isRendered = true;
	container.useTexture = true;
	container.texture = rend::defaultContainerTexture;

	btn::Init(container);

	for (int b = 0; b < (int)LButtons::AMOUNT; b++)
	{
		buttons[b].signalTimerLimit = 0.1f;
		buttons[b].size = { 0.2,0.1 };
		buttons[b].clickedOffset = { -0.4,0 };
		buttons[b].useText = false;
		buttons[b].useSprite = true;
	}

	buttons[(int)LButtons::EXIT].text = "Exit";
	buttons[(int)LButtons::EXIT].pos = { 0.1,0.2 };

	btn::Init(buttons[(int)LButtons::EXIT], container, true);

	buttons[(int)LButtons::EXIT].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)LButtons::EXIT].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)LButtons::EXIT].hoveredSound = rend::defaultButtonHoverSound;

	buttons[(int)LButtons::EXIT].mainTexture.file = "res/sprites/exitButtonTexture.png";
	buttons[(int)LButtons::EXIT].hoveredTexture.file = "res/sprites/exitButtonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)LButtons::EXIT].mainTexture);
	drw::InitSpriteData(buttons[(int)LButtons::EXIT].hoveredTexture);
}

void MainMenuUpdate(btn::Button mainMenuButtons[], SubMenus& subMenu)
{
	btn::UpdateInput(mainMenuButtons, (int)MMButtons::AMOUNT);

	if (mainMenuButtons[(int)MMButtons::PLAY].signal) {
		subMenu = SubMenus::LEVEL_SELECTOR;
	}
	if (mainMenuButtons[(int)MMButtons::SETTINGS].signal) {
		subMenu = SubMenus::SETTINGS;
	}
	if (mainMenuButtons[(int)MMButtons::CREDITS].signal) {
		subMenu = SubMenus::CREDTIS;
	}
	if (mainMenuButtons[(int)MMButtons::EXIT].signal) {
		subMenu = SubMenus::EXIT;
	}
}

void LevelsUpdate(btn::Button levelsButtons[], SubMenus& subMenu, GameStates& gameState)
{
	btn::UpdateInput(levelsButtons, (int)LButtons::AMOUNT);

	if (levelsButtons[(int)LButtons::EXIT].signal) {
		subMenu = SubMenus::MAIN;
	}
}

void SettingsUpdate(btn::Button settingsButtons[], SubMenus& subMenu)
{
	btn::UpdateInput(settingsButtons, (int)SButtons::AMOUNT);

	if (settingsButtons[(int)SButtons::EXIT].signal) {
		subMenu = SubMenus::MAIN;
	}
}

void CreditsUpdate(btn::Button creditsButtons[], SubMenus& subMenu)
{
	btn::UpdateInput(creditsButtons, (int)CButtons::AMOUNT);

	if (creditsButtons[(int)CButtons::EXIT].signal) {
		subMenu = SubMenus::MAIN;
	}
}

void MainMenuDraw(btn::Container mainMenuContainer, btn::Button mainMenuButtons[])
{
}
