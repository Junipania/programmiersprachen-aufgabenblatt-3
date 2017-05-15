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

/*void Rectangle::draw(Window const& wins){
    wins.draw_line(min_.x, min_.y, min_.x, max_.y, color.r, color.g, color.b);
    wins.draw_line(min_.x, min_.y, max_.x, min_.y, color.r, color.g, color.b);
    wins.draw_line(max_.x, min_.y, max_.x, max_.y, color.r, color.g, color.b);
    wins.draw_line(min_.x, max_.y, max_.x, max_.y, color.r, color.g,color.b);
}

void Rectangle::draw(Window const& wins, Color const& clr){
    wins.draw_line(min_.x, min_.y, min_.x, max_.y, clr.r, clr.g, clr.b);
    wins.draw_line(min_.x, min_.y, max_.x, min_.y, clr.r, clr.g, clr.b);
    wins.draw_line(max_.x, min_.y, max_.x, max_.y, clr.r, clr.g, clr.b);
    wins.draw_line(min_.x, max_.y, max_.x, max_.y, clr.r, clr.g,clr.b);*/
}

bool Rectangle::is_inside(Vec2 const& point){
    int count = 0;
    for (int i = 1; i<= 360; ++i){
        if (getMin().x <= point.x && point.x<= getMax().x && getMin().y <= point.y && point.y <= getMax().y){
           count += 1; 
        }
    }
    if(count == 0){
        return false;
    }
    else{
        return true;
    }
}

