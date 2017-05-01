#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.cpp"
#include "mat2.cpp"
#include "cirlce.cpp"
#include "rectangle.cpp"
#include <cmath>
#include <math.h>

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

Mat2 emptyMat{};
Mat2 filledMat{1, 2, 3, 4};

Mat2 multMat1{2, 2, 2, 2};
Mat2 multMat2{3, 3, 3, 3};
Mat2 multMat3{1, 4, 2, 1};
Mat2 multMat4{};
Mat2 multMat5{};

Vec2 matmultVec1{};
Vec2 matmultVec2{};

Mat2 inverseMat{};

Mat2 transMat{};

Mat2 rotMat{};

Circle cir{3.0, Color{0.0}, Vec2{2, 2}};

Rectangle rec{Vec2{2, 2},Vec2{4, 4},Color{0.0}}

float erg;


TEST_CASE("vecConstructor","[vecConstructor]"){
	CHECK(emptyConstructor.x == 0);
	CHECK(emptyConstructor.y == 0);
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

TEST_CASE("matConstructor","[matConstructor]"){
    CHECK(emptyMat.a1 == 1);
    CHECK(emptyMat.a2 == 1);
    CHECK(emptyMat.b1 == 1);
    CHECK(emptyMat.b2 == 1);
    CHECK(filledMat.a1 == 1);
    CHECK(filledMat.a2 == 2);
    CHECK(filledMat.b1 == 3);
    CHECK(filledMat.b2 == 4);
}

TEST_CASE("matMult","[matMult]"){
    CHECK(multMat4.a1 == 12);
    CHECK(multMat4.a2 == 12);
    CHECK(multMat4.b1 == 12);
    CHECK(multMat4.b2 == 12);
    CHECK(multMat5.a1 == 6);
    CHECK(multMat5.a2 == 10);
    CHECK(multMat5.b1 == 6);
    CHECK(multMat5.b2 == 4);
}

TEST_CASE("det","[det]"){
    CHECK(erg == -2);
}

TEST_CASE("vecmult","[vecmult]"){
    CHECK(matmultVec1.x == 2);
    CHECK(matmultVec1.y == 2);
    CHECK(matmultVec2.x == 2);
    CHECK(matmultVec2.y == 2);
}

TEST_CASE("inverse","[inverse]"){
    CHECK(inverseMat.a1 == -2);
    CHECK(inverseMat.a2 == 1);
    CHECK(inverseMat.b1 == 1.5);
    CHECK(inverseMat.b2 == -0.5);
}

TEST_CASE("transpose","[transpose]"){
    CHECK(transMat.a1 == 1);
    CHECK(transMat.a2 == 3);
    CHECK(transMat.b1 == 2);
    CHECK(transMat.b2 == 4);
}

TEST_CASE("rotation","[rotation]"){
    CHECK(rotMat.a1 == -0);
    CHECK(rotMat.a2 == -1);
    CHECK(rotMat.b1 == 1);
    CHECK(rotMat.b2 == -0);
}

TEST_CASE("circle","[circle]"){
    CHECK(cir.getRadius() == 3.0);
    CHECK(cir.getColor() == {0.0, 0.0, 0.0});
    CHECK(cir.getCenter() == {2, 2});
}

TEST_CASE("rectangle","[rectangle]"){
    CHECK(rec.getMin() == {2, 2});
    CHECK(rec.getMax() == {4, 4});
    CHECK(rec.getColor() == {0.0, 0.0, 0.0})


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

    multMat4 = multMat1 * multMat2;
    multMat5 = multMat1 * multMat3;

    erg = filledMat.det();

    matmultVec1 = emptyMat * filledConstructor;
    matmultVec2 = filledConstructor * emptyMat;

    inverseMat = inverse(filledMat);

    transMat = transpose(filledMat);

    rotMat = make_rotation_mat2(M_PI / 2);

    return Catch::Session().run(argc, argv);
}
