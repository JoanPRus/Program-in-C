#include <stdio.h>

/*Fer un algoritme que donat un nombre positiu, indiqui si és o no
un nombre natural senar. En cas que el nombre introduït sigui negatiu, caldrà
mostrar un missatge d’error*/

int main() {

    //Primero recibimos el numero 

    int num;

    printf("Introdueix un numero: ");
    scanf("%d", &num);

    //Determinar si el numero positivo es impar
    //Si no es positivo mostrar mensaje de error

    if (num < 0) {
        printf("Dades inicials incorrectes");
    }
    else if (num % 2 == 0) { 
        /*esta operacion nos esta diciendo que el resto 
        de la division es igual a cero */
        printf("El numero %d es parell", num);
    } else if (num % 2 != 0) { /*!= 0 no es igual 0 */
        printf("El numero %d es senar", num);
    }
    getch();
    return 0;
}