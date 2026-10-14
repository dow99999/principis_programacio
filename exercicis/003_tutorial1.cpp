/**
 *     1. Dado el siguiente fragmento de código, identifique las declaraciones de variables,
 *        las instrucciones de asignación, los operadores y las expresiones.
 *        ¿Cuál será el resultado de evaluar esas expresiones?
 *      
 *      Nota: El operador división se comporta de diferente forma según el tipo de datos de
 *      los operandos: si son números enteros el resultado será también un número entero. Si
 *      los operandos son números reales, el resultado será también un número real. Si uno de
 *      los dos es entero y otro real, el entero se convierte a real y la operación se hace entre reales.
 */

/**
 * Autor: Diego
 */

#include <stdio.h>

int main()
{
    int i1, i2, i3;     // declaracion de variables
    float r1, r2, r3;   // declaracion de variables
    i1 = 12;            // asignacion con el operador =     | resultado 12
    i2 = 5;             // asignacion con el operador =     | resultado 5
    r1 = 12.0;          // asignacion con el operador =     | resultado 12.0
    r2 = 5;             // asignacion con el operador =     | resultado 5.0
    r3 = r1 / r2;       // operador /                       | resultado 2.4
    // printf("%f ", r3);
    r3 = i1 / i2;       // operador /                       | resultado 2.0
    // printf("%f ", r3);
    i3 = i1 / r2;       // operador /                       | resultado 2
    // printf("%d ", i3);

    return 0;
}