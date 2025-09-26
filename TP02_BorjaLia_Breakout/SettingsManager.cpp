#include "SettingsManager.h"

void LoadSettings()
{
	rend::activeGraphics = (rend::GraphicsLib)stoi(utl::SearchInFile(settingsFilePath.c_str(), "graphics"));
	rend::nextGraphics = rend::activeGraphics;

	rend::windowSize.x = stoi(utl::SearchInFile(settingsFilePath.c_str(), "resolution_width"));
	rend::windowSize.y = stoi(utl::SearchInFile(settingsFilePath.c_str(), "resolution_height"));

	isFullscreen = stoi(utl::SearchInFile(settingsFilePath.c_str(), "fullscreen"));

	sett::graphics = rend::activeGraphics;

	sett::fullscreen = isFullscreen;
	sett::resolution = { rend::windowSize.x ,rend::windowSize.y };

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

void SettingsUpdate(btn::Button settingsButtons[], SubMenus& subMenu)
{
	if (sett::changingKeyUp) {

		ctrl::Key chosenKey = GetValidKey();

		if (chosenKey != ctrl::Key::NULL_KEY) {
			utl::SaveToFile(settingsFilePath.c_str(), "key_up", (int)chosenKey);
			sett::keyUp = chosenKey;
			sett::changingKeyUp = false;
			SetControlKeyText(settingsButtons[(int)SButtons::KEY_UP],chosenKey);
		}
		else {
			return;
		}
	}
	if (sett::changingKeyLeft) {

		ctrl::Key chosenKey = GetValidKey();

		if (chosenKey != ctrl::Key::NULL_KEY) {
			utl::SaveToFile(settingsFilePath.c_str(), "key_left", (int)chosenKey);
			sett::keyLeft = chosenKey;
			sett::changingKeyLeft = false;
			SetControlKeyText(settingsButtons[(int)SButtons::KEY_LEFT],chosenKey);
		}
		else {
			return;
		}
	}
	if (sett::changingKeyRight) {

		ctrl::Key chosenKey = GetValidKey();

		if (chosenKey != ctrl::Key::NULL_KEY) {
			utl::SaveToFile(settingsFilePath.c_str(), "key_right", (int)chosenKey);
			sett::keyRight = chosenKey;
			sett::changingKeyRight = false;
			SetControlKeyText(settingsButtons[(int)SButtons::KEY_RIGHT],chosenKey);
		}
		else {
			return;
		}
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

void SettingsDraw(btn::Container settingsContainer, btn::Button settingsButtons[])
{
	btn::Draw(settingsContainer, settingsButtons, (int)SButtons::AMOUNT);
}

ctrl::Key GetValidKey()
{
	ctrl::Key key = ctrl::GetKeyDown();

	if (((int)key > (int)ctrl::Key::A && (int)key < (int)ctrl::Key::Z) || ((int)key > (int)ctrl::Key::RIGHT && (int)key < (int)ctrl::Key::UP)) {
		return key;
	}
	else {
		return ctrl::Key::NULL_KEY;
	}


}

void SetControlKeyText(btn::Button& button, ctrl::Key selectedKey)
{
	if ((int)selectedKey <= (int)ctrl::Key::Z) {
		button.text = (char)selectedKey;
	}
	else {
		switch (selectedKey)
		{
		case ctrl::Key::RIGHT: {

			button.text = ">";
			break;
		}
		case ctrl::Key::LEFT: {

			button.text = "<";
			break;
		}
		case ctrl::Key::DOWN: {

			button.text = "v";
			break;
		}
		case ctrl::Key::UP: {

			button.text = "^";
			break;
		}
		default:
			break;
		}
	}
}