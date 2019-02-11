#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = MAX_COLOR;;
  c.green = MAX_COLOR;
  c.blue = MAX_COLOR;

  clear_screen(s);

  int x;
  int y;

  for (y = 0; y <= 250; y++) {
    draw_line(0,0,250,y,s,c);
  }
  for (x = 250; x >= 0; x--) {
    draw_line(0,500,x,250,s,c);
  }
  for (x = 500; x >= 250; x--) {
    draw_line(250,250,x,500,s,c);
  }
  for (y = 250; y >= 0; y--) {
    draw_line(250,250,500,y,s,c);
  }

  display(s);
  save_extension(s, "lines.png");
}
