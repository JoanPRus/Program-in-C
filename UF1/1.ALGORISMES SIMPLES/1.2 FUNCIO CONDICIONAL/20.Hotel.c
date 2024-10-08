#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


/*Crea un algoritme que calculi el preu a pagar en un hotel; cal tenir en
compte que durant els dies laborals el preu de l’habitació és de 80 € mentre
que el cap de setmana és de 100. Se li aplicarà un descompte del 5% en cas
que sigui soci Premium (aquesta variable serà tipus bool). El client només
estarà en l’hotel 1 dia*/

int main() {

    //Declaramos variables 

    float preuhabitacio;
    int preulaboral = 80;
    int preufestiu = 100;
    bool socipremium;
    char dia[15];
    char sisoci[5]; 

    //Preguntamos el dia y si es socio 

    printf("Quin dia es? ");
    scanf("%14s", dia);
    printf("Ets soci premium? ");
    scanf("%4s", sisoci);

    //Condiciones si es laboral o festivo 

    if (strcasecmp(dia,"Dissabte") == 0 || strcasecmp(dia,"Diumenge") == 0) {

          //condiciones si es socio o no (bool)

        if  (strcasecmp (sisoci, "Si") == 0) {
            socipremium = true;
            preuhabitacio = preufestiu * 0.95;
          printf("El preu es %.2f euros", preuhabitacio);  
        } else if (strcasecmp (sisoci, "No") == 0) {
            socipremium = false;
            preuhabitacio = preufestiu; 
            printf("El preu es %.2f euros", preuhabitacio);  
        } else { printf("Resposta no valida"); 
            return 1;
        }



    } else if (strcasecmp(dia,"Dilluns") == 0 || strcasecmp(dia,"Dimarts") == 0 || strcasecmp(dia,"Dimecres") == 0 || strcasecmp(dia,"Dijous") == 0 || strcasecmp(dia,"Divendres") == 0) {
        
        //condiciones si es socio o no bool

        if  (strcasecmp (sisoci, "Si") == 0) {
            socipremium = true;
         preuhabitacio = preulaboral * 0.95;
          printf("El preu es %.2f euros", preuhabitacio);     
        } else if (strcasecmp (sisoci, "No") == 0) {
            socipremium = false;
         preuhabitacio = preulaboral; 
          printf("El preu es %.2f euros", preuhabitacio);  
        } else  { printf("Resposta no valida");
            return 1;
        } 

    } else { printf("Dades incorrectes"); 
        return 1;
    }

    getch();
    return 0;
}