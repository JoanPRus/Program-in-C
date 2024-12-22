#include <stdio.h>
#include <rlutil.h>
#include <time.h>


/*(MasterMindAI): Inverteix el programa del MasterMind per tal de fer que ara
sigui el PC qui hagi d’encertar el número que prèviament ha introduit l’usuari.
El número a esbrinar ha de tenir 4 dígits.
Per indicar que el número generat per la máquina és més petit l’usuari
introduïrà un ‘-‘, mentre per dir que és més gran un ‘+’.
Al finalizar cal indicar amb quants intents ha esbrinat l’ordinar el número de
l’usuari.
*/

int main(){

    /*Introducir un numero de 4  digitos,  y  que la maquina lo adivine,  indicar si es mas grande + o mas  pequeño -*/

    int numero = 0, numIA = 0, vueltas  = 1, num_menos = 9999,  num_mas = 1000;
    char c; 

     
    
    //pedimos  el  numero  y  controlamos que tenga  4 digitos.  
    do {
    printf("introdueix  un  numero de 4  digits: ");
    scanf("%d", &numero);
    }while(numero < 1000 || numero > 9999);

    //ahora tengo  que hacer que  el ordenador genere  numeros con ciertas  condiciones. 4 digitos y que controle si es mas grande o pequeño el numero. 

    srand(time(NULL)); 

    while(numero != numIA){
          
        c = ' ';//elimina el caracter anterior
        numIA = rand() % (num_menos - num_mas + 1) + num_mas; //genera  el numero  teniendo en cuenta los limites  y luego  se suma num_mas 

        printf("\n[%d-%d]---> numero generat en el intent [%d] = %d %c", num_mas, num_menos, vueltas, numIA, c);
        scanf(" %c", &c);
        vueltas++;

        if(c == '+'){

            num_mas = numIA + 1;  //limite del rango  por abajo se  suma 1 
                  

        }else if(c == '-'){

            num_menos = numIA - 1; //limite  del  rango   por arriba se resta 1.

        }else if(c == '='){
            break;
        }

    }

    printf("Numero trobat  amb %d intents!!!", vueltas - 1);

    getch();
    return 0;
}