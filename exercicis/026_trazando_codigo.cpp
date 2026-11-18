#include <cstdio>

void primero()
{
  const int CLAVE = 2025;

  int intento, acertado = 0;

  for (int i = 1; i <= 3; i++)
  {
    printf("intento %d. Contraseña:", i);
    scanf("%d", &intento);

    if (intento == CLAVE)
    {
      acertado = 1;
      break;
    }

    printf("Incorrecta\n");
  }

  if (acertado)
    printf("Acceso permitido\n");
  else
    printf("Acceso bloqueado\n");
}

void segundo()
{
  for (int i = 0; i <= 15; i++)
  {
    if (i % 3 == 0)
    {
      continue;
    }

    printf("%d", i);
  }
}

int main()
{
  // primero();
  segundo();
  return 0;
}