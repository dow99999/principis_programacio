/**
 * Entrada y salida de datos por terminal
 *
 * Salida de datos:
 * printf("Mensaje %d", variable); -> para mostrar por pantalla
 *
 * Entrada de datos:
 * scanf("%f", &variable); -> obtiene un float entrado por terminal
 *        |→ tipo de datos que queremos leer
 *                 |→ la dirección de la variable en la que guardaremos el dato
 *
 * & es el operador dirección, al ponerlo delante de una variable se obtiene su dirección de memoria.
 * & es un operador unario, solo necesita un operando, en este caso detras del operador.
 */

/**
 * Autor: Diego
 */

// Standard Input Output
#include <stdio.h>
// Console Input Output
#include <conio.h>

// Primer ejercicio
#define PI 3.1416

// Segundo ejercicio
#define IVA 0.21
#define IRPF 0.15
#define PRECIO_HORA 18.5

int main()
{
  /**
   * Modificar el programa de cálculo de longitud de una circumferencia para
   * pedir por pantalla el radio en vez de tenerlo como literal en el código
   */
  // float
  //     radio = 0,
  //     longitud = 0;

  // printf("Entra el valor del radio: ");
  // scanf("%f", &radio);

  // longitud = 2 * PI * radio;

  // printf("La longitud de la circumferencia es %f", longitud);


  // -----------------------------------------------------------------------------------------------



  /* Calcular el total de una factura sabiendo que el precio hora es 18.5€
  Las horas se piden por pantalla (números decimales).

  El total bruto es: horas * PRECIO_HORA
  La retención es: total * IRPF
  El neto es: (bruto - retencion) * IVA
  */

  // Declarar variables
  float
      horas     = 0,
      bruto     = 0,
      retencion = 0,
      neto      = 0,
      total_iva = 0;

  // Pedir datos necesarios por pantalla
  printf("Entra las horas trabajadas: ");
  scanf("%f", &horas);

  // Procesar la información
  bruto = horas * PRECIO_HORA;
  retencion = bruto * IRPF;
  total_iva = (bruto - retencion) * IVA;
  neto = bruto - retencion + total_iva;

  // Visualizar los resultados
  printf("+- Entrada --------------------------------\n");
  printf("| IVA: \t\t\t%f%\n", IVA*100);
  printf("| IRPF: \t\t%f%\n", IRPF*100);
  printf("| PRECIO HORA: \t\t%fE\n", PRECIO_HORA);
  printf("| Horas trabajadas: \t%fh\n", horas);
  printf("|\n");
  printf("+- Salida ---------------------------------\n");
  printf("| Bruto: \t%fE\n", bruto);
  printf("| Retencion: \t%fE\n", retencion);
  printf("| Total IVA: \t%fE\n", total_iva);
  printf("| Neto: \t%fE\n", neto);
  printf("+------------------------------------------\n");
  printf("Presiona enter para continuar...");
  getch();

  return 0;
}
