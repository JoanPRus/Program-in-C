#include <stdio.h>
#include <string.h>

int main()
{
    /*Demanar el resultat del partit de futbol i el nom dels dos equips
    el programa informara del guanyador o si han empatat*/

    int resultat1, resultat2; 
    char equip1[20], equip2[20], resultat[50];

    printf("nom del equip1: ");
    scanf("%19s", equip1);
    printf("El equip1 es el %s\n", equip1);

    printf("nom del equip2: ");
    scanf("%19s", equip2);
    printf("El equip2 es el %s\n", equip2);
    
    printf("Quin ha estat el resultat format (x-y): ");
    scanf("%49s", resultat); 
    printf("El resultat es %s\n", resultat); 

    //sscanf almacena los datos de la cadena y los convierte en variables
    sscanf(resultat, "%d-%d", &resultat1, &resultat2);   
                                                        
    if (resultat1 > resultat2) { 
        printf("El guanyador es %s\n", equip1);
    } else if (resultat1 < resultat2) { 
        printf("El guanyador es %s\n", equip2);
    } else printf("Hi ha un empat");

    return 0;
}