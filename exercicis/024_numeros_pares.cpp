/**
 * Un programa que guarde los 25 primeros numeros pares y
 *  los guarde en un array. que los muestre por pantalla. Luego que calcule la media
 *  aritmética de todos los valores y los muestre por pantalla.
 */

#include <stdio.h>

int main()
{
  const int VALORES = 25;

  int pares[VALORES];
  float media = 0;
  int valor = 0;

  for (int i = 1; i <= VALORES; i++)
  {
    valor = i * 2;
    pares[i - 1] = valor;
    media += valor;
  }

  media /= (float)VALORES;

  printf("Valores: ");

  for (int i = 0; i < VALORES; i++)
  {
    printf("%d%c ", pares[i], i == VALORES - 1 ? '\n' : ',');
  }

  printf("\rMedia: %.2f", media);

  return 0;
}