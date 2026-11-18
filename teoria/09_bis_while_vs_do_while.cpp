#include <stdio.h>

int main()
{
  int i;

  // Si el valor inicial es inferior al maximo, los dos bucles funcionan igual
  // Pero, ¿y si el valor inicial es superior al máximo? ¿qué ocurre?
  const int VALOR_INICIAL_I = 0;
  const int VALOR_MAXIMO_I = 4;

  i = VALOR_INICIAL_I;
  while (i <= VALOR_MAXIMO_I)
  {
    printf("%d\n", i);
    i++;
  }

  printf("--------\n");

  i = VALOR_INICIAL_I;
  do
  {
    printf("%d\n", i);
    i++;

  } while (i <= VALOR_MAXIMO_I);

  /**
   * while siempre comprueba la condición al inicio, y en caso de ésta evaluarse
   *   como cierta, ejecutará el código del cuerpo del bucle.
   *
   * do while hace su comprobación al final de la ejecución del bucle, por lo tanto,
   * siempre se ejecutará al menos una vez, sin importar la condición.
   */

  return 0;
}