#include "Ball.h"

void bll::Init(bll::Ball& ball)
{
	ball.normalTexture.file = "res/sprites/mouseTexture.png";

	drw::InitSpriteData(ball.normalTexture);

	ball.activeTexture = ball.normalTexture;

	ball.bounce.file = "res/audio/ButtonClick.wav";

	snd::Init(ball.bounce);

	bll::Reset(ball);
}

void bll::Reset(bll::Ball& ball)
{
	ball.pos = {0.5, 0.07};
	ball.vel = {0,1};

	ball.size = {0.01,0.01};
}

void bll::Input(bll::Ball& ball)
{
	if (ctrl::GetKeyDown(ball.startKey)) {
		ball.isActive = true;
	}
}

void bll::Update(bll::Ball& ball, pdl::Paddle paddle)
{
	if (!ball.isActive) {

		ball.vel.normalize();
		ball.vel *= 2;

		if (ball.vel.x  < -1) {

			ball.rotationDirecton = -1;
		}
		else if (ball.vel.x > 1) {

			ball.rotationDirecton = 1;
		}
		ball.vel.rotate(ball.rotationDirecton * rend::deltaTime);

		ball.pos = paddle.pos;
		ball.pos.y += paddle.size.y;
		return;
	}
	ball.vel.normalize();

	ball.pos += ball.vel * rend::deltaTime;

	if (CheckCollision(ball, paddle.pos, paddle.size)) {
		ball.pos.y = paddle.pos.y + (paddle.size.y / 2) + (ball.size.y / 2);
		ball.vel.y = utl::Abs(ball.vel.y);
	}

	if (ball.pos.x + ball.size.x > 1 && ball.vel.x > 0) {
		ball.pos.x = 1;
		ball.vel.x *= -1;
	}
	if (ball.pos.x - ball.size.x < 0 && ball.vel.x < 0) {
		ball.pos.x = 0;
		ball.vel.x *= -1;
	}
	if (ball.pos.y + ball.size.y > 1 && ball.vel.y > 0) {
		ball.pos.y = 1;
		ball.vel.y *= -1;
	}
	if (ball.pos.y - ball.size.y < -0.1) {
		ball.vel.y = utl::Abs(ball.vel.y);
	}
}

void bll::Draw(bll::Ball ball)
{
	drw::Circle(ball.pos,ball.size);
	drw::Sprite(ball.activeTexture,ball.pos,ball.size);

	if (!ball.isActive) {
		//drw::Rectangle({ ball.pos.x + (ball.vel.x / 50.0f),ball.pos.y + (ball.vel.y / 50.0f) }, { 0.1,0.1 });
		drw::Circle({ ball.pos.x + (ball.vel.x / 50.0f),ball.pos.y + (ball.vel.y / 50.0f) }, { 0.01,0.01 });
	}
}

void bll::Sound(bll::Ball ball)
{
	snd::Play(ball.bounce);
}

bool bll::CheckCollision(bll::Ball ball, vec::Vector2 pos, vec::Vector2 size)
{
	if (!(ball.pos.x - ball.size.x/2 < pos.x + size.x / 2 && ball.pos.x + ball.size.x / 2 > pos.x - size.x / 2)) {
		return false;
	}
	if (!(ball.pos.y - ball.size.y / 2 < pos.y + size.y / 2 && ball.pos.y + ball.size.y / 2 > pos.y - size.y / 2)) {
		return false;
	}

	return true;
}
