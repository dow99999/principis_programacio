#include <stdio.h>

void elfor(char palabra[7]);
void elwhile(char palabra[7]);

void pausa();
char menu();

const char FOR = 'a';
const char WHILE = 'b';
const char SALIR = 'c';

int main()
{
  char palabra[7] = {'p', 'a', 'l', 'a', 'b', 'r', 'a'};
  char o;

  do
  {
    o = menu();

    switch (o)
    {
    case FOR:
      elfor(palabra);
      break;

    case WHILE:
      elwhile(palabra);
      break;
      
    case SALIR: break;

    default:
      printf("ERROR: la opcio no existeix\n");
    }
    pausa();

  } while (o != SALIR);

  printf("Adiooos!!!");

  return 0;
}

void elfor(char palabra[7])
{

  for (int i = 6; i >= 0; i--)
  {
    printf("%c", palabra[i]);
  }

  printf("\n");
}

void elwhile(char palabra[7])
{
  int i = 0;

  while (i < 7)
  {
    printf("%c", palabra[i]);
    i++;
  }
  printf("\n");
}

void pausa()
{
  while(getchar() != '\n');
  printf("Pressiona una tecla per a continuar...");
  getchar();
}

char menu()
{
  char o;

  printf("%c. El for\n", FOR);
  printf("%c. El while\n", WHILE);
  printf("%c. Sortir\n", SALIR);
  printf("Entra la opcio: ");
  scanf("%c", &o);

  return o;
}