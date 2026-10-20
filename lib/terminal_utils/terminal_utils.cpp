#include <stdio.h>
#include "terminal_utils.hpp"


void reset_visuals()
{
  printf("\x1b[0m");
  show_cursor(); // por si acaso, aunque parece que no hace falta con el anterior
}

void set_color(unsigned char r, unsigned char g, unsigned char b)
{
  printf("\x1b[38;2;%d;%d;%dm", r, g, b);
}
void set_background(unsigned char r, unsigned char g, unsigned char b)
{
  printf("\x1b[48;2;%d;%d;%dm", r, g, b);
}

void move_cursor(int x, int y)
{
  printf("\x1b[%d;%dH", y, x);
}

void clear_screen()
{
  printf("\x1b[2J");
}

void hide_cursor()
{
  printf("\x1b[25l");
}

void show_cursor()
{
  printf("\x1b[25h");
}