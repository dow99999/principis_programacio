#include <stdio.h>

#define PRINCIPIO {
#define FIN }
#define ENTERO int
#define NUMERO 10
#define LIMITE NUMERO*5
#define SUMAXY x+y
#define SUMA1 (x+y)
#define MENSAJE "Demasiado grande"
#define SALTO printf("\n");

ENTERO main()
PRINCIPIO
    ENTERO x,y,z;
    x=5;
    y=LIMITE;
    
    printf("y=%d \n");
    printf(MENSAJE);
    SALTO
    
    z=SUMAXY;
    printf("z: %d",z);
    SALTO
    
    z=SUMAXY+6;
    printf("z: %d",z);
    SALTO
    
    z=SUMA1;
    printf("z: %d",z);
    SALTO
    

    return 0;
FIN