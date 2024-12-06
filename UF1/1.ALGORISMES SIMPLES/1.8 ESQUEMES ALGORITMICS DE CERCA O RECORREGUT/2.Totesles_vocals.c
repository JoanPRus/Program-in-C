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
        printf("\nIntrodueix una lletra en minuscula: "); //pedir  letra
        scanf("\n%c", &car[i]); //guarda las letras  

        if (car[i] == 'a'){ // mira si es  igual y se guarda  si es asi
            memoria_vocal_a++;
        }
        
        if (car[i] == 'e'){
            memoria_vocal_e++;
        }
        
        if (car[i] == 'i'){
            memoria_vocal_i++;
        }
        
        if (car[i] == 'o'){
            memoria_vocal_o++;
        }
        
        if (car[i] == 'u'){
            memoria_vocal_u++;
        }
        
        if (memoria_vocal_a >= 1 && memoria_vocal_e >= 1 &&  memoria_vocal_i >= 1 && memoria_vocal_o >= 1 && memoria_vocal_u >= 1){   
            printf("\nHi ha totes les vocals");  //si todas las memorias valen  1 o mas tenemos las 5 vocales
            printf("\nPrem una tecla per finalitzar");
            break;

        }
        
        i++; //completa  el array

    }while (car[i - 1] != '.'); // el  bucle sigue si no  es punto
        
        if (car[i - 1] == '.'){
        printf("\nNo hi ha  5 vocals");
        printf("\nPrem una tecla per finalitzar");
        }

    


    getch();
    return 0;
}