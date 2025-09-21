#include "StateManager.h"

/// <summary>
///		Breakout!
/// 
///		By
///		Borja Lia
///		TP02 Practica de dessarrollo de videojuegos
/// 
/// </summary>

void GameLoop()
{ 
	//Init

	rend::windowSize = { 1920 ,1080 };
	rend::activeGraphics = (rend::GraphicsLib)0;

	LoadSettings();
	LoadDefaultFiles();

	rend::activeGraphics = (rend::GraphicsLib)2;
	rend::nextGraphics = rend::activeGraphics;
	rend::OpenWindow(rend::windowSize, gameTitle.c_str(), isFullscreen);
	snd::StartAudioDevice();

	btn::InitButtonDefaults();

	bool isRunning = true;

	btn::Button mouse;

	InitMouse(mouse);

	btn::Container mainMenuContainer;

	btn::Button playButton;
	btn::Button settingsButton;
	btn::Button creditsButton;
	btn::Button exitButton;

	btn::Button mainMenuButtons[] = { playButton, settingsButton, creditsButton, exitButton };

	InitMainMenuContext(mainMenuContainer, mainMenuButtons);


	btn::Container levelsContainer;
	btn::Container levelsGridContainer;

	btn::Button levelOne;
	btn::Button levelTwo;
	btn::Button levelThree;
	btn::Button levelFour;
	btn::Button exitLevelsButton;

	btn::Button levelsButtons[] = { exitLevelsButton };
	btn::Button levelsGridButtons[] = { levelOne,levelTwo,levelThree,levelFour };

	InitLevelsContext(levelsContainer, levelsGridContainer, levelsButtons, levelsGridButtons);

	btn::Container settingsContainer;

	btn::Button rendererSettingsButton;
	btn::Button applySettingsButton;
	btn::Button exitSettingsButton;

	btn::Button settingsButtons[] = { rendererSettingsButton, applySettingsButton, exitSettingsButton };

	InitSettingsContext(settingsContainer, settingsButtons);

	btn::Container endScreenContainer;

	btn::Button nextEndScreenButton;
	btn::Button lastEndScreenButton;
	btn::Button retryEndScreenButton;
	btn::Button exitEndScreenButton;

	btn::Button endScreenButtons[] = { nextEndScreenButton,lastEndScreenButton, retryEndScreenButton, exitEndScreenButton };

	InitEndScreenContext(endScreenContainer, endScreenButtons);


	btn::Container creditsContainer;

	btn::Button exitCreditsButton;

	btn::Button creditsButtons[] = { exitCreditsButton };

	InitCreditsContext(creditsContainer, creditsButtons);

	rend::AudioData backgroundMusic;
	backgroundMusic.file = "res/audio/BackgroundMusic.wav";

	snd::Init(backgroundMusic);

	GameStates gameState = GameStates::MAIN_MENU;
	SubMenus subMenu = SubMenus::MAIN;


	btn::Container playContainer;

	btn::Button pausePlayButton;
	btn::Button returnPlayButton;
	btn::Button retryPlayButton;
	btn::Button exitPlayButton;

	btn::Button playButtons[] = { pausePlayButton ,returnPlayButton,retryPlayButton ,exitPlayButton };

	lvl::LevelData activeLevel;

	//pdl::Paddle paddle;
	//bll::Ball ball;
	//blk::Block block;
	//blk::Block blocks[] = {block};
	int blocksAmount = 1;

	LoadLevel(activeLevel);

	InitPlayContext(playContainer,playButtons);

	while (isRunning) {

		//systems update
		isRunning = !rend::ShouldExit();

		if (rend::activeGraphics != rend::nextGraphics) {
			//btn::DeInitButtonDefaults();
			rend::Close();
			rend::activeGraphics = rend::nextGraphics;
			rend::OpenWindow(rend::windowSize, gameTitle.c_str());
			//btn::InitButtonDefaults();
		}

		rend::deltaTime = rend::GetDeltaTime();

		rend::windowSize = rend::GetWindowSize();
		rend::mousePos = rend::GetMousePos();

		BackgroundMusicManager(backgroundMusic);

		//Inputs

		if (ctrl::GetKeyDown(ctrl::Key::F1)) {
			devMode = !devMode;
		}

		if (devMode) {
			if (ctrl::GetKeyDown(ctrl::Key::F2)) {
				rend::ChangeRenderer();
			}
		}

		switch (gameState)
		{
		case GameStates::MAIN_MENU: {

			MouseUpdate(mouse);

			switch (subMenu)
			{
			case SubMenus::MAIN: {

				MainMenuUpdate(mainMenuButtons, subMenu);
				break;
			}
			case SubMenus::SETTINGS: {

				SettingsUpdate(settingsButtons, subMenu);
				break;
			}
			case SubMenus::LEVEL_SELECTOR: {

				LevelsUpdate(levelsContainer, levelsGridContainer, levelsButtons, levelsGridButtons, subMenu, gameState);

				if (gameState == GameStates::PLAYING) {
					LoadLevel(activeLevel);
				}
				break;
			}
			case SubMenus::CREDTIS: {

				CreditsUpdate(creditsButtons, subMenu);
				break;
			}
			case SubMenus::ENDSCREEN: {

				EndScreenUpdate(endScreenButtons, subMenu,gameState,activeLevel);
				break;
			}
			case SubMenus::EXIT: {

				isRunning = false;

				break;
			}
			default: {

				break;
			}
			}

			break;
		}
		case GameStates::PLAYING: {

			PlayInputUpdate(activeLevel);

			break;
		}
		default:
			break;
		}


		//Update


		switch (gameState)
		{
		case GameStates::MAIN_MENU: {

			break;
		}
		case GameStates::PLAYING:
			PlayUpdate(playContainer, playButtons, subMenu, gameState,activeLevel);
			break;
		default:
			break;
		}

		//Draw

		drw::Begin();

		drw::Clear(WHITE);

		switch (gameState)
		{
		case GameStates::MAIN_MENU: {

			switch (subMenu)
			{
			case SubMenus::MAIN: {
				MainMenuDraw(mainMenuContainer, mainMenuButtons);
				break;
			}
			case SubMenus::SETTINGS: {
				SettingsDraw(settingsContainer, settingsButtons);
				break;
			}
			case SubMenus::LEVEL_SELECTOR: {
				LevelsDraw(levelsContainer, levelsGridContainer, levelsButtons, levelsGridButtons);
				break;
			}
			case SubMenus::CREDTIS: {
				CreditsDraw(creditsContainer, creditsButtons);
				break;
			}
			case SubMenus::ENDSCREEN: {

				EndScreenDraw(endScreenContainer, endScreenButtons);
				break;
			}
			case SubMenus::EXIT: {
				MainMenuDraw(mainMenuContainer, mainMenuButtons);
				break;
			}
			default: {

				break;
			}
			}

			MouseDraw(mouse);

			break;
		}
		case GameStates::PLAYING: {

			PlayDraw(playContainer, playButtons, activeLevel);

			break;
		}
		default: {

			break;
		}
		}

		drw::End();

		//Sounds

		switch (gameState)
		{
		case GameStates::MAIN_MENU: {

			switch (subMenu)
			{
			case SubMenus::MAIN: {

				btn::Sound(mainMenuButtons, (int)MMButtons::AMOUNT);
				break;
			}
			case SubMenus::SETTINGS: {

				btn::Sound(settingsButtons, (int)SButtons::AMOUNT);
				break;
			}
			case SubMenus::LEVEL_SELECTOR: {

				btn::Sound(levelsButtons, (int)LButtons::AMOUNT);
				break;
			}
			case SubMenus::CREDTIS: {
				btn::Sound(creditsButtons, (int)CButtons::AMOUNT);

				break;
			}
			case SubMenus::EXIT: {

				break;
			}
			default: {

				break;
			}
			}

			break;
		}
		case GameStates::PLAYING: {

			btn::Sound(playButtons, (int)PButtons::AMOUNT);
			PlaySounds(activeLevel);

			break;
		}
		default: {

			break;
		}
		}
	}
	rend::Close();
}
