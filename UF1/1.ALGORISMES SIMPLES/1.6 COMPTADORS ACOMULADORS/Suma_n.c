#include <stdio.h>


/*(Suma n) Fer un algoritme que demani a l’usuari un nombre natural.
L’algoritme ha de mostrar la suma de tots els nombres entre el 1 i el número
introduït per l’usuari. Cal controlar que el valor introduït per l’usuari sigui
positiu
Introdueix el numero: -4
Introdueix el numero: 6
La suma des de l'1 fins 6 es 21
Prem una tecla per finalitzar*/

int main(){

    int nombre_natural;
    int cum = 0;

    do {
        printf("Introdueix el numero: ");
        scanf("%d", &nombre_natural);
    } while (nombre_natural < 0);

    for (int i = 1; i <= nombre_natural; i++){

        printf("\n i=%d", i); printf("  acum = %2d + %2d = %2d;", cum, i, cum + i);
        cum = cum + i;

    } 
    printf("\nPrem una tecla per finalitzar");



    getch();
    return 0;
}