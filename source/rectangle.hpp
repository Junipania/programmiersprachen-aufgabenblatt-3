#include "color.hpp"
#include "vec2.hpp"

class Rectangle{
    Vec2 min_;
    Vec2 max_;
    Color color;

    public:
    Rectangle(Vec2 const& min_, Vec2 const& max_, Color const& color);
    float circumference();
    Vec2 getMax();    
    Vec2 getMin();
    Color getColor();
};
