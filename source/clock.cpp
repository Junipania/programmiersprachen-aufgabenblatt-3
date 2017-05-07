#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "circle.hpp"

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};
  

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    auto t = win.get_time();
    
    

    Vec2 cent{400, 400};

    Circle clck(380, Color{1.0, 0.0, 0.0}, Vec2{cent.x, cent.y});

    win.draw_line(400, 780, 400, 710, clck.getColor().r, clck.getColor().g, clck.getColor().b);
    win.draw_line(400, 20, 400, 90, clck.getColor().r, clck.getColor().g, clck.getColor().b);
    win.draw_line(780, 400, 710, 400, clck.getColor().r, clck.getColor().g, clck.getColor().b);
    win.draw_line(20, 400, 90, 400, clck.getColor().r, clck.getColor().g, clck.getColor().b);
    win.draw_line(729.09, 590, 685.79, 565, clck.getColor().r, clck.getColor().g, clck.getColor().b);
    win.draw_line(590, 729.09, 565, 685.79, clck.getColor().r, clck.getColor().g, clck.getColor().b);
    win.draw_line(210, 729.09, 235, 685.79, clck.getColor().r, clck.getColor().g, clck.getColor().b);
    win.draw_line(729.09, 210, 685.79, 235, clck.getColor().r, clck.getColor().g, clck.getColor().b);
    win.draw_line(70.91, 590, 114.21, 565, clck.getColor().r, clck.getColor().g, clck.getColor().b);
    win.draw_line(70.91, 210, 114.21, 235, clck.getColor().r, clck.getColor().g, clck.getColor().b);
    win.draw_line(210, 70.91, 235, 114.21, clck.getColor().r, clck.getColor().g, clck.getColor().b);
    win.draw_line(590, 70.91, 565, 114.21, clck.getColor().r, clck.getColor().g, clck.getColor().b);
 
    clck.draw(win);

    float a = cent.x + 350 * std::cos((12*t * M_PI - 585)/360);
    float b = cent.y + 350 * std::sin((12*t * M_PI - 585)/360);

    Vec2 sec {a, b};

    float c = cent.x + 330 * std::cos((0.2*t * M_PI - 565)/360);
    float d = cent.y + 330 * std::sin((0.2*t * M_PI - 565)/360);

    Vec2 min {c, d};

    float e = cent.x + 310 * std::cos((0.015f*t * M_PI - 565)/360);
    float f = cent.y + 310 * std::sin((0.015f*t * M_PI - 565)/360);

    Vec2 hour {e, f};

    win.draw_line(cent.x, cent.y, sec.x, sec.y, 1.0, 0.0, 0.0);

    win.draw_line(cent.x, cent.y, min.x, min.y, 0.0, 1.0, 0.0);

    win.draw_line(cent.x, cent.y, hour.x, hour.y, 0.0, 0.0, 1.0);

    //Zeiger initialisieren? WIE?!
    

    win.update();
  }
  return 0;
}
