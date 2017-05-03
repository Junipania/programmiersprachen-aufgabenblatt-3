#include "circle.hpp"
#include <math.h>


Circle::Circle(float r, Color const& clr, Vec2 const& cent):
    radius{r},
    color{clr},
    center{cent}{}

float Circle::getRadius(){
    return this->radius;
}

Color const& Circle::getColor()const{
    return this->color;
}

Vec2 const& Circle::getCenter()const{
    return this->center;
}

float Circle::circumference(){
    return 2 * M_PI * this->radius;
}

void Circle::draw(Window const& wins){
    for (int i = 1; i<= 360; ++i){
        float phi = 2 * M_PI * i/360;
        Vec2 start{(make_rotation_mat2(phi)) * Vec2(getRadius(), 0)+ getCenter()};
        Vec2 end{(make_rotation_mat2((2 * M_PI * (i + 1))/360)) * Vec2(getRadius(), 0)+ getCenter()};
        wins.draw_line(start.x, start.y, end.x, end.y, color.r, color.g, color.b);
    }
}

