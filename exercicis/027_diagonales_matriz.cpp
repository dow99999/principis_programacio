/**
 * Una matriz en la que el usuario entre el tamaño de la matriz cuadrada
 *
 * de esta, que se rellenen todos los valores con 0 excepto la diagonal
 * principal y la diagonal secundaria, que tendrá 1
 * 
 * Añadido: que en vez de 1 se coloque la dimension de la matriz cuadrada
 */

#include <stdio.h>
#include <stdlib.h>

int** crear_matriz(int t)
{
  int** matriz;

  matriz = (int **)malloc(t * sizeof(int **));
  for (int i = 0; i < t; i++)
  {
    matriz[i] = (int *)malloc(t * sizeof(int));
  }

  return matriz;
}

void limpiar_matriz(int** matriz, int tamano)
{
  for (int i = 0; i < tamano; i++)
  {
    free(matriz[i]);
  }

  free(matriz);
}

int main()
{
  int **matriz;
  int t = 0;

  printf("Tamano de la matriz cuadrada: ");
  scanf("%d", &t);

  matriz = crear_matriz(t);

  // Inicializamos todo a 0
  for (int i = 0; i < t; i++)
  {
    for (int j = 0; j < t; j++)
    {
      matriz[i][j] = (i == j || i + j == t - 1) ? t : 0;
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

  limpiar_matriz(matriz, t);

  return 0;
}
