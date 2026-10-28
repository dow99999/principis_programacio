/**
 * Un programa que salude al usuario por su nombre, espere
 * hasta que el usuario entre una tecla y acabe
 */

/**
 * Autor: Diego MUñoz Jorquera
 */

#include <stdio.h>
#include <conio.h>
#include <locale.h>

/**
 * Este procedimiento muestra un mensaje de espera y
 * espera a que el usuario presione una tecla
 */
void pausa()
{
  printf("Pulse una tecla para continuar...");
  getch();
}





int main()
{
  setlocale(LC_ALL, "");
  printf("Buenos días, %s\n", "Diego");
  pausa();

  return 0;
}