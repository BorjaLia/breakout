#pragma once
#include "PowerDrop.h"
#include "Paddle.h"
#include "Block.h"

enum class ColisionSide {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	NONE,
	AMOUNT
};

namespace bll {

	struct Ball {

		//Active

		bool isActive = false;
		int rotationDirecton = 1;

		//positions
		vec::Vector2 pos = { 0.1,0.5 };
		vec::Vector2 vel = { 0,0 };

		vec::Vector2 bounceOffset = { 0,-0.25f };

		vec::Vector2 size = { 0.02,0.02 };

		//Control

		ctrl::Key startKey = ctrl::Key::W;

		//textures

		rend::SpriteData activeTexture;

		rend::SpriteData normalTexture;

		//sounds

		bool slAudioInit = false;
		bool raylibAudioInit = false;

		rend::AudioData bounce;
	};

	void Init(bll::Ball& ball);
	void Reset(bll::Ball& ball);
	void Input(bll::Ball& ball);
	void Update(bll::Ball& ball, pdl::Paddle paddle);
	void Draw(bll::Ball ball);
	void Sound(bll::Ball ball);

	bool CheckCollision(bll::Ball ball, vec::Vector2 pos, vec::Vector2 size);
}