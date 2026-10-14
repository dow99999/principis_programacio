/**
 *     4. Indique cuáles de estas instrucciones son correctas y cuáles incorrectas, e indique cuál es el resultado de su ejecución.
 * i=i+1;
 * printf("%d", 4+20);
 * printf("suma=var_uno + var_dos = %i + %i", var_uno, var_dos, suma);
 */

/**
 * Autor: Diego
 */

#include <stdio.h>

int main()
{
    i = i + 1;  // falta declarar la variable i
    
    printf("%d", 4 + 20);   // correcto, resultado: 24
    
    printf("suma=var_uno + var_dos = %i + %i", var_uno, var_dos, suma);
    /*
        1: Falta declarar las variables var_uno, var_dos, suma
            1.1: Suponemos que las variables son enteros, en caso contrario también deberíamos cambiar el tipo de dato dentro del printf
        2: Falta mostrar por pantalla el resultado de la suma, solo se muestran los dos valores separados por un '+'
    */
}