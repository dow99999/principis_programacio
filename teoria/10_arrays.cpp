#include <stdio.h>

/**
 * Ejemplo: definir 3 arrays y recorrerlos para ver sus datos.
 */

int main()
{
  int v[4] = {7, 2, 9, 4};

  int m[2][3] = {
      {1, 2, 3},
      {4, 5, 6}};

  int t[2][2][3] = {
      {{1, 2, 3}, {4, 5, 6}},
      {{7, 8, 9}, {10, 11, 12}}};

  int ceros[3][4] = {0};

  printf("- vector -------------------\n");

  int l_vi = sizeof(v) / sizeof(v[0]);

  for (int i = 0; i < l_vi; i++)
  {
    printf("%d%c ", v[i], i == 3 ? ' ' : ',');
  }

  printf("\n- matriz -------------------\n");


  

  for (int i = 0; i < sizeof(m)/ sizeof(m[i]); i++)
  {
    for (int j = 0; j < sizeof(m[i]) / sizeof(m[i][j]); j++)
    {
      printf("%d%c ", m[i][j], j == ((sizeof(m[i]) / sizeof(m[i][j])) - 1) ? ' ' : '\t');
    }
    printf("\n");
  }

  printf("- matriz 3-dimensional -----\n");

  for (int i = 0; i < sizeof(t) / sizeof(t[i]); i++)
  {
    for (int j = 0; j < sizeof(t[i]) / sizeof(t[i][j]); j++)
    {
      for (int k = 0; k < sizeof(t[i][j]) / sizeof(t[i][j][k]); k++)
      {
        printf("%d%c ", t[i][j][k], k == ((sizeof(t[i][j]) / sizeof(t[i][j][k])) - 1) ? ' ' : '\t');
      }
      printf("\n");
    }
    printf("--\n");
  }

  printf("- ceros --------------------\n");

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      printf("%d%c ", ceros[i][j], j == 3 ? ' ' : '\t');
    }
    printf("\n");
  }

  return 0;
}

/**
 * Arrays multidimensionales
 *
 * Definición de una matriz de enteros 3x4:
 *   int m[3][4]
 *
 * Se declaran de la siguiente forma:
 *
 * int m[3][4] = {
 *  { 1, 1, 1, 1 },
 *  { 1, 1, 1, 1 },
 *  { 1, 1, 1, 1 },
 * }
 *
 * Básicamente, se declaran arrays dentro de los valores de un array:
 *
 * int m[2][2] = {
 *  array1,
 *  array2
 * }
 *
 * Y evidentemente, dentro de un array podríamos colocar mas arrays, las veces que queramos.
 * Cuantos más arrays coloquemos, más dimensiones tendrá nuestra estructura.
 *
 */