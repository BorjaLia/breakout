#include "EndScreenManager.h"

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