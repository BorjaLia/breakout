#include "Paddle.h"

void pdl::Init(pdl::Paddle& paddle)
{
	paddle.normalTexture = spr::defaultPaddleTexture;
	paddle.largeTexture = spr::defaultPaddleTexture;
	paddle.smallTexture = spr::defaultPaddleTexture;
	paddle.fastTexture = spr::defaultPaddleTexture;
	paddle.slowTexture = spr::defaultPaddleTexture;
	paddle.mirrorTexture = spr::defaultPaddleTexture;

	paddle.activeTexture = paddle.normalTexture;

	//pdl::Reset(paddle);
}

void pdl::Reset(pdl::Paddle& paddle)
{
	paddle.pos = pdl::Paddle().pos;
	
	paddle.currentSpeed = 0;
	paddle.defaultSpeed = pdl::Paddle().defaultSpeed;

	paddle.activeTexture = paddle.normalTexture;

	paddle.color = WHITE;
	paddle.color.a /= 1.2f;
	paddle.color.r = (paddle.color.r + fg::mainTitlesColor.r) / 2.0f;
	paddle.color.g = (paddle.color.g + fg::mainTitlesColor.g) / 2.0f;
	paddle.color.b = (paddle.color.b + fg::mainTitlesColor.b) / 2.0f;
}

void pdl::Input(pdl::Paddle& paddle)
{
	paddle.currentSpeed = 0;

	if (ctrl::IsKeyHeldDown(sett::keyLeft)) {
		paddle.currentSpeed -= paddle.defaultSpeed;
	}
	if (ctrl::IsKeyHeldDown(sett::keyRight)) {
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
		Color color = paddle.color;
		color.a = (color.a + SKYBLUE.a) / 2.0f;
		color.r = (color.r + SKYBLUE.r) / 2.0f;
		color.g = (color.g + SKYBLUE.g) / 2.0f;
		color.b = (color.b + SKYBLUE.b) / 2.0f;
		drw::Sprite(paddle.activeTexture, { (1.0f - paddle.pos.x) ,paddle.pos.y }, paddle.size, {0,0}, color);
	}
	drw::Sprite(paddle.activeTexture, paddle.pos, paddle.size, {},paddle.color);
}

void pdl::Sound(pdl::Paddle paddle)
{
	snd::Play(paddle.bounce);
}
