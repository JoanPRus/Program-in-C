#include <stdio.h>
#include <string.h>

/*(PromocioEmpresa) Una empresa vol promoure a una nova secció als
empleats que compleixin una de les següents condicions:
• Pertànyer al torn de matí
• Ser de la Secció 1 i que el seu sou sigui inferior a 700
El torn pot ser matí, tarda o nit (‘M’ o ‘T’ o ‘N’); la secció entre 1 o 3 i el sou
positiu.*/


int main() {

    // Declarar variables

    int seccio, sou; 
    char torn; 

    //Preguntar

    printf("Introdueix el torn: "); 
    scanf(" %c", &torn); 
    printf("\nIntrodueix la seccio: "); 
    scanf("%d", &seccio); 
    printf("\nIntrodueix el sou: ");
    scanf("%d", &sou); 


    //condiciones y resultados

    if (torn == 'M' || (seccio == 1 && sou < 700)) {
        printf("El treballador es promou a la nova seccio");
    } else {
        printf("El treballador no es promou a la nova seccio");
    }
    
    getch();
    return 0;
}