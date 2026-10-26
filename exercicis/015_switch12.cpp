/**
 * 12. Escriba un programa que pida al usuario un número entre el uno y el siete
 *   y muestre un mensaje con el nombre del día correspondiente.
 */

#include <stdio.h>

int main()
{
  unsigned int dia = 0;

  printf("Entra el numero de un dia (1-7): ");
  scanf("%d", &dia);

  switch(dia)
  {
    case 1:
      printf("Lunes");
    break;
    case 2:
      printf("Martes");
    break;
    case 3:
      printf("Miercoles");
    break;
    case 4:
      printf("Jueves");
    break;
    case 5:
      printf("Viernes");
    break;
    case 6:
      printf("Sabado");
    break;
    case 7:
      printf("Domingo");
    break;
  }

  return 0;
}