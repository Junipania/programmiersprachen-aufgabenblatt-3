#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "color.hpp"
#include "vec2.hpp"

class Circle {
    float radius;
    Color color;
    Vec2 center;

    public:
    float getRadius();
    Color getColor();
    Vec2 getCenter();

    Circle(float r, Color const& clr, Vec2 const& cent);

    float circumference();
    
};

#endif
