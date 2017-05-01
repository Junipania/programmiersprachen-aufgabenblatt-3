#include "rectangle.hpp"

Rectangle::Rectangle(Vec2 const& min_, Vec2 const& max_, Color const& color):
    min_{min_},
    max_{max_},
    color{color}{}

Vec2 Rectangle::getMin(){
    return this->min_;
}

Vec2 Rectangle::getMax(){
    return this->max_;
}

Color Rectangle::getColor(){
    return this->color;
}
