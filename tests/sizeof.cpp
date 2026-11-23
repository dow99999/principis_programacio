#include <stdio.h>

int main()
{
  int a[3][2] = {
      {2, 3},
      {2, 7},
      {2, 4}};

  printf("%d\n", sizeof(a));
  printf("%d\n", sizeof(a[0]));
  printf("%d\n", sizeof(a[0][0]));
  printf("%d\n", sizeof(a) / sizeof(a[0]));
  printf("%d", sizeof(a[0]) / sizeof(a[0][0]));

  return 0;
}