#include <stdio.h>
#include "../lib/terminal_utils/terminal_utils.hpp"

void test_gradients(unsigned char step)
{
  int col = 0;

  for (unsigned char r = 0x00; r < 0xFF; r += step)
  {
    for (unsigned char g = 0x00; g < 0xFF; g += step)
    {
      for (unsigned char b = 0x00; b < 0xFF; b += step)
      {
        set_background(r, g, b);
        col = r + g + b > 0xFFFFFF / 2 ? 0x000000 : 0xFFFFFF;
        set_color(col, col, col);
        printf("#%.2x%.2x%.2x", r, g, b);
        
        reset_visuals();
        printf("\n");
      }
    }
  }
}

int main()
{
  test_gradients(0x33);

  move_cursor(1, 1);
  printf("a");
  move_cursor(5, 1);
  printf("á");

  // clear_screen();

  return 0;
}