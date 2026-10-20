/**
 * 3. Escriba un programa en C que pida un número al usuario e indique si es par o impar.
 * En caso de que sea par indicar si es o no múltiplo de 3.
 */

 /**
  * Autor: Diego Muñoz Jorquera
  */

#include <stdio.h>

int main()
{
  int num = 0;

  printf("Entra un numero entero: ");
  scanf("%d", &num);

  if(num % 2 == 0) {
    printf("El numero es par");
    if(num % 3 == 0) {
      printf(", ademas, es multiplo de 3");
    }
    printf("\n");
  } else {
    printf("El numero es impar");
  }

  return 0;
}