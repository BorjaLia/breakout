#pragma once
#include "Utils_Borja.h"
#include "Power.h"

struct PowerDrop {

	vec::Vector2 pos = { 0,0 };
	vec::Vector2 direction = { 0,0 };

	float speed = 1.0f;

	vec::Vector2 size = { 0,0 };

	Power power;
};