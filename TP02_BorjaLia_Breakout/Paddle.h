#pragma once
#include "Globals.h"

namespace pdl {

	struct Paddle {

		// gameplay
		int healthPoints = 3;

		int score = 0;

		//positions
		vec::Vector2 pos = { 0.5,0.05 };
		float currentSpeed = 0;
		float defaultSpeed = 1;

		vec::Vector2 bounceOffset = { 0,-0.25f };

		vec::Vector2 size = { 0.15,0.025 };

		//Controls

		ctrl::Key rightKey = ctrl::Key::D;
		ctrl::Key leftKey = ctrl::Key::A;

		//textures

		rend::SpriteData activeTexture;

		rend::SpriteData normalTexture;
		rend::SpriteData largeTexture;
		rend::SpriteData smallTexture;
		rend::SpriteData fastTexture;
		rend::SpriteData slowTexture;
		rend::SpriteData mirrorTexture;

		//sounds

		bool slAudioInit = false;
		bool raylibAudioInit = false;

		rend::AudioData bounce;
		rend::AudioData powerUp;
		rend::AudioData powerDown;
	};

	void Init(pdl::Paddle& paddle);
	void Reset(pdl::Paddle& paddle);
	void Input(pdl::Paddle& paddle);
	void Update(pdl::Paddle& paddle);
	void Draw(pdl::Paddle paddle);
	void Sound(pdl::Paddle paddle);

}