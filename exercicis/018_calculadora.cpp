/**
 * Un programa que simule una calculadora solo aritmetica (sumar, restar, multiplicar,
 *   dividir, calcular el resto de la division entera y hacer la raiz cuadrada).
 *
 * Lo primero que va ha hacer es
 */

/**
 * Autor: Diego Muñoz Jorquera
 */

#include <stdio.h>
#include <math.h>

/**
 * Esta funcion muestra por pantalla un menu y espera que el usuario escoja una opcion
 *
 * @returns la opcion entrada por el usuario
 */
char menu()
{
  char op = '0';

  printf("+- Calculadora ---------------------------------\n");
  printf("| 1. Sumar\n");
  printf("| 2. Restar\n");
  printf("| 3. Multiplicar\n");
  printf("| 4. Dividir\n");
  printf("| 5. Resto de la division\n");
  printf("| 6. Raiz cuadrada\n");
  printf("| 0. Salir\n");
  printf("+-----------------------------------------------\n");
  printf("| Entra una opcion: ");
  scanf("%c", &op);

  return op;
}

/**
 * Esta funcion suma dos numeros pasados por parametro y devuelve la suma
 * 
 * @param x el primer operador de la suma
 * @param y el segundo operador de la suma
 * @returns el resultado de la suma
 */
double suma(double x, double y)
{
  return (x + y);
}

double resta(double x, double y)
{
  return suma(x, -y);
}

double multiplica(double x, double y)
{
  return (x * y);
}
double divide(double x, double y)
{
  return (x / y);
}
int resto(int x, int y)
{
  return (x % y);
}

int main()
{
  char operacion = ' ';
  double
      o1 = 0,
      o2 = 0;

  operacion = menu();

  switch (operacion)
  {
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
    printf("Entra el primer operador: ");
    scanf("%lf", &o1);
    printf("Entra el segundo operador: ");
    scanf("%lf", &o2);
    break;

  case '6':
    printf("Entra el primer operador: ");
    scanf("%lf", &o1);
    break;
  }

  switch (operacion)
  {
  case '1':
    printf("El resultado de la suma es %f", suma(o1, o2));
    break;

  case '2':
    printf("El resultado de la resta es %f", resta(o1, o2));
    break;

  case '3':
    printf("El resultado de la multiplicacion es %f", multiplica(o1, o2));
    break;

  case '4':
    printf("El resultado de la division es %f", divide(o1, o2));
    break;

  case '5':
    printf("El resultado de la division es %d", resto((int)o1, (int)o2));
    break;

  case '6':
    printf("El resultado de la raiz cuadrada es %f", sqrt(o1));
    break;

  case '0':
    printf("Adios!!");
    break;

  default:
    printf("ERROR: la operacion no existe");
  }
}