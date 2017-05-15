#include "color.hpp"
#include "vec2.hpp"
//#include "window.hpp"

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
    //void draw(Window const& wins);
    //void draw(Window const& wins, Color const& clr);
    bool is_inside(Vec2 const& point);
};
