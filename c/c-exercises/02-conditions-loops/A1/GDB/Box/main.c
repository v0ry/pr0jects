#include <stdio.h>

typedef struct Circle {
  float var_x, var_y, center;
} circle;

typedef struct Box {
  float tl, tr, bl, br;
} box;

int main(void) {
  circle x, y, c;
  x.var_x = 0;
  y.var_y = 0;
  printf("X-coordinate of the circle's center: ");
  scanf(" %f", &x.var_x);

  printf("Y-coordinate of the circle's center: ");
  scanf(" %f", &y.var_y);

  printf("Radius of the circle: ");
  scanf(" %f", &c.center);

  box bl_x, bl_y, tl_x, tl_y;
  bl_x.bl = (x.var_x - c.center);
  bl_y.bl = (y.var_y - c.center);

  bl_x.br = (x.var_x + c.center);
  bl_y.br = (y.var_y - c.center);

  tl_x.tl = (x.var_x - c.center);
  tl_y.tl = (y.var_y + c.center);

  // for debugging
  tl_x.tr = (x.var_x + c.center);
  tl_y.tr = (y.var_y + c.center);
  /*printf("%f", bl_x.bl);*/
  /*printf("%f", bl_y.bl);*/

  printf("Bounding Box - TL: (%.2f/%.2f)\n", tl_x.tl, tl_y.tl);
  printf("Bounding Box - TR: (%.2f/%.2f)\n", tl_x.tr, tl_y.tr);
  printf("Bounding Box - BL: (%.2f/%.2f)\n", bl_x.bl, bl_y.bl);
  printf("Bounding Box - BR: (%.2f/%.2f)\n", bl_x.br, bl_y.br);
  return 0;
}
