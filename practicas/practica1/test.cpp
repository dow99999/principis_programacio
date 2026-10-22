#include <stdio.h>
#include <string.h>

#include <Windows.h>

typedef struct
{
    const char *in;
    const char *out;
} Test;

int main()
{
    // const unsigned char TESTS = 15;

    // Test tests[TESTS] = {
    //     {"1 -3 2", "Dos soluciones reales: x1 = 2.0000, x2 = 1.0000"},
    //     {"1 -2 1", "Una solucion doble: x = 1.0000"},
    //     {"1 2 5", "Complejas: x1 = -1.0000 + 2.0000i, x2 = -1.0000 - 2.0000i"},
    //     {"1 0 4", "Complejas: x1 = 0.0000 + 2.0000i, x2 = 0.0000 - 2.0000i"},
    //     {"-1 2 -5", "Complejas: x1 = 1.0000 + 2.0000i, x2 = 1.0000 - 2.0000i"},
    //     {"2 2 1", "Complejas: x1 = -0.5000 + 0.5000i, x2 = -0.5000 - 0.5000i"},
    //     {"2 3 1", "Dos soluciones reales: x1 = -0.5000, x2 = -1.0000"},
    //     {"4 4 1", "Una solucion doble: x = -0.5000"},
    //     {"0 2 -4", "Ecuacion lineal: x = 2.0000"},
    //     {"0 2 3", "Ecuacion lineal: x = -1.5000"},
    //     {"0 0 0", "Infinitas soluciones"},
    //     {"0 0 5", "Sin solucion"},
    //     {"2 0 -8", "Dos soluciones reales: x1 = 2.0000, x2 = -2.0000"},
    //     {"1 0 0", "Una solucion doble: x = 0.0000"},
    //     {"-1 3 0", "Dos soluciones reales: x1 = 0.0000, x2 = 3.0000"}
    // };

    // // he visto que sizeof(tests)/sizeof(tests[0]) da el numero de elementos, pero ya que los he de definir en el array mejor lo pongo en una constante

    // for(unsigned char i = 0; i < TESTS; i++)
    // {
    //     printf("Test %d\n", i);
    //     printf("  IN: %s\n", tests[i].in);
    //     printf("  OUT: %s\n", tests[i].out);
    //     printf("es diferente a -1 3 0? %d\n", strcmp(tests[i].in, "-1 3 0"));
    // }

    STARTUPINFOW si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(si);
    si.dwFlags |= STARTF_USESTDHANDLES;

    HANDLE escritura = {0};
    HANDLE lectura = {0};

    wchar_t comando[] = L"../../lib/terminal_utils/colores.exe";
    wchar_t argumentos[] = L"../../lib/terminal_utils/colores.exe -h";

    SECURITY_ATTRIBUTES sa = {0};
    sa.nLength = sizeof(sa);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;

    if (!CreatePipe(
            &lectura,
            &escritura,
            &sa,
            0))
    {
        printf("Fallo al crear los canales de comunicacion con el subproceso");
        return -1;
    };

    SetHandleInformation(
        lectura,
        HANDLE_FLAG_INHERIT,
        0
    );

    // va despues porque CreatePipe inicializa los HANDLE de escritura y lectura
    si.hStdOutput = escritura;

    // he puesto NULL en los parametros opcionales
    bool resultado = CreateProcessW(
        comando,
        argumentos,
        NULL,
        NULL,
        true,
        0,
        NULL,
        NULL,
        &si,
        &pi);

    if (!resultado)
    {
        printf("Error: %d\n", GetLastError());
    }
    else
    {
        CloseHandle(escritura);

        DWORD respuesta_ejecucion = WaitForSingleObject(pi.hProcess, 20000);
        printf("Respuesta ejecucion: %d\n", respuesta_ejecucion);

        switch (respuesta_ejecucion)
        {
        case WAIT_OBJECT_0:
            printf("Ejecucion correcta\n");
            // Miramos que tal ha ido el intento de ejecucion del proceso.
            unsigned long int exit_code;
            if (GetExitCodeProcess(pi.hProcess, &exit_code))
            {
                printf("Bien recuperado el codigo de salida\n");
                printf("exit code: %lu\n", exit_code);
            }
            else
            {
                printf("Mal recuperado el codigo de salida\n");
            }

            break;
        case WAIT_TIMEOUT:
            printf("Timeout :(\n");
            break;
        case WAIT_FAILED:
            printf("Ha ocurrido un error\n");
            break;

        default:
            printf("A saber lo que ha pasado");
        }

        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    }

    CloseHandle(lectura);

    return 0;
}