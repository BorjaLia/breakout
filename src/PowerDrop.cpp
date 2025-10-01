#include "PowerDrop.h"

void pwr::Init(pwr::PowerDrop& powerDrop, vec::Vector2 pos, PowerType powerType)
{
	powerDrop.isActive = true;

	powerDrop.pos = pos;

	powerDrop.powerType = powerType;

	switch (powerType)
	{
	case pwr::PowerType::NONE:
		powerDrop.isActive = false;
		break;
	case pwr::PowerType::LARGE:
		powerDrop.color = GREEN;
		powerDrop.activeTexture = pwr::largePowerDropTexture;
		break;
	case pwr::PowerType::MIRROR:
		powerDrop.color = SKYBLUE;
		powerDrop.activeTexture = pwr::mirrorPowerDropTexture;
		break;
	case pwr::PowerType::HOMING:
		powerDrop.color = PINK;
		powerDrop.activeTexture = pwr::homingPowerDropTexture;
		break;
	case pwr::PowerType::MULTIPLY:
		powerDrop.color = ORANGE;
		break;
	case pwr::PowerType::COMBO:
		powerDrop.color = DARKPURPLE;
		powerDrop.activeTexture = pwr::comboPowerDropTexture;
		break;
	case pwr::PowerType::AMOUNT:
		break;
	default:
		powerDrop.isActive = false;
		break;
	}

}

void pwr::Reset(pwr::PowerDrop& powerDrop)
{
	powerDrop.isActive = false;

	powerDrop.pos = { 0.5f,0.5f };
	powerDrop.vel = { 0,-1 };

	powerDrop.speed = 0.5f;

	powerDrop.size = { 0.024f,0.0426f };

	powerDrop.powerType = PowerType::NONE;

	powerDrop.color = WHITE;
}

void pwr::Update(pwr::PowerDrop& powerDrop, vec::Vector2 pos, vec::Vector2 size)
{
	if (!sett::usePowers) {
		return;
	}

	if (!powerDrop.isActive) {
		return;
	}
	switch (powerDrop.powerType)
	{
	case pwr::PowerType::NONE:
		powerDrop.isActive = false;
		break;
	case pwr::PowerType::LARGE:
		break;
	case pwr::PowerType::MIRROR:
		break;
	case pwr::PowerType::HOMING:

		powerDrop.vel.rotate(utl::DegreeToRadian(5.0f * rend::deltaTime));
		powerDrop.vel.y -= 0.5f;

		break;
	case pwr::PowerType::MULTIPLY:
		break;
	case pwr::PowerType::COMBO:
		break;
	case pwr::PowerType::AMOUNT:
		break;
	default:
		break;
	}

	powerDrop.vel.normalize();
	powerDrop.pos += powerDrop.vel * powerDrop.speed * rend::deltaTime;

	if (CheckCollision(powerDrop, pos, size)) {
		powerDrop.isActive = false;

		switch (powerDrop.powerType)
		{
		case pwr::PowerType::NONE:
			break;
		case pwr::PowerType::LARGE:
			largePowerTimer = 0;
			break;
		case pwr::PowerType::MIRROR:
			mirrorPowerTimer = 0;
			break;
		case pwr::PowerType::HOMING:
			homingPowerTimer = 0;
			break;
		case pwr::PowerType::MULTIPLY:
			multiplyPowerActivation = true;
			break;
		case pwr::PowerType::COMBO:
			comboPowerTimer = 0;
			break;
		case pwr::PowerType::AMOUNT:
			break;
		default:
			break;
		}
		powerDrop.powerType = PowerType::NONE;
	}
}

void pwr::Draw(pwr::PowerDrop powerDrop)
{
	if (!sett::usePowers) {
		return;
	}
	if (powerDrop.isActive) {
		//drw::Circle(powerDrop.pos, powerDrop.size, powerDrop.color);
		drw::Sprite(powerDrop.activeTexture,powerDrop.pos, powerDrop.size);
	}
}

void pwr::Sound(pwr::PowerDrop powerDrop)
{
}

bool pwr::CheckCollision(pwr::PowerDrop& powerDrop, vec::Vector2 pos, vec::Vector2 size)
{
	if (!sett::usePowers) {
		return false;
	}
	if (!(powerDrop.pos.x - powerDrop.size.x / 2 < pos.x + size.x / 2 && powerDrop.pos.x + powerDrop.size.x / 2 > pos.x - size.x / 2)) {
		return false;
	}
	if (!(powerDrop.pos.y - powerDrop.size.y / 2 < pos.y + size.y / 2 && powerDrop.pos.y + powerDrop.size.y / 2 > pos.y - size.y / 2)) {
		return false;
	}

	return true;
}
