#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

TEST_CASE("vecConstructor","[vecConstructor]"){
    Vec2 emptyVec{};
    Vec2 filledVec{1, 1};
	CHECK(emptyVec.x == 0);
	CHECK(emptyVec.y == 0);
    CHECK(filledVec.x == 1);
	CHECK(filledVec.y == 1);
}

TEST_CASE("plusequals","[plusequals]"){
    Vec2 peVector1{1, 1};
    Vec2 peVector2{1, 2};
    Vec2 peVector3{1, 3};
    peVector1 += peVector3;
    peVector2 += peVector3;
	CHECK(peVector1.x == 2);
    CHECK(peVector1.y == 4);
    CHECK(peVector2.x == 2);
    CHECK(peVector2.y == 5);
}

TEST_CASE("minusequals","[minusequals]"){
    Vec2 mieVector1{2, 1};
    Vec2 mieVector2{2, 2};
    Vec2 mieVector3{2, 3};
    mieVector1 -= mieVector3;
    mieVector2 -= mieVector3;
	CHECK(mieVector1.x == 0);
    CHECK(mieVector1.y == -2);
    CHECK(mieVector2.x == 0);
    CHECK(mieVector2.y == -1);
}

TEST_CASE("multequals","[multequals]"){
    Vec2 mueVector1{3, 1};
    Vec2 mueVector2{3, 2};
    mueVector1 *= 2;
    mueVector2 *= 2;
	CHECK(mueVector1.x == 6);
    CHECK(mueVector1.y == 2);
    CHECK(mueVector2.x == 6);
    CHECK(mueVector2.y == 4);
}

TEST_CASE("divequals","[divequals]"){
    Vec2 deVector1{4, 1};
    Vec2 deVector2{4, 2};
    deVector1 /= 2;
    deVector2 /= 2;
	CHECK(deVector1.x == 2);
    CHECK(deVector1.y == 0.5);
    CHECK(deVector2.x == 2);
    CHECK(deVector2.y == 1);
}

TEST_CASE("plus","[plus]"){
    Vec2 pVector1{1, 4};
    Vec2 pVector2{1, 5};
    Vec2 pVector3{};
    pVector3 = pVector1 + pVector2;
	CHECK(pVector3.x == 2);
    CHECK(pVector3.y == 9);
}

TEST_CASE("minus","[minus]"){
    Vec2 miVector1{2, 4};
    Vec2 miVector2{2, 5};
    Vec2 miVector3{};
    miVector3 = miVector2 - miVector1;
	CHECK(miVector3.x == 0);
    CHECK(miVector3.y == 1);
}

TEST_CASE("mult","[mult]"){
    Vec2 muVector1{3, 3};
    Vec2 muVector2{};
    Vec2 muVector3{};
    muVector2 = muVector1 * 2;
    muVector3 = 3 * muVector1;
	CHECK(muVector2.x == 6);
    CHECK(muVector2.y == 6);
    CHECK(muVector3.x == 9);
    CHECK(muVector3.y == 9);
}

TEST_CASE("div","[div]"){
    Vec2 dVector1{4, 3};
    Vec2 dVector2{};
    dVector2 = dVector1 / 2;
	CHECK(dVector2.x == 2);
    CHECK(dVector2.y == 1.5);
}

TEST_CASE("matConstructor","[matConstructor]"){
    Mat2 emptyMat{};
    Mat2 filledMat{1, 2, 3, 4};
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
    Mat2 multMat1{2, 2, 2, 2};
    Mat2 multMat2{3, 3, 3, 3};
    Mat2 multMat3{1, 4, 2, 1};
    Mat2 multMat4{};
    Mat2 multMat5{};
    multMat4 = multMat1 * multMat2;
    multMat5 = multMat1 * multMat3;
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
    float erg;
    Mat2 filledMat{1, 2, 3, 4};    
    erg = filledMat.det();
    CHECK(erg == -2);
}

TEST_CASE("vecmult","[vecmult]"){
    Vec2 matmultVec1{};
    Vec2 matmultVec2{};
    Mat2 emptyMat{};
    Vec2 filledVec{1, 1};
    matmultVec1 = emptyMat * filledVec;
    matmultVec2 = filledVec * emptyMat;
    CHECK(matmultVec1.x == 2);
    CHECK(matmultVec1.y == 2);
    CHECK(matmultVec2.x == 2);
    CHECK(matmultVec2.y == 2);
}

TEST_CASE("inverse","[inverse]"){
    Mat2 inverseMat{};
    Mat2 filledMat{1, 2, 3, 4};
    inverseMat = inverse(filledMat);
    CHECK(inverseMat.a1 == -2);
    CHECK(inverseMat.a2 == 1);
    CHECK(inverseMat.b1 == 1.5);
    CHECK(inverseMat.b2 == -0.5);
}

TEST_CASE("transpose","[transpose]"){
    Mat2 transMat{};
    Mat2 filledMat{1, 2, 3, 4};
    transMat = transpose(filledMat);
    CHECK(transMat.a1 == 1);
    CHECK(transMat.a2 == 3);
    CHECK(transMat.b1 == 2);
    CHECK(transMat.b2 == 4);
}

TEST_CASE("rotation","[rotation]"){
    Mat2 rotMat{};
    rotMat = make_rotation_mat2(M_PI / 2);
    CHECK(rotMat.a1 == Approx(0.0f));
    CHECK(rotMat.a2 == Approx(-1.0f));
    CHECK(rotMat.b1 == Approx(1.0f));
    CHECK(rotMat.b2 == Approx(0.0f));
}

TEST_CASE("circle","[circle]"){
    Circle cir{3.0, Color{0.0}, Vec2{2, 2}};
    CHECK(cir.getRadius() == 3.0);
    CHECK(cir.getColor().r == 0.0f);
    CHECK(cir.getColor().g == 0.0f);
    CHECK(cir.getColor().b == 0.0f);
}

TEST_CASE("rectangle","[rectangle]"){
    Rectangle rec{Vec2{2, 2},Vec2{4, 4},Color{0.0}};
    CHECK(rec.getMin().x ==  2);
    CHECK(rec.getMin().y ==  2);
    CHECK(rec.getMax().x ==  4);
    CHECK(rec.getMax().y ==  4);
    CHECK(rec.getColor().r == 0.0f);
    CHECK(rec.getColor().g == 0.0f);
    CHECK(rec.getColor().b == 0.0f);
}

int main(int argc, char *argv[])
{
    return Catch::Session().run(argc, argv);
}
