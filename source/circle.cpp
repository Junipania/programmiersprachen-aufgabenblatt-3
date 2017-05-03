#include "circle.hpp"
#include <math.h>


Circle::Circle(float r, Color const& clr, Vec2 const& cent):
    radius{r},
    color{clr},
    center{cent}{}

float Circle::getRadius(){
    return this->radius;
}

Color Circle::getColor(){
    return this->color;
}

Vec2 Circle::getCenter(){
    return this->center;
}

float Circle::circumference(){
    return 2 * M_PI * this->radius;
}

