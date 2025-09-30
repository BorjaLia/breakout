#include "MainMenuManager.h"


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
		buttons[b].textData = rend::defaultFont;
		buttons[b].mainTexture = rend::defaultButtonMainTexture;
		buttons[b].hoveredTexture = rend::defaultButtonHoveredTexture;
		buttons[b].clickedDownSound = rend::defaultButtonClickDownSound;
		buttons[b].clickedUpSound = rend::defaultButtonClickUpSound;
		buttons[b].hoveredSound = rend::defaultButtonHoverSound;
	}

	buttons[(int)MMButtons::PLAY].text = "Play";
	buttons[(int)MMButtons::PLAY].pos = { 0.1,0.65 };

	btn::Init(buttons[(int)MMButtons::PLAY], container, true);

	buttons[(int)MMButtons::PLAY].mainTexture = menu::playButtonTexture;
	buttons[(int)MMButtons::PLAY].hoveredTexture = menu::playButtonHoveredTexture;


	buttons[(int)MMButtons::SETTINGS].text = "Settings";
	buttons[(int)MMButtons::SETTINGS].pos = { 0.1,0.5 };

	btn::Init(buttons[(int)MMButtons::SETTINGS], container, true);

	buttons[(int)MMButtons::SETTINGS].mainTexture = menu::settingsButtonTexture;
	buttons[(int)MMButtons::SETTINGS].hoveredTexture = menu::settingsButtonHoveredTexture;


	buttons[(int)MMButtons::CREDITS].text = "Credits";
	buttons[(int)MMButtons::CREDITS].pos = { 0.1,0.35 };

	btn::Init(buttons[(int)MMButtons::CREDITS], container, true);

	buttons[(int)MMButtons::CREDITS].mainTexture = menu::creditsButtonTexture;
	buttons[(int)MMButtons::CREDITS].hoveredTexture = menu::creditsButtonHoveredTexture;


	buttons[(int)MMButtons::EXIT].text = "Exit";
	buttons[(int)MMButtons::EXIT].pos = { 0.1,0.2 };

	btn::Init(buttons[(int)MMButtons::EXIT], container, true);

	buttons[(int)MMButtons::EXIT].mainTexture = menu::exitButtonTexture;
	buttons[(int)MMButtons::EXIT].hoveredTexture = menu::exitButtonHoveredTexture;
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

void MainMenuDraw(btn::Container mainMenuContainer, btn::Button mainMenuButtons[])
{
	btn::Draw(mainMenuContainer, mainMenuButtons, (int)MMButtons::AMOUNT);
	drw::Sprite(bg::defaultBackgroundOverlayTexture, { 0.5f,0.5f }, { 1,1 }, {}, bg::backgroundOverlayColor);

	//drw::Sprite(fg::mainBreakoutText, { 0.5f,0.85f }, { 0.6f,0.3f }, {},mainTitleColor);
	std::string breakoutText = "Breakout!";
	drw::Text(breakoutText.c_str(), rend::defaultFont, { 0.5f,0.8f }, 180, {}, fg::mainTitlesColor);
}