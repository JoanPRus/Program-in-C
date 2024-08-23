#include <stdio.h>
#include <string.h>

/*Atès l’encariment de la llum, es demana fer un programa que
es demani una hora i el día de la setmana i ens informi a quina de les tres
zones pertany l’hora. Les tres zones són Punta, Llano o Valle. L’hora que
introduirà l’usuari és una hora sencera (sense minuts ni segons)
*/

int main() {

//Declarar variables 

int hora;
char dia[20];

//Demanar hora y dia al usuari.

    printf("Introdueix una hora: ");
    scanf("%d",&hora);
    printf("Introdueix un dia: ");
    scanf("%19s", dia);


//Declarar les zones dia
//Utilitzem un if i dentre un switch

if (strcasecmp(dia, "Dilluns") == 0 || 
strcasecmp(dia, "Dimarts") == 0 ||
 strcasecmp(dia, "Dimecres") == 0 ||
  strcasecmp(dia, "Dijous") == 0 || 
  strcasecmp(dia, "Divendres") == 0 ) {


    //Declarar les zones hora

    switch (hora) {
        case 0: case 1: case 2:
        case 3: case 4: case 5:
        case 6: case 7:
            printf("A las %d es Valle", hora);
            break;

        case 8: case 9: case 14:
        case 15: case 16: case 17:
        case 22: case 23:
            printf("A las %d es Llano", hora);
            break;

        case 10: case 11: case 12:
        case 13: case 18: case 19:
        case 20: case 21:
            printf("A las %d es Punta", hora);
            break;

        default:
            printf("Dades incorrectes: ");
            break;
    }
}
else if (strcasecmp (dia, "Dissabte") == 0 || strcasecmp (dia, "Diumenge") == 0) {
    if (hora >= 0 && hora <= 23) {
        printf("A las %d es Valle", hora);
    }  else {
            printf("Dades incorrectes: Hora fora de rang\n");
        }
      
}   
else {
        printf("Dades incorrectes: Dia no valid\n");
    }
   
    return 0;
}