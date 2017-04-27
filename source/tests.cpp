#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.cpp"
#include "vec2.hpp"
#include <cmath>

Vec2 vector1{};
Vec2 vector2{1, 1};
Vec2 vector3{2, 2};
Vec2 vector4{3, 3};
Vec2 vector5{4, 4};
Vec2 vector6{5, 5};
Vec2 vector7{1, 2};
Vec2 vector8{1, 3};
Vec2 vector9{1, 4};
Vec2 vector10{1, 5};


TEST_CASE("vector1","[vector1]"){
	CHECK(vector1.x == 0);
	CHECK(vector1.y == 0);
}

TEST_CASE("vector2","[vector2]"){
	CHECK(vector2.x == 1);
	CHECK(vector2.y == 1);
}

TEST_CASE("operators","[operators]"){
	CHECK(vector3.x == 4);
	CHECK(vector3.y == 4);
	CHECK(vector4.x == 0);
	CHECK(vector4.y == 0);
	CHECK(vector5.x == 8);
	CHECK(vector5.y == 8);
	CHECK(vector6.x == 2.5);
	CHECK(vector6.y == 2.5);
	CHECK(vector7.x == 5);
	CHECK(vector7.y == 6);
	CHECK(vector8.x == 0);
	CHECK(vector8.y == 2);
	CHECK(vector9.x == 4);
	CHECK(vector9.y == 16);
	CHECK(vector10.x == 0.25);
	CHECK(vector10.y == 1.25);
}


int main(int argc, char *argv[])
{
  vector3 += vector3;
  vector7 += vector5;
  vector4 -= vector4;
  vector8 -= vector2;
  vector5 *= 2;
  vector9 *= 4;
  vector6 /= 2;
  vector10 /= 4;
  return Catch::Session().run(argc, argv);
}
