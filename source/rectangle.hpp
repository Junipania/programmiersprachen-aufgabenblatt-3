#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"

class Rectangle{
    Vec2 min_;
    Vec2 max_;
    Color color;

    public:
    Rectangle(Vec2 const& min_, Vec2 const& max_, Color const& color);
    float circumference()const;
    Vec2 const& getMax()const;    
    Vec2 const& getMin()const;
    Color const& getColor()const;
    void draw(Window const& wins);
};
