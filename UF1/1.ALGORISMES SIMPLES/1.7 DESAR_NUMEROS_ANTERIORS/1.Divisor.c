#include <stdio.h>

/*(Divisor) Fer un programa que demani números naturals a l’usuari, fins que
introdueixi un 0, i ens indiqui per a cadascun dels números introduïts, si el
número que hem introduït prèviament és divisor del número que acabem
d’introduir
Introdueix un numero: 3
Introdueix un numero: 0
Nomes s'ha introduit un numero valid
Prem una tecla per finalitzar
Introdueix un numero: 0
No s'ha introduit cap numero valid
Prem una tecla per finalitzar
Introdueix un numero: 12
Introdueix un numero: 2
Si, ja que 12 es divisible entre 2
Introdueix un numero: 5
No, ja que 2 no es divisible entre 5
Introdueix un numero: 2
No, ja que 5 no es divisible entre 2
Introdueix un numero: 8
No, ja que 2 no es divisible entre 8
Introdueix un numero: 2
Si, ja que 8 es divisible entre 2
Introdueix un numero: 0
Prem una tecla per finalitzar*/

int main(){

    /*Pedir numeros naturales al usuario, si pone 0 dejar de pedirle. Tenemos que ver si 
    el numero introducido anterior con el actual es divisible y ponemos un mensaje.
    Diferentes casos posibles: Solo introduce un numero  (terminar  programa),
    no introduce  ningun numero (terminar programa),
    introduce los dos numeros y son divisibles o  no. */

    /*Tenemos que crear for, diferentes condiciones y tambien formula para que divida y 
    el resto sea 0, el numero anterior con el actual y que despues repita el bucle.*/

    int numero1, numero2; 
    int numero_sortida = 0;
    int operacions;  

    do {
        printf("\n");
        printf("\nIntrodueix un numero: ");
        scanf("%d", &numero1);
        if (numero1 == 0){
            printf("\nPrem una tecla per finalitzar");
            break;
        }else if (numero1 != 0){
            printf("\nIntrodueix un numero: ");
            scanf("%d", &numero2);
            if (numero2 == 0){
                printf("\nNomes s'ha introduit un numero valid");
                printf("\nPrem una tecla per finalitzar");
                break;
                }
            }
            
          if (numero1 % numero2 == 0){
            printf("\nSi, ja que %d  es divisible entre %d", numero1,  numero2);
        }  else  printf("\nNo, ja que %d no es divisible entre %d", numero1, numero2);
        

        } while (numero1 != 0  || numero2 != 0);


    getch();
    return 0;
}