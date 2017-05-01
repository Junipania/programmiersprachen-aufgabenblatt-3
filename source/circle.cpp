#include "circle.hpp"

Circle::Circle(float radius, Color const& color, Vec2 const& center):
    radius{radius},
    color{color},
    center{center}{}

float Circle::getRadius(){
    return this->radius;
}

Color Circle::getColor(){
    return this->color;
}

Vec2 Circle::getCenter(){
    return this->center;
}
