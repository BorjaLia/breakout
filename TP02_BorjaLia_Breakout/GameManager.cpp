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

	mouse.clickedDownSound = rend::defaultButtonClickDownSound;
	mouse.clickedUpSound = rend::defaultButtonClickUpSound;
	mouse.hoveredSound = rend::defaultButtonHoverSound;

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


	buttons[(int)MMButtons::PLAY].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)MMButtons::PLAY].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)MMButtons::PLAY].hoveredSound = rend::defaultButtonHoverSound;

	btn::Init(buttons[(int)MMButtons::PLAY], container, true);

	buttons[(int)MMButtons::PLAY].mainTexture.file = "res/sprites/playButtonTexture.png";
	buttons[(int)MMButtons::PLAY].hoveredTexture.file = "res/sprites/playButtonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)MMButtons::PLAY].mainTexture);
	drw::InitSpriteData(buttons[(int)MMButtons::PLAY].hoveredTexture);

	buttons[(int)MMButtons::SETTINGS].text = "Settings";
	buttons[(int)MMButtons::SETTINGS].pos = { 0.1,0.5 };


	buttons[(int)MMButtons::SETTINGS].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)MMButtons::SETTINGS].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)MMButtons::SETTINGS].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(buttons[(int)MMButtons::SETTINGS], container, true);

	buttons[(int)MMButtons::SETTINGS].mainTexture.file = "res/sprites/settingsButtonTexture.png";
	buttons[(int)MMButtons::SETTINGS].hoveredTexture.file = "res/sprites/settingsButtonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)MMButtons::SETTINGS].mainTexture);
	drw::InitSpriteData(buttons[(int)MMButtons::SETTINGS].hoveredTexture);



	buttons[(int)MMButtons::CREDITS].text = "Credits";
	buttons[(int)MMButtons::CREDITS].pos = { 0.1,0.35 };


	buttons[(int)MMButtons::CREDITS].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)MMButtons::CREDITS].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)MMButtons::CREDITS].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(buttons[(int)MMButtons::CREDITS], container, true);

	buttons[(int)MMButtons::CREDITS].mainTexture.file = "res/sprites/creditsButtonTexture.png";
	buttons[(int)MMButtons::CREDITS].hoveredTexture.file = "res/sprites/creditsButtonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)MMButtons::CREDITS].mainTexture);
	drw::InitSpriteData(buttons[(int)MMButtons::CREDITS].hoveredTexture);



	buttons[(int)MMButtons::EXIT].text = "Exit";
	buttons[(int)MMButtons::EXIT].pos = { 0.1,0.2 };


	buttons[(int)MMButtons::EXIT].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)MMButtons::EXIT].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)MMButtons::EXIT].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(buttons[(int)MMButtons::EXIT], container, true);

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


	buttons[(int)SButtons::RENDERER].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)SButtons::RENDERER].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)SButtons::RENDERER].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(buttons[(int)SButtons::RENDERER], container, true);

	buttons[(int)SButtons::RENDERER].mainTexture.file = "res/sprites/buttonTexture.png";
	buttons[(int)SButtons::RENDERER].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)SButtons::RENDERER].mainTexture);
	drw::InitSpriteData(buttons[(int)SButtons::RENDERER].hoveredTexture);


	buttons[(int)SButtons::APPLY].text = "Apply";
	buttons[(int)SButtons::APPLY].pos = { 0.9,0.2 };
	buttons[(int)SButtons::APPLY].clickedOffset = { 0.4,0 };
	buttons[(int)SButtons::APPLY].useText = true;
	buttons[(int)SButtons::APPLY].textColor = WHITE;


	buttons[(int)SButtons::APPLY].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)SButtons::APPLY].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)SButtons::APPLY].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(buttons[(int)SButtons::APPLY], container, true);

	buttons[(int)SButtons::APPLY].mainTexture.file = "res/sprites/applyButtonTexture.png";
	buttons[(int)SButtons::APPLY].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)SButtons::APPLY].mainTexture);
	drw::InitSpriteData(buttons[(int)SButtons::APPLY].hoveredTexture);


	buttons[(int)SButtons::EXIT].text = "Exit";
	buttons[(int)SButtons::EXIT].pos = { 0.1,0.2 };


	buttons[(int)SButtons::EXIT].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)SButtons::EXIT].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)SButtons::EXIT].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(buttons[(int)SButtons::EXIT], container, true);

	buttons[(int)SButtons::EXIT].mainTexture.file = "res/sprites/exitButtonTexture.png";
	buttons[(int)SButtons::EXIT].hoveredTexture.file = "res/sprites/exitButtonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)SButtons::EXIT].mainTexture);
	drw::InitSpriteData(buttons[(int)SButtons::EXIT].hoveredTexture);
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
		buttons[b].useText = false;
		buttons[b].useSprite = true;
		buttons[b].isActive = true;
	}

	buttons[(int)EButtons::NEXT].text = ">";
	buttons[(int)EButtons::NEXT].pos = { 0.8,0.5 };
	buttons[(int)EButtons::NEXT].size = { 0.15,0.1 };
	buttons[(int)EButtons::NEXT].clickedOffset = { 0,-0.1f };
	buttons[(int)EButtons::NEXT].useText = true;
	buttons[(int)EButtons::NEXT].textColor = WHITE;


	buttons[(int)EButtons::NEXT].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)EButtons::NEXT].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)EButtons::NEXT].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(buttons[(int)EButtons::NEXT], container, true);

	buttons[(int)EButtons::NEXT].mainTexture.file = "res/sprites/buttonTexture.png";
	buttons[(int)EButtons::NEXT].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)EButtons::NEXT].mainTexture);
	drw::InitSpriteData(buttons[(int)EButtons::NEXT].hoveredTexture);

	buttons[(int)EButtons::LAST].text = "<";
	buttons[(int)EButtons::LAST].pos = { 0.2,0.5 };
	buttons[(int)EButtons::LAST].size = { 0.15,0.1 };
	buttons[(int)EButtons::LAST].clickedOffset = { 0,-0.1f };
	buttons[(int)EButtons::LAST].useText = true;
	buttons[(int)EButtons::LAST].textColor = WHITE;


	buttons[(int)EButtons::LAST].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)EButtons::LAST].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)EButtons::LAST].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(buttons[(int)EButtons::LAST], container, true);

	buttons[(int)EButtons::LAST].mainTexture.file = "res/sprites/buttonTexture.png";
	buttons[(int)EButtons::LAST].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)EButtons::LAST].mainTexture);
	drw::InitSpriteData(buttons[(int)EButtons::LAST].hoveredTexture);

	buttons[(int)EButtons::RETRY].text = "Retry";
	buttons[(int)EButtons::RETRY].pos = { 0.5,0.5 };
	buttons[(int)EButtons::RETRY].clickedOffset = { 0,-0.1f };
	buttons[(int)EButtons::RETRY].useText = true;
	buttons[(int)EButtons::RETRY].textColor = WHITE;


	buttons[(int)EButtons::RETRY].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)EButtons::RETRY].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)EButtons::RETRY].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(buttons[(int)EButtons::RETRY], container, true);

	buttons[(int)EButtons::RETRY].mainTexture.file = "res/sprites/buttonTexture.png";
	buttons[(int)EButtons::RETRY].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)EButtons::RETRY].mainTexture);
	drw::InitSpriteData(buttons[(int)EButtons::RETRY].hoveredTexture);

	buttons[(int)EButtons::EXIT].text = "Exit";
	buttons[(int)EButtons::EXIT].pos = { 0.5,0.25 };
	buttons[(int)EButtons::EXIT].clickedOffset = { 0,-0.1f };
	buttons[(int)EButtons::EXIT].useText = true;
	buttons[(int)EButtons::EXIT].textColor = WHITE;


	buttons[(int)EButtons::EXIT].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)EButtons::EXIT].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)EButtons::EXIT].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(buttons[(int)EButtons::EXIT], container, true);

	buttons[(int)EButtons::EXIT].mainTexture.file = "res/sprites/buttonTexture.png";
	buttons[(int)EButtons::EXIT].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(buttons[(int)EButtons::EXIT].mainTexture);
	drw::InitSpriteData(buttons[(int)EButtons::EXIT].hoveredTexture);

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


	buttons[(int)CButtons::EXIT].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)CButtons::EXIT].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)CButtons::EXIT].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(buttons[(int)CButtons::EXIT], container, true);

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
	gridContainer.color = { 128,128,128,128 };

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


	buttons[(int)LButtons::EXIT].clickedUpSound = rend::defaultButtonClickUpSound;
	buttons[(int)LButtons::EXIT].clickedDownSound = rend::defaultButtonClickDownSound;
	buttons[(int)LButtons::EXIT].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(buttons[(int)LButtons::EXIT], container, true);

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


	gridButtons[(int)Levels::LEVEL1].clickedUpSound = rend::defaultButtonClickUpSound;
	gridButtons[(int)Levels::LEVEL1].clickedDownSound = rend::defaultButtonClickDownSound;
	gridButtons[(int)Levels::LEVEL1].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(gridButtons[(int)Levels::LEVEL1], gridContainer, true);

	gridButtons[(int)Levels::LEVEL1].mainTexture.file = "res/sprites/buttonTexture.png";
	gridButtons[(int)Levels::LEVEL1].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL1].mainTexture);
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL1].hoveredTexture);


	gridButtons[(int)Levels::LEVEL2].text = "Level 2";
	gridButtons[(int)Levels::LEVEL2].pos = { 0.8,0.8 };


	gridButtons[(int)Levels::LEVEL2].clickedUpSound = rend::defaultButtonClickUpSound;
	gridButtons[(int)Levels::LEVEL2].clickedDownSound = rend::defaultButtonClickDownSound;
	gridButtons[(int)Levels::LEVEL2].hoveredSound = rend::defaultButtonHoverSound;

	btn::Init(gridButtons[(int)Levels::LEVEL2], gridContainer, true);

	gridButtons[(int)Levels::LEVEL2].mainTexture.file = "res/sprites/buttonTexture.png";
	gridButtons[(int)Levels::LEVEL2].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL2].mainTexture);
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL2].hoveredTexture);

	gridButtons[(int)Levels::LEVEL3].text = "Level 3";
	gridButtons[(int)Levels::LEVEL3].pos = { 0.2,0.2 };


	gridButtons[(int)Levels::LEVEL3].clickedUpSound = rend::defaultButtonClickUpSound;
	gridButtons[(int)Levels::LEVEL3].clickedDownSound = rend::defaultButtonClickDownSound;
	gridButtons[(int)Levels::LEVEL3].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(gridButtons[(int)Levels::LEVEL3], gridContainer, true);

	gridButtons[(int)Levels::LEVEL3].mainTexture.file = "res/sprites/buttonTexture.png";
	gridButtons[(int)Levels::LEVEL3].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL3].mainTexture);
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL3].hoveredTexture);


	gridButtons[(int)Levels::LEVEL4].text = "Level 4";
	gridButtons[(int)Levels::LEVEL4].pos = { 0.8,0.2 };


	gridButtons[(int)Levels::LEVEL4].clickedUpSound = rend::defaultButtonClickUpSound;
	gridButtons[(int)Levels::LEVEL4].clickedDownSound = rend::defaultButtonClickDownSound;
	gridButtons[(int)Levels::LEVEL4].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(gridButtons[(int)Levels::LEVEL4], gridContainer, true);

	gridButtons[(int)Levels::LEVEL4].mainTexture.file = "res/sprites/buttonTexture.png";
	gridButtons[(int)Levels::LEVEL4].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL4].mainTexture);
	drw::InitSpriteData(gridButtons[(int)Levels::LEVEL4].hoveredTexture);
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
	}

	playButtons[(int)PButtons::PAUSE].text = "| |";
	playButtons[(int)PButtons::PAUSE].fontSize *= 0.75f;
	playButtons[(int)PButtons::PAUSE].pos = { 0.5,0.925 };
	playButtons[(int)PButtons::PAUSE].size = { 0.05,0.075 };


	playButtons[(int)PButtons::PAUSE].clickedUpSound = rend::defaultButtonClickUpSound;
	playButtons[(int)PButtons::PAUSE].clickedDownSound = rend::defaultButtonClickDownSound;
	playButtons[(int)PButtons::PAUSE].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(playButtons[(int)PButtons::PAUSE], playContainer, true);

	playButtons[(int)PButtons::PAUSE].mainTexture.file = "res/sprites/buttonTexture.png";
	playButtons[(int)PButtons::PAUSE].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(playButtons[(int)PButtons::PAUSE].mainTexture);
	drw::InitSpriteData(playButtons[(int)PButtons::PAUSE].hoveredTexture);

	playButtons[(int)PButtons::RETURN].text = "Return";
	playButtons[(int)PButtons::RETURN].pos = { 0.5,0.6 };


	playButtons[(int)PButtons::RETURN].clickedUpSound = rend::defaultButtonClickUpSound;
	playButtons[(int)PButtons::RETURN].clickedDownSound = rend::defaultButtonClickDownSound;
	playButtons[(int)PButtons::RETURN].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(playButtons[(int)PButtons::RETURN], playContainer, true);

	playButtons[(int)PButtons::RETURN].mainTexture.file = "res/sprites/buttonTexture.png";
	playButtons[(int)PButtons::RETURN].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(playButtons[(int)PButtons::RETURN].mainTexture);
	drw::InitSpriteData(playButtons[(int)PButtons::RETURN].hoveredTexture);


	playButtons[(int)PButtons::RETRY].text = "Retry";
	playButtons[(int)PButtons::RETRY].pos = { 0.5,0.4 };


	playButtons[(int)PButtons::RETRY].clickedUpSound = rend::defaultButtonClickUpSound;
	playButtons[(int)PButtons::RETRY].clickedDownSound = rend::defaultButtonClickDownSound;
	playButtons[(int)PButtons::RETRY].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(playButtons[(int)PButtons::RETRY], playContainer, true);

	playButtons[(int)PButtons::RETRY].mainTexture.file = "res/sprites/buttonTexture.png";
	playButtons[(int)PButtons::RETRY].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(playButtons[(int)PButtons::RETRY].mainTexture);
	drw::InitSpriteData(playButtons[(int)PButtons::RETRY].hoveredTexture);

	playButtons[(int)PButtons::EXIT].text = "Exit";
	playButtons[(int)PButtons::EXIT].pos = { 0.5,0.2 };


	playButtons[(int)PButtons::EXIT].clickedUpSound = rend::defaultButtonClickUpSound;
	playButtons[(int)PButtons::EXIT].clickedDownSound = rend::defaultButtonClickDownSound;
	playButtons[(int)PButtons::EXIT].hoveredSound = rend::defaultButtonHoverSound;
	
	btn::Init(playButtons[(int)PButtons::EXIT], playContainer, true);

	playButtons[(int)PButtons::EXIT].mainTexture.file = "res/sprites/buttonTexture.png";
	playButtons[(int)PButtons::EXIT].hoveredTexture.file = "res/sprites/buttonHoverTexture.png";
	drw::InitSpriteData(playButtons[(int)PButtons::EXIT].mainTexture);
	drw::InitSpriteData(playButtons[(int)PButtons::EXIT].hoveredTexture);

	blk::normalTexture.file = "res/sprites/BrickTexture.png";
	blk::largeTexture.file = "res/sprites/BrickTexture.png";
	blk::smallTexture.file = "res/sprites/BrickTexture.png";
	blk::fastTexture.file = "res/sprites/BrickTexture.png";
	blk::slowTexture.file = "res/sprites/BrickTexture.png";
	blk::mirrorTexture.file = "res/sprites/BrickTexture.png";

	drw::InitSpriteData(blk::normalTexture);
	drw::InitSpriteData(blk::largeTexture);
	drw::InitSpriteData(blk::smallTexture);
	drw::InitSpriteData(blk::fastTexture);
	drw::InitSpriteData(blk::slowTexture);
	drw::InitSpriteData(blk::mirrorTexture);

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
		blk::Update(levelData.blocks[i], levelData.paddle);
	}

	if (currentScore != -1) {
		currentScore = levelData.paddle.score;
	}
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
		LoadLevel(activeLevel);
	}
	if (playButtons[(int)PButtons::EXIT].signal) {
		isGamePaused = false;
		subMenu = SubMenus::MAIN;
		gameState = GameStates::MAIN_MENU;
	}

	if (lvl::BlocksLeft(activeLevel) <= 0) {
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
		drw::Text("You lost!", rend::defaultFont, {0.5f,0.65f}, 60);
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

	btn::Draw(playButtons, (int)PButtons::AMOUNT);
	std::string score = "Score: ";
	drw::Text((score.append(std::to_string(levelData.paddle.score))).c_str(), rend::defaultFont, { 0.1f,0.965f }, 50);
	std::string hp = "Hp: ";
	drw::Text((hp.append(std::to_string(levelData.paddle.healthPoints))).c_str(), rend::defaultFont, { 0.3f,0.965f }, 50);

	std::string timer = "Time: ";
	drw::Text((timer.append(std::to_string((int)levelTimer))).c_str(), rend::defaultFont, { 0.6f,0.965f }, 50);

	//drw::Text(score.c_str(), rend::defaultFont, { 0.05f,0.95f }, 50);
	//drw::Text(std::to_string(levelData.paddle.score).c_str(), rend::defaultFont, { 0.1f,0.95f }, 50);
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

	levelData.blockAmount = 0;
	int m = 0;

	switch ((Levels)(currentLevel - 1))
	{
	case Levels::LEVEL1: {


		levelData.paddle = pdl::Paddle();
		levelData.ball = bll::Ball();

		levelData.blockAmount = 24;

		for (int i = 0; i < 24; i++)
		{
			if (m >= 8) {
				m = 0;
			}

			levelData.blocks[i].color = WHITE;
			levelData.blocks[i].pos = { 0.5f + ((float)((m - 8 / 2) * levelData.blocks[i].size.x) * 1.5f), 0.6f };
			levelData.blocks[i].pos.x += levelData.blocks[i].size.x / 1.33f;

			if (i >= 8) {
				levelData.blocks[i].pos.y += 0.15f;
			}
			if (i >= 16) {
				levelData.blocks[i].pos.y += 0.15f;
			}
			m++;
		}

		break;
	}
	case Levels::LEVEL2: {
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

		levelData.paddle = pdl::Paddle();
		levelData.ball = bll::Ball();

		levelData.blockAmount = 1;

		levelData.blocks[0].pos = { 0.5,0.5 };
		levelData.blocks[0].size = { 0.3,0.2 };
		levelData.blocks[0].maxHitPoints = 1;


		break;
	}
	case Levels::LEVEL4: {

		break;
	}
	case Levels::AMOUNT:
		break;
	default:
		break;
	}
	InitLevel(levelData);

	levelTimer = 0;
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