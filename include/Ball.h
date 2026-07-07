#pragma once

#include "Vec2.h"

struct Ball {
	Vec2 position;
	Vec2 velocity;
	float radius;
	bool visible = true;
};