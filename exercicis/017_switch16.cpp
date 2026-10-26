/**
 * 16. Escribir un programa que tras solicitar al usuario las coordenadas (x, y) de dos puntos
 *  calcule la pendiente de la recta que pasa por ambos puntos. La pendiente de dicha
 *  recta se calcula como:
 *
 *  D = (y2 - y1) / (x2 - x1)
 *
 *  Validar el funcionamiento del programa cuando los puntos introducidos son: A(2,1) y B(2,5).
 */

#include <stdio.h>

int main()
{
  float
      x1 = 0,
      x2 = 0;
  float
      y1 = 0,
      y2 = 0;

  float pendiente = 0;

  printf("Entra la coordenada x1: ");
  scanf("%f", &x1);
  printf("Entra la coordenada y1: ");
  scanf("%f", &y1);

  printf("Entra la coordenada x2: ");
  scanf("%f", &x2);
  printf("Entra la coordenada y2: ");
  scanf("%f", &y2);

  if (x2 == x1)
  {
    printf("La pendiente es infinita");
  }
  else
  {
    pendiente = (y2 - y1) / (x2 - x1);

    printf("La pendiente de la recta es %.4f", pendiente);
  }

  return 0;
}