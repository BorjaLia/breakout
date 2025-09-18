#include "Paddle.h"

void paddle::Init(paddle::Paddle& paddle)
{
	paddle.normalTexture.file = "";
	paddle.largeTexture.file = "";
	paddle.smallTexture.file = "";
	paddle.fastTexture.file = "";
	paddle.slowTexture.file = "";
	paddle.mirrorTexture.file = "";

	drw::InitSpriteData(paddle.normalTexture);
	drw::InitSpriteData(paddle.largeTexture);
	drw::InitSpriteData(paddle.smallTexture);
	drw::InitSpriteData(paddle.fastTexture);
	drw::InitSpriteData(paddle.slowTexture);
	drw::InitSpriteData(paddle.mirrorTexture);

	paddle.activeTexture = paddle.normalTexture;
}

void paddle::Reset(paddle::Paddle& paddle)
{
}

void paddle::Input(paddle::Paddle& paddle)
{
}

void paddle::Update(paddle::Paddle& paddle)
{
}

void paddle::Draw(paddle::Paddle paddle)
{
}

void paddle::Sound(paddle::Paddle paddle)
{
}
