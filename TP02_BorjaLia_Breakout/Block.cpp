#include "Block.h"

void blk::Init(blk::Block& block)
{
	block.stage = Stages::FULL;

	block.activeTexture = normalTexture;

	block.activeOverlayTexture = blk::fullTexture;

	block.activeSound = blk::blockHitSound;

	block.isActive = true;

	block.currentHitPoints = block.maxHitPoints;
}

void blk::Reset(blk::Block& block)
{
	block.isActive = true;

	block.pos = {0.5,0.5};

	block.activeTexture = blk::normalTexture;

	block.activeOverlayTexture = fullTexture;

	block.currentHitPoints = block.maxHitPoints;
}

void blk::Update(blk::Block& block, pdl::Paddle& paddle,pwr::PowerDrop& powerDrop)
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

		if (pwr::isComboPowerActive) {
			paddle.score += block.breakScore * pwr::comboMultiplier;
		}
		else {
			paddle.score += block.breakScore;
		}

		if (block.heldPowerType != pwr::PowerType::NONE) {
			pwr::Init(powerDrop,block.pos,block.heldPowerType);
			block.heldPowerType = pwr::PowerType();
		}
	}

	switch ((pwr::PowerType)block.heldPowerType)
	{
	case pwr::PowerType::NONE: {
		block.activeTexture = normalTexture;
		break;
	}
	case pwr::PowerType::LARGE: {
		block.activeTexture = largeTexture;
		break;
	}
	case pwr::PowerType::MIRROR: {
		block.activeTexture = mirrorTexture;
		break;
	}
	case pwr::PowerType::HOMING: {
		block.activeTexture = mirrorTexture;
		break;
	}
	case pwr::PowerType::MULTIPLY: {
		block.activeTexture = mirrorTexture;
		break;
	}
	default:
		break;
	}

}

void blk::Draw(blk::Block block)
{
	if (block.isActive) {
	drw::Rectangle(block.pos,block.size,block.color);
	drw::Sprite(block.activeTexture, block.pos, block.size);
	drw::Sprite(block.activeOverlayTexture, block.pos, block.size);
	}
}

void blk::Sound(blk::Block& block)
{
	if (block.playSound) {
		snd::Play(block.activeSound);
		block.playSound = false;
	}
}
