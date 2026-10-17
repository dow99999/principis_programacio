/**
 * Escriba un programa que pregunte al usuario su edad, y luego compruebe si es mayor de 21 años.
 * Si es mayor deberá escribir un 1 y si es menor un 0.
 * El ejercicio se debe resolver usando operadores relacionales.
 * Recuerde que el resultado de evaluar una expresión verdadera en C (por ejemplo 7>5) es 1, y el de evaluar una falsa (7
 */

#include <stdio.h>

int main()
{
    // No tiene sentido una edad negativa y no hace falta demasiado espacio para guardar una edad
    const unsigned short int MAX_EDAD = 21;
    unsigned short int edad = 0;

    printf("Entra tu edad: ");
    scanf("%d", &edad);

    printf("%i", edad >= MAX_EDAD);

    return 0;
}