#include <stdio.h>
#include <string.h>

/*(Màxim) Fer un algoritme que calculi el màxim de dos números enters entrats
per l’usuari. En cas que siguin el mateix nombre, mostrarà qualsevol dels dos 
nombres. Seria bo, desar en una variable el màxim dels dos valors i fer
únicament un únic printf*/

int main() {

    int enter,enter2,maxim;

    printf("Introdueix dos enters: ");
    scanf("%d %d", &enter, &enter2);
    printf("\nNumero1= %d Numero2= %d", enter, enter2);

    //Podriamos usar condicion if para hacerlo. Otra forma es el operador tenario.

    /*el valor se asigna dependiendo si es verdadero o falso
    Si "enter" es mayor que "enter2" "maxim" tomara el valor de "enter"
    Si "enter" es menor que "enter2" "maxim" tomara el valor de "enter2"*/

    maxim = (enter > enter2) ? enter : enter2; //operador  tenario

    printf("\nEl valor maxim es %d", maxim);

    getch();
    return 0;
}