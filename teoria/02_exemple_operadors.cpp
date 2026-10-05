/**
 * Algunos ejemplos de uso de operadores y muestra de información por pantalla
 */

/**
 * Autor: Diego
 */

#include <stdio.h>
#include <cstdlib>

#define PI 3.1416

float radio = 3;
float longitud;

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

  longitud = PI * radio * 2;

  printf("El perimetre d'un cercle de radi %f es %f", radio, longitud);

  return 0;
}

/*
    Tendremos que darle nombre a: funciones, constantes y variables.
    A estos "nombres" se les llaman identificadores.

    Reglas para escribir identificadores:
    - Debe empezar por un carácter alfabético (A-Za-z). Algunas variables de bajo nivel pueden empezar por _
    - Las constantes siempre se escribirán en mayúscula
    - Las variables siempre se escribirán en minúscula
    - No podemos usar palabras reservadas del lenguaje
    - No podemos construir identificadores con * , ; . : + - etc
    - Se pueden usar _ para separar palabras
    - Pueden tener hasta 32 carcateres



    Tipos de operadores:

    Aritméticos:
        suma: +
        resta: -
        multiplicación: *
        división: /
        módulo: %

    Asignación:
        = -> e.g. x = 2 + 3
        =[operador aritmético] -> e.g. x += 2

    Unarios:
        positivo: +
        negativo: -

    Condicional: "?:"

    Incrementales:
        Sumar 1: ++
        Restar 1: --

        No es lo mismo ++x que x++, el primero primero suma y luego devuelve el valor,
        el segundo primero devuelve el valor y luego suma 1


        Para el próximo día:
        declarar dos enteros (o 3 si queremos guardar el resultado) y aplicar todas las operaciones aritméticas con ellos.
*/

/*
Para mostrar cosas por pantalla utilizaremos la función printf
Para usar esta función necesitaremos incluir la libreria stdio.h

el input estándard es el teclado
el output estándard es la pantalla

para usar el printf:

sin variables: printf("mensaje");
con variables: printf("El valor es %d", valor);

*/