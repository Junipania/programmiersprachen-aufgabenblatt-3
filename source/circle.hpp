#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "color.hpp"
#include "mat2.hpp"
#include "window.hpp"

class Circle {
    float radius;
    Color color;
    Vec2 center;

    public:
    float getRadius();
    Color const& getColor()const;
    Vec2 const& getCenter()const;
    Circle(float r, Color const& clr, Vec2 const& cent);
    float circumference();
    void draw(Window const& wins);    
};

#endif
