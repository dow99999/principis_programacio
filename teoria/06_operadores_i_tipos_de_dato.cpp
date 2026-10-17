int main()
{

}

/**
 * Operadores a nivel de bit
 * 
 * &: and a nivel de bit.
 * |: or a nivel de bit.
 * ^: xor (or exclusiva) a nivel de bit.
 * 
 *      & | ^
 * 0 0  0 0 0
 * 0 1  0 1 1
 * 1 0  0 1 1
 * 1 1  1 1 0
 * 
 * Complementario ~
 * 
 * ~0 = 1
 * ~1 = 0
 */

/**
 * Tipos de datos:
 * 
 * int tiene 16 bits de tamaño (su rango es de -32768 a 32767)
 * 
 * Existen los calificadores de tipo, estos se añaden DELANTE de un tipo de dato:
 * signed y unsigned. Signed se aplica por defecto a todos los tipos de datos, unsigned debe especificarse.
 * 
 * unsigned int tiene 16 bits de tamaño (su rango es de 0 a 65535). Cabe un número positivo superior
 * ya que dejamos de utilizar el primer bit para definir el signo del número.
 * 
 * También existen los calificadores short y long. El short divide por 2 su espacio, el long multiplica por 2 su espacio.
 * short int tiene 8 bits de tamaño (de -128 a 127)
 * unsigned short int tiene 8 bits de tamaño (de 0 a 255)
 * long int tiene 32 bits de tamaño ()
 * 
 * IMPORTANTE: Un entero equivale al ancho de la arquitectura del procesador (32 bits, 64 bits...)
 */

 /**
  * Para mostrar diferentes datos por pantalla:
  * 
  * %c: un unico caracter
  * %d: un numero entero con signo
  * %u: un numero entero sin signo
  * %o: un numero entero en base octal
  * %x: un numero entero en base hexadecimal
  * %e: un numero real en coma flotante, con exponente
  * %f: un numero real en coma flotante, sin exponente
  * %s: una cadena de caracteres
  * %p: un puntero o direccion de memoria
  * 
  * Algunos caracteres de escape:
  * \n: salto de linea
  * \b: retroceso
  * \n z
  */