#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "color.hpp"
#include "mat2.hpp"
//#include "window.hpp"

class Circle {
    float radius;
    Color color;
    Vec2 center;

    public:
    float getRadius();
    Color const& getColor()const;
    Vec2 const& getCenter()const;
    Circle();
    Circle(float r, Color const& clr, Vec2 const& cent);
    float circumference();
    //void draw(Window const& wins); 
    //void draw(Window const& wins, Color const& clr);   
    bool is_inside(Vec2 const& point);

    bool operator < ( Circle const & c );
    bool operator > ( Circle const & c );
    bool operator == ( Circle const & c );
};

#endif
