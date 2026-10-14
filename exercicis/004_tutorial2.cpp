/**
 * Escriba un programa que pida un tiempo en segundos y lo muestre convertido a minutos y segundos.
 */

/**
 * Autor: Diego
 */

#include <stdio.h>

int main()
{
    int tiempo = 0;

    printf("Entra un tiempo en segundos: ");
    scanf("%d", &tiempo);

    // printf("Tiempo convertido [%d:%d]", tiempo/60, tiempo%60);
    printf("Tiempo convertido [%.2d:%.2d]", tiempo / 60, tiempo % 60); // mas bonito (https://cplusplus.com/reference/cstdio/printf/)

    return 0;
}