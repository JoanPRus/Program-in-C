#include <stdio.h>
#include <string.h>

    /*Un restaurant cobra els menús dels dies laborables a 10 € i dels
    festius a 14 €. Fer un algoritme que demani a l’usuari un número de l’1 al 7
    que indica el dia de la setmana, i la quantitat d’euros que ha pagat el client.
    Llavors l’algoritme ha de donar error si el client ha pagat menys del que
    correspon segons el dia, o bé el canvi que se li ha de tornar, si ha pagat més.
    */


int main() {

    //Declarem les variables y constants 

    int dia, paga, resultat; 
    const int laboral = 10;
    const int festiu = 14; 

    //Demanar dia de la setmana 1-7, i el import que ha pagat.

    printf("Introdueix un dia del 1-7 y la quantitat pagada: ");
    scanf("%d %d", &dia, &paga);


    /*Declarar si es laboral o festiu. Despres donar
    opcions: canvi, bon dia o falten x euros per pagar*/

    if (dia <= 5) {

    resultat = paga - laboral;   
       if (resultat == 0) {
            printf("Es laboral. Bon dia");
        } else if (resultat > 0) {
            printf("Es laboral. El canvi es %d euros", resultat);
        } else if (resultat < 0) {
            printf("Es laboral. Faltan per pagar %d euros", -resultat);
        }
    }else if (dia>=6) {
        
        resultat = paga - festiu;   
       if (resultat == 0) {
            printf("Es festiu. Bon dia");
        } else if (resultat > 0) {
            printf("Es festiu. El canvi es %d euros", resultat);
        } else if (resultat < 0) {
            printf("Es festiu. Faltan per pagar %d euros", -resultat);
        }
    }

    return 0;
}