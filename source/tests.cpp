#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.cpp"
#include "vec2.hpp"
#include <cmath>

Vec2 emptyConstructor{};
Vec2 filledConstructor{1, 1};

Vec2 peVector1{1, 1};
Vec2 peVector2{1, 2};
Vec2 peVector3{1, 3};

Vec2 mieVector1{2, 1};
Vec2 mieVector2{2, 2};
Vec2 mieVector3{2, 3};

Vec2 mueVector1{3, 1};
Vec2 mueVector2{3, 2};

Vec2 deVector1{4, 1};
Vec2 deVector2{4, 2};

Vec2 pVector1{1, 4};
Vec2 pVector2{1, 5};
Vec2 pVector3{};

Vec2 miVector1{2, 4};
Vec2 miVector2{2, 5};
Vec2 miVector3{};

Vec2 muVector1{3, 3};
Vec2 muVector2{};
Vec2 muVector3{};

Vec2 dVector1{4, 3};
Vec2 dVector2{};

TEST_CASE("vector1","[vector1]"){
	CHECK(emptyConstructor.x == 0);
	CHECK(emptyConstructor.y == 0);
}

TEST_CASE("vector2","[vector2]"){
	CHECK(filledConstructor.x == 1);
	CHECK(filledConstructor.y == 1);
}

TEST_CASE("plusequals","[plusequals]"){
	CHECK(peVector1.x == 2);
    CHECK(peVector1.y == 4);
    CHECK(peVector2.x == 2);
    CHECK(peVector2.y == 5);
}

TEST_CASE("minusequals","[minusequals]"){
	CHECK(mieVector1.x == 0);
    CHECK(mieVector1.y == -2);
    CHECK(mieVector2.x == 0);
    CHECK(mieVector2.y == -1);
}

TEST_CASE("multequals","[multequals]"){
	CHECK(mueVector1.x == 6);
    CHECK(mueVector1.y == 2);
    CHECK(mueVector2.x == 6);
    CHECK(mueVector2.y == 4);
}

TEST_CASE("divequals","[divequals]"){
	CHECK(deVector1.x == 2);
    CHECK(deVector1.y == 0.5);
    CHECK(deVector2.x == 2);
    CHECK(deVector2.y == 1);
}

TEST_CASE("plus","[plus]"){
	CHECK(pVector3.x == 2);
    CHECK(pVector3.y == 9);
}

TEST_CASE("minus","[minus]"){
	CHECK(miVector3.x == 0);
    CHECK(miVector3.y == 1);
}

TEST_CASE("mult","[mult]"){
	CHECK(muVector2.x == 6);
    CHECK(muVector2.y == 6);
    CHECK(muVector3.x == 9);
    CHECK(muVector3.y == 9);
}

TEST_CASE("div","[div]"){
	CHECK(dVector2.x == 2);
    CHECK(dVector2.y == 1.5);
}

int main(int argc, char *argv[])
{
    peVector1 += peVector3;
    peVector2 += peVector3;
  
    mieVector1 -= mieVector3;
    mieVector2 -= mieVector3;

    mueVector1 *= 2;
    mueVector2 *= 2;

    deVector1 /= 2;
    deVector2 /= 2;

    pVector3 = pVector1 + pVector2;

    miVector3 = miVector2 - miVector1;

    muVector2 = muVector1 * 2;
    muVector3 = 3 * muVector1;

    dVector2 = dVector1 / 2;

    return Catch::Session().run(argc, argv);
}
