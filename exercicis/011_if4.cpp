/**
 * 4. Escriba un programa en C que pida dos números enteros al usuario, y determine cuál es 
 * mayor, el primero o el segundo. Modifíquelo para considerar también la posibilidad de
 * que sean iguales.
 */

/**
 * Autor. Diego Muñoz Jorquera
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

  if(num1 > num2) {
    printf("El primer numero es mas grande que el segundo");

  } else if(num2 > num1) {
    printf("El segundo numero es mas grande que el primero");

  } else {
    printf("Los numeros son iguales");
  
  }

  return 0;
}