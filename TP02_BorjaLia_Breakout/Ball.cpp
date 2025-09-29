#include "Ball.h"

void bll::Init(bll::Ball& ball)
{
	ball.normalTexture.file = "res/sprites/mouseTexture.png";

	drw::InitSpriteData(ball.normalTexture);

	ball.activeTexture = ball.normalTexture;

	ball.bounce.file = "res/audio/ButtonClick.wav";

	snd::Init(ball.bounce);

	//bll::Reset(ball);
}

void bll::Reset(bll::Ball& ball)
{
	ball.pos = bll::Ball().pos;
	ball.vel = { 0,1 };

	ball.size = bll::Ball().size;
}

void bll::Input(bll::Ball& ball)
{
	if (ctrl::IsKeyHeldDown(sett::keyUp)) {
		ball.isActive = true;
	}
}

void bll::Update(bll::Ball& ball, pdl::Paddle& paddle, blk::Block blocks[], int blocksAmount)
{
	if (!ball.isActive) {

		ball.vel.normalize();
		ball.vel *= 2;

		if (ball.vel.x < -1) {

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

	vec::Vector2 vel = ball.vel;

	utl::Abs(vel.x);
	utl::Abs(vel.y);

	if (vel.y / vel.x < 1.0f/3.0f) {
		ball.vel.x = 3 * ball.vel.x / vel.x;
		ball.vel.y = ball.vel.y / vel.y;
	}

	if (pwr::isHomingPowerActive) {
		ball.vel.x += (paddle.pos.x - ball.pos.x) * 1/(ball.pos.y-paddle.pos.y);
	}

	if (pwr::isHomingPowerDeActiveChange) {
		ball.vel.y = 5.0f;
	}

	ball.vel.normalize();
	ball.pos += ball.vel * rend::deltaTime;

	if (CheckCollision(ball, paddle.pos, paddle.size)) {

		//ball.vel.x += utl::Clamped(paddle.currentSpeed,-0.15f,0.15f );

		ball.pos.y = paddle.pos.y + (paddle.size.y / 2) + (ball.size.y / 2);
		ball.vel.y = utl::Abs(ball.vel.y);

		float rotationAmount = 300.0f * (paddle.pos.x - ball.pos.x);

		//utl::Clamp(rotationAmount, -25,25);

		ball.vel.rotate(utl::DegreeToRadian(rotationAmount));
	}
	else if (pwr::isMirrorPowerActive) {
		if (CheckCollision(ball, { (1.0f - paddle.pos.x),paddle.pos.y }, paddle.size)) {

			//ball.vel.x += utl::Clamped(paddle.currentSpeed,-0.15f,0.15f );

			ball.pos.y = paddle.pos.y + (paddle.size.y / 2) + (ball.size.y / 2);
			ball.vel.y = utl::Abs(ball.vel.y);

			float rotationAmount = 300.0f * ((1.0f - paddle.pos.x) - ball.pos.x);

			//utl::Clamp(rotationAmount, -25,25);

			ball.vel.rotate(utl::DegreeToRadian(rotationAmount));
		}
	}

	for (int b = 0; b < blocksAmount; b++)
	{
		if (blocks[b].isActive) {

			if (CheckCollision(ball, blocks[b].pos, blocks[b].size)) {

				if (!blocks[b].isColliding) {
					blocks[b].wasHit = true;
				}
				blocks[b].isColliding = true;

				if (ball.pos.y < blocks[b].pos.y && ball.vel.y > 0) {
					ball.vel.y = -utl::Abs(ball.vel.y);
					ball.pos.y = blocks[b].pos.y - (blocks[b].size.y / 2) - ball.size.y;
				}
				else if (ball.pos.y > blocks[b].pos.y && ball.vel.y < 0) {
					ball.vel.y = utl::Abs(ball.vel.y);
					ball.pos.y = blocks[b].pos.y + (blocks[b].size.y / 2) + ball.size.y;
				}
				else if (ball.pos.x < blocks[b].pos.x && ball.vel.x > 0) {
					ball.vel.x = -utl::Abs(ball.vel.x);
					ball.pos.x = blocks[b].pos.x - (blocks[b].size.x / 2) - ball.size.x;
				}
				else if (ball.pos.x > blocks[b].pos.x && ball.vel.x < 0) {
					ball.vel.x = utl::Abs(ball.vel.x);
					ball.pos.x = blocks[b].pos.x + (blocks[b].size.x / 2) + ball.size.x;
				}
			}
			else {
				blocks[b].isColliding = false;
			}
		}
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
		paddle.healthPoints--;
		pdl::Reset(paddle);
		bll:Reset(ball);
		ball.isActive = false;
		if (paddle.healthPoints <= 0) {
			currentScore = -1;
		}
	}
}

void bll::Draw(bll::Ball ball)
{
	drw::Circle(ball.pos, ball.size);
	drw::Sprite(ball.activeTexture, ball.pos, ball.size);

	if (!ball.isActive) {
		//drw::Circle({ ball.pos.x + (ball.vel.x / 50.0f),ball.pos.y + (ball.vel.y / 50.0f) }, { 0.0025,0.0025 });
	
		drw::Circle(ball.pos + ball.vel.normalized() * 0.075f, {0.005,0.005});
		drw::Circle(ball.pos + ball.vel.normalized() * 0.05f, {0.004,0.004});
		drw::Circle(ball.pos + ball.vel.normalized() * 0.025f, {0.003,0.003});
	}
}

void bll::Sound(bll::Ball ball)
{
	snd::Play(ball.bounce);
}

bool bll::CheckCollision(bll::Ball ball, vec::Vector2 pos, vec::Vector2 size)
{
	if (!(ball.pos.x - ball.size.x / 2 < pos.x + size.x / 2 && ball.pos.x + ball.size.x / 2 > pos.x - size.x / 2)) {
		return false;
	}
	if (!(ball.pos.y - ball.size.y / 2 < pos.y + size.y / 2 && ball.pos.y + ball.size.y / 2 > pos.y - size.y / 2)) {
		return false;
	}

	return true;
}
