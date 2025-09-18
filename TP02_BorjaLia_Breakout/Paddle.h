#pragma once
#include "Globals.h"
#include "PowerDrop.h"


namespace paddle {

	struct Paddle {

		//positions
		vec::Vector2 pos = { 0.1,0.5 };

		vec::Vector2 bounceOffset = { 0,-0.25f };

		vec::Vector2 size = { 0.2,0.05 };

		//Controls

		ctrl::Key rightKey = ctrl::Key::D;
		ctrl::Key leftKey = ctrl::Key::A;

		//Powers

		Power activePower;

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

	void Init(paddle::Paddle& paddle);
	void Reset(paddle::Paddle& paddle);
	void Input(paddle::Paddle& paddle);
	void Update(paddle::Paddle& paddle);
	void Draw(paddle::Paddle paddle);
	void Sound(paddle::Paddle paddle);

}