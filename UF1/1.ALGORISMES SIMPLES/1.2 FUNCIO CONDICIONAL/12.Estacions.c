#include <stdio.h>
#include <string.h>


    /*Fer un algoritme que demani a l’usuari un mes i un dia, i mostri
    per pantalla l’estació de l’any corresponent. Suposem que els valors d’entrada
    estan ben introduïts
    */

int main() {
    
    //Establir les variables

    int mesdia;

    //Demanar un mes y un dia 

    printf("Introdueix un mes i un dia: format(mesdia, 104): ");
    scanf("%d", &mesdia);

    //Declarem els rangs de les estacions i mostrem l'estacio corresponent 
        //101-320 i 1221-1231 == Hivern
        //321-620 == Primavera
        //621-920 == Estiu
        //921-1220 == Tardor


    if (320 >= mesdia && mesdia >= 101) {
        printf("\nLa estacio correspont a hivern");
    } else if(1231 >= mesdia && mesdia >= 1221){
        printf("\nLa estacio correspont a hivern");
    }else if (620 >= mesdia && mesdia >= 321) {
        printf("\nLa estacio correspont a primavera");
    } else if (920 >= mesdia && mesdia >= 621) {
        printf("\nLa estacio correspont a estiu");
    } else if (1220 >= mesdia && mesdia  >= 921){
        printf("\nLa estacio correspont a tardor");
    }

    getch();
    return 0;
}