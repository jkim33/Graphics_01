#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if (x0 > x1) {
    int temp = x1;
    x1 = x0;
    x0 = temp;
    temp = y1;
    y1 = y0;
    y0 = temp;
  }

  int x = x0;
  int y = y0;
  int A = y1 - y0;
  int B = x0 - x1;

  if (A > 0) {
    if (A > -B) {
      int d = A + 2*B;
      while (y <= y1) {
	plot(s,c,x,y);
	if (d < 0) {
	  x++;
	  d += 2*A;
	}
	y++;
	d += 2*B;
      }
    }
    else {
      int d = 2*A + B;
      while (x <= x1) {
	plot(s,c,x,y);
	if (d > 0) {
	  y++;
	  d += 2*B;
	}
	x++;
	d += 2*A;
      }
    }
  }
  else {
    if (A > B) {
      int d = B - 2*A;
      while (x <= x1) {
	plot(s,c,x,y);
	if (d > 0) {
	  y--;
	  d += 2*B;
	}
	x++;
	d -= 2*A;
      }
    }
    else {
      int d = 2*B - A;
      while (y >= y1) {
	plot(s,c,x,y);
	if (d < 0) {
	  x++;
	  d -= 2*A;
	}
	y--;
	d += 2*B;
      }
    }
  }
}
