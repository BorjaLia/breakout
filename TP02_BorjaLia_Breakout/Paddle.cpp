#include "Paddle.h"

void pdl::Init(pdl::Paddle& paddle)
{
	paddle.normalTexture.file = "res/sprites/buttonHoverTexture.png";
	paddle.largeTexture.file = "res/sprites/buttonHoverTexture.png";
	paddle.smallTexture.file = "res/sprites/buttonHoverTexture.png";
	paddle.fastTexture.file = "res/sprites/buttonHoverTexture.png";
	paddle.slowTexture.file = "res/sprites/buttonHoverTexture.png";
	paddle.mirrorTexture.file = "res/sprites/buttonHoverTexture.png";

	drw::InitSpriteData(paddle.normalTexture);
	drw::InitSpriteData(paddle.largeTexture);
	drw::InitSpriteData(paddle.smallTexture);
	drw::InitSpriteData(paddle.fastTexture);
	drw::InitSpriteData(paddle.slowTexture);
	drw::InitSpriteData(paddle.mirrorTexture);

	paddle.activeTexture = paddle.normalTexture;

	//pdl::Reset(paddle);
}

void pdl::Reset(pdl::Paddle& paddle)
{
	paddle.pos = pdl::Paddle().pos;
	
	paddle.currentSpeed = 0;
	paddle.defaultSpeed = pdl::Paddle().defaultSpeed;

	paddle.activeTexture = paddle.normalTexture;
}

void pdl::Input(pdl::Paddle& paddle)
{
	paddle.currentSpeed = 0;

	if (ctrl::GetKeyDown(sett::keyLeft)) {
		paddle.currentSpeed -= paddle.defaultSpeed;
	}
	if (ctrl::GetKeyDown(sett::keyRight)) {
		paddle.currentSpeed += paddle.defaultSpeed;
	}
}

void pdl::Update(pdl::Paddle& paddle)
{
	paddle.pos.x += paddle.currentSpeed * rend::deltaTime;

	utl::Clamp(paddle.pos.x,paddle.size.x/2,1-paddle.size.x/2);
}

void pdl::Draw(pdl::Paddle paddle)
{
	//drw::Rectangle(paddle.pos,paddle.size);
	if (pwr::isMirrorPowerActive) {
		Color color = SKYBLUE;
		color.a /= 2;
		drw::Sprite(paddle.activeTexture, { (1.0f - paddle.pos.x) ,paddle.pos.y }, paddle.size, {0,0}, color);
	}
	drw::Sprite(paddle.activeTexture, paddle.pos, paddle.size);
}

void pdl::Sound(pdl::Paddle paddle)
{
	snd::Play(paddle.bounce);
}
