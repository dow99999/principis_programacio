#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include <iostream>
#include <windows.h>

int main()
{
  const int WAIT = 1000/30;

  for (int k = 1; k < 20; k++)
  {
    for (int j = 0; j < 15; j++)
    {
      for (int i = j; i < 100; i++)
      {
        printf(i % k == 0 ? "." : " ");
      
      }
      printf("\n");

    }


    Sleep(WAIT);
    system("cls");
  }

  return 0;
}