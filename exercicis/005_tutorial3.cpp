/**
 *     3.  Escriba un programa en C que convierta euros a dolares (1 euro = 1.286 dolares) y a
 *         libras esterlinas (1 euro = 0,865 libras). Imprima los resultados por pantalla.
 */

/**
 * Autor: Diego
 */

#include <stdio.h>

int main()
{
    const float EURO_DOLAR = 1.286;
    const float EURO_LIBRA = 0.865;

    float euro = 0;

    printf("Entre un valor en euros: ");
    scanf("%f", &euro);

    printf("Dolares: %.2f\n", euro * EURO_DOLAR);
    printf("Libras esterlinas: %.2f\n", euro * EURO_LIBRA);

    return 0;
}