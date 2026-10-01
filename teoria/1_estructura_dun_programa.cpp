/**
 * Enunciado: este programa muestra por pantalla
 * el texto definido entre comillas
 */

/**
 * Autor: Diego
 */

// Por cada librería pondremos un nuevo #include
// A todo lo que empieza con # se le llama 'directivas del preprocesador'

#include <iostream> // La librería del lenguaje donde están las funciones que vamos a usar en el programa


// También se le pueden definir constantes al preprocesador (#define nombre valor):
#define PI 3.1416
#define IVA 0.21
#define SALUDO "Buenos días"
// El #define le dice al preprocesador que cambie cambie las constantes en el programa por los valores definidos

// Números enteros
int x; // Números positivos y negativos sin decimales
unsigned int y; // Números positivos sin decimales

// Números reales
// Para definir números reales los podemos definir con float (32 bits) o double ( mucha más precisión que un float).
float f; // Positivo y negativo con decimales
double d; // Positivo y negativo con decimales (con más espacio)


using namespace std;

int main()
{
  cout << "otra cosa: " << endl;

  return 0;
}



/* Estructura de un programa en C

  1º Directivas del preprocesador
  2º Definición de constantes
  3º Declaración de variables globales
  4º Prototipo/cabecera/firma de funciones

  C++ es un lenguaje de medio nivel, porque se pueden tocar posiciones de memoria
  cosas a bajo nivel pero su sintaxis no es lenguaje máquina

  Java es un lenguaje interpretado porque pasa de codigo fuente a codigo compilado para la máquina virtual.



  -- Formación de un ejecutable en C++: ------------------------------------------

  1º tenemos un código fuente con extensión .cpp

  2º el código pasa por el compilador y se crea un archivo .obj

  3º el .obj se enlaza mediante el linkador con las librerías de C++

  4º se genera el ejecutable .exe

  --------------------------------------------------------------------------------


  la nada en C++ se llama void, es un tipo de dato

*/
