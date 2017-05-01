#include "color.cpp"
#include "vec2.cpp"

class Circle {
    float radius;
    Color const& color;
    Vec2 const& center;

    float getRadius();
    Color getColor();
    Vec2 getCenter();

    Circle(float radius, Color const& color, Vec2 const& center);
};
