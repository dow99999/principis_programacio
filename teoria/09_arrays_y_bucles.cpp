#include <stdio.h>

/**
 * Autor: Diego Muñoz Jorquera
 */

int main()
{
  int valores[5] = {3, 7, 1, 8, -5};
  int pos = 0;

  for (int i = 0; i < 5; i++)
  {
    printf("La posicion %d vale %d\n", i, valores[i]);
  }

  // printf("Entra una posicion a ver: ");
  // scanf("%d", &pos);

  // printf("%d: %d\n", pos, valores[pos]);

  printf("\n");
  
  int i = 0;

  while (i < 5)
  {
    printf("La posicion %d vale %d\n", i, valores[i]);
    i++;
  }

  return 0;
}

/**
 * Tipos de datos simples vs tipos de datos estructurados
 *
 * Los tipos de datos simples solo guardan un valor, los tipos de datos
 *   estructurados pueden contener múltiples valores de un mismo tipo.
 *
 * Los arrays nos permiten guardar múltiples datos de un
 *  mismo tipo en una misma variable:
 *
 *  int valores[5] = { 3, 7, 1, 8, -5 };
 *   ↓          |      ↓
 * Tipo de dato |    Valores del array
 *              ↓
 *            Dimension del array
 *
 * Para acceder a los datos de un array: se hace a través de su índice.
 * El índice empieza en 0 y acaba en la longitud-1 del array.
 *
 * Algunos ejemplos de acceso a valores de un array:
 *
 *  valores[0] // primer valor (3)
 *  valores[4] // quinto/último valor (-5)
 *
 * No se puede hacer:
 *  valores[-1] // es inferior a 0
 *  valores[5]  // se pasa de longitud-1
 *
 */

/**
 * Bucles
 *
 * Todos se basan en ejecutar un bloque de código múltiples veces
 *  en base a una condición.
 *
 * for:
 *    Condición del bucle
 *      Iterador ↑   Modificación del iterador en cada iteración
 *       ↑       |    ↑
 * for(int i; i < 5; i++)
 * {
 *  // Codigo a ejecutar en cada iteración
 * }
 *
 *
 *
 * while:
 * int i = 0; → iterador
 *
 *        Condición del bucle
 *          ↑
 * while (i < 5)
 * {
 *   // Código a ejecutar en cada iteración
 * 
 *   i++;
 *    ↑
 *  Modificación del iterador en cada iteración
 * }
 *
 */