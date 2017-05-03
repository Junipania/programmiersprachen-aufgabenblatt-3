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

    win.draw_line(400, 780, 400, 730, clck.getColor().r, clck.getColor().g, clck.getColor().b);
    win.draw_line(400, 20, 400, 70, clck.getColor().r, clck.getColor().g, clck.getColor().b);
    win.draw_line(780, 400, 730, 400, clck.getColor().r, clck.getColor().g, clck.getColor().b);
    win.draw_line(20, 400, 70, 400, clck.getColor().r, clck.getColor().g, clck.getColor().b);
 
    clck.draw(win);

    //Zeiger initialisieren? WIE?!

    win.update();
  }
  return 0;
}
