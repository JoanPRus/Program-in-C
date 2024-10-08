#include <string.h>
#include <stdio.h>


int main()  {

    /*Escriu un programa que demani a l’usuari que introdueixi un
    número d’any i ens indiqui si aquest és de traspàs o no. Podem saber que un
    any és de traspàs quan: L’any és divisible entre 4, excepte si és final de segle 
    (acaba en 00) on cal que també les dues primeres xifres de l’any siguin també divisibles entre 4.
    Per obtenir les dues primeres xifres cal fer la divisió sencera amb 100 */

    int any;
    int DosPrimerosNumeros = 0;
    
    printf("Introdueix un numero d any: ");
    scanf("%d", &any); 

    /*Condicions: dividir l'any en 4 y si termina en 00 l'any també dividir 4 les dues primeres
    xifres*/

    /*Primero divido el año en 4 si no es divisible el año no es de traspaso*/

    if (any % 4 == 0) { 
      /*Si el numero es divisible en 4 necesito verificar si tiene dos 00 al final*/

         if (any % 100 == 0) {
                DosPrimerosNumeros = any / 100;
                if (DosPrimerosNumeros % 4 == 0)  {
                printf("El %d es de traspas", any);
                } else {
                printf("El %d no es de traspas", any);
                }
        } else {
            printf("El %d es de traspas", any);
        }          
    

    } else printf("El %d no es de traspas", any);
    
    
    getch();
    return 0;
}
