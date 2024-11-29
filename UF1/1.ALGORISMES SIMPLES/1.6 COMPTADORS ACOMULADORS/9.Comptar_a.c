#include <stdio.h>

/*(Comptar ‘a’ s) Fer un algoritme que donat una sèrie de caràcters
introduïts per l’usuari, calculi el nombre de lletres ‘a’ introduïdes. L’usuari
finalitzarà d’introduir dades quan insereixi una ‘z’ o ‘Z’
Introdueix el caracter: a
Introdueix el caracter: G
Introdueix el caracter: 9
Introdueix el caracter: o
Introdueix el caracter: A
Introdueix el caracter: A
Introdueix el caracter: z
S'han introduit 3 caracteres a
Prem una tecla per finalitzar*/

int main(){

    //primero un for  para pedir los caracteres, if para salir

    char caracter[50];
    int contador = 0;

   
    for (int i = 0; i < 50; i++){ // for para recorrer el array

        printf("\nIntrodueix un caracter: "); //pedimos  caracter
        scanf(" %c", &caracter[i]); //dejamos espacio para  no coger otro caracter
        
        if (caracter[i] == 'Z' || caracter[i] == 'z' || caracter[i] == caracter[50]){ //ponemos limite array
            printf("No mes caracters");
            break;
            
        }
        if (caracter[i] == 'A' || caracter[i] == 'a'){
            contador++;
        }

    } 
    {
    printf("\nHi ha %d caracteres 'A o a'",  contador);
    printf("\nPrem una tecla  per finalitzar");
    }



    getch();
    return 0;
}
