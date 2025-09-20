#include "Block.h"

void blk::Init(blk::Block& block)
{

	block.normalTexture.file = "res/sprites/buttonHoverTexture.png";
	block.largeTexture.file = "res/sprites/buttonHoverTexture.png";
	block.smallTexture.file = "res/sprites/buttonHoverTexture.png";
	block.fastTexture.file = "res/sprites/buttonHoverTexture.png";
	block.slowTexture.file = "res/sprites/buttonHoverTexture.png";
	block.mirrorTexture.file = "res/sprites/buttonHoverTexture.png";

	drw::InitSpriteData(block.normalTexture);
	drw::InitSpriteData(block.largeTexture);
	drw::InitSpriteData(block.smallTexture);
	drw::InitSpriteData(block.fastTexture);
	drw::InitSpriteData(block.slowTexture);
	drw::InitSpriteData(block.mirrorTexture);

	block.activeTexture = block.normalTexture;

	block.fullTexture.file = "res/sprites/buttonHoverTexture.png";
	block.mediumTexture.file = "res/sprites/buttonHoverTexture.png";
	block.depletedTexture.file = "res/sprites/buttonHoverTexture.png";

	drw::InitSpriteData(block.fullTexture);
	drw::InitSpriteData(block.mediumTexture);
	drw::InitSpriteData(block.depletedTexture);

	block.activeOverlayTexture = block.fullTexture;
}

void blk::Reset(blk::Block& block)
{
	block.pos = {0.5,0.5};

	block.activeTexture = block.normalTexture;
	block.activeOverlayTexture = block.fullTexture;

	block.currentHitPoints = block.maxHitPoints;
}

void blk::Update(blk::Block& block)
{
}

void blk::Draw(blk::Block block)
{
	drw::Rectangle(block.pos,block.size,block.color);
}

void blk::Sound(blk::Block block)
{

}
