#include <stdio.h>
#include <stdlib.h> //para usar abs()

/*(Abs) Fer un algoritme que mostri el valor absolut d’un número enter entrat
per l’usuari. El valor absolut d’un número és el mateix número amb signe
positiu. En finalizar el programa, el número ha de ser positiu.
*/

int main() {

int num;
    printf("Introdueix un nombre enter: ");
    scanf("%d", &num);

    //abs(num) convierte el numero en absoluto.
    int numabsolut = abs(num); 

    printf("\nEl valor absolut es: %d", numabsolut);

    getch();
    return 0;
}