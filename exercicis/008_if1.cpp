/**
 * 1. Escriba un programa que lea un número entero y escriba un mensaje si el número es 
 * mayor que 100
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

  if(num > 100) {
    printf("El numero es mayor a 100");
  }

  return 0;
}