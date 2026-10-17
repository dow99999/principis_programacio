/**
 * Introducir dos numeros por teclado x e y y intercambiar los valores y
 * volver a visualizarlos.
 */

 /**
  * Autor: Diego
  */

#include <stdio.h>

int main()
{
  int x = 0, y = 0;
  // int aux = 0;

  // printf("Entra un entero: ");
  // scanf("%d", &x);
  // printf("Entra otro entero: ");
  // scanf("%d", &y);

  // printf("Estado inicial: x=%d y=%d\n", x, y);

  // aux = x;
  // x = y;
  // y = aux;

  // printf("Estado final: x=%d y=%d", x, y);
  
  // Lo mismo pero mas interesante, aunque no funciona con numeros decimales
  printf("Entra un entero: ");
  scanf("%d", &x);
  printf("Entra otro entero: ");
  scanf("%d", &y);

  printf("Estado inicial: x=%d y=%d\n", x, y);

  // Teniendo en cuenta que aplicar xor de un numero a otro dos veces recupera el primer valor, es decir: que N xor M xor M = N
  x ^= y; // en x tengo x xor y
  y ^= x; // en y tengo x, ya que (x xor y) xor y = x
  x ^= y;  // en x tengo y, ya que (x xor y) xor x recupera y

  printf("Estado final: x=%d y=%d", x, y);
  

  return 0;
}