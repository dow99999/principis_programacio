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




#define SALIR         '0'
#define SUMA          '1'
#define RESTA         '2'
#define MULTIPLICACIO '3'
#define DIVISION      '4'
#define RESTO         '5'
#define SQRT          '6'



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
 * Esta funcion suma dos numeros pasados por parametro y devuelve el resultado
 *
 * @param x el primer operador de la suma
 * @param y el segundo operador de la suma
 * @returns el resultado de la suma
 */
double suma(double x, double y)
{
  return (x + y);
}

/**
 * Esta funcion resta dos numeros pasados por parametro y devuelve el resultado
 *
 * @param x el primer operador de la resta
 * @param y el segundo operador de la resta
 * @returns el resultado de la resta
 */
double resta(double x, double y)
{
  return suma(x, -y);
}

/**
 * Esta funcion multiplica dos numeros pasados por parametro y devuelve el resultado
 *
 * @param x el primer operador de la multiplicacion
 * @param y el segundo operador de la multiplicacion
 * @returns el resultado de la multiplicacion
 */
double multiplica(double x, double y)
{
  return (x * y);
}

/**
 * Esta funcion divide dos numeros pasados por parametro y devuelve el resultado
 *
 * @param x el primer operador de la division
 * @param y el segundo operador de la division
 * @returns el resultado de la division
 */
double divide(double x, double y)
{
  return (x / y);
}

/**
 * Esta funcion calcula el resto de la division entera de dos numeros
 * pasados por parametro y devuelve el resultado
 *
 * @param x el primer operador de la division entera
 * @param y el segundo operador de la division entera
 * @returns el resultado del resto de la division entera
 */
int resto(int x, int y)
{
  return (x % y);
}

int main()
{
  // opcion escojida
  char operacion = ' ';

  double
      // primer operador
      o1 = 0,
      // segundo operador
      o2 = 0;

  
  operacion = menu();

  // Pedimos los datos necesarios segun la operacion
  switch (operacion)
  {
  case SUMA:
  case RESTA:
  case MULTIPLICACIO:
  case DIVISION:
  case RESTO:
    printf("Entra el primer operador: ");
    scanf("%lf", &o1);
    printf("Entra el segundo operador: ");
    scanf("%lf", &o2);
    break;

  case SQRT:
    printf("Entra el primer operador: ");
    scanf("%lf", &o1);
    break;
  }

  // Calculamos el resultado de la operacion
  switch (operacion)
  {
  case SUMA:
    printf("El resultado de la suma es %f", suma(o1, o2));
    break;

  case RESTA:
    printf("El resultado de la resta es %f", resta(o1, o2));
    break;

  case MULTIPLICACIO:
    printf("El resultado de la multiplicacion es %f", multiplica(o1, o2));
    break;

  case DIVISION:
    printf("El resultado de la division es %f", divide(o1, o2));
    break;

  case RESTO:
    printf("El resultado de la division es %d", resto((int)o1, (int)o2));
    break;

  case SQRT:
    printf("El resultado de la raiz cuadrada es %f", sqrt(o1));
    break;

  case SALIR:
    printf("Adios!!");
    break;

  default:
    printf("ERROR: la operacion no existe");
  }
}