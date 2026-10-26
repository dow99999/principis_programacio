#include <stdio.h>

int main()
{
  int
      i = 0,
      j = 10;

  if (i < j)
  {
    printf("%d es mas pequeno que %d\n", i, j);
  }
  else if (i > j)
  {
    printf("%d es mas grande que %d\n", i, j);
  }
  else
  {
    printf("%d es igual a %d\n", i, j);
  }

  switch (i < j)
  {
  case true:
    printf("%d es mas pequeno que %d\n", i, j);
    break;
  case false:
    switch (i > j)
    {
    case true:
      printf("%d es mas grande que %d\n", i, j);

      break;
    case false:
      printf("%d es igual a %d\n", i, j);
      break;
    }
    break;
  }

  return 0;
}