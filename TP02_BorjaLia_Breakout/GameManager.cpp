#include "GameManager.h"

void LoadSettings()
{
	rend::activeGraphics = (rend::GraphicsLib)stoi(utl::SearchInFile(settingsFilePath.c_str(), "graphics"));
	rend::nextGraphics = rend::activeGraphics;

	rend::windowSize.x = stoi(utl::SearchInFile(settingsFilePath.c_str(), "resolution_width"));
	rend::windowSize.y = stoi(utl::SearchInFile(settingsFilePath.c_str(), "resolution_height"));

	isFullscreen = stoi(utl::SearchInFile(settingsFilePath.c_str(), "fullscreen"));

	sett::graphics = rend::activeGraphics;

	sett::fullscreen = isFullscreen;
	sett::resolution = { rend::windowSize.x ,rend::windowSize.y};

	sett::usePowers = stoi(utl::SearchInFile(settingsFilePath.c_str(), "use_powers"));

	sett::keyUp = (ctrl::Key)stoi(utl::SearchInFile(settingsFilePath.c_str(), "key_up"));
	sett::keyLeft = (ctrl::Key)stoi(utl::SearchInFile(settingsFilePath.c_str(), "key_left"));;
	sett::keyRight = (ctrl::Key)stoi(utl::SearchInFile(settingsFilePath.c_str(), "key_right"));;

}

void SaveSettings() {
	utl::SaveToFile(settingsFilePath.c_str(), "graphics", (int)sett::graphics);
	
	utl::SaveToFile(settingsFilePath.c_str(), "fullscreen", (int)sett::fullscreen);
	utl::SaveToFile(settingsFilePath.c_str(), "resolution_width", (int)sett::resolution.x);
	utl::SaveToFile(settingsFilePath.c_str(), "resolution_height", (int)sett::resolution.y);

	utl::SaveToFile(settingsFilePath.c_str(), "use_powers", (int)sett::usePowers);

	utl::SaveToFile(settingsFilePath.c_str(), "use_multiply", (int)sett::usePowers);
}

void LoadDefaultFiles()
{
	rend::defaultContainerTexture.file = "res/sprites/Background4.png";

	rend::defaultButtonMainTexture.file = "res/sprites/ButtonTexture.png";
	rend::defaultButtonHoveredTexture.file = "res/sprites/ButtonHoverTexture.png";

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

	mouse.clickedDownSound = rend::defaultButtonClickDownSound;
	mouse.clickedUpSound = rend::defaultButtonClickUpSound;
	mouse.hoveredSound = rend::defaultButtonHoverSound;

	btn::Init(mouse);

	mouse.mainTexture.file = "res/sprites/mouseTexture.png";
	mouse.hoveredTexture.file = "res/sprites/mouseTexture.png";
	drw::InitSpriteData(mouse.mainTexture);
	drw::InitSpriteData(mouse.hoveredTexture);
}

void DeInitMouse(btn::Button& mouse)
{
	drw::DeInitSpriteData(mouse.mainTexture);
	drw::DeInitSpriteData(mouse.hoveredTexture);
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
		buttons[b].pos = { 0.5,0.5 };
		buttons[b].clickedOffset = { 0,-0.1f };
		buttons[b].textColor = WHITE;
		buttons[b].useText = true;
		buttons[b].useSprite = true;
		buttons[b].isActive = true;
		buttons[b].textData = rend::defaultFont;
		buttons[b].mainTexture = rend::defaultButtonMainTexture;
		buttons[b].hoveredTexture = rend::defaultButtonHoveredTexture;
		buttons[b].clickedDownSound = rend::defaultButtonClickDownSound;
		buttons[b].clickedUpSound = rend::defaultButtonClickUpSound;
		buttons[b].hoveredSound = rend::defaultButtonHoverSound;
		buttons[b].activeTexture = rend::defaultButtonMainTexture;
	}

	std::string renderer = "";

	switch (sett::graphics)
	{
	case rend::GraphicsLib::RAYLIB: {
		renderer = "Raylib";
		break;
	}
	case rend::GraphicsLib::SIGIL: {
		renderer = "Sigil";
		break;
	}
	default:
		break;
	}

	buttons[(int)SButtons::RENDERER].text = renderer;
	buttons[(int)SButtons::RENDERER].pos = { 0.8,0.8 };

	btn::Init(buttons[(int)SButtons::RENDERER], container, true);

	buttons[(int)SButtons::FULLSCREEN].text = "Fullscreen";
	buttons[(int)SButtons::FULLSCREEN].pos = { 0.8,0.7 };

	btn::Init(buttons[(int)SButtons::FULLSCREEN], container, true);

	buttons[(int)SButtons::RESOLUTION].text = "Resolution";
	buttons[(int)SButtons::RESOLUTION].pos = { 0.8,0.6 };

	btn::Init(buttons[(int)SButtons::RESOLUTION], container, true);

	buttons[(int)SButtons::USE_POWERS].text = "Use Powers";
	buttons[(int)SButtons::USE_POWERS].pos = { 0.8,0.5 };

	btn::Init(buttons[(int)SButtons::USE_POWERS], container, true);

	buttons[(int)SButtons::KEY_UP].text = "Key up";
	buttons[(int)SButtons::KEY_UP].pos = { 0.4,0.6 };
	buttons[(int)SButtons::KEY_UP].size = { 0.1,0.1 };

	btn::Init(buttons[(int)SButtons::KEY_UP], container, true);

	buttons[(int)SButtons::KEY_LEFT].text = "key Left";
	buttons[(int)SButtons::KEY_LEFT].pos = { 0.6,0.6 };
	buttons[(int)SButtons::KEY_LEFT].size = { 0.1,0.1 };

	btn::Init(buttons[(int)SButtons::KEY_LEFT], container, true);

	buttons[(int)SButtons::KEY_RIGHT].text = "Key Right";
	buttons[(int)SButtons::KEY_RIGHT].pos = { 0.5,0.7 };
	buttons[(int)SButtons::KEY_RIGHT].size = { 0.1,0.1 };

	btn::Init(buttons[(int)SButtons::KEY_RIGHT], container, true);


	buttons[(int)SButtons::APPLY].text = "Apply";
	buttons[(int)SButtons::APPLY].pos = { 0.9,0.2 };
	buttons[(int)SButtons::APPLY].clickedOffset = { 0.4,0 };
	buttons[(int)SButtons::APPLY].useText = false;

	btn::Init(buttons[(int)SButtons::APPLY], container, true);

	buttons[(int)SButtons::APPLY].mainTexture = menu::applyButtonTexture;
	buttons[(int)SButtons::APPLY].hoveredTexture = menu::applyButtonHoveredTexture;


	buttons[(int)SButtons::EXIT].text = "Exit";
	buttons[(int)SButtons::EXIT].pos = { 0.1,0.2 };
	buttons[(int)SButtons::EXIT].clickedOffset = { -0.4,0 };
	buttons[(int)SButtons::EXIT].useText = false;

	btn::Init(buttons[(int)SButtons::EXIT], container, true);

	buttons[(int)SButtons::EXIT].mainTexture = menu::exitButtonTexture;
	buttons[(int)SButtons::EXIT].hoveredTexture = menu::exitButtonHoveredTexture;
}

void InitEndScreenContext(btn::Container& container, btn::Button buttons[]) {

	container.pos = { 0.5,0.5 };
	container.size = { 1.8,1.1 };
	container.isRendered = true;
	container.useTexture = true;
	container.texture = rend::defaultContainerTexture;

	btn::Init(container);

	for (int b = 0; b < (int)EButtons::AMOUNT; b++)
	{
		buttons[b].signalTimerLimit = 0.1f;
		buttons[b].size = { 0.2,0.1 };
		buttons[b].clickedOffset = { -0.4,0 };
		buttons[b].textColor = WHITE;
		buttons[b].useText = true;
		buttons[b].useSprite = true;
		buttons[b].isActive = true;
		buttons[b].textData = rend::defaultFont;
		buttons[b].mainTexture = rend::defaultButtonMainTexture;
		buttons[b].hoveredTexture = rend::defaultButtonHoveredTexture;
		buttons[b].clickedDownSound = rend::defaultButtonClickDownSound;
		buttons[b].clickedUpSound = rend::defaultButtonClickUpSound;
		buttons[b].hoveredSound = rend::defaultButtonHoverSound;
	}

	buttons[(int)EButtons::NEXT].text = ">";
	buttons[(int)EButtons::NEXT].pos = { 0.8,0.5 };
	buttons[(int)EButtons::NEXT].size = { 0.15,0.1 };
	buttons[(int)EButtons::NEXT].clickedOffset = { 0,-0.1f };

	btn::Init(buttons[(int)EButtons::NEXT], container, true);


	buttons[(int)EButtons::LAST].text = "<";
	buttons[(int)EButtons::LAST].pos = { 0.2,0.5 };
	buttons[(int)EButtons::LAST].size = { 0.15,0.1 };
	buttons[(int)EButtons::LAST].clickedOffset = { 0,-0.1f };;

	btn::Init(buttons[(int)EButtons::LAST], container, true);


	buttons[(int)EButtons::RETRY].text = "Retry";
	buttons[(int)EButtons::RETRY].pos = { 0.5,0.5 };
	buttons[(int)EButtons::RETRY].clickedOffset = { 0,-0.1f };

	btn::Init(buttons[(int)EButtons::RETRY], container, true);

	buttons[(int)EButtons::EXIT].text = "Exit";
	buttons[(int)EButtons::EXIT].pos = { 0.5,0.25 };
	buttons[(int)EButtons::EXIT].clickedOffset = { 0,-0.1f };

	btn::Init(buttons[(int)EButtons::EXIT], container, true);
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
		buttons[b].textColor = WHITE;
		buttons[b].useText = false;
		buttons[b].useSprite = true;
		buttons[b].isActive = true;
		buttons[b].textData = rend::defaultFont;
		buttons[b].mainTexture = rend::defaultButtonMainTexture;
		buttons[b].hoveredTexture = rend::defaultButtonHoveredTexture;
		buttons[b].clickedDownSound = rend::defaultButtonClickDownSound;
		buttons[b].clickedUpSound = rend::defaultButtonClickUpSound;
		buttons[b].hoveredSound = rend::defaultButtonHoverSound;
	}

	buttons[(int)CButtons::EXIT].text = "Exit";
	buttons[(int)CButtons::EXIT].pos = { 0.1,0.2 };

	btn::Init(buttons[(int)CButtons::EXIT], container, true);

	buttons[(int)CButtons::EXIT].mainTexture = menu::exitButtonTexture;
	buttons[(int)CButtons::EXIT].hoveredTexture = menu::exitButtonHoveredTexture;
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
	gridContainer.isRendered = false;
	gridContainer.useTexture = false;
	//gridContainer.texture = rend::defaultButtonHoveredTexture;
	gridContainer.color = { 128,128,128,128 };

	btn::Init(gridContainer);

	for (int b = 0; b < (int)LButtons::AMOUNT; b++)
	{
		buttons[b].signalTimerLimit = 0.1f;
		buttons[b].size = { 0.2,0.1 };
		buttons[b].clickedOffset = { -0.4,0 };
		buttons[b].textColor = WHITE;
		buttons[b].useText = true;
		buttons[b].useSprite = true;
		buttons[b].isActive = true;
		buttons[b].textData = rend::defaultFont;
		buttons[b].mainTexture = rend::defaultButtonMainTexture;
		buttons[b].hoveredTexture = rend::defaultButtonHoveredTexture;
		buttons[b].clickedDownSound = rend::defaultButtonClickDownSound;
		buttons[b].clickedUpSound = rend::defaultButtonClickUpSound;
		buttons[b].hoveredSound = rend::defaultButtonHoverSound;
	}

	buttons[(int)LButtons::EXIT].text = "Exit";
	buttons[(int)LButtons::EXIT].pos = { 0.1,0.2 };
	buttons[(int)LButtons::EXIT].useText = false;

	btn::Init(buttons[(int)LButtons::EXIT], container, true);

	buttons[(int)LButtons::EXIT].mainTexture = menu::exitButtonTexture;
	buttons[(int)LButtons::EXIT].hoveredTexture = menu::exitButtonHoveredTexture;


	for (int b = 0; b < (int)Levels::AMOUNT; b++)
	{
		gridButtons[b].signalTimerLimit = 0.1f;
		gridButtons[b].size = { 0.2,0.1 };
		gridButtons[b].clickedOffset = { 0,-0.2 };
		gridButtons[b].textColor = WHITE;
		gridButtons[b].textData = rend::defaultFont;
		gridButtons[b].useText = true;
		gridButtons[b].useSprite = true;
		gridButtons[b].isActive = true;
		gridButtons[b].textData = rend::defaultFont;
		gridButtons[b].mainTexture = rend::defaultButtonMainTexture;
		gridButtons[b].hoveredTexture = rend::defaultButtonHoveredTexture;
		gridButtons[b].clickedDownSound = rend::defaultButtonClickDownSound;
		gridButtons[b].clickedUpSound = rend::defaultButtonClickUpSound;
		gridButtons[b].hoveredSound = rend::defaultButtonHoverSound;
	}

	gridButtons[(int)Levels::LEVEL1].text = "Level	1";
	gridButtons[(int)Levels::LEVEL1].pos = { 0.2,0.8 };

	btn::Init(gridButtons[(int)Levels::LEVEL1], gridContainer, true);


	gridButtons[(int)Levels::LEVEL2].text = "Level	2";
	gridButtons[(int)Levels::LEVEL2].pos = { 0.8,0.8 };

	btn::Init(gridButtons[(int)Levels::LEVEL2], gridContainer, true);


	gridButtons[(int)Levels::LEVEL3].text = "Level	3";
	gridButtons[(int)Levels::LEVEL3].pos = { 0.2,0.2 };

	btn::Init(gridButtons[(int)Levels::LEVEL3], gridContainer, true);


	gridButtons[(int)Levels::LEVEL4].text = "Level	4";
	gridButtons[(int)Levels::LEVEL4].pos = { 0.8,0.2 };

	btn::Init(gridButtons[(int)Levels::LEVEL4], gridContainer, true);
}

void InitPlayContext(btn::Container& playContainer, btn::Button playButtons[])
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
		playButtons[b].textData = rend::defaultFont;
		playButtons[b].mainTexture = rend::defaultButtonMainTexture;
		playButtons[b].hoveredTexture = rend::defaultButtonHoveredTexture;
		playButtons[b].clickedDownSound = rend::defaultButtonClickDownSound;
		playButtons[b].clickedUpSound = rend::defaultButtonClickUpSound;
		playButtons[b].hoveredSound = rend::defaultButtonHoverSound;

	}

	playButtons[(int)PButtons::PAUSE].text = "| |";
	playButtons[(int)PButtons::PAUSE].fontSize *= 0.75f;
	playButtons[(int)PButtons::PAUSE].pos = { 0.5,0.925 };
	playButtons[(int)PButtons::PAUSE].size = { 0.05,0.075 };

	btn::Init(playButtons[(int)PButtons::PAUSE], playContainer, true);


	playButtons[(int)PButtons::RETURN].text = "Return";
	playButtons[(int)PButtons::RETURN].pos = { 0.5,0.6 };

	btn::Init(playButtons[(int)PButtons::RETURN], playContainer, true);


	playButtons[(int)PButtons::RETRY].text = "Retry";
	playButtons[(int)PButtons::RETRY].pos = { 0.5,0.4 };

	btn::Init(playButtons[(int)PButtons::RETRY], playContainer, true);


	playButtons[(int)PButtons::EXIT].text = "Exit";
	playButtons[(int)PButtons::EXIT].pos = { 0.5,0.2 };

	btn::Init(playButtons[(int)PButtons::EXIT], playContainer, true);

	blk::normalTexture.file = "res/sprites/BrickTexture.png";
	blk::largeTexture.file = "res/sprites/LargeBrickTexture.png";
	blk::mirrorTexture.file = "res/sprites/MirrorBrickTexture.png";
	blk::homingTexture.file = "res/sprites/HomingBrickTexture.png";
	blk::multiplyTexture.file = "res/sprites/MultBrickTexture.png";
	blk::comboTexture.file = "res/sprites/ComboBrickTexture.png";

	drw::InitSpriteData(blk::normalTexture);
	drw::InitSpriteData(blk::largeTexture);
	drw::InitSpriteData(blk::mirrorTexture);
	drw::InitSpriteData(blk::homingTexture);
	drw::InitSpriteData(blk::multiplyTexture);
	drw::InitSpriteData(blk::comboTexture);

	blk::fullTexture.file = "res/sprites/Full.png";
	blk::mediumTexture.file = "res/sprites/Medium.png";
	blk::depletedTexture.file = "res/sprites/Depleted.png";

	drw::InitSpriteData(blk::fullTexture);
	drw::InitSpriteData(blk::mediumTexture);
	drw::InitSpriteData(blk::depletedTexture);

	blk::blockHitSound.file = "res/audio/ButtonClick.wav";
	blk::blockBrokenSound.file = "res/audio/ButtonClick.wav";
	blk::blockBrokenPowerSound.file = "res/audio/ButtonClick.wav";

	snd::Init(blk::blockHitSound);
	snd::Init(blk::blockBrokenSound);
	snd::Init(blk::blockBrokenPowerSound);
}

void MouseUpdate(btn::Button& mouse)
{
	mouse.pos = rend::mousePos;
	btn::UpdateInput(mouse);
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
	if (sett::changingKeyUp || sett::changingKeyLeft || sett::changingKeyRight) {



	}



	btn::UpdateInput(settingsButtons, (int)SButtons::AMOUNT);

	if (settingsButtons[(int)SButtons::RENDERER].signal) {

		switch (sett::graphics)
		{
		case rend::GraphicsLib::RAYLIB: {
			sett::graphics = rend::GraphicsLib::SIGIL;
			settingsButtons[(int)SButtons::RENDERER].text = "Sigil";
			break;
		}
		case rend::GraphicsLib::SIGIL: {
			sett::graphics = rend::GraphicsLib::RAYLIB;
			settingsButtons[(int)SButtons::RENDERER].text = "Raylib";
			break;
		}
		default:
			break;
		}

		if (sett::graphics != rend::activeGraphics) {
			shouldReset = true;
		}
		else {
			shouldReset = false;
		}
	}
	if (settingsButtons[(int)SButtons::FULLSCREEN].signal) {
		
		sett::fullscreen = !sett::fullscreen;

		if (sett::fullscreen != isFullscreen) {
			shouldReset = true;
		}
		else {
			shouldReset = false;
		}

	}
	if (settingsButtons[(int)SButtons::RESOLUTION].signal) {
		
	}
	if (settingsButtons[(int)SButtons::USE_POWERS].signal) {
		
	}
	if (settingsButtons[(int)SButtons::KEY_UP].signal) {
		sett::changingKeyUp = true;
	}
	if (settingsButtons[(int)SButtons::KEY_LEFT].signal) {
		sett::changingKeyLeft = true;
		
	}
	if (settingsButtons[(int)SButtons::KEY_RIGHT].signal) {
		sett::changingKeyRight = true;
		
	}




	if (settingsButtons[(int)SButtons::APPLY].signal) {
		SaveSettings();
		if (shouldReset) {
			subMenu = SubMenus::EXIT;
		}
		else {
			subMenu = SubMenus::MAIN;
		}
	}

	if (settingsButtons[(int)SButtons::EXIT].signal) {
		subMenu = SubMenus::MAIN;
	}
}

void EndScreenUpdate(btn::Button endScreenButtons[], SubMenus& subMenu, GameStates& gameState, lvl::LevelData& activeLevel)
{
	btn::UpdateInput(endScreenButtons, (int)EButtons::AMOUNT);

	if (endScreenButtons[(int)EButtons::NEXT].signal) {
		subMenu = SubMenus::MAIN;
		gameState = GameStates::PLAYING;
		currentLevel++;

		if (currentLevel > (int)Levels::AMOUNT) {
			currentLevel = 1;
		}
		LoadLevel(activeLevel);
	}
	if (endScreenButtons[(int)EButtons::LAST].signal) {
		subMenu = SubMenus::MAIN;
		gameState = GameStates::PLAYING;
		currentLevel--;

		if (currentLevel < 1) {
			currentLevel = (int)Levels::AMOUNT;
		}
		LoadLevel(activeLevel);
	}
	if (endScreenButtons[(int)EButtons::RETRY].signal) {
		subMenu = SubMenus::MAIN;
		gameState = GameStates::PLAYING;
		ResetLevel(activeLevel);
		LoadLevel(activeLevel);
	}
	if (endScreenButtons[(int)EButtons::EXIT].signal) {
		subMenu = SubMenus::MAIN;
		gameState = GameStates::MAIN_MENU;
	}

	if (subMenu != SubMenus::ENDSCREEN || gameState == GameStates::PLAYING) {
		currentScore = 0;
	}

}
void CreditsUpdate(btn::Button creditsButtons[], SubMenus& subMenu)
{
	btn::UpdateInput(creditsButtons, (int)CButtons::AMOUNT);

	if (creditsButtons[(int)CButtons::EXIT].signal) {
		subMenu = SubMenus::MAIN;
	}
}

void PlayInputUpdate(lvl::LevelData& levelData)
{
	if (isGamePaused) {
		return;
	}
	pdl::Input(levelData.paddle);
	bll::Input(levelData.ball);
	pdl::Update(levelData.paddle);
	bll::Update(levelData.ball, levelData.paddle, levelData.blocks, levelData.blockAmount);

	for (int i = 0; i < levelData.blockAmount; i++)
	{
		lvl::NextAvailablePowerDrop(levelData);
		blk::Update(levelData.blocks[i], levelData.paddle, levelData.powerDrops[levelData.availablePowerDrop]);
	}

	for (int i = 0; i < levelData.powerDropAmount; i++)
	{
		pwr::Update(levelData.powerDrops[i],levelData.paddle.pos,levelData.paddle.size);
	}

	if (currentScore != -1) {
		currentScore = levelData.paddle.score;
	}

	PowerManager(levelData);
}

void PlayUpdate(btn::Container& playContainer, btn::Button playButtons[], SubMenus& subMenu, GameStates& gameState, lvl::LevelData& activeLevel)
{
	if (isGamePaused) {
		playButtons[(int)PButtons::PAUSE].isActive = false;
		playButtons[(int)PButtons::PAUSE].isRendered = false;
		playButtons[(int)PButtons::RETURN].isActive = true;
		playButtons[(int)PButtons::RETURN].isRendered = true;
		playButtons[(int)PButtons::RETRY].isActive = true;
		playButtons[(int)PButtons::RETRY].isRendered = true;
		playButtons[(int)PButtons::EXIT].isActive = true;
		playButtons[(int)PButtons::EXIT].isRendered = true;
	}
	else {
		levelTimer += rend::deltaTime;

		playButtons[(int)PButtons::PAUSE].isActive = true;
		playButtons[(int)PButtons::PAUSE].isRendered = true;
		playButtons[(int)PButtons::RETURN].isActive = false;
		playButtons[(int)PButtons::RETURN].isRendered = false;
		playButtons[(int)PButtons::RETRY].isActive = false;
		playButtons[(int)PButtons::RETRY].isRendered = false;
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
	if (playButtons[(int)PButtons::RETRY].signal) {
		isGamePaused = false;
		ResetLevel(activeLevel);
		//LoadLevel(activeLevel);
	}
	if (playButtons[(int)PButtons::EXIT].signal) {
		isGamePaused = false;
		subMenu = SubMenus::MAIN;
		gameState = GameStates::MAIN_MENU;
	}

	if (lvl::BlocksLeft(activeLevel) <= 0) {
		
		if (currentScore > activeLevel.hiScore || (currentScore == activeLevel.hiScore && levelTimer < activeLevel.bestTime)) {
			SaveLevel(activeLevel);
		}
		
		subMenu = SubMenus::ENDSCREEN;
		gameState = GameStates::MAIN_MENU;
	}

	if (currentScore == -1) {
		subMenu = SubMenus::ENDSCREEN;
		gameState = GameStates::MAIN_MENU;
	}
}


void MouseDraw(btn::Button mouse)
{
	btn::Draw(mouse);
}



void LevelsDraw(btn::Container& container, btn::Container& gridContainer, btn::Button buttons[], btn::Button gridButtons[])
{
	btn::Draw(container, buttons, (int)LButtons::AMOUNT);
	btn::Draw(gridContainer, gridButtons, (int)Levels::AMOUNT);

	for (int i = 0; i < (int)Levels::AMOUNT; i++)
	{

		std::string levelFile = "data/level.txt";

		switch ((Levels)i)
		{
		case Levels::LEVEL1: {
			levelFile = "data/level1.txt";
			break;
		}
		case Levels::LEVEL2: {
			levelFile = "data/level2.txt";
			break;
		}
		case Levels::LEVEL3: {
			levelFile = "data/level3.txt";
			break;
		}
		case Levels::LEVEL4: {
			levelFile = "data/level4.txt";
			break;
		}
		case Levels::AMOUNT:
			break;
		default:
			break;
		}

		int hiScore = stoi(utl::SearchInFile(levelFile.c_str(),"best_score"));
		int bestTime = stoi(utl::SearchInFile(levelFile.c_str(),"best_time"));

		std::string hiScoreString = "Best Score: ";
		hiScoreString.append(std::to_string(hiScore));

		std::string bestTimeString = "Best Time: ";
		bestTimeString.append(std::to_string((int)bestTime));

		drw::Text(hiScoreString.c_str(), rend::defaultFont, { gridButtons[i].pos.x,gridButtons[i].pos.y - gridButtons[i].size.y }, 40);
		drw::Text(bestTimeString.c_str(), rend::defaultFont, { gridButtons[i].pos.x,gridButtons[i].pos.y - 1.5f * (gridButtons[i].size.y) }, 40);
	}

}

void SettingsDraw(btn::Container settingsContainer, btn::Button settingsButtons[])
{
	btn::Draw(settingsContainer, settingsButtons, (int)SButtons::AMOUNT);
}

void EndScreenDraw(btn::Container endScreenContainer, btn::Button endScreenButtons[]) {

	btn::Draw(endScreenContainer, endScreenButtons, (int)EButtons::AMOUNT);
	std::string level = "Level ";
	drw::Text(level.append(std::to_string(currentLevel)).c_str(), rend::defaultFont, { 0.5f,0.8f }, 100);
	if (currentScore != -1) {

		std::string score = "Scored: ";
		drw::Text(score.append(std::to_string(currentScore)).c_str(), rend::defaultFont, { 0.5f,0.65f }, 60);
		std::string timer = "Time: ";
		drw::Text(timer.append(std::to_string((int)levelTimer)).c_str(), rend::defaultFont, { 0.5f,0.6f }, 60);
	}
	else {
		drw::Text("You lost!", rend::defaultFont, { 0.5f,0.65f }, 60);
	}
}

void CreditsDraw(btn::Container creditsContainer, btn::Button creditsButtons[])
{
	btn::Draw(creditsContainer, creditsButtons, (int)CButtons::AMOUNT);
	drw::Rectangle({ 0.5,0.25 }, { 0.2,0.6 }, GREY);
	drw::Text("Made by", rend::defaultFont, { 0.5,0.7 }, 70);
	drw::Text("Borja Lia", rend::defaultFont, { 0.5,0.6 }, 120);
	drw::Text("Special thanks to", rend::defaultFont, { 0.5,0.4 }, 50);
}

void PlayDraw(btn::Container& playContainer, btn::Button playButtons[], lvl::LevelData& levelData)
{
	btn::Draw(playContainer);

	pdl::Draw(levelData.paddle);
	bll::Draw(levelData.ball);

	for (int i = 0; i < levelData.blockAmount; i++)
	{
		blk::Draw(levelData.blocks[i]);
	}

	for (int i = 0; i < levelData.powerDropAmount; i++)
	{
		pwr::Draw(levelData.powerDrops[i]);
	}

	btn::Draw(playButtons, (int)PButtons::AMOUNT);
	std::string score = "Score: ";
	drw::Text((score.append(std::to_string(levelData.paddle.score))).c_str(), rend::defaultFont, { 0.1f,0.965f }, 50);
	std::string hp = "Hp: ";
	drw::Text((hp.append(std::to_string(levelData.paddle.healthPoints))).c_str(), rend::defaultFont, { 0.3f,0.965f }, 50);

	std::string timer = "Time: ";
	drw::Text((timer.append(std::to_string((int)levelTimer))).c_str(), rend::defaultFont, { 0.6f,0.965f }, 50);

	if (pwr::isLargePowerActive) {
		drw::Text("L!", rend::defaultFont, {0.8f,0.965f}, 50);
	}
	if (pwr::isHomingPowerActive) {
		drw::Text("H!", rend::defaultFont, { 0.9f,0.965f }, 50);
	}
}

void PlaySounds(lvl::LevelData& levelData)
{
	//pdl::Sound(levelData.paddle);
	//bll::Sound(levelData.ball);

	for (int i = 0; i < levelData.blockAmount; i++)
	{
		blk::Sound(levelData.blocks[i]);
	}
}

void LoadLevel(lvl::LevelData& levelData)
{

	//for (int i = 0; i < 8; i++)
	//{
	//	levelData.blocks[i].pos = { 0.5f + ((float)((i - levelData.blockAmount / 2) * levelData.blocks[i].size.x) * 1.5f), 0.7f };
	//	//levelData.blocks[i].pos = { 0.5f + ((float)(i- levelData.blockAmount/2.0f) / 10.0f),0.7f };
	//	if (levelData.blockAmount % 2 == 0) {
	//		levelData.blocks[i].pos.x += levelData.blocks[i].size.x / 1.33f;
	//	}
	//}

	pwr::largePowerTimer = pwr::largePowerTimerLimit;
	pwr::mirrorPowerTimer = pwr::mirrorPowerTimerLimit;
	pwr::homingPowerTimer = pwr::homingPowerTimerLimit;
	pwr::comboPowerTimer = pwr::comboPowerTimerLimit;

	pwr::multiplyPowerActivation = false;

	pwr::isLargePowerActive = false;
	pwr::isMirrorPowerActive = false;
	pwr::isHomingPowerActive = false;
	pwr::isComboPowerActive = false;
	pwr::isMultiplyPowerActive = false;

	pwr::isLargePowerActiveChange = false;
	pwr::isMirrorPowerActiveChange = false;
	pwr::isHomingPowerActiveChange = false;
	pwr::isComboPowerActiveChange = false;
	pwr::isMultiplyPowerActiveChange = false;

	pwr::isLargePowerDeActiveChange = false;
	pwr::isMirrorPowerDeActiveChange = false;
	pwr::isHomingPowerDeActiveChange = false;
	pwr::isComboPowerDeActiveChange = false;
	pwr::isMultiplyPowerDeActiveChange = false;

	for (int i = 0; i < levelData.powerDropAmount; i++)
	{
		pwr::Reset(levelData.powerDrops[i]);
	}

	std::string levelFile = "data/level.txt";

	levelData.blockAmount = 0;
	int m = 0;

	switch ((Levels)(currentLevel - 1))
	{
	case Levels::LEVEL1: {

		levelData.id = 1;

		levelFile = "data/level1.txt";

		levelData.paddle = pdl::Paddle();
		levelData.ball = bll::Ball();

		levelData.blockAmount = 24;

		for (int i = 0; i < 24; i++)
		{
			if (m >= 8) {
				m = 0;
			}
			levelData.blocks[i].isActive = true;
			levelData.blocks[i].heldPowerType = pwr::PowerType::NONE;

			levelData.blocks[i].color = WHITE;
			levelData.blocks[i].playSound = false;
			levelData.blocks[i].activeSound = blk::blockHitSound;

			levelData.blocks[i].pos = { 0.5f + ((float)((m - 8 / 2) * levelData.blocks[i].size.x) * 1.5f), 0.6f };
			levelData.blocks[i].pos.x += levelData.blocks[i].size.x / 1.33f;
			levelData.blocks[i].heldPowerType = pwr::PowerType::MIRROR;

			if (i >= 8) {
				levelData.blocks[i].heldPowerType = pwr::PowerType::LARGE;
				levelData.blocks[i].pos.y += 0.15f;
			}
			if (i >= 16) {
				levelData.blocks[i].heldPowerType = pwr::PowerType::HOMING;
				levelData.blocks[i].pos.y += 0.15f;
			}
			m++;
		}

		if (sett::usePowers) {
			for (int i = 0; i < 24; i++) {

			}
		}

		//levelData.blocks[3].heldPowerType = pwr::PowerType::HOMING;

		break;
	}
	case Levels::LEVEL2: {

		levelData.id = 2;

		levelFile = "data/level2.txt";

		levelData.paddle = pdl::Paddle();
		levelData.ball = bll::Ball();

		levelData.blockAmount = 38;

		for (int i = 0; i < 24; i++)
		{
			if (m >= 8) {
				m = 0;
			}

			levelData.blocks[i].maxHitPoints = 2;
			levelData.blocks[i].color = WHITE;
			levelData.blocks[i].pos = { 0.5f + ((float)((m - 8 / 2) * levelData.blocks[i].size.x) * 1.5f), 0.45f };
			levelData.blocks[i].pos.x += levelData.blocks[i].size.x / 1.33f;

			if (i >= 8) {
				levelData.blocks[i].pos.y += 0.175f;
			}
			if (i >= 16) {
				levelData.blocks[i].pos.y += 0.175f;
			}
			m++;
		}
		m = 0;
		for (int i = 24; i < levelData.blockAmount; i++)
		{
			if (m >= 7) {
				m = 0;
			}

			levelData.blocks[i].maxHitPoints = 1;
			levelData.blocks[i].color = WHITE;
			levelData.blocks[i].pos = { 0.5f + ((float)((m - 7 / 2) * levelData.blocks[i].size.x) * 1.5f), 0.525f };
			//levelData.blocks[i].pos.x += levelData.blocks[i].size.x;

			if (i >= 31) {
				levelData.blocks[i].pos.y += 0.175f;
			}
			m++;
		}

		break;
	}
	case Levels::LEVEL3: {

		levelData.id = 3;

		levelFile = "data/level3.txt";

		levelData.paddle = pdl::Paddle();
		levelData.ball = bll::Ball();

		levelData.blockAmount = 1;

		levelData.blocks[0].pos = { 0.5,0.5 };
		levelData.blocks[0].size = { 0.3,0.2 };
		levelData.blocks[0].maxHitPoints = 1;


		break;
	}
	case Levels::LEVEL4: {
		levelData.id = 4;

		levelFile = "data/level4.txt";
		break;
	}
	case Levels::AMOUNT:
		break;
	default:
		break;
	}



	levelData.hiScore = stoi(utl::SearchInFile(levelFile.c_str(), "best_score"));
	levelData.bestTime = stoi(utl::SearchInFile(levelFile.c_str(), "best_time"));

	InitLevel(levelData);

	levelTimer = 0;
}

void SaveLevel(lvl::LevelData& levelData)
{
	std::string levelFile = "data/level.txt";

	switch ((Levels)(levelData.id - 1))
	{
	case Levels::LEVEL1: {
		levelFile = "data/level1.txt";

		levelData.hiScore = currentScore;
		levelData.bestTime = levelTimer;
		break;
	}
	case Levels::LEVEL2: {
		levelFile = "data/level2.txt";

		levelData.hiScore = currentScore;
		levelData.bestTime = levelTimer;
		break;
	}
	case Levels::LEVEL3: {
		levelFile = "data/level3.txt";

		levelData.hiScore = currentScore;
		levelData.bestTime = levelTimer;
		break;
	}
	case Levels::LEVEL4: {
		levelFile = "data/level4.txt";

		levelData.hiScore = currentScore;
		levelData.bestTime = levelTimer;
		break;
	}
	case Levels::AMOUNT:
		break;
	
	default:
		break;
	}
		utl::SaveToFile(levelFile.c_str(), "best_score", currentScore);
		utl::SaveToFile(levelFile.c_str(), "best_time", levelTimer);
}

void InitLevel(lvl::LevelData& levelData)
{

	pdl::Reset(levelData.paddle);
	bll::Reset(levelData.ball);
	pdl::Init(levelData.paddle);
	bll::Init(levelData.ball);


	for (int i = 0; i < levelData.blockAmount; i++)
	{
		blk::Init(levelData.blocks[i]);
	}
}

void ResetLevel(lvl::LevelData& levelData) {
	pdl::Reset(levelData.paddle);
	bll::Reset(levelData.ball);

	for (int i = 0; i < levelData.blockAmount; i++)
	{
		blk::Reset(levelData.blocks[i]);
	}
	LoadLevel(levelData);
}

void PowerManager(lvl::LevelData& levelData)
{
	pwr::largePowerTimer += rend::deltaTime;
	pwr::mirrorPowerTimer += rend::deltaTime;
	pwr::homingPowerTimer += rend::deltaTime;
	pwr::comboPowerTimer += rend::deltaTime;

	if (pwr::largePowerTimer < pwr::largePowerTimerLimit) {
		if (!pwr::isLargePowerActive) {
			pwr::isLargePowerActiveChange = true;
		}
		pwr::isLargePowerActive = true;
	}
	else {
		if (pwr::isLargePowerActive) {
			pwr::isLargePowerDeActiveChange = true;
		}
		pwr::isLargePowerActive = false;
	}

	if (pwr::mirrorPowerTimer < pwr::mirrorPowerTimerLimit) {
		if (!pwr::isMirrorPowerActive) {
			pwr::isMirrorPowerActiveChange = true;
		}
		pwr::isMirrorPowerActive = true;
	}
	else {
		if (pwr::isMirrorPowerActive) {
			pwr::isMirrorPowerDeActiveChange = true;
		}
		pwr::isMirrorPowerActive = false;
	}

	if (pwr::homingPowerTimer < pwr::homingPowerTimerLimit) {
		if (!pwr::isHomingPowerActive) {
			pwr::isHomingPowerActiveChange = true;
		}
		pwr::isHomingPowerActive = true;
	}
	else {
		if (pwr::isHomingPowerActive) {
			pwr::isHomingPowerDeActiveChange = true;
		}
		pwr::isHomingPowerActive = false;
	}

	if (pwr::comboPowerTimer < pwr::comboPowerTimerLimit) {
		if (!pwr::isComboPowerActive) {
			pwr::isComboPowerActiveChange = true;
		}
		pwr::isComboPowerActive = true;
	}
	else {
		if (pwr::isComboPowerActive) {
			pwr::isComboPowerDeActiveChange = true;
		}
		pwr::isComboPowerActive = false;
	}

	if (pwr::isLargePowerActiveChange) {
		pwr::isLargePowerActiveChange = false;
		levelData.paddle.size.x *= pwr::largeMultiplier;
	}
	if (pwr::isLargePowerDeActiveChange) {
		pwr::isLargePowerDeActiveChange = false;
		levelData.paddle.size.x /= pwr::largeMultiplier;
	}

	if (pwr::isMirrorPowerActiveChange) {
		pwr::isMirrorPowerActiveChange = false;
	}
	if (pwr::isMirrorPowerDeActiveChange) {
		pwr::isMirrorPowerDeActiveChange = false;
	}

	if (pwr::isHomingPowerActiveChange) {
		pwr::isHomingPowerActiveChange = false;
	}
	if (pwr::isHomingPowerDeActiveChange) {
		pwr::isHomingPowerDeActiveChange = false;
	}

	if (pwr::isComboPowerActiveChange) {
		pwr::isComboPowerActiveChange = false;
	}
	if (pwr::isComboPowerDeActiveChange) {
		pwr::isComboPowerDeActiveChange = false;
	}
}
