#include <stdio.h>
#include <stdlib.h>

/*(Totes_les_vocals) Fer un algoritme que demani a l'usuari una sèrie de
lletres acabades en ‘.’. Llavors l’algoritme ha de mostrar si en aquesta sèrie de
lletres hi ha totes les vocals, almenys un cop. Fixeu-vos que si troba les 5
vocals, no ha de continuar demanant més lletres.
*/

int main(){

    //Tenemos que pedir letras y cuando se hayan introducido todas las vocales terminar el programa, para salir usar '.'

    /*Vamos a  pedir letras con un bucle, cada vez que se introduzca una vocal se guardara en memoria_vocal_A, etc, cuando cada memoria
    sea mayor o igual a  1  el bucle para*/

    char car[50];
    int memoria_vocal_a = 0, memoria_vocal_e = 0, memoria_vocal_i = 0, memoria_vocal_o = 0, memoria_vocal_u = 0;
    int i = 0;
    do{
        printf("\nIntrodueix una lletra en minuscula: ");
        scanf("\n%c", &car[i]);
        
        i++;

    }while (car[i - 1] != '.'); //no va


    getch();
    return 0;
}