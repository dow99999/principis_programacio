/**
 * Esta aplicacion da soporte al uso de la libreria terminal_utils directamente
 * desde terminal
 */

/**
 * Autor: Diego Muñoz Jorquera
 */

#include "terminal_utils.hpp"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <list>

#define HELP          'h'
#define RESET_VISUALS 'r'
#define SET_COLOR     'c'
#define SET_BG        'b'
#define MOVE_CURSOR   'm'
#define CLEAR_SCREEN  's'
#define HIDE_CURSOR   'i'
#define SHOW_CURSOR   'v'

void print_help()
{
    printf("Para usar este programa debes pasar alguno de los siguientes parametros:\n");
    printf("\t-%c: muestra esta ayuda\n", HELP);
    printf("\t-%c: reinicia toda configuracion visual que haya podido modificar esta aplicacion\n", RESET_VISUALS);
    printf("\t-%c <r> <g> <b>: define un color de letra, los valores rgb son enteros de 0-255\n", SET_COLOR);
    printf("\t-%c <r> <g> <b>: define un color de fondo, los valores rgb son enteros de 0-255\n", SET_BG);
    printf("\t-%c <x> <y>: la x define la columna objetivo y la y la fila objetivo, ambos numeros enteros igual o superiores a 1\n", MOVE_CURSOR);
    printf("\t-%c: limpia la pantalla\n", CLEAR_SCREEN);
    printf("\t-%c: esconde el cursor\n", HIDE_CURSOR);
    printf("\t-%c: muestra el cursor\n", SHOW_CURSOR);
}

int main(int argc, char* argv[])
{
    std::list<char> instrucciones;
    std::list<int> valores;

    int consume_values = 0;

    for (int i = 1; i < argc; i++)
    {

        // Si bloque de comandos
        if(argv[i][0] == '-')
        {
            int j = 1;
            
            while(argv[i][j] != '\0')
            {
                instrucciones.push_back(argv[i][j]);
                switch(argv[i][j])
                {
                    case SET_COLOR:
                    case SET_BG:
                        consume_values += 3;
                        break;
                    case MOVE_CURSOR:
                        consume_values += 2;

                }
                j++;
            }
        } else
        {
            valores.push_back(atoi(argv[i]));
            consume_values--;
        }
    }

    if(instrucciones.empty()) {
        print_help();
        return 0;
    }

    if(consume_values > 0) {
        printf("ERROR: falta pasar parametros para las instrucciones definidas");
        return -1;
    }

    while(instrucciones.size() > 0)
    {
        char instruccion = instrucciones.front();
        instrucciones.pop_front();
        
        int r = 0, g = 0, b = 0;
        int x = 0, y = 0;
        
        switch(instruccion)
        {
            case HELP:
                print_help();
                break;
            
            case RESET_VISUALS:
                reset_visuals();
                break;
            
            case SET_COLOR:
            case SET_BG:
                r = valores.front();
                valores.pop_front();
                g = valores.front();
                valores.pop_front();
                b = valores.front();
                valores.pop_front();
                if(instruccion == SET_COLOR) set_color(r, g, b);
                else set_background(r, g, b);
                break;

            case MOVE_CURSOR:
                x = valores.front();
                valores.pop_front();
                y = valores.front();
                valores.pop_front();
                move_cursor(x, y);
                break;

            case CLEAR_SCREEN:
                clear_screen();
                break;
            case HIDE_CURSOR:
                hide_cursor();
                break;
            case SHOW_CURSOR:
                show_cursor();

        }       
    }

    return 0;
}