#include <stdio.h>

/* (Senars): Escriu un programa que mostri la seqüència de tots els números
senars que van del 0 al número que hagi introduït l’usuari separats per una
coma. Resoldre l’exercici amb els tres bucles que s’han vist: mentre, repetir i
per.
Introdueix un numero: 6
1, 3, 5
1, 3, 5
1, 3, 5
Prem una tecla per finalitzar
*/ 


int main(){

    //tengo que hacer los tres bucles a la misma vez. 

    int numusuari;
    int num;

    printf("Introdueix un nombre: ");
    scanf("%d", &numusuari);
    num = 1;
    do {
        printf("%d",num);
        num+= 2;
        if (num <= numusuari){
            printf(", ");
        }
    } while (num <= numusuari);
    
    printf("\n");

    num = 1;
    while (num <= numusuari){
        printf("%d", num);
        num+= 2;
        if  (num <= numusuari){
            printf(", ");
        }
    }

    printf("\n");

    num = 1;

    for (int num = 1; num <= numusuari; num+= 2){
        printf("%d", num);
        if ((num + 2) <= numusuari){
            printf(", ");
        }
    }

    getch();
    return 0;
}