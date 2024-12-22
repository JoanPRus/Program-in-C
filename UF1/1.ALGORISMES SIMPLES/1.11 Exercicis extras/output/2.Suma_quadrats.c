#include <stdio.h>



/*. (SumaQuadrats): Escriu un programa que mostri el resultat de sumar tots
els quadrats dels números del 1 al 100. Cal utilitzar el bucle per.
La suma dels quadrats dels números de l’1 al 100 es de 338350*/


int main(){

    //tengo que sumar todos los cuadrados del 1 al 100.

    //El cuadrado de  x es x * x 

    int resultado = 0;

    for(int i = 1; i <= 100; i++){

        resultado += i * i;
    }

    printf("El resultado es %d", resultado);


    getch();
    return 0;
}