#include <stdio.h>



/* (Parells) Fer un algoritme que mostri tots els nombres parells del 0 al
número natural que indiqui l’usuari. Si el número és negatiu que torni a
demanar-lo.
Introdueix el darrer numero: 9
Resultat: 0 2 4 6 8*/

int main() {

    int numnatural;
    
    do {
    printf("Introdueix un nombre natural: "); 
    scanf("%d", &numnatural);
    } while (numnatural < 0); 

    for (int i = 0; i <= numnatural; i++) {
       if (i % 2 == 0) {
        printf("%d ", i);
       }
    }



    getch();
    return 0;
}