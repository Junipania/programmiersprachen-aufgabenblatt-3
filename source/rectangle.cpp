#include "rectangle.hpp"
#include <math.h>

Rectangle::Rectangle(Vec2 const& min_, Vec2 const& max_, Color const& color):
    min_{min_},
    max_{max_},
    color{color}{}

Vec2 const& Rectangle::getMin()const{
    return this->min_;
}

Vec2 const& Rectangle::getMax()const{
    return this->max_;
}

Color const& Rectangle::getColor()const{
    return this->color;
}

float Rectangle::circumference()const{
    return (2 * (this->max_.x - this->min_.x)) + (2 * (this->max_.y - this->min_.y));
}

void Rectangle::draw(Window const& wins){

    wins.draw_line(min_.x, min_.y, min_.x, max_.y, color.r, color.g, color.b);
    wins.draw_line(min_.x, min_.y, max_.x, min_.y, color.r, color.g, color.b);
    wins.draw_line(max_.x, min_.y, max_.x, max_.y, color.r, color.g, color.b);
    wins.draw_line(min_.x, max_.y, max_.x, max_.y, color.r, color.g,color.b);
}


