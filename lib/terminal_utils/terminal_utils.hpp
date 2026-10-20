/**
 * Esta libreria busca facilitar el control sobre el terminal para
 * realizar aplicaciones CLI visualmente interesantes
 * 
 * Esta libreria se ha implementado utilizando codigos de escape ANSI, la referencia usada
 * se puede consultar en el siguiente enlace: https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
 * 
 * @author Diego Muñoz Jorquera
 * @date 19/10/2026
 * @version 1.0
 */


/**
 * Este procedimineto devuelve el terminal a su estado por defecto: tipo de letra,
 * color de texto, color de fondo y visibilidad del cursor
 */
void reset_visuals();

/**
 * Este procedimiento recibe tonalidades RGB y configura el terminal
 * para utilizar como color de <strong>letra</strong> el definido
 *  
 * @param r intensidad roja
 * @param g intensidad verde
 * @param b intensidad azul
 */
void set_color(unsigned char r, unsigned char g, unsigned char b);

/**
 * Este procedimiento recibe tonalidades RGB y configura el terminal
 * para utilizar como color de <strong>fondo</strong> el definido
 *  
 * @param r intensidad roja
 * @param g intensidad verde
 * @param b intensidad azul
 */
void set_background(unsigned char r, unsigned char g, unsigned char b);

/**
 * Este procedimiento recibe una posicion de columna y fila y mueve el cursor
 * a esa posicion.
 *
 * La x va de izquierda a derecha (1 -> ANCHO)
 * La y va de arriba a bajo (1 -> ALTO)
 * 
 * @param x columna objetivo (horizontal)
 * @param y fila objetivo (vertical)
 */
void move_cursor(int x, int y);

/**
 * Este procedimiento limpia la pantalla
 */
void clear_screen();

/**
 * Este procedimiento <strong>esconde</strong> el cursor, el cuadradito blanco que muestra
 * la posicion del cursor
 */
void hide_cursor();

/**
 * Este procedimiento <strong>muestra</strong> el cursor, el cuadradito blanco que muestra
 * la posicion del cursor
 */
void show_cursor();