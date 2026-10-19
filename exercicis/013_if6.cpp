/**
 * 6. Dada la función f(x), realizar un programa C que calcule dicha función para un valor
 * dado de x y lo muestre por pantalla. De forma que: x + 3 para x ≤ 0; x2 + 2x para x >0
 * x2 + 2x para x > 0
 */

/**
 * Autor: Diego Muñoz Jorquera
 */

#include <stdio.h>

int main()
{
  float
      x = 0,
      resultado = 0;

  printf("Entra un valor para x: ");
  scanf("%f", &x);

  // if (x <= 0)
  // {
  //   resultado = x + 3;
  // }
  // else
  // {
  //   resultado = 2 * x + 2 * x;
  // }

  resultado = (x <= 0) ? (x + 3) : (2 * x + 2 * x);

  printf("El valor de f(x) para x=%f es %f", x, resultado);

  return 0;
}