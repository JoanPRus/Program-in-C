#include <stdlib.h>
#include <stdio.h> // rango  aleatorio
#include <time.h> //semilla aleatoria


/*(Mastermind) Fer un algoritme que generi un nombre aleatori de 4 xifres.
L'usuari llavors ha d'introduir nombres de 4 xifres fins que l'encerti o be hagi
fet n intents. El nombre d'intents també els ha d'introduir l'usuari. A cada
nombre de 4 xifres que introdueixi l'usuari, el programa li ha de dir si el
nombre que ha d'endevinar és més gran o més petit. Si l'usuari l'encerta en un
nombre de vegades menor que n, llavors ha guanyat. Si no, ha perdut.*/


int main(){

    /*Generar un numero aleatorio de 4 cifras. Pedir cuantos intentos quiere, decir si es mas grande o pequeño el numero
    si encierta el numero a ganado, si se terminan  los intentos sin acertar a perdido*/

    srand(time(NULL));  

    int num_aleatori = rand() % 9000 + 1000;  // el rango va de 0 a 8999 despues sumamos 1000 asi siempre tiene 4 cifras 8999+1000= 9999

    int intents = 0;
    int num_usuari;

    printf("Quants intents vols fer: ");
    scanf("%d", &intents);
    printf("\nNumero per adivinar %d", num_aleatori);

    for (int i = 0; i < intents; i++){
        
        printf("\nIntrodueix un numero de 4 xifres: ");
        scanf("%d", &num_usuari);

        if (num_aleatori == num_usuari){
            printf("\nHas guanyat");
            printf("\nPrem una tecla per finalitzar");
            getch();
            return 0;
        }

    }{
        printf("\nHas perdut");
        printf("\nPrem una tecla per finalitzar");
    }

    getch();
    return 0;
}