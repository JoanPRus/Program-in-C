#include <stdio.h>

/*(MesGranMesPetit): Calcula el numero més gran i més petit dels números
introduïts per teclats. Acabem d’introduir números quan l’usuari ens
introdueixi el 0. EL 0 no s’ha de tenir en compte, és una marca final.
Introdueix el numero: 0
No s'ha introduit cap numero
Prem una tecla per finalitzar

Introdueix el numero: 4
Introdueix el numero: 0
El numero maxim es 4 i el minim es 4
Prem una tecla per finalitzar

Introdueix el numero: 5
Introdueix el numero: 8
Introdueix el numero: 2
Introdueix el numero: 9
Introdueix el numero: -3
Introdueix el numero: 9
Introdueix el numero: 0
El numero maxim es 9 i el minim es -3
Prem una tecla per finalitzar
*/

int main(){

    /*Pedir numeros, terminar cuando ponga 0. Calcular que numero es el mas grande y  
    el mas pequeño
    Podemos hacer un for y un array  (fijo, no se dinamico), condicion para el 0.
    Para saber cual es el  numero mas gran y pequeño podemos hacer que el  array 
    se ordene y ahi ya imprimimos por el indice.
    Tenemos que poner un contador para saber cuantas vueltas a dado el for y asi sabemos
    el numero de indices que hay, el 0 el numero mas grande y el ultimo numero del indice 
    es el mas pequeño que es el numero del  contador. 
    Para ordenar  array:
    tengo  que aprender un metodo, o mirar de aplicar el intercanvio con un aux. 
    */

    int numeros[50];
    int salida = 0;
    int contador = 0;
    int aux = 0;

    for (int i = 0; i < 50; i++){  //for para pedir  numeros

    printf("Introdueix el numero: ");
    scanf("%d", &numeros[i]); //guardamos los numeros en el  array

        if (numeros[i] == 0){ //condicion cero para salir del bucle, posibles problemas con el siguiente if 
            break;
        }
        contador++; //cuenta  las vueltas que da, que se traduce a la posicion final del indice. Pienso que puedo  acceder al final con n - 1

    }
     //Algoritmo del Método de Intercambio (Bubble Sort Simplificado)
     
    for (int i = 0; i < contador - 1; i++) { //recorremos todas las posiciones del array hasta el contador, el contador a contado 5num pero el indice marca 4 porque cuenta desde  cero por ejemplo por eso contador - 1
        for (int j = 0; j < contador - 1; j++) { //comparamos cada elemento con el siguiente 
            if (numeros[j] < numeros[j + 1]) { //condiciones para cambiar el orden
                aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }

            
     {
        printf("\nNumero mes gran  %d", numeros[0]);
        printf("\nNumero mes petit %d", numeros[contador - 1]);
    }

    getch();
    return 0;
}