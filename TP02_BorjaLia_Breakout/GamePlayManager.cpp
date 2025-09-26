#include "GamePlayManager.h"

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
		pwr::Update(levelData.powerDrops[i], levelData.paddle.pos, levelData.paddle.size);
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
		drw::Text("L!", rend::defaultFont, { 0.8f,0.965f }, 50);
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
