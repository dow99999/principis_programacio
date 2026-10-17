int main()
{

  const int valor = 10; // también sirve para definir constantes (y es mejor practica que el #define)
  int
      x = 0x0F, // Numero hexadecimal
      y = 056,  // Numero octal
      y = 0b01, // Numero binario
      z = 10;   // Numero decimal
  char letra = 'a'; // un unico caracter
}

/**
 * Recordatorio de cambios de base:
 * 
 * Si queremos trabajar con cualquier base y la base decimal:
 * Para pasar de decimal a cualquier base: dividimos por la base
 * Para pasar de cualquier base a decimal: sumamos potencias de la base. e.g: 1010 = 2^3 + 2^2 + 2^1 + 2^0
 * 
 * Si trabajamos con binario:
 * 
 * Para octal:
 * separamos cada digito octal en agrupaciones de 3 digitos binarios: 12 = 001 010
 * 
 * Para hexadecimal:
 * separamos cada digito hexadecimal en agrupaciones de 4 digitos binarios: 12 = 0001 0010
 * 
 * 0 0 0 0
 * 0 0 0 1
 * 0 0 1 0
 * 0 0 1 1
 * 0 1 0 0
 * 0 1 0 1
 * 0 1 1 0
 * 0 1 1 1
 * 1 0 0 0
 * 1 0 0 1
 * 1 0 1 0
 * 1 0 1 1
 * 1 1 0 0
 * 1 1 0 1
 * 1 1 1 0
 * 1 1 1 1
 * 
 */