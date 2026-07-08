#pragma once
#include "../include/Transform.h"

#include "Vec2.h"

struct Rectangle {
	Transform transform;
	Vec2 position; 
	Vec2 size;
	bool visible = true;
};