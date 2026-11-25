/**
 * Una matriz en la que el usuario entre el tamaño de forma dinamica xdddddd
 *
 * que se rellenen todos los valores con 0 excepto la diagonal, que tendrá 1
 */

#include <stdio.h>
#include <stdlib.h>

// que puta barbaridad la teoría en el examen...
int main()
{
  int **matriz;
  int t = 0;

  printf("Tamano de la matriz cuadrada: ");
  scanf("%d", &t);

  matriz = (int **)malloc(t * sizeof(int **));
  for (int i = 0; i < t; i++)
  {
    matriz[i] = (int *)malloc(t * sizeof(int));
  }

  // Inicializamos todo a 0
  for (int i = 0; i < t; i++)
  {
    for (int j = 0; j < t; j++)
    {
      matriz[i][j] = (i == j || i + j == t - 1);
    }
  }

  for (int i = 0; i < t; i++)
  {
    for (int j = 0; j < t; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < t; i++)
  {
    free(matriz[i]);
  }
  free(matriz);

  return 0;
}
