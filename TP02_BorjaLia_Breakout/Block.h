#pragma once
#include "Utils_Borja.h"
#include "Globals.h"
#include "Paddle.h"
#include "PowerDrop.h"

enum class Stages {
	FULL,
	MEDIUM,
	DEPLETED,
	AMOUNT
};

namespace blk {

	struct Block {

		bool isActive = false;

		int maxHitPoints = 3;
		int currentHitPoints = maxHitPoints;

		bool wasHit = false;
		bool isColliding = false;

		int breakScore = 100;
		int hitScore = 50;

		vec::Vector2 pos = { 0,0 };
		vec::Vector2 offset = { 0,0 };

		vec::Vector2 bounceOffset = { 0,-0.25f };

		vec::Vector2 size = { 0.065,0.045 };

		//Powers

		Power heldPower;

		//color

		Color color = RED;

		//base textures

		rend::SpriteData activeTexture;

		

		//overlay textures
		
		Stages stage = Stages::FULL;
		
		rend::SpriteData activeOverlayTexture;


		//sounds

		bool slAudioInit = false;
		bool raylibAudioInit = false;

		bool playSound = false;

		rend::AudioData activeSound;
	};

	void Init(blk::Block& block);
	void Reset(blk::Block& block);
	void Update(blk::Block& block, pdl::Paddle& paddle);
	void Draw(blk::Block block);
	void Sound(blk::Block& block);

}
