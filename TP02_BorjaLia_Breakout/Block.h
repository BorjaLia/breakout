#pragma once
#include "Utils_Borja.h"
#include "PowerDrop.h"

namespace blk {

	struct Block {

		int maxHitPoints = 3;
		int currentHitPoints = maxHitPoints;

		int breakScore = 100;
		int hitScore = 50;

		vec::Vector2 pos = { 0,0 };
		vec::Vector2 offset = { 0,0 };

		vec::Vector2 bounceOffset = { 0,-0.25f };

		vec::Vector2 size = { 0.2,0.05 };

		//Powers

		Power heldPower;

		//color

		Color color = RED;

		//base textures

		rend::SpriteData activeTexture;

		rend::SpriteData normalTexture;
		rend::SpriteData largeTexture;
		rend::SpriteData smallTexture;
		rend::SpriteData fastTexture;
		rend::SpriteData slowTexture;
		rend::SpriteData mirrorTexture;

		//overlay textures
		rend::SpriteData activeOverlayTexture;

		rend::SpriteData fullTexture;
		rend::SpriteData mediumTexture;
		rend::SpriteData depletedTexture;

		//sounds

		bool slAudioInit = false;
		bool raylibAudioInit = false;

		rend::AudioData hit;
		rend::AudioData broken;
		rend::AudioData brokenPower;

	};

	void Init(blk::Block& block);
	void Reset(blk::Block& block);
	void Update(blk::Block& block);
	void Draw(blk::Block block);
	void Sound(blk::Block block);

}
