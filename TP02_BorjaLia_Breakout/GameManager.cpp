#include "GameManager.h"

void LoadDefaultFiles()
{
	rend::defaultContainerTexture.file = "res/sprites/Background5.png";

	rend::defaultButtonMainTexture.file = "res/sprites/ButtonTexture.png";
	rend::defaultButtonHoveredTexture.file = "res/sprites/ButtonHoverTexture.png";

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

void BackgroundOverlayColorRandomizer()
{
	unsigned char r = ((32 * rng::GetRandom(1, 7)) - 1);
	unsigned char g = ((32 * rng::GetRandom(1, 7)) - 1);
	unsigned char b = ((32 * rng::GetRandom(1, 7)) - 1);
	unsigned char a = ((16 * rng::GetRandom(1, 5)) - 1);
	bg::backgroundOverlayColor = {r,g,b,a};

	fg::mainTitlesColor.a = 240 - bg::backgroundOverlayColor.a;
	fg::mainTitlesColor.r = bg::backgroundOverlayColor.r * 1.05f;
	fg::mainTitlesColor.g = bg::backgroundOverlayColor.g * 1.05f;
	fg::mainTitlesColor.b = bg::backgroundOverlayColor.b * 1.05f;
}

void InitMouse(btn::Button& mouse)
{
	mouse.signalTimerLimit = 0.1f;
	mouse.size = { 0.015,0.03 };
	mouse.offset = { 0.005,-0.01 };
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

void DeInitMouse(btn::Button& mouse)
{
	drw::DeInitSpriteData(mouse.mainTexture);
	drw::DeInitSpriteData(mouse.hoveredTexture);
}

void MouseUpdate(btn::Button& mouse)
{
	mouse.pos = rend::mousePos;
	btn::UpdateInput(mouse);
}

void MouseDraw(btn::Button mouse)
{
	btn::Draw(mouse);
}
