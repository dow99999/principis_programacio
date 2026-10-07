/**
 * Un programa que dada una base y una altura calcule el area de:
 *    triangulo-rectángulo
 *    un rectangulo
 * Y tambien el perimetro de un rectángulo
 */

/**
 * Autor: Diego
 */

// Para usar printf
#include <stdio.h>

int main()
{
  float
      base   = 5.121,
      altura = 2.323,
      mul    = 0;

  printf("\n");
  printf("+ Datos ---------------------------------\n");
  printf("| base: %.2f\n| altura: %.2f\n", base, altura);
  printf("+----------------------------------------\n\n");

  mul = base * altura;

  printf("+ Resultados ----------------------------\n");
  printf("| Area de un triangulo-rectangulo: %.2f\n", mul / 2);
  printf("| Area de un rectangulo: %.2f\n", mul);
  printf("| Perimetro de un rectangulo: %.2f\n", base * 2 + altura * 2);
  printf("+----------------------------------------\n\n");

  return 0;
}