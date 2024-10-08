#include <string.h>
#include <stdio.h>



/* Un cinema ha demanat si podem fer un programa que calculi
l’import que ha de pagar un client. Aquest cinema compta amb unes ofertes
segons l’edat dels usuaris, juntament amb una diferència de preu segons si
són dies laborables o cap de setmana. Suposem que només entra al cinema
una única persona.
Ofertes disponibles
• Oferta Infantil (de 0 a 15 anys) -->70%
• Oferta Junior (de 16 a 59 anys) --> 30%
• Oferta Senior (més de 60 anys) --> 15%
Preus cap de setmana: 12 €
Preus dies laborables: 8€*/


// Otra vez mejor hacer las condiciones y luego switch
int main() {

    //determinar variables
    
    int festiu = 12;
    int laboral =  8; 
    int edat; 
    char dia[15]; 
    float preuentrada;  

    //saber si es  laboral o festivo, edad
    printf("Que dia es? ");
    scanf("%14s", dia);
    printf("Quants anys tens? ");
    scanf("%d", &edat); 

    //condiciones 



    if (strcasecmp(dia,"Dissabte") == 0 || strcasecmp(dia,"Diumenge") == 0) {
        
        switch (edat)
        {
        case 0 ... 15:  //rango

            preuentrada = festiu * 0.3;
            printf("El preu es %.2f euros", preuentrada); 
            
            break;
         case 16 ... 59:  //rango

            preuentrada = festiu * 0.7;
            printf("El preu es %.2f euros", preuentrada); 
            
            break;
         case 60 ... 100:  //rango

            preuentrada = festiu * 0.85;
            printf("El preu es %.2f euros", preuentrada); 
            
            break;
        
        default: printf("Error");
            break;
        }

    
    } else if (strcasecmp(dia,"Dilluns") == 0 || strcasecmp(dia,"Dimarts") == 0 || strcasecmp(dia,"Dimecres") == 0 || strcasecmp(dia,"Dijous") == 0 || strcasecmp(dia,"Divendres") == 0) {
        switch (edat)
        {
        case 0 ... 15:  //rango

            preuentrada = laboral * 0.3;
            printf("El preu es %.2f euros", preuentrada); 
            
            break;
         case 16 ... 59:  //rango

            preuentrada = laboral * 0.7;
            printf("El preu es %.2f euros", preuentrada); 
            
            break;
         case 60 ... 100:  //rango

            preuentrada = laboral * 0.85;
            printf("El preu es %.2f euros", preuentrada); 
            
            break;
        
        default: printf("Error");
            break;
        }

        
    } else { 
        printf("Resposta incorrecte"); 
    }
      




     getch();
     return 0;
} 


