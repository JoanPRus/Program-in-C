#include <stdio.h> 
#include <string.h>

int main()
{
    /*Demanar a l'usuari un dia de la setmana i si està plovent.
    Indicar el lloc del entrenament fora o dins del pavelló, els dies de entrenament dl,dc,dv
    Informar del dels dies que no hi ha entrenament*/
    
    char dia[20],temps[20]; //nos permite poner un limite de caracteres para no colapsar
    
    printf("Quin dia es: ");
    scanf("%19s", dia); //marcanos los caracteres
    printf("Estem a %s\n", dia);
    printf("Esta plovent: ");
    scanf("%19s", temps); //marcanos los caracteres

     /*nos dice los dias que entrenamos y los que no.
     strcasecmp no diferencia mayusculas ni minusculas. Cuando (strcasecmp(dia, "dilluns") == 0  
     estamos comparando que las cadenas sean iguales*/

   if (strcasecmp(dia, "dilluns") == 0 || strcasecmp(dia, "dimecres") == 0 || strcasecmp(dia, "divendres") == 0) {
        printf("hi ha entrenament\n");
    } else if (strcasecmp(dia, "dimarts") == 0 || strcasecmp(dia, "dijous") == 0 ||
              strcasecmp(dia, "dissabte") == 0 || strcasecmp(dia, "diumenge") == 0) {
        printf("no hi ha entrenament\n"); 
        getch();
        return 0;
    } else {
        printf("Resposta no valida\n");
    }

    if (strcasecmp(temps, "si") == 0) {
        printf("entrenarem en el pavello\n");
    } else if (strcasecmp(temps, "no") == 0) {
        printf("entrenarem fora\n");
    } else {
        printf("Resposta no valida\n");
    }
    getch();
    return 0;
}

