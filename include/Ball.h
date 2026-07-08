#pragma once

#include "Vec2.h"
#include "Transform.h"

struct Ball {
	Transform transform;
	Vec2 position;
	Vec2 velocity;
	float radius;
	bool visible = true;
};