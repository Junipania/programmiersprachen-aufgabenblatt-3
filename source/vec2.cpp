#include "vec2.hpp"
#include <cmath>

Vec2::Vec2():
	x{0},
	y{0} {}

Vec2::Vec2(float a, float b):
	x{a},
	y{b} {}


Vec2& Vec2::operator += ( Vec2 const & v ){
	this->x += v.x;
	this->y += v.y;
	return *this;
}

Vec2& Vec2::operator -= ( Vec2 const & v ){
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}

Vec2& Vec2::operator *= ( float s ){
	this->x *= s;
	this->y *= s;
	return *this;
}

Vec2& Vec2::operator /= ( float s ){
	this->x /= s;
	this->y /= s;
	return *this;
}

