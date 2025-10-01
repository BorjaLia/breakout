#include "LevelMenuManager.h"

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
void LevelsDraw(btn::Container& container, btn::Container& gridContainer, btn::Button buttons[], btn::Button gridButtons[])
{
	btn::Draw(container, buttons, (int)LButtons::AMOUNT);
	btn::Draw(gridContainer, gridButtons, (int)Levels::AMOUNT);
	drw::Sprite(bg::defaultBackgroundOverlayTexture, { 0.5f,0.5f }, { 1,1 }, {}, bg::backgroundOverlayColor);

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

		int hiScore = stoi(utl::SearchInFile(levelFile.c_str(), "best_score"));
		int bestTime = stoi(utl::SearchInFile(levelFile.c_str(), "best_time"));

		std::string hiScoreString = "Best Score: ";
		hiScoreString.append(std::to_string(hiScore));

		std::string bestTimeString = "Best Time: ";
		bestTimeString.append(std::to_string((int)bestTime));

		drw::Text(hiScoreString.c_str(), rend::defaultFont, { gridButtons[i].pos.x,gridButtons[i].pos.y - gridButtons[i].size.y }, 40);
		drw::Text(bestTimeString.c_str(), rend::defaultFont, { gridButtons[i].pos.x,gridButtons[i].pos.y - 1.5f * (gridButtons[i].size.y) }, 40);
	}

}
