#include <stdio.h>

int main(int argc, char const *argv[])
{
    //creant un algorisme que intercanvïï el valor de les dues variables introduïdes per teclat

    
    int a,b;
    printf("Ingresa un numero entero, A = ");
    scanf("%d", &a);

    printf("Ingresa un numero entero, B = ");
    scanf("%d", &b);

    printf("Les variables intercanviades son: ");
    printf("\n");
    printf(" A = %d", b);
    printf(" B = %d", a);
    
    getch();
    return 0;
}
