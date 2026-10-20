/**
 * 2. Escriba un programa en C que pida dos números enteros al usuario, y determine si el
 * primero es divisible entre el segundo.
 */

/**
* Autor: Diego Muñoz Jorquera
*/

#include <stdio.h>

int main()
{
  int
    num1 = 0,
    num2 = 0;

  printf("Entra un numero entero: ");
  scanf("%d", &num1);
  printf("Entra otro numero entero: ");
  scanf("%d", &num2);

  printf("%d ", num1);
  if(num1 % num2 != 0) printf("no ");
  printf("es divisible por %d", num2);

  return 0;
}