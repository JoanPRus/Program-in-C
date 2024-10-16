#include <stdio.h>
#include <rlutil.h>


/*. (ComptaEndarrera) Fes un compte endarrere des del 10 fins al 0. Entre
número i número esperarem 100 ms (cal utilitzar la funció Sleep(100) de la
llibreria rlutil.h). Cadascun dels números es mostraran en la mateixa posició
inicial (caldrà que utilitzis la funció cls() que neteja la pantalla). Cal fer
l’exercici amb els tres bucles (for / while / do ... while))*/


int main(){

    int num = 10;
    for (int i = 10;  i >= 0; i--){
        printf("%d", i);
        Sleep(100);
        cls();
    }

    

    num = 10;
    while (num >= 0){
    printf("\n");
    printf("%d", num);
    Sleep(100);
    cls();
    num--;
    }


   num = 10;
   do {
    printf("\n");
    printf("\n");
    printf("%d", num);
    Sleep(100);
    cls();
    num--;
   } while (num >= 0);


    getch();
    return 0;
}