#include "color.hpp"

Color::Color():
    r{0.0},
    g{0.0},
    b{0.0}{}

Color::Color(float num):
    r{num},
    g{num},
    b{num}{}

Color::Color(float red, float green, float blue):
    r{red},
    g{green},
    b{blue}{}
