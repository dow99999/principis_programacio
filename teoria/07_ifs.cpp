/**
 * El dia en el que se explicaron condicionales no estaba, asi que
 *   explico lo que sé de esta estructura y de los operadores condicionales
 */

int main()
{
    return 0;
}

/**
 * Dentro de un programa, muy probablemente nos encontremos con la necesidad
 *   de hacer algo solo si se cumple una condición, o hacer otra cosa en caso de
 *   que no se cumpla.
 * 
 * Una condición es cierta si su valor diferente a 0 o true y falsa si su valor
 *   es igual a 0 o false.
 * 
 * Para eso existe una estructura condicional llamada if - else if - else
 * 
 * Su estructura más simple es la siguiente:
 *   
 *   if(condicion)
 *   {
 *    // Codigo a ejecutar si se cumple la condicion
 *   }
 * 
 * 
 * En casos en los que el programa lo requira, se puede hacer mas compleja la 
 *   gestión de la condición:
 *   
 *   if(condicion)
 *   {
 *     // Codigo a ejecutar si se cumple la condicion
 *   } else
 *   {
 *     // Codigo a ejecutar si NO se cumple la condicion
 *   }
 * 
 * 
 * Y la versión más compleja la encontramos encadenando condiciones a partir del else:
 * 
 *   if(condicion1)
 *   {
 *     // Codigo a ejecutar si se cumple la condicion1
 *   } else if(condicion2)
 *   {
 *     // Codigo a ejecutar si se cumple la condicion2
 *   } else 
 *   {
 *     // Codigo a ejecutar si NINGUNA de las condiciones anteriores
 *   }
 * 
 * 
 * También se puede simplificar la estructura de un if siempre y cuando este tenga
 *   una única expresión en su cuerpo. Esta estructura es muy útil en el uso de guardianes
 *   (cuando veamos bucles entraré más en ello)
 * 
 * if(condicion) expresion;
 * 
 * 
 */


/**
 * Operadores logicos y resultados de sus operaciones
 * 
 * Conocemos los siguientes operadores logicos, el resultado de los cuales puede colocarse
 *   directamente dentro de los parentesis de un if.
 * 
 *         menor que: <
 *         mayor que: >
 * menor o igual que: <=
 * mayor o igual que: >=
 *      diferente de: !=
 *           igual a: ==
 * 
 * Ejemplo:
 * 
 * if(3 < 5)
 * {
 *   // Codigo que se ejecutará
 * }
 * 
 * 
 * El valor de una operación lógica puede guardarse en una variable, estas variables serán
 *   de tipo bool:
 * 
 *   float cantidad_lluvia = 3.7;
 *   bool llueve = cantidad_lluvia > 0;
 * 
 * Estos valores se tratan como enteros, se pueden mostrar en un printf con %d. veremos 0 o 1.
 * 
 */