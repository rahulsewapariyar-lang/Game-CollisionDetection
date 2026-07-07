#pragma once

#include "Vec2.h"

struct Rectangle {
	Vec2 position; 
	Vec2 size;
	bool visible = true;
};