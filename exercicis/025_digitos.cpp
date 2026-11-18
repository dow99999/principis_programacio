/**
 * Que lea un numero entero de x cifras por pantalla, que diga cuantos digitos
 * tiene el numero y verlos uno por uno en cada linea.
 *
 * Que no salga del programa hasta que se introduzca un 0
 * 
 * Que esté separado por funciones: el calculo de dígitos y el mostrar la info por pantalla
 */

#include <stdio.h>


void mostrar_numero_por_pantalla(int num)
{
  printf("Digitos: %d\n", num);
  
}

void numero_al_reves(int num)
{
  int digitos = 0;

  if (num < 0) num *= -1;

  while (num != 0)
  {
    printf("%d\n", num % 10);
    num /= 10;

    digitos++;
  }
  
  mostrar_numero_por_pantalla(digitos);

}


int main()
{
  int num = -1;

  while (num != 0)
  {
    printf("Entra un numero entero (0 para salir del programa): ");
    scanf("%d", &num);

    if (num == 0)
      break;

    numero_al_reves(num);
  }

  return 0;
}