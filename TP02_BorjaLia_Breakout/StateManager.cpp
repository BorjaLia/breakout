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

	rend::activeGraphics = (rend::GraphicsLib)1;
	rend::nextGraphics = rend::activeGraphics;
	rend::OpenWindow(rend::windowSize, gameTitle.c_str());
	snd::StartAudioDevice();

	btn::InitButtonDefaults();

	bool isRunning = true;

	btn::Container mainMenuContainer;

	btn::Button playButton;
	btn::Button settingsButton;
	btn::Button creditsButton;
	btn::Button exitButton;

	btn::Button mainMenuButtons[] = { playButton, settingsButton, creditsButton, exitButton };

	InitMainMenuContext(mainMenuContainer, mainMenuButtons);


	btn::Container levelsContainer;

	btn::Button exitLevelsButton;

	btn::Button levelsButtons[] = { exitLevelsButton };

	InitLevelsContext(levelsContainer, levelsButtons);


	btn::Container settingsContainer;

	btn::Button rendererSettingsButton;
	btn::Button applySettingsButton;
	btn::Button exitSettingsButton;

	btn::Button settingsButtons[] = { rendererSettingsButton, applySettingsButton, exitSettingsButton };

	InitSettingsContext(settingsContainer, settingsButtons);

	btn::Container creditsContainer;

	btn::Button exitCreditsButton;

	btn::Button creditsButtons[] = { exitCreditsButton };

	InitCreditsContext(creditsContainer, creditsButtons);

	rend::AudioData backgroundMusic;
	backgroundMusic.file = "res/audio/BackgroundMusic.wav";

	snd::Init(backgroundMusic);

	snd::Play(backgroundMusic);

	GameStates gameState = GameStates::MAIN_MENU;
	SubMenus subMenu = SubMenus::MAIN;

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

			break;
		}
		case GameStates::PLAYING: {

			break;
		}
		default:
			break;
		}


		//Update


		switch (gameState)
		{
		case GameStates::MAIN_MENU: {

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

				LevelsUpdate(levelsButtons, subMenu, gameState);
				break;
			}
			case SubMenus::CREDTIS: {

				CreditsUpdate(creditsButtons, subMenu);
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
		case GameStates::PLAYING:
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

				btn::Draw(mainMenuContainer, mainMenuButtons, (int)MMButtons::AMOUNT);
				break;
			}
			case SubMenus::SETTINGS: {

				btn::Draw(settingsContainer, settingsButtons, (int)SButtons::AMOUNT);
				break;
			}
			case SubMenus::LEVEL_SELECTOR: {

				btn::Draw(levelsContainer, levelsButtons, (int)LButtons::AMOUNT);
				break;
			}
			case SubMenus::CREDTIS: {

				btn::Draw(creditsContainer, creditsButtons, (int)CButtons::AMOUNT);
				break;
			}
			case SubMenus::EXIT: {

				btn::Draw(mainMenuContainer, mainMenuButtons, (int)MMButtons::AMOUNT);
				break;
			}
			default: {

				break;
			}
			}

			break;
		}
		case GameStates::PLAYING: {

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

			break;
		}
		default: {

			break;
		}
		}
	}
	rend::Close();
}
