#pragma once

struct Vec2 {
	float x;
	float y;

	Vec2 operator-(const Vec2& other) const {
		return Vec2{ x - other.x,y - other.y };
	}
	Vec2 operator+(const Vec2& other) const {
		return Vec2{ x + other.x,y + other.y };
	}
};