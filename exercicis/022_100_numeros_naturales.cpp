/**
 * Mostrar los 100 primeros numeros naturales y solo los pares del 1 al 100
 */

#include <stdio.h>

int main()
{
  for(int i = 1; i <= 100; i++)
  {
    printf("%d%c ", i, (i == 100 ? ' ' : ','));
  }

  printf("\n");
  printf("\n");

  for(int i = 1; i <= 100; i++)
  {
    if(i % 2 == 0)
      printf("%d%c ", i, (i == 100 ? ' ' : ','));
  }

  return 0;
}