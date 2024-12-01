#include <stdio.h>
#include <stdlib.h>


/*. (Comptar “la”s) Fer un algoritme que donat una sèrie de caràcters introduïts
per l’usuari, calculi en nombre de “la” introduïdes. Finalitzarem d’introduir
caracters quan l’usuari posi un ‘.’
Introdueix un caracter: a
Introdueix un caracter: s
Introdueix un caracter: l
Introdueix un caracter: a
Introdueix un caracter: l
Introdueix un caracter: 0
Introdueix un caracter: L
Introdueix un caracter: a
Introdueix un caracter: .
Han aparegut 2 la
Prem una tecla per finalitzar
*/

int main(){

    char car[100]; //array estatico ponemos mas espacio
    int contador = 0;

    for (int i = 0; i < 100; i++){ //iniciamos el bucle

        printf("\nIntrodueix un caracter: "); //pedimos Caracter
        scanf("\n%c", &car[i]); //guardamos el dato

        if (car[i] ==  '.'){   //paramos el bucle si se cumple la condicion
            break;
        }


        //comprueba si en  la  vuelta anterior hay  una  L y en  la actual una  A
       if ((car[i - 1] == 'L' ||  car[i - 1] == 'l') && (car[i] == 'A' ||  car[i] == 'a')){

            contador++; 
       }

    }{

        printf("Han aparegut %d LA", contador);
    }

    getch();
    return 0;
}