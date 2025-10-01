#include "CreditsManager.h"

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

void CreditsUpdate(btn::Button creditsButtons[], SubMenus& subMenu)
{
	btn::UpdateInput(creditsButtons, (int)CButtons::AMOUNT);

	if (creditsButtons[(int)CButtons::EXIT].signal) {
		subMenu = SubMenus::MAIN;
	}
}

void CreditsDraw(btn::Container creditsContainer, btn::Button creditsButtons[])
{
	btn::Draw(creditsContainer, creditsButtons, (int)CButtons::AMOUNT);
	drw::Sprite(bg::defaultBackgroundOverlayTexture, { 0.5f,0.5f }, { 1,1 }, {}, bg::backgroundOverlayColor);
	drw::Rectangle({ 0.5,0.45 }, { 0.35,0.9 }, fg::mainTitlesColor);
	//drw::Sprite(rend::defaultButtonHoveredTexture, { 0.5,0.25 }, { 0.2,0.6 });
	drw::Text("Made by", rend::defaultFont, { 0.5,0.7 }, 70);
	drw::Text("Borja Lia", rend::defaultFont, { 0.5,0.6 }, 120);
	drw::Text("Special thanks to", rend::defaultFont, { 0.5,0.4 }, 50);
	drw::Text("Sergio Baretto", rend::defaultFont, { 0.5,0.3 }, 40);
	drw::Text("Stefano Cvitanich", rend::defaultFont, { 0.5,0.25 }, 40);
}