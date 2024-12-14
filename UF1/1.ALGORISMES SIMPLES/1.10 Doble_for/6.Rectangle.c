#include <stdio.h>




/*(Rectangle) Fer un algoritme que demani a l'usuari dos naturals entre 2 i 20.
L'algoritme ha de dibuixar per pantalla un quadrat que tingui d'ample el primer
dels dos naturals introduïts i d'alt el segon*/

int main(){

    
    int altura,  ancho;

    printf("Introdueix la altura entre 2-20: ");
    scanf("%d", &altura);
    printf("Introdueix la amplada entre 2-20: ");
    scanf("%d", &ancho);

    

    for (int i = 1; i <= altura; i++){
        
        for  (int  j = 1; j <= ancho; j++){

            printf("X");
        }

        printf("\n");

    }

    getch();
    return 0;
}