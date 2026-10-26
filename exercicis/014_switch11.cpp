/**
 * 11. Escriba un programa en C que lea un carácter y utilizando la instrucción switch
 *   determine si es o no una vocal. Realice el mismo ejercicio
 *   utilizando la sentencia if ¿Qué opción es mejor?
 */

#include <stdio.h>

int main()
{
  char c = '-';

  printf("Entra una letra: ");
  scanf("%c", &c);

  switch (c)
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
    printf("Es vocal");
    break;
  default:
    printf("No es vocal");
  }

  if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
  {
    printf("Es vocal");
  }
  else
  {
    printf("No es vocal");
  }

  return 0;
}