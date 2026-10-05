#include <stdio.h>

int main()
{
  // Declarar variables
  int x, y, z;

  // Asignar valores a las variables
  x = 15;
  y = -3;

  // Instrucciones del proceso que tiene que realizar nuestro programa
  z = x + y;
  printf("La suma de x=%d y y=%d es z=%d\n", x, y, z);

  z = x - y;
  printf("La resta de x=%d y y=%d es z=%d\n", x, y, z);

  z = x * y;
  printf("La multiplicacio de x=%d y y=%d es z=%d\n", x, y, z);

  z = x / y;
  printf("La divisio de x=%d y y=%d es z=%d\n", x, y, z);

  z = x % y;
  printf("El modul de x=%d y y=%d es z=%d\n", x, y, z);

  return 0;
}