#include "Block.h"

void blk::Init(blk::Block& block)
{

	//block.normalTexture.file = "res/sprites/buttonHoverTexture.png";
	//block.largeTexture.file = "res/sprites/buttonHoverTexture.png";
	//block.smallTexture.file = "res/sprites/buttonHoverTexture.png";
	//block.fastTexture.file = "res/sprites/buttonHoverTexture.png";
	//block.slowTexture.file = "res/sprites/buttonHoverTexture.png";
	//block.mirrorTexture.file = "res/sprites/buttonHoverTexture.png";

	//drw::InitSpriteData(block.normalTexture);
	//drw::InitSpriteData(block.largeTexture);
	//drw::InitSpriteData(block.smallTexture);
	//drw::InitSpriteData(block.fastTexture);
	//drw::InitSpriteData(block.slowTexture);
	//drw::InitSpriteData(block.mirrorTexture);

	//block.activeTexture = block.normalTexture;

	//block.fullTexture.file = "res/sprites/buttonHoverTexture.png";
	//block.mediumTexture.file = "res/sprites/buttonHoverTexture.png";
	//block.depletedTexture.file = "res/sprites/buttonHoverTexture.png";

	//drw::InitSpriteData(block.fullTexture);
	//drw::InitSpriteData(block.mediumTexture);
	//drw::InitSpriteData(block.depletedTexture);

	block.activeOverlayTexture = fullTexture;

	block.activeSound = rend::AudioData();

	block.isActive = true;

	block.currentHitPoints = block.maxHitPoints;
}

void blk::Reset(blk::Block& block)
{
	block.isActive = true;

	block.pos = {0.5,0.5};

	block.activeTexture = normalTexture;
	block.activeOverlayTexture = fullTexture;

	block.currentHitPoints = block.maxHitPoints;
}

void blk::Update(blk::Block& block, pdl::Paddle& paddle)
{
	if (!block.isActive) {
		return;
	}
	if (block.wasHit && !block.isColliding) {
		block.wasHit = false;
		block.currentHitPoints--;

		switch (block.stage)
		{
		case Stages::FULL: {
			block.stage = Stages::MEDIUM;
			block.activeOverlayTexture = mediumTexture;
			break;
		}
		case Stages::MEDIUM: {
			block.stage = Stages::DEPLETED;
			block.activeOverlayTexture = depletedTexture;
			break;
		}
		default:
			block.stage = Stages::DEPLETED;
			break;
		}

		block.playSound = true;
		block.activeSound = blockHitSound;

		paddle.score += block.hitScore;
	}
	if (block.currentHitPoints == 0) {
		block.playSound = true;
		block.activeSound = blockBrokenSound;
		block.isActive = false;

		paddle.score += block.breakScore;
	}

	switch ((PowerType)block.heldPower.powerType)
	{
	case PowerType::NONE: {
		block.activeTexture = normalTexture;
		break;
	}
	case PowerType::LARGE: {
		block.activeTexture = largeTexture;

		break;
	}
	case PowerType::SMALL: {
		block.activeTexture = smallTexture;

		break;
	}
	case PowerType::FAST: {
		block.activeTexture = fastTexture;

		break;
	}
	case PowerType::SLOW: {
		block.activeTexture = slowTexture;

		break;
	}
	case PowerType::MIRROR: {
		block.activeTexture = mirrorTexture;

		break;
	}
	default:
		break;
	}

}

void blk::Draw(blk::Block block)
{
	if (!block.isActive) {
		return;
	}
	drw::Rectangle(block.pos,block.size,block.color);
	drw::Sprite(block.activeTexture, block.pos, block.size);
	drw::Sprite(block.activeOverlayTexture, block.pos, block.size);
}

void blk::Sound(blk::Block& block)
{
	if (block.playSound) {
		snd::Play(block.activeSound);
		block.playSound = false;
	}
}
