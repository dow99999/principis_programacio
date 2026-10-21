/**
 * Descripcion de la practica:
 * 
 *   Escribe un programa en C++ que resuelva una ecuación de segundo grado de la forma:
 *     a·x^2 + b·x + c = 0
 * 
 *   El programa pedirá al usuario los coeficientes a, b y c (números enteros), calculará las soluciones y
 *     las mostrará por pantalla con un mensaje que indique de qué tipo son.
 * 
 *   Todo el programa se escribirá dentro de la función main(); no hay que crear funciones propias.
 */

/**
 * Autor: Diego Muñoz Jorquera
 */

/******************************************************************************************
 * BLOQUE 0: directivas del preprocesador
 */

// Libreria necesaria para usar las funciones scanf y printf.
#include <stdio.h>
// Libreria necesaria para usar la funcion sqrt.
#include <math.h>

// Definicion de estados segun el tipo de solucion de la equacion entrada:
#define               CALCULANDO 0
#define             UNA_SOLUCION 1
#define       UNA_SOLUCION_DOBLE 2
#define           DOS_SOLUCIONES 3
#define DOS_SOLUCIONES_COMPLEJAS 4
#define            INFINITAS_SOL 5
#define           SIN_SOLUCIONES 6

/**
 * FIN DEL BLOQUE 0
 ******************************************************************************************/





int main()
{
  /******************************************************************************************
   * BLOQUE 1: Definicion de variables
   */
  
  int a = 0;
  int b = 0;
  int c = 0;
  int discriminante = 0;
  double sol1 = 0;
  double sol2 = 0;
  double sol1i = 0;
  double sol2i = 0;
  
  unsigned char tipo_de_solucion = CALCULANDO;

  /**
   * FIN DEL BLOQUE 1
   ******************************************************************************************/
  
  
  
  
  
  
  
  /******************************************************************************************
   * BLOQUE 2: explicacion del programa y solicitud de datos
   */
  
  printf("+-----------------------------------------------------------------------\n");
  printf("| Este programa calcula las soluciones de una equacion de segundo grado.\n");
  printf("|   ax^2 + b^x + c = 0\n");
  printf("+-----------------------------------------------------------------------\n");
  printf("\n");
  printf("Entra el valor de a: ");
  scanf("%d", &a);
  printf("Entra el valor de b: ");
  scanf("%d", &b);
  printf("Entra el valor de c: ");
  scanf("%d", &c);
  
  /**
   * FIN DEL BLOQUE 2
   ******************************************************************************************/
  
  
  
  /******************************************************************************************
   * BLOQUE 3: analisis del tipo de solucion i calculo del resultado
   */
  
  if (a == 0)                                   // La equacion no es de segundo grado
  { 
    if(b != 0)                                    // La equacion es de primer grado
    {
      // cast a double para realizar la division correctamente
      sol1 = -(double)c / b;
      tipo_de_solucion = UNA_SOLUCION;
      
    } else
    {
      if(c == 0)                                  // La equacion es la identidad 0 = 0
      {
        tipo_de_solucion = INFINITAS_SOL;
        
      } else                                      // La equacion no tiene solucion
      {
        tipo_de_solucion = SIN_SOLUCIONES;
        
      }
    }
  }
  else                                          // La equacion es de segundo grado
  {
    discriminante = b * b - 4 * a * c;
    
    if(discriminante > 0) {                        // La equacion tiene dos soluciones
      tipo_de_solucion = DOS_SOLUCIONES;
      discriminante = sqrt(discriminante);

      sol1 = (-b + discriminante) / (2.0 * a);
      sol2 = (-b - discriminante) / (2.0 * a);

    } else {
      
      if (discriminante == 0)                      // La equacion tiene una solucion doble
      {
        tipo_de_solucion = UNA_SOLUCION_DOBLE;
        
        sol1 = -b / 2.0 * a;
        sol2 = sol1;
        
      }
      else                                         // La equacion solo tiene soluciones complejas
      {
        tipo_de_solucion = DOS_SOLUCIONES_COMPLEJAS;
        
        discriminante = sqrt(-discriminante);
        sol1 = -b / 2.0 * a;
        sol2 = sol1;
        sol1i = discriminante / 2.0 * a;
        sol2i = (-discriminante) / 2.0 * a;

      }
      
    }
  }

  /**
   * FIN DEL BLOQUE 2
   ******************************************************************************************/
  
  printf("\n");

  switch(tipo_de_solucion)
  {
    case UNA_SOLUCION:
      printf("Ecuacion lineal. x = %.4f", sol1);
      break;
      
    case UNA_SOLUCION_DOBLE:
      printf("Una solucion doble. x = %.4f", sol1);
      break;
      
    case DOS_SOLUCIONES:
      printf("Dos soluciones reales. x1 = %.4f, x2 = %.4f", sol1, sol2);
      break;
      
    case DOS_SOLUCIONES_COMPLEJAS:
      printf("Complejas. x1 = %.4f + %.4fi, x2 = %.4f + %.4fi", sol1, sol1i, sol2, sol2i);
      break;
    
    case INFINITAS_SOL:
      printf("Infinitas soluciones");
      break;
      
    case SIN_SOLUCIONES:
      printf("Sin solución");
      break;
    
    // No deberia entrar nunca ya que siempre se acaba dando uno de los estados anteriores
    default:
    printf("Error");

  }

  printf("\n");
  
  return 0;
}
