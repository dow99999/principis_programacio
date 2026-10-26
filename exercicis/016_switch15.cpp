/**
 * 15. Escribir un programa que reciba un número de una carta de una baraja
 *   española e imprima por pantalla: “As” si es un 1, “Sota”, si es un 10,
 *   “Caballo” si es un 11y “Rey” si es un 12. Para números de cartas entre
 *   2 y 9 (incluidos) debe imprimir: "No es as ni figura". Para otros números
 *   debe imprimir: "este no es un número de una carta de la baraja española".
 */

/**
 * Autor: Diego Muñoz Jorquera
 */

#include <stdio.h>

int main()
{
  int carta = 0;

  printf("Entra el numero de una carta: ");
  scanf("%d", &carta);

  switch (carta)
  {
  case 1:
    printf("As");
    break;
  case 10:
    printf("Sota");
    break;
  case 11:
    printf("Caballo");
    break;
  case 12:
    printf("Rey");
    break;
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
    printf("No es ni as ni figura");
    break;
  default:
    printf("No es una carta de la baraja espanola");
  }

  return 0;
}