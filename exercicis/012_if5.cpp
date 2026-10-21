/**
 * 5. Escriba un programa en C que muestre por pantalla el valor de una entrada de cine en
 * función de los años de la persona. Así, el precio es de 7 Euros, pero si el usuario tiene
 * menos de 5 años se aplica un 60% de descuento, y si es mayor de 60 años, se aplicará
 * un descuento del 55 %. El precio de la entrada se debe declarar como una constante.
 */

/**
 * Autor: Diego Muñoz Jorquera
 */

#include <stdio.h>

int main()
{
  const short int PRECIO_ENTRADA  = 7;
  const short int DESC_MIN_EDAD   = 5;
  const short int DESC_MAX_EDAD   = 60;
      const float DESC_MIN_PORC   = 0.6;
      const float DESC_MAX_PORC   = 0.55;

  unsigned short int edad = 0;
  
  float
    precio = 0,
    descuento = 0;


  printf("Entra la edad de la persona: ");
  scanf("%hu", &edad);

  if(edad < DESC_MIN_EDAD)
  {
    descuento = DESC_MIN_PORC;

  } else if (edad > DESC_MAX_EDAD) 
  {
    descuento = DESC_MAX_PORC;

  }

  // precio = PRECIO_ENTRADA - descuento * PRECIO_ENTRADA;
  precio = PRECIO_ENTRADA * (1 - descuento);

  printf("La entrada vale %fE", precio);

  return 0;
}