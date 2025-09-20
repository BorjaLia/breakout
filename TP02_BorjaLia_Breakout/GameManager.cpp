#include "GameManager.h"

void LoadSettings()
{
	rend::activeGraphics = (rend::GraphicsLib)stoi(utl::SearchInFile(settingsFilePath.c_str(), "graphics"));
	rend::nextGraphics = rend::activeGraphics;

	rend::windowSize.x = stoi(utl::SearchInFile(settingsFilePath.c_str(), "resolution_width"));
	rend::windowSize.y = stoi(utl::SearchInFile(settingsFilePath.c_str(), "resolution_height"));

	isFullscreen = stoi(utl::SearchInFile(settingsFilePath.c_str(), "fullscreen"));
}

void SaveSettings() {

}

void LoadDefaultFiles()
{
	rend::defaultContainerTexture.file = "res/sprites/Background4.png";

	rend::defaultButtonMainTexture.file = "res/sprites/NoTexture.png";
	rend::defaultButtonHoveredTexture.file = "res/sprites/NoTexture.png";

	rend::defaultButtonClickDownSound.file = "res/audio/ButtonClick.wav";
	rend::defaultButtonClickUpSound.file = "res/audio/ButtonClick.wav";
	rend::defaultButtonHoverSound.file = "res/audio/ButtonHover.wav";

	rend::defaultFont.file = "res/fonts/ReemKufiFun-Regular.ttf";
}

void BackgroundMusicManager(rend::AudioData& music)
{
	backgroundMusicLoopTimer += rend::deltaTime;

	if (backgroundMusicLoopTimer > backgroundMusicLoopTimerLimit) {
		snd::Stop(music);
		snd::Play(music);
		backgroundMusicLoopTimer = 0;
	}

}

void InitMouse(btn::Button& mouse)
{
	mouse.signalTimerLimit = 0.1f;
	mouse.size = { 0.03,0.03 };
	mouse.offset = { 0.01,-0.01 };
	mouse.clickedOffset = { -0.1,0 };
	mouse.useText = false;
	mouse.useSprite = true;
	
	mouse.text = "Mouse";
	mouse.pos = { 0.1,0.65 };

	btn::Init(mouse);

	mouse.mainTexture.file = "res/sprites/mouseTexture.png";
	mouse.hoveredTexture.file = "res/sprites/mouseTexture.png";
	drw::InitSpriteData(mouse.mainTexture);
	drw::InitSpriteData(mouse.hoveredTexture);
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
		buttons[b].isActive = true;
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
		buttons[b].isActive = true;
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


	buttons[(int)SButtons::APPLY].text = "Apply";
	buttons[(int)SButtons::APPLY].pos = { 0.9,0.2 };
	buttons[(int)SButtons::APPLY].clickedOffset = { 0.4,0 };
	buttons[(int)SButtons::APPLY].useText = true;
	buttons[(int)SButtons::APPLY].textColor = WHITE;

	btn::Init(buttons[(int)SButtons::APPLY], container, true);

	buttons[(int)SButtons::APPLY].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)SButtons::APPLY].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)SButtons::APPLY].hoveredSound = rend::defaultButtonHoverSound;

	buttons[(int)SButtons::APPLY].mainTexture.file = "res/sprites/applyButtonTexture.png";
	buttons[(int)SButtons::APPLY].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)SButtons::APPLY].mainTexture);
	drw::InitSpriteData(buttons[(int)SButtons::APPLY].hoveredTexture);


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
		buttons[b].isActive = true;;
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

void InitLevelsContext(btn::Container& container, btn::Container& gridContainer, btn::Button buttons[], btn::Button gridButtons[])
{
	container.pos = { 0.5,0.5 };
	container.size = { 1.8,1.1 };
	container.isRendered = true;
	container.useTexture = true;
	container.texture = rend::defaultContainerTexture;

	btn::Init(container);

	gridContainer.pos = { 0.5,0.5 };
	gridContainer.size = { 1,0.6 };
	gridContainer.isRendered = true;
	gridContainer.useTexture = false;
	//gridContainer.texture = rend::defaultButtonHoveredTexture;
	gridContainer.color = {128,128,128,128};

	btn::Init(gridContainer);

	for (int b = 0; b < (int)LButtons::AMOUNT; b++)
	{
		buttons[b].signalTimerLimit = 0.1f;
		buttons[b].size = { 0.2,0.1 };
		buttons[b].clickedOffset = { -0.4,0 };
		buttons[b].useText = false;
		buttons[b].useSprite = true;
		buttons[b].isActive = true;
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


	for (int b = 0; b < (int)Levels::AMOUNT; b++)
	{
		gridButtons[b].signalTimerLimit = 0.1f;
		gridButtons[b].size = { 0.2,0.1 };
		gridButtons[b].clickedOffset = { 0,-0.2 };
		gridButtons[b].textColor = WHITE;
		gridButtons[b].useText = true;
		gridButtons[b].useSprite = true;
		gridButtons[b].isActive = true;
	}

	gridButtons[(int)Levels::LEVEL1].text = "Level 1";
	gridButtons[(int)Levels::LEVEL1].pos = { 0.2,0.8 };

	btn::Init(gridButtons[(int)Levels::LEVEL1], gridContainer, true);

	gridButtons[(int)Levels::LEVEL1].clickedUpSound = rend::defaultButtonClickUpSound;
	gridButtons[(int)Levels::LEVEL1].clickedDownSound = rend::defaultButtonClickDownSound;
	gridButtons[(int)Levels::LEVEL1].hoveredSound = rend::defaultButtonHoverSound;

	gridButtons[(int)Levels::LEVEL1].mainTexture.file = "res/sprites/buttonTexture.png";
	gridButtons[(int)Levels::LEVEL1].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL1].mainTexture);
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL1].hoveredTexture);


	gridButtons[(int)Levels::LEVEL2].text = "Level 2";
	gridButtons[(int)Levels::LEVEL2].pos = { 0.8,0.8 };

	btn::Init(gridButtons[(int)Levels::LEVEL2], gridContainer, true);

	gridButtons[(int)Levels::LEVEL2].clickedUpSound = rend::defaultButtonClickUpSound;
	gridButtons[(int)Levels::LEVEL2].clickedDownSound = rend::defaultButtonClickDownSound;
	gridButtons[(int)Levels::LEVEL2].hoveredSound = rend::defaultButtonHoverSound;

	gridButtons[(int)Levels::LEVEL2].mainTexture.file = "res/sprites/buttonTexture.png";
	gridButtons[(int)Levels::LEVEL2].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL2].mainTexture);
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL2].hoveredTexture);

	gridButtons[(int)Levels::LEVEL3].text = "Level 3";
	gridButtons[(int)Levels::LEVEL3].pos = { 0.2,0.2 };

	btn::Init(gridButtons[(int)Levels::LEVEL3], gridContainer, true);

	gridButtons[(int)Levels::LEVEL3].clickedUpSound = rend::defaultButtonClickUpSound;
	gridButtons[(int)Levels::LEVEL3].clickedDownSound = rend::defaultButtonClickDownSound;
	gridButtons[(int)Levels::LEVEL3].hoveredSound = rend::defaultButtonHoverSound;

	gridButtons[(int)Levels::LEVEL3].mainTexture.file = "res/sprites/buttonTexture.png";
	gridButtons[(int)Levels::LEVEL3].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL3].mainTexture);
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL3].hoveredTexture);


	gridButtons[(int)Levels::LEVEL4].text = "Level 4";
	gridButtons[(int)Levels::LEVEL4].pos = { 0.8,0.2 };

	btn::Init(gridButtons[(int)Levels::LEVEL4], gridContainer, true);

	gridButtons[(int)Levels::LEVEL4].clickedUpSound = rend::defaultButtonClickUpSound;
	gridButtons[(int)Levels::LEVEL4].clickedDownSound = rend::defaultButtonClickDownSound;
	gridButtons[(int)Levels::LEVEL4].hoveredSound = rend::defaultButtonHoverSound;

	gridButtons[(int)Levels::LEVEL4].mainTexture.file = "res/sprites/buttonTexture.png";
	gridButtons[(int)Levels::LEVEL4].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL4].mainTexture);
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL4].hoveredTexture);
}

void InitPlayContext(btn::Container& playContainer, btn::Button playButtons[], pdl::Paddle& paddle, bll::Ball& ball, blk::Block blocks[])
{
	playContainer.pos = { 0.5,0.5 };
	playContainer.size = { 1.8,1.1 };
	playContainer.isRendered = true;
	playContainer.useTexture = true;
	playContainer.texture = rend::defaultContainerTexture;

	btn::Init(playContainer);

	for (int b = 0; b < (int)PButtons::AMOUNT; b++)
	{
		playButtons[b].signalTimerLimit = 0.1f;
		playButtons[b].size = { 0.2,0.1 };
		playButtons[b].clickedOffset = { 0,-0.1 };
		playButtons[b].textColor = WHITE;
		playButtons[b].useText = true;
		playButtons[b].useSprite = true;
		playButtons[b].isActive = true;
	}

	playButtons[(int)PButtons::PAUSE].text = "| |";
	playButtons[(int)PButtons::PAUSE].fontSize *= 0.75f;
	playButtons[(int)PButtons::PAUSE].pos = { 0.5,0.925 };
	playButtons[(int)PButtons::PAUSE].size = { 0.05,0.075 };

	btn::Init(playButtons[(int)PButtons::PAUSE], playContainer, true);

	playButtons[(int)PButtons::PAUSE].clickedUpSound = rend::defaultButtonClickUpSound;
	playButtons[(int)PButtons::PAUSE].clickedDownSound = rend::defaultButtonClickDownSound;
	playButtons[(int)PButtons::PAUSE].hoveredSound = rend::defaultButtonHoverSound;

	playButtons[(int)PButtons::PAUSE].mainTexture.file = "res/sprites/buttonTexture.png";
	playButtons[(int)PButtons::PAUSE].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(playButtons[(int)PButtons::PAUSE].mainTexture);
	drw::InitSpriteData(playButtons[(int)PButtons::PAUSE].hoveredTexture);

	playButtons[(int)PButtons::RETURN].text = "Return";
	playButtons[(int)PButtons::RETURN].pos = { 0.5,0.6 };

	btn::Init(playButtons[(int)PButtons::RETURN], playContainer, true);

	playButtons[(int)PButtons::RETURN].clickedUpSound = rend::defaultButtonClickUpSound;
	playButtons[(int)PButtons::RETURN].clickedDownSound = rend::defaultButtonClickDownSound;
	playButtons[(int)PButtons::RETURN].hoveredSound = rend::defaultButtonHoverSound;

	playButtons[(int)PButtons::RETURN].mainTexture.file = "res/sprites/buttonTexture.png";
	playButtons[(int)PButtons::RETURN].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(playButtons[(int)PButtons::RETURN].mainTexture);
	drw::InitSpriteData(playButtons[(int)PButtons::RETURN].hoveredTexture);


	playButtons[(int)PButtons::EXIT].text = "Exit";
	playButtons[(int)PButtons::EXIT].pos = { 0.5,0.4 };

	btn::Init(playButtons[(int)PButtons::EXIT], playContainer, true);

	playButtons[(int)PButtons::EXIT].clickedUpSound = rend::defaultButtonClickUpSound;
	playButtons[(int)PButtons::EXIT].clickedDownSound = rend::defaultButtonClickDownSound;
	playButtons[(int)PButtons::EXIT].hoveredSound = rend::defaultButtonHoverSound;

	playButtons[(int)PButtons::EXIT].mainTexture.file = "res/sprites/buttonTexture.png";
	playButtons[(int)PButtons::EXIT].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(playButtons[(int)PButtons::EXIT].mainTexture);
	drw::InitSpriteData(playButtons[(int)PButtons::EXIT].hoveredTexture);

	pdl::Init(paddle);
	bll::Init(ball);
}

void MouseUpdate(btn::Button& mouse)
{
	mouse.pos = rend::mousePos;
	btn::UpdateInput(mouse);
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

void LevelsUpdate(btn::Container& container, btn::Container& gridContainer, btn::Button levelsButtons[], btn::Button gridButtons[], SubMenus& subMenu, GameStates& gameState)
{
	btn::UpdateInput(levelsButtons, (int)LButtons::AMOUNT);
	btn::UpdateInput(gridButtons, (int)Levels::AMOUNT);

	if (levelsButtons[(int)LButtons::EXIT].signal) {
		subMenu = SubMenus::MAIN;
	}

	if (gridButtons[(int)Levels::LEVEL1].signal) {
		subMenu = SubMenus::MAIN;
		gameState = GameStates::PLAYING;
		currentLevel = (int)Levels::LEVEL1 + 1;
	}
	if (gridButtons[(int)Levels::LEVEL2].signal) {
		subMenu = SubMenus::MAIN;
		gameState = GameStates::PLAYING;
		currentLevel = (int)Levels::LEVEL2 + 1;
	}
	if (gridButtons[(int)Levels::LEVEL3].signal) {
		subMenu = SubMenus::MAIN;
		gameState = GameStates::PLAYING;
		currentLevel = (int)Levels::LEVEL3 + 1;
	}
	if (gridButtons[(int)Levels::LEVEL4].signal) {
		subMenu = SubMenus::MAIN;
		gameState = GameStates::PLAYING;
		currentLevel = (int)Levels::LEVEL4 + 1;
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

void PlayInputUpdate(pdl::Paddle& paddle, bll::Ball& ball, blk::Block blocks[])
{
	if (isGamePaused) {
		return;
	}
	pdl::Input(paddle);
	bll::Input(ball);
	pdl::Update(paddle);
	bll::Update(ball,paddle);
}

void PlayUpdate(btn::Container& playContainer, btn::Button playButtons[], GameStates& gameState)
{
	if (isGamePaused) {
		playButtons[(int)PButtons::PAUSE].isActive = false;
		playButtons[(int)PButtons::PAUSE].isRendered = false;
		playButtons[(int)PButtons::RETURN].isActive = true;
		playButtons[(int)PButtons::RETURN].isRendered = true;
		playButtons[(int)PButtons::EXIT].isActive = true;
		playButtons[(int)PButtons::EXIT].isRendered = true;
	}
	else {
		playButtons[(int)PButtons::PAUSE].isActive = true;
		playButtons[(int)PButtons::PAUSE].isRendered = true;
		playButtons[(int)PButtons::RETURN].isActive = false;
		playButtons[(int)PButtons::RETURN].isRendered = false;
		playButtons[(int)PButtons::EXIT].isActive = false;
		playButtons[(int)PButtons::EXIT].isRendered = false;
	}

	btn::UpdateInput(playButtons, (int)PButtons::AMOUNT);

	if (playButtons[(int)PButtons::PAUSE].signal) {
		isGamePaused = true;
	}
	if (playButtons[(int)PButtons::RETURN].signal) {
		isGamePaused = false;
	}
	if (playButtons[(int)PButtons::EXIT].signal) {
		isGamePaused = false;
		gameState = GameStates::MAIN_MENU;
	}
}


void MouseDraw(btn::Button mouse)
{
	btn::Draw(mouse);
}

void MainMenuDraw(btn::Container mainMenuContainer, btn::Button mainMenuButtons[])
{
	btn::Draw(mainMenuContainer, mainMenuButtons, (int)MMButtons::AMOUNT);
}

void LevelsDraw(btn::Container& container, btn::Container& gridContainer, btn::Button buttons[], btn::Button gridButtons[])
{
	btn::Draw(container, buttons, (int)LButtons::AMOUNT);
	btn::Draw(gridContainer, gridButtons, (int)Levels::AMOUNT);

}

void SettingsDraw(btn::Container settingsContainer, btn::Button settingsButtons[])
{
	btn::Draw(settingsContainer, settingsButtons, (int)SButtons::AMOUNT);
}

void CreditsDraw(btn::Container creditsContainer, btn::Button creditsButtons[])
{
	btn::Draw(creditsContainer, creditsButtons, (int)CButtons::AMOUNT);
	drw::Rectangle({ 0.5,0.25 }, {0.2,0.6},GREY);
	drw::Text("Made by", rend::defaultFont, {0.5,0.7},70);
	drw::Text("Borja Lia", rend::defaultFont, {0.5,0.6}, 120);
	drw::Text("Special thanks to", rend::defaultFont, {0.5,0.4}, 50);
}

void PlayDraw(btn::Container playContainer, btn::Button playButtons[], pdl::Paddle& paddle, bll::Ball& ball, blk::Block blocks[])
{
	btn::Draw(playContainer, playButtons, (int)PButtons::AMOUNT);

	pdl::Draw(paddle);
	bll::Draw(ball);


}

void LoadLevel(lvl::LevelData& levelData)
{
	switch ((Levels)currentLevel)
	{
	case Levels::LEVEL1:

		levelData.paddle = pdl::Paddle();
		levelData.ball = bll::Ball();

		levelData.blockAmount = 6;

		for (int i = 0; i < levelData.blockAmount; i++)
		{
			levelData.blocks[i].pos = {0.1f + ((float)i/10),0.7f};
		}

		break;
	case Levels::LEVEL2:
		break;
	case Levels::LEVEL3:
		break;
	case Levels::LEVEL4:
		break;
	case Levels::AMOUNT:
		break;
	default:
		break;
	}
}

void InitLevel(lvl::LevelData& levelData, pdl::Paddle& paddle, bll::Ball& ball, blk::Block blocks[])
{

	pdl::Init(levelData.paddle);
	bll::Init(levelData.ball);

	paddle = levelData.paddle;
	ball = levelData.ball;

	for (int i = 0; i < levelData.blockAmount; i++)
	{
		blocks[i] = levelData.blocks[i];
	}
}