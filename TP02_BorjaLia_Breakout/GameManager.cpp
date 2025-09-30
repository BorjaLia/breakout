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

void InitMouse(btn::Button& mouse)
{
	mouse.signalTimerLimit = 0.1f;
	mouse.size = { 0.03,0.03 };
	mouse.offset = { 0.01,-0.01 };
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
