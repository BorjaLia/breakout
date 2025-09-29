#pragma once
#include "Utils_Borja.h"
#include "Paddle.h"
#include "Power.h"

namespace pwr {

	struct PowerDrop {

		bool isActive = false;

		vec::Vector2 pos = { 0.5f,0.5f };
		vec::Vector2 vel = { 0,-1 };

		float speed = 0.5f;

		vec::Vector2 size = { 0.01f,0.01f };

		Color color;

		PowerType powerType = PowerType::NONE;

		rend::SpriteData activeTexture;
	};

	void Init(pwr::PowerDrop& powerDrop, vec::Vector2 pos, PowerType powerType);
	void Reset(pwr::PowerDrop& powerDrop);
	void Update(pwr::PowerDrop& powerDrop, vec::Vector2 pos, vec::Vector2 size);
	void Draw(pwr::PowerDrop powerDrop);
	void Sound(pwr::PowerDrop powerDrop);

	bool CheckCollision(pwr::PowerDrop& powerDrop, vec::Vector2 pos, vec::Vector2 size);
}