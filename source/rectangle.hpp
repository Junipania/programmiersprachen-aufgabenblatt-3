#include "color.cpp"
#include "vec2.cpp"

class Rectangle{
    Color const& color;
    Vec2 const& min_;
    Vec2 const& max_;

    Rectangle(Vec2 const& min_, Vec2 const& max_, Color const& color);

    float circumference();
};
