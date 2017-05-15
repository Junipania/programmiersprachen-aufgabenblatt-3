#include "circle.hpp"
#include <math.h>

Circle::Circle():
    radius{0.0},
    color{Color{}},
    center{}{}

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

/*void Circle::draw(Window const& wins){
    for (int i = 1; i<= 360; ++i){
        Vec2 start{(make_rotation_mat2(2 * M_PI * i/360)) * Vec2(getRadius(), 0)+ getCenter()};
        Vec2 end{(make_rotation_mat2((2 * M_PI * (i + 1))/360)) * Vec2(getRadius(), 0)+ getCenter()};
        wins.draw_line(start.x, start.y, end.x, end.y, color.r, color.g, color.b);
    }
}

void Circle::draw(Window const& wins, Color const& clr){
    for (int i = 1; i<= 360; ++i){
        Vec2 start{(make_rotation_mat2(2 * M_PI * i/360)) * Vec2(getRadius(), 0)+ getCenter()};
        Vec2 end{(make_rotation_mat2((2 * M_PI * (i + 1))/360)) * Vec2(getRadius(), 0)+ getCenter()};
        wins.draw_line(start.x, start.y, end.x, end.y, clr.r, clr.g, clr.b);
    }
}*/

bool Circle::is_inside(Vec2 const& point){
    int count = 0;
    for (int i = 1; i<= 360; ++i){
        Vec2 start{(make_rotation_mat2(2 * M_PI * i/360)) * Vec2(getRadius(), 0)+ getCenter()};
        if (getCenter().x <= point.x && point.x<= start.x && getCenter().y <= point.y && point.y <= start.y){
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

bool Circle::operator < ( Circle const & c ){
    return (this->radius < c.radius);
}

bool Circle::operator > ( Circle const & c ){
    return (this->radius > c.radius);
}

bool Circle::operator == ( Circle const & c ){
    return (this->radius == c.radius);
}
