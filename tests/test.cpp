#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

#include <Windows.h>

typedef struct
{
    char *in;
    char *out;
} Test;

// Longitud del buffer de lectura, en bytes
const int BUFFER_LN = 4 * 1024;

// longitud del buffer acumulador (longitud maxima del output del programa), en bytes
const int ACUM_LN = 128 * 1024;

std::wstring CharToWString(const char* str) {
    if (!str || str[0] == '\0') {
        return L"";
    }

    // 1. Calcular el tamaño necesario del buffer wchar_t
    int size_needed = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
    if (size_needed <= 0) return L"";

    // 2. Crear el string vacío y redimensionarlo de forma segura
    std::wstring wstrTo;
    wstrTo.resize(size_needed - 1);

    // 3. Realizar la conversión escribiendo directamente en la memoria del string
    MultiByteToWideChar(CP_ACP, 0, str, -1, &wstrTo[0], size_needed);

    return wstrTo;
}

std::vector<Test> generar_tests(char* in_file_path, char* out_file_path)
{
    std::vector<Test> tests;


    FILE *fin = fopen(in_file_path, "rb");
    FILE *fout = fopen(out_file_path, "rb");

    if (fin == NULL || fout == NULL)
    {
        printf("Error: faltan los archivos de test");
        return tests;
    }

    char buffer[BUFFER_LN];
    char *in_acum = (char*) calloc(ACUM_LN, sizeof(char));
    char *out_acum = (char*) calloc(ACUM_LN, sizeof(char));
    char *in_acum_ptr = in_acum;
    char *out_acum_ptr = out_acum;
    int i = 0;


    while (fgets(buffer, BUFFER_LN, fin) != NULL)
    {
        strcat(in_acum, buffer);
    }

    while (fgets(buffer, BUFFER_LN, fout) != NULL)
    {
        strcat(out_acum, buffer);
    }

    while (true)
    {
        char *sep_in = strstr(in_acum_ptr, "\r\n\r\n");
        
        // tests[i].in = ;
        // tests[i].out = ;

        tests.push_back({in_acum_ptr, out_acum_ptr});

        char *sep_out = strstr(out_acum_ptr, "\r\n\r\n");

        if (sep_in != NULL)
        {
            *sep_in = '\0';
            in_acum_ptr = sep_in + 4;
        }
        else
        {
            break;
        }
        
        if (sep_out != NULL)
        {
            *sep_out = '\0';
            out_acum_ptr = sep_out + 4;
        }
        else
        {
            break;
        }

        i++;
    }

    fclose(fin);
    fclose(fout);

    return tests;
}

bool recompilar_programa()
{
    STARTUPINFOW si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(si);

    wchar_t argumentos[] = L"g++ main.cpp -o main.exe";

    bool status = CreateProcessW(
                      NULL,
                      argumentos, // argumentos a pasar al programa
                      NULL,
                      NULL,
                      false, // No hay PIPEs que son controladas por el subproceso, asi que true
                      0,
                      NULL,
                      NULL,
                      &si,
                      &pi)
                      ? true
                      : false;
    if (!status)
        printf("E: %lu\n", GetLastError());

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return status;
}

int main(int argc, char **argv)
{
    
    if(argc != 4)
    {
        printf("Uso: test <input.txt> <output.txt> <programa.exe>\n");
        printf("  Debe haber el mismo numero de bloques de entrada que de salida en los archivos de test.\n");
        printf("  Una linea vacia define la separacion entre dos bloques de test.\n");
        return 0;
    }
    
    std::vector<Test> tests = generar_tests(argv[1], argv[2]);

    if(tests.size() == 0)
    {
        printf("Error: no hay tests a probar");
        return -1;
    }

    unsigned char errores = 0;

    // if (!recompilar_programa())
    // {
    //     printf("Error: No se ha podido recompilar el programa\n");
    //     return -1;
    // }

    for (unsigned char i = 0; i < tests.size(); i++)
    {
        // Definicion de las variables con las que gestionamos el control del subproceso
        STARTUPINFOW si = {0};
        PROCESS_INFORMATION pi = {0};
        si.cb = sizeof(si);
        si.dwFlags |= STARTF_USESTDHANDLES;

        // Definicion de las variables con las que gestionan las pipes de stdin y stdout
        HANDLE escritura_salida_programa = {0};
        HANDLE lectura_salida_programa = {0};
        HANDLE escritura_entrada_programa = {0};
        HANDLE lectura_entrada_programa = {0};

        // Necesario para que el subproceso pueda heredar el control sobre las pipes creadas en el padre
        SECURITY_ATTRIBUTES sa = {0};
        sa.nLength = sizeof(sa);
        sa.lpSecurityDescriptor = NULL;
        sa.bInheritHandle = TRUE;

        // programa a ejecutar
        std::wstring comando = CharToWString(argv[3]);
        // wchar_t argumentos[] = L"main.exe -h"; // ejemplo para pasar argumentos al programa

        // Intentamos crear los canales de comunicacion con el subproceso, tanto el de stdin como el de stdout

        // Para el stdout del subproceso
        if (!CreatePipe(
                &lectura_salida_programa,
                &escritura_salida_programa,
                &sa,
                0))
        {
            printf("Fallo al crear los canales de comunicacion (lectura) con el subproceso");
            return -1;
        };

        // Para el stdin del subproceso
        if (!CreatePipe(
                &lectura_entrada_programa,
                &escritura_entrada_programa,
                &sa,
                0))
        {
            printf("Fallo al crear los canales de comunicacion (escritura) con el subproceso");
            return -1;
        };

        // Permitimos a las PIPEs que controla el subproceso que pueden ser heredables
        if (!SetHandleInformation(
                lectura_salida_programa,
                HANDLE_FLAG_INHERIT,
                0))
        {
            printf("Error al configurar el handle de lectura");
            return -1;
        }

        if (!SetHandleInformation(
                escritura_entrada_programa,
                HANDLE_FLAG_INHERIT,
                0))
        {
            printf("Error al configurar el handle de escritura");
            return -1;
        }

        // Si todo ha ido bien, asignamos al stdout y al stdin las PIPEs creadas anteriormente
        si.hStdOutput = escritura_salida_programa;
        si.hStdInput = lectura_entrada_programa;

        bool resultado = CreateProcessW(
            comando.c_str(),
            NULL, // argumentos a pasar al programa
            NULL,
            NULL,
            true, // Hay PIPEs que son controladas por el subproceso, asi que true
            0,
            NULL,
            NULL,
            &si,
            &pi);

        if (!resultado)
        {
            // En caso que no se haya podido crear el subproceso mostramos su codigo de error
            printf("Error %d: No se ha podido crear el subproceso\n", GetLastError());
            return -1;
        }
        else
        {
            // Cerramos los handles del lado del subproceso, no los necesitamos en el parent
            CloseHandle(escritura_salida_programa);
            CloseHandle(lectura_entrada_programa);

            // Inicializamos un test

            // Buffer acumulador del output total del programa
            char acumulado[ACUM_LN];
            DWORD bacumulado = 0; // aqui contamos los bytes totales leidos

            // Buffer del output parcial del programa
            char leido[BUFFER_LN];
            DWORD bleido = 0; // aqui contamos los bytes totales leidos

            bool resultado_lectura;
            DWORD bescrito = 0; // esto no lo gestionamos, pero WriteFile lo pide

            // Enviamos los datos de entrada al subproceso
            if (!WriteFile(
                    escritura_entrada_programa,
                    tests[i].in,
                    strlen(tests[i].in),
                    &bescrito,
                    NULL))
            {
                printf("ERROR: No se ha podido escribir en la comunicacion con el subproceso");
                return -1;
            }

            CloseHandle(escritura_entrada_programa); // avisamos que la entrada de datos ha terminado cerrando el handle de escritura

            // Leemos la salida del subproceso hasta que termine de escribir
            do
            {
                resultado_lectura = ReadFile(
                    lectura_salida_programa,
                    leido,
                    sizeof(leido),
                    &bleido,
                    NULL);

                // Si no hay nada a leer saltamos al final
                if (!resultado_lectura)
                    continue;

                // En caso que no quepa en el buffer acumulador
                if (bleido > sizeof(acumulado) - bacumulado)
                {
                    printf("ERROR: La salida del programa es demasiado larga.");
                    return -1;
                }

                // Guardamos la salida acumulada
                memcpy(acumulado + bacumulado, leido, bleido);
                bacumulado += bleido;

            } while (resultado_lectura);

            // Si hemos salido por un error con el subproceso, lo mostramos
            if (GetLastError() != ERROR_BROKEN_PIPE)
            {
                printf("ERROR: Error en la lectura del canal de comunicacion");
                return -1;
            }

            // Esperamos a que la ejecucion del subproceso termine
            DWORD respuesta_ejecucion = WaitForSingleObject(pi.hProcess, 20000);
            // printf("Respuesta ejecucion: %d\n", respuesta_ejecucion);

            switch (respuesta_ejecucion)
            {

            // Caso en el que el cierre del subproceso ha sido correcto
            case WAIT_OBJECT_0:
                // printf("Ejecucion correcta\n");
                // Miramos que tal ha ido el intento de ejecucion del proceso.
                unsigned long int exit_code;
                if (GetExitCodeProcess(pi.hProcess, &exit_code))
                {
                    if (bacumulado == strlen(tests[i].out) && memcmp(tests[i].out, acumulado, bacumulado) == 0)
                    {
                        printf("%.3d Test correcto\n", i + 1);
                    }
                    else
                    {
                        printf("%.3d Test incorrecto\n", i + 1);
                        printf("Entrada: %s\n", tests[i].in);
                        printf("Se esperaba: %s\n", tests[i].out);
                        printf("  Se evalua: %.xs\n", acumulado, bacumulado);
                        errores++;
                    }
                    printf("---------------------------------------------------\n");
                }
                else
                {
                    printf("Mal recuperado el codigo de salida\n");
                }

                break;

            // Caso en el que se ha forzado el cierre del subproceso por tardar demasiado
            case WAIT_TIMEOUT:
                printf("Timeout :(\n");
                return -1;
                break;

            // Caso en el que se ha producido un error con el subproceso que no ha permitido esperar a que termine
            case WAIT_FAILED:
                printf("Ha ocurrido un error\n");
                return -1;
                break;

            // No deberia entrar nunca, pero lo gestionamos por si acaso
            default:
                printf("A saber lo que ha pasado...\n");
                return -1;
            }

            // Hemos terminado con el subproceso, asi que limpiamos los handles que aun tenemos abiertos
            CloseHandle(pi.hThread);
            CloseHandle(pi.hProcess);
        }

        CloseHandle(lectura_salida_programa);
    }

    printf("Tests superados %d/%d\n", tests.size() - errores, tests.size());

    if (errores == 0)
        printf("Todo bien, oleee!!\n");

    return 0;
}