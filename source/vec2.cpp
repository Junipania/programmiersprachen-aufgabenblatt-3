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

Vec2 operator +( Vec2 const & u , Vec2 const & v ){
    Vec2 test{};
    test.x = u.x + v.x;
    test.y = u.y + v.y;
    return test;
}

Vec2 operator -( Vec2 const & u , Vec2 const & v ){
    Vec2 test{};
    test.x = u.x - v.x;
    test.y = u.y - v.y;
    return test;
}

Vec2 operator *( Vec2 const & v , float s ){
    Vec2 test{};
    test.x = v.x * s;
    test.y = v.y * s;
    return test;
}

Vec2 operator /( Vec2 const & v , float s ){
    Vec2 test{};
    test.x = v.x / s;
    test.y = v.y / s;
    return test;
}

Vec2 operator *( float s , Vec2 const & v ){
    Vec2 test{};
    test.x = v.x * s;
    test.y = v.y * s;
    return test;
}

