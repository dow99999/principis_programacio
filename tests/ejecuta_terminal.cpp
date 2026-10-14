#include <stdio.h>

// para la funcion system
// #include <stdlib.h>

#include <windows.h>

int main()
{

  STARTUPINFO si;
  PROCESS_INFORMATION pi;

  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  ZeroMemory(&pi, sizeof(pi));

  if (!CreateProcess(TEXT("C:/Users/diego/Documents/2627/programacion/principis_programacio/tests/main.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
  {
    printf("Mal");
  }
  else
  {
    printf("Bien");
  }

  WaitForSingleObject(pi.hProcess, INFINITE);

  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);

  return 0;
}