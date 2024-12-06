#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

/*(Serie_Creixent_Res_Decreixent) Fer un algoritme que donat una sèrie de
nombres naturals introduïts per l'usuari, indiqui si aquesta sèrie és creixent
(cada nombre és major o igual que l'anterior), no creixent (hi ha un nombre
que no és igual o major que l'anterior) o decreixent (tots els nombres són
iguals o més petits que l'anterior). La sèrie de nombres acaba quan l'usuari
introdueix un 0 (zero)
Introdueix un numero: 1
Introdueix un numero: 2
Introdueix un numero: 2
Introdueix un numero: 3
Introdueix un numero: 4
Introdueix un numero: 5
Introdueix un numero: 0
Creix
Prem una tecla per finalitzar

Introdueix un numero: 1
Introdueix un numero: 2
Introdueix un numero: 3
Introdueix un numero: 1
Introdueix un numero: 0
Ni creix ni decreix
Prem una tecla per finalitzar
Introdueix un numero: 1
Introdueix un numero: -1
Introdueix un numero: -2
Introdueix un numero: 0
Decreix
Prem una tecla per finalitzar

Introdueix un numero: 3
Introdueix un numero: 0
No has posat cap numero valid
Prem una tecla per finalitza

Procediment: demana els dos primers números abans d’entrar en el
bucle i determina si la seqüència amb aquests dos números està
pujant o baixant.
El cas que siguin iguals l’hauràs de tractar com a cas especial
Seguidament dins del bucle cerca quines són les condicions que fan
que tant creixent com decreixent canvïin d’estat
*/

int main(){

    /*Pedir los dos primeros numeros antes  de entrar  en el bucle y determinar si la  secuencia sube o baja.
    Si los dos primeros numeros son iguales se trata como algo especial. Dentro  del bucle poner que condiciones hacen 
    que la secuencia cambie. Para terminar se introduce 0 */

    //Crece si el numero actual es igual al  enterior o superior  1 3 4 9
    //decrece si el numero anterior es superior o igual  al actual 9 7 5 2
    //Ni crece ni decrece un numero rompe con la secuencia  ya  sea creciento o decreciente.  4 5 6 1
    //si no se han pedido los dos  numeros y ya se ha  puesto el cero no se  determina la serie. 

    //Pedimos los dos  primeros  numeros  sin  entrar en ningun bucle y tenemos que poner  la opcion  de poner 0, determinar la secuencia. 
    //Despues de tener los dos primeros numeros  entramos en  el bucle y se recorre hasta que pongan 0, condiciones para determinar la  secuencia. 

    int numero1 = 0, numero2 = 0, numero3 = 1;
    bool creciente =  true;
    int sin_tendencia = 0;
    

        //Pedir el primero numero, comprobar que  no sea cero, igual  con el segundo  numero. 
        printf("Introdueix un numero: ");
        scanf("%d", &numero1);

        if (numero1 == 0){
            printf("\nNo has posat cap numero valid");
            printf("\nPrem una tecla per finalitzar");
            getch();
            return 0;
        }

        printf("Introdueix un numero: ");
        scanf("%d", &numero2);

          if (numero2 == 0){
            printf("\nNo has posat cap numero valid");
            printf("\nPrem una tecla per finalitzar");
            getch();
            return 0;
        }

        //bucle para determinar las tendencias y dar resultados
        while (numero3 != 0){

            printf("Introdueix un numero: ");
            scanf("%d", &numero3);
            if (numero3 == 0){ //evitamos que cuente el 0 y modifique los resultados de las condiciones
                break;
            }

               if (numero1 <= numero2 && numero2 <= numero3){
                numero1 = numero2;
                numero2 = numero3;
                creciente = true;  //si  es creciente es true
                

            }else if (numero1 >= numero2 && numero2 >= numero3){
                numero1 = numero2;
                numero2 = numero3;
                creciente = false; // si  no es creciente es false


            }else {
                sin_tendencia = 1; // si no  se cumplen las  anteriores condicones lo marcamos  en  una variable
            }

        }
            if (sin_tendencia == 1){  // condicion  para cuando se ha roto la tendencia
                printf("\nNi creix ni  decreix");
                printf("\nPrem una tecla per finalitzar");
                getch();
                return 0;
            }

            if(creciente == true){
                printf("\nLa tendencia es creixent");
            }else if (creciente == false){
                printf("\nLa tendencia decreix");
            }

            printf("\nPrem una tecla per finalitzar");
            getch();
            return 0;
               
}