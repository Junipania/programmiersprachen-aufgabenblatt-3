#include "mat2.hpp"
#include <math.h>
#include <cmath>

Mat2::Mat2():
    a1{1},
    a2{0},
    b1{1},
    b2{0}{}

Mat2::Mat2(float a1,float a2,float b1,float b2):
    a1{a1},
    a2{a2},
    b1{b1},
    b2{b2}{}

Mat2 & Mat2::operator *= ( Mat2 const & m ){
    this->a1 *= m.a1;
    this->a2 *= m.a2;
    this->b1 *= m.b1;
    this->b2 *= m.b2;
    return *this;
}

Mat2 operator *( Mat2 const & m1 , Mat2 const & m2 ){
    Mat2 test{};
    
    test.a1 = (m1.a1 * m2.a1) + (m1.a2 * m2.b1);
    test.a2 = (m1.a1 * m2.a2) + (m1.a2 * m2.b2);
    test.b1 = (m1.b1 * m2.a1) + (m1.b2 * m2.b1);
    test.b2 = (m1.b1 * m2.a1) + (m1.b2 * m2.b2);
    return test;
}

float Mat2::det() const{
    float res = (this->a1 * this->b2) - (this->a2 * this-> b1);
    return res;
}

Vec2 operator *( Mat2 const & m , Vec2 const & v ){
    Vec2  test{};
    test.x = (m.a1 * v.x) + (m.a2 * v.y);
    test.y = (m.b1 * v.x) + (m.b2 * v.y);
    return test;
}

Vec2 operator *( Vec2 const & v , Mat2 const & m ){
    Vec2  test{};
    test.x = (m.a1 * v.x) + (m.a2 * v.y);
    test.y = (m.b1 * v.x) + (m.b2 * v.y);
    return test;
}

Mat2 inverse ( Mat2 const & m ){
    Mat2 res{};    
    float constant = 1 / ((m.a1 * m.b2) - (m.a2 * m.b1));
    res.a1 = constant * m.b2;
    res.a2 = constant * - m.a2;
    res.b1 = constant * - m.b1;
    res.b2 = constant * m.a1;
    return res;    
}

Mat2 transpose ( Mat2 const & m ){
    Mat2 res{};
    res.a1 = m.a1;
    res.a2 = m.b1;
    res.b1 = m.a2;
    res.b2 = m.b2;
    return res;
}

Mat2 make_rotation_mat2 ( float phi ){
    Mat2 res{};
    res.a1 = cos(phi);
    res.a2 = -sin(phi);
    res.b1 = sin(phi);
    res.b2 = cos(phi);
    return res;
}
