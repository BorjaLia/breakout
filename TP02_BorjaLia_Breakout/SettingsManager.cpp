#include "SettingsManager.h"

void LoadSettings()
{
	rend::activeGraphics = (rend::GraphicsLib)stoi(utl::SearchInFile(settingsFilePath.c_str(), "graphics"));
	rend::nextGraphics = rend::activeGraphics;

	rend::activeResolution = (rend::Resolution)stoi(utl::SearchInFile(settingsFilePath.c_str(), "resolution"));

	switch (rend::activeResolution)
	{
	case rend::Resolution::MANUAL: {
		rend::windowSize.x = stoi(utl::SearchInFile(settingsFilePath.c_str(), "resolution_width"));
		rend::windowSize.y = stoi(utl::SearchInFile(settingsFilePath.c_str(), "resolution_height"));
		break;
	}
	case rend::Resolution::HD: {
		rend::windowSize = HD_RES;
		break;
	}
	case rend::Resolution::FHD: {
		rend::windowSize = FHD_RES;
		break;
	}
	case rend::Resolution::QHD: {
		rend::windowSize = QHD_RES;
		break;
	}
	case rend::Resolution::UHD: {
		rend::windowSize = UHD_RES;
		break;
	}
	default: {
		rend::windowSize.x = stoi(utl::SearchInFile(settingsFilePath.c_str(), "resolution_width"));
		rend::windowSize.y = stoi(utl::SearchInFile(settingsFilePath.c_str(), "resolution_height"));
		break;
	}
	}

	isFullscreen = stoi(utl::SearchInFile(settingsFilePath.c_str(), "fullscreen"));

	sett::graphics = rend::activeGraphics;

	sett::windowType = (rend::WindowType)isFullscreen;

	sett::resolution = rend::activeResolution;

	sett::usePowers = stoi(utl::SearchInFile(settingsFilePath.c_str(), "use_powers"));

	sett::keyUp = (ctrl::Key)stoi(utl::SearchInFile(settingsFilePath.c_str(), "key_up"));
	sett::keyLeft = (ctrl::Key)stoi(utl::SearchInFile(settingsFilePath.c_str(), "key_left"));;
	sett::keyRight = (ctrl::Key)stoi(utl::SearchInFile(settingsFilePath.c_str(), "key_right"));;

}

void SaveSettings() {
	utl::SaveToFile(settingsFilePath.c_str(), "graphics", (int)sett::graphics);

	utl::SaveToFile(settingsFilePath.c_str(), "fullscreen", (int)sett::windowType);

	utl::SaveToFile(settingsFilePath.c_str(), "resolution", (int)sett::resolution);

	if (rend::activeResolution != rend::Resolution::MANUAL) {
		utl::SaveToFile(settingsFilePath.c_str(), "resolution_width", (int)rend::windowSize.x);
		utl::SaveToFile(settingsFilePath.c_str(), "resolution_height", (int)rend::windowSize.y);
	}

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
		buttons[b].size = { 0.225,0.1 };
		buttons[b].pos = { 0.5,0.55 };
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

	if (isFullscreen) {
		buttons[(int)SButtons::FULLSCREEN].text = "Fullscreen";
	}
	else {
		buttons[(int)SButtons::FULLSCREEN].text = "Windowed";
	}
	buttons[(int)SButtons::FULLSCREEN].pos = { 0.8,0.7 };

	btn::Init(buttons[(int)SButtons::FULLSCREEN], container, true);

	buttons[(int)SButtons::RESOLUTION].text = "Resolution";
	buttons[(int)SButtons::RESOLUTION].pos = { 0.8,0.6 };

	btn::Init(buttons[(int)SButtons::RESOLUTION], container, true);
	switch (sett::resolution)
	{
	case rend::Resolution::MANUAL: {
		buttons[(int)SButtons::RESOLUTION].text = "Manual";
		break;
	}
	case rend::Resolution::HD: {
		buttons[(int)SButtons::RESOLUTION].text = "HD";
		break;
	}
	case rend::Resolution::FHD: {
		buttons[(int)SButtons::RESOLUTION].text = "FHD";
		break;
	}
	case rend::Resolution::QHD: {
		buttons[(int)SButtons::RESOLUTION].text = "QHD";
		break;
	}
	case rend::Resolution::UHD: {
		buttons[(int)SButtons::RESOLUTION].text = "UHD";
		break;
	}
	default:
		break;
	}

	buttons[(int)SButtons::USE_POWERS].text = "Use Powers";
	buttons[(int)SButtons::USE_POWERS].pos = { 0.8,0.5 };

	btn::Init(buttons[(int)SButtons::USE_POWERS], container, true);
	if (sett::usePowers) {
		buttons[(int)SButtons::USE_POWERS].text = "Powers: On";
	}
	else {
		buttons[(int)SButtons::USE_POWERS].text = "Powers: Off";
	}

	buttons[(int)SButtons::KEY_UP].text = "Key up";
	buttons[(int)SButtons::KEY_UP].pos = { 0.3,0.5 };
	buttons[(int)SButtons::KEY_UP].size = { 0.1,0.1 };

	btn::Init(buttons[(int)SButtons::KEY_UP], container, true);
	SetControlKeyText(buttons[(int)SButtons::KEY_UP], sett::keyUp);

	buttons[(int)SButtons::KEY_LEFT].text = "key Left";
	buttons[(int)SButtons::KEY_LEFT].pos = { 0.2,0.4 };
	buttons[(int)SButtons::KEY_LEFT].size = { 0.1,0.1 };

	btn::Init(buttons[(int)SButtons::KEY_LEFT], container, true);
	SetControlKeyText(buttons[(int)SButtons::KEY_LEFT], sett::keyLeft);

	buttons[(int)SButtons::KEY_RIGHT].text = "Key Right";
	buttons[(int)SButtons::KEY_RIGHT].pos = { 0.4,0.4 };
	buttons[(int)SButtons::KEY_RIGHT].size = { 0.1,0.1 };

	btn::Init(buttons[(int)SButtons::KEY_RIGHT], container, true);
	SetControlKeyText(buttons[(int)SButtons::KEY_RIGHT], sett::keyRight);


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
			SetControlKeyText(settingsButtons[(int)SButtons::KEY_UP], chosenKey);
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
			SetControlKeyText(settingsButtons[(int)SButtons::KEY_LEFT], chosenKey);
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
			SetControlKeyText(settingsButtons[(int)SButtons::KEY_RIGHT], chosenKey);
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
			changedSettings = true;
		}
		else {
			changedSettings = false;
		}
	}
	if (settingsButtons[(int)SButtons::FULLSCREEN].signal) {

		switch (sett::windowType)
		{
		case rend::WindowType::WINDOWED: {
			sett::windowType = rend::WindowType::FULLSCREEN;
			settingsButtons[(int)SButtons::FULLSCREEN].text = "Fullscreen";
			break;
		}
		case rend::WindowType::FULLSCREEN: {
			sett::windowType = rend::WindowType::WINDOWED;
			settingsButtons[(int)SButtons::FULLSCREEN].text = "Windowed";
			break;
		}
		default:
			break;
		}

		if ((int)sett::windowType != isFullscreen) {
			changedSettings = true;
		}
		else {
			changedSettings = false;
		}

	}
	if (settingsButtons[(int)SButtons::RESOLUTION].signal) {
		
		switch (sett::resolution)
		{
		case rend::Resolution::MANUAL: {
			sett::resolution = rend::Resolution::HD;
			settingsButtons[(int)SButtons::RESOLUTION].text = "HD";
			break;
		}
		case rend::Resolution::HD: {
			sett::resolution = rend::Resolution::FHD;
			settingsButtons[(int)SButtons::RESOLUTION].text = "FHD";
			break;
		}
		case rend::Resolution::FHD: {
			sett::resolution = rend::Resolution::QHD;
			settingsButtons[(int)SButtons::RESOLUTION].text = "QHD";
			break;
		}
		case rend::Resolution::QHD: {
			sett::resolution = rend::Resolution::UHD;
			settingsButtons[(int)SButtons::RESOLUTION].text = "UHD";
			break;
		}
		case rend::Resolution::UHD: {
			sett::resolution = rend::Resolution::HD;
			settingsButtons[(int)SButtons::RESOLUTION].text = "HD";
			break;
		}
		default:
			break;
		}

		if (sett::resolution != rend::activeResolution) {
			changedSettings = true;
		}
		else {
			changedSettings = false;
		}
	}
	if (settingsButtons[(int)SButtons::USE_POWERS].signal) {
		sett::usePowers = !sett::usePowers;

		if (sett::usePowers) {
			settingsButtons[(int)SButtons::USE_POWERS].text = "Powers: On";
		}
		else {
			settingsButtons[(int)SButtons::USE_POWERS].text = "Powers: Off";
		}
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
		subMenu = SubMenus::MAIN;
	}

	if (settingsButtons[(int)SButtons::EXIT].signal) {
		subMenu = SubMenus::MAIN;
	}
}

void SettingsDraw(btn::Container settingsContainer, btn::Button settingsButtons[])
{
	btn::Draw(settingsContainer, settingsButtons, (int)SButtons::AMOUNT);
	drw::Sprite(bg::defaultBackgroundOverlayTexture, { 0.5f,0.5f }, { 1,1 }, {}, bg::backgroundOverlayColor);
	if (changedSettings) {
		drw::Text("Some settings take effect after a reset!", rend::defaultFont, { 0.5,0.1 }, 50, { 0,0 }, RED);
	}
}

ctrl::Key GetValidKey()
{
	ctrl::Key key = ctrl::GetKeyDown();

	if (((int)key >= (int)ctrl::Key::A && (int)key <= (int)ctrl::Key::Z) || ((int)key >= (int)ctrl::Key::RIGHT && (int)key <= (int)ctrl::Key::UP) || (key == ctrl::Key::LEFT_SHIFT) || (key == ctrl::Key::SPACE)) {
		return key;
	}
	else {
		return ctrl::Key::NULL_KEY;
	}
}

void SetControlKeyText(btn::Button& button, ctrl::Key selectedKey)
{
	if (((int)selectedKey >= (int)ctrl::Key::A && (int)selectedKey <= (int)ctrl::Key::Z)) {
		button.text = (char)selectedKey;
	}
	else {
		switch (selectedKey)
		{
		case ctrl::Key::RIGHT: {

			button.text = "Right";
			break;
		}
		case ctrl::Key::LEFT: {

			button.text = "Left";
			break;
		}
		case ctrl::Key::DOWN: {

			button.text = "Down";
			break;
		}
		case ctrl::Key::UP: {

			button.text = "Up";
			break;
		}
		case ctrl::Key::LEFT_SHIFT: {

			button.text = "LShift";
			break;
		}
		case ctrl::Key::SPACE: {

			button.text = "Space";
			break;
		}
		default:
			break;
		}
	}
}