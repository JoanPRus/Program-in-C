#include <stdio.h>

/*(Taula de multiplicar) Fer un algoritme que mostri per pantalla la taula del
número que indiqui l’usuari. El resultat que mostri el vostre programa ha
d’ésser igual al que s’adjunta a continuació.*/

int main() {

    int numtaula; 

    printf("Introdueix la taula: ");
    scanf("%d", &numtaula); 

    for (int i = 0; i <= 10; i++) {
        printf("%d X %d = %d\n", numtaula, i, numtaula * i);
    } printf("Prem una tecla  per finalitzar");

    getch();
    return 0;
}