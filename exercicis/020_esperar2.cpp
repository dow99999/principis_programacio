#include <iostream>
#include <locale.h>


#define SALUDO "\t Buenos días Diego"

void pausa();
void activar_acentos();

int main()
{
  activar_acentos();
  printf(SALUDO);
  pausa();
  return 0;
}

void activar_acentos()
{
  setlocale(LC_ALL, "");
}

void pausa()
{
  char c;
  printf("\n \n \tPulse tecla para continuar...\n");
  scanf("%c", &c);
}