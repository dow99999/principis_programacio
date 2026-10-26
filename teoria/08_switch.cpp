/**
 * Escriba un programa en C que lea un caracter y, utilizando la instrucción 
 *   switch determine si es o no una vocal. Realice el mismo ejercicio utilizando la sentencia if
 *   ¿Que opción es mejor? 
 */

/**
 * Autor: Diego Muñoz Jorquera
 */

#include <stdio.h>

int main()
{
  char caracter;
  bool vocal = false;

  printf("Entra una letra: ");
  scanf("%c", &caracter);

  switch (caracter)
  {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      vocal = true;
    break;
  }

  if(caracter == 'a' || caracter == 'A') // faltan las otras vocales
  {
    vocal = true;
  }

  printf("%c ", caracter);
  if(!vocal) printf("no ");
  printf("es una vocal");


  return 0;
}